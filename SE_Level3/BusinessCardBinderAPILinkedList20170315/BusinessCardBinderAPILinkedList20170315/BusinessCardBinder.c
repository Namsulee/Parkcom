//BusinessCardBinder.c
#include "BusinessCardBinder.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//메인함수정의
int main(int argc, char *argv[]) {
	BusinessCardBinder businessCardBinder;
	BusinessCard businessCard;
	BusinessCard *index;
	BusinessCard* (*indexes);
	ULong count;
	ULong i;

	//Create
	BusinessCardBinder_Create(&businessCardBinder);

	//TakeIn
	strcpy(businessCard.personal.name, "홍길동");
	strcpy(businessCard.personal.position, "사원");
	strcpy(businessCard.personal.cellularPhoneNumber, "0105879424");
	strcpy(businessCard.personal.emailAddress, "hong@");
	strcpy(businessCard.company.name, "삼성");
	strcpy(businessCard.company.telephoneNumber, "025879424");
	strcpy(businessCard.company.url, "SAMSUNG.com");
	strcpy(businessCard.company.address, "서울시 서초구");
	strcpy(businessCard.company.faxNumber, "025879424");
	index = TakeIn(&businessCardBinder, businessCard);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);
	//TakeIn
	strcpy(businessCard.personal.name, "이길동");
	strcpy(businessCard.personal.position, "대리");
	strcpy(businessCard.personal.cellularPhoneNumber, "0105879424");
	strcpy(businessCard.personal.emailAddress, "lee@");
	strcpy(businessCard.company.name, "현대");
	strcpy(businessCard.company.telephoneNumber, "025879424");
	strcpy(businessCard.company.url, "HUNDAI.com");
	strcpy(businessCard.company.address, "서울시 중구");
	strcpy(businessCard.company.faxNumber, "025879424");
	index = TakeIn(&businessCardBinder, businessCard);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);
	//TakeIn
	strcpy(businessCard.personal.name, "홍길동");
	strcpy(businessCard.personal.position, "과장");
	strcpy(businessCard.personal.cellularPhoneNumber, "0105879424");
	strcpy(businessCard.personal.emailAddress, "hong2@");
	strcpy(businessCard.company.name, "엘지");
	strcpy(businessCard.company.telephoneNumber, "025879424");
	strcpy(businessCard.company.url, "LG.com");
	strcpy(businessCard.company.address, "서울시 서초구");
	strcpy(businessCard.company.faxNumber, "025879424");
	index = TakeIn(&businessCardBinder, businessCard);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//Find
	Find(&businessCardBinder, "홍길동", &indexes, &count);
	i = 0;
	while (i < count) {
		printf("%s %s %s %s %s %s %s %s %s\n", indexes[i]->personal.name, indexes[i]->personal.position,
			indexes[i]->personal.cellularPhoneNumber, indexes[i]->personal.emailAddress,
			indexes[i]->company.name, indexes[i]->company.telephoneNumber, indexes[i]->company.url,
			indexes[i]->company.address, indexes[i]->company.faxNumber);
		i++;
	}
	if (indexes != NULL) {
		free(indexes);
		indexes = NULL;
	}

	//FindByCompanyNames
	index = FindByCompanyName(&businessCardBinder, "삼성");
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//Previous
	index = BusinessCardBinder_Previous(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//First & Previous, UnderFlow Check
	index = BusinessCardBinder_First(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	index = BusinessCardBinder_Previous(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//Next
	index = BusinessCardBinder_Next(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//Last & Next, Overflow check
	index = BusinessCardBinder_Last(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	index = BusinessCardBinder_Next(&businessCardBinder);
	printf("%s %s %s %s %s %s %s %s %s\n", index->personal.name, index->personal.position,
		index->personal.cellularPhoneNumber, index->personal.emailAddress,
		index->company.name, index->company.telephoneNumber, index->company.url,
		index->company.address, index->company.faxNumber);

	//TakeOut
	//index = BusinessCardBinder_Last(&businessCardBinder);
	businessCard = TakeOut(&businessCardBinder, index);
	printf("%s %s %s %s %s %s %s %s %s\n", businessCard.personal.name, businessCard.personal.position,
		businessCard.personal.cellularPhoneNumber, businessCard.personal.emailAddress,
		businessCard.company.name, businessCard.company.telephoneNumber, businessCard.company.url,
		businessCard.company.address, businessCard.company.faxNumber);

	//Destroy
	BusinessCardBinder_Destroy(&businessCardBinder);

	return 0;
}

/*
함수명칭 : BusinessCardBinder_Create
기    능 : 명함관리철을 초기화 한다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성일자 : 2017/03/26
*/
void BusinessCardBinder_Create(BusinessCardBinder *businessCardBinder) {
	Create(&businessCardBinder->businessCards);
	businessCardBinder->length = 0;
	businessCardBinder->current = NULL;
}


/*
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
ULong Load(BusinessCardBinder *businessCardBinder);

/*
함수명칭 : TakeIn
기    능 : 명함관리철에 입력받은 명함을 끼운다.
입    력 : 명함
출    력 : 명함링크
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard* TakeIn(BusinessCardBinder *businessCardBinder, BusinessCard businessCard) {
	Node *index;

	index = AppendFromTail(&businessCardBinder->businessCards, &businessCard, sizeof(BusinessCard));
	businessCardBinder->length++;
	businessCardBinder->current = (BusinessCard*)(index + 1);

	return businessCardBinder->current;
}

/*
함수명칭 : Find
기    능 : 명함관리철에서 입력받은 성명과 일치하는 명함들과 개수를 출력한다.
입    력 : 성명
출    력 : 명함들, 개수
작 성 자 : Joey
작성일자 : 2017/03/26
*/
void Find(BusinessCardBinder *businessCardBinder, char(*name), BusinessCard* *(*indexes), ULong *count) {
	Node* (*nodeIndexes);
	ULong i = 0;

	*indexes = (BusinessCard* (*))calloc(businessCardBinder->length, sizeof(BusinessCard*));
	LinearSearchDuplicate(&businessCardBinder->businessCards, name, &nodeIndexes, count, CompareNames);
	while (i < *count) {
		(*indexes)[i] = (BusinessCard*)(nodeIndexes[i] + 1);
		i++;
	}
	if (nodeIndexes != NULL) {
		free(nodeIndexes);
		nodeIndexes = NULL;
	}
}

/*
함수명칭 : FindByCompanyName
기    능 : 명함관리철에서 입력받은 상호를 찾아서 명함링크를 출력한다.
입    력 : 상호
출    력 : 명함링크
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard* FindByCompanyName(BusinessCardBinder *businessCardBinder, char(*companyName)) {
	BusinessCard *index;
	Node *nodeIndex;

	nodeIndex = LinearSearchUnique(&businessCardBinder->businessCards, companyName, CompareCompanyNames);
	index = (BusinessCard*)(nodeIndex + 1);

	return index;
}

/*
함수명칭 : TakeOut
기    능 : 명함관리철에서 입력받은 명함링크에 해당하는 명함을 출력한다.
입    력 : 명함링크
출    력 : 명함
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard TakeOut(BusinessCardBinder *businessCardBinder, BusinessCard *index) {
	Node *nodeIndex;
	BusinessCard businessCard;

	nodeIndex = LinearSearchUnique(&businessCardBinder->businessCards, index, CompareIndexes);
	GetAt(&businessCardBinder->businessCards, nodeIndex, &businessCard, sizeof(BusinessCard));
	Delete(&businessCardBinder->businessCards, nodeIndex);
	businessCardBinder->length--;
	businessCardBinder->current = (BusinessCard*)(businessCardBinder->businessCards.current + 1);

	return businessCard;
}

/*
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard BusinessCardBinder_GetAt(BusinessCardBinder *businessCardBinder, BusinessCard *index);

/*
함수명칭 : BusinessCardBinder_First
기    능 : 명함관리철의 처음 명함으로 이동하고 명함링크를 출력한다.
입    력 : 없음
출    력 : 명함링크
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard* BusinessCardBinder_First(BusinessCardBinder *businessCardBinder) {
	Node *nodeIndex;

	nodeIndex = First(&businessCardBinder->businessCards);
	businessCardBinder->current = (BusinessCard*)(nodeIndex + 1);

	return businessCardBinder->current;
}

/*
함수명칭 : BusinessCardBinder_Previous
기    능 : 명함관리철에서 이전 명함으로 이동하고 명함링크를 출력한다.
입    력 : 없음
출    력 : 명함 링크
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard* BusinessCardBinder_Previous(BusinessCardBinder *businessCardBinder) {
	Node *nodeIndex;

	nodeIndex = Previous(&businessCardBinder->businessCards);
	businessCardBinder->current = (BusinessCard*)(nodeIndex + 1);

	return businessCardBinder->current;
}

/*
함수명칭 : BusinessCardBInder_Next
기    능 : 명함관리철에서 다음 명함으로 이동하고 명함링클르 출력한다.
입    력 : 없음
출    력 : 명함링크
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard* BusinessCardBinder_Next(BusinessCardBinder *businessCardBinder) {
	Node *nodeIndex;

	nodeIndex = Next(&businessCardBinder->businessCards);
	businessCardBinder->current = (BusinessCard*)(nodeIndex + 1);

	return businessCardBinder->current;
}

/*
함수명칭 : BusinessCardBinder_Last
기    능 : 명함관리철 마지막 명함으로 이동하고 명함링크를 출력한다.
입    력 : 없음
출    력 : 명함링크
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard* BusinessCardBinder_Last(BusinessCardBinder *businessCardBinder) {
	Node *nodeIndex;

	nodeIndex = Last(&businessCardBinder->businessCards);
	businessCardBinder->current = (BusinessCard*)(nodeIndex + 1);

	return businessCardBinder->current;
}

/*
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
ULong Save(BusinessCardBinder *businessCardBinder);

/*
함수명칭 : BusinessCardBinder_Destroy
기    능 : 명함관리철을 지운다.
입    력 : 없음
출    력 : 없음
작 성 자 : Joey
작성일자 : 2017/03/26
*/
void BusinessCardBinder_Destroy(BusinessCardBinder *businessCardBinder) {
	Destroy(&businessCardBinder->businessCards);
}


/*
함수명칭 : CompareNames
기    능 : 명함과 성명을 입력받고 명함의 성명과 성명을 비교한다.
입    력 : 명함, 성명
출    력 : 비교결과
작 성 자 : Joey
작성일자 : 2017/03/26
*/
int CompareNames(void *one, void *other) {
	return strcmp( ((BusinessCard*)one)->personal.name, (char*)other );
}

/*
함수명칭 : CompareCompanyNames
기    능 : 명함과 상호를 입력받고 명함의 상호와 상호를 비교한 결과를 출력한다.
입    력 : 명함링크, 상호
출    력 : 비교결과
작 성 자 : Joey
작성일자 : 2017/03/26
*/
int CompareCompanyNames(void *one, void *other) {
	return strcmp(((BusinessCard*)one)->company.name, (char*)other);
}

/*
함수명칭 : CompareIndexes
기    능 : 입력받은 노드링크와 노드링크를 비교해서 결과를 출력한다.
입    력 : 노드링크, 노드링크
출    력 : 비교결과
작 성 자 : Joey
작성일자 : 2017/03/26
*/
int CompareIndexes(void *one, void *other) {
	int ret = -1;
	if (one == other) {
		return 0;
	}
	return ret;
}