/*
        Inheritance

                Suppose we have three classes with names: car, bicycle, and truck. 
                The properties for each are as follows :


                    ---------------------------------------------------------------------------------------------------------
                    |               Car             |               Bicycle             |               Truck               |
                    ---------------------------------------------------------------------------------------------------------
                    |           ● Colour            |              ● Colour             |              ● Colour             |
                    |           ● MaxSpeed          |              ● MaxSpeed           |              ● MaxSpeed           |
                    |           ● Number of gears   |              ● Is Foldable?       |              ● Max weight         |
                    ---------------------------------------------------------------------------------------------------------

                From above, we can see that two of the properties: Colour and MaxSpeed, 
                are the same for every object. Hence, we can combine all these in one 
                parent class and make the above three classes as its subclass. This 
                property is called Inheritance.

                Technically, inheritance is defined as the process of acquiring the 
                features and behaviours of a class by another class. Here, the class 
                that contains these members is called the ​base class​ and the class 
                that inherits these members from the base class is called the ​derived 
                class ​of that base class​.

                Access Modifiers

                When creating a derived class from a base class, we need to use access 
                modifiers to inherit data members of the base class. These are:

                            ●   Public
                            ●   Private
                            ●   Protected

                The "​public"​ data members can be accessed by any of its child class as 
                well as the class objects.

                "Private" ​data members are inaccessible outside the class. These can’t 
                be accessed even by the child classes.

                "Protected" ​data members can only be accessed by the derived classes 
                but are inaccessible using the class objects.


*/