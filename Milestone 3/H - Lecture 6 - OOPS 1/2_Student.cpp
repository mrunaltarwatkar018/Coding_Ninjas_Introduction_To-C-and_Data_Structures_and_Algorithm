// student
class Student {

	public :

	int rollNumber;
	//int age;
    
	private :
	int age;

	public :

	~Student() {
		cout << "Destructor called ! " << endl;
	}

	// default Constructor

    Student() {
        cout << "Default Constreuctor Called !" << endl;
    }

	// Parameterized constreuctor because this constructur take arguments
	Student( int r ) {
		cout << "Constreuctor 2 Called !" << endl; 
		rollNumber = r;
	}

	Student( int rollNumber ) {
		cout << "Constreuctor 2 Called !" << endl; 
		this -> rollNumber = rollNumber;
	}

	Student( int a, int r ) {
		cout << " this : " << this<< endl;
		cout << "Constreuctor 3 Called !" << endl;
		age = a;
		rollNumber = r;
	}

	// above arguments can be write as, Here this is optional
	// Student( int a, int r ) {
	// 	cout << " this : " << this<< endl;
	// 	cout << "Constreuctor 3 Called !" << endl;
	// 	this -> age = a;
	// 	this -> rollNumber = r;
	// }

	void display() {
		cout << age << " " << rollNumber << endl;
	}

	int getAge() {
		return age;
	}
	

	void setAge( int a ) {
		age = a;
	}


	// void setAge1( int a, int password ) {
	// 	if ( password != 123 ) {
	// 		return;
	// 	}

	// 	if ( a < 0 ) {
	// 		return;
	// 	}

	// 	age = a;
	// }
};

// Access Modifiers :		
// 					The	class body contains the	declaration	of its members ( data and functions ). 
// 					They are generally two types of members in a class : private and public, 
// 					which are correspondingly grouped under two sections namely private : and public : ...
						
// 					i) Public --> 	The public members can be	accessed outside the class also. 
// 									These can be directly accessed	by any function, whether member 
// 									function of	the	class or non-member function. These are	basically 
// 									the public interface of the class.

// 					ii) Private --> 	The private members can	be accessed only from within the class. 
// 										These members are hidden from the outside world. Hence they can	
// 										be used only by member functions of	the	class in which it is declared.

// 									By default, members	of a class are private if no access specifier is provided.

// 					iii) Protected -->






// KeyWord
//  -- this : It is a keyword which holds the address the adress of current of objects & it is pointer variable