//BusinessCardBinder.c
#include "BusinessCardBinder.h"
#include <string.h>
#include <stdio.h>


//메인함수정의
int main(int argc, char *argv[]) {
	BusinessCardBinder businessCardBinder;
	BusinessCard businessCard;
	BusinessCard *index;

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
void Find(BusinessCardBinder *businessCardBinder, char(*name), BusinessCard* *(*indexes), ULong *count);

/*
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard* FindByCompanyName(BusinessCardBinder *businessCardBinder, char(*companyName));

/*
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard TakeOut(BusinessCardBinder *businessCardBinder, BusinessCard *index);

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
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard* BusinessCardBinder_First(BusinessCardBinder *businessCardBinder);

/*
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard* BusinessCardBinder_Previous(BusinessCardBinder *businessCardBinder);

/*
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard* BusinessCardBInder_Next(BusinessCardBinder *businessCardBinder);

/*
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
BusinessCard* BusinessCardBInder_Last(BusinessCardBinder *businessCardBinder);

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
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
int CompareNames(void *one, void *other);

/*
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
int CompareCompanyNames(void *one, void *other);

/*
함수명칭 :
기    능 :
입    력 :
출    력 :
작 성 자 : Joey
작성일자 : 2017/03/26
*/
int CompareIndexes(void *one, void *other);