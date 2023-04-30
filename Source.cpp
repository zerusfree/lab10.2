#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateTXT(char* fname)
{
    ofstream fout(fname);
    char ch;
    string s;
    do
    {
        cin.get();
        cin.sync();
        cout << "enter line: "; getline(cin, s);
        s += ' ';
        fout << s << endl;
        cout << "continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << endl;
}
void PrintTXT(char* fname)
{
    ifstream fin(fname);
    string s;
    while (getline(fin, s))
    {
        cout << s << endl;
    }
    cout << endl;
}

bool checkWords(const string& filename)
{
    ifstream fin(filename);
    int count = 0;

    if (!fin.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return false;
    }

    string line;
    string word;
    while (getline(fin, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ') {
                word += line[i];
            }
            else {
                if (!word.empty() && word.front() == 'a') {
                    return true;
                }
                word.clear();
            }
        }

        // перевірити останнє слово
        if (!word.empty() && word.front() == 'a') {
            return true;
        }

    }
    fin.close();
    return false;

}

int main()
{
    char fname[100];

    cout << "enter file name: "; cin >> fname;

    CreateTXT(fname);
    PrintTXT(fname);

    if (checkWords(fname)) {
        cout << "The file '" << fname << "' contains words which starts at character a \n";
    }
    else {
        cout << "The file '" << fname << "' does not contain words which starts at character a \n";
    }

    return 0;
}
