#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "Lecture.h"
#include "Purchase.h"
#include <vector>
#include <fstream>
#include "recfile.h"
#include <cstring>

#define LEN_BUFFER 256

void modifyRecord() {
	int menu;
	cout << "1. Modify Member record" << endl;
	cout << "2. Modify Lecture record" << endl;
	cout << "3. Modify Purchase record" << endl;
	cout << "0. Back to menu" << endl << endl;
	cout << ">> ";
	cin >> menu;
	cout << endl;

	if (menu == 1) {
		string id;
		Member m, mRead;

		cout << "Please Enter a member ID to modify" << endl;
		cout << ">> ";
		cin.ignore();
		getline(cin, id);
		cout << endl;

		m.update_id(id);

		DelimFieldBuffer buffer('|', LEN_BUFFER);
		RecordFile <Member> MemberFile(buffer);

		MemberFile.Open("fileOfMember.dat", ios::in);

		int recaddr;
		bool flag = false;
		while ((recaddr = MemberFile.Read(mRead)) != -1) {
			if (m == mRead) {
				flag = true;
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

		if (!flag)
			cout << "No such id" << endl;
	}

	else if (menu == 2) {
		char lecture_id[LEN_LECTURE_ID + 1];
		Lecture l, lRead;

		cout << "Please Enter a lecture ID to modify" << endl;
		cout << ">> ";
		cin.ignore();
		cin >> lecture_id;
		cout << endl;

		l.update_lecture_id(lecture_id);

		DelimFieldBuffer buffer('|', LEN_BUFFER);
		RecordFile <Lecture> LectureFile(buffer);

		LectureFile.Open("fileOfLecture.dat", ios::in);

		int recaddr;
		bool flag = false;
		while ((recaddr = LectureFile.Read(lRead)) != -1) {
			if (l == lRead) {
				LectureFile.Close();

				int select;
				cout << "1. Modify subject" << endl;
				cout << "2. Modify level" << endl;
				cout << "3. Modify price" << endl;
				cout << "4. Modify extension" << endl;
				cout << "5. Modify due_date" << endl;
				cout << "6. Modify name of teacher" << endl;
				cout << "7. Modify textbook" << endl;
				cout << "0. Back to menu" << endl << endl;
				cout << ">> ";
				cin >> select;
				cout << endl;

				if (select == 1) {
					string subject;
					int len, new_len;
					cout << "Please enter new subject" << endl;
					cout << ">> ";
					cin.ignore();
					getline(cin, subject);
					cout << endl;

					len = (int)lRead.get_subject().length();
					new_len = (int)subject.length();

					if (len >= new_len) {
						LectureFile.Close();
						LectureFile.Open("fileOfLecture.dat", ios::out);
						subject.append(len - new_len, ' ');
						lRead.update_subject(subject);
						LectureFile.Write(lRead, recaddr);
					}
					else {
						LectureFile.Close();

						/* 기존 record를 삭제 */
						LectureFile.Open("fileOfLecture.dat", ios::out);
						char new_id[LEN_LECTURE_ID];
						char copy[LEN_LECTURE_ID];

						strncpy(new_id, lRead.get_lecture_id(), LEN_LECTURE_ID);
						strncpy(copy, lRead.get_lecture_id(), LEN_LECTURE_ID);
						copy[0] = '*';
						lRead.update_lecture_id(copy);
						LectureFile.Write(lRead, recaddr);
						LectureFile.Close();

						/* 수정된 record를 새로 추가 */
						LectureFile.Open("fileOfLecture.dat", ios::out);
						lRead.update_lecture_id(new_id);
						lRead.update_subject(subject);
						LectureFile.Append(lRead);
						LectureFile.Close();

					}
				}

				else if (select == 2) {
					char level;

					cout << "Please enter new level" << endl;
					cout << ">> ";
					cin.ignore();
					cin >> level;
					cout << endl;

					LectureFile.Close();
					LectureFile.Open("fileOfLecture.dat", ios::out);
					lRead.update_level(level);
					LectureFile.Write(lRead, recaddr);

				}

				else if (select == 3) {
					int  price;
					int len, new_len;
					cout << "Please enter new price" << endl;
					cout << ">> ";
					cin.ignore();
					cin >> price;
					cout << endl;

					len = (int)to_string(lRead.get_price()).length();
					new_len = (int)to_string(price).length();

					if (len == new_len) {
						LectureFile.Close();
						LectureFile.Open("fileOfLecture.dat", ios::out);
						lRead.update_price(price);
						LectureFile.Write(lRead, recaddr);
					}
					else {
						LectureFile.Close();

						/* 기존 record를 삭제 */
						LectureFile.Open("fileOfLecture.dat", ios::out);
						char new_id[LEN_LECTURE_ID];
						char copy[LEN_LECTURE_ID];

						strncpy(new_id, lRead.get_lecture_id(), LEN_LECTURE_ID);
						strncpy(copy, lRead.get_lecture_id(), LEN_LECTURE_ID);
						copy[0] = '*';
						lRead.update_lecture_id(copy);
						LectureFile.Write(lRead, recaddr);
						LectureFile.Close();

						/* 수정된 record를 새로 추가 */
						LectureFile.Open("fileOfLecture.dat", ios::out);
						lRead.update_lecture_id(new_id);
						lRead.update_price(price);
						LectureFile.Append(lRead);
						LectureFile.Close();

					}
				}

				else if (select == 4) {
					char extension;

					cout << "Please enter new extension" << endl;
					cout << ">> ";
					cin.ignore();
					cin >> extension;
					cout << endl;

					LectureFile.Close();
					LectureFile.Open("fileOfLecture.dat", ios::out);
					lRead.update_level(extension);
					LectureFile.Write(lRead, recaddr);
				}

				else if (select == 5) {
					int  due_date;
					int len, new_len;
					cout << "Please enter new price" << endl;
					cout << ">> ";
					cin.ignore();
					cin >> due_date;
					cout << endl;

					len = (int)to_string(lRead.get_due_date()).length();
					new_len = (int)to_string(due_date).length();

					if (len == new_len) {
						LectureFile.Close();
						LectureFile.Open("fileOfLecture.dat", ios::out);
						lRead.update_price(due_date);
						LectureFile.Write(lRead, recaddr);
					}
					else {
						LectureFile.Close();

						/* 기존 record를 삭제 */
						LectureFile.Open("fileOfLecture.dat", ios::out);
						char new_id[LEN_LECTURE_ID];
						char copy[LEN_LECTURE_ID];

						strncpy(new_id, lRead.get_lecture_id(), LEN_LECTURE_ID);
						strncpy(copy, lRead.get_lecture_id(), LEN_LECTURE_ID);
						copy[0] = '*';
						lRead.update_lecture_id(copy);
						LectureFile.Write(lRead, recaddr);
						LectureFile.Close();

						/* 수정된 record를 새로 추가 */
						LectureFile.Open("fileOfLecture.dat", ios::out);
						lRead.update_lecture_id(new_id);
						lRead.update_due_date(due_date);
						LectureFile.Append(lRead);
						LectureFile.Close();

					}
				}

				else if (select == 6) {
					string name_of_teacher;
					int len, new_len;
					cout << "Please enter new name of teacher" << endl;
					cout << ">> ";
					cin.ignore();
					getline(cin, name_of_teacher);
					cout << endl;

					len = (int)lRead.get_name_of_teacher().length();
					new_len = (int)name_of_teacher.length();

					if (len >= new_len) {
						LectureFile.Close();
						LectureFile.Open("fileOfLecture.dat", ios::out);
						name_of_teacher.append(len - new_len, ' ');
						lRead.update_name_of_teacher(name_of_teacher);
						LectureFile.Write(lRead, recaddr);
					}
					else {
						LectureFile.Close();

						/* 기존 record를 삭제 */
						LectureFile.Open("fileOfLecture.dat", ios::out);
						char new_id[LEN_LECTURE_ID];
						char copy[LEN_LECTURE_ID];

						strncpy(new_id, lRead.get_lecture_id(), LEN_LECTURE_ID);
						strncpy(copy, lRead.get_lecture_id(), LEN_LECTURE_ID);
						copy[0] = '*';
						lRead.update_lecture_id(copy);
						LectureFile.Write(lRead, recaddr);
						LectureFile.Close();

						/* 수정된 record를 새로 추가 */
						LectureFile.Open("fileOfLecture.dat", ios::out);
						lRead.update_lecture_id(new_id);
						lRead.update_name_of_teacher(name_of_teacher);
						LectureFile.Append(lRead);
						LectureFile.Close();
					}
				}

				else if (select == 7) {
					string textbook;
					int len, new_len;
					cout << "Please enter new textbook" << endl;
					cout << ">> ";
					cin.ignore();
					getline(cin, textbook);
					cout << endl;

					len = (int)lRead.get_textbook().length();
					new_len = (int)textbook.length();

					if (len >= new_len) {
						LectureFile.Close();
						LectureFile.Open("fileOfLecture.dat", ios::out);
						textbook.append(len - new_len, ' ');
						lRead.update_textbook(textbook);
						LectureFile.Write(lRead, recaddr);
					}
					else {
						LectureFile.Close();

						/* 기존 record를 삭제 */
						LectureFile.Open("fileOfLecture.dat", ios::out);
						char new_id[LEN_LECTURE_ID];
						char copy[LEN_LECTURE_ID];

						strncpy(new_id, lRead.get_lecture_id(), LEN_LECTURE_ID);
						strncpy(copy, lRead.get_lecture_id(), LEN_LECTURE_ID);
						copy[0] = '*';
						lRead.update_lecture_id(copy);
						LectureFile.Write(lRead, recaddr);
						LectureFile.Close();

						/* 수정된 record를 새로 추가 */
						LectureFile.Open("fileOfLecture.dat", ios::out);
						lRead.update_lecture_id(new_id);
						lRead.update_textbook(textbook);
						LectureFile.Append(lRead);
						LectureFile.Close();
					}
				}

				else if (select == 0)
					return;
			}
		}
		if (!flag)
			cout << "No such id" << endl;
	}

	else if (menu == 3) {
		char purchase_id[LEN_PURCHASE_ID + 1];
		Purchase p, pRead;

		cout << "Please Enter a purchase ID to modify" << endl;
		cout << ">> ";
		cin.ignore();
		cin >> purchase_id;
		cout << endl;

		p.update_purchase_id(purchase_id);

		DelimFieldBuffer buffer('|', LEN_BUFFER);
		RecordFile <Purchase> PurchaseFile(buffer);

		PurchaseFile.Open("fileOfPurchase.dat", ios::in);

		int recaddr;
		bool flag = false;
		while ((recaddr = PurchaseFile.Read(pRead)) != -1) {
			if (p == pRead) {
				PurchaseFile.Close();

				int select;
				cout << "1. Modify lecture_id" << endl;
				cout << "2. Modify member_id" << endl;
				cout << "3. Modify mileage" << endl;
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
					string member_id;
					int len, new_len;
					cout << "Please enter new member_id" << endl;
					cout << ">> ";
					cin.ignore();
					getline(cin, member_id);
					cout << endl;

					len = (int)pRead.get_member_id().length();
					new_len = (int)member_id.length();

					DelimFieldBuffer buffer2('|', LEN_BUFFER);
					RecordFile <Member> MemberFile(buffer2);
					Member m, mRead;

					m.update_id(member_id);
					MemberFile.Open("fileOfMember.dat", ios::in);

					bool flag2 = false;

					while (MemberFile.Read(mRead) != -1) {
						if (m == mRead) {
							flag2 = true;
							if (len >= new_len) {
								PurchaseFile.Close();
								PurchaseFile.Open("fileOfPurchase.dat", ios::out);
								member_id.append(len - new_len, ' ');
								pRead.update_member_id(member_id);
								PurchaseFile.Write(pRead, recaddr);
							}
							else {
								PurchaseFile.Close();

								/* 기존 record를 삭제 */
								PurchaseFile.Open("fileOfPurchase.dat", ios::out);
								char new_id[LEN_PURCHASE_ID];
								char copy[LEN_PURCHASE_ID];

								strncpy(new_id, pRead.get_purchase_id(), LEN_PURCHASE_ID);
								strncpy(copy, pRead.get_purchase_id(), LEN_PURCHASE_ID);
								copy[0] = '*';
								pRead.update_purchase_id(copy);
								PurchaseFile.Write(pRead, recaddr);
								PurchaseFile.Close();

								/* 수정된 record를 새로 추가 */
								PurchaseFile.Open("fileOfPurchase.dat", ios::out);
								pRead.update_purchase_id(new_id);
								pRead.update_member_id(member_id);
								PurchaseFile.Append(pRead);
								PurchaseFile.Close();

							}
						}
					}

					if (!flag2)
						cout << "No such member id" << endl << endl;
				}

				else if (select == 3) {
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
}