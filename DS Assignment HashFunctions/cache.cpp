//include any header files as required
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp>
#include <time.h>

#include "linearProbing.cpp"

using namespace std;

int main () {

  clock_t tStart = clock();

  string line;
////////////////////////////////////////////////////
  ifstream dictionary ("dictionary.txt");
  vector <string> dict_list;
  vector<string> dict_list_numbers;
  vector<string> dict_list_values;

  while (getline(dictionary,line))
  {
  	dict_list.push_back(line);
  }
  for(int i=0; i<dict_list.size(); i++)
  {
  	vector <string> temp;
  	boost::split(temp, dict_list[i], boost::is_any_of(" "));

  	dict_list_numbers.push_back(temp[0]);
  	dict_list_values.push_back(temp[1]);
  }

  // for(int i=0; i<dict_list.size(); i++)
  // {
  // 	cout <<dict_list_numbers[i]<< dict_list_numbers[i+1] << endl;
  // 	cout <<dict_list_values[i]<<dict_list_values[i+1]<< endl;
  // 	break;
  // }
////////////////////////////////////////////////////

  ifstream secrets ("secret1.txt");
  getline(secrets,line);
  vector <string> secret_list;
  boost::split(secret_list, line, boost::is_any_of(", "));

  // for(int i=0; i<secret_list.size(); i+=2)
  // {
  // 		cout << secret_list[i]<< endl;
  // }
////////////////////////////////////////////////////

  for(int i=0; i<secret_list.size(); i+=2)
  {
  	cout<< dict_list_values[stoi(secret_list[i])]<< " ";
  }


  cout << endl;
  cout << endl;
  printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


















  return 0;
}