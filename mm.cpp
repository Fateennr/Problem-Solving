#include <iostream>
using namespace std;
#define sz 20005

class SegmentTree{
private:
    // enum SZ{size=20100};
    int segment[3*sz];
    const int MAX= 1e9+7;

public:
    void init(int input[], int node, int begin, int end)
    {
        if(begin>end) return;

        if(begin==end)
        {
            segment[node]=input[begin];
            return;
        }
        else{
            int left, right, mid;
            
            left=node*2;
            right=(node*2)+1;
            mid=(begin+end)/2;

            init(input, left, begin, mid);
            init(input, right, mid + 1, end);

            segment[node]=min(segment[left],segment[right]);
        }
    }
    
    
    int Query(int node, int begin, int end, int query_start, int query_end){

        // no overlap
        if(begin>query_end or end<query_start)
            return MAX;

        // complete overlap
        else if(begin>=query_start and end<=query_end){
            return segment[node];
        }

        // partial overlap
        else{
            int left, right, mid;
            
            left=node*2;
            right=(node*2)+1;
            mid=(begin+end)/2;

            return min(Query(left, begin, mid, query_start, query_end) , Query(right, mid+1, end, query_start, query_end));
        }
    }

    void update(int node, int begin, int end, int i, int update_By){ //increment By
        
        // no overlap
        if(begin>i or end<i)
            return;

        // complete overlap
        else if(begin==i and end==i){
            segment[node]=update_By;
            return;
        }

        // partial overlap
        else{
            int left, right, mid;
            
            left=node*2;
            right=(node*2)+1;
            mid=(begin+end)/2;

            update(left, begin, mid, i, update_By);
            update(right, mid+1, end, i, update_By);

            segment[node]=min(segment[left], segment[right]);
        }
    }

};


int main()
{
    int inputs, queries, val, op, start, end;
    int array[sz];

    cin>>inputs>>queries;

    for(int i=1; i<=inputs; i++){ // 1 based indexing fixing
        cin>>val;
        array[i]=val;
    }

    SegmentTree stree;
    stree.init(array, 1, 1, inputs);

    while(queries--){
        cin>>op;
        
        if(op==1) {
            cin>>start>>val;
            stree.update(1, 1, inputs, start, val);
        }
        else if(op==2){
            cin>>start>>end;
            cout<<stree.Query(1, 1, inputs, start, end)<<endl;
        }
        
        // stree.printSegment(2*inputs);
    }
}