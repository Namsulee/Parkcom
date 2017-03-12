//UpdatingForm.h
/*
파일 명칭 : UpdatingForm.h
기    능 : 메인 프레임 윈도우에 필요한 함수들에 대해서 선언한다.
작 성 자 : Joey
작성 일자 : 2017/02/23
작업 일자 : 2017/03/01 UpdatingForm_OnFindingZipcodeButtonClicked 추가
*/

#ifndef _UPDAINGFORM_H
#define _UPDATINGFORM_H

#include <Windows.h>

//상수 정의
#define NUMBER 64

//함수선언
BOOL CALLBACK UpdatingFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnRecordButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnFindingZipcodeButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnCorrectButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnEraseButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnArrangeButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnListViewItemDoubleClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);

#endif //_UPDAINGFORM_H
