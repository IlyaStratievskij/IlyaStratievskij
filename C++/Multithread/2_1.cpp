#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <algorithm>
#define i 0

std::string derivative(std::string polynomial) {
    if (polynomial[i] != '+' && polynomial[i] != '-') polynomial = "+" + polynomial;

    int j = 0;
    while (polynomial[j] != '\0')
        if (isspace(polynomial[j])) polynomial.erase(j, 1);
        else j++;

    std::map <long int, long int> my_map;
    std::map <long int, long int>::reverse_iterator it;

    while (!polynomial.empty()) {
        std::cmatch result;
        bool znak = false;
        if (polynomial[i] == '-') znak = true;

        std::regex regular("([+-])""([\\w *^]*)");

        regex_search(polynomial.c_str(), result, regular);

        std::string str = result[i];

        if (str.find('x') == -1) {
            polynomial.erase(i, 1);
            while (polynomial[i] != '+' && polynomial[i] != '-' && polynomial[i] != '\0') polynomial.erase(i, 1);
            continue;
        }

        j = 1;
        int one = 0, two = 0;
        if (isdigit(str[j]))
            while (str[j] != '*') {
                one = one * 10 + (str[j] & 0x0F);
                j++;
            }
        while (str[j] != 'x') j++;
        if (str[j+1] == '^') {
            j += 2;
            while (str[j] != '\0') {
                two = two * 10 + (str[j] & 0x0F);
                j++;
            }
        }

        if (!one) one++;
        if (znak) one *= -1;
        if (two == 1) two--;

        if (my_map.count(two)) my_map[two] += one;
        else my_map[two] = one;

        polynomial.erase(i, 1);
        while (polynomial[i] != '+' && polynomial[i] != '-' && polynomial[i] != '\0') polynomial.erase(i, 1);

    }
    for (it = my_map.rbegin(); it != my_map.rend(); it++) if (it->first != 0) it->second *= it->first;

    std::string s_numb = "";
    for (j = 0, it = my_map.rbegin(); it != my_map.rend(); it++, j++) {
        long i_numb = it->second;
        if (i_numb < 0) { s_numb += '-'; i_numb *= -1; }
        else if (i_numb > 0 && j != 0) s_numb += '+';

        if(i_numb != 1|| (i_numb == 1 && it->first == 0)) {
            std::string s = "";
            while (i_numb != 0) {
                s += ((i_numb % 10) + '0');
                i_numb /= 10;
            }
            reverse(s.begin(), s.end());
            s_numb += s;
        }

        i_numb = it->first-1;
        if (i_numb == -1) continue;
        else if (i_numb == 1) s_numb += "*x";
        else {
            s_numb += "*x";
            std::string s = "";
            while (i_numb != 0) {
                s += ((i_numb % 10) + '0');
                i_numb /= 10;
            }
            reverse(s.begin(), s.end());
            s_numb += "^";
            s_numb += s;
        }
    }

    return s_numb;
}

int main() {
    std::string str;
    std::getline (std::cin, str);
    std::cout << derivative(str);

    return 0;
}
