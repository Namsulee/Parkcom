//BusinessCardBinder.c
/*
파일 명칭 : BusinessCardBinder.c
기     능 : 명함을 관리한다.
작 성 자 : Joey
작성 일자 : 2017/03/13
*/
#include "BusinessCardBinder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main(int argc, char*argv[]) {
//	BusinessCardBinder businessCardBinder;
//	BusinessCard businessCard;
//	BusinessCard *index;
//	BusinessCard* (*indexes);
//	ULong count;
//	ULong i;
//
//	//Create
//	Create(&businessCardBinder);
//	strcpy(businessCard.company.name, "삼성");
//	strcpy(businessCard.company.telephoneNumber, "025879424");
//	strcpy(businessCard.company.url, "3.com");
//	strcpy(businessCard.company.address, "서울시 서초구");
//	strcpy(businessCard.company.faxNumber, "025879424");
//	strcpy(businessCard.personal.name, "김길동");
//	strcpy(businessCard.personal.position, "부장");
//	strcpy(businessCard.personal.cellularPhoneNumber, "0102222222");
//	strcpy(businessCard.personal.emailAddress, "kim@");
//	businessCard.next = NULL;
//	index = TakeIn(&businessCardBinder, businessCard);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	strcpy(businessCard.company.name, "구글");
//	strcpy(businessCard.company.telephoneNumber, "035879424");
//	strcpy(businessCard.company.url, "9.com");
//	strcpy(businessCard.company.address, "서울시 강남구");
//	strcpy(businessCard.company.faxNumber, "035879424");
//	strcpy(businessCard.personal.name, "홍길동");
//	strcpy(businessCard.personal.position, "과장");
//	strcpy(businessCard.personal.cellularPhoneNumber, "0103333333");
//	strcpy(businessCard.personal.emailAddress, "hong@");
//	businessCard.next = NULL;
//	index = TakeIn(&businessCardBinder, businessCard);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	strcpy(businessCard.company.name, "마소");
//	strcpy(businessCard.company.telephoneNumber, "045879424");
//	strcpy(businessCard.company.url, "ms.com");
//	strcpy(businessCard.company.address, "서울시 종로구");
//	strcpy(businessCard.company.faxNumber, "045879424");
//	strcpy(businessCard.personal.name, "이길동");
//	strcpy(businessCard.personal.position, "대리");
//	strcpy(businessCard.personal.cellularPhoneNumber, "0104444444");
//	strcpy(businessCard.personal.emailAddress, "lee@");
//	businessCard.next = NULL;
//	index = TakeIn(&businessCardBinder, businessCard);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	strcpy(businessCard.company.name, "엘지");
//	strcpy(businessCard.company.telephoneNumber, "055879424");
//	strcpy(businessCard.company.url, "g.com");
//	strcpy(businessCard.company.address, "서울시 금천구");
//	strcpy(businessCard.company.faxNumber, "055879424");
//	strcpy(businessCard.personal.name, "홍길동");
//	strcpy(businessCard.personal.position, "사원");
//	strcpy(businessCard.personal.cellularPhoneNumber, "0105555555");
//	strcpy(businessCard.personal.emailAddress, "hong2@");
//	businessCard.next = NULL;
//	index = TakeIn(&businessCardBinder, businessCard);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	//Find
//	Find(&businessCardBinder, "홍길동", &indexes, &count);
//	i = 0;
//	while (i < count) {
//		printf("%s %s %s %s %s %s %s %s %s\n", 
//			indexes[i]->company.name, indexes[i]->company.telephoneNumber,
//			indexes[i]->company.url, indexes[i]->company.address, indexes[i]->company.faxNumber,
//			indexes[i]->personal.name, indexes[i]->personal.position, 
//			indexes[i]->personal.cellularPhoneNumber, indexes[i]->personal.emailAddress);
//		i++;
//	}
//
//	//TakeOut
//	businessCard = TakeOut(&businessCardBinder, indexes[0]);
//	printf("%s %s %s %s %s %s %s %s %s\n", businessCard.company.name, businessCard.company.telephoneNumber,
//		businessCard.company.url, businessCard.company.address, businessCard.company.faxNumber,
//		businessCard.personal.name, businessCard.personal.position, businessCard.personal.cellularPhoneNumber,
//		businessCard.personal.emailAddress);
//	if (indexes != NULL) {
//		free(indexes);
//		indexes = NULL;
//	}
//
//	//TakeIn
//	TakeIn(&businessCardBinder, businessCard);
//
//	//Arrange
//	Arrange(&businessCardBinder);
//
//	//First
//	index = First(&businessCardBinder);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	//Next
//	index = Next(&businessCardBinder);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	//Previous
//	index = Previous(&businessCardBinder);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	//Last
//	index = Last(&businessCardBinder);
//	printf("%s %s %s %s %s %s %s %s %s\n", index->company.name, index->company.telephoneNumber,
//		index->company.url, index->company.address, index->company.faxNumber,
//		index->personal.name, index->personal.position, index->personal.cellularPhoneNumber,
//		index->personal.emailAddress);
//
//	//Destroy
//	Destroy(&businessCardBinder);
//
//	return 0;
//}

/*
함수 명칭 : Create
기    능 : 명함관리철을 준비한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/13
*/
void Create(BusinessCardBinder *businessCardBinder) {
	businessCardBinder->first = NULL;
	businessCardBinder->current = NULL;
	businessCardBinder->length = 0;
}

/*
함수 명칭 : TakeIn
기    능 : 명함관리철에 명함을 끼워넣는다.
입    력 : 명함
출    력 : 위치(명함링크)
작 성 자 : Joey
작성 일자 : 2017/03/13
*/
BusinessCard* TakeIn(BusinessCardBinder *businessCardBinder, BusinessCard businessCard) {
	BusinessCard *previous = NULL;
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != NULL) {
		previous = businessCardBinder->current;
		businessCardBinder->current = businessCardBinder->current->next;
	}
	businessCardBinder->current = (BusinessCard *)malloc(sizeof(BusinessCard));
	(*businessCardBinder->current) = businessCard;
	if (previous != NULL) {
		previous->next = businessCardBinder->current;
	}
	else {
		businessCardBinder->first = businessCardBinder->current;
	}
	businessCardBinder->length++;

	return businessCardBinder->current;
}

/*
함수 명칭 : Find
기    능 : 명함관리철에서 입력받은 성명을가진 명함을 찾는다.
입    력 : 성명
출    력 : 링크들, 개수
작 성 자 : Joey
작성 일자 : 2017/03/13
*/
void Find(BusinessCardBinder *businessCardBinder, char(*name), BusinessCard **(*indexes), ULong *count) {
	ULong i = 0;
	*count = 0;
	(*indexes) = (BusinessCard* (*))calloc(businessCardBinder->length, sizeof(BusinessCard*));
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != NULL) {
		if (strcmp(businessCardBinder->current->personal.name, name) == 0) {
			(*indexes)[i] = businessCardBinder->current;
			i++;
			(*count)++;
		}
		businessCardBinder->current = businessCardBinder->current->next;
	}
}

/*
함수 명칭 : TakeOut
기    능 : 명함관리철에서 명함을 빼낸다.
입    력 : 위치
출    력 : 명함
작 성 자 : Joey
작성 일자 : 2017/03/13
*/
BusinessCard TakeOut(BusinessCardBinder *businessCardBinder, BusinessCard *index){
	BusinessCard businessCard;
	BusinessCard *previous = NULL;
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != index) {
		previous = businessCardBinder->current;
		businessCardBinder->current = businessCardBinder->current->next;
	}
	if (previous != NULL) {
		previous->next = businessCardBinder->current->next;
	}
	else {
		businessCardBinder->first = businessCardBinder->current->next;
	}

	if (index->next != NULL) {
		businessCardBinder->current = index->next;
	}
	else{
		businessCardBinder->current = previous;
	}

	index->next = NULL;
	businessCard = *index;
	if (index != NULL){
		free(index);
		index = NULL;
	}
	businessCardBinder->length--;
	return businessCard;
}

/*
함수 명칭 : Arrange
기    능 : 명함철의 명함들을 버블정렬을 이용해서 오름차순으로 정렬한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/13
*/
void Arrange(BusinessCardBinder *businessCardBinder) {
	BusinessCard *previous;
	BusinessCard *next;
	BusinessCard *temp;
	ULong i = 1;
	ULong j;

	while (i < businessCardBinder->length) {
		previous = NULL;
		businessCardBinder->current = businessCardBinder->first;
		next = businessCardBinder->current->next;
		j = 1;
		while (j <= businessCardBinder->length - i) {
			if (strcmp(businessCardBinder->current->personal.name, next->personal.name) > 0) {
				if (previous != NULL) {
					temp = previous->next;
					previous->next = businessCardBinder->current->next;
				}
				else {
					temp = businessCardBinder->first;
					businessCardBinder->first = businessCardBinder->current->next;
				}
				businessCardBinder->current->next = next->next;
				next->next = temp;
				previous = next;
			}
			else {
				previous = businessCardBinder->current;
				businessCardBinder->current = next;
			}
			next = businessCardBinder->current->next;
			j++;
		}
		i++;
	}
}

/*
함수 명칭 : Destroy
기    능 : 명함철을 지운다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/13
*/
void Destroy(BusinessCardBinder *businessCardBinder) {
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != NULL) {
		businessCardBinder->first = businessCardBinder->current->next;
		if (businessCardBinder->current != NULL) {
			free(businessCardBinder->current);
		}
		businessCardBinder->length--;;
		businessCardBinder->current = businessCardBinder->first;
	}
}

/*
함수 명칭 : First
기    능 : 명함관리철의 처음 명함으로 이동한다.
입    력 : 없음
출    력 : 명함링크
작 성 자 : Joey
작성 일자 : 2017/03/13
*/
BusinessCard* First(BusinessCardBinder *businessCardBinder) {
	businessCardBinder->current = businessCardBinder->first;
	return businessCardBinder->current;
}

/*
함수 명칭 : Previous
기    능 : 명함관리청의 현재 위치 이전의 명함으로 이동한다.
입    력 : 없음
출    력 : 명함링크
작 성 자 : Joey
작성 일자 : 2017/03/13
*/
BusinessCard* Previous(BusinessCardBinder *businessCardBinder){
	BusinessCard *previous = NULL;
	BusinessCard *current = businessCardBinder->current;
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != current){
		previous = businessCardBinder->current;
		businessCardBinder->current = businessCardBinder->current->next;
	}
	if (previous != NULL) {
		businessCardBinder->current = previous;
	}
	return businessCardBinder->current;
}

/*
함수 명칭 : Next
기    능 : 명함관리철의 다음 명함으로 이동한다.
입    력 : 없음
출    력 : 명함링크
작 성 자 : Joey
작성 일자 : 2017/03/13
*/
BusinessCard* Next(BusinessCardBinder *businessCardBinder) {
	BusinessCard *previous = businessCardBinder->current;
	businessCardBinder->current = businessCardBinder->current->next;
	if (businessCardBinder->current == NULL) {
		businessCardBinder->current = previous;
	}
	return businessCardBinder->current;
}

/*
함수 명칭 : Last
기    능 : 명함관리철의 마지막 명함으로 이동한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/13
*/
BusinessCard* Last(BusinessCardBinder *businessCardBinder){
	BusinessCard *previous = NULL;
	if (businessCardBinder->current == NULL) {
		businessCardBinder->current = businessCardBinder->first;
	}
	while (businessCardBinder->current != NULL) {
		previous = businessCardBinder->current;
		businessCardBinder->current = businessCardBinder->current->next;
	}
	businessCardBinder->current = previous;
	return businessCardBinder->current;
}

/*
함수 명칭 : FindByCompanyName
기    능 : 명함관리철의 회사을 찾는다.(중복없음)
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/23
*/
BusinessCard* FindByCompanyName(BusinessCardBinder *businessCardBinder, char(*name)) {
	businessCardBinder->current = businessCardBinder->first;
	while (businessCardBinder->current != NULL && strcmp(businessCardBinder->current->company.name, name) != 0) {
		businessCardBinder->current = businessCardBinder->current->next;
	}
	return businessCardBinder->current;
}

/*
함수 명칭 : Load
기    능 : 디스크파일을 읽어서 개인들과 회사들을 추가한다.(회사 상호 중복없음)
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/25
*/
ULong Load(BusinessCardBinder *businessCardBinder) {
	Personal personal;
	Company company;
	ULong number;
	BusinessCard businessCard;
	BusinessCard *previous = NULL;
	ULong i;
	FILE *personalsFile;
	FILE *companiesFile;
	ULong flag1;
	ULong flag2;

	personalsFile = fopen("Personals.dat", "rb");
	companiesFile = fopen("Companies.dat", "rb");
	//1. 개인 파일의 끝이 아닌동안 반복한다.
	if (personalsFile != NULL && companiesFile != NULL) {
		//1.1. 번호와 개인을 읽는다.
		fread(&number, sizeof(ULong), 1, personalsFile);
		flag1 = fread(&personal, sizeof(Personal), 1, personalsFile);
		while (!feof(personalsFile) && flag1 != 0) {
			fseek(companiesFile, 0L, SEEK_SET);
			//1.2. 번호에 있는 회사를 읽는다.
			i = 1;
			flag2 = fread(&company, sizeof(Company), 1, companiesFile);
			while (!feof(companiesFile) && flag2 != 0 && i < number) {
				i++;
				flag2 = fread(&company, sizeof(Company), 1, companiesFile);
			}
			//1.3. 명함을 만든다.
			businessCard.personal = personal;
			businessCard.company = company;
			businessCard.next = NULL;
			//1.4. 명함철에 명함을 낀다.
			businessCardBinder->current = (BusinessCard*)malloc(sizeof(BusinessCard));
			*businessCardBinder->current = businessCard;
			if (previous != NULL) {
				previous->next = businessCardBinder->current;
			}
			else {
				businessCardBinder->first = businessCardBinder->current;
			}
			//1.5. 명함의 개수를 세다.
			businessCardBinder->length++;
			previous = businessCardBinder->current;
			fread(&number, sizeof(Long), 1, personalsFile);
			flag1 = fread(&personal, sizeof(Personal), 1, personalsFile);
		}
		fclose(personalsFile);
		fclose(companiesFile);
	}
	//2. 명함의 개수를 출력한다.
	return businessCardBinder->length;
	//3. 끝내다.
}

/*
함수 명칭 : Save
기    능 : 명함관리철의 개인들과 회사들을 디스크파일에 저장한다.(회사 상호 중복없음)
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성 일자 : 2017/03/25
*/
ULong Save(BusinessCardBinder *businessCardBinder) {
	ULong count = 0;
	Company company;
	ULong relationShip;
	FILE *personalsFile;
	FILE *companiesFile;
	ULong flag;

	personalsFile = fopen("Personals.dat", "wb");
	companiesFile = fopen("Companies.dat", "wb+");
	if (personalsFile != NULL && companiesFile != NULL) {
		businessCardBinder->current = businessCardBinder->first;
		//1.명함관리철의 끝이 아닌동안 반복한다.
		while (businessCardBinder->current != NULL) {
			relationShip = 1;
			fseek(companiesFile, 0L, SEEK_SET);
			flag = fread(&company, sizeof(Company), 1, companiesFile);
			//1.1. 명함의 상호와 같은 상호를 회사파일에서 찾는다.
			while (!feof(companiesFile) && flag != 0 && strcmp(businessCardBinder->current->company.name, company.name) != 0) {
				relationShip++;
				flag = fread(&company, sizeof(Company), 1, companiesFile);
			}
			//1.2. 없으면 회사파일에 회사를 출력한다.
			if (feof(companiesFile) && flag == 0) {
				fwrite(&businessCardBinder->current->company, sizeof(Company), 1, companiesFile);
			}
			//1.3. 번호와 개인을 출력한다.
			fwrite(&relationShip, sizeof(ULong), 1, personalsFile);
			fwrite(&businessCardBinder->current->personal, sizeof(Personal), 1, personalsFile);
			//1.4. 개인의 개수를 세다.
			count++;
			businessCardBinder->current = businessCardBinder->current->next;
		}
		fclose(personalsFile);
		fclose(companiesFile);
	}
	//2. 개인의 개수를 출력한다.
	return count;
	//3. 끝내다.
}