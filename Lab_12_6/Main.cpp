#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

// ������� ��� ���������� ���� ����� � ���������� �����
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

// ������� ��� ��������� ����� ��� � �����
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
        q.push(word); // ������ ������ �����
    }
    return q;
}

// ������� ��� ��������� ����� ����� �� ����� ��� ��������� ��������
void printQueue(queue<string> q) {
    cout << "Queue contents:" << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// ������� ��� ������������ ���� ����
queue<string> concatenateQueues(queue<string>& q1, queue<string>& q2) {
    queue<string> result = q1;
    while (!q2.empty()) {
        result.push(q2.front());
        q2.pop();
    }
    return result;
}

// ������� ��� ��������� ���� ����
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

    // ��������� ����� ����� ����� �� �����
    cout << "Contents of Queue 1:" << endl;
    printQueue(queue1);
    cout << "Contents of Queue 2:" << endl;
    printQueue(queue2);

    // ������������ ���� ����
    queue<string> concatenatedQueue = concatenateQueues(queue1, queue2);
    cout << "Contents of Concatenated Queue:" << endl;
    printQueue(concatenatedQueue);

    // ��������� ���� ����
    compareQueues(queue1, queue2);

    return 0;
}