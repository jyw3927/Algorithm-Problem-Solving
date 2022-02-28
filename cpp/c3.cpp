#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
   int m;
   cin >> m;
   cin.ignore();

   int input;
   vector<int> bag_list;
   
   while(!cin.eof()){
      cin >> input;
      bag_list.push_back(input);
      cout << "pushed" << endl;
      cin.clear();
   }

//    while (1) {
//         cin >> input;

//         if (cin.eof()) {
//             cin.clear();
//             break;
//         }
//         bag_list.push_back(input);
//     }

   sort(bag_list.begin(),bag_list.end());

   for (int i = 0; i < bag_list.size(); i++) {
       cout << bag_list[i] << " ";
   }

   int result = 0;
   int light = 0, heavy = bag_list.size() - 1;

   while(light < heavy){
      if(bag_list[light] + bag_list[heavy] > m){
         result++;
         heavy--;
      }
      else{
         light++;
         heavy--;
         result++;
      }
   }
   if(light == heavy) result++;
//    cout << result << endl;
}