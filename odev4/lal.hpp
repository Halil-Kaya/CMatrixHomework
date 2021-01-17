#ifndef LAL_H_
#define LAL_H_

class Vector;


class Matrix{

    public:

        double* entries;
        int rows;
        int cols;


        Matrix(double* _entries,int _rows,int _cols);
        
        void print();

        Matrix operator+(const Matrix& matrix2);

        Matrix operator-(const Matrix& matrix2);

        Matrix operator*(const Matrix& matrix2);

        Vector operator*(const Vector& vector);

        bool operator==(const Matrix& matrix2);

        virtual void transpose();
        
        virtual void norm();
};



class Vector : public Matrix{

    public:

        double l2norm;


        Vector(double* _entries,int _rows);

        void print();

        Vector operator+(const Vector& vector2);

        Vector operator-(const Vector& vector2);

        Vector operator*(const Vector& vector2);

        bool operator==(const Vector& vector2);

        void operator++();

	    void operator++(int);

};

Vector **CreateVectorArray(int,int);
void FillVectorArray(Vector** vectorArray, int m, int p);
Matrix vectorArray2Matrix(Vector**,int,int);

#endif