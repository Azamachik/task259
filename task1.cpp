#include "task1.h"
#include "constants.h"

namespace task1{
// Функция для обработки последовательности символов
void process_sequence(char* &sequence, int& length) {
    if (string(sequence).find('*') != -1) {
    char* new_sequence = new char[length * 2];
    int j = 0;
    for (int i {0}; i < length; i++) {
        if (sequence[i] != '*' && sequence[i] != '\n') {
            new_sequence[j++] = sequence[i];
        }
        else if (sequence[i] = '*') {continue;}
        new_sequence[j++] = sequence[i];
    }
    new_sequence[j] = '\0';

    delete[] sequence; // Освобождаем предыдущую память
    sequence = new_sequence;
    length = j; // Обновляем длину
    }
}

// Функция для чтения данных из файла
void read_from_file(char* &sequence, int& length) {
    ifstream file(constants::task259Input);
    if (file.is_open()) {
        string data, temp;
        while (std::getline(file, temp)) {
            data += temp + '\n';
        }
        
        length = data.length();
        sequence = new char[length + 1];
        strcpy(sequence, data.c_str());
        file.close();
    } 
    else {
        cerr << "Unable to open file!" << endl;
    }
}

// Функция для записи результатов в файл
void write_to_file(char* sequence) {
    ofstream file(constants::task259Output);
    if (file.is_open()) {
        file << sequence;
        file.close();
    } 
    else {
        cerr << "Unable to write to file!" << endl;
    }
}

void task259() {
    cout << "Task1 is started ..." << endl;
    string ans;
    cout << "Enter any symbol (to continue) or b (to break): ";
    cin.ignore(1, '\n');
    getline(cin, ans);
    while (ans != "b" && ans != "B") {
    char* sequence = nullptr;
    int length = 0;
    string choice;
    cout << "Do you want to read data from a file (yes - y, no - any symbol)?: ";
    getline(cin, choice);
    if (choice == "Y" || choice == "y") {
        read_from_file(sequence, length);
    }
    else {
        cout << "Enter a sequence of characters: ";
        string input;
        getline(cin, input);
        length = input.length();
        sequence = new char[length + 1];
        strcpy(sequence, input.c_str());
    }

    // Обрабатываем последовательность
    process_sequence(sequence, length);

    string outputChoice;
    cout << "Do you want to output the result to a file (yes - y, no - any symbol)?: ";
    getline(cin, outputChoice);
    if (outputChoice == "Y" || outputChoice == "y") {
        write_to_file(sequence);
        cout << "Result's been written.\n";
    } 
    else {
        cout << "Processed sequence: " << sequence << endl;
    }

    // Освобождаем память
    delete[] sequence;
    cout << "Do you want to continue? Enter any symbol (to continue) or b (to break): ";
    getline(cin, ans);}
    cout << "Task1 is finished ...\n"; 
}
}
