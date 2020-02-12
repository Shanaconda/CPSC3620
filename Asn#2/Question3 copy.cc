#include<iostream>
#include<list>
#include<algorithm>

using namespace std;
list<int> intersection(list<int> L1, list<int> L2);

int main()
{
   list<int>L1;
   list<int>L2;

   L1.push_back(1);
   L1.push_back(2);
   L1.push_back(3);
   L1.push_back(4);
   L1.push_back(5);
   L1.push_back(6);


   L2.push_back(1);
   L2.push_back(2);
   L2.push_back(7);
   L2.push_back(9);
   L2.push_back(11);
   L2.push_back(6);

   
   list<int>L3 = intersection(L1, L2);

   cout<<"L1 is: ";
   list<int>::iterator itr, itr1, itr2;

   for(itr=L1.begin(); itr!=L1.end(); itr++)
   {
      cout<<*itr<<" ";
   }

   cout<<endl;

   cout<<"L2 is: ";

   for(itr1=L2.begin(); itr1!=L2.end(); itr1++)
   {
      cout<<*itr1<<" ";
   }

   cout<<endl;

   cout<<"The union between L1 & L2 is: ";

   for(itr2=L3.begin(); itr2!=L3.end(); itr2++)
   {
      cout<<*itr2<<" ";
   }

   cout<<endl;

   return 0;
}

list<int> intersection(list<int>L1, list<int>L2)
{
   list<int>L3;

   list<int>::iterator itr1, itr2;

   itr1=L1.begin();
   itr2=L2.begin();

   while(itr1!=L1.end() && itr2!= L2.end())
   {
      if(*itr1==*itr2)
      {
	 L3.push_back(*itr1);
	 itr1++;
	 itr2++;
      }

      else
      {
	 itr1++;
	 itr2++;
      }

   }


   return L3;
}
   
