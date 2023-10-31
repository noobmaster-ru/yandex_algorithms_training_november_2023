#include <stdio.h>


int minimum(int left, int right,int *pa){
    int k,min;
    min = *(pa+left);
    for (k = left+1; k<=right; k++){
        if (*(pa + k) < min) {
            min = *(pa+k);
        }
    }
    return min;
}

int main(){
    int n,m,i;
    scanf("%d %d",&n,&m);
    int array[n];

    for (i=0; i<n; i++){
        scanf("%d",&array[i]);
        //printf("%d\n",array[i]);
    }


    for (i = 0; i<m; i++){
        int l,r;
        scanf("%d %d",&l,&r);
        int j, mini, ans, flag=0;
        int *pa;
        pa = &array[0];

        mini = minimum(l,r,pa);
        //printf("%d\n",mini);
        for (j = l; j <= r; j++){
            if ((mini != *(pa+j)) && (r < n)){
                ans = *(pa +j);
                flag = 1;
            }
        }
        if (flag == 1){
            printf("%d\n",ans);
        }
        else{
            printf("NOT FOUND\n");
        }
    }
    return 0;
}