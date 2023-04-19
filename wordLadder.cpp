// Mathew Breland
// CPSC 2120 - Widman
// 4/19/2023
// Word ladder assignment 

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

vector<string> V; // words from wordlist05.txt

void loadWordList() {

    ifstream wordList("wordlist05.txt");    // creating ifstream loading in the word list 
    string word;

    while (getline(wordList, word)) {       // using getline to load in each word
        V.push_back(word);                  // pushing back the words to the vector
        
    }
}

void wordLadder(string s, string t, int& steps, vector<string>& p)
{
    
    loadWordList(); // calling the loadwordlist function so that each word loads 

    unordered_map<string, int> dist;
    unordered_map<string, string> pred;
    unordered_map<string, vector<string>> adj;

    queue<string> q;

    set<string> words(V.begin(), V.end());

    for (const string& word : words) {

        dist[word] = -1;    // setting dist equal to -1
        pred[word] = "";    // setting pred equal to null

        for (int i = 0; i < 5; i++) {

            string newWord = word;  // sttting new word equal to word 

            for (char c = 'a'; c <= 'z'; c++) {

                newWord[i] = c;

                if (words.count(newWord) && newWord != word) {  // if the words have count of newWord and newWord != word

                    adj[word].push_back(newWord);   // push back newWord
                }
            }
        }
    }

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {      // while q isnt empty 
        string u = q.front(); // u is equal to the front of the q string 
        q.pop();              // popping q back

        for (const string& v : adj[u]) {

            if (dist[v] == -1) {

                dist[v] = dist[u] + 1;
                pred[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[t] == -1) {    // if distance of t is negative 1 then steps = 0
        steps = 0;
    }

    else {

        steps = dist[t];                // otherwise steps = dist t 

        string currentWord = t;         // setting string equal to the current word 

        while (currentWord != "") { 
                                        // while curr word isnt null push back to p
            p.push_back(currentWord);
            currentWord = pred[currentWord];
        }

        reverse(p.begin(), p.end());    // reversing p begin to p end
    }
}

// main would go here 

