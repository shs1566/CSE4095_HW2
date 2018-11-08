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

