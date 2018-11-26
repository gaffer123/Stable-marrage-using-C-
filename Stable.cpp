#include <iostream>
using namespace std;

bool ok(int q[], int col){
  int mp[3][3] = { {0,2,1}, // Man#0's preferences
                   {0,2,1}, // Man#1's preferences
                   {1,2,0}}; // Man#2's preferences

  int wp[3][3] = { {2,1,0}, // Woman#0's preferences
                   {0,1,2}, // Woman#1's preferences
                   {2,0,1}}; // Woman#2's preferences

  int nm = col, nw = q[col]; //new man / Woman

  for (int i = 0; i < col; ++i) {
         int cm = i, cw = q[i];     //current woman/man
   //if statements check if the pair work
         if(cw == nw) return false;
         if((mp[cm][nw] < mp[cm][cw]) && (wp[nw][cm] < wp[nw][nm])) return false;
         if((mp[nm][cw] < mp[nm][nw]) && (wp[cw][nm] < wp[cw][cm])) return false;
       }
       return true;

}


  void backtrack(int &col){
    col--;
    if(col == -1){
      system("PAUSE");
      exit(1);
    }
  }

void print(int q[]){
  int count = 0;
  cout << ++count << endl;
  for(int i = 0; i < 3; i++){
    cout << q[i]<< " ";
    cout << endl;
  }
}


int main(){
  int c = 1, n = 3;
  int q[n];
  q[0] = 0;

  bool from_backtrack = false;

  while(true){
    while(c < n){
      if(!from_backtrack)q[c] = -1;
      from_backtrack = true;
      while(q[c]<n){
               q[c]++;

               if(q[c]==n){
                   from_backtrack=true;
                   backtrack(c);
                   break;
               }

               if(ok(q,c)){
                   from_backtrack=false;
                   c++;
                   break;
               }

           }

       }
       print(q);
       from_backtrack=true;
       backtrack(c);
   }


}
