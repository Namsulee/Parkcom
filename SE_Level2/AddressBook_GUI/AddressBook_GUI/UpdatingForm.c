//UpdatingForm.c
/*
파일 명칭 : UpdatingForm.c
기     능 : 메인 프레임 윈도우에 필요한 함수들에 대해서 구현한다.
작 성 자 : Joey
작성 일자 : 2017/02/23
*/

//전처리기
#include "UpdatingForm.h"
#include "AddressBook.h"
#include "resource.h"
#include <CommCtrl.h>
#include <stdlib.h>

//함수 정의

/*
함수 명칭 : UpdatingFormProc
기    능 : UpdatingForm에서 메시지에 따라서 함수를 호출한다.
출    력 : 함수 호출 결과
입    력 : 윈도우핸들, 메시지, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL CALLBACK UpdatingFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	BOOL ret;

	switch (message) {
		case WM_INITDIALOG :
			ret = UpdatingForm_OnInitDialog(hWnd, wParam, lParam); break;
		case WM_COMMAND :
			ret = UpdatingForm_OnCommand(hWnd, wParam, lParam); break;
		case WM_NOTIFY :
			ret = UpdatingForm_OnNotify(hWnd, wParam, lParam); break;
		case WM_CLOSE :
			ret = UpdatingForm_OnClose(hWnd, wParam, lParam); break;
		default :
			ret = FALSE; break;
	}

	return ret;
}

/*
함수 명칭 : UpdatingForm_OnInitDialog
기    능 : 메인 프레임 윈도우가 생성될 떄, 주소록을 만들고 리스트뷰 헤더를 생성한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL UpdatingForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;
	LVCOLUMN column = { 0, };

	//1.1. 주소록을 만든다.
	addressBook = (AddressBook *)malloc(sizeof(AddressBook));
	Create(addressBook, 60000);
	SetWindowLong(hWnd, GWL_USERDATA, (LONG)addressBook);

	//1.2. 리스트뷰 헤더를 생성한다.
	column.mask = LVCF_TEXT | LVCF_WIDTH;
	column.pszText = "번호";
	column.cx = 50;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&column);

	column.pszText = "성명";
	column.cx = 100;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&column);

	column.pszText = "주소";
	column.cx = 100;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&column);

	column.pszText = "전화번호";
	column.cx = 100;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&column);

	column.pszText = "이메일주소";
	column.cx = 100;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&column);

	return FALSE;
}

/*
함수 명칭 : UpdatingForm_OnCommand
기    능 : Command 이벤트에 대해서 해당 함수를 호출한다.
출    력 : 함수 호출 결과
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL UpdatingForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BOOL ret;

	switch (LOWORD(wParam)) {
		case IDC_BUTTON_RECORD :
			ret = UpdatingForm_OnRecordButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_FIND :
			ret = UpdatingForm_OnFindButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_CORRECT :
			ret = UpdatingForm_OnCorrectButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_ERASE :
			ret = UpdatingForm_OnEraseButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_ARRANGE :
			ret = UpdatingForm_OnArrangeButtonClicked(hWnd, wParam, lParam); break;
		default:
			ret = FALSE; break;
	}

	return ret;
}

/*
함수 명칭 : UpdatingForm_OnNotify
기    능 : 리스트뷰에 대한 이벤트에 따라서 함수를 호출한다.
출    력 : 함수 실행 결과
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL UpdatingForm_OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BOOL ret;

	switch (wParam) {
		case IDC_LIST_PERSONALS :
			ret = UpdatingForm_OnListViewItemDoubleClicked(hWnd, wParam, lParam); break;
		default:
			ret = FALSE; break;
	}

	return ret;
}

/*
함수 명칭 : UpdatingForm_OnClose
기    능 : 닫기를 클릭했을 때, 주소록을 없애고, 프레임 윈도우를 닫는다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL UpdatingForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;

	//8.1. 주소록을 없앤다.
	addressBook = (AddressBook *)GetWindowLong(hWnd, GWL_USERDATA);
	if (addressBook != NULL) {
		free(addressBook);
		addressBook = NULL;
	}

	//8.2. 윈도우를 닫는다.
	EndDialog(hWnd, 0);

	return FALSE;
}

/*
함수 명칭 : UpdatingForm_OnRecordButtonClicked
기    능 : 기재하기 버튼이 눌렸을 때, 이벤트를 처리한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL UpdatingForm_OnRecordButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;
	TCHAR name[NAME];
	TCHAR address[ADDRESS];
	TCHAR telephoneNumber[TELEPHONENUMBER];
	TCHAR emailAddress[EMAILADDRESS];
	Long index;
	LVITEM item = { 0, };
	TCHAR number[NUMBER];

	//버튼이 클릭될 경우에만 수행한다.
	if (HIWORD(wParam) == BN_CLICKED) {
		//2.1. 개인을 읽는다.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_NAME), WM_GETTEXT, (WPARAM)NAME, (LPARAM)name);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_ADDRESS), WM_GETTEXT, (WPARAM)ADDRESS, (LPARAM)address);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_TELEPHONENUMBER), WM_GETTEXT, (WPARAM)TELEPHONENUMBER, (LPARAM)telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_EMAILADDRESS), WM_GETTEXT, (WPARAM)EMAILADDRESS, (LPARAM)emailAddress);
		
		//2.2. 주소록에 기재하다.
		addressBook = (AddressBook *)GetWindowLong(hWnd, GWL_USERDATA);
		index = Record(addressBook, name, address, telephoneNumber, emailAddress);

		//2.3. 리스트뷰 컨트롤의 항목을 추가한다.
		item.mask = LVIF_TEXT;
		item.iItem = index;
		
		item.iSubItem = 0;
		sprintf(number, "%d", index + 1);
		item.pszText = number;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&item);

		item.iSubItem = 1;
		item.pszText = addressBook->personals[index].name;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 2;
		item.pszText = addressBook->personals[index].address;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 3;
		item.pszText = addressBook->personals[index].telephoneNumber;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 4;
		item.pszText = addressBook->personals[index].emailAddress;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);
	}

	return FALSE;
}

/*
함수 명칭 : UpdatingForm_OnFindButtonClicked
기    능 : 찾기 버튼이 눌렸을 때, 찾기 프레임 윈도우를 출력한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL UpdatingForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	// 찾기 버튼이 클릭되었을 때,
	if (HIWORD(wParam) == BN_CLICKED) {
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_FINDINGFORM), hWnd, FindingFormProc);
	}
	return FALSE;
}

/*
함수 명칭 : UpdatingForm_OnCorrectButtonClicked
기    능 : 고치기 버튼이 눌렸을 때, 이벤트를 처리한다. 
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL UpdatingForm_OnCorrectButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;
	TCHAR address[ADDRESS];
	TCHAR telephoneNumber[TELEPHONENUMBER];
	TCHAR emailAddress[EMAILADDRESS];
	LVITEM item = { 0, };
	Long index;

	//버튼이 클릭될 경우에만 수행한다.
	if (HIWORD(wParam) == BN_CLICKED) {
		//5.1. 주소, 전화번호, 이메일주소를 읽는다.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_ADDRESS), WM_GETTEXT, (WPARAM)ADDRESS, (LPARAM)address);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_TELEPHONENUMBER), WM_GETTEXT, (WPARAM)TELEPHONENUMBER, (LPARAM)telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_EMAILADDRESS), WM_GETTEXT, (WPARAM)EMAILADDRESS, (LPARAM)emailAddress);

		//5.2. 리스트뷰 컨트롤에서 위치를 읽는다.
		index = SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETSELECTIONMARK, (WPARAM)0, (LPARAM)0);

		//5.3. 주소록을 고친다.
		addressBook = (AddressBook *)GetWindowLong(hWnd, GWL_USERDATA);
		index = Correct(addressBook, index, address, telephoneNumber, emailAddress);

		//5.4. 리스트뷰 컨트롤 항목을 변경한다.
		item.mask = LVIF_TEXT;
		item.iItem = index;

		item.iSubItem = 2;
		item.pszText = addressBook->personals[index].address;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 3;
		item.pszText = addressBook->personals[index].telephoneNumber;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 4;
		item.pszText = addressBook->personals[index].emailAddress;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);
	}
	return FALSE;
}

/*
함수 명칭 : UpdatingForm_OnEraseButtonClicked
기    능 : 지우기 버튼이 눌렸을 때, 이벤트를 처리한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL UpdatingForm_OnEraseButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;
	Long index;
	//Long ListViewIndex;
	LVITEM item = { 0, };
	TCHAR number[NUMBER];
	Long i;

	//버튼이 클릭될 경우에만 수행한다.
	if (HIWORD(wParam) == BN_CLICKED) {
		//6.1. 리스트뷰 컨트롤에서 위치를 읽는다.
		index = SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETSELECTIONMARK, (WPARAM)0, (LPARAM)0);

		//6.2. 주소록에서 지운다.
		addressBook = (AddressBook *)GetWindowLong(hWnd, GWL_USERDATA);
		index = Erase(addressBook, index);

		//6.3. 리스트뷰 컨트롤에 항목을 지운다.
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_DELETEITEM, (WPARAM)index, (LPARAM)0);

		//6.4. 실행줄 이후부터 마지막줄까지 번호를 고친다.
		item.mask = LVIF_TEXT;
		item.iSubItem = 0;

		i = index;
		while (i < addressBook->length) {
			item.iItem = i;
			sprintf(number, "%d", i + 1);			
			item.pszText = number;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);
			i++;
		}
	}

	return FALSE;
}

/*
함수 명칭 : UpdatingForm_OnArrangeButtonClicked
기    능 : 정리하기 버튼이 눌렸을 때, 이벤트를 처리한다.
출    력 :
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL UpdatingForm_OnArrangeButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;
	LVITEM item = { 0, };
	Long i = 0;
	TCHAR number[NUMBER];

	//버튼이 클릭될 경우에만 수행한다.
	if (HIWORD(wParam) == BN_CLICKED) {
		//7.1. 주소를 정리한다.
		addressBook = (AddressBook *)GetWindowLong(hWnd, GWL_USERDATA);
		Arrange(addressBook);

		//7.2. 리스트뷰 컨트롤 항목을 지운다.
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_DELETEALLITEMS, (WPARAM)0, (LPARAM)0);

		//7.3. 주소록의 사용량만큼 리스트 컨트롤에 항목을 추가한다.
		item.mask = LVIF_TEXT;
		while (i < addressBook->length) {
			item.iItem = i;

			item.iSubItem = 0;
			sprintf(number, "%d", i + 1);
			item.pszText = number;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&item);

			item.iSubItem = 1;
			item.pszText = addressBook->personals[i].name;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			item.iSubItem = 2;
			item.pszText = addressBook->personals[i].address;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			item.iSubItem = 3;
			item.pszText = addressBook->personals[i].telephoneNumber;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			item.iSubItem = 4;
			item.pszText = addressBook->personals[i].emailAddress;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			i++;
		}
	}

	return FALSE;
}

/*
함수 명칭 : UpdatingForm_OnListViewItemDoubleClicked
기    능 :
출    력 :
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL UpdatingForm_OnListViewItemDoubleClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	Long index;
	TCHAR name[NAME];
	TCHAR address[ADDRESS];
	TCHAR telephoneNumber[TELEPHONENUMBER];
	TCHAR emailAddress[EMAILADDRESS];
	LVITEM item = { 0, };

	//버튼이 더블 클릭될 경우에만 수행한다.
	if (((NMHDR *)lParam) == NM_DBLCLK) {
		//4.1. 리스트뷰 컨트롤에서 위치를 읽는다.
		index = SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETSELECTIONMARK, (WPARAM)0, (LPARAM)0);

		//4.2. 선택한 항목을 읽는다.
		item.mask = LVIF_TEXT;
		item.iItem = index;

		item.iSubItem = 1;
		item.pszText = name;
		item.cchTextMax = NAME;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 2;
		item.pszText = address;
		item.cchTextMax = ADDRESS;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 3;
		item.pszText = telephoneNumber;
		item.cchTextMax = TELEPHONENUMBER;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 4;
		item.pszText = emailAddress;
		item.cchTextMax = EMAILADDRESS;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		//4.3. 선택한 항목을 개인에 출력한다.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_NAME), WM_SETTEXT, (WPARAM)0, (LPARAM)name);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_ADDRESS), WM_SETTEXT, (WPARAM)0, (LPARAM)address);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_TELEPHONENUMBER), WM_SETTEXT, (WPARAM)0, (LPARAM)telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_EMAILADDRESS), WM_SETTEXT, (WPARAM)0, (LPARAM)emailAddress);
	}

	return FALSE;
}
