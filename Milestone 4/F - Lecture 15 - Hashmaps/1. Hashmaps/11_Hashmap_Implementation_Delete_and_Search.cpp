
/* Hashmap implementation - Delete and search */

/*
    Refer to the code below and follow the comments in it.
*/


#include <iostream>
#include <string>
using namespace std;

template <typename V>
// class for linked list.
class MapNode {
	public:
		string key;     // to store key of type string
		V value;        // to store value of type template
		MapNode* next;  // to store the next pointer

        // constructor to assign values
		MapNode(string key, V value) {
			this->key = key;
			this->value = value;
			next = NULL;
		}

        // Destructor to delete the node.
		~MapNode() {
			delete next;
		}
};


template <typename V>
// for storing the bucket array
class ourMap {
    // a 2D bucket array to store the head pointers
    // of the linked list corresponding to each index.
    MapNode<V>** buckets;

    int count;          // to store the size
    int numBuckets;     // to store number of buckets for compression function

    public :
        // constructor: to initialize the values
        OurMap() {
            count = 0;
            numBuckets = 5;
            buckets = new MapNode <V> * [numBuckets];   // dynamically allocated
            for ( int i = 0; i < numBuckets; i++ ) {
			    buckets[i] = NULL;      // assigning each head pointer to NULL
		    }
        }

        // destructor: to delete the storage used
        ~ OurMap() { 
            // first-of-all delete each linked list
            for ( int i = 0; i < numBuckets; i++ ) { 
                delete buckets[i];
            }
            // the delete the total bucket
            delete [] buckets; 
        }

        // to return the size of the map
        int size() {
		    return count;
	    }

        // to search for the key
        V getValue ( string key ) {
            int bucketIndex = getBucketIndex(string key);       // find the index
            MapNode<V>* head = buckets[bucketIndex];        // head of linked list
            while ( head != NULL ) {
                if ( head->key == key ) { // if found, returned the value
                    return head->value;
                }
                head = head -> next;
            }
            return 0; // if not found, returning 0 as default value.
        }

    private :
        int getBucketIndex( string key ) {
            // to provide the index using hash function
            int hashCode;
            int currentCoeff = 1;

            // using “abcd” = (‘a’ * p^3) + (‘b’ * p^2) + (‘c’ * p^1) + (‘d’ * p^0) as our hash code
            for ( int i = key.length() - 1; i >= 0; i-- ) {
                hashCode += key[i] * currentCoeff;
                hashCode = hashCode % numBuckets;
                currentCoeff *= 37;     // taking p = 37
                currentCoeff = currentCoeff % numBuckets;
            }

            return hashCode % numBuckets;

        }

    public :
        void insert ( string key, V value ) {
            // To get the bucket index, i.e., passing it through the hash function
            int bucketIndex = getBucketIndex(string key);
            // to insert the key-value pair in the linked list corresponding to index obtained
            MapNode<V>* head = buckets[bucketIndex];
            while ( head != NULL ) {
                if ( head -> key == key ) {         // If key already present, then we are
                    head -> value = value;        // just updating the value against it
                    return;
                }
                head = head -> next;
            }
            // otherwise creating a new node and inserting that node before head so making it
            // as the head and marking the bucket index to this node as the new head
            head = buckets[bucketIndex];
            MapNode<V>* node = new MapNode<V>(key, value);
            node -> next = head;
            buckets[bucketIndex] = node;
            count++;
        }

        // to delete the key-value pair
        V remove ( string key ) {
            int bucketIndex = getBucketIndex(key); // find the index
            MapNode<V>* head = buckets[bucketIndex]; // head node
            MapNode <V> * prev = NULL;      // previous pointer

            while ( head -> key == key ) {
                if ( head -> key == key ) {
                    if ( prev == NULL ) {
                        buckets[bucketIndex] = head -> next;
                    } else {
                        prev -> next = head -> next;    // connecting previous to the head’s next pointer
                    }
                    V value = head->value;
                    head -> next = NULL; // before calling delete over it, in
                    // order to avoid complete linked list deletion, we have to assign it’s next to NULL
                    delete head;
                    count--;        // reducing the size
                    return value;   // return the value stored at deleted node
                }
                prev = head;
                head = head -> next;
            }
            return 0;       // means that value not found
        }
        
};


