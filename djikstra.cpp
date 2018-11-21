#include<iostream>
#define V 9
using namespace std;
int minimum = 0;
void dijkstra(int graph[V][V],int src, int des){

    if(graph[src][des]>0){
        minimum = graph[src][des];
    }
    for(int i=0; i<V; i++){
        if((graph[src][i]>0)&&(graph[i][des]>0)){
            if(minimum==0){
                    minimum = (graph[src][i] + graph[i][des]);

            }
            else if(minimum>(graph[src][i]+graph[i][des]))
                minimum = (graph[src][i] + graph[i][des]);
        }
    }
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if((graph[src][i]>0)&&(graph[i][j]>0)&&(graph[j][des]>0)){
            cout<<endl;
            cout<<"i :"<<i<<endl;
            cout<<"j :"<<j<<endl;
            if(minimum==0)
                {minimum = (graph[src][i] + graph[i][j] + graph[j][des]);
                }
            else if(minimum>(graph[src][i]+graph[i][j]+graph[j][des])){
                minimum = (graph[src][i]+graph[i][j]+graph[j][des]);
            }
            }
        }
    }
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            for(int k=0; k<V; k++){
                    if((graph[src][i]>0)&&(graph[i][j]>0)&&(graph[j][k]>0)&&(graph[k][des]>0)){
                            cout<<endl;
                            cout<<"i :"<<i<<endl;
                            cout<<"j :"<<j<<endl;
                            cout<<"k :"<<k<<endl;


                            if(minimum==0)
                                minimum = (graph[src][i] + graph[i][j] + graph[j][k] + graph[k][des]);

                            else if(minimum>(graph[src][i]+graph[i][j]+graph[j][k])+graph[k][des]){
                                minimum = (graph[src][i]+graph[i][j]+graph[j][k]+graph[k][des]);
                            }
                    }

            }
        }
    }



}
int main()
{
/* Let us create the example graph discussed above */
int graph[V][V] = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
					{4, 0, 8, 0, 0, 0, 0, 11, 0},
					{0, 8, 0, 7, 0, 4, 0, 0, 2},
					{0, 0, 7, 0, 9, 14, 0, 0, 0},
					{0, 0, 0, 9, 0, 10, 0, 0, 0},
					{0, 0, 4, 14, 10, 0, 2, 0, 0},
					{0, 0, 0, 0, 0, 2, 0, 1, 6},
					{8, 11, 0, 0, 0, 0, 1, 0, 7},
					{0, 0, 2, 0, 0, 0, 6, 7, 0}
					};

    int src, des;
	cout<<"Enter the source: ";
	cin>>src;
	cout<<"Enter the destination: ";
	cin>>des;
	dijkstra(graph,src,des);

	if(src==des){
        cout<<"The minimum distance between them is: 0 ";

	}
	else if(minimum>0){
        cout<<"The minimum distance between them is: ";
        cout<<minimum;
	}

	else
        cout<<"No path between them exist.";

	return 0;
}