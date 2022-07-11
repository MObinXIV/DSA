//Recursion Solution
#include<bits/stdc++.h>

using namespace std;
//Generate all sequences
void solve(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        solve(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string for n
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    //generete all seqeunces
    solve(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }


  //Mathematical approach

  string getPermutation(int n, int k) 
  {
      int fact=1;
      vector<int>num;//our vector for permutaion
      for (int i = 1 ; i<n ; i++)
      {
          fact*=i;//generate the divisble num 
          num.push_back(i);//push nums
      }
      num.push_back(n);
      string ans="";
      k=k-1;//0-ind
      while(true)
      {
          ans = ans +to_string(num[k/fact]);//the num from crosppending permutation which we dividi them 
          num.erase(num.begin()+k/fact);//erase the number for the purpose of new division
          if(num.size()==0)break;
          k=k%fact;//calculate the new K value
          fact/=num.size();//calc new fact val
      }
      return ans;
  }