//Виселица
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main() {
    //подготовка
    const int MAX_WRONG = 8; // максимальное количество ошибок
    vector <string> words; // подборка слов для разгадывания
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    words.push_back("LOVELY");
    words.push_back("ALPHABET");
    words.push_back("ATHLETICS");
    words.push_back("BUSINESS");
    words.push_back("SPACE");
    words.push_back("TRAINING");
    words.push_back("BASKETBALL");
    words.push_back("WALKING");
    words.push_back("AUTO");
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0]; // слово для отгадывания
    int wrong = 0; // текущее количество ошибок
    string soFar(THE_WORD.size(), '-'); // часть слова открытая на данный момет
    string used = ""; // уже отгаданные буквы
    cout << "\t\tWhelcome to Hangman. Good luck! \n";
    
    // основной цикл
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) 
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;
        
        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); // перевод в верхний регистр
        
        while (used.find(guess) != string::npos) 
        {
            cout << "\nYou've already guassed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        used += guess;
        if (THE_WORD.find(guess) != string::npos) 
        {
            cout << "That's right! " << guess << " is in the word.\n";
            // обновить переменную soFar, включив в неё новую угаданную букву
            for (int i = 0; i < THE_WORD.length(); ++i) 
            {
                if (THE_WORD[i] == guess) 
                {
                    soFar[i] = guess;
                }
            }
        }
        else 
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }
    
    // конец игры
    if (wrong == MAX_WRONG)
    {
        cout << "\nYou've been hanged!";
    }
    else 
    {
        cout << "\nYou guessed it!";
    }
    cout << "\nThe word was " << THE_WORD << endl;
    
    return 0;

}