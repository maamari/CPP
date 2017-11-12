#include <iostream>
#include <fstream>

using namespace std;

void sort(int *, int);
void recursiveSort(int *, int);
int binsearch(int, int *, int, int);

int main(int argc, char *argv[]){
  int target;
  if(argc < 2){
    cout << "Provide a filename of the data to be searched" << endl;
    return 1;
  }
  ifstream datfile(argv[1], ios::in);
  if( datfile.fail() ){
    cout << "Unable to open file: " << argv[1] << endl;
    return 1;
  }
  int count = 0;

  while(! datfile.fail()){
    int temp;
    datfile >> temp;
    if(!datfile.fail()){
      count++;
    }
  }

  datfile.clear();

  datfile.seekg(0,ios::beg);

  int *data = new int[count];
  for(int i=0; i < count; i++){
    datfile >> data[i];
  }

  datfile.close();

  cout << "Read " << count << " integers from the data file.\n" << endl;
  cout << "Enter the target positive integer to search for: ";
  cin >> target;

  //sort(data, count);
  recursiveSort(data, count);

  int retval = binsearch(target,data,0,count);

  if(retval == -1){
    cout << target << " does not appear in the data." << endl;
  }
  else {
    cout << target << " appears at index " << retval << " in the data." << endl;
  }

  delete [] data;
  return 0;
}


int binsearch(int target, int *data, int start, int end)
{

  int mid = (start+end)/2;

  
  if(start >= end){
    return -1;
  }
  if(target == *(data+mid)){
    return mid;
  }
  else if(target < *(data+mid)){
    return binsearch(target, data, start, mid);

  }
  else{
    return binsearch(target, data, mid+1, end);
  }
  
}

void sort(int *data, int len)
{

  for (int i = 0; i < len; i++){
    int min = i;
    {

      for (int k = (i + 1); k < len; k++){
        if (data[k] < data[min])
          min = k;
      }

      int temp = data[i];
      data[i] = data[min];
      data[min] = temp;
    }
  }
}

void recursiveSort(int *data, int len)
{
  int min = 0;

  if(len == 1){
    return -1;
  }  

  for (int i = 0; i < len; i++){
    if (*(data+min) < *(data+i)){ 
      min = i;
    }
  }

  int temp = *(data+(len-1));
  *(data+(len-1)) = *(data+min);
  *(data+min) = temp;

  if(len > 1){
    recursiveSort(data, --len);
  }
}
