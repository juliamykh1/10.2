#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // відкриваємо файл для читання
    ifstream fin("T1.txt");
    if (!fin) {
        cout << "Error opening file\n";
        return 1;
    }

    // знаходимо перший пробіл та зберігаємо позицію
    int spacePos = -1;
    string line;
    getline(fin, line);
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            spacePos = i;
            break;
        }
    }

    // створюємо новий файл для запису
    ofstream fout("T2.txt");
    if (!fout) {
        cout << "Error opening file\n";
        return 1;
    }

    // читаємо T1 по символу та записуємо в T2 лише літери та цифри до першого пробілу
    fin.seekg(0, ios::beg);
    char ch;
    while (fin.get(ch) && spacePos != -1) {
        if (ch == ' ' || ch == '\n') {
            break;
        }
        if (isalnum(ch)) {
            if (isupper(ch)) {
                ch = tolower(ch);
            }
            fout << ch;
        }
    }

    // закриваємо файли
    fin.close();
    fout.close();

    cout << "File T2 created successfully\n";

    return 0;
}
