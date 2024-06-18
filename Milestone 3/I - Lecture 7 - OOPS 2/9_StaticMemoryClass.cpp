// Static Memory = means which belongs to a class

class Student {
        static int totalStudents;      // total number of students present

    public :

        int rollNumber;
        int age;

        // static int totalStudents;      // total number of students present

        Student() {
            totalStudents++;
        }

        int getRollNumber() {
            return rollNumber;
        }

        static int getTotalStudents() {
            return totalStudents;
        }
};

// initialize static data memory
int Student :: totalStudents = 0;
// data_type class_name :: name_of_the_property = the_value_what_you_want_to_give; 


/*
        To access the static the property, we need to access in the below format :
        cout << class_name :: name_of_the_property;
        "::" = scope resolution operator
        for example, - 
        cout << Student :: totalStudents;
*/

/*
        Static Functions only access the static properties.
        Static Function does not have "this" keyword.
        
*/