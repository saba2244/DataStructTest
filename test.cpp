#include <iostream>
#include <fstream>
using namespace std;
//Function initialization
int insertIntoSortedArray(int myArray[], int numEntries, int newVal);

int main(int argc,char const *argv[]){
    //Creates a stream object and opens it to read in text file of numbers
    ifstream inStream;
    inStream.open(argv[1]);
    //Checks if input stream opened correctly
    if(inStream.is_open()){
      string line;
      int num;
      int numEntries = 0;
      int sortedNums[100];
      //Puts numbers from file into array
      while(getline(inStream, line)){
        if(line == ""){
          inStream.close();
          return 0;
        }
        //Convert number in string form from file to int and assign to num
        num = stoi(line);
        numEntries = insertIntoSortedArray(sortedNums, numEntries, num);
        for(int i = 0; i < numEntries;i++){
          if(i == numEntries -1){
            cout << sortedNums[i];
          }
          else{
            cout << sortedNums[i] << ",";
          }

        }
        cout << endl;
      }
    }
    //If stream not opened, displays error message.
    //Commented for changes
    else{
      cout << "Failed to open the file." << endl;
    }
    inStream.close();
}
int insertIntoSortedArray(int myArray[], int numEntries, int newVal){
  if(numEntries == 0){
    myArray[0] = newVal;
  }
  else{
  for(int i = 0; i < numEntries;i++){
    if(myArray[i] > newVal){
      for(int j = numEntries; j > i;j--){
        myArray[j] = myArray[j-1];
      }
      myArray[i] = newVal;
      numEntries = numEntries + 1;
      return numEntries;
    }
  }
  myArray[numEntries] = newVal;
}
  numEntries = numEntries + 1;
  return numEntries;
}
