//PostalBook.c
/*
파일 명칭 : PostalBook.c
기    능 : 우편번호부 찾기 기능을 제공한다.
작 성 자 : Joey
작성 일자 : 2017/03/012
*/


#include "PostalBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//int main(int argc, char *argv[]) {
//	PostalBook postalBook;
//	ULong(*indexes);
//	ULong count;
//	ULong i = 0;
//
//	PostalBookCreate(&postalBook, 60000);
//	count = PostalBookLoad(&postalBook);
//	PostalBookFind(&postalBook, "서초동", &indexes, &count);
//	while (i < count) {
//		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
//			postalBook.addresses[indexes[i]].zipcode, postalBook.addresses[indexes[i]].sido,
//			postalBook.addresses[indexes[i]].gugun, postalBook.addresses[indexes[i]].dong,
//			postalBook.addresses[indexes[i]].ri, postalBook.addresses[indexes[i]].bldg,
//			postalBook.addresses[indexes[i]].stBunji, postalBook.addresses[indexes[i]].edBunji,
//			postalBook.addresses[indexes[i]].seq);
//		i++;
//	}
//	if (indexes != NULL){
//		free(indexes);
//	}
//	PostalBookDestroy(&postalBook);
//
//	return 0;
//}

/*
함수 명칭 : PostalBookCreate
기     능 : 우편번호부를 생성한다.
입     력 : 허용량
출     력 : 없음
*/
void PostalBook_Create(PostalBook *postalBook, ULong capacity) {
	postalBook->addresses = (Address(*))calloc(capacity, sizeof(Address));
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
	Address(*temp);
	char buffer[256];
	char line[256];
	Address address;
	ULong fieldIndex;
	ULong i = 0;
	ULong j;
	ULong k;
	ULong l;
	FILE *file;

	file = fopen("PostalBook.txt", "rt");
	if (file != NULL) {
		fgets(line, sizeof(line), file);
		fgets(line, sizeof(line), file);
		while (!feof(file)) {
			if (postalBook->length >= postalBook->capacity) {
				temp = (Address(*))calloc(postalBook->capacity + 1, sizeof(Address));
				j = 0;
				while (j < postalBook->length) {
					temp[j] = postalBook->addresses[j];
					j++;
				}
				if (postalBook->addresses != NULL) {
					free(postalBook->addresses);
					postalBook->addresses = NULL;
				}
				postalBook->addresses = temp;
				postalBook->capacity++;
			}
			fieldIndex = 1;
			k = 0;
			while (line[k] != '\0') {
				l = 0;
				while (line[k] != '\t' && line[k] != '\n') {
					buffer[l] = line[k];
					l++;
					k++;
				}
				buffer[l] = '\0';
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
				k++;
			}
			postalBook->addresses[i] = address;
			postalBook->length++;
			i++;
			fgets(line, sizeof(line), file);
		}
		fclose(file);
	}
	return postalBook->length;
}

/*
함수 명칭 : PostalBookFind
기     능 : 우편번호부에서 입력받은 동과 일치하는 주소를 찾는다.
입     력 : 동
출     력 : 주소들, 개수
*/
void PostalBook_Find(PostalBook *postalBook, char(*inputDong), ULong *(*indexes), ULong *count){
	char dong[DONG];
	char targetDong[DONG];
	ULong i = 0;
	ULong j = 0;
	ULong index = 0;
	ULong edIndex;

	*count = 0;
	*indexes = (ULong(*))calloc(postalBook->length, sizeof(ULong));
	while (inputDong[i] != '\0') {
		i++;
	}
	edIndex = i - 3;
	i = 0;
	while (i <= edIndex) {
		targetDong[i] = inputDong[i];
		i++;
	}
	targetDong[i] = '\0';
	while (j < postalBook->length) {
		i = 0;
		while (i <= edIndex) {
			dong[i] = postalBook->addresses[j].dong[i];
			i++;
		}
		dong[i] = '\0';
		if (strcmp(targetDong, dong) == 0) {
			(*indexes)[index] = j;
			index++;
			(*count)++;
		}
		j++;
	}
}

/*
함수 명칭 : PostalBookDestroy
기     능 : 우편번호부의 주소를 해제한다.
입     력 : 없음
출     력 : 없음
*/
void PostalBook_Destroy(PostalBook *postalBook) {
	if (postalBook->addresses != NULL) {
		free(postalBook->addresses);
		postalBook->addresses = NULL;
	}
}

/*
함수 명칭 : PostalBook_GetAt
기     능 : 
입     력 : 
출     력 : 
*/
void PostalBook_GetAt(PostalBook *postalBook, ULong index);

/*
함수 명칭 : CompareDongs
기     능 : 
입     력 : 
출     력 : 
*/
int CompareDongs(void *one, void *other);