#include <iostream>
using namespace std;

int main()
{
    int i,j,k,l;
     
    //Get Frame
    int frame_size;
    cout<<"\n Enter Frame size: ";
    cin>>frame_size;
     
    int frame[20];
     
    cout<<"\n Enter Frame:";
    for(i=0;i<frame_size;i++) {
        cin>>frame[i];
    }
 
    //Get Generator
    int gen_size;
    cout<<"\n Enter Generator size: ";
    cin>>gen_size;
     
    int gen[20];
     
    cout<<"\n Enter Generator:";
    for(i=0;i<gen_size;i++) {
        cin>>gen[i];
    }
 
    cout<<"\n Sender Side:";
    cout<<"\n Frame: ";
    for(i=0;i<frame_size;i++) {
        cout<<frame[i];
    }
    cout<<"\n Generator :";
    for(i=0;i<gen_size;i++) {
        cout<<gen[i];
    }
 
    //Append 0's
    int red_size=gen_size-1;
    cout<<"\n Number of 0's to be appended: "<<red_size;
    for (i=frame_size;i<frame_size+red_size;i++) {
        frame[i]=0;
    }
 
    int temp[20];
    for(i=0;i<20;i++) {
        temp[i]=frame[i];
    }
 
    cout<<"\n Message after appending 0's :";
    for(i=0; i<frame_size+red_size;i++) {
        cout<<temp[i];
    }
 
    //Division
    for(i=0;i<frame_size;i++) {
        j=0;
        k=i;
        //check whether it is divisible or not
        if (temp[k]>=gen[j]) {
            for(j=0,k=i;j<gen_size;j++,k++) {
                if((temp[k]==1 && gen[j]==1) || (temp[k]==0 && gen[j]==0)) {
                    temp[k]=0;
                } else {
                    temp[k]=1;
                }
            }
        }
    }
 
    //CRC
    int crc[15];
    for(i=0,j=frame_size;i<red_size;i++,j++) {
        crc[i]=temp[j];
    }
 
    cout<<"\n CRC bits: ";
    for(i=0;i<red_size;i++) {
        cout<<crc[i];
    }
 
    cout<<"\n Transmitted Frame: ";
    int trans_frame[15];
    for(i=0;i<frame_size;i++) {
        trans_frame[i]=frame[i];
    }
    for(i=frame_size,j=0;i<frame_size+red_size;i++,j++) {
        trans_frame[i]=crc[j];
    }
    for(i=0;i<frame_size+red_size;i++) {
        cout<<trans_frame[i];
    }
 
    cout<<"\n Receiver side : ";
    cout<<"\n Received Frame: ";
    for(i=0;i<frame_size+red_size;i++) {
        cout<<trans_frame[i];
    }
 
    for(i=0;i<frame_size+red_size;i++) {
        temp[i]=trans_frame[i];
    }
 
    //Division
    for(i=0;i<frame_size+red_size;i++) {
        j=0;
        k=i;
        if (temp[k]>=gen[j]) {
            for(j=0,k=i;j<gen_size;j++,k++) {
                if((temp[k]==1 && gen[j]==1) || (temp[k]==0 && gen[j]==0)) {
                    temp[k]=0;
                } else {
                    temp[k]=1;
                }
            }
        }
    }
 
    cout<<"\n Reaminder: ";
    int rrem[15];
    for (i=frame_size,j=0;i<frame_size+red_size;i++,j++) {
        rrem[j]= temp[i];
    }
    for(i=0;i<red_size;i++) {
        cout<<rrem[i];
    }
 
    int flag=0;
    for(i=0;i<red_size;i++) {
        if(rrem[i]!=0) {
            flag=1;
        }
    }
 
    if(flag==0) {
        cout<<"\n Since Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Correct";
    }
    else {
        cout<<"\n Since Remainder Is Not 0 Hence Message Transmitted From Sender To Receriver Contains Error";
    }
    cout<<"\n";
}