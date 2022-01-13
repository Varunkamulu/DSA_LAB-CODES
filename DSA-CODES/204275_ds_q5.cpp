#include<iostream>
using namespace std;

class queue
{
    int front,rear,a[6];
    public:
      queue()
      {
          front=-1,rear=5;
          for(int i=0; i<5; i++)
          {
              a[i]=0;
          }
      }
      bool isEmpty()
      {
          if(front==-1 && rear==5)
             return true;
          else
             return false;
      }
      bool isFull()
      {
          if((rear-1==front) || (front+1==rear))
             return true;
          else
             return false;
      }
      void enqueue_back(int n)
      {
          if(isFull())
          {
              cout<<"Stack is full.";
              return;
          }
          else
          {
              rear--;
              a[rear]=n;
          }
      }
      void enqueue_front(int n)
      {
          if(isFull())
          {
              cout<<"Stack is full.";
              return;
          }
          else
          {
              front++;
              a[front]=n;
          }
      }
      int dequeue_front()
      {
          int x;
          if(front==-1)
          {
              cout<<"Stack is empty. cant remove further elements from front";
              return 0;
          }
          else
          {
              x=a[front];
              a[front]=0;
              front--;
          }
          return x;
      }
      int dequeue_back()
      {
          int x;
          if(rear==5)
          {
              cout<<"Stack is empty.";
              return 0;
          }
          else
          {
              x=a[rear];
              a[rear]=0;
              rear++;
          }
          return x;
      }
    
      void display()
      {
          cout<<"Stack members:\n";
          for(int i=0;i<5;i++)
          {
              cout<<a[i]<<" ";
          }
      }
};

int main()
{
    queue s;
    int choice,value;
    cout<<"0.To exit 1.Full 2.Empty 3. front enqueue 4.back enqueue 5. front dequeue 6. back dequeue 7.display\n";

    do{
        
        cout<<"enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 0:
               break;
            case 1:
               if(s.isEmpty())
               {
                 cout<<"Stack is empty."<<endl;
                }
                else{
                     cout<<"Stack is not empty."<<endl;
                  }
                break;
            case 2:
                if(s.isFull()){
                 cout<<"Stack is full."<<endl;}
                else{
                  cout<<"Stack is not full."<<endl;}
                break;
                case 3:
            cout<<"Enter the value to push in stack: ";
            cin>>value;
            s.enqueue_front(value);
            cout<<endl;
            break;
            case 4:
            cout<<"Enter the value to push in stack: ";
            cin>>value;
            s.enqueue_back(value);
            cout<<endl;
            break; 
            case 5:
            cout<<"Pop value: "<<s.dequeue_front()<<endl;
            break; 
            case 6:
            cout<<"Pop value: "<<s.dequeue_back()<<endl;
            break;             
            case 7:
            cout<<"Display Stack members:"<<endl;
            s.display();
            cout<<endl;
            break;                     
        }
    } while(choice!=0);
}