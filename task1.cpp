#include "task1.h"
#include "constants.h"

namespace task1 {
    void process_sequence(char** &sequence, int& size_of_matrix, int& length) {
        for (int k {0}; k < size_of_matrix; k++) {
        if (string(sequence[k]).find('*') != -1) {
            char* new_sequence { new char[size_of_matrix * 2]};
            int j {0};
            for (int i {0}; i < length; i++) {
                if (sequence[k][i] != '*') {
                    new_sequence[j++] = sequence[k][i];
                } else {
                    continue;
                }
                new_sequence[j++] = sequence[k][i];
            }
            new_sequence[j] = '\0';
            delete[] sequence[k];
            sequence[k] = new_sequence;
            //length = j; // Update the length
        }
        }
    }
    void read_from_file(char** &sequence, int& size_of_matrix, int& length) {
        ifstream file(constants::task259Input);
        if (file.is_open()) {
            string line;
            size_of_matrix = 0;
            while (getline(file, line)) {
                length = line.length();
                char* temp  {new char[line.length() + 1]};
                strcpy(temp, line.c_str());
                sequence = (char**)realloc(sequence, (size_of_matrix + 1) * sizeof(char*));
                sequence[size_of_matrix] = temp;
                process_sequence(sequence, size_of_matrix, length);
                size_of_matrix++;
            }
            file.close();
        } else {
            cerr << "Unable to open file!" << endl;
        }
    }
    void write_to_file(char* sequence, int& calls_write) {
        if (calls_write > 0) {
            ofstream file(constants::task259Output, ios::app);
            if (file.is_open()) {
                file << sequence << endl;
                file.close();
            } else {
                cerr << "Unable to write to file!" << endl;
            } } 
        else {
            ofstream file(constants::task259Output);
            if (file.is_open()) {
                file << sequence << endl;
                file.close();
            } else {
                cerr << "Unable to write to file!" << endl;
            } 
        } 
}
    void task259() {
        char** sequence = nullptr;
        int length {0}, size_of_matrix {0}, calls_write {0};
        cout << "Task1 is started ..." << std::endl;
        string ans;
        cout << "Enter any symbol (to continue) or b (to break): ";
        getline(cin, ans);
        while (ans != "b" && ans != "B") {
            string choice;
            cout << "Do you want to read data from a file (yes - y, no - any symbol)?: ";
            getline(cin, choice);
            if (choice == "Y" || choice == "y") {
                read_from_file(sequence, size_of_matrix, length);
            } else {
                cout << "Enter a sequence of characters: ";
                string input;
                getline(cin, input);
                size_of_matrix = 1;
                length = input.length();
                sequence = new char*[1];
                sequence[0] = new char[length + 1];
                strcpy(sequence[0], input.c_str());
                process_sequence(sequence, size_of_matrix, length);
            }
            string outputChoice;
            cout << "Do you want to output the result to a file (yes - y, no - any symbol)?: ";
            getline(cin, outputChoice);
            if (outputChoice == "Y" || outputChoice == "y") {
                for (int i {0}; i < size_of_matrix; i++) {
                write_to_file(sequence[i], calls_write);
                calls_write++;}
                cout << "Result's been written." << endl;
            } else {
                cout << "Processed sequence: " << endl;
                for (int i {0}; i < size_of_matrix; i++) {
                    cout << sequence[i];
                    cout << endl;}
            }
            for (int i {0}; i < size_of_matrix; i++) {
                delete[] sequence[i];
                sequence[i] = nullptr;}
            delete[] sequence;
            sequence = nullptr;
            size_of_matrix = 0;
            length = 0;
            calls_write = 0;
            cout << "Do you want to continue? Enter any symbol (to continue) or b (to break): ";
            getline(cin, ans);}
        cout << "Task1 is finished ...\n"; 
}
}
