#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;

struct packet {
    int data;
};

struct frame {
    packet pdata;
    int seq_num;
};

int reciever(frame f, int seq_num) {
    packet p;
    int d;
    int s;
    cout<<"\n Reciever's End";
    if(seq_num == 5) {
        cout<<"Frame Discarded!!";
    } else {
        p = f.pdata;
        s = f.seq_num;
        d = p.data;
        cout<<"\n Frame is recieved from physical layer of reciever";
        cout<<"info: "<<p.data<<"\t sequence number: "<<s<<endl;
        cout<<"\n Frame is now converted back to packet";
    }

    if(s==0) {
        s = 1;
    } else {
        s = 0;
    }
    cout<<"\n Acknoldgement Transmission";
    cout<<"\n Acknoldgement "<<f.pdata.data<<"is now converted to packet..";
    cout<<"\n Packet is now converted to Frame(ACK) ..\t sequence number: "<<s<<"\n";
    return s;
}

int sender(int data, int s, int cases) {
    //int var = -1;
    int check;
    packet pack;
    pack.data = data;
    cout<<"\n Sender End:";
    cout<<"\n Data "<<data<<"is now converted to packet..";
    frame f1;
    f1.pdata=pack;
    f1.seq_num = s;
    cout<<"Packet is now converted to frame with information "<< f1.pdata.data<<"and sequence number "<<f1.seq_num<<"\n";
    cout<<"Frame is sent to reciever...";
    if(cases==1 || cases == 2 || cases == 3) {
        cout<<"\n Acknoldgement doesn't recieved!!";
        return -1;
    } else if (cases ==5) {
        check = reciever(f1, 5);
        cout<<"\n Sender's End: ";
        if(check > 1) {
            cout<<"\n Acknoldgement is failed";
        } else if (check == 0) {
            cout<<"\n Acknoldgement is recieved by sender to send data frame with sequence number"<<check;
        } else {
            cout<<"\n Acknoldgement is recieved by sender to send data frame with sequence number"<<check;
        }
    } else {
        check = reciever(f1, 0);
        cout<<"\n Sender's End: ";
        if(check > 1) {
            cout<<"\n Acknoldgement is failed";
        } else if(check == 0) {
            cout<<"\n Acknoldgement is recieved by sender to send data frame with sequence number"<<check;
        } else {
            cout<<"\n Acknoldgement is reciever by sender to send data frame with sequence number"<<check;
        }
    }
    return 0;
}

int main() {
    int trigger;
    int data_size;

    cout<<"\n Enter the size of data: ";
    cin>>data_size;

    int data[data_size];
    cout<<"\n Enter data:";
    for(int i=0; i<data_size; i++) {
        cin>>data[i];
    }

    for(int i=0; i<data_size; i++) {
        int ch;
        srand(time(NULL));
        trigger = rand()%4;
        switch(trigger) {
            case 1: 
                cout<<"\n Case: "<<endl;
                cout<<"\n Frame gets Damaged";
                ch = sender(data[i], (i+1)%2, trigger);
                if(ch == -1) {
                    cout<<"\n Frame is sent again";
                    ch = sender(data[i], (i+1)%2, 0);
                }
                break;
            case 2:
                cout<<"\n Case: "<<endl;
                cout<<"\n Frame lost";
                ch = sender(data[i], (i+1)%2, trigger);
                if(ch == -1) {
                    cout<<"\n Frame is sent again";
                    ch = sender(data[i], (i+1)%2, 0);
                }
                break;
            case 3:
                cout<<"\n Case: "<<endl;
                cout<<"\n Acknoldgement is lost";
                ch = sender(data[i], (i+1)%2, trigger);
                if(ch==-1) {
                    cout<<"\n Frame is sent again";
                    ch = sender(data[i], (i+1)%2, 0);
                }
                break;
            default:
                cout<<"\n Case: "<<endl;
                cout<<"Normal Frame";
                ch = sender(data[i], (i+1)%2, 0);
                break;    
        }
    }
}