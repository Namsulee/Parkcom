//FindingZipcodeForm.c
/*
파일 명칭 : FindingZipcodeForm.h
기    능 : 우편번호찾기기능의 사용자 인터페이스에 대해서 제공한다.
작 성 자 : Joey
작성 일자 : 2017/03/01
*/

#include "FindingZipcodeForm.h"
#include "resource.h"
#include "PostalBook.h"
#include <CommCtrl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
함수 명칭 : WinMain
기     능 : 
입     력 : 
출     력 : 
*/
//BOOL CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int mCmdShow) {
//	int response;
//	response = DialogBox(hInstance, MAKEINTRESOURCE(IDD_POSTALBOOK), NULL, FindingZipcodeFormProc);
//	return response;
//}

/*
함수 명칭 : FindingZipcodeFormProc
기     능 : FindingZipcodeFormProc에서 메시지에 따라서 함수를 호출한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
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
함수 명칭 :FindingZipcodeForm_OnInitDialog
기     능 : 우편번호찾기 프레임윈도우가 생성될 때, 리스트뷰 헤더를 생성한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
*/
BOOL FindingZipcodeForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	PostalBook *postalBook;
	ULong count;
	LVCOLUMN column = { 0, };

	//1.1. 우편번호부를 준비한다.
	postalBook = (PostalBook *)malloc(sizeof(PostalBook));
	PostalBook_Create(postalBook, 60000);
	//1.2. 주소들을 적재한다.
	count = PostalBook_Load(postalBook);
	SetWindowLong(hWnd, GWL_USERDATA, (LONG)postalBook);
	//1.3. 리스트뷰 헤더를 생성한다.
	// LVM_INSERTCOLUMN,
	// wParam: Index of the new column.
	// lParam: Pointer to an LVCOLUMN structure that contains the attributes of the new column.
	column.mask = LVCF_TEXT | LVCF_WIDTH;
	column.pszText = "번호";
	column.cx = 50;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&column);

	column.pszText = "주소";
	column.cx = 200;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&column);

	column.pszText = "우편번호";
	column.cx = 70;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&column);

	return FALSE;
}

/*
함수 명칭 :FindingZipcodeForm_OnCommand
기     능 : Command 이벤트에 대해서 해당 함수를 호출한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
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
함수 명칭 :FindingZipcodeForm_OnNotify
기    능 : 리스트뷰에 대한 이벤트에 따라서 함수를 호출한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
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
함수 명칭 :FindingZipcodeForm_OnClose
기    능 : 닫기를 클릭했을 때, 프레임 윈도우를 닫는다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
*/
BOOL FindingZipcodeForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	PostalBook *postalBook;
	postalBook = (PostalBook *)GetWindowLong(hWnd, GWL_USERDATA);
	//4.0. 메모리 할당 해제 한다.
	if (postalBook != NULL) {
		PostalBook_Destroy(postalBook);
		free(postalBook);
	}

	//4.1. 윈도우를 닫는다.
	EndDialog(hWnd, 0);

	return FALSE;
}

/*
함수 명칭 :FindingZipcodeForm_OnFindButtonClicked
기    능 : 찾기 버튼을 클릭했을 때, 찾기 기능을 수행한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
수정일자 : 2017/03/12
		배열라이브러리 사용으로 postalBook->addresses[indexes[i]] 표현 사용 불가(PostalBook_GetAt으로 사용)
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

	//버튼이 클릭될 경우에만 수행한다.
	if (HIWORD(wParam) == BN_CLICKED) {
		//1.1. 동을 읽는다.
		// WM_GETTEXT: 
		// wParam: The maximum number of characters to be copied
		// lParam: A pointer to the buffer that is to receive the text.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_DONG), WM_GETTEXT, (WPARAM)27, (LPARAM)inputDong);

		//1.2. 우편번호부에서 입력받은 동을 찾는다.
		postalBook = (PostalBook *)GetWindowLong(hWnd, GWL_USERDATA);
		PostalBook_Find(postalBook, inputDong, &indexes, &count);

		//1.3. 리스트뷰 항목들을 모두 지운다.
		// LVM_DELETEALLITEMS
		// wParam: Must be zero.
		// lParam: Must be zero.
		SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_DELETEALLITEMS, (WPARAM)0, (LPARAM)0);

		//1.4. 찾은 개수만큼 리스트뷰에 항목을 추가한다.
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
함수 명칭 :FindingZipcodeForm_OnListViewItemDoubleClicked
기    능 : 리스트뷰에 항목을 더블클릭할 때, 기능을 수행한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
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

		//Message Box로 띄우기 위해서 사용했고, 현재는 필요없는 내용임
		//item.iSubItem = 2;
		//item.pszText = zipcode;
		//item.cchTextMax = ZIPCODE;
		//SendMessage(GetDlgItem(hWnd, IDC_LIST_ADDRESSES), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);
		//sprintf(text, "%s\n%s", zipcode, completeAddress);
		//MessageBox(hWnd, (LPCTSTR)text, (LPCTSTR)"알림", MB_OK | MB_ICONEXCLAMATION);

		//3.3. 주소록 윈도우를 찾는다.
		addressBookWindow = FindWindow("#32770", "주소록");
		//3.4. 주소록 윈도우의 주소에 찾은 주소를 적는다.
		SendMessage(GetDlgItem(addressBookWindow, IDC_EDIT_ADDRESS), WM_SETTEXT, (WPARAM)0, (LPARAM)completeAddress);
		//3.5. 캐럿의 위치를 적은 문자 한칸뒤로 보낸다. (미해결)
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
