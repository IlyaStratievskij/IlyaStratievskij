/*
input:
name foo bar
name1 foo1
value	20
value 30
foo 200  # 	400  654
foob 201  #422 	65
bar #400 4564 64
# 1212361 443
vasya "Vasya
spaceman "Gagarin" # 136 67 gf

output:
name1 foo1
value 20
spaceman "Gagarin" # 136 67 gf
foob 201 #422 65
foo 200 # 400 654

errors:

String 1 has incorrect syntax
String 4 has incorrect syntax
String 7 has incorrect syntax
String 9 has incorrect syntax
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#define SIZEN 9999999

using namespace std;

int main() {
	ifstream inText("input.txt");
	unordered_map <string, string> myMap;
	string s1, s2, stemp;
	s1 = "";
	int *arr = new int[SIZEN];
	char ch;
	int i, line;
	i = 0; line = 1;

	while (!inText.eof()) {
		stemp = s1;
		inText >> s1;

		if ( (s1[0] == '#' && stemp == "") ) {
			getline(inText, s1);
			s1 = "";
			line += 1;
			continue;
		}
		else if (s1[0] == '#' && stemp != "") {
			while (true) {
				myMap[stemp] += " " + s1;
				inText.get(ch);
				if (ch != '\n' && !inText.eof()) inText >> s1;
				else break;
			}
			s1 = "";
			line += 1;
			continue;
		}
		else if (stemp != "" && s1[0] != '#') {
			myMap.erase(stemp);
			getline(inText, s1);
			s1 = "";
			arr[i] = line;
			i += 1;
			line += 1;
			continue;
		}
		
		inText >> s2;
		if (s2[0] == '#') {
			getline(inText, s1);;
			s1 = "";
			arr[i] = line;
			i += 1;
			line += 1;

			continue;
		}
		else if (s2[0] == '"' && s2[s2.length()-1] != '"') {
			while (true) {
				inText.get(ch);
				if (ch != '\n' && !inText.eof()) s2 += ch;
				if (ch == '"' || ch == '\n' || inText.eof()) break;
			}
			if (s2[s2.length() - 1] != '"') {
				s1 = "";
				arr[i] = line;
				i += 1;
				line += 1;

				continue;
			}
				
		}

		if (!myMap.count(s1))
			myMap[s1] = s2;
		else {
			arr[i] = line;
			i += 1;
		}

		inText.get(ch);
		if (ch == '\n') {
			line += 1;
			s1= "";
		}
	}
	inText.close();

	for (auto a = myMap.begin(); a != myMap.end(); a++)
		cout << a->first << " " << a->second << endl;
	
	cout << "\nerrors:\n\n";
	for (line = 0; line < i; line++)
		cout << "String " << arr[line] << " has incorrect syntax" << endl;

	delete[] arr;
	return 0;
}