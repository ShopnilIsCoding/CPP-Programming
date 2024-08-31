#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    while (T--) {
        string S;
        getline(cin, S); 

        vector<string> words;
        vector<int> counts;
        stringstream ss(S);
        string word;
        string maxWord;
        int maxCount = 0;
        int firstMaxIndex = -1;

        while (ss >> word) {
           
            bool found = false;
            for (int i = 0; i < words.size(); i++) {
                if (words[i] == word) {
                    counts[i]++;
                    found = true;

                   
                    if (counts[i] > maxCount || (counts[i] == maxCount && firstMaxIndex == -1)) {
                        maxWord = words[i];
                        maxCount = counts[i];
                        firstMaxIndex = i;
                    }
                    break;
                }
            }

           
            if (!found) {
                words.push_back(word);
                counts.push_back(1);

               
                if (maxCount == 0 || 1 > maxCount) {
                    maxWord = word;
                    maxCount = 1;
                    firstMaxIndex = words.size() - 1;
                }
            }
        }

        cout << maxWord << " " << maxCount << endl;
    }

    return 0;
}
