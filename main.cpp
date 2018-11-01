#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "Lecture.h"
#include "Purchase.h"
#include <vector>
#include <fstream>
#include "recfile.h"
#include <cstring>

#define LEN_BUFFER 256
using namespace std;

bool readMember(vector<Member> &member_list);
bool readLecture(vector<Lecture> &lecture_list);
bool readPurchase(vector<Purchase> &purchase_list);

void showMember(vector<Member> &member_list);
void showLecture(vector<Lecture> &lecture_list);
void showPurchase(vector<Purchase> &purchase_list);

void memberTest();
void lectureTest();
void purchaseTest();

void printMenu();

void lecturePurchaseSystem();
void searchRecord();
void insertRecord();
void deleteRecord();
void modifyRecord();

int main(void) {
	vector<Member> member_list;
	vector<Lecture> lecture_list;
	vector<Purchase> purchase_list;

	if (!readMember(member_list) || !readLecture(lecture_list) || !readPurchase(purchase_list))
		return 0;
	
	while (true) {
		int menu;
		printMenu();
		cin >> menu;
		cout << endl;
		switch (menu) {
		case 1:
			showMember(member_list);
			break;
		case 2:
			showLecture(lecture_list);
			break;
		case 3:
			showPurchase(purchase_list);
			break;
		case 4:
			memberTest();
			break;
		case 5:
			lectureTest();
			break;
		case 6:
			purchaseTest();
			break;
		case 7:
			lecturePurchaseSystem();
			break;
		}
	}

	return 0;
}


void printMenu() {
	cout << "1. showMember" << endl;
	cout << "2. showLecture" << endl;
	cout << "3. showPurchase" << endl;
	cout << "4. memberTest" << endl;
	cout << "5. lectureTest" << endl;
	cout << "6. purchaseTest" << endl;
	cout << "7. lecturePurchaseSystem" << endl << endl;
	cout << "Select Menu : ";
}

void lecturePurchaseSystem() {
	DelimFieldBuffer buffer('|', LEN_BUFFER);
	RecordFile <Member> MemberFile(buffer);
	RecordFile <Lecture> LectureFile(buffer);
	RecordFile <Purchase> PurchaseFile(buffer);

	MemberFile.Open("fileOfMember.dat", ios::in);
	LectureFile.Open("fileOfLecture.dat", ios::in);
	PurchaseFile.Open("fileOfPurchase.dat", ios::in);

	while (true) {
		int menu;
		cout << "1. Search record" << endl;
		cout << "2. Insert record" << endl;
		cout << "3. Delete record" << endl;
		cout << "4. Modify record" << endl;
		cout << "0. Back to menu" << endl << endl;
		cout << ">> ";
		
		cin >> menu;
		cout << endl;
		switch (menu) {
		case 1:
			searchRecord();
			break;
		case 2:
			insertRecord();
			break;
		case 3:
			deleteRecord();
			break;
		case 4:
			modifyRecord();
			break;
		case 0:
			return;
		}
	}	
}
