#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    while (T--) {
        string S;
        getline(cin, S); 

        unordered_map<string, int> wordCount;
        stringstream ss(S);
        string word;
        string maxWord;
        int maxCount = 0;

        while (ss >> word) {
            wordCount[word]++;

            if (wordCount[word] > maxCount || 
               (wordCount[word] == maxCount && (maxWord.empty() || wordCount[maxWord] < wordCount[word]))) {
                maxWord = word;
                maxCount = wordCount[word];
            }
        }

        cout << maxWord << " " << maxCount << endl;
    }

    return 0;
}
