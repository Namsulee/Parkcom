//AddressBook.c
/*
���� ��Ī : AddressBook.c
��    �� : �迭 ���̺귯���� ����ؼ� �ּҷ��� �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
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
	index = Record(&addressBook, "ȫ�浿", "����� ���ʱ�", "025879424", "hong@");
	personal = AddressBook_GetAt(&addressBook, index);
	printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);

	index = Record(&addressBook, "��浿", "��õ�� �߱�", "0325879424", "ko@");
	personal = AddressBook_GetAt(&addressBook, index);
	printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);

	index = Record(&addressBook, "ȫ�浿", "������ ����", "0425879424", "gil@");
	personal = AddressBook_GetAt(&addressBook, index);
	printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);

	index = Record(&addressBook, "�ڱ浿", "�뱸�� �޼���", "0525879424", "park@");
	personal = AddressBook_GetAt(&addressBook, index);
	printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);

	//Find
	Find(&addressBook, "ȫ�浿", &indexes, &count);
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
	Find(&addressBook, "�ڱ浿", &indexes, &count);
	index = Correct(&addressBook, indexes[0], "�λ�� �ؿ�뱸", "0545879424", "dong@");
	personal = AddressBook_GetAt(&addressBook, index);
	printf("%s %s %s %s\n", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);
	
	if (indexes != NULL) {
		free(indexes);
		indexes = NULL;
	}

	//Erase
	Find(&addressBook, "ȫ�浿", &indexes, &count);
	index = Erase(&addressBook, indexes[0]);
	if (index == -1) {
		printf("�������ϴ�.\n");
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
�Լ� ��Ī : AddressBook_Create
��     �� : �ּҷ��� �غ��Ѵ�.
��     �� : �ּҷ� ��뷮
��     �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
*/
void AddressBook_Create(AddressBook *addressBook, Long capacity) {
	Create(&addressBook->personals, capacity, sizeof(Personal));
	addressBook->capacity = capacity;
	addressBook->length = 0;
}

/*
�Լ� ��Ī : Load
��     �� : ��ũ������ �ּҸ� �ּҷ����� �ҷ��´�.
��     �� : ����
��     �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
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
�Լ� ��Ī : Record
��     �� : ������ �ּҷϿ� �����Ѵ�.
��     �� : ����, �ּ�, ��ȭ��ȣ, �̸����ּ�
��     �� : ��ġ
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
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
�Լ� ��Ī : Find
��     �� : �ּҷϿ� �Է¹��� ����� ������ ���ε��� ã�´�.
��     �� : ����
��     �� : ��ġ��, ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
*/
void Find(AddressBook *addressBook, char(*name), Long *(*indexes), Long *count) {
	LinearSearchDuplicate(&addressBook->personals, name, indexes, count, sizeof(Personal), CompareNames);
}

/*
�Լ� ��Ī : AddressBook_GetAt
��     �� : �ش� ��ġ�� ������ ����Ѵ�.
��     �� : ��ġ
��     �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
*/
Personal AddressBook_GetAt(AddressBook *addressBook, Long index) {
	Personal personal;
	GetAt(&addressBook->personals, index, &personal, sizeof(Personal));
	return personal;
}

/*
�Լ� ��Ī : Correct
��     �� : �ּҷϿ��� ������ ������ �ּ�, ��ȭ��ȣ, �̸����ּҸ� ��ģ��.
��     �� : ��ġ, �ּ�, ��ȭ��ȣ, �̸����ּ�
��     �� : ��ġ
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
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
�Լ� ��Ī : Erase
��     �� : �ּҷϿ��� ������ �����.
��     �� : ��ġ
��     �� : ��ġ(-1)
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
*/
Long Erase(AddressBook *addressBook, Long index) {
	index = Delete(&addressBook->personals, index, sizeof(Personal));
	addressBook->length--;
	addressBook->capacity--;
	return index;
}

/*
�Լ� ��Ī : Arrange
��     �� : �ּҷ��� ������ ������������ �����Ѵ�.
��     �� : ����
��     �� : ����
�� �� �� : Jeoy
�ۼ� ���� : 2017/03/12
*/
void Arrange(AddressBook *addressBook) {
	InsertionSort(&addressBook->personals, sizeof(Personal), ComparePersonals);
}

/*
�Լ� ��Ī : AddressBook_Destroy
��     �� : �ּҷ��� �����.
��     �� : ����
��     �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
*/
void AddressBook_Destroy(AddressBook *addressBook) {
	Destroy(&addressBook->personals);
}

/*
�Լ� ��Ī : Save
��     �� : �ּҷ��� ��ũ���Ͽ� �����Ѵ�.
��     �� : ����
��     �� : ����
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
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
�Լ� ��Ī : CompareNames
��     �� : ������ ����� �Է¹��� ������ ���Ѵ�.
��     �� : ����, ����
��     �� : ���(1, 0, -1)
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
*/
int CompareNames(void *one, void *other) {
	int ret;
	ret = strcmp(((Personal*)one)->name, (char(*))other);
	return ret;
}

/*
�Լ� ��Ī : ComparePersonals
��     �� : ����1�� ����2�� ���Ѵ�.
��     �� : ����1, ����2
��     �� : �񱳰��(1, 0, -1)
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
*/
int ComparePersonals(void *one, void *other) {
	int ret;
	ret = strcmp(((Personal*)one)->name, ((Personal*)other)->name);
	return ret;
}