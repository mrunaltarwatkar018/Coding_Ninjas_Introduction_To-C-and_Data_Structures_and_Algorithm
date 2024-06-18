class Student {
    public :

        int age;
        const int rollNumber;
        int &x;     // age refference variable

        // Student(int r) : rollNumber(r) {
        //     // rollNumber = r;
        // }

        // Student(int r, int a) : rollNumber(r), age(a) {
        //     // rollNumber = r;
        // }

        // Above statements can be written as
        // Student(int r, int age) : rollNumber(r), age(age) {
        //     // rollNumber = r;
        // }

        Student(int r, int a) : rollNumber(r), age(a), x(this -> age) {
            // rollNumber = r;
        }
};