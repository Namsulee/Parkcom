//Contents.cpp
#include "Contents.h"

Contents::Contents() {

}

Contents::Contents(const Contents& source) {

}

Contents::~Contents() {

}

//�Լ� ���𿡼� ���ǵ� �̸� ����
//Long Contents::Add(Contents *contens) { return -1; };
//Contents* Contents::GetAt(Long index) { return 0; };
//Long Contents::Remove(Long index) { return -1; };
//Contents* Contents::operator [] (Long index) { return 0; };

Contents& Contents::operator = (const Contents& source) {
	return *this;
}