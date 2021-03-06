#include <iostream>
#include <vector>
#include <string>
#include "integerset.h"

using namespace std;

integerset::integerset(){
    arraysize = 10;
    darr = new int[arraysize];
    intsize = 0;
}

integerset::integerset(const integerset &var) {
  //arraysize = var.arraysize;
  //darr = var.darr;
  //intsize = var.intsize;
  arraysize = var.arraysize;
  intsize = var.intsize;
   darr = new int[intsize];

    for(int i = 0; i < intsize; i++){
      darr[i] = var.darr[i];
    }
}

integerset::~integerset(){
    //delete [] darr;
    delete[] darr;
    //cout << "cool" << endl;
    //darr = NULL;
}
    //return 0;

integerset* integerset::operator=(const integerset &sett){
  arraysize = sett.arraysize;
  intsize = sett.intsize;

  delete [] darr;
  darr = new int[arraysize];

  for(int i = 0; i < arraysize; i++){
    darr[i] = sett.darr[i];
  }
  return this;


}


int integerset::size(){
    //int b = intsize;
    return intsize;
}

bool integerset::isempty(){
    if(intsize == 0){
        return true;
    }
    else{
        return false;
    }
}


bool integerset::contains(int a){
    for(int i = 0; i < intsize; i++){
        if(darr[i] == a){
            return true;
        }
    }
    return false;
}

void integerset::add(int a){
    if (hasintvalue(a, darr)) {
      return;
    }
    if(intsize == arraysize){
        arraysize = arraysize*2; //20
        int *darr2 = new int[arraysize];
        for(int i = 0; i < intsize; i++){
            darr2[i] = darr[i];
        }
        //intsize++;
        darr2[intsize] = a;
        intsize++;
        delete[]darr;
        darr = darr2;
        }
    else{
        darr[intsize] = a;
        intsize++;
    }
}



void integerset::remove(int a){
    for(int i = 0; i < intsize; i++){
        if(darr[i] == a){
            //darr[i] = NULL;
            for(int m = i; m < intsize; m++){
                    darr[m] = darr[m+1];
            }
            intsize--;
            //darr[i] = darr[i+1];
        }

    }
    //intsize--;
}

vector<int> integerset::getasvector(int *darr, int intsize){
    vector<int> myvector;

    for(unsigned int i = 0; i < intsize; i++){
        int b = darr[i];
        myvector.push_back(b);
    }
    return myvector;
}

integerset integerset::operator+(integerset sett){
    integerset brandnew;
    brandnew.darr = new int[intsize*2];
    brandnew.intsize = intsize;
    cout << "brandnew int size initially is " << brandnew.intsize << endl;
    for(int i = 0; i < intsize; i++){
        brandnew.darr[i] = darr[i];
    }
    int count = intsize;
    for(int i = 0; i < sett.intsize; i++){
            if(!hasintvalue(sett.darr[i], darr)){
                brandnew.darr[count] = sett.darr[i];
                count++;
                brandnew.intsize++;
            }
    }
    return(brandnew);
}
           
bool integerset::hasintvalue(int num, int* arr) {
  for (int i = 0; i< intsize; i++) {
    if (num == arr[i]) {
      return true;
    }
  }
  return false;
}

integerset integerset::operator*(integerset sett){
    integerset brandnew;
    //int count;
    if (sett.intsize > intsize) {
      brandnew.darr = new int[sett.intsize];
    }
    else {
      brandnew.darr = new int[intsize];
    }

    int count = 0;
    for(int i = 0; i < intsize; i++){
      for(int j = 0; j < sett.intsize; j++){
        if(darr[i] == sett.darr[j]){
          brandnew.add(sett.darr[j]);
          //brandnew.darr[count] = sett.darr[j];
          count++;
        }
      }
    }
    cout << "brandnew int size is " << brandnew.intsize << endl;
    brandnew.intsize = count;
    return(brandnew);
    //brandnew.darr[arraysize];
    //brandne
}

integerset integerset::operator/(integerset sett){
	integerset brandnew;
	for(int i = 0; i < intsize; i++){
		int counter = 0;
		for(int j = 0; j < sett.intsize; j++){
			if(darr[i] != sett.darr[j]){
				counter++;
			}
			if(counter == sett.intsize){
				brandnew.add(darr[i]);
			}
		}
	}
	for(int i = 0; i < sett.intsize; i++){
		int counter = 0;
		for(int j = 0; j < intsize; j++){
			if(sett.darr[i] != darr[j]){
				counter++;
			}

			if(counter == intsize){
				brandnew.add(sett.darr[i]);
			}
		}
	}
	return brandnew;
}

