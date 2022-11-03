/*
Кодирование (декодирование) Хаффмана

По данной непустой строке, состоящей из строчных букв латинского алфавита, 
постройте оптимальный беспрефиксный код. В первой строке выведите количество различных букв k, 
встречающихся в строке, и размер получившейся закодированной строки. В следующих k строках 
запишите коды букв в формате "letter: code". В последней строке выведите закодированную строку.

Sample Input 1:
a

Sample Output 1:
1 1
a: 0
0

Sample Input 2:
abacabad

Sample Output 2:
4 14
a: 0
b: 10
c: 110
d: 111
01001100100111
*/

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Huffman {
    struct CharSetFrequency {
        string char_set;
        int frequency;

        bool operator < (const CharSetFrequency& other) const {
            return tie(frequency, char_set) > tie(other.frequency, other.char_set);
        }
    };


public:
    static unordered_map<char, string>encode(const string& text);

    static string decode(const string& text, const unordered_map<char, string>& huffman_encoding);

};

unordered_map<char, string>Huffman::encode(const string& text) {
    unordered_map<char, int> char_frequencies;
    for (auto c : text) {
        char_frequencies[c]++;
    }

    vector<CharSetFrequency> frequencies;
    for (auto char_frequency : char_frequencies) {
        frequencies.push_back({string(1, char_frequency.first), char_frequency.second });
    }

    if (frequencies.size() == 1) {
        unordered_map<char, string>result;
        result[frequencies[0].char_set[0]] = "0";
        return result;
    }

    // huffman algorithm
    unordered_map<char, string> result;
    priority_queue<CharSetFrequency> q(frequencies.begin(), frequencies.end());
    while (q.size() >= 2) {
        auto first = q.top();
        q.pop();
        auto second = q.top();
        q.pop();
        
        for (auto s :first.char_set) {
            result[s] = "0" + result[s];
        }
        for (auto s :second.char_set) {
            result[s] = "1" + result[s];
        }
        q.push({first.char_set + second.char_set, first.frequency + second.frequency});    
    }
    return result;
}

string Huffman::decode(const string& text, const unordered_map<char, string>& huffman_encoding) {
    size_t len = text.size();
    size_t pos = 0;
    string result;
    while (pos < len) {
        for (auto& encoded : huffman_encoding) {
            if (text.substr(pos, encoded.second.size()) == encoded.second) {
                result += encoded.first;
                pos += encoded.second.size();
                break;
            }
        }
    }
    return result;
}

int main() {
    string text;
    cin >> text;

    auto huffman_encoding = Huffman::encode(text);

    string encoded_text;
    for (auto c : text) {
        encoded_text += huffman_encoding[c];
    }

    cout << huffman_encoding.size() << " " << encoded_text.size() << endl;
    for (auto& encoded : huffman_encoding) {
        cout << encoded.first << ": " << encoded.second << endl;
    }
    cout << encoded_text << endl;

    return 0;
}