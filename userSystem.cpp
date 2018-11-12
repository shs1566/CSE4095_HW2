#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "Lecture.h"
#include "Purchase.h"
#include <vector>
#include <fstream>
#include "recfile.h"
#include <cstring>

#define LEN_BUFFER 256


void modifyUserRecord(string id) {
	Member m, mRead;

	m.update_id(id);

	DelimFieldBuffer buffer('|', LEN_BUFFER);
	RecordFile <Member> MemberFile(buffer);

	MemberFile.Open("fileOfMember.dat", ios::in);

	int recaddr;

	while ((recaddr = MemberFile.Read(mRead)) != -1) {
		if (m == mRead) {

			MemberFile.Close();

			int select;
			cout << "1. Modify password" << endl;
			cout << "2. Modify name" << endl;
			cout << "3. Modify phoneNumber" << endl;
			cout << "4. Modify address" << endl;
			cout << "5. Modify mileage" << endl;
			cout << "0. Back to menu" << endl << endl;
			cout << ">> ";
			cin >> select;
			cout << endl;

			if (select == 1) {
				string password;
				int len, new_len;
				cout << "Please enter new password" << endl;
				cout << ">> ";
				cin.ignore();
				getline(cin, password);
				cout << endl;

				len = (int)mRead.get_password().length();
				new_len = (int)password.length();

				if (len >= new_len) {
					MemberFile.Close();
					MemberFile.Open("fileOfMember.dat", ios::out);
					password.append(len - new_len, ' ');
					mRead.update_password(password);
					MemberFile.Write(mRead, recaddr);
				}
				else {
					MemberFile.Close();

					/* 기존 record를 삭제 */
					MemberFile.Open("fileOfMember.dat", ios::out);
					string new_id = mRead.get_id();
					string copy = new_id;
					copy[0] = '*';
					mRead.update_id(copy);
					MemberFile.Write(mRead, recaddr);
					MemberFile.Close();

					/* 수정된 record를 새로 추가 */
					MemberFile.Open("fileOfMember.dat", ios::out);
					mRead.update_id(new_id);
					mRead.update_password(password);
					MemberFile.Append(mRead);
					MemberFile.Close();

				}
			}

			else if (select == 2) {
				string name;
				int len, new_len;
				cout << "Please enter new name" << endl;
				cout << ">> ";
				cin.ignore();
				getline(cin, name);
				cout << endl;

				len = (int)mRead.get_name().length();
				new_len = (int)name.length();

				if (len >= new_len) {
					MemberFile.Close();
					MemberFile.Open("fileOfMember.dat", ios::out);
					name.append(len - new_len, ' ');
					mRead.update_name(name);
					MemberFile.Write(mRead, recaddr);
				}
				else {
					MemberFile.Close();

					/* 기존 record를 삭제 */
					MemberFile.Open("fileOfMember.dat", ios::out);
					string new_id = mRead.get_id();
					string copy = new_id;
					copy[0] = '*';
					mRead.update_id(copy);
					MemberFile.Write(mRead, recaddr);
					MemberFile.Close();

					/* 수정된 record를 새로 추가 */
					MemberFile.Open("fileOfMember.dat", ios::out);
					mRead.update_id(new_id);
					mRead.update_name(name);
					MemberFile.Append(mRead);
					MemberFile.Close();
				}
			}

			else if (select == 3) {
				string phoneNumber;
				int len, new_len;
				cout << "Please enter new phoneNumber" << endl;
				cout << ">> ";
				cin.ignore();
				getline(cin, phoneNumber);
				cout << endl;

				len = (int)mRead.get_phoneNumber().length();
				new_len = (int)phoneNumber.length();

				if (len >= new_len) {
					MemberFile.Close();
					MemberFile.Open("fileOfMember.dat", ios::out);
					phoneNumber.append(len - new_len, ' ');
					mRead.update_phoneNumber(phoneNumber);
					MemberFile.Write(mRead, recaddr);
				}
				else {
					MemberFile.Close();

					/* 기존 record를 삭제 */
					MemberFile.Open("fileOfMember.dat", ios::out);
					string new_id = mRead.get_id();
					string copy = new_id;
					copy[0] = '*';
					mRead.update_id(copy);
					MemberFile.Write(mRead, recaddr);
					MemberFile.Close();

					/* 수정된 record를 새로 추가 */
					MemberFile.Open("fileOfMember.dat", ios::out);
					mRead.update_id(new_id);
					mRead.update_phoneNumber(phoneNumber);
					MemberFile.Append(mRead);
					MemberFile.Close();
				}
			}

			else if (select == 4) {
				string address;
				int len, new_len;
				cout << "Please enter new address" << endl;
				cout << ">> ";
				cin.ignore();
				getline(cin, address);
				cout << endl;

				len = (int)mRead.get_address().length();
				new_len = (int)address.length();

				if (len >= new_len) {
					MemberFile.Close();
					MemberFile.Open("fileOfMember.dat", ios::out);
					address.append(len - new_len, ' ');
					mRead.update_address(address);
					MemberFile.Write(mRead, recaddr);
				}
				else {
					MemberFile.Close();

					/* 기존 record를 삭제 */
					MemberFile.Open("fileOfMember.dat", ios::out);
					string new_id = mRead.get_id();
					string copy = new_id;
					copy[0] = '*';
					mRead.update_id(copy);
					MemberFile.Write(mRead, recaddr);
					MemberFile.Close();

					/* 수정된 record를 새로 추가 */
					MemberFile.Open("fileOfMember.dat", ios::out);
					mRead.update_id(new_id);
					mRead.update_address(address);
					MemberFile.Append(mRead);
					MemberFile.Close();
				}
			}

			else if (select == 5) {
				char mileage_char[LEN_MILEAGE];
				string mileage_string;

				cout << "Please enter new mileage" << endl;
				cout << ">> ";
				cin.ignore();
				getline(cin, mileage_string);
				cout << endl;

				memset(mileage_char, '0', LEN_MILEAGE);
				strncpy(mileage_char + LEN_MILEAGE - mileage_string.length(), mileage_string.c_str(), mileage_string.length());

				MemberFile.Close();
				MemberFile.Open("fileOfMember.dat", ios::out);
				mRead.update_mileage(mileage_char);
				MemberFile.Write(mRead, recaddr);

			}

			else if (select == 0)
				return;
		}
	}
}

void searchLecture() {
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

void searchUserPurchase(string id) {

	Purchase p, pRead;

	
	DelimFieldBuffer buffer('|', LEN_BUFFER);
	RecordFile <Purchase> PurchaseFile(buffer);
	PurchaseFile.Open("fileOfPurchase.dat", ios::in);

	cout << "Serach Result" << endl << endl; 
	while (PurchaseFile.Read(pRead) != -1) {
		if (strcmp(pRead.get_member_id().c_str(), id.c_str()) == 0) {
			cout << pRead << endl << endl;
		}
	}

	PurchaseFile.Close();
}

void insertUserPurchase(string id) {
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
	string member_id = id;

	p.update_member_id(member_id);

	char mileage[LEN_MILEAGE];
	memset(mileage, '0', LEN_MILEAGE);
	p.update_mileage(mileage);

	PurchaseFile.Append(p);
	PurchaseFile.Close();
	cout << "Purchase is added sucessfully" << endl << endl;
}

void modifyUserPurchase(string id) {
	Purchase p, pRead;
	char purchase_id[LEN_PURCHASE_ID + 1];

	DelimFieldBuffer buffer('|', LEN_BUFFER);
	RecordFile <Purchase> PurchaseFile(buffer);

	PurchaseFile.Open("fileOfPurchase.dat", ios::in);

	int recaddr;
	bool flag = false;

	cout << "**Purchase History **" << endl;
	searchUserPurchase(id);


	cout << "Please enter Purchase ID to modify" << endl;
	cout << ">> ";
	cin.ignore();
	cin >> purchase_id;
	cout << endl;

	p.update_purchase_id(purchase_id);

	while ((recaddr = PurchaseFile.Read(pRead)) != -1) {
		if (p == pRead) {
			PurchaseFile.Close();

			if (pRead.get_member_id() != id) {
				cout << "Permission denied" << endl;
				return;
			}

			int select;
			cout << "1. Modify lecture_id" << endl;
			cout << "2. Modify mileage" << endl;
			cout << "0. Back to menu" << endl << endl;
			cout << ">> ";
			cin >> select;
			cout << endl;

			if (select == 1) {
				char lecture_id_char[LEN_LECTURE_ID];
				string lecture_id_string;

				cout << "Please enter new lecture_id" << endl;
				cout << ">> ";
				cin.ignore();
				getline(cin, lecture_id_string);
				cout << endl;

				memset(lecture_id_char, '0', LEN_LECTURE_ID);
				strncpy(lecture_id_char + LEN_LECTURE_ID - lecture_id_string.length(), lecture_id_string.c_str(), lecture_id_string.length());

				DelimFieldBuffer buffer2('|', LEN_BUFFER);
				RecordFile <Lecture> LectureFile(buffer2);
				Lecture l, lRead;
				l.update_lecture_id(lecture_id_char);
				LectureFile.Open("fileOfLecture.dat", ios::in);

				bool flag2 = false;
				while (LectureFile.Read(lRead) != -1) {
					if (l == lRead) {
						flag2 = true;
						PurchaseFile.Open("fileOfPurchase.dat", ios::out);
						pRead.update_lecture_id(lecture_id_char);
						PurchaseFile.Write(pRead, recaddr);
						PurchaseFile.Close();
					}
				}
				LectureFile.Close();
				if (!flag2)
					cout << "No such lecture id" << endl << endl;
			}


			else if (select == 2) {
				char mileage_char[LEN_MILEAGE];
				string mileage_string;

				cout << "Please enter new mileage" << endl;
				cout << ">> ";
				cin.ignore();
				getline(cin, mileage_string);
				cout << endl;

				memset(mileage_char, '0', LEN_MILEAGE);
				strncpy(mileage_char + LEN_MILEAGE - mileage_string.length(), mileage_string.c_str(), mileage_string.length());

				PurchaseFile.Close();
				PurchaseFile.Open("fileOfPurchase.dat", ios::out);
				pRead.update_mileage(mileage_char);
				PurchaseFile.Write(pRead, recaddr);

			}
		}
	}
}

void deleteUserPurchase(string id) {
	char purchase_id[LEN_PURCHASE_ID + 1];
	Purchase p, pRead;

	cout << "**Purchase History **" << endl;
	searchUserPurchase(id);

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
			
			if (pRead.get_member_id() != id) {
				cout << "Permission denied" << endl;
				return;
			}
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
