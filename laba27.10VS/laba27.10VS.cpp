/**********************************
*Автор:Витвинова Альвина          *
*Задание:Строки,векторы и словари *
*Вариант:1                        *
**********************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    char part;
    cout << "Enter part (A, B, C or D): ";
    cin >> part;

    if (part == 'A' || part == 'a') {
        cin.ignore();
        cout << "Enter string: ";
        string text;
        getline(cin, text);

        int count = 0;
        for (int i = 0; i < text.length(); i++) {
            if (text[i] >= '0' && text[i] <= '9') {
                count++;
            }
        }
        cout << "Answer: " << count << endl;
    }
    else if (part == 'B' || part == 'b') {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements separated by space: ";
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                result.push_back(arr[i]);
            }
        }

        cout << "Answer: ";
        if (result.size() == 0) {
            cout << "EMPTY";
        }
        else {
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << " ";
            }
        }
        cout << endl;
    }
    else if (part == 'C' || part == 'c') {
        int count;
        cout << "Enter number of pairs: ";
        cin >> count;

        map<string, int> myMap;
        cout << "Enter pairs (key value):" << endl;
        for (int i = 0; i < count; i++) {
            string key;
            int val;
            cin >> key >> val;
            myMap[key] = val;
        }

        string query;
        cout << "Enter key to search: ";
        cin >> query;

        if (myMap.count(query) > 0) {
            cout << "Answer: " << myMap[query] << endl;
        }
        else {
            cout << "Answer: NONE" << endl;
        }
    }
    else if (part == 'D' || part == 'd') {
        int n;
        cout << "Enter number of records: ";
        cin >> n;
        cin.ignore();

        vector<map<string, string>> records;
        cout << "Enter First Name and Last Name (each on a new line):" << endl;

        for (int i = 0; i < n; i++) {
            string first, last;
            getline(cin, first);
            getline(cin, last);

            map<string, string> person;
            person["first"] = first;
            person["last"] = last;
            records.push_back(person);
        }

        vector<string> unique_names;
        for (int i = 0; i < records.size(); i++) {
            string fullName = records[i]["first"] + " " + records[i]["last"];

            bool isDuplicate = false;
            for (int j = 0; j < unique_names.size(); j++) {
                if (unique_names[j] == fullName) {
                    isDuplicate = true;
                    break;
                }
            }

            if (!isDuplicate) {
                unique_names.push_back(fullName);
            }
        }

        cout << "Answer:" << endl;
        if (unique_names.size() == 0) {
            cout << "EMPTY" << endl;
        }
        else {
            for (int i = 0; i < unique_names.size(); i++) {
                cout << unique_names[i] << endl;
            }
        }
    }
    else {
        cout << "Invalid part" << endl;
    }

    return 0;
}