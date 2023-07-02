#include <iostream>
#define MAX 100
using namespace std;

int compare(const void* a, const void* b){
    const int* x = (int*) a;
    const int* y = (int*) b;

    if(*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

    return 0;
}

int main(){
    int count=0, sum=0, temp=0, goal=0;     // count == number of card, sum == sum of 3 cards
    int i,j,k=0;
    int card[MAX];

    cin>>count>>goal;

    for(int i=0;i<count;i++){
        cin>>card[i];
    }
    qsort(card,count,sizeof(int),compare);

    if(goal>=card[count-1]+card[count-2]+card[count-3]){
        sum = card[count-1] + card[count-2] + card[count-3];
        cout<<sum;
        return 0;
    }
    for(i=count-1; i>=0; i--){
        temp=card[i];
        if(temp>=goal){
            continue;
        }

        for(j=i-1; j>=0; j--){
            temp=card[i]+card[j];
            if(temp>=goal){
                continue;
            }

            for(k=j-1; k>=0; k--){
                temp=card[i]+card[j]+card[k];
                if(temp>goal){
                    continue;
                }
                else{
                    if(temp>=sum)
                        sum=temp;
                }
            }
        }
    }
    cout<<sum;

    return 0;
}