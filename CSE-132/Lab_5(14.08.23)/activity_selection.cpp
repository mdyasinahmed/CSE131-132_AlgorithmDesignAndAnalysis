#include <bits/stdc++.h>
using namespace std;


struct Activity{
    int start, finish;
};

bool finishTime(Activity a, Activity b){
    return (a.finish<b.finish);
}

void ac(Activity arr[], int size){
    sort(arr, arr + size, finishTime);
    int i=0;
    cout<<i<<" ";
    for(int j=1; j<size; j++){
        if(arr[j].start >= arr[i].finish){
            cout<<j<<" ";
            i = j;
        }
    }
}

int main()
{
    //Activity arr[] = {{1,2}, {2,3}, {4,5}, {5,6}, {6,7}};
    Activity arr[] = {{1,2}, {3,4}, {5,6}, {3,9}, {6,7}};

    ac(arr, 5);

}
