#include <bits/stdc++.h>
using namespace std;

int main()
{
  string init = "";
  cout << "Enter a string" << endl;
  cin >> init;
  map<char, int> count;
  queue<int> q;
  string ans = "";
  for (int i = 0; i < init.length(); i++)
  {
    char ch = init[i];
    //  increase count
    count[ch]++;

    // push the character in queue
    q.push(ch);

    while(!q.empty()){
      if(count[q.front()]>1){
        // repeating character

        q.pop();
      }
      else{
        // non repeating character
        ans.push_back(q.front());
        break;
      }
    }
    if(q.empty()){
      ans.push_back('#');
    }
  }
cout<<ans;

  return 0;
}