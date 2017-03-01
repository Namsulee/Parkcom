//AddressBook.c
/*
파일 명칭 : AddressBook.c
기     능 : 주소록을 관리한다.
입     력 : 없음
출     력 : 없음
작 성 자 : Joey
작성 일자 : 2016/2/19
*/

//전처리기
#include "AddressBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

//함수정의
//int main(int argc, char* argv[]) {
//	AddressBook addressBook;
//	Long menu;
//
//	Create(&addressBook, 4);
//	DisplayMenu();
//	fflush(stdin); scanf("%d", &menu);
//
//	while (menu != 0) {
//		switch(menu) {
//			case 1: FormForRecording(&addressBook); break;
//			case 2: FormForFinding(&addressBook); break;
//			case 3: FormForCorrecting(&addressBook); break;
//			case 4: FormForErasing(&addressBook); break;
//			case 5: FormForArranging(&addressBook); break;
//			case 6: FormForViewAll(&addressBook); break;
//			default: break;
//		}
//		DisplayMenu();
//		fflush(stdin); scanf("%d", &menu);
//	}
//	Destroy(&addressBook);
//	return 0;
//}

/*
함수 명칭 : Record
기     능 : 입력받은 성명, 주소, 전화번호, 이메일주소를 주소록에 입력한다.
입     력 : 주소록, 성명, 주소, 전화번호, 이메일주소
출     력 : 주소록, 줄번호
*/
Long Record(AddressBook *addressBook, char(*name), char(*address), char(*telephoneNumber), char(*emailAddress)) {
	Personal (*personals);
	Long index;
	Long i = 0;

	if (addressBook->capacity == addressBook->length) {
		personals = (Personal(*))calloc(addressBook->capacity + 1, sizeof(Personal));
		while (i < addressBook->length) {
			personals[i] = addressBook->personals[i];
			i++;
		}

		if (addressBook->personals != NULL) {
			free(addressBook->personals);
		}
		addressBook->personals = personals;
		addressBook->capacity++;
	}
	index = addressBook->length;
	strcpy(addressBook->personals[index].name, name);
	strcpy(addressBook->personals[index].address, address);
	strcpy(addressBook->personals[index].telephoneNumber, telephoneNumber);
	strcpy(addressBook->personals[index].emailAddress, emailAddress);
	addressBook->length++;
	
	return index;
}

/*
함수 명칭 : Find
기     능 : 성명을 입력받고 성명과 일치하는 줄들과 개수를 출력한다.
입     력 : 주소록, 성명
출     력 : 주소록, 줄번호들, 개수
*/
void Find(AddressBook *addressBook, char(*name), Long *(*indexes), Long *count) {
	Long i;
	Long j = 0;
	*indexes = NULL;
	*count = 0;
	if (addressBook->length > 0) {
		*indexes = (Long(*))calloc(addressBook->length, sizeof(Long));
	}
	for (i = 0; i < addressBook->length; i++) {
		if (strcmp(addressBook->personals[i].name, name) == 0) {
			(*indexes)[j] = i;
			j++;
			(*count)++;
		}
	}
}

/*
함수 명칭 : Correct
기     능 : 주소록에 입력받은 줄번호에 입력받은 주소, 전화번호, 이메일주소로 변경한다.
입     력 : 주소록, 줄번호, 주소, 전화번호, 이메일주소
출     력 : 주소록, 줄번호
*/
Long Correct(AddressBook *addressBook, Long index, char(*address), char(*telephoneNumber), char(*emailAddress)){
	strcpy(addressBook->personals[index].address, address);
	strcpy(addressBook->personals[index].telephoneNumber, telephoneNumber);
	strcpy(addressBook->personals[index].emailAddress, emailAddress);
	return index;
}

/*
함수 명칭 : Erase
기     능 : 주소록의 줄번호를 삭제하고 줄번호(-1)를 출력한다.
입     력 : 주소록, 줄번호
출     력 : 주소록, 줄번호(-1)
*/
Long Erase(AddressBook *addressBook, Long index) {
	Personal(*personals);
	Long i = 0;
	Long j = 0;

	if (addressBook->capacity > 1) {
		personals = (Personal(*))calloc(addressBook->capacity - 1, sizeof(Personal));
	}
	while (i < addressBook->length) {
		if (i != index) {
			personals[j] = addressBook->personals[i];
			j++;
		}
		i++;
	}
	if (addressBook->personals != NULL) {
		free(addressBook->personals);
		addressBook->personals = NULL;
	}

	if (addressBook->capacity > 1) {
		addressBook->personals = personals;
	}

	addressBook->capacity--;
	addressBook->length--;
	index = -1;

	return index;
}

/*
함수 명칭 : Arrange
기     능 : 주소록이 입력되면 오름차순으로 정렬한다.
입     력 : 주소록
출     력 : 주소록
*/
void Arrange(AddressBook *addressBook) {
	Personal temp;
	Long i = 0;
	Long j;

	while (i < addressBook->length - 1) {
		j = i + 1;
		while(j < addressBook->length) {
			if (strcmp(addressBook->personals[i].name, addressBook->personals[j].name) > 0) {
				temp = addressBook->personals[i];
				addressBook->personals[i] = addressBook->personals[j];
				addressBook->personals[j] = temp;
			}
			j++;
		}
		i++;
	}
}

/*
함수 명칭 : Create
기     능 : 입력받은 전체줄수 만큼의 개인들을 생성한다.
입     력 : 주소록, 전체줄수
출     력 : 주소록
*/
void Create(AddressBook *addressBook, Long capacity) {
	addressBook->personals = (Personal(*))calloc(capacity, sizeof(Personal));
	addressBook->capacity = capacity;
	addressBook->length = 0;
}

/*
함수 명칭 : Destroy
기     능 : 주소록을 해제한다.
입     력 : 주소록
출     력 : 없음
*/
void Destroy(AddressBook *addressBook) {
	if (addressBook->personals != NULL) {
		free(addressBook->personals);
	}
}

/*
함수 명칭 : Load
기     능 : dat파일에서 개인들을 주소록에 저장한다.
입     력 : 주소록
출     력 : 개인들의 수
작성 일자 : 2017/02/25
*/
Long Load(AddressBook *addressBook) {
	Long count = 0;
	Personal personal;
	Personal(*temp);
	Long index;
	Long i;
	Long j;
	FILE *file;
	Long flag;

	//file = fopen("AddressBook.txt", "rt");
	file = fopen("AddressBook.dat", "rb");
	if (file != NULL) {
		//1.1. 성명, 주소, 전화번호, 이메일주소를 읽는다.
		//fscanf(file, "%s %s %s %s", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);
		flag = fread(&personal, sizeof(Personal), 1, file);
		//1. 파일의 끝이 아닌동안 반복한다.
		while (!feof(file) && flag != 0) {
			
			i = 0;
			while (i < addressBook->capacity && strcmp(addressBook->personals[i].name, "") != 0) {
				i++;
			}
			if (i >= addressBook->capacity) {
				temp = (Personal(*))calloc(addressBook->capacity + 1, sizeof(Personal));
				j = 0;
				while (j < addressBook->length) {
					temp[j] = addressBook->personals[j];
					j++;
				}
				if (addressBook->personals != NULL) {
					free(addressBook->personals);
					addressBook->personals = NULL;
				}
				addressBook->personals = temp;
				(addressBook->capacity)++;
			}
			
			//1.2. 주소록에 성명, 주소, 전화번호, 이메일주소를 기재한다.
			index = i;
			addressBook->personals[index] = personal;
			(addressBook->length)++;

			//1.3. 개수를 센다.
			count++;

			//1.1. 성명, 주소, 전화번호, 이메일주소를 읽는다.
			//fscanf(file, "%s %s %s %s", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);
			fread(&personal, sizeof(Personal), 1, file);
		}
		fclose(file);
	}
	//2. 개수를 출력한다.	
	return count;

	//3. 끝내다.
}

/*
함수 명칭 : Save
기     능 : 주소록의 개인들을 dat파일에 저장한다.
입     력 : 주소록
출     력 : 개인들의 수
작성 일자 : 2017/02/25
*/
Long Save(AddressBook *addressBook) {
	Long count = 0;
	Long i = 0;
	FILE *file;

	//file = fopen("AddressBook.txt", "wt");
	file = fopen("AddressBook.dat", "wb");

	if (!feof(file)) {
		//1. 주소록의 사용량 만큼 반복한다.
		while (i < addressBook->length) {
			//1.1. 파일에 성명, 주소, 전화번호, 이메일주소를 기재한다.
			//fprintf(file, "%s %s %s %s\n", addressBook->personals[i].name, addressBook->personals[i].address,
			//	addressBook->personals[i].telephoneNumber, addressBook->personals[i].emailAddress);
			fwrite(addressBook->personals + i, sizeof(Personal), 1, file);
			
			//1.2. 개수를 센다.
			count++;
			i++;
		}
		fclose(file);
	}

	//2. 개수를 출력한다.
	return count;

	//3. 끝내다.
}