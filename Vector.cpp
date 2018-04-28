#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class fraction {
	int m; // ���������
	int n; // �����������
public:
	fraction() {}
	fraction(int m, int n) {
		this->m = m;
		this->n = n;
	}
	int getN() { return n; }
	bool operator<(fraction ob2); // ��������������� �����w���<
	bool operator==(fraction ob2); // ��������������� ��������==
								   // ��������������� ���������� �����/������
	friend istream &operator >> (istream&stream, fraction &ob);
	friend ostream &operator<<(ostream&stream, fraction ob);
};
bool fraction::operator <(fraction ob2) {
	if (m*ob2.n < n*ob2.m) return true;
	else return false;
}
bool fraction::operator ==(fraction ob2) {
	if (m == ob2.m&&n == ob2.n) return true;
	else return false;
}
ostream&operator<<(ostream&stream, fraction ob) {
	stream << ob.m << "/" << ob.n;
	return stream;
};
istream&operator >> (istream&stream, fraction &ob) {
	cout << "���������";
	cin >> ob.m;
	cout << "�����������";
	cin >> ob.n;
	return stream;
}
int main() {
	setlocale(LC_ALL, "rus");
	vector<fraction> fractions;//������ ������
							   //���������� ������� ������
	fractions.push_back({ 4,5 });
	fractions.push_back({ 3,5 });
	fractions.push_back({ 2,6 });
	fractions.push_back({ 2,5 });
	fractions.push_back({ 3,6 });
	//������� �������� � ���������� ��� �� ������ �������
	vector<fraction>::iterator p = fractions.begin();
	sort(fractions.begin(), fractions.end());//������������� ������
											 //������� �������� ������� 
	p = fractions.begin();
	while (p != fractions.end()) {
		cout << *p << ' ';//������� �������
		p++;//����������� ���������
	}
	//��������� ������� ��� ����������� ����� � � ������� 
	fraction A(3, 6);//������� ����� �
	cout << endl << A << " ����������� " << count(fractions.begin(), fractions.end(), A) << " ���" << endl;
	//����� ����� �� ������������ 5
	p = fractions.begin();
	while (p != fractions.end()) {
		p = find_if(p, fractions.end(), [](fraction obj) { return (obj.getN() == 5); });/*�������� ������ �������� ����� ������-���������*/
		if (p != fractions.end()) {
			cout << endl << "Element found: " << *p << '\n';
			p++;
		}
	}
	//����� ������ ����� �� ������������ 5
}