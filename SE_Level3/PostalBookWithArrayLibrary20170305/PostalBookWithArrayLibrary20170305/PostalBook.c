//PostalBook.c
/*
파일 명칭 : PostalBook.c
기    능 : 배열라이브러리를 사용해서 우편번호부 찾기 기능을 제공한다.
작 성 자 : Joey
작성 일자 : 2017/03/012
*/


#include "PostalBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	PostalBook postalBook;
	ULong(*indexes);
	ULong count;
	ULong i = 0;
	Address address;

	//Create
	PostalBook_Create(&postalBook, 60000);

	//Load
	count = PostalBook_Load(&postalBook);
	while (i < count) {
		address = PostalBook_GetAt(&postalBook, i);
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			address.zipcode, address.sido, address.gugun, 
			address.dong, address.ri, address.bldg, 
			address.stBunji, address.edBunji, address.seq);
		i++;
	}

	//Find
	PostalBook_Find(&postalBook, "서초동", &indexes, &count);
	i = 0;
	while (i < count) {
		address = PostalBook_GetAt(&postalBook, indexes[i]);
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			address.zipcode, address.sido, address.gugun,
			address.dong, address.ri, address.bldg,
			address.stBunji, address.edBunji, address.seq);
		i++;
	}
	if (indexes != NULL){
		free(indexes);
		indexes = NULL;
	}

	//Destroy
	PostalBook_Destroy(&postalBook);

	return 0;
}

/*
함수 명칭 : PostalBookCreate
기     능 : 우편번호부를 생성한다.
입     력 : 허용량
출     력 : 없음
*/
void PostalBook_Create(PostalBook *postalBook, ULong capacity) {
	//postalBook->addresses = (Address(*))calloc(capacity, sizeof(Address));
	Create(&postalBook->addresses, capacity, sizeof(Address));
	postalBook->capacity = capacity;
	postalBook->length = 0;
}

/*
함수 명칭 : PostalBookLoad
기     능 : 디스크파일에서 우편번호부 주소를 불러온다.
입     력 : 없음
출     력 : 주소개수
*/
ULong PostalBook_Load(PostalBook *postalBook) {
	char buffer[256];
	char line[256];
	Address address;
	ULong fieldIndex;
	ULong i;
	ULong j;
	FILE *file;

	file = fopen("PostalBook.txt", "rt");
	if (file != NULL) {
		fgets(line, sizeof(line), file);
		fgets(line, sizeof(line), file);
		while (!feof(file)) {
			fieldIndex = 1;
			i = 0;
			while (line[i] != '\0') {
				j = 0;
				while (line[i] != '\t' && line[i] != '\n') {
					buffer[j] = line[i];
					i++;
					j++;
				}
				buffer[j] = '\0';
				switch (fieldIndex) {
					case 1: strcpy(address.zipcode, buffer); break;
					case 2: strcpy(address.sido, buffer); break;
					case 3: strcpy(address.gugun, buffer); break;
					case 4: strcpy(address.dong, buffer); break;
					case 5: strcpy(address.ri, buffer); break;
					case 6: strcpy(address.bldg, buffer); break;
					case 7: strcpy(address.stBunji, buffer); break;
					case 8: strcpy(address.edBunji, buffer); break;
					case 9: strcpy(address.seq, buffer); break;
					default: break;
				}
				fieldIndex++;
				i++;
			}			
			if (postalBook->length < postalBook->capacity) {
				Store(&postalBook->addresses, postalBook->length, &address, sizeof(Address));
			}
			else {
				AppendFromRear(&postalBook->addresses, &address, sizeof(Address));
				postalBook->capacity++;
			}
			postalBook->length++;
			fgets(line, sizeof(line), file);
		}//feof
		fclose(file);
	}//file
	return postalBook->length;
}

/*
함수 명칭 : PostalBookFind
기     능 : 우편번호부에서 입력받은 동과 일치하는 주소를 찾는다.
입     력 : 동
출     력 : 주소들, 개수
*/
void PostalBook_Find(PostalBook *postalBook, char(*inputDong), ULong *(*indexes), ULong *count){
	LinearSearchDuplicate(&postalBook->addresses, inputDong, indexes, count, sizeof(Address), CompareDongs);
}

/*
함수 명칭 : PostalBookDestroy
기     능 : 우편번호부의 주소를 해제한다.
입     력 : 없음
출     력 : 없음
*/
void PostalBook_Destroy(PostalBook *postalBook) {
	Destroy(&postalBook->addresses);
}

/*
함수 명칭 : PostalBook_GetAt
기     능 : 우편번호부에서 위치에 해당하는 주소를 출력한다.
입     력 : 우편번호부, 위치
출     력 : 주소
*/
Address PostalBook_GetAt(PostalBook *postalBook, ULong index) {
	Address address;
	GetAt(&postalBook->addresses, index, &address, sizeof(Address));
	return address;
}

/*
함수 명칭 : CompareDongs
기     능 : 주소에서 입력받은 동과 비교해서 결과를 출력한다.
입     력 : 우편번호부 주소, 동
출     력 : 동 비교 결과(1, 0, -1)
*/
int CompareDongs(void *one, void *other) {
	char inputDong[27];
	char dataDong[27];
	char(*input);
	char(*data);
	ULong edIndex;
	ULong i = 0;
	input = (char(*))other;
	data = ((Address *)one)->dong;
	while (input[i] != '\0') {
		i++;
	}
	edIndex = i - 3;
	i = 0;
	while (i <= edIndex) {
		inputDong[i] = input[i];
		dataDong[i] = data[i];
		i++;
	}
	inputDong[i] = '\0';
	dataDong[i] = '\0';
	return strcmp(dataDong, inputDong);
}