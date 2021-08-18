#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

struct Node{
    string name;
    int b_t;
    int a_t;
    int size;
    int time_quant;
    char status;
    Node(string n,int a, int b, int s, char c, int t=5)
    {
        name = n;
        a_t = a;
        b_t = b;
        size = s;
        status = c;
        time_quant = t;
    }
};

int main()
{
    queue <Node> run,ready,list;
    int n;
    int Mem_Size = 1000;
    cout<<"Enter number of programs: ";
    cin>>n;
    string name;
    int a,b,s;
    char c;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter arrival time: ";
        cin>>a;
        cout<<"Enter burst time: ";
        cin>>b;
        cout<<"Enter size of program(less than 1000(in MB)): ";
        cin>>s;
        cout<<"Enter status(P for preemptive, any other key otherwise): ";
        cin>>c;
        if(s<1000)
            list.push(Node(name,a,b,s,c));
        else
        {
            cout<<"\nSize entered was more than 1000!! Program ignored! Please enter again!"<<endl;
            i -= 1;
        }
    }

    int comp = 0,t = 0;
    
    while(comp!=n)
    {
        if(!run.empty())
        {
            queue <Node> run1,temp = run;
            while(!temp.empty())
            {
                if(temp.front().b_t == 0)              //If a program has completed its burst time
                {
                    cout<<"\nProgram "<<temp.front().name<<" completed succesfully!";
                    Mem_Size = Mem_Size + temp.front().size;
                    comp += 1;
                    if(run.empty())
                        break;
                }

                else if(comp == n)                                   //If all codes have been executed, then exit loop automatically
                    break;  

                else                                   //If a program hasn't completed its burst time
                {
                    run1.push(Node(temp.front().name,temp.front().a_t,temp.front().b_t,temp.front().size,temp.front().status,temp.front().time_quant));
                }
                temp.pop(); 
            }
                
            run = run1;
        }

        if(comp == n)                                   //After execution of all codes hopefully :)
        {
            cout<<"\nExecution of all "<<comp<<" programs completed succesfully!";
            break;
        }

        while(!list.empty() && list.front().a_t == t)
        {

            if((Mem_Size - list.front().size) >= 0 && list.front().status != 'P')   //In case the main memory has space available to execute programs
            {
                run.push(Node(list.front().name,list.front().a_t,list.front().b_t,list.front().size,list.front().status));
                cout<<"\nProgram "<<run.back().name<<" running!";
                list.pop();
                Mem_Size = Mem_Size - run.back().size;
            }

            else if((list.front().size > Mem_Size) && list.front().status != 'P')                                     //In case main memory limit is exhausted by ongoing program executions                          
            {
                ready.push(Node(list.front().name,list.front().a_t,list.front().b_t,list.front().size,list.front().status));
                list.pop();
                cout<<"\nProgram "<<ready.back().name<<" pushed to ready queue due to memory shortage!";
            }

            else if(list.front().status == 'P')
            {
                
                if((Mem_Size - list.front().size) >= 0)   //In case the main memory has space available to execute preempted program
                {
                    run.push(Node(list.front().name,list.front().a_t,list.front().b_t,list.front().size,list.front().status));
                    cout<<"\nPreempted program "<<run.back().name<<" running!";
                    list.pop();
                    Mem_Size = Mem_Size - run.back().size;
                }
                
                else                                //In case main memory does not have enough space to accomodate preempted program
                {
                    
                    int x = 0;
                    queue <Node> run1,temp = run;
                    while(!temp.empty())
                    {
                        if(Mem_Size + temp.front().size - list.front().size < 0 || x==1)
                            run1.push(Node(temp.front().name,temp.front().a_t,temp.front().b_t,temp.front().size,temp.front().status));
                        else
                        {
                            cout<<"\nProgram "<<temp.front().name<<" pushed to ready queue as a result of preemption!";
                            ready.push(Node(temp.front().name,temp.front().a_t,temp.front().b_t,temp.front().size,temp.front().status));
                            Mem_Size = Mem_Size + temp.front().size;
                            x = 1;
                        }
                        temp.pop();
                    }
                    run = run1;
                    run.push(Node(list.front().name,list.front().a_t,list.front().b_t,list.front().size,list.front().status));
                    list.pop();
                    Mem_Size = Mem_Size - run.back().size;
                    cout<<"\nProgram "<<run.back().name<<" executing as a result of preemption!";
                }
            }
        }

        if(!ready.empty() && (Mem_Size - ready.front().size >= 0))                //In case there is space in memory to execute a program from ready queue
        {
            run.push(Node(ready.front().name,ready.front().a_t,ready.front().b_t,ready.front().size,ready.front().status,ready.front().time_quant));
            cout<<"\nProgram "<<run.back().name<<" popped from ready queue and executing now!";
            ready.pop();
            Mem_Size = Mem_Size - run.back().size;
        }

        t+=1;                                                               //Incrementing time counter
        if(!run.empty())
        {
            queue <Node> run1;
            queue <Node> temp = run;                                 
            while(!temp.empty())
            {
                if(temp.front().b_t == 0)              //If a program has completed its burst time
                {
                    cout<<"\nProgram "<<temp.front().name<<" completed succesfully!";
                    Mem_Size = Mem_Size + temp.front().size;
                    temp.pop();
                    comp += 1;
                }

                else if(temp.front().b_t>0)
                {
                    --temp.front().time_quant;
                    --temp.front().b_t;                   //Decrementing time counter and time quantum counter of all executing programs
                

                    if(temp.front().time_quant == -1)                //In case a program exceeds its time quantum
                    {
                        cout<<"\nProgram "<<temp.front().name<<" pushed to ready queue as exceeded time quantum!";
                        temp.front().time_quant += 6;
                        Mem_Size = Mem_Size + temp.front().size;
                        ready.push(Node(temp.front().name,temp.front().a_t,temp.front().b_t,temp.front().size,temp.front().status));
                    }
                    else                              
                    {
                        run1.push(Node(temp.front().name,temp.front().a_t,temp.front().b_t,temp.front().size,temp.front().status,temp.front().time_quant));
                    }
                    temp.pop();
                }
            run = run1;
            }
        }
    }
    
    return 0;
}






