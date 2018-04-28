#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class fraction {
	int m; // числитель
	int n; // знаменатель
public:
	fraction() {}
	fraction(int m, int n) {
		this->m = m;
		this->n = n;
	}
	int getN() { return n; }
	bool operator<(fraction ob2); // переопределение операwции<
	bool operator==(fraction ob2); // переопределение операции==
								   // переопределение операторов ввода/вывода
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
	cout << "„ислитель";
	cin >> ob.m;
	cout << "«наменатель";
	cin >> ob.n;
	return stream;
}
int main() {
	setlocale(LC_ALL, "rus");
	vector<fraction> fractions;//вектор дробей
							   //заполнение вектора дробей
	fractions.push_back({ 4,5 });
	fractions.push_back({ 3,5 });
	fractions.push_back({ 2,6 });
	fractions.push_back({ 2,5 });
	fractions.push_back({ 3,6 });
	//создать итератор и установить его на начало вектора
	vector<fraction>::iterator p = fractions.begin();
	sort(fractions.begin(), fractions.end());//отсортировать вектор
											 //вывести элементы вектора 
	p = fractions.begin();
	while (p != fractions.end()) {
		cout << *p << ' ';//вывести элемент
		p++;//передвинуть указатель
	}
	//посчитать сколько раз встречаетс€ дробь ј в векторе 
	fraction A(3, 6);//создать дробь ј
	cout << endl << A << " встречаетс€ " << count(fractions.begin(), fractions.end(), A) << " раз" << endl;
	//поиск дроби со знаменателем 5
	p = fractions.begin();
	while (p != fractions.end()) {
		p = find_if(p, fractions.end(), [](fraction obj) { return (obj.getN() == 5); });/*критерий посика задаетс€ через л€мбда-выражение*/
		if (p != fractions.end()) {
			cout << endl << "Element found: " << *p << '\n';
			p++;
		}
	}
	//конец поиска дроби со знаменателем 5
}