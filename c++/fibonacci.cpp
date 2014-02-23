#include <iostream>

class Fibonacci {

    private:

        double *buffer;

        int bufferLenth;

        void insertIntoBuffer(int i, double val) {
            if(i <= this->bufferLenth) {
                *(this->buffer + i) = val;
                return;
            } else {

                size_t nextSize = (i + 1) * sizeof(double);

                double *temp = (double*) realloc(this->buffer, nextSize);
                if(temp == NULL)
                    throw 1;
                else
                    this->buffer = temp;
            }

            *(this->buffer + i) = val;

            this->bufferLenth = i;
        }

    public:

        const static int FIRST_TERM = 0;

        const static int SECOND_TERM = 1;

        Fibonacci () {
            this->buffer = (double*) calloc(1, sizeof(double));
            this->bufferLenth = 1;
        }

        ~Fibonacci() {
            free(this->buffer);
        }

        double getNthTerm(int term) {

            if(term <= this->bufferLenth && *(this->buffer + term) != 0)
                return *(this->buffer + term);

            double sum = 0, one = Fibonacci::FIRST_TERM, two = Fibonacci::SECOND_TERM;

            this->insertIntoBuffer(0, one);

            sum = one + two;

            this->insertIntoBuffer(1, sum);

            int i;

            for(i = 2; i < term; i++) {
                this->insertIntoBuffer(i, sum);
                one = two;
                two = sum;
                sum = one + two;
            }

            this->insertIntoBuffer(i, sum);

            return sum;

        }

        void printBuffer() {
            for (int i = 0; i <= this->bufferLenth; i++)
            {
                std::cout << "i = " << (i) << ", val = " << *(this->buffer + i) << '\n';
            }
        }

};