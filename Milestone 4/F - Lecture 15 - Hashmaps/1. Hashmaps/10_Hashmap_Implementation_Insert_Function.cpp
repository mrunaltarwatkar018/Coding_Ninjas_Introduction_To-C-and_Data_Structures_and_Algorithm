
/*  Hashmap implementation - Insert */

/*
    As discussed earlier, we will be implementing separate chaining. We will be using
    value as a template and key as a string as we are required to find the hash code for
    the key. Taking key as a template will make it difficult to convert it using hash code.

    Let’s look at the code for the same.

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

        // for returning the value corresponding to a key
        V getValue ( string key ) {

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

        V remove ( string key ) {

        }
        
};







/*
        #include <string>
        using namespace std;

        template <typename V>
        class MapNode {
            public:
                string key;
                V value;
                MapNode* next;

                MapNode(string key, V value) {
                    this->key = key;
                    this->value = value;
                    next = NULL;
                }

                ~MapNode() {
                    delete next;
                }
        };

        template <typename V>
        class ourmap {
            MapNode<V>** buckets;
            int count;
            int numBuckets;

            public:
            ourmap() {
                count = 0;
                numBuckets = 5;
                buckets = new MapNode<V>*[numBuckets];
                for (int i = 0; i < numBuckets; i++) {
                    buckets[i] = NULL;
                }
            }

            ~ourmap() {
                for (int i = 0; i < numBuckets; i++) {
                    delete buckets[i];
                }
                delete [] buckets;
            }

            int size() {
                return count;
            }

            V getValue(string key) {
                
            }

            private:
            int getBucketIndex(string key) {
                int hashCode = 0;

                int currentCoeff = 1;
                for (int i = key.length() - 1; i >= 0; i--) {
                    hashCode += key[i] * currentCoeff;
                    hashCode = hashCode % numBuckets;
                    currentCoeff *= 37;
                    currentCoeff = currentCoeff % numBuckets;
                }

                return hashCode % numBuckets;
            }

            public:
            void insert(string key, V value) {
                int bucketIndex = getBucketIndex(string key);
                MapNode<V>* head = buckets[bucketIndex];
                while (head != NULL) {
                    if (head->key == key) {
                        head->value = value;
                        return;
                    }
                    head = head->next;
                }
                head = buckets[bucketIndex];
                MapNode<V>* node = new MapNode<V>(key, value);
                node->next = head;
                buckets[bucketIndex] = node;
                count++;
            }

        };
*/