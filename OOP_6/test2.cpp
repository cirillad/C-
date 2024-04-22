#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
//1
	string name = "Hello, world!";

//2
	int NameLen = name.length();
	cout << NameLen << endl;

//3
	cout << name[0] << endl;
	
//4
	name = name.replace(name.find("world"), 5, "planet");
	cout << name << endl;

//5
	string name2 = name;
	name2 = name2.replace(name2.find("!"), 1, ", how are you?");
	cout << name2 << endl;

//6
	if (name == name2) {
		cout << "Rows are same." << endl;
	}
	else {
		cout << "Rows arent same." << endl;
	}

//7
	string SubString7 = name.substr(7, 6);
	cout << SubString7 << endl;

//8
	size_t PosOfSubStr = name2.find(SubString7);
	cout << PosOfSubStr << endl;

//9
	string SubString9 = name2.substr(7, 6);
	cout << SubString9 << endl;

//10
	name2.insert(PosOfSubStr, "big ");
	cout << name2 << endl;

//11
	reverse(name.begin(), name.end());

//12
	int count = 0;
	for (size_t i = 0; i < name2.length(); i++)
	{
		if (name2[i] == 'h') {
			count++;
		}
	}

	cout << count << endl;

//13

	for (auto &c : name)
	{
		c = toupper(c);
	}

	cout << name << endl;

//14
	string str = "Hello, its very easy.";

	str.erase(remove(str.begin(), str.end(), ' '), str.end());

	cout << str << endl;

//15
	string str15 = "Hello, its very easy.";

	str.erase(remove(str.begin(), str.end(), ' '), str.end());

	cout << str << endl;

//16
	string str16 = "This is very very interesting";

	size_t pos = 0;
	while ((pos = str.find("very", pos)) != string::npos) {
		str.replace(pos, 4, " extremely ");
		pos += 11;
	}

	cout << "Modified string: " << str << endl;

//17
	string str17 = "abba";

	string str17_2 = str17;

	reverse(str17_2.begin(), str17_2.end());

	if (str17 == str17_2)
	{
		cout << "its pallindrome" << endl;
	}
	else {
		cout << "NO" << endl;
	}

//18
	string str18 = "akjuretyhj";

	sort(str18.begin(), str18.end());

	cout << "Sorted: " << str18 << endl;

//19

	string str19 = "Today 2024-04-22";

	for (char& c : str19) {
		if (isdigit(c)) {
			c = 'X';
		}
	}

	cout << "Replaced string: " << str19 << endl;

//20
	string str1 = "Hello";
	string str2 = "world";

	string combined(str1.begin(), str1.end());
	combined.insert(combined.end(), str2.begin(), str2.end());

	cout << "Combined string: " << combined << endl;
}
