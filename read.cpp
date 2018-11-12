#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "Lecture.h"
#include "Purchase.h"
#include <vector>
#include <fstream>
#include "recfile.h"
#include "textind.h"
#include "tindbuff.h"
#include "buffile.h"
#include <cstring>
#include <fstream>

#define LEN_BUFFER 256
#define LENID 12
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
	TextIndex MemberIndex(n);
	for (int i = 0; i < n; i++) {
		Member m;
		ifs >> m;
		int recaddr;

		if ((recaddr = MemberFile.Write(m)) == -1) {
			cout << "Write Error!" << endl;
			break;
		}

		MemberIndex.Insert(m.Key(), recaddr);
		member_list.push_back(m);
	}
	MemberFile.Close();

	TextIndexBuffer idxbuf(LENID, n);
	BufferFile memberIdxFile(idxbuf);
	memberIdxFile.Create("fileOfMember.ind", ios::out | ios::trunc);
	memberIdxFile.Rewind();
	idxbuf.Pack(MemberIndex);
	int result = memberIdxFile.Write();
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

	TextIndex LectureIndex(n);
	for (int i = 0; i < n; i++) {
		Lecture l;
		ifs >> l;
		int recaddr;

		if ((recaddr = LectureFile.Write(l)) == -1) {
			cout << "Write Error!" << endl;
			break;
		}
		LectureIndex.Insert(l.Key(), recaddr);
		lecture_list.push_back(l);
	}
	LectureFile.Close();

	TextIndexBuffer idxbuf(LENID, n);
	BufferFile lectureIdxFile(idxbuf);
	lectureIdxFile.Create("fileOfLecture.ind", ios::out | ios::trunc);
	lectureIdxFile.Rewind();
	idxbuf.Pack(LectureIndex);
	int result = lectureIdxFile.Write();
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

	TextIndex PurchaseIndex(n);

	for (int i = 0; i < n; i++) {
		Purchase p;
		ifs >> p;
		int recaddr;

		if ((recaddr = PurchaseFile.Write(p)) == -1) {
			cout << "Write Error!" << endl;
			break;
		}
		PurchaseIndex.Insert(p.Key(), recaddr);

		purchase_list.push_back(p);
	}
	PurchaseFile.Close();

	TextIndexBuffer idxbuf(LENID, n);
	BufferFile purchaseIdxFile(idxbuf);
	purchaseIdxFile.Create("fileOfPurchase.ind", ios::out | ios::trunc);
	purchaseIdxFile.Rewind();
	idxbuf.Pack(PurchaseIndex);
	int result = purchaseIdxFile.Write();
	PurchaseFile.Close();
	return true;
}
