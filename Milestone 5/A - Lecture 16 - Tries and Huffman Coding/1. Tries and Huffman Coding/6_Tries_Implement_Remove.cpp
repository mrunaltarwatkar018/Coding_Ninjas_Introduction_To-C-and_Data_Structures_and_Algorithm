#include<iostream>
using namespace std;
#include "2_TrieNode_Class.h"
#include <string>

class Trie {
	TrieNode *root;

	public :

	Trie() {
		root = new TrieNode('\0');
	}

	bool search(TrieNode *root, string word) {
		if( word.size() == 0 ) {
			return root -> isTerminal;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			return false;
		}

		// Recursive call
		return search(child, word.substr(1));
	}

	bool search(string word) {
		return search(root, word);
	}


	void insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			root -> isTerminal = true;
			return;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		insertWord(root, word);
	}


    void removeWord( TrieNode * root, string word ) {
        // Base case
		if(word.size() == 0) {
			root -> isTerminal = false;
			return;
		}

		// Small calculation
        TrieNode * child;
        int index = word[0] - 'a';

        if ( root -> children[index] != NULL ) {
            child = root -> children[index];
        }
        else {
            // word not found
            return;
        }

		removeWord( child, word.substr(1) );
        
		// Remove child Node if it is useless

        if ( child -> isTerminal == false ) {
            for( int i = 0; i < 26; i++ ) {
				if( child -> children[i] != NULL ) {
					return;
				}
			}

            // to dealloacte the node
			delete child;
			root -> children[index] = NULL;
        }
    }

    void removeWord( string word ) {
        removeWord( root, word );
    }
};



int main() {
	Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("dot");

	cout << "Word is Exist : " << t.search("and") << endl;

	t.removeWord("and");
	cout << "Word is not Exist : " << t.search("and") << endl;
}