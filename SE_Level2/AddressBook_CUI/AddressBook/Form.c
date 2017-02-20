//Form.c
/*
���� ��Ī : Form.c
��     �� : ���θ޴�, �����ϱ�, ã��, ��ġ��, �����, �����ϱ�, ��ü���� ����� ȣ���ϴ� ���
��     �� : �ּҷ�
��     �� : ����
��  �� �� : �輼��
�ۼ� ���� : 2017/02/16
*/

//��ó����
#include "Form.h"
#include "AddressBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�Լ�����
/*
�Լ� ��Ī : DisplayMenu
��     �� : �޴� ��
��     �� : ����
��     �� : ����
*/
void DisplayMenu() {
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t      �ּҷ� Version 0.05\n");
	printf("\t\t\t      ======================\n");
	printf("\t\t\t      [1] �����ϱ�\n");
	printf("\t\t\t      [2] ã    ��\n");
	printf("\t\t\t      [3] �� ġ ��\n");
	printf("\t\t\t      [4] �� �� ��\n");
	printf("\t\t\t      [5] �����ϱ�\n");
	printf("\t\t\t      [6] ��ü����\n");
	printf("\t\t\t      [0] �� �� ��\n");
	printf("\t\t\t      ----------------------\n");
	printf("\t\t\t      �޴��� �����Ͻʽÿ� : ");
}

/*
�Լ� ��Ī : FormForRecording
��     �� : �����ϱ� ��
��     �� : �ּҷ�
��     �� : ����
*/
void FormForRecording(AddressBook *addressBook) {
	//�ڵ�����
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
		printf("\t    �ּҷ� Version 0.05 - �����ϱ�\n");
		printf("\t    =========================================================\n");
		printf("\t    ��      �� : "); fflush(stdin); scanf("%s", name);
		printf("\t    ��      �� : "); fflush(stdin); gets(address);
		printf("\t    ��ȭ  ��ȣ : "); fflush(stdin); scanf("%s", telephoneNumber);
		printf("\t    �̸����ּ� : "); fflush(stdin); scanf("%s", emailAddress);
		printf("\t    ---------------------------------------------------------\n");
		printf("\t    �����Ͻðڽ��ϱ�? (Yes/No) "); fflush(stdin); recording = getchar();
		if (recording == 'Y' || recording == 'y') {
			index = Record(addressBook, name, address, telephoneNumber, emailAddress);
			printf("\t    =========================================================\n");
			printf("\t    ��ȣ   ����        �ּ�        ��ȭ��ȣ        �̸����ּ�\n");
			printf("\t    ---------------------------------------------------------\n");
			printf("\t    %4d   %-12s%-12s%-16s%-12s\n", index + 1, addressBook->personals[index].name,
				addressBook->personals[index].address, addressBook->personals[index].telephoneNumber,
				addressBook->personals[index].emailAddress);
		}
		printf("\t    =========================================================\n");
		printf("\t    ����Ͻðڽ��ϱ�? (Yes/No) "); fflush(stdin); going = getchar();
	}
}

/*
�Լ� ��Ī : FormForFinding
��     �� : ã�� ��
��     �� : �ּҷ�
��     �� : ����
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
		printf("\t    �ּҷ� Version 0.05 - ã��\n");
		printf("\t    =========================================================\n");
		printf("\t    ��      �� : "); fflush(stdin); scanf("%s", name);
		printf("\t    =========================================================\n");
		printf("\t    ��ȣ   ����        �ּ�        ��ȭ��ȣ        �̸����ּ�\n");
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
		printf("\t    ����Ͻðڽ��ϱ�? (Yes/No) "); fflush(stdin); going = getchar();
	}
}

/*
�Լ� ��Ī : FormForCorrecting
��     �� : ��ġ�� ��
��     �� : �ּҷ�
��     �� : ����
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
		printf("\t    �ּҷ� Version 0.05 - ��ġ��\n");
		printf("\t    =========================================================\n");
		printf("\t    ��      �� : "); fflush(stdin); scanf("%s", name);
		printf("\t    =========================================================\n");
		printf("\t    ��ȣ   ����        �ּ�        ��ȭ��ȣ        �̸����ּ�\n");
		printf("\t    ---------------------------------------------------------\n");
		Find(addressBook, name, &indexes, &count);
		if (count > 0) {			
			for (i = 0; i < count; i++) {
				printf("\t    %4d   %-12s%-12s%-16s%-12s\n", index + 1, addressBook->personals[indexes[i]].name,
					addressBook->personals[indexes[i]].address, addressBook->personals[indexes[i]].telephoneNumber,
					addressBook->personals[indexes[i]].emailAddress);
			}
			printf("\t    =========================================================\n");
			printf("\t    ��      ȣ : "); fflush(stdin); scanf("%d", &number);
			printf("\t    ��      �� : "); fflush(stdin); gets(address);
			printf("\t    ��ȭ  ��ȣ : "); fflush(stdin); gets(telephoneNumber);
			printf("\t    �̸����ּ� : "); fflush(stdin); gets(emailAddress);
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
			printf("\t    ��ġ�ðڽ��ϱ�? (Yes/No) "); fflush(stdin); correcting = getchar();
			if (correcting == 'Y' || correcting == 'y') {
				index = Correct(addressBook, indexes[number - 1], address, telephoneNumber, emailAddress);
				printf("\t    =========================================================\n");
				printf("\t    ��ȣ   ����        �ּ�        ��ȭ��ȣ        �̸����ּ�\n");
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
		printf("\t    ����Ͻðڽ��ϱ�? (Yes/No) "); fflush(stdin); going = getchar();
	}
}

/*
�Լ� ��Ī : FormForErasing
��     �� : ����� ��
��     �� : �ּҷ�
��     �� : ����
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
		printf("\t    �ּҷ� Version 0.05 - �����\n");
		printf("\t    =========================================================\n");
		printf("\t    ��      �� : "); fflush(stdin); scanf("%s", name);
		printf("\t    =========================================================\n");
		printf("\t    ��ȣ   ����        �ּ�        ��ȭ��ȣ        �̸����ּ�\n");
		printf("\t    ---------------------------------------------------------\n");
		Find(addressBook, name, &indexes, &count);
		if (count > 0) {
			for (i = 0; i < count; i++) {
				printf("\t    %4d   %-12s%-12s%-16s%-12s\n", i + 1, addressBook->personals[indexes[i]].name,
					addressBook->personals[indexes[i]].address, addressBook->personals[indexes[i]].telephoneNumber,
					addressBook->personals[indexes[i]].emailAddress);
			}
			printf("\t    =========================================================\n");
			printf("\t    ��      ȣ : "); fflush(stdin); scanf("%d", &number);
			printf("\t    ---------------------------------------------------------\n");
			printf("\t    ��ȣ   ����        �ּ�        ��ȭ��ȣ        �̸����ּ�\n");
			printf("\t    ---------------------------------------------------------\n");
			printf("\t    %4d   %-12s%-12s%-16s%-12s\n", indexes[number - 1], addressBook->personals[indexes[number - 1]].name,
				addressBook->personals[indexes[number - 1]].address, addressBook->personals[indexes[number - 1]].telephoneNumber,
				addressBook->personals[indexes[number - 1]].emailAddress);
			printf("\t    =========================================================\n");
			printf("\t    ����ðڽ��ϱ�? (Yes/No) "); fflush(stdin); erasing = getchar();
			if (erasing == 'Y' || erasing == 'y') {
				index = Erase(addressBook, indexes[number - 1]);
				printf("\t    =========================================================\n");
				printf("\t    ���������ϴ�.\n");
			}
		}//if
		printf("\t    =========================================================\n");
		if (indexes != NULL) {
			free(indexes);
			indexes = NULL;
		}
		printf("\t    ����Ͻðڽ��ϱ�? (Yes/No) "); fflush(stdin); going = getchar();
	}
}

/*
�Լ� ��Ī : FormForArranging
��     �� : �����ϱ� ��
��     �� : �ּҷ�
��     �� : ����
*/
void FormForArranging(AddressBook *addressBook) {
	Long i = 0;
	Long j;

	Arrange(addressBook);
	while (i < addressBook->length) {
		system("cls");
		printf("\n\n\n\n");
		printf("\t    �ּҷ� Version 0.05 - �����ϱ�\n");
		printf("\t    =========================================================\n");
		printf("\t    ��ȣ   ����        �ּ�        ��ȭ��ȣ        �̸����ּ�\n");
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
		printf("\t    �ƹ�Ű�� ��������. "); fflush(stdin); getchar();
	}
}

/*
�Լ� ��Ī : FormForViewAll
��     �� : ��ü���� ��
��     �� : �ּҷ�
��     �� : ����
*/
void FormForViewAll(AddressBook *addressBook) {
	Long i = 0;
	Long j;

	//Arrange(addressBook);
	while (i < addressBook->length) {
		system("cls");
		printf("\n\n\n\n");
		printf("\t    �ּҷ� Version 0.05 - ��ü����\n");
		printf("\t    =========================================================\n");
		printf("\t    ��ȣ   ����        �ּ�        ��ȭ��ȣ        �̸����ּ�\n");
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
		printf("\t    �ƹ�Ű�� ��������. "); fflush(stdin); getchar();
	}
}