#include <iostream>

class Fibonacci {

    public:

        const static int FIRST_TERM = 0;

        const static int SECOND_TERM = 1;

        Fibonacci () {}

        int getNthTerm(int term) {

            int sum, one, two;

            for (int i = 0; i <= term; i++)
            {
                if(i == 0) {
                    sum = Fibonacci::FIRST_TERM + Fibonacci::SECOND_TERM;
                    one = Fibonacci::SECOND_TERM;
                    two = sum;
                    continue;
                }

                sum = one + two;
                one = two;
                two = sum;

            }

            return sum;

        }

}