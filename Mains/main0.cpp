#include <iostream>
using namespace std;

int main() {
	int numberOfEqu, numberOfIteration, gaussOrJacobi;
	int i, j;
	
	cout << "Enter Number of Equation : "; cin >> numberOfEqu;
	cout << "Enter Number of Iteration : "; cin >> numberOfIteration;
	cout << "To GaussMethod Enter 0 to JacobiMethod enter 1 : "; cin >> gaussOrJacobi;
	
	float mainArray[numberOfEqu][numberOfEqu], xArray[numberOfEqu], constantArray[numberOfEqu], initialSln[numberOfEqu], resultArray[numberOfEqu];
	
	
	//Enter Arrays
	for(i = 0; i < numberOfEqu; i++){
		for(j = 0; j < numberOfEqu; j++){
			cout << "\nEnter mainArray[" << i << "]" << "[" << j << "] : "; cin >> mainArray[i][j];
			
		}
	}
	
	for(i = 0; i < numberOfEqu; i++){
		cout << "\nEnter constantArray[" << i << "] : "; cin >> constantArray[i];
	}
	
	for(i = 0; i < numberOfEqu; i++){
		cout << "\nEnter initialSln[" << i << "] : "; cin >> initialSln[i];
	}
	
	//Print Arrays
	cout << "\nMain Array" << endl;
	for(i = 0; i < numberOfEqu; i++){
		for(j = 0; j < numberOfEqu; j++){
			cout << mainArray[i][j] << "\t";
			
		}
		cout << "\n";
	}
	
	cout << "\n\nConstantArray" << endl;
	for(i = 0; i < numberOfEqu; i++){
		cout << constantArray[i] << endl;
	}
	
	cout << "\n\nIntial Solution Array" << endl;
	for(i = 0; i < numberOfEqu; i++){
		cout << initialSln[i] << endl;
	}
	
	if(gaussOrJacobi == 0){
		cout << "\n\n\nGauss Method Solution" << endl;
		//Gauss Method
		int passNumberOfIteration = numberOfIteration;
		while(numberOfIteration > 0){
		
			//fill xArray with initialSln
			if(passNumberOfIteration == numberOfIteration)
				for(i = 0; i < numberOfEqu; i++)
					xArray[i] = initialSln[i];
			
			//Number of equation	
			for(i = 0; i < numberOfEqu; i++){
				xArray[i] =  constantArray[i] /mainArray[i][i];
				for(j = 0; j < numberOfEqu; j++){
					if(i != j)
						xArray[i] -= ((mainArray[i][j] * xArray[j]) /mainArray[i][i]);
				}
			}	
			numberOfIteration--;
					
			cout << "\n\n";
			for(i = 0; i < numberOfEqu; i++){
				cout << xArray[i] << endl;
			}
		}
	}
	else{
		cout << "\n\n\nJacobi Method Solution" << endl;
		//Jacobi Method
		int passNumberOfIteration = numberOfIteration, counter = 1;
		while(numberOfIteration > 0){
		
			//fill xArray with initialSln
			if(passNumberOfIteration == numberOfIteration)
				for(i = 0; i < numberOfEqu; i++)
					xArray[i] = initialSln[i];
			
			//Number of equation	
			for(i = 0; i < numberOfEqu; i++){
				resultArray[i] =  constantArray[i] /mainArray[i][i];
				for(j = 0; j < numberOfEqu; j++){
					if(i != j)
						resultArray[i] -= ((mainArray[i][j] * xArray[j]) /mainArray[i][i]);
				}
			}	
			
			//fill resultArray into xArray to pass results to next iteration
			for(i = 0; i < numberOfEqu; i++){
				xArray[i] = resultArray[i];
			}
					
			cout << "\n\nIteration " << counter << endl;
			for(i = 0; i < numberOfEqu; i++){
				cout << resultArray[i] << endl;
			}
			
			counter++; numberOfIteration--;
		}
	}	
	return 0;
}

