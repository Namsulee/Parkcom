//AddressBook.c
/*
파일 명칭 : AddressBook.c
기    능 : 배열 라이브러리를 사용해서 주소록을 관리한다.
작 성 자 : Joey
작성 일자 : 2017/03/12
*/

#include "AddressBook.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
	AddressBook addressBook;
	Long count;
	Long(*indexes);
	Personal personal;
	Long i;
	Long index;

	//Create
	AddressBook_Create(&addressBook, 3);
	count = Load(&addressBook);
	i = 0;
	while (i < count){
		personal = AddressBook_GetAt(&addressBook, i);
		printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);
		i++;
	}

	//Record
	index = Record(&addressBook, "홍길동", "서울시 서초구", "025879424", "hong@");
	personal = AddressBook_GetAt(&addressBook, index);
	printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);

	index = Record(&addressBook, "고길동", "인천시 중구", "0325879424", "ko@");
	personal = AddressBook_GetAt(&addressBook, index);
	printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);

	index = Record(&addressBook, "홍길동", "대전시 서구", "0425879424", "gil@");
	personal = AddressBook_GetAt(&addressBook, index);
	printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);

	index = Record(&addressBook, "박길동", "대구시 달서구", "0525879424", "park@");
	personal = AddressBook_GetAt(&addressBook, index);
	printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);

	//Find
	Find(&addressBook, "홍길동", &indexes, &count);
	i = 0;
	while (i < count) {
		personal = AddressBook_GetAt(&addressBook, index);
		printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);
		i++;
	}
	if (indexes != NULL) {
		free(indexes);
		indexes = NULL;
	}

	//Correct
	Find(&addressBook, "박길동", &indexes, &count);
	index = Correct(&addressBook, indexes[0], "부산시 해운대구", "0545879424", "dong@");
	personal = AddressBook_GetAt(&addressBook, index);
	printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);
	
	if (indexes != NULL) {
		free(indexes);
		indexes = NULL;
	}

	//Erase
	Find(&addressBook, "홍길동", &indexes, &count);
	index = Erase(&addressBook, indexes[0]);
	if (index == -1) {
		printf("지웠습니다.\n");
	}

	//Arrange
	Arrange(&addressBook);
	i = 0;
	while (i < addressBook.length) {
		personal = AddressBook_GetAt(&addressBook, i);
		printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);
		i++;
	}

	//Save
	count = Save(&addressBook);

	//Destroy
	AddressBook_Destroy(&addressBook);

	return 0;
}

/*
함수 명칭 : AddressBook_Create
기     능 : 주소록을 준비한다.
입     력 : 주소록 허용량
출     력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/12
*/
void AddressBook_Create(AddressBook *addressBook, Long capacity) {
	Create(&addressBook->personals, capacity, sizeof(Personal));
	addressBook->capacity = capacity;
	addressBook->length = 0;
}

/*
함수 명칭 : Load
기     능 : 디스크파일의 주소를 주소록으로 불러온다.
입     력 : 없음
출     력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/12
*/
Long Load(AddressBook *addressBook) {
	Long flag;
	Personal personal;
	FILE *file;
	file = fopen("AddressBook.bat", "rb");
	if (file != NULL) {
		flag = fread(&personal, sizeof(Personal), 1, file);
		while (!feof(file) && flag != 0) {
			if (addressBook->capacity > addressBook->length) {
				Store(&addressBook->personals, addressBook->length, &personal, sizeof(Personal));
			}
			else {
				AppendFromRear(&addressBook->personals, &personal, sizeof(Personal));
				addressBook->capacity++;
			}
			addressBook->length++;
			flag = fread(&personal, sizeof(Personal), 1, file);
		}
		fclose(file);
	}
	return addressBook->length;
}

/*
함수 명칭 : Record
기     능 : 개인을 주소록에 저장한다.
입     력 : 성명, 주소, 전화번호, 이메일주소
출     력 : 위치
작 성 자 : Joey
작성 일자 : 2017/03/12
*/
Long Record(AddressBook *addressBook, char(*name), char(*address), char(*telephoneNumber), char(*emailAddress)) {
	Long index;
	Personal personal;

	strcpy(personal.name, name);
	strcpy(personal.address, address);
	strcpy(personal.telephoneNumber, telephoneNumber);
	strcpy(personal.emailAddress, emailAddress);

	if (addressBook->length < addressBook->capacity) {
		index = Store(&addressBook->personals, addressBook->length, &personal, sizeof(Personal));
	}
	else {
		index = AppendFromRear(&addressBook->personals, &personal, sizeof(Personal));
		addressBook->capacity++;
	}
	addressBook->length++;
	return index;
}

/*
함수 명칭 : Find
기     능 : 주소록에 입력받은 성명과 동일한 개인들을 찾는다.
입     력 : 성명
출     력 : 위치들, 개수
작 성 자 : Joey
작성 일자 : 2017/03/12
*/
void Find(AddressBook *addressBook, char(*name), Long *(*indexes), Long *count) {
	LinearSearchDuplicate(&addressBook->personals, name, indexes, count, sizeof(Personal), CompareNames);
}

/*
함수 명칭 : AddressBook_GetAt
기     능 : 해당 위치의 개인을 출력한다.
입     력 : 위치
출     력 : 개인
작 성 자 : Joey
작성 일자 : 2017/03/12
*/
Personal AddressBook_GetAt(AddressBook *addressBook, Long index) {
	Personal personal;
	GetAt(&addressBook->personals, index, &personal, sizeof(Personal));
	return personal;
}

/*
함수 명칭 : Correct
기     능 : 주소록에서 선택한 개인의 주소, 전화번호, 이메일주소를 고친다.
입     력 : 위치, 주소, 전화번호, 이메일주소
출     력 : 위치
작 성 자 : Joey
작성 일자 : 2017/03/12
*/
Long Correct(AddressBook *addressBook, Long index, char(*address), char(*telephoneNumber), char(*emailAddress)){
	Personal personal;
	GetAt(&addressBook->personals, index, &personal, sizeof(Personal));
	strcpy(personal.address, address);
	strcpy(personal.telephoneNumber, telephoneNumber);
	strcpy(personal.emailAddress, emailAddress);
	index = Modify(&addressBook->personals, index, &personal, sizeof(Personal));
	return index;
}

/*
함수 명칭 : Erase
기     능 : 주소록에서 개인을 지운다.
입     력 : 위치
출     력 : 위치(-1)
작 성 자 : Joey
작성 일자 : 2017/03/12
*/
Long Erase(AddressBook *addressBook, Long index) {
	index = Delete(&addressBook->personals, index, sizeof(Personal));
	addressBook->length--;
	addressBook->capacity--;
	return index;
}

/*
함수 명칭 : Arrange
기     능 : 주소록을 성명의 오름차순으로 정렬한다.
입     력 : 없음
출     력 : 없음
작 성 자 : Jeoy
작성 일자 : 2017/03/12
*/
void Arrange(AddressBook *addressBook) {
	InsertionSort(&addressBook->personals, sizeof(Personal), ComparePersonals);
}

/*
함수 명칭 : AddressBook_Destroy
기     능 : 주소록을 지운다.
입     력 : 없음
출     력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/12
*/
void AddressBook_Destroy(AddressBook *addressBook) {
	Destroy(&addressBook->personals);
}

/*
함수 명칭 : Save
기     능 : 주소록을 디스크파일에 저장한다.
입     력 : 없음
출     력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/12
*/
Long Save(AddressBook *addressBook) {
	Long i = 0;
	Personal personal;
	FILE *file;
	file = fopen("AddressBook.dat", "wb");
	if (file != NULL){
		while (i < addressBook->length) {
			GetAt(&addressBook->personals, i, &personal, sizeof(Personal));
			fwrite(&personal, sizeof(Personal), 1, file);
			i++;
		}
		fclose(file);
	}
	return addressBook->length;
}

/*
함수 명칭 : CompareNames
기     능 : 개인의 성명과 입력받은 성명을 비교한다.
입     력 : 개인, 성명
출     력 : 결과(1, 0, -1)
작 성 자 : Joey
작성 일자 : 2017/03/12
*/
int CompareNames(void *one, void *other) {
	int ret;
	ret = strcmp(((Personal*)one)->name, (char(*))other);
	return ret;
}

/*
함수 명칭 : ComparePersonals
기     능 : 개인1과 개인2를 비교한다.
입     력 : 개인1, 개인2
출     력 : 비교결과(1, 0, -1)
작 성 자 : Joey
작성 일자 : 2017/03/12
*/
int ComparePersonals(void *one, void *other) {
	int ret;
	ret = strcmp(((Personal*)one)->name, ((Personal*)other)->name);
	return ret;
}