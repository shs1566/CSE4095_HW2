#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "Lecture.h"
#include "Purchase.h"
#include <vector>
#include <fstream>
#include "recfile.h"
#include <cstring>

void showMember(vector<Member> &member_list) {
	for (int i = 0; i < 10; i++)
		cout << member_list[i] << endl;
	cout << endl;
}

void showLecture(vector<Lecture> &lecture_list) {
	for (int i = 0; i < 10; i++)
		cout << lecture_list[i] << endl;
	cout << endl;
}

void showPurchase(vector<Purchase> &purchase_list) {
	for (int i = 0; i < 10; i++)
		cout << purchase_list[i] << endl;
	cout << endl;
}