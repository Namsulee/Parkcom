//FindingZipcodeForm.c
/*
���� ��Ī : FindingZipcodeForm.h
��    �� : �����ȣã������ ����� �������̽��� ���ؼ� �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/03/01
*/

#include "FindingZipcodeForm.h"
#include "resource.h"
#include "PostalBook.h"
#include <CommCtrl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
�Լ� ��Ī : WinMain
��     �� : 
��     �� : 
��     �� : 
*/
//BOOL CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int mCmdShow) {
//	int response;
//	response = DialogBox(hInstance, MAKEINTRESOURCE(IDD_POSTALBOOK), NULL, FindingZipcodeFormProc);
//	return response;
//}

/*
�Լ� ��Ī : FindingZipcodeFormProc
��     �� : FindingZipcodeFormProc���� �޽����� ���� �Լ��� ȣ���Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
*/
BOOL CALLBACK FindingZipcodeFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	BOOL ret;

	switch (message) {
	case WM_INITDIALOG:
		ret = FindingZipcodeForm_OnInitDialog(hWnd, wParam, lParam); break;
	case WM_COMMAND:
		ret = FindingZipcodeForm_OnCommand(hWnd, wParam, lParam); break;
	case WM_NOTIFY:
		ret = FindingZipcodeForm_OnNotify(hWnd, wParam, lParam); break;
	case WM_CLOSE:
		ret = FindingZipcodeForm_OnClose(hWnd, wParam, lParam); break;
	default:
		ret = FALSE; break;
	}

	return ret;

}

/*
�Լ� ��Ī :FindingZipcodeForm_OnInitDialog
��     �� : �����ȣã�� �����������찡 ������ ��, ����Ʈ�� ����� �����Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
*/
BOOL FindingZipcodeForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	PostalBook *postalBook;
	ULong count;
	LVCOLUMN column = { 0, };

	//1.1. �����ȣ�θ� �غ��Ѵ�.
	postalBook = (PostalBook *)malloc(sizeof(PostalBook));
	PostalBook_Create(postalBook, 60000);
	//1.2. �ּҵ��� �����Ѵ�.
	count = PostalBook_Load(postalBook);
	SetWindowLong(hWnd, GWL_USERDATA, (LONG)postalBook);
	//1.3. ����Ʈ�� ����� �����Ѵ�.
	// LVM_INSERTCOLUMN,
	// wParam: Index of the new column.
	// lParam: Pointer to an LVCOLUMN structure that contains the attributes of the new column.
	column.mask = LVCF_TEXT | LVCF_WIDTH;
	column.pszText = "��ȣ";
	column.cx = 50;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&column);

	column.pszText = "�ּ�";
	column.cx = 200;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&column);

	column.pszText = "�����ȣ";
	column.cx = 70;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&column);

	return FALSE;
}

/*
�Լ� ��Ī :FindingZipcodeForm_OnCommand
��     �� : Command �̺�Ʈ�� ���ؼ� �ش� �Լ��� ȣ���Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
*/
BOOL FindingZipcodeForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam){
	BOOL ret;

	switch (LOWORD(wParam)) {
	case IDC_BUTTON_FIND:
		ret = FindingZipcodeForm_OnFindButtonClicked(hWnd, wParam, lParam); break;
	default:
ret = FALSE; break;
	}

	return ret;
}

/*
�Լ� ��Ī :FindingZipcodeForm_OnNotify
��    �� : ����Ʈ�信 ���� �̺�Ʈ�� ���� �Լ��� ȣ���Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
*/
BOOL FindingZipcodeForm_OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BOOL ret;

	switch (wParam) {
	case IDC_LIST_ADDRESSES:
		ret = FindingZipcodeForm_OnListViewItemDoubleClicked(hWnd, wParam, lParam); break;
	default:
		ret = FALSE; break;
	}

	return ret;
}

/*
�Լ� ��Ī :FindingZipcodeForm_OnClose
��    �� : �ݱ⸦ Ŭ������ ��, ������ �����츦 �ݴ´�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
*/
BOOL FindingZipcodeForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	PostalBook *postalBook;
	postalBook = (PostalBook *)GetWindowLong(hWnd, GWL_USERDATA);
	//4.0. �޸� �Ҵ� ���� �Ѵ�.
	if (postalBook != NULL) {
		PostalBook_Destroy(postalBook);
		free(postalBook);
	}

	//4.1. �����츦 �ݴ´�.
	EndDialog(hWnd, 0);

	return FALSE;
}

/*
�Լ� ��Ī :FindingZipcodeForm_OnFindButtonClicked
��    �� : ã�� ��ư�� Ŭ������ ��, ã�� ����� �����Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�������� : 2017/03/12
		�迭���̺귯�� ������� postalBook->addresses[indexes[i]] ǥ�� ��� �Ұ�(PostalBook_GetAt���� ���)
*/
BOOL FindingZipcodeForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	PostalBook *postalBook;
	TCHAR inputDong[27];
	ULong(*indexes);
	ULong count;
	TCHAR totalAddress[MAXTEXTSIZE];
	TCHAR number[8];
	ULong i = 0;
	LVITEM item = { 0, };
	Address address;

	//��ư�� Ŭ���� ��쿡�� �����Ѵ�.
	if (HIWORD(wParam) == BN_CLICKED) {
		//1.1. ���� �д´�.
		// WM_GETTEXT: 
		// wParam: The maximum number of characters to be copied
		// lParam: A pointer to the buffer that is to receive the text.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_DONG), WM_GETTEXT, (WPARAM)27, (LPARAM)inputDong);

		//1.2. �����ȣ�ο��� �Է¹��� ���� ã�´�.
		postalBook = (PostalBook *)GetWindowLong(hWnd, GWL_USERDATA);
		PostalBook_Find(postalBook, inputDong, &indexes, &count);

		//1.3. ����Ʈ�� �׸���� ��� �����.
		// LVM_DELETEALLITEMS
		// wParam: Must be zero.
		// lParam: Must be zero.
		SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_DELETEALLITEMS, (WPARAM)0, (LPARAM)0);

		//1.4. ã�� ������ŭ ����Ʈ�信 �׸��� �߰��Ѵ�.
		// LVM_INSERTITEM
		// wParam: Must be zero.
		// lParam: Pointer to an LVITEM structure
		// LVM_SETITEMTEXT
		// wParam: Zero-based index of the list-view item
		// lParam: Pointer to an LVITEM structure. 
		item.mask = LVIF_TEXT;
		while (i < count) {
			item.iItem = i;

			item.iSubItem = 0;
			sprintf(number, "%d", i + 1);
			item.pszText = number;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&item);

			item.iSubItem = 1;
			address = PostalBook_GetAt(postalBook, i);
			sprintf(totalAddress, "%s %s %s %s %s", address.sido,
				address.gugun, address.dong, address.ri, address.bldg);
			if (strcmp(address.stBunji, "") != 0) {
				sprintf(totalAddress, "%s %s~%s", totalAddress, address.stBunji, address.edBunji);
			}
			item.pszText = totalAddress;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			item.iSubItem = 2;
			item.pszText = address.zipcode;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			i++;
		}
		if (indexes != NULL) {
			free(indexes);
			indexes = NULL;
		}
	}
	return FALSE;
}

/*
�Լ� ��Ī :FindingZipcodeForm_OnListViewItemDoubleClicked
��    �� : ����Ʈ�信 �׸��� ����Ŭ���� ��, ����� �����Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
*/
BOOL FindingZipcodeForm_OnListViewItemDoubleClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	PostalBook *postalBook;
	//TCHAR zipcode[ZIPCODE];
	TCHAR completeAddress[COMPLETEADDRESS];
	//TCHAR text[MAXTEXTSIZE];
	ULong index;
	LVITEM item = { 0, };
	HWND addressBookWindow;
	int textLength;

	//if (((LPNMHDR)lParam)->code == NM_DBLCLK) {
	if (((NMHDR *)lParam)->code == NM_DBLCLK) {
		postalBook = (PostalBook *)GetWindowLong(hWnd, GWL_USERDATA);
		index = SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_GETSELECTIONMARK, (WPARAM)0, (LPARAM)0);
		
		item.mask = LVIF_TEXT;
		item.iItem = index;

		item.iSubItem = 1;
		item.pszText = completeAddress;
		item.cchTextMax = COMPLETEADDRESS;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		//Message Box�� ���� ���ؼ� ����߰�, ����� �ʿ���� ������
		//item.iSubItem = 2;
		//item.pszText = zipcode;
		//item.cchTextMax = ZIPCODE;
		//SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);
		//sprintf(text, "%s\n%s", zipcode, completeAddress);
		//MessageBox(hWnd, (LPCTSTR)text, (LPCTSTR)"�˸�", MB_OK | MB_ICONEXCLAMATION);

		//3.3. �ּҷ� �����츦 ã�´�.
		addressBookWindow = FindWindow("#32770", "�ּҷ�");
		//3.4. �ּҷ� �������� �ּҿ� ã�� �ּҸ� ���´�.
		SendMessage(GetDlgItem(addressBookWindow, IDC_EDIT_ADDRESS), WM_SETTEXT, (WPARAM)0, (LPARAM)completeAddress);
		//3.5. ĳ���� ��ġ�� ���� ���� ��ĭ�ڷ� ������. (���ذ�)
		//SendMessage(GetDlgItem(addressBookWindow, IDC_BUTTON_FINDINGZIPCODE), WM_KILLFOCUS, NULL, (LPARAM)0);
		textLength = SendMessage(GetDlgItem(addressBookWindow, IDC_EDIT_ADDRESS), WM_GETTEXT, (WPARAM)COMPLETEADDRESS, (LPARAM)completeAddress);
		SendMessage(GetDlgItem(addressBookWindow, IDC_EDIT_ADDRESS), EM_SETSEL, (WPARAM)textLength, (LPARAM)textLength);
		SendMessage(GetDlgItem(addressBookWindow, IDC_EDIT_ADDRESS), WM_SETFOCUS, (WPARAM)0, (LPARAM)0);
		
		//3.6. 
		if (postalBook != NULL) {
			PostalBook_Destroy(postalBook);
			free(postalBook);
		}
		//3.7.
		EndDialog(hWnd, 0);
	}
	return FALSE;
}
