#include<iostream>
using namespace std;

int main() {
    int a[10];
    cout << a << endl;
    cout << &a[0] << endl;

    a[0] = 5;
    a[1] = 10;
    cout << *a << endl;

    cout << *(a + 1) << endl;

    int * p = &a[0];

    cout << a << endl;
    cout << p << endl;

    cout << &p << endl;
    cout << &a << endl;


    cout << sizeof(p) << endl;
    cout << sizeof(a) << endl;

    p = p + 1;
    p = a + 1;

}



/*
                ==> Pointer and Arrays :

                                Pointers and arrays are intricately linked. An Array is actually a pointer that	
                                points to the first element of the array. Because the array variable is	apointer, 
                                you can dereference it, which returns array element 0.

                                Consider the following code –

                                                int a[] = {1,2,3,4,5};
                                                int *b	= &a[0];
                                                cout << b << endl;
                                                cout << a << endl;
                                                cout << *b << endl;	// This	will print 1

                                        Both b and a will print same same address as they are referring to first element of the	array.
                                        Also in	arrays - a[i] is same as *(a + i).

                                Consider an example for the same – 

                                                #include<iostream>
                                                using namespace std;

                                                int main() {
                                                        int a[5] = {1,2,3,4,5};
                                                        cout << *(a + 2) << endl;
                                                }

                                                Output : 
                                                        3   

                        
                ==> Differences between arrays and pointers :        
                        1. the sizeof operator :

                                sizeof(array)	returns	the	amount	of	memory	used	by	all	elements	in	
                                array whereas sizeof(pointer)	only	returns	the	amount	of	memory	used	
                                by	the pointer	variabl itself.
                                        #include<iostream>
                                        using	namespace	std;
                                        int	main(){
                                        		int	a[5]	= {1,2,3,4,5};
                                        		int	*b	=	&a[0];
                                        		cout	<<	sizeof(a)	<<	endl;
                                        		cout	<<	sizeof(b)	<<	endl;
                                        }
                                        Output	:
                                                20
                                                8		//	Size	of	pointer	is	compiler	dependent.	Here	it	is	8.
        
                        2. the & operator :

                                In	the	example	above	&a is	an	alias	for	&a[0]	and	returns	the	address	of	
                                the	first element	in	array
                                &b returns	the	address	of	pointer.
        
                        3. Pointer variable can	be assigned a value whereas array variable cannot be :
        
                                        int	a[10];
                                        int	*p;	
                                        p=a;	 //legal
                                        a=p;	 //illegal

                        4. Arithmetic on pointer variable is allowed, but not allowed on array variable :

                                        p++;	 //Legal
                                        a++;	 //illegal
*/