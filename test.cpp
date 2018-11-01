#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "Lecture.h"
#include "Purchase.h"
#include <vector>
#include <fstream>
#include "recfile.h"
#include <cstring>

#define LEN_BUFFER 256

void memberTest() {
	DelimFieldBuffer buffer('|', LEN_BUFFER);
	RecordFile <Member> MemberFile(buffer);
	MemberFile.Open("fileOfMember.dat", ios::in);

	for (int i = 0; i < 10; i++) {
		Member m;
		MemberFile.Read(m);
		cout << m << endl;
	}
	cout << endl;
	MemberFile.Close();
}

void lectureTest() {
	DelimFieldBuffer buffer('|', LEN_BUFFER);
	RecordFile <Lecture> LectureFile(buffer);
	LectureFile.Open("fileOfLecture.dat", ios::in);

	for (int i = 0; i < 10; i++) {
		Lecture l;
		LectureFile.Read(l);
		cout << l << endl;
	}
	cout << endl;
	LectureFile.Close();
}

void purchaseTest() {
	DelimFieldBuffer buffer('|', LEN_BUFFER);
	RecordFile <Purchase> PurchaseFile(buffer);
	PurchaseFile.Open("fileOfPurchase.dat", ios::in);

	for (int i = 0; i < 10; i++) {
		Purchase p;
		PurchaseFile.Read(p);
		cout << p << endl;;
	}
	cout << endl;
	PurchaseFile.Close();
}