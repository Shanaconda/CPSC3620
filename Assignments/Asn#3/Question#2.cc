//
//  main.cpp
//  CPSC3620As#3
//
//  Created by Shannon Abeda on 2020-02-16.
//  Copyright © 2020 Shannon Abeda. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>

void reverseQueue(std::queue<int>&, int);

int main(int argc, const char * argv[]) {
    
    std::queue<int> q;
    int n, n1, k;

    std::cout<<"How many elements to want to insert into the queue: ";
    std::cin>>n;
    
    for(int i=0; i<n; i++)
    {
        std::cout<<"Enter element " <<i+1<<" : ";
        std::cin>>n1;
        q.push(n1);
    }
    
    
    std::cout<<"Between 1 and "<<n<<" element in the queue how many do you want to reverse: ";
    std::cin>>k;
        
    
    //User input for the n amount of elements to be reversed
    //std::cout<<"How many elements between do you want to reverse ";
   // std::cin>>k;
    
    
    std::cout<<"The "<<k<<" elements now in reverse are: ";
    std::cout<<std::endl;
    reverseQueue(q,k);

    return 0;
}

void reverseQueue(std::queue<int> &q, int k)
{
   
    //Declaration of a stack
    std::stack<int> s;
    
    //Removal of the n elements from queue
    for(int i=0; i<k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    //Enqueue elements
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    
    //Removal of the remaining elements in the queue and pushing them to the back of the queue
    for(int i=0; i<q.size()-k; i++)
    {
        q.push(q.front());
        q.pop();
    }
    
    //Printing reverse queue
    while(!q.empty())
    {
        std::cout<<q.front()<<std::endl;
        q.pop();
    }
}

