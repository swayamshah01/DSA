#include<bits/stdc++.h>

using namespace std;

int main() {
  set < int > s;
  for (int i = 1; i <= 10; i++) {  //Iterate through 10 and insert the value of i in the set
    s.insert(i);
  }

  cout << "Elements present in the set: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";  //If element is found print it
  }
  cout << endl;
  int n = 2;
  if (s.find(2) != s.end())
    cout << n << " is present in set" << endl;  //Print the element

  s.erase(s.begin());
  cout << "Elements after deleting the first element: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";
  }
  cout << endl;

  cout << "The size of the set is: " << s.size() << endl;  ///Return the size of the set

  if (s.empty() == false)
    cout << "The set is not empty " << endl;  //If set is not empty and elements are still present in it
  else
    cout << "The set is empty" << endl;  //If set is empty
  s.clear();
  cout << "Size of the set after clearing all the elements: " << s.size();
}