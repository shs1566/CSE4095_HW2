#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "Lecture.h"
#include "Purchase.h"
#include <vector>
#include <fstream>
#include "recfile.h"
#include <cstring>

#define LEN_BUFFER 256

void searchRecord() {
	int menu;
	cout << "1. Search Member" << endl;
	cout << "2. Search Lecture" << endl;
	cout << "3. Search Purchase" << endl;
	cout << "0. Back to menu" << endl << endl;
	cout << ">> ";
	cin >> menu;
	cout << endl;
	if (menu == 1) {
		string id;
		Member m, mRead;
		cout << "Please enter ID of member to search" << endl << endl;
		cout << ">> ";

		cin.ignore();
		getline(cin, id);
		cout << endl;

		m.update_id(id);
		DelimFieldBuffer buffer('|', LEN_BUFFER);
		RecordFile <Member> MemberFile(buffer);
		MemberFile.Open("fileOfMember.dat", ios::in);

		while (MemberFile.Read(mRead) != -1) {
			if (mRead == m) {
				cout << "Serach Result" << endl << endl;
				cout << mRead << endl << endl;
				MemberFile.Close();
				return;
			}
		}
		cout << "No result found" << endl << endl;
		MemberFile.Close();
	}
	if (menu == 2) {
		char lecture_id[LEN_LECTURE_ID + 1];
		Lecture l, lRead;
		cout << "Please enter ID of lecture to search" << endl << endl;
		cout << ">> ";

		cin.ignore();
		cin >> lecture_id;
		cout << endl;

		l.update_lecture_id(lecture_id);
		DelimFieldBuffer buffer('|', LEN_BUFFER);
		RecordFile <Lecture> LectureFile(buffer);
		LectureFile.Open("fileOfLecture.dat", ios::in);

		while (LectureFile.Read(lRead) != -1) {
			if (lRead == l) {
				cout << "Serach Result" << endl << endl;
				cout << lRead << endl << endl;
				LectureFile.Close();
				return;
			}
		}
		cout << "No result found" << endl << endl;
		LectureFile.Close();
	}
	if (menu == 3) {
		char purchase_id[LEN_PURCHASE_ID + 1];
		Purchase p, pRead;
		cout << "Please enter ID of purchase to search" << endl << endl;
		cout << ">> ";

		cin.ignore();
		cin >> purchase_id;
		cout << endl;

		p.update_purchase_id(purchase_id);
		DelimFieldBuffer buffer('|', LEN_BUFFER);
		RecordFile <Purchase> PurchaseFile(buffer);
		PurchaseFile.Open("fileOfPurchase.dat", ios::in);

		while (PurchaseFile.Read(pRead) != -1) {
			if (pRead == p) {
				cout << "Serach Result" << endl << endl;
				cout << pRead << endl << endl;
				PurchaseFile.Close();
				return;
			}
		}
		cout << "No result found" << endl << endl;
		PurchaseFile.Close();
	}
	if (menu == 0)
		return;
}