//AddressBook.c
/*
���� ��Ī : AddressBook.c
��     �� : �ּҷ��� �����Ѵ�.
��     �� : ����
��     �� : ����
�� �� �� : Joey
�ۼ� ���� : 2016/2/19
*/

//��ó����
#include "AddressBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

//�Լ�����
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
�Լ� ��Ī : Record
��     �� : �Է¹��� ����, �ּ�, ��ȭ��ȣ, �̸����ּҸ� �ּҷϿ� �Է��Ѵ�.
��     �� : �ּҷ�, ����, �ּ�, ��ȭ��ȣ, �̸����ּ�
��     �� : �ּҷ�, �ٹ�ȣ
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
�Լ� ��Ī : Find
��     �� : ������ �Է¹ް� ����� ��ġ�ϴ� �ٵ�� ������ ����Ѵ�.
��     �� : �ּҷ�, ����
��     �� : �ּҷ�, �ٹ�ȣ��, ����
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
�Լ� ��Ī : Correct
��     �� : �ּҷϿ� �Է¹��� �ٹ�ȣ�� �Է¹��� �ּ�, ��ȭ��ȣ, �̸����ּҷ� �����Ѵ�.
��     �� : �ּҷ�, �ٹ�ȣ, �ּ�, ��ȭ��ȣ, �̸����ּ�
��     �� : �ּҷ�, �ٹ�ȣ
*/
Long Correct(AddressBook *addressBook, Long index, char(*address), char(*telephoneNumber), char(*emailAddress)){
	strcpy(addressBook->personals[index].address, address);
	strcpy(addressBook->personals[index].telephoneNumber, telephoneNumber);
	strcpy(addressBook->personals[index].emailAddress, emailAddress);
	return index;
}

/*
�Լ� ��Ī : Erase
��     �� : �ּҷ��� �ٹ�ȣ�� �����ϰ� �ٹ�ȣ(-1)�� ����Ѵ�.
��     �� : �ּҷ�, �ٹ�ȣ
��     �� : �ּҷ�, �ٹ�ȣ(-1)
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
�Լ� ��Ī : Arrange
��     �� : �ּҷ��� �ԷµǸ� ������������ �����Ѵ�.
��     �� : �ּҷ�
��     �� : �ּҷ�
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
�Լ� ��Ī : Create
��     �� : �Է¹��� ��ü�ټ� ��ŭ�� ���ε��� �����Ѵ�.
��     �� : �ּҷ�, ��ü�ټ�
��     �� : �ּҷ�
*/
void Create(AddressBook *addressBook, Long capacity) {
	addressBook->personals = (Personal(*))calloc(capacity, sizeof(Personal));
	addressBook->capacity = capacity;
	addressBook->length = 0;
}

/*
�Լ� ��Ī : Destroy
��     �� : �ּҷ��� �����Ѵ�.
��     �� : �ּҷ�
��     �� : ����
*/
void Destroy(AddressBook *addressBook) {
	if (addressBook->personals != NULL) {
		free(addressBook->personals);
	}
}

/*
�Լ� ��Ī : Load
��     �� : dat���Ͽ��� ���ε��� �ּҷϿ� �����Ѵ�.
��     �� : �ּҷ�
��     �� : ���ε��� ��
�ۼ� ���� : 2017/02/25
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
		//1.1. ����, �ּ�, ��ȭ��ȣ, �̸����ּҸ� �д´�.
		//fscanf(file, "%s %s %s %s", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);
		flag = fread(&personal, sizeof(Personal), 1, file);
		//1. ������ ���� �ƴѵ��� �ݺ��Ѵ�.
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
			
			//1.2. �ּҷϿ� ����, �ּ�, ��ȭ��ȣ, �̸����ּҸ� �����Ѵ�.
			index = i;
			addressBook->personals[index] = personal;
			(addressBook->length)++;

			//1.3. ������ ����.
			count++;

			//1.1. ����, �ּ�, ��ȭ��ȣ, �̸����ּҸ� �д´�.
			//fscanf(file, "%s %s %s %s", personal.name, personal.address, personal.telephoneNumber, personal.emailAddress);
			fread(&personal, sizeof(Personal), 1, file);
		}
		fclose(file);
	}
	//2. ������ ����Ѵ�.	
	return count;

	//3. ������.
}

/*
�Լ� ��Ī : Save
��     �� : �ּҷ��� ���ε��� dat���Ͽ� �����Ѵ�.
��     �� : �ּҷ�
��     �� : ���ε��� ��
�ۼ� ���� : 2017/02/25
*/
Long Save(AddressBook *addressBook) {
	Long count = 0;
	Long i = 0;
	FILE *file;

	//file = fopen("AddressBook.txt", "wt");
	file = fopen("AddressBook.dat", "wb");

	if (!feof(file)) {
		//1. �ּҷ��� ��뷮 ��ŭ �ݺ��Ѵ�.
		while (i < addressBook->length) {
			//1.1. ���Ͽ� ����, �ּ�, ��ȭ��ȣ, �̸����ּҸ� �����Ѵ�.
			//fprintf(file, "%s %s %s %s\n", addressBook->personals[i].name, addressBook->personals[i].address,
			//	addressBook->personals[i].telephoneNumber, addressBook->personals[i].emailAddress);
			fwrite(addressBook->personals + i, sizeof(Personal), 1, file);
			
			//1.2. ������ ����.
			count++;
			i++;
		}
		fclose(file);
	}

	//2. ������ ����Ѵ�.
	return count;

	//3. ������.
}