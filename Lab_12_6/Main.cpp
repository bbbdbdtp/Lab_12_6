#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

// Функція для зчитування двох рядків з текстового файлу
void readStringsFromFile(const string& filename, string& str1, string& str2) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }
    getline(file, str1);
    getline(file, str2);
    file.close();
}

// Функція для створення черги слів з рядка
queue<string> createQueueFromString(const string& str) {
    queue<string> q;
    string word = "";
    for (char c : str) {
        if (c == ' ') {
            if (!word.empty()) {
                q.push(word);
                word = "";
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        q.push(word); // Додаємо останнє слово
    }
    return q;
}

// Функція для виведення вмісту черги на екран без видалення елементів
void printQueue(queue<string> q) {
    cout << "Queue contents:" << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// Функція для конкатенації двох черг
queue<string> concatenateQueues(queue<string>& q1, queue<string>& q2) {
    queue<string> result = q1;
    while (!q2.empty()) {
        result.push(q2.front());
        q2.pop();
    }
    return result;
}

// Функція для порівняння двох черг
bool compareQueues(const queue<string>& q1, const queue<string>& q2) {
    if (q1.size() != q2.size()) {
        return false;
    }

    queue<string> temp1 = q1;
    queue<string> temp2 = q2;

    while (!temp1.empty()) {
        if (temp1.front() != temp2.front()) {
            return false;
        }
        temp1.pop();
        temp2.pop();
    }
    return true;
}

int main() {
    string str1, str2;
    readStringsFromFile("text.txt", str1, str2);

    queue<string> queue1 = createQueueFromString(str1);
    queue<string> queue2 = createQueueFromString(str2);

    // Виведення вмісту кожної черги на екран
    cout << "Contents of Queue 1:" << endl;
    printQueue(queue1);
    cout << "Contents of Queue 2:" << endl;
    printQueue(queue2);

    // Конкатенація двох черг
    queue<string> concatenatedQueue = concatenateQueues(queue1, queue2);
    cout << "Contents of Concatenated Queue:" << endl;
    printQueue(concatenatedQueue);

    // Порівняння двох черг
    compareQueues(queue1, queue2);

    return 0;
}