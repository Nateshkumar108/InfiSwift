#include<iostream>

using namespace std;
 
int main()
{
	int poolMoney[]={21,54,70,32,50,45};  
	
	int giftCard,i,j,k;
	
	int length= sizeof(poolMoney)/sizeof(poolMoney[0]);
	int index[length];
	int sum=0;
	int prevIndex;
	//Loop to check if the Pool Money is more than 100 then give them (poolMoney/100) GiftCards
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
	j=0;
	for(i=0;i<length;i++){
		if(sum >=0 && sum < 100){
			if(poolMoney[i]!=0){
				sum = sum + poolMoney[i];
				index[j]=i;
				j++;
			}
		}
		if((sum == 100 )|| (sum > 100)){
			cout<<"Gift Card will be shared between: ";
			for(k=0;k<j;k++){
				poolMoney[index[k]]=0;
				cout<<"PoolMoney[ "<<index[k]<<" ] ";
				prevIndex=index[k];
				index[k]=-1;
		 	}
		 	cout<<endl;
		 	if(sum == 100){
		 		sum=0;
		 		j=0;
			 } 
			if(sum > 100){
				poolMoney[prevIndex]= sum - 100;
				sum = poolMoney[prevIndex];
				index[0]=prevIndex;
				j=1;
			}
		}	
	}
	cout<<endl;
	for(i=0;i<length;i++){
		if(poolMoney[i]>0)
			cout<<"poolMoney[" <<i<<" ] will give: $"<<poolMoney[i]<<" to Alan"<<endl;
	}
	return 0;	
}
