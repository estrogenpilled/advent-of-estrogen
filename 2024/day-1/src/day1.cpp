//prepare to gauge your eyeballs

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std; //scary

//avoid calling vector.size() on every single loop
int part_two(vector<int> &left_list, vector<int> &right_list, int left_size, int right_size){
  int sum = 0;
    for(int i = 0; i < left_size; i++){
      int occurences = 0;
      for(int j = 0; j < right_size; j++){
          if (left_list[i] == right_list[j]){
            occurences++;
          }
      }
      sum += left_list[i] * occurences;
    }
    return sum;
}

int main(){
    vector<int> left;
    vector<int> right;
    int sum = 0;
    int nums = 0;
    int left_num;
    int right_num;
    while(cin >> left_num && cin >> right_num){
        left.push_back(left_num);
        right.push_back(right_num);
    };
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    //I'm making the assumption that left and right are the same length 
    for(int i = 0; i <= left.size(); i++ ){
        sum += abs(left[i] - right[i]);
    }
    cout << "Sum of distances(part 1): " << sum << '\n'; 
    cout << "Similarity score(part 2): " << part_two(left, right, left.size(), right.size()) << '\n';
    return 0;
}
