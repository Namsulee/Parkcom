#pragma once
//BusinessCardBinderFindingForm.h
#ifndef _BUSINESSCARDBINDERFINDINGFORM_H
#define _BUSINESSCARDBINDERFINDINGFORM_H
#include <Windows.h>

//함수선언
BOOL CALLBACK BusinessCardBinderFindingFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL BusinessCardBinderFindingForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL BusinessCardBinderFindingForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL BusinessCardBinderFindingForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL BusinessCardBinderFindingForm_OnChoiceButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL BusinessCardBinderFindingForm_OnFirstButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL BusinessCardBinderFindingForm_OnPreviousButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL BusinessCardBinderFindingForm_OnNextButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL BusinessCardBinderFindingForm_OnLastButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);

#endif //_BUSINESSCARDBINDERFINDINGFORM_H