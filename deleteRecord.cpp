#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "Lecture.h"
#include "Purchase.h"
#include <vector>
#include <fstream>
#include "recfile.h"
#include <cstring>

#define LEN_BUFFER 256

void deleteRecord() {
	int menu;
	cout << "1. Delete Member" << endl;
	cout << "2. Delete Lecture" << endl;
	cout << "3. Delete Purchase" << endl;
	cout << "0. Back to menu" << endl << endl;
	cout << ">> ";
	cin >> menu;
	cout << endl;

	if (menu == 1) {
		string id;
		Member m, mRead;

		cout << "Please enter a ID of member to delete" << endl;
		cout << ">> ";
		cin.ignore();
		getline(cin, id);

		m.update_id(id);
		DelimFieldBuffer buffer('|', LEN_BUFFER);
		RecordFile <Member> MemberFile(buffer);

		DelimFieldBuffer buffer2('|', LEN_BUFFER);
		RecordFile <Purchase> PurchaseFile(buffer2);

		MemberFile.Open("fileOfMember.dat", ios::in);

		int recaddr_member;
		vector<int> delete_recaddr;
		vector<Purchase> delete_purchase;
		while ((recaddr_member = MemberFile.Read(mRead)) != -1) {
			if (mRead == m) {
				MemberFile.Close();

				Purchase p, pRead;
				PurchaseFile.Open("fileOfPurchase.dat", ios::in);

				int recaddr_purchase;
				while ((recaddr_purchase = PurchaseFile.Read(pRead)) != -1) {
					if (id == pRead.get_member_id()) {
						char purchase_id[LEN_PURCHASE_ID + 1];
						strncpy(purchase_id, pRead.get_purchase_id(), LEN_PURCHASE_ID);
						purchase_id[0] = '*';	// delete symbol
						pRead.update_purchase_id(purchase_id);
						delete_recaddr.push_back(recaddr_purchase);
						delete_purchase.push_back(pRead);
					}
				}
				PurchaseFile.Close();

				/* 삭제될 부분을 미리 표시해두고 해당 id의 첫글자를 *로 표기하여 다시 씀 */
				PurchaseFile.Open("fileOfPurchase.dat", ios::out);
				for (int i = 0; i < delete_recaddr.size(); i++)
					PurchaseFile.Write(delete_purchase[i], delete_recaddr[i]);
				PurchaseFile.Close();

				MemberFile.Open("fileOfMember.dat", ios::out);
				id[0] = '*';
				mRead.update_id(id);
				MemberFile.Write(mRead, recaddr_member);
				MemberFile.Close();

				cout << endl << "Delete Success" << endl << endl;
			}
		}
		if (delete_recaddr.size() == 0)
			cout << endl << "No such member id" << endl << endl;
	}

	if (menu == 2) {
		char  lecture_id[LEN_LECTURE_ID + 1];
		Lecture l, lRead;

		cout << "Please enter a ID of lecture to delete" << endl;
		cout << ">> ";
		cin >> lecture_id;

		l.update_lecture_id(lecture_id);
		DelimFieldBuffer buffer('|', LEN_BUFFER);
		RecordFile <Lecture> LectureFile(buffer);

		DelimFieldBuffer buffer2('|', LEN_BUFFER);
		RecordFile <Purchase> PurchaseFile(buffer2);

		LectureFile.Open("fileOfLecture.dat", ios::in);

		int recaddr_lecture;
		vector<int> delete_recaddr;
		vector<Purchase> delete_purchase;
		while ((recaddr_lecture = LectureFile.Read(lRead)) != -1) {
			if (lRead == l) {
				LectureFile.Close();

				Purchase p, pRead;
				PurchaseFile.Open("fileOfPurchase.dat", ios::in);

				int recaddr_purchase;
				while ((recaddr_purchase = PurchaseFile.Read(pRead)) != -1) {
					if (!strncmp(lecture_id, pRead.get_lecture_id(), LEN_LECTURE_ID)) {
						char purchase_id[LEN_PURCHASE_ID + 1];
						strncpy(purchase_id, pRead.get_purchase_id(), LEN_PURCHASE_ID);
						purchase_id[0] = '*';	// delete symbol
						pRead.update_purchase_id(purchase_id);
						delete_recaddr.push_back(recaddr_purchase);
						delete_purchase.push_back(pRead);
					}
				}
				PurchaseFile.Close();

				/* 삭제될 부분을 미리 표시해두고 해당 id의 첫글자를 *로 표기하여 다시 씀 */
				PurchaseFile.Open("fileOfPurchase.dat", ios::out);
				for (int i = 0; i < delete_recaddr.size(); i++)
					PurchaseFile.Write(delete_purchase[i], delete_recaddr[i]);
				PurchaseFile.Close();

				LectureFile.Open("fileOfLecture.dat", ios::out);
				lecture_id[0] = '*';
				lRead.update_lecture_id(lecture_id);
				LectureFile.Write(lRead, recaddr_lecture);
				LectureFile.Close();

				cout << endl << "Delete Success" << endl << endl;
			}
		}

		if (delete_recaddr.size() == 0)
			cout << endl << "No such lecture id" << endl << endl;
	}

	if (menu == 3) {
		char purchase_id[LEN_PURCHASE_ID + 1];
		Purchase p, pRead;

		cout << "Please enter a ID of purchase to delete" << endl;
		cout << ">> ";
		cin >> purchase_id;

		p.update_purchase_id(purchase_id);

		DelimFieldBuffer buffer('|', LEN_BUFFER);
		RecordFile <Purchase> PurchaseFile(buffer);

		PurchaseFile.Open("fileOfPurchase.dat", ios::in);

		int recaddr_purchase;
		bool flag = false;
		while (recaddr_purchase = PurchaseFile.Read(pRead) != -1) {
			if (pRead == p) {
				PurchaseFile.Close();

				flag = true;
				PurchaseFile.Open("fileOfPurchase.dat", ios::out);
				purchase_id[0] = '*';
				pRead.update_purchase_id(purchase_id);
				PurchaseFile.Write(pRead, recaddr_purchase);
				PurchaseFile.Close();

				cout << endl << "Delete Success" << endl << endl;
			}
		}

		if (!flag)
			cout << endl << "No such purchase id" << endl << endl;
	}
}