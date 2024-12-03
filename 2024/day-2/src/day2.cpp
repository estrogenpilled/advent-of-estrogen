#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//c++ problems
bool descending(int a, int b){
  return a > b;
}
int diffcheck(vector<int> &vec){
  for (int i = 0; i < vec.size() - 1; i++){
    int diff = abs(vec[i] - vec[i + 1]);
    if(diff > 3 || diff == 0){
      return i + 1; //it misses by 1 for some reason
    }
  }
  return -1; //some value that won't be an index
}

int checksort(vector<int> &vec){
  bool asc = false;
  bool desc = 0;
  for(int i = 0; i < vec.size() - 1; i++){
    if(vec[i] < vec[i + 1]){
      asc = true;
    }
    else{ // we guarantee no equal elements through diffcheck
      desc = true;
    }
    if(asc & desc) return i;
  }
  return -1;
}
bool checksafe(vector<int> &vec, int &diff_idx, int &sort_chk){
  diff_idx = diffcheck(vec);
  if(diff_idx != -1){
    return false;
  }
  sort_chk = checksort(vec);
  if(sort_chk != -1){
    return false;
  }
  return true;
}
void p2_loop_internals(std::string &report, vector<int> &report_int, int &safe_counter){
  int diff_idx, sort_chk;
  istringstream rep_stream(report);
  string token;
  while(getline(rep_stream, token, ' ')){
    int num = stoi(token);
    report_int.push_back(num);
  }
  if(checksafe(report_int, diff_idx, sort_chk)){
    safe_counter++;
  }
  else{
    int idx_erase = diff_idx;
    if(sort_chk != -1) idx_erase = sort_chk;
    report_int.erase(report_int.begin() + idx_erase);
    if(checksafe(report_int, diff_idx, sort_chk)){
      safe_counter++;
    }
  }
  report_int.clear();
}
int part_2(string &report, fstream &input){
  int safe_counter = 0;
  vector<int> report_int;
  while(getline(input, report)){
    p2_loop_internals(report, report_int, safe_counter);
  } 
  return safe_counter;
}


int part_1(string report, fstream &input){
  int safe_counter = 0;
  vector<int> report_int;
  while(getline(input, report)){
    int safe = 1;
    istringstream rep_stream(report);
    string token;
    while(getline(rep_stream, token, ' ')){
      int num = stoi(token);
      report_int.push_back(num);
    }
    for (int i = 0; i < report_int.size() - 1; i++){
      int diff = abs(report_int[i] - report_int[i + 1]);
      if(diff > 3 || diff == 0){
        safe = 0; 
      }
    }
    if (!is_sorted(report_int.cbegin(), report_int.cend())){
      if(!is_sorted(report_int.cbegin(), report_int.cend(), descending)){
        safe = 0;
      }
    }  
    if(safe){
      safe_counter++;
    }
    report_int.clear();
  }
  return safe_counter;
}
int main(int argc, char **argv){ 
  fstream input;
  if (argc != 2){
    cout << "Usage: " << argv[0] << '\n';
    return 1;
  }
  input.open(argv[1],  std::fstream::in | std::fstream::out);
  string report_str;
  if (input){
    cout <<"Part 1: " << part_1(report_str, input) << '\n';
    input.close();
  }
  input.open(argv[1],  std::fstream::in | std::fstream::out);
  if (input){
    cout << "Part 2: " << part_2(report_str, input) << '\n';
    input.close();
  }
  else{
    cerr << "failed to open file" << '\n';
    return 1;
  }
  input.close();
  return 0;
}

