   #include<bits/stdc++.h>
   
   
   using namespace std;

   int main()
   { 
    
    vector<int> v;

    v.push_back(3);

    v.push_back(1);
    v.push_back(2);
   

    do {

        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;

    }while( next_permutation( v.begin(), v.end() ) );

   }