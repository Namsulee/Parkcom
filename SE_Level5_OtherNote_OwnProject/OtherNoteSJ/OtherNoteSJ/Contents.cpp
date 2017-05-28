//Contents.cpp
#include "Contents.h"

Contents::Contents() {

}

Contents::Contents(const Contents& source) {

}

Contents::~Contents() {

}

//함수 선언에서 정의도 미리 해줌
//Long Contents::Add(Contents *contens) { return -1; };
//Contents* Contents::GetAt(Long index) { return 0; };
//Long Contents::Remove(Long index) { return -1; };
//Contents* Contents::operator [] (Long index) { return 0; };

Contents& Contents::operator = (const Contents& source) {
	return *this;
}