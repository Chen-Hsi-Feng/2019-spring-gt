/* 
    Your main program goes here
*/
#include <iostream>
#include <string.h>
#include "network_manager.h"
#include "gplot.h"
#include "path.h"

using namespace std;

// create NetworkManager first
NetworkManager *nm = new NetworkManager();

// C++ program to find the shortest path 
// with minimum edges in a graph 
#define INFINITY 9999 
#define n 10 
//#define s 1 
//#define d 4 
#define NILL -1 
int MinDistance(int*, int*); 
void PrintPath(int*, int, int*, int); 

// Function to find the shortest path 
// with minimum edges in a graph 
void Dijkstra(int Graph[n][n], int _n, int _s, int _d, int path[]) 
{ 
	int c = -1;
	int i, u, v, count; 
	int dist[n]; 
	int Blackened[n] = { 0 }; 
	int pathlength[n] = { 0 }; 
	int parent[n]; 

	// The parent Of the source vertex is always equal to nill 
	parent[_s] = NILL; 

	// first, we initialize all distances to infinity. 
	for (i = 0; i < n; i++) 
		dist[i] = INFINITY; 

	dist[_s] = 0; 
	for (count = 0; count < n - 1; count++) { 
		u = MinDistance(dist, Blackened); 

		// if MinDistance() returns INFINITY, then the graph is not 
		// connected and we have traversed all of the vertices in the 
		// connected component of the source vertex, so it can reduce 
		// the time complexity sometimes 
		// In a directed graph, it means that the source vertex 
		// is not a root 
		if (u == INFINITY) 
			break; 
		else { 

			// Mark the vertex as Blackened 
			Blackened[u] = 1; 
			for (v = 0; v < n; v++) { 
				if (!Blackened[v] && Graph[u][v] 
					&& dist[u] + Graph[u][v] < dist[v]) { 
					parent[v] = u; 
					pathlength[v] = pathlength[parent[v]] + 1; 
					dist[v] = dist[u] + Graph[u][v]; 
				} 
				else if (!Blackened[v] && Graph[u][v] 
						&& dist[u] + Graph[u][v] == dist[v] 
						&& pathlength[u] + 1 < pathlength[v]) { 
					parent[v] = u; 
					pathlength[v] = pathlength[u] + 1; 
				} 
			} 
		} 
	} 

	// Printing the path 
	if (dist[_d] != INFINITY) 
		PrintPath(parent, _d, path, c); 
	else
		cout << "There is no path between vertex "
			<< _s << "to vertex " << _d; 
			
			
			
	//cout << " Dij's c :" << c;		
			
} 

int MinDistance(int* dist, int* Blackened) 
{ 
	int min = INFINITY, min_index, v; 
	for (v = 0; v < n; v++) 
		if (!Blackened[v] && dist[v] < min) { 
			min = dist[v]; 
			min_index = v; 
		} 
	return min == INFINITY ? INFINITY : min_index; 
} 

// Function to print the path 
void PrintPath(int* parent, int _d, int path[], int c) 
{ 
	if (parent[_d] == NILL) { 
		cout << _d; 
		return; 
	} 
	c++;
	PrintPath(parent, parent[_d], path, c); 
	
	cout << "->" << _d; 
	//cout << endl;
	path[c] = _d;
	//cout << "before : " ;
	//cout << c << " " << path[c] << " ";
	
	//c++;
	//length++;
	//cout << "after : " ;
	//cout << c << " " << path[c] << " ";
} 

// Driver code 
/*
int main() 
{ 
	int path[n] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
	int length_true = 0;
	// INFINITY means that u and v are not neighbors. 
	int Graph[n][n] =   {{ 0, 1, 1, 0, 0 , 0, 0, 0, 0, 0},
						{ 1, 0, 1, 0, 1 , 0, 0, 0, 0, 0},
						{ 1, 1, 0, 1, 1 , 0, 0, 0, 0, 0},
						{ 0, 0, 1, 0, 1 , 0, 0, 0, 0, 0},
						{ 0, 1, 1, 1, 0 , 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	Dijkstra(Graph, n, s, d, path); 
	
	cout << endl;
	cout << "path : ";
	
	for (int i = 0; i < n; i++)
	{
		
		
		if (path[i] != 99)
		length_true++;
				
}
	
	
	path[length_true] = s;
	
	for (int i = 0; i < n; i++)
	{
		cout << path[i] << " ";
				
}
	cout << "length : " << length_true;
	
	return 0; 
} 
*/


int main(int argc, char** argv){

    /* start your program */
    nm->interpret("./topo.txt");
//    nm->print_all_e();
//    nm->print_all_v();
    Vertex *list =  nm->get_all_nodes();
    Edge *edge = nm->elist;

int size = 0;
string names[10];

    while(list!=NULL){
        //std::cout << list->name << std::endl;

	names[size] = list->name;
        cout << "name : " << size << " = " << names[size] << endl;
	//cout << "name_size : " << size << " = " << names[size].size() << endl;
	list=list->next;
	size++;

}
	cout << "size : "<< size << endl;

int array[size-1];

    for (int i = 0; i < size; i++)
    {
	array[i] = 0;
	//cout << "array[" << i << "]" << array[i] << endl;
}

    while(edge!=NULL){
        //std::cout << edge->head->name << std::endl;
        //std::cout << edge->tail->name << std::endl;
	
    for(int i = 0; i < size; i++)
    {
	if (names[i] == edge->head->name)
	array[i]++;
	else if (names[i] == edge->tail->name)
	array[i]++;
	//cout << "array[" << i << "]" << array[i] << endl;
}
        edge=edge->next;
}

int odd[size-1];
int odd_num = 0;

    for(int i = 0; i < size; i++)
    {
	odd[i] = 0;
}

    for(int i = 0; i < size; i++)
    {
	cout << "array[" << i << "] : " << array[i] << endl;
	
	if ((array[i]/2)%2 != 0)
	{
	odd[odd_num] = i;
	
	//cout << "odd[" << odd_num << "] : " << odd[odd_num] << endl;
	odd_num++;
}	
	//cout << "odd_shit[" << odd_num-1 << "] : " << odd[odd_num-1] << endl;
}

    for(int i = 0; i < odd_num; i++)
    {
	cout << "odd[" << i << "] : " << odd[i] << endl;

}

    int adj[10][10];

    for(int i = 0; i < 10; i++)    
    {
	for(int j = 0; j < 10; j++)
	{
	adj[i][j] = 0;
}
}
	

    cout << "adj matrix : " << endl;    // adj. matrix
    for(int i = 0; i < size; i++)    
    {
	for(int j = 0; j < size; j++)
	{
	adj[i][j] = 0;

	if (nm->connected(names[i], names[j]) == 0)
	adj[i][j]++;
	else
	adj[i][j] = 0;
	cout << adj[i][j] << " ";
}
	cout << endl;
}
	


    cout << "adj matrix : " << endl;    // adj. matrix
    for(int i = 0; i < 10; i++)    
    {
	for(int j = 0; j < 10; j++)
	{
	cout << adj[i][j] << " ";
}
	cout << endl;
}

	
	
    int path[n] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
	int length_true = 0;	

	
	int start = odd[0];
	int endline = odd[1]; 

	Dijkstra(adj, n, start, endline, path); 
	
	cout << endl;
	cout << "path : ";
	
	for (int i = 0; i < n; i++)
	{
		
		
		if (path[i] != 99)
		length_true++;
				
}
	
	
	path[length_true] = start;
	
	for (int i = 0; i < n; i++)
	{
		cout << path[i] << " ";
				
}
	cout << "length : " << length_true;
  


    for (int i =  0; i < length_true; i++)  // update adj matrix
    {
	for (int j = 0; j < length_true; j++)
	{
	adj[start][endline]++;
	adj[endline][start]++;
}	
}

cout << endl;

    cout << "adj matrix update : " << endl;    // adj. matrix
    for(int i = 0; i < 10; i++)    
    {
	for(int j = 0; j < 10; j++)
	{
	cout << adj[i][j] << " ";
}
	cout << endl;
}
	


	//-------------------------path--------------------------//

/*
	int path_num[size];
	int length[size][size];
	string paths[size][size][size];

	Path *path;
	path = new Path();
	path->append(nm->elist);

int odd_number = 0;
odd_number = odd_num;
int situation = 0;

	while ((odd_num-1) != 0)             
	{
	std::vector<std::vector<Edge *>> avail_paths = path->find_paths(std::string(names[odd[situation]]), std::string(names[odd[situation+1]]));
	path_num[situation] = 0;
	
	std::cout<< "======================================================" << std::endl;
    	std::cout << "Number of found paths: " << path->paths.size() << std::endl;
	path_num[situation] = path->paths.size();
	
   	 for(int i=0;i<path->paths.size();i++)
  	  {
	 length[0][i] = 0;
       	 for(int x=0;x<path->paths.at(i).size();x++)
        	{
            std::cout << path->paths.at(i).at(x)->head->name << "->" << path->paths.at(i).at(x)->tail->name << " ";
	    length[situation][i]++;
	    paths[situation][i][x] = path->paths.at(i).at(x)->head->name;
	    cout << "path : " << paths[situation][i][x] << endl;
        	}
		
		cout << "len : " << length[situation][i] << endl;
		cout << "i : " << i << endl;
       	 	std::cout << "\n";
 	   }
    	std::cout<< "======================================================" << std::endl;	
	odd_num--;
	situation++;
}

int smallest_index = 99;

    for (int i = 0; i < odd_number-1; i++)
    {
    	for (int j = 0; j < path_num[i]-1; j++)
	{
	if (length[i][j] < length[i][j+1])
	smallest_index = j;
	else
	smallest_index = j+1;
	
}
    cout << "smallest_index : " << smallest_index << endl;
}
*/
	//-------------------------path--------------------------//


    Gplot *gp = new Gplot();
    gp->gp_add(nm->elist);



    gp->gp_dump(true);
    gp->gp_export("plot");


    return 0;
}
