template <typename T>

class QueueUsingArray {
	T *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;

	public :

	QueueUsingArray(int s) {
		data = new T[s];        // s denotes the size of an queue
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

    // Function getsize() returns the number of elements which arre present in Queue
	int getSize() {
		return size;
	}

    // Function isEmpty() returns the if Queue empty or not
	bool isEmpty() {
		return size == 0;
	}

	// to insert an element : enqueue( element );
	void enqueue(T element) {
		if(size == capacity) {
			cout << "Queue Full ! " << endl;
			return;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity ;
		if(firstIndex == -1) {
			firstIndex = 0;
		}
		size++;
	}
	
    // to print the first element of queue
	T front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

    // to delete and retuen the first element of queue
	T dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		T ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
        // if my queue is empty the reset the firstIndex to -1 and nextIndex to 0
		if(size == 0) {
			firstIndex = -1;
			nextIndex = 0;
		}
		return ans;
	}

};

