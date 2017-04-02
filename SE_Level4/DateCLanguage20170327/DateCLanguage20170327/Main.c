//Main.c
/*
���� ��Ī : Main.c
��     �� : ��¥ ����� �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/03/27
*/

#include "Date.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	Date date;
	Date today;
	Date yesterday;
	Date tommorrow;
	Date previousDate;
	Date nextDate;
	Boolean ret;

	//�����Ѵ�.
	Create(&date);
	Create(&today);
	Create(&yesterday);
	Create(&tommorrow);
	Create(&previousDate);
	Create(&nextDate);

	//����
	today = date.Today(&date);
	printf("%4d-%02d-%02d-", today.year, today.month, today.day);
	switch(today.weekDay) {
		case SUNDAY: printf("�Ͽ���\n"); break;
		case MONDAY: printf("������\n"); break;
		case TUESDAY: printf("ȭ����\n"); break;
		case WEDNESDAY: printf("������\n"); break;
		case THURSDAY: printf("�����\n"); break;
		case FRIDAY: printf("�ݿ���\n"); break;
		case SATURDAY: printf("�����\n"); break;
		default: break;
	}

	//����
	yesterday = today.Yesterday(&today);
	printf("%4d-%02d-%02d-", yesterday.year, yesterday.month, yesterday.day);
	switch (yesterday.weekDay) {
		case SUNDAY: printf("�Ͽ���\n"); break;
		case MONDAY: printf("������\n"); break;
		case TUESDAY: printf("ȭ����\n"); break;
		case WEDNESDAY: printf("������\n"); break;
		case THURSDAY: printf("�����\n"); break;
		case FRIDAY: printf("�ݿ���\n"); break;
		case SATURDAY: printf("�����\n"); break;
		default: break;
	}

	//����
	tommorrow = yesterday.Tommorrow(&yesterday);
	printf("%4d-%02d-%02d-", tommorrow.year, tommorrow.month, tommorrow.day);
	switch (tommorrow.weekDay) {
		case SUNDAY: printf("�Ͽ���\n"); break;
		case MONDAY: printf("������\n"); break;
		case TUESDAY: printf("ȭ����\n"); break;
		case WEDNESDAY: printf("������\n"); break;
		case THURSDAY: printf("�����\n"); break;
		case FRIDAY: printf("�ݿ���\n"); break;
		case SATURDAY: printf("�����\n"); break;
		default: break;
	}

	//������¥
	previousDate = today.PreviousDate(&today, 3);
	printf("%4d-%02d-%02d-", previousDate.year, previousDate.month, previousDate.day);
	switch (previousDate.weekDay) {
		case SUNDAY: printf("�Ͽ���\n"); break;
		case MONDAY: printf("������\n"); break;
		case TUESDAY: printf("ȭ����\n"); break;
		case WEDNESDAY: printf("������\n"); break;
		case THURSDAY: printf("�����\n"); break;
		case FRIDAY: printf("�ݿ���\n"); break;
		case SATURDAY: printf("�����\n"); break;
		default: break;
	}
	
	//���ĳ�¥
	nextDate = today.NextDate(&today, 4);
	printf("%4d-%02d-%02d-", nextDate.year, nextDate.month, nextDate.day);
	switch (nextDate.weekDay) {
		case SUNDAY: printf("�Ͽ���\n"); break;
		case MONDAY: printf("������\n"); break;
		case TUESDAY: printf("ȭ����\n"); break;
		case WEDNESDAY: printf("������\n"); break;
		case THURSDAY: printf("�����\n"); break;
		case FRIDAY: printf("�ݿ���\n"); break;
		case SATURDAY: printf("�����\n"); break;
		default: break;
	}

	//������
	ret = tommorrow.IsEqual(&tommorrow, &today);
	if (ret == TRUE) {
		printf("�����ϴ�.\n");
	}
	else {
		printf("���� �ʽ��ϴ�.\n");
	}

	//�ٸ���
	ret = yesterday.IsNotEqual(&yesterday, &today);
	if (ret == TRUE) {
		printf("�ٸ��ϴ�.\n");
	}
	else {
		printf("�ٸ��� �ʽ��ϴ�.\n");
	}

	//��ū��
	ret = today.IsGreaterThen(&today, &yesterday);
	if (ret == TRUE) {
		printf("�� �����Դϴ�.\n");
	}
	else {
		printf("�� ������ �ƴմϴ�.\n");
	}

	//��������
	ret = previousDate.IsLesserThen(&previousDate, &nextDate);
	if (ret == TRUE) {
		printf("�� �����Դϴ�.\n");
	}
	else {
		printf("�� ������ �ƴմϴ�.\n");
	}

	//�����.
	Destroy(&date);
	Destroy(&today);
	Destroy(&yesterday);
	Destroy(&tommorrow);
	Destroy(&previousDate);
	Destroy(&nextDate);

	return 0;
}