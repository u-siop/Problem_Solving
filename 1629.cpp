#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    int val;
    cin >> a >> b>> c;

    vector<int> mod;
    mod.push_back(a%c);
    val = a%c;
    while(1){
        val = (val*val)%c;
        if(find(mod.begin(), mod.end(), val) != mod.end()){
            break;
        }
        mod.push_back(val);
    }


    if( b == 0){
        cout << 1 << endl;
    }
    else{
        cout << mod[b%mod.size()] << endl;
    }
    return 0;
}

// #include <stdio.h>
// long long int A, B, C;
// int main()
// {
// 	scanf("%lld %lld %lld", &A, &B, &C);
// 	long long int ans = 1;
// 	while (B > 0)
// 	{
// 		if (B % 2 == 1) ans =(ans*A)%C;
// 		A = (A*A) % C;
// 		B /= 2;
// 	}
// 	printf("%lld\n",ans);
// }