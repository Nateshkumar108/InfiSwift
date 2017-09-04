#include<iostream>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high, int index[])
{
    int pivot = arr[high];  
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            swap(&index[i], &index[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    swap(&index[i + 1], &index[high]);
    return (i + 1);
}
 
 void quickSort(int arr[], int low, int high, int index[])
{
    if (low < high)
    {
        int pi = partition(arr, low, high,index);
        quickSort(arr, low, pi - 1,index);
        quickSort(arr, pi + 1, high,index);
    }
}
 
 int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid =( l + r)/2;
        
		if (arr[mid] == x) 
			return mid;

 		if (arr[mid] > x) 
		 
		 return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
    return -1;
}
 
 void pushMinus1ToEnd(int arr[], int n)
{
    int count = 0;
 	for (int i = 0; i < n; i++)
        if (arr[i] != -1)
            arr[count++] = arr[i];
     while (count < n)
        arr[count++] = -1;
}
 
int main()
{
	int poolMoney[]={234,23,856,55,45,34,66,12,3,89,56,23,23,23,23,23,100,100,100};
	
	int length= sizeof(poolMoney)/sizeof(poolMoney[0]);
	int giftCard,i,j,k;
	int index[length];
	int sum=0;
	int prevIndex;
		
	for(i=0;i<length;i++){
		if(poolMoney[i]>100);
		{
			giftCard=poolMoney[i]/100;
			if(giftCard > 0)
			{
			cout<<"poolMoney["<<i<<"] will give "<<giftCard<< " gift cards"<<endl;
			poolMoney[i]=poolMoney[i]%100;
			}
		}
	}  

	for(i=0;i<length;i++){
		index[i]=i;
	}
	
	quickSort(poolMoney,0,length-1,index);
	
	j=0;	
	
	for(i=0;i<length;i++){
		int temp=100-poolMoney[i];
		if((temp==50) &&(temp==poolMoney[i+1])){
			cout<<"Gift Card will be Shared between poolMoney[ "<<i<<" ] and poolMoney[ "<<i+1<<" ]"<<endl;
			poolMoney[i]=-1;
			poolMoney[i+1]=-1;
			index[i]=-1;
			index[i+1]=-1;
		}
		else{
			int low=i+1;
			int high=length-1;
			int result=binarySearch(poolMoney,low,high,temp);
			if(result!=-1){
			cout<<"Gift Card will be Shared between poolMoney[ "<<index[i]<<" ] and poolMoney[ "<<index[result]<<" ]"<<endl;
			poolMoney[i]=-1;
			poolMoney[result]=-1;
			index[i]=-1;
			index[result]=-1;
						
		}	
		}
		
	}
	pushMinus1ToEnd(poolMoney,length);
	pushMinus1ToEnd(index,length);
	
	j=0;
	int temp[length];
	int pre;
	for(i=0;i<length;i++){
		if(sum >=0 && sum < 100){
			if(poolMoney[i]!=-1){
				sum = sum + poolMoney[i];
				temp[j]=i;
				j++;
			}
		}
		if((sum == 100 ) || (sum > 100)){
			cout<<"Gift Card will be shared between: ";
			for(k=0;k<j;k++){
				if(temp[k]!=-1){
					poolMoney[temp[k]]=-1;
					pre=index[temp[k]];
					cout<<"PoolMoney[ "<<index[temp[k]]<<" ] ";
					index[temp[k]]=-1;
					prevIndex=temp[k];
					temp[k]=-1;
				}
		 	}
		 	cout<<endl;
		 	if(sum == 100){
		 		sum=0;
		 		j=0;
			 } 
			 else
			if(sum > 100){
				poolMoney[prevIndex]= sum - 100;
				sum = 0;
				index[prevIndex]=pre;
				--i;
				j=0;	
			}	
		}
	}
	
	int output[length];
	
	for(i=0;i<length;i++){
		output[i]=0;
	}
	
	for(i=0;i<length;i++){
		if(index[i]>0)
			output[index[i]]=poolMoney[i];
	}
		for(i=0;i<length;i++){
		cout<<endl<<"poolmoney["<<i<<"]: "<<output[i]<<endl;
	}
	return 0;
}
