 #include<iostream>

using namespace std;
 
int main()
{	
	//Money Contributed by colleagues
	int poolMoney[]={25,70,130,100};  
	
	int giftCard,i;
	
	//Length of the Array
	int length= sizeof(poolMoney)/sizeof(poolMoney[0]);
	
	//Loop to check if the Pool Money is more than 100 then give them (poolMoney/100) GiftCards
	for(int i=0;i<length;i++)
	{
		if(poolMoney[i]>100);
		{
			giftCard=poolMoney[i]/100;
			if(giftCard > 0)
			{
			cout<<"poolMoney["<<i<<"] will get "<<giftCard<< " gift cards"<<endl;
			poolMoney[i]=poolMoney[i]%100;
			}
		}
	}
	
	//Create a hashmap to store the poolmoney as index and their index as value
	int hashmap[]={0};
	
	for(i=0;i<length;i++)
	{
		hashmap[poolMoney[i]]=i;
	}
	
	
	//Now Check whether their are 2 colleagues whose combined poolMoney is exact 100.
	for(i=0;i<length;i++)
	{
		if(hashmap[100-poolMoney[i]])
		{
			cout<<"poolMoney[ "<<i<<" ] and poolMoney[ "<<hashmap[100-poolMoney[i]]<<" ] will shared a gift card"<<endl;
			poolMoney[i]=0;
			poolMoney[hashmap[100-poolMoney[i]]]=0;
		}
	}
	i=0;
	int sum=0;
	int CountingSum[]={0};
	//check whether there are 2 or more colleagues whose combined sum is greater than 100. 
	while(i < length)
	{
		if(sum < 100)
		{
			if(poolMoney[i] != 0)
			{
				sum = sum + poolMoney[i];
				//Store the values in hashmap so that if the total is not 100, then we can easily pay them in cash
				CountingSum[poolMoney[i]] = i; 
				if( sum == 100){
					poolMoney[i] = 0;
					CountingSum[]={0};
				}

				//Now if the sum is greater than 100 then change the poolMoney[i] value
				elseif( sum>100){
					poolMoney[i] = sum - 100;
					//assign the poolMoney[i] to sum 
					sum = 	poolMoney[i]; 
					CountingSum[]={0};
					CountingSum[poolMoney[i]]=i;
					
				}
				else{
					poolMoney[i] = 0;
				}
				
			}
			
			i++;
		}
	}
	
	cout<<"Cash will be given to the following";
	for(int k=0;k<CountingSum.length();k++)
	{
		cout<<poolMoney[CountingSum[poolmoney[k]]];;
	}
	return 0;
 } 
