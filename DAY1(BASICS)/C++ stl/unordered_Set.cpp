#include<bits/stdc++.h>
using namespace std;      // Allows direct use of standard library objects without prefixing std::

int main() {
  // Declare an unordered_map 'mp' with key and value both of type int
  unordered_map <int, int> mp;

  // Insert 5 key-value pairs into the unordered_map
  // Each key is i, and each value is i * 10
  for (int i = 1; i <= 5; i++) {
    mp.insert({ i , i * 10 });
  }

  // Display the elements present in the unordered_map
  cout << "Elements present in the map: " << endl;
  cout << "Key\tElement" << endl;

  // Iterate through the map and print each key-value pair
  // 'auto it' is an iterator pointing to each element
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << "\t" << it->second << endl;  // 'first' = key, 'second' = value
  }

  // Search for an element with key = 2
  int n = 2;
  if (mp.find(n) != mp.end())  // mp.find(n) returns an iterator to the key if found, else mp.end()
    cout << n << " is present in map" << endl;

  // Erase the first element in the map
  // Note: unordered_map does not maintain any order of elements
  mp.erase(mp.begin());

  // Display elements after deletion
  cout << "Elements after deleting the first element: " << endl;
  cout << "Key\tElement" << endl;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << "\t" << it->second << endl;
  }

  // Print the current size of the map
  cout << "The size of the map is: " << mp.size() << endl;

  // Check whether the map is empty or not
  if (!mp.empty())  // mp.empty() returns true if the map has no elements
    cout << "The map is not empty " << endl;
  else
    cout << "The map is empty" << endl;

  // Clear all elements from the map
  mp.clear();

  // Print size after clearing
  cout << "Size of the map after clearing all the elements: " << mp.size();
}

