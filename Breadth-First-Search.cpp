#include <iostream.h>
#include <conio.h>
#include <timer.h>

/*--------------------------------
The nodes are numbered from 1 to last...don't enter from 0..always start from 1
--------------------------------*/

typedef enum bool {false = 0,true} boolean;

#define MAX 20

class Graph
{
     int edges[MAX][MAX],*visited,nodes,sides,*connect,x;
     void bfs(int);
   public:
     Graph()
     {
	 sides = nodes = 0;
	 x = -1;
     }
     void input();
     void traverse();
     boolean isConnected();
     void print();
};

void Graph :: input()
{
     while(1)
     {
	 cout << "\nGive the number of nodes : ";cin >> nodes;
	 if(nodes >= MAX) cout << "\nGive the nodes lesser than 20\n";
	 else break;
     }
     cout << "\nGive the number of edges : ";cin >> sides;
     visited = new int [nodes];connect = new int [nodes];

     for(int i = 0;i < nodes;i++) visited[i] = false;

     for(int e = 0;e < nodes;e++)
	 for(int j = 0;j < nodes;j++) edges[e][j] = false;

     cout << "\nNow give the edges one-by-one\n\n";
     while(sides--)
     {
	 int start,end;
	 cout << "From : ";cin >> start;
	 cout << "To : ";cin >> end;cout << "\n";
	 edges[start - 1][end - 1] = 1;edges[end - 1][start - 1] = 1;
     }
}

boolean Graph :: isConnected()
{
    //do it only after traverse
    for(int f = 0;f < nodes;f++) visited[f] = false;
    visited[0] = true;

    for(int i = 1;i < nodes;i++)
	   if(edges[0][i] && !visited[i])
	   {
	      visited[i] = true;
	      bfs(i);
	   }

    for(int w = 0;w < nodes;w++)
	if(!visited[w]) return false;

    return true;
}

void Graph :: traverse()
{
     for(int i = 0;i < nodes;i++)
	if(!visited[i])
	{
	   visited[i] = true;
	   connect[++x] = i + 1;
	   bfs(i);
	}
}

void Graph :: bfs(int source)
{
     for(int i = 0;i < nodes;i++)
	if(edges[source][i] && !visited[i])
	{
	   visited[i] = true;
	   connect[++x] = i + 1;
	}
}

void Graph :: print()
{
    cout << "\n[ " << connect[0];
    for(int i = 1;i < nodes;i++) cout << " , " << connect[i];
    cout << " ]\n";
    x = -1;
}

int main()
{
    Graph G;
    Timer t;
    clrscr();

    G.input();t.reset();
    t.start();G.traverse();t.stop();
    if(G.isConnected() == false) cout << "\nThe graph is DIS-connected\n";
    else cout << "\nThe graph is connected\n";
    G.print();
    cout << "\nTime taken for this operation is : "<< t.time() << " seconds\n";
    getch();
    return 0;
}