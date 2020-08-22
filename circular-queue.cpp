//
//  main.cpp
//  DSA
//
//  Created by Anurag Gupta on 16/08/20.
//  Copyright © 2020 Anurag Gupta. All rights reserved.
//

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class CircularQueue{
private:
    int length;
    int *arr;
    int front;
    int rear;
    int itemCount;
public:
    CircularQueue(int n){
        length=n;
        arr = new int[n];
        front = -1;
        rear = -1;
        for(int i=0;i<n;i++){
            arr[i]=0;
        }
        itemCount=0;
    }
    
    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull(){
        if((rear+1)%length==front){
            return true;
        }else{
            return false;
        }
    }
    
    void enqueue(int val){
        if(isFull()){
            cout<<"Queue overflow"<<endl;
            return;
        }else if(isEmpty()){
            rear=0;
            front=0;
        }else{
            rear=(rear+1)%length;
        }
        arr[rear]=val;
        itemCount++;
    }
    
    int dequeue(){
        int x;
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return 0;
        }else if(front==rear){
            x=arr[front];
            arr[front]=0;
            front=-1;
            rear=-1;
            itemCount--;
        }else{
            x=arr[front];
            arr[front]=0;
            front=(front+1)%length;
            itemCount--;
        }
        return x;
    }
    
    int count(){
        return itemCount;
    }
    
    void display(){
        for(int i=0;i<length;i++){
            cout<<arr[i]<<endl;
        }
    }
};

int main() {
    CircularQueue q1(5);
    int option,value;
    
     do {
       cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
       cout << "1. Enqueue()" << endl;
       cout << "2. Dequeue()" << endl;
       cout << "3. isEmpty()" << endl;
       cout << "4. isFull()" << endl;
       cout << "5. count()" << endl;
       cout << "6. display()" << endl;
    
       cin >> option;
       switch (option) {
       case 0:
         break;
       case 1:
        cout << "Enter Number: ";
        cin >> value;
        q1.enqueue(value);
        break;
       case 2:
        cout << "Dequeued Number: "<<q1.dequeue()<<endl;
        break;
       case 3:
         if (q1.isEmpty())
           cout << "Queue is Empty" << endl;
         else
           cout << "Queue is not Empty" << endl;
         break;
       case 4:
         if (q1.isFull())
           cout << "Queue is Full" << endl;
         else
           cout << "Queue is not Full" << endl;
         break;
       case 5:
         cout << "Number of Items in the Queue are: " << q1.count() << endl;
         break;
       case 6:
         cout << "Display Function Called - " << endl;
         q1.display();
         break;
       default:
         cout << "Enter Proper Option number " << endl;
       }
    
     } while (option != 0);
}
