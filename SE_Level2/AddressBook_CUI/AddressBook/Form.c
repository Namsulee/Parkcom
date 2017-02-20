//Form.c
/*
파일 명칭 : Form.c
기     능 : 메인메뉴, 기재하기, 찾기, 고치기, 지우기, 정리하기, 전체보기 기능을 호출하는 기능
입     력 : 주소록
출     력 : 없음
작  성 자 : 김세중
작성 일자 : 2017/02/16
*/

//전처리기
#include "Form.h"
#include "AddressBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//함수정의
/*
함수 명칭 : DisplayMenu
기     능 : 메뉴 폼
입     력 : 없음
출     력 : 없음
*/
void DisplayMenu() {
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t      주소록 Version 0.05\n");
	printf("\t\t\t      ======================\n");
	printf("\t\t\t      [1] 기재하기\n");
	printf("\t\t\t      [2] 찾    기\n");
	printf("\t\t\t      [3] 고 치 기\n");
	printf("\t\t\t      [4] 지 우 기\n");
	printf("\t\t\t      [5] 정리하기\n");
	printf("\t\t\t      [6] 전체보기\n");
	printf("\t\t\t      [0] 끝 내 기\n");
	printf("\t\t\t      ----------------------\n");
	printf("\t\t\t      메뉴를 선택하십시오 : ");
}

/*
함수 명칭 : FormForRecording
기     능 : 기재하기 폼
입     력 : 주소록
출     력 : 없음
*/
void FormForRecording(AddressBook *addressBook) {
	//자동변수
	char name[11];
	char address[128];
	char telephoneNumber[12];
	char emailAddress[128];
	char recording;
	char going = 'Y';
	Long index;

	while (going == 'Y' || going == 'y') {
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t    주소록 Version 0.05 - 기재하기\n");
		printf("\t    =========================================================\n");
		printf("\t    성      명 : "); fflush(stdin); scanf("%s", name);
		printf("\t    주      소 : "); fflush(stdin); gets(address);
		printf("\t    전화  번호 : "); fflush(stdin); scanf("%s", telephoneNumber);
		printf("\t    이메일주소 : "); fflush(stdin); scanf("%s", emailAddress);
		printf("\t    ---------------------------------------------------------\n");
		printf("\t    기재하시겠습니까? (Yes/No) "); fflush(stdin); recording = getchar();
		if (recording == 'Y' || recording == 'y') {
			index = Record(addressBook, name, address, telephoneNumber, emailAddress);
			printf("\t    =========================================================\n");
			printf("\t    번호   성명        주소        전화번호        이메일주소\n");
			printf("\t    ---------------------------------------------------------\n");
			printf("\t    %4d   %-12s%-12s%-16s%-12s\n", index + 1, addressBook->personals[index].name,
				addressBook->personals[index].address, addressBook->personals[index].telephoneNumber,
				addressBook->personals[index].emailAddress);
		}
		printf("\t    =========================================================\n");
		printf("\t    계속하시겠습니까? (Yes/No) "); fflush(stdin); going = getchar();
	}
}

/*
함수 명칭 : FormForFinding
기     능 : 찾기 폼
입     력 : 주소록
출     력 : 없음
*/
void FormForFinding(AddressBook *addressBook) {
	char name[11];
	Long (*indexes);
	Long count;
	//char finding;
	char going = 'Y';
	Long i;

	while (going == 'Y' || going == 'y') {
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t    주소록 Version 0.05 - 찾기\n");
		printf("\t    =========================================================\n");
		printf("\t    성      명 : "); fflush(stdin); scanf("%s", name);
		printf("\t    =========================================================\n");
		printf("\t    번호   성명        주소        전화번호        이메일주소\n");
		printf("\t    ---------------------------------------------------------\n");
		Find(addressBook, name, &indexes, &count);
		for (i = 0; i < count; i++) {
			printf("\t    %4d   %-12s%-12s%-16s%-12s\n", i + 1, addressBook->personals[indexes[i]].name,
				addressBook->personals[indexes[i]].address, addressBook->personals[indexes[i]].telephoneNumber,
				addressBook->personals[indexes[i]].emailAddress);
		}
		printf("\t    =========================================================\n");
		if (indexes != NULL) {
			free(indexes);
			indexes = NULL;
		}
		printf("\t    계속하시겠습니까? (Yes/No) "); fflush(stdin); going = getchar();
	}
}

/*
함수 명칭 : FormForCorrecting
기     능 : 고치기 폼
입     력 : 주소록
출     력 : 없음
*/
void FormForCorrecting(AddressBook *addressBook) {
	char name[11];
	char address[128];
	char telephoneNumber[12];
	char emailAddress[128];
	char correcting;
	char going = 'Y';
	Long number;
	Long index;
	Long(*indexes);
	Long count;
	Long i;

	while (going == 'Y' || going == 'y') {
		system("cls");
		printf("\n");
		printf("\t    주소록 Version 0.05 - 고치기\n");
		printf("\t    =========================================================\n");
		printf("\t    성      명 : "); fflush(stdin); scanf("%s", name);
		printf("\t    =========================================================\n");
		printf("\t    번호   성명        주소        전화번호        이메일주소\n");
		printf("\t    ---------------------------------------------------------\n");
		Find(addressBook, name, &indexes, &count);
		if (count > 0) {			
			for (i = 0; i < count; i++) {
				printf("\t    %4d   %-12s%-12s%-16s%-12s\n", index + 1, addressBook->personals[indexes[i]].name,
					addressBook->personals[indexes[i]].address, addressBook->personals[indexes[i]].telephoneNumber,
					addressBook->personals[indexes[i]].emailAddress);
			}
			printf("\t    =========================================================\n");
			printf("\t    번      호 : "); fflush(stdin); scanf("%d", &number);
			printf("\t    주      소 : "); fflush(stdin); gets(address);
			printf("\t    전화  번호 : "); fflush(stdin); gets(telephoneNumber);
			printf("\t    이메일주소 : "); fflush(stdin); gets(emailAddress);
			if (strcmp(address, "") == 0) {
				strcpy(address, addressBook->personals[indexes[number - 1]].address);
			}
			if (strcmp(telephoneNumber, "") == 0) {
				strcpy(telephoneNumber, addressBook->personals[indexes[number - 1]].telephoneNumber);
			}
			if (strcmp(emailAddress, "") == 0) {
				strcpy(emailAddress, addressBook->personals[indexes[number - 1]].emailAddress);
			}
			printf("\t    ---------------------------------------------------------\n");
			printf("\t    고치시겠습니까? (Yes/No) "); fflush(stdin); correcting = getchar();
			if (correcting == 'Y' || correcting == 'y') {
				index = Correct(addressBook, indexes[number - 1], address, telephoneNumber, emailAddress);
				printf("\t    =========================================================\n");
				printf("\t    번호   성명        주소        전화번호        이메일주소\n");
				printf("\t    ---------------------------------------------------------\n");
				printf("\t    %4d   %-12s%-12s%-16s%-12s\n", i + 1, addressBook->personals[index].name,
					addressBook->personals[index].address, addressBook->personals[index].telephoneNumber,
					addressBook->personals[index].emailAddress);
			}
		}
		printf("\t    =========================================================\n");
		if (indexes != NULL) {
			free(indexes);
			indexes = NULL;
		}
		printf("\t    계속하시겠습니까? (Yes/No) "); fflush(stdin); going = getchar();
	}
}

/*
함수 명칭 : FormForErasing
기     능 : 지우기 폼
입     력 : 주소록
출     력 : 없음
*/
void FormForErasing(AddressBook *addressBook) {
	char name[11];
	Long number;
	char erasing;
	char going = 'Y';
	Long (*indexes);
	Long count;
	Long index;
	Long i;
	while (going == 'Y' || going == 'y') {
		system("cls");
		printf("\n\n\n\n");
		printf("\t    주소록 Version 0.05 - 지우기\n");
		printf("\t    =========================================================\n");
		printf("\t    성      명 : "); fflush(stdin); scanf("%s", name);
		printf("\t    =========================================================\n");
		printf("\t    번호   성명        주소        전화번호        이메일주소\n");
		printf("\t    ---------------------------------------------------------\n");
		Find(addressBook, name, &indexes, &count);
		if (count > 0) {
			for (i = 0; i < count; i++) {
				printf("\t    %4d   %-12s%-12s%-16s%-12s\n", i + 1, addressBook->personals[indexes[i]].name,
					addressBook->personals[indexes[i]].address, addressBook->personals[indexes[i]].telephoneNumber,
					addressBook->personals[indexes[i]].emailAddress);
			}
			printf("\t    =========================================================\n");
			printf("\t    번      호 : "); fflush(stdin); scanf("%d", &number);
			printf("\t    ---------------------------------------------------------\n");
			printf("\t    번호   성명        주소        전화번호        이메일주소\n");
			printf("\t    ---------------------------------------------------------\n");
			printf("\t    %4d   %-12s%-12s%-16s%-12s\n", indexes[number - 1], addressBook->personals[indexes[number - 1]].name,
				addressBook->personals[indexes[number - 1]].address, addressBook->personals[indexes[number - 1]].telephoneNumber,
				addressBook->personals[indexes[number - 1]].emailAddress);
			printf("\t    =========================================================\n");
			printf("\t    지우시겠습니까? (Yes/No) "); fflush(stdin); erasing = getchar();
			if (erasing == 'Y' || erasing == 'y') {
				index = Erase(addressBook, indexes[number - 1]);
				printf("\t    =========================================================\n");
				printf("\t    지워졌습니다.\n");
			}
		}//if
		printf("\t    =========================================================\n");
		if (indexes != NULL) {
			free(indexes);
			indexes = NULL;
		}
		printf("\t    계속하시겠습니까? (Yes/No) "); fflush(stdin); going = getchar();
	}
}

/*
함수 명칭 : FormForArranging
기     능 : 정리하기 폼
입     력 : 주소록
출     력 : 없음
*/
void FormForArranging(AddressBook *addressBook) {
	Long i = 0;
	Long j;

	Arrange(addressBook);
	while (i < addressBook->length) {
		system("cls");
		printf("\n\n\n\n");
		printf("\t    주소록 Version 0.05 - 정리하기\n");
		printf("\t    =========================================================\n");
		printf("\t    번호   성명        주소        전화번호        이메일주소\n");
		printf("\t    ---------------------------------------------------------\n");
		j = 1;
		while (j <= 10 && i < addressBook->length) {
			printf("\t    %4d   %-12s%-12s%-16s%-12s\n", i + 1, addressBook->personals[i].name,
				addressBook->personals[i].address, addressBook->personals[i].telephoneNumber,
				addressBook->personals[i].emailAddress);
			i++;
			j++;
		}
		printf("\t    =========================================================\n");
		printf("\t    아무키나 누르세요. "); fflush(stdin); getchar();
	}
}

/*
함수 명칭 : FormForViewAll
기     능 : 전체보기 폼
입     력 : 주소록
출     력 : 없음
*/
void FormForViewAll(AddressBook *addressBook) {
	Long i = 0;
	Long j;

	//Arrange(addressBook);
	while (i < addressBook->length) {
		system("cls");
		printf("\n\n\n\n");
		printf("\t    주소록 Version 0.05 - 전체보기\n");
		printf("\t    =========================================================\n");
		printf("\t    번호   성명        주소        전화번호        이메일주소\n");
		printf("\t    ---------------------------------------------------------\n");
		j = 1;
		while (j <= 10 && i < addressBook->length) {
			printf("\t    %4d   %-12s%-12s%-16s%-12s\n", i + 1, addressBook->personals[i].name,
				addressBook->personals[i].address, addressBook->personals[i].telephoneNumber,
				addressBook->personals[i].emailAddress);
			i++;
			j++;
		}
		printf("\t    =========================================================\n");
		printf("\t    아무키나 누르세요. "); fflush(stdin); getchar();
	}
}