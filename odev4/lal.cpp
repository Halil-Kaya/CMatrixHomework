#include <iostream>
#include <string>
#include <math.h>
#include "lal.hpp"

using namespace std;


Matrix::Matrix(double* _entries,int _rows,int _cols){

    entries = _entries;
    rows = _rows;
    cols = _cols;

}

void Matrix::print(){

    cout<<"-------------------------------------\n";
    
    int tmpCol = 0;
    int tmpRow = 0;
    for(int i = 0 ; i < rows*cols ;i++){

        if(i%cols == 0 && i != 0){
            tmpRow++;
            tmpCol = 0;
            cout << "\n";
        }
    
        cout << entries[tmpCol + rows*tmpRow] << " ";

        tmpCol++;

    }
    cout<<"\n-------------------------------------\n";

}

Matrix Matrix::operator+(const Matrix& matrix2){


    double* entries = (double*)malloc(this->rows*this->cols*sizeof(double));
   
    for(int i = 0 ; i < rows*cols ;i++){

        entries[i] = this->entries[i];

    }

    Matrix toplamMatrix(entries,this->rows,this->cols);

    if(this->rows == matrix2.rows && this->cols == matrix2.cols){

        int tmpCol = 0;
        int tmpRow = 0;
        for(int i = 0 ; i < rows*cols ;i++){
            if(i%cols == 0 && i != 0){
                tmpRow++;
                tmpCol = 0;
            }
        
            toplamMatrix.entries[tmpCol + rows*tmpRow] += matrix2.entries[tmpCol + rows*tmpRow] ;
            tmpCol++;
        }

    }else{
        cout<<"\nİşlem geçersiz: boyut uyumsuzluğu!\n";
    }
    return toplamMatrix;
}

Matrix Matrix::operator-(const Matrix& matrix2){

    double* entries = (double*)malloc(this->rows*this->cols*sizeof(double));
   
    for(int i = 0 ; i < rows*cols ;i++){

        entries[i] = this->entries[i];

    }

    Matrix cikarmaMatrix(entries,this->rows,this->cols);

    if(this->rows == matrix2.rows && this->cols == matrix2.cols){

        int tmpCol = 0;
        int tmpRow = 0;
        for(int i = 0 ; i < rows*cols ;i++){
            if(i%cols == 0 && i != 0){
                tmpRow++;
                tmpCol = 0;
            }
        
            cikarmaMatrix.entries[tmpCol + rows*tmpRow] -= matrix2.entries[tmpCol + rows*tmpRow] ;
            tmpCol++;
        }

    }else{
        cout<<"\nİşlem geçersiz: boyut uyumsuzluğu!\n";
    }

    return cikarmaMatrix;
}

Matrix Matrix::operator*(const Matrix& matrix2){

    double* yeniMatrix;

    yeniMatrix = (double*)malloc((this->rows*matrix2.cols)*sizeof(double));

    Matrix carpmaMatrix(yeniMatrix,this->rows,matrix2.cols);

    if(this->cols == matrix2.rows){

        int tmpCol = 0;
        int tmpRow = 0;
        for(int i = 0 ; i < this->rows*matrix2.cols ;i++){

            if(i%cols == 0 && i != 0){
                tmpRow++;
                tmpCol = 0;
            }
                
            for(int k = 0 ; k < this->rows ; k++){
            carpmaMatrix.entries[rows*tmpRow + tmpCol] += this->entries[rows*tmpRow + k]  *   matrix2.entries[k*rows + tmpCol]; 
            }
            tmpCol++;

        }

    }else{
        cout<<"\nİşlem geçersiz: boyut uyumsuzluğu!\n";
    }

    return carpmaMatrix;
}

Vector Matrix::operator*(const Vector &vector) {

	double *entries = (double*) malloc(this->rows * sizeof(double));
	Vector toplamVector(entries, this->rows);


	if (vector.rows == this->cols) {
        

		int index = 0;
		for (int i = 0; i < this->rows; i++) {


			for (int j = 0; j < this->cols; j++) {
				
                toplamVector.entries[index] +=  vector.entries[j] * this->entries[j + i * this->cols];

			}

			index++;

		}
        

	} else {
        
        cout<<"\nİşlem geçersiz: boyut uyumsuzluğu!\n";
        
	}

	return toplamVector;

}

bool Matrix::operator==(const Matrix& matrix2){


    if(this->rows != matrix2.rows || this->cols != matrix2.cols){
        
        return false;

    }
    

    int tmpCol = 0;
    int tmpRow = 0;
    for(int i = 0 ; i < rows*cols ;i++){
        if(i%cols == 0 && i != 0){
            tmpRow++;
            tmpCol = 0;
        }
    
        if(this->entries[rows*tmpRow + tmpCol] != matrix2.entries[rows*tmpRow + tmpCol]){

            return false;

        }                


        tmpCol++;
    }


    return true;
}



Vector::Vector(double* _entries,int _rows) : Matrix(_entries,_rows,1){
    
    double accum = 0.;
    for (int i = 0; i < _rows; ++i) {
        accum += _entries[i] * _entries[i];
    }
    l2norm = sqrt(accum);
}


void Vector::print(){

    cout<<"-------------------------------------\n";
    for(int i = 0 ; i < rows ;i++){

        cout << entries[i] << " ";

    }
    cout<<"\n-------------------------------------\n";

}


Vector Vector::operator+(const Vector& vector2){
    
    double* entries = (double*)malloc(this->rows*sizeof(double));

    for(int i = 0; i < this->rows; i++){

        entries[i] = this->entries[i];

    }

    Vector toplamVector(entries,this->rows);
    

    if(this->rows == vector2.rows){
        
        for(int i = 0 ; i < rows ;i++){

            toplamVector.entries[i] += vector2.entries[i];

        }

    }else{

        cout<<"\nİşlem geçersiz: boyut uyumsuzluğu!\n";

    }

    return toplamVector;

}



Vector Vector::operator-(const Vector& vector2){


    double* entries = (double*)malloc(this->rows*sizeof(double));

    for(int i = 0; i < this->rows; i++){

        entries[i] = this->entries[i];

    }

    Vector cikarmaVector(entries,this->rows);

    if(this->rows == vector2.rows){
        
        for(int i = 0 ; i < rows ;i++){

            cikarmaVector.entries[i] += vector2.entries[i];

        }

    }else{

        cout<<"\nİşlem geçersiz: boyut uyumsuzluğu!\n";

    }

    return cikarmaVector;

}

Vector Vector::operator*(const Vector& vector2){


    double* icCarpimVectorEntrie = (double*)malloc(sizeof(double));


    Vector icCarpimVector(icCarpimVectorEntrie,1);

    if(this->rows == vector2.rows){


        for(int i = 0; i< this->rows; i++){

            icCarpimVector.entries[0] += this->entries[i]* vector2.entries[i];

        }


    }else{

        cout<<"\nİşlem geçersiz: boyut uyumsuzluğu!\n";

    }

    return icCarpimVector;

}

bool Vector::operator==(const Vector& vector2){

    if(this->rows != vector2.rows){
        
        return false;

    }

    for(int i = 0;i < this->rows;i++){

        if(this->entries[i] != vector2.entries[i]){
            
            return false;

        }

    }

    return true;
}
void Vector::operator++(){

    for(int i = 0;i<this->rows; i++){

        this->entries[i]++;

    }

}
void Matrix::transpose() {

	if (typeid(*this).name() == typeid(Vector).name()) {

        int size = this->rows;

		double *entries = (double*) malloc(size * sizeof(double));

		for (int i = 0; i < size; i++) {

			entries[i] = this->entries[size - i - 1];

		}

		this->entries = entries;

	} else if(typeid(*this).name() == typeid(Matrix).name()) {

        int size = this->rows * this->cols;

		double *entries = (double*) malloc( size * sizeof(double));

		for (int i = 0; i < size; i++) {

			entries[i] = this->entries[size - i - 1];

		}

		this->entries = entries;

	}
}

void Matrix::norm() {

	if (typeid(*this).name() == typeid(Matrix).name()) {

        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        double l2Norm = 0.0;

		for (int i = 0; i < this->rows * this->cols; ++i) {
			l2Norm += pow(entries[i], 2);
		}

		l2Norm = sqrt(l2Norm);

		cout << l2Norm ;


	} else if(typeid(*this).name() == typeid(Vector).name()) {
		
        cout << dynamic_cast<Vector *>(this)->l2norm;
        
	}

}

Vector **CreateVectorArray(int m,int p){
	
    Vector **vectorArray = (Vector**) calloc(m, sizeof(Vector*));  
	
    for (int i = 0; i < m; i++) {           
		vectorArray[i] = (Vector*) calloc(p, sizeof(Vector));
	}

	return vectorArray;
}

void FillVectorArray(Vector** vectorArray, int m, int p){
	
    for(int i = 0; i < m; i++){
	
    	double *entries = (double*) calloc(p, sizeof(double));
	
    	for(int j = 0; j < p; j++){
			entries[j] = (double) rand() / (double) (RAND_MAX) + 1.0; 
		}
	
    	Vector *v = new Vector(entries,p);
		vectorArray[i] = v;
		delete[]entries;
	
    }

}

Matrix vectorArray2Matrix(Vector** vectorArray, int m, int p){

	double* entries = (double*) calloc(m * p, sizeof(double));

	for(int i = 0; i < m; i++){
		for(int j = 0; j < p; j++){
			entries[i + j * m] = vectorArray[i]->entries[j];
		}
	}

	Matrix newMatrix(entries, p, m);

	return newMatrix;
}