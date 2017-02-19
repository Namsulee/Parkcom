#ifndef _FORM_H
#define _FORM_H

//전방선언
typedef struct _addressBook AddressBook;

//함수선언
void DisplayMenu();
void FormForRecording(AddressBook *addressBook);
void FormForFinding(AddressBook *addressBook);
void FormForCorrecting(AddressBook *addressBook);
void FormForErasing(AddressBook *addressBook);
void FormForArranging(AddressBook *addressBook);
void FormForViewAll(AddressBook *addressBook);

#endif //_FORM_H