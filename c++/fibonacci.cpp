#include <iostream>

class Fibonacci {

    public:

        const static int FIRST_TERM = 0;

        const static int SECOND_TERM = 1;

        Fibonacci () {}

        int getNthTerm(int term) {

            int sum, one = Fibonacci::FIRST_TERM, two = Fibonacci::SECOND_TERM;

            for(int i = 1; i < term; i++) {
                sum = one + two;
                one = two;
                two = sum;
            }

            return sum;

        }

};