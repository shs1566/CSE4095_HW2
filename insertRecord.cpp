#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "Lecture.h"
#include "Purchase.h"
#include <vector>
#include <fstream>
#include "recfile.h"
#include <cstring>

#define LEN_BUFFER 256

void insertRecord() {
	int menu;
	cout << "1. Insert member record" << endl;
	cout << "2. Insert lecture record" << endl;
	cout << "3. Insert purchase record" << endl;
	cout << "0. Back to menu" << endl << endl;
	cout << ">> ";
	cin >> menu;
	cout << endl;

	if (menu == 1) {
		string id;
		Member m, mRead;
		cout << "Please enter ID of member to insert" << endl;
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
				cout << "Error : There is already " << id << endl << endl;
				MemberFile.Close();
				return;
			}
		}
		MemberFile.Close();

		MemberFile.Open("fileOfMember.dat", ios::out);
		string password;
		cout << "Enter a password: ";
		getline(cin, password);
		m.update_password(password);

		string name;
		cout << "Enter a name: ";
		getline(cin, name);
		m.update_name(name);

		string phoneNumber;
		cout << "Enter a phoneNumber: ";
		getline(cin, phoneNumber);
		m.update_phoneNumber(phoneNumber);

		string address;
		cout << "Enter a address: ";
		getline(cin, address);
		m.update_address(address);

		char mileage[LEN_MILEAGE];
		memset(mileage, '0', LEN_MILEAGE);
		m.update_mileage(mileage);

		MemberFile.Append(m);
		MemberFile.Close();
		cout << "Member is added sucessfully" << endl << endl;
	}

	if (menu == 2) {
		char lecture_id[LEN_LECTURE_ID + 1];
		Lecture l, lRead;
		cout << "Please enter ID of lecture to insert" << endl;
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
				cout << "Error : There is already " << lecture_id << endl << endl;
				LectureFile.Close();
				return;
			}
		}
		LectureFile.Close();

		LectureFile.Open("fileOfLecture.dat", ios::out);

		string subject;
		cout << "Enter a subject: ";
		cin.ignore();
		getline(cin, subject);
		l.update_subject(subject);

		char level;
		cout << "Enter a level: ";
		cin >> level;
		l.update_level(level);

		int price;
		cout << "Enter a price: ";
		cin >> price;
		l.update_price(price);

		char extension;
		cout << "Enter a extension: ";
		cin >> extension;
		l.update_extension(extension);

		int due_date;
		cout << "Enter a due date: ";
		cin >> due_date;
		l.update_due_date(due_date);

		string name_of_teacher;
		cout << "Enter a name of teacher: ";
		cin.ignore();
		getline(cin, name_of_teacher);
		l.update_name_of_teacher(name_of_teacher);

		string textbook;
		cout << "Enter a textbook: ";
		getline(cin, textbook);
		l.update_textbook(textbook);

		LectureFile.Append(l);
		LectureFile.Close();
		cout << "Lecture is added sucessfully" << endl << endl;
	}

	if (menu == 3) {
		char purchase_id[LEN_PURCHASE_ID + 1];
		Purchase p, pRead;
		cout << "Please enter ID of purchase to insert" << endl;
		cout << ">> ";

		cin.ignore();
		cin >> purchase_id;
		cout << endl;

		p.update_purchase_id(purchase_id);

		DelimFieldBuffer buffer('|', LEN_BUFFER);
		RecordFile <Purchase> PurchaseFile(buffer);
		RecordFile <Lecture> LectureFile(buffer);
		RecordFile <Member> MemberFile(buffer);

		PurchaseFile.Open("fileOfPurchase.dat", ios::in);

		while (PurchaseFile.Read(pRead) != -1) {
			if (pRead == p) {
				cout << "Error : There is already " << purchase_id << endl << endl;
				PurchaseFile.Close();
				return;
			}
		}
		PurchaseFile.Close();

		PurchaseFile.Open("fileOfPurchase.dat", ios::out);

		LectureFile.Open("fileOfLecture.dat", ios::out);
		char lecture_id[LEN_LECTURE_ID + 1];
		cout << "Enter a lecture id: ";
		cin >> lecture_id;

		Lecture l, lRead;
		bool flag = false;
		l.update_lecture_id(lecture_id);

		while (LectureFile.Read(lRead) != -1) {
			if (lRead == l) {
				p.update_lecture_id(lecture_id);
				flag = true;
				LectureFile.Close();
				break;
			}
		}
		if (!flag) {
			cout << "No such lecture ID " << lecture_id << endl << endl;
			LectureFile.Close();
			PurchaseFile.Close();
			return;
		}

		MemberFile.Open("fileOfMember.dat", ios::out);
		string member_id;
		cout << "Enter a member id: ";
		cin.ignore();
		getline(cin, member_id);

		Member m, mRead;
		flag = false;
		m.update_id(member_id);

		while (MemberFile.Read(mRead) != -1) {
			if (mRead == m) {
				p.update_member_id(member_id);
				flag = true;
				MemberFile.Close();
				break;
			}
		}
		if (!flag) {
			cout << "No such member ID " << member_id << endl << endl;
			MemberFile.Close();
			PurchaseFile.Close();
			return;
		}

		char mileage[LEN_MILEAGE];
		memset(mileage, '0', LEN_MILEAGE);
		p.update_mileage(mileage);

		PurchaseFile.Append(p);
		PurchaseFile.Close();
		cout << "Purchase is added sucessfully" << endl << endl;
	}

	if (menu == 0)
		return;
}