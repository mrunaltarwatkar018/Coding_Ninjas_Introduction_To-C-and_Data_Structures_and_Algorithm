#include<iostream>
using namespace std;


class Fraction {
	private :

		int numerator;
		int denominator;

	public :

		Fraction(int numerator, int denominator) {
			this -> numerator = numerator;
			this -> denominator = denominator;
		}


        // Getters and Setters
        int getNumerator() const {
            return numerator;
        }

        int getDenominator() const {
            return denominator;
        }
        void setNumerator(int n) {
            numerator = n;
        }
        void setDenominator(int d) {
            denominator = d;
        }


        // for printing 
		void print() const {
			cout << this -> numerator << " / " << denominator << endl;
		}


		void simplify() {
			int gcd = 1;
			int j = min(this -> numerator, this -> denominator);
			for(int i = 1; i <= j; i++) {
				if(this -> numerator % i == 0 && this -> denominator % i == 0) {
					gcd = i;
				}
			}
			this -> numerator = this -> numerator / gcd;
			this -> denominator = this -> denominator / gcd;
		}

		void add( Fraction const & f2 ) {
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			numerator = num;
			denominator = lcm;
			simplify();	

		}


        void multiply( Fraction const &f2 ) {
            numerator = numerator * f2.numerator;
            denominator = denominator * f2.denominator;

            simplify();
        }
};
