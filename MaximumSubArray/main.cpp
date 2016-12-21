
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <time.h>

class MaxSubArray{
public: int l;
public: int h;
public: int sum;
public: MaxSubArray() {
    l= INT_MIN;
    h= INT_MIN;
    sum=0;
}
public: MaxSubArray(int l,int h,int sum){
    this->l=l;
    this->h=h;
    this->sum=sum;
}
};

double count = 0;
MaxSubArray maxCrossingSum(int arr[], int l, int m, int h)
{
    // Include elements on left of mid.
    int leftSum = INT_MIN;
    count++;
    int rightSum = INT_MIN;
    count++;
    int sum = 0;
    count++;
    
    int leftIndex =-1;
    count++;
    int rightIndex =-1;
    count++;
    for(int i=m;i>=l;i--){
        count++;
        sum=sum+arr[i];
        if(sum>leftSum){
            leftSum=sum;
            count++;
            leftIndex=i;
            count++;
        }
    }
    sum=0;
    for(int i=m+1;i<=h;i++){
        count++;
        sum=sum+arr[i];
        if(sum>rightSum){
            rightSum=sum;
            count++;
            rightIndex=i;
            count++;
        }
    }
    return MaxSubArray(leftIndex,rightIndex,leftSum+rightSum);
}


MaxSubArray maxSubArraySum(int arr[], int l, int h)
{
    if (l == h){
        count++;
        return MaxSubArray(l,h,arr[l]);
    }
    
    int m = l +(h-l)/2;
    count++;
    MaxSubArray left = maxSubArraySum(arr, l, m);
    MaxSubArray right = maxSubArraySum(arr, m+1, h);
    MaxSubArray crossMax = maxCrossingSum(arr, l, m, h);
    
    if(left.sum >= right.sum && left.sum >= crossMax.sum)
        return left;
    else if(right.sum>=left.sum&&right.sum>=crossMax.sum)
        return right;
    else return crossMax;
}

int main()
{
    int arraySize[] = {4, 8, 15, 32, 64, 128};
    for (int i=0; i<6; i++) {
        int array[arraySize[i]];
        
        for(int j=0; j<arraySize[i]; j++){
            if (j % 2 == 0){
                array[j] = (rand()%100)+1;
            }
            else{
                array[j] = (rand()%100-99);
            }
        }
        std::cout<<"Divide and conquer starts "<<"\n";
        std::cout<<"Input array size: "<<arraySize[i]<<"\n";
        int n = sizeof(array)/sizeof(array[0]);
        clock_t t1 = clock();
        MaxSubArray result = maxSubArraySum(array, 0, n-1);
        clock_t t2 = clock();
        float diff = ((float)(t2 - t1) / 1000000.0F ) * 1000;
        std::cout<<"Sum result: "<<result.sum<<"\n";
        std::cout<<"Step counts: "<<count<<"\n";
        std::cout<<"left element of SubArray: "<<result.l<<"\n";
        std::cout<<"right element of SubArray: "<<result.h<<"\n";
        count = 0;
        std::cout<<"took time: "<<diff<<"\n";
        std::cout<<"Divide and conquer End "<<"\n\n";
    }
    return 0;
}
