//FindingZipcodeForm.h
/*
파일 명칭 : FindingZipcodeForm.h
기    능 : 우편번호찾기기능의 사용자 인터페이스에 대해서 정의한다.
작 성 자 : Joey
작성 일자 : 2017/03/01
*/

#ifndef _FINDINGZIPCODEFORM_H
#define _FINDIINGZIPCODEFORM_H

#include <Windows.h> // 윈도우 컨트롤러 사용하기 위해서 기본적으로 추가

//상수 선언들
#define COMPLETEADDRESS 256
#define MAXTEXTSIZE 256

//함수선언들
BOOL CALLBACK FindingZipcodeFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnListViewItemDoubleClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);

#endif //_FINDINGZIPCODEFORM_H