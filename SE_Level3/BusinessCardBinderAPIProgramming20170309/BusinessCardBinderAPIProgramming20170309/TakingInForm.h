#pragma once
//TakingInForm.h

#ifndef _TAKINGINNFORM_H
#define _TAKINGINFORM_H
#include <Windows.h>

//함수 선언
BOOL CALLBACK TakingInFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL TakingInForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL TakingInForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL TakingInForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL TakingInForm_OnTakeInButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL TakingInForm_OnCompanyNameEditKillFocused(HWND hWnd, WPARAM wParam, LPARAM lParam);
#endif //_TAKINGINFORM_H
