#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "Lecture.h"
#include "Purchase.h"
#include <vector>
#include <fstream>
#include "recfile.h"
#include <cstring>

#define LEN_BUFFER 256

bool readMember(vector<Member> &member_list) {
	ifstream ifs("listOfMember.txt");
	if (ifs.fail()) {
		cout << "listOfMeber.txt open error!" << endl;
		return false;
	}

	int n;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer('|', LEN_BUFFER);
	RecordFile <Member> MemberFile(buffer);

	MemberFile.Create("fileOfMember.dat", ios::out | ios::trunc);

	for (int i = 0; i < n; i++) {
		Member m;
		ifs >> m;
		int recaddr;

		if ((recaddr = MemberFile.Write(m)) == -1)
			cout << "Write Error!" << endl;

		member_list.push_back(m);
	}
	MemberFile.Close();
	return true;
}

bool readLecture(vector<Lecture> &lecture_list) {
	ifstream ifs("listOfLecture.txt");
	if (ifs.fail()) {
		cout << "listOfLecture.txt open error!" << endl;
		return false;
	}

	DelimFieldBuffer buffer('|', LEN_BUFFER);
	RecordFile <Lecture> LectureFile(buffer);

	LectureFile.Create("fileOfLecture.dat", ios::out | ios::trunc);

	int n;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < n; i++) {
		Lecture l;
		ifs >> l;
		int recaddr;

		if ((recaddr = LectureFile.Write(l)) == -1)
			cout << "Write Error!" << endl;

		lecture_list.push_back(l);
	}
	LectureFile.Close();
	return true;
}

bool readPurchase(vector<Purchase> &purchase_list) {
	ifstream ifs("listOfPurchase.txt");
	if (ifs.fail()) {
		cout << "listOfPurchase.txt open error!" << endl;
		return false;
	}

	DelimFieldBuffer buffer('|', LEN_BUFFER);
	RecordFile <Purchase> PurchaseFile(buffer);

	PurchaseFile.Create("fileOfPurchase.dat", ios::out | ios::trunc);

	int n;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < n; i++) {
		Purchase p;
		ifs >> p;
		int recaddr;

		if ((recaddr = PurchaseFile.Write(p)) == -1)
			cout << "Write Error!" << endl;

		purchase_list.push_back(p);
	}
	PurchaseFile.Close();
	return true;
}
