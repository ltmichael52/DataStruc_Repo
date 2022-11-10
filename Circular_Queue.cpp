#include<iostream>
#define SIZE 5

using namespace std;

class Queue{
    private:
    int items[SIZE],front,rear;

    public:
    Queue(){
        front=-1;
        rear=-1;
    }

    //Check the queue is full or not
    bool isFull(){
        if(front==0 && rear== SIZE-1){
            return true;
        }
        if( front==rear+1){
            return true;
        }
        return false;
    }

    //check the queue is empty or not
    bool isEmpty(){
        if(front==-1){
            return true;
        }
        else{
            return false;
        }
    }

    //adding an element
    void enQueue(int element){
        if(isFull()){
            cout<<"Queue is full";
        }
        else{
            if(front==-1){
                front=0;
                rear=(rear+1)%SIZE;
                items[rear]=element;
                cout<<"\nInserted "<<element<<endl;
            }
        }
    }

    //Removing an element
    int deQueue(){
        int element;
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return (-1);
        }
        else{
            element= items[front];
            if(front==rear){
                front=-1;
                rear=-1;
            }
            else{
                front=(front+1)%SIZE;
            }
            return (element);
        }
    }

    void display(){
        //Function to display status of circular queue
        if(isEmpty()){
            cout<<"\nEmpty Queue"<<endl;
        }
        else{
            cout<<"Front -> " <<front;
            cout<<"\nItems ->";
            for (int i=front ; i!=rear;i=(i+1)%SIZE){
                cout<<items[i];
                cout<<items[i];
                cout<<"\nRear ->"<<rear;
            }
        }
    }
};

int main(){
    Queue q;

    q.deQueue(); //nothing to dequeue

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    q.enQueue(6);//queue can only contain 5 values

    q.display();

    int elem = q.deQueue();

    if (elem!=-1){
        cout<<"\nDeleted Element is "<<elem;
    }

    q.display();

    q.enQueue(7);
    q.display();

    q.enQueue(8);//fails

    return 0;
}