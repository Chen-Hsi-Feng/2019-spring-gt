/* 
    Your main program goes here
*/
#include <iostream>
#include <string.h>
#include "network_manager.h"
#include "gplot.h"
#include "path.h"
#include <stdlib.h>
#include <queue>
#include <vector>

using namespace std;

// create NetworkManager first
NetworkManager *nm = new NetworkManager();

#define INFINITY 9999 
#define n 10 
//#define s 1 
//#define d 4 
#define minus_1 -1 
int Min_d(int*, int*); 
void Print_road(int*, int, int*, int); 
vector<string> outpath;
int ok;




void DFS (int s, int len, int visit[], int adj[][10], string names[], int size)
{
	ok = 0;
	visit[s] = visit[s] - 1 ;
	for(int i = 0; i < size; i++)
	{
		if (adj[s][i] != 0 && visit[i] != 0)
		{
			adj[s][i]--;
			adj[i][s]--;
			
			outpath.push_back(names[i]);
/*
			for (int k = 0; k < outpath.size(); k++)
			cout << outpath[k] << " " ;
			//fgetc(stdin);   //pause
			cout << endl;
*/
			len--;
			
			if (len > 0)
			{
				DFS(i, len, visit, adj, names, size);
				
			}
			else if (i == 0)
			{
				ok = 1;
				return;
			}
			
			if (ok == 1)  return;
			
			len++;
			visit[i]++;
			outpath.pop_back();
			adj[s][i]++;
			adj[i][s]++;
		}	
	}
}


int main(int argc, char** argv){

    /* start your program */
    nm->interpret("./topo_6points.txt");
//    nm->print_all_e();
//    nm->print_all_v();
    Vertex *list =  nm->get_all_nodes();
    Edge *edge = nm->elist;

int size = 0;
string names[10];
int names_vector[10];

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

int odd[size];

int odd_num = 0;

    for(int i = 0; i < size; i++)
    {
	odd[i] = 0;
	//record[i] = 1;
}

    for(int i = 0; i < size; i++)
    {
	cout << "array[" << i << "] : " << array[i] << endl;
	
	if ((array[i])%2 != 0)
	{
	odd[odd_num] = i;
	
	//cout << "odd[" << odd_num << "] : " << odd[odd_num] << endl;
	odd_num++;
}	
	//cout << "odd_shit[" << odd_num-1 << "] : " << odd[odd_num-1] << endl;
}

cout << "odd_num : " << odd_num<<endl;

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

	//----------------------add edges--------------------------//


int record[odd_num];
int record_points[odd_num];
	
    for (int i = 0; i < odd_num; i++)
    {
	
	record[i] = 1;
	record_points[i] = 1;
	cout << "record[ " << i << " ] : " << record[i] <<endl ;
}

int test = 0;
    if (odd_num == 0)
    test = 0;
    else if (odd_num == 2)
    test = 1;
    else if (odd_num == 4)
    test = 3;

int cnt = 0;
int length_true = 0;
//int path[10];
int start = 99;
int endline = 99;
int min_length_array[10] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int path[10] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99};

while (test != 0)
{
    for (int i = 0; i < 10; i++)
    path[i] = 99;

    length_true = 0;	
    int index_start = 0;
    int index_end   = 0;
    int start_done = 0;
    int end_done = 0;
    

    while (start_done == 0)
    {	
	
	if (record_points[index_start] == 1)
	{
	start = odd[index_start];
	start_done = 1;
}
	else
	index_start++;
}
	cout << "index_start : " << index_start << endl;
	
	cout << "start : " << start << endl;

	index_end = index_start + 1;

    while (end_done == 0)
    {	
	
	if (record_points[index_end] == 1)
	{
	endline = odd[index_end];
	end_done = 1;
}
	else
	index_end++;
}
	record[index_end] = 0;
	cout << "index_end : " << index_end << endl;
	cout << "endline : " << endline << endl;

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
	cout << "length : " << length_true << endl;

	min_length_array[cnt] = length_true;


	test--;
    
    //record_points[index_start] = 0;
    record_points[index_end] = 0;

    for (int i = 0; i < odd_num; i++)
    {
	
	cout << "record_points[ " << i << " ] : " << record_points[i] <<endl ;
}
	cnt++;
	cout << "cnt : " << cnt << endl;
}  // while end

	int min = 99;
        int min_index = 0;
	int start1 = 99;
	int endline1 = 99;
	int start2 = 99;
	int endline2 = 99;
	
	for (int i = 0; i < cnt; i++)
	{
	cout << "min_length_array[" << i << "] : " << min_length_array[i] <<endl;
	if (min_length_array[i] - min < min)
	{
	min = min_length_array[i];
	min_index = i;
}
}

	cout << "min : " << min << endl;
	cout << "min_index : " << min_index << endl;


	if (min_index == 0)	
	{
	start1 = odd[0];
	endline1 = odd[1];
	start2 = odd[2];
	endline2 = odd[3];
	//cout << "min_index : " << min_index << endl;	
}
	
	else if (min_index == 1)	
	{
	start1 = odd[0];
	endline1 = odd[2];
	start2 = odd[1];
	endline2 = odd[3];
	//cout << "min_index : " << min_index << endl;	
	//fgetc(stdin);   //pause

}	

	else if (min_index == 2)	
	{
	start1 = odd[0];
	endline1 = odd[3];	
	start2 = odd[1];
	endline2 = odd[2];
	//cout << "min_index : " << min_index << endl;
}	

	cout << "start1 : " << start1 <<endl;
	cout << "endline1 : " << endline1 <<endl;
	cout << "start2 : " << start2 <<endl;
	cout << "endline2 : " << endline2 <<endl;

//fgetc(stdin);   //pause

    if (odd_num == 4)
    {
	int times = 2;
	while (times != 0)
	{

    for (int i = 0; i < 10; i++)
    path[i] = 99;

    length_true = 0;


	if (times == 2)
	{
	start = start1;
	endline = endline1;
}

	else if (times == 1)
	{
	start = start2;
	endline = endline2;
}

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
	cout << "length : " << length_true << endl;


	for (int i =  0; i < length_true; i++)  // update adj matrix
    {
	adj[path[i]][path[i+1]]++;
	adj[path[i+1]][path[i]]++;
	
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
	times--;
}   // end while
}    // end if 


else if (odd_num == 2)
{
    for (int i =  0; i < length_true; i++)  // update adj matrix
    {
	adj[path[i]][path[i+1]]++;
	adj[path[i+1]][path[i]]++;
	
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
	
}

else if (odd_num == 6)
{
int times = 3;
	while (times != 0)
	{

    for (int i = 0; i < 10; i++)
    path[i] = 99;

    length_true = 0;

	if (times == 3)
	{
	start = odd[0];
	endline = odd[5];
}

	else if (times == 2)
	{
	start = odd[1];
	endline = odd[4];
}

	else if (times == 1)
	{
	start = odd[2];
	endline = odd[3];
}

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
	cout << "length : " << length_true << endl;


	for (int i =  0; i < length_true; i++)  // update adj matrix
    {
	adj[path[i]][path[i+1]]++;
	adj[path[i+1]][path[i]]++;
	
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
	times--;
}   // end while
}    // end if 

else if (odd_num == 8)
{
int times = 4;
	while (times != 0)
	{

    for (int i = 0; i < 10; i++)
    path[i] = 99;

    length_true = 0;

	if (times == 4)
	{
	start = odd[0];
	endline = odd[7];
}

	else if (times == 3)
	{
	start = odd[1];
	endline = odd[6];
}

	else if (times == 2)
	{
	start = odd[2];
	endline = odd[5];
}

	else if (times == 1)
	{
	start = odd[3];
	endline = odd[4];
}

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
	cout << "length : " << length_true << endl;


	for (int i =  0; i < length_true; i++)  // update adj matrix
    {
	adj[path[i]][path[i+1]]++;
	adj[path[i+1]][path[i]]++;
	
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
	times--;
}   // end while
}    // end if 

else if (odd_num == 10)
{
int times = 5;
	while (times != 0)
	{

    for (int i = 0; i < 10; i++)
    path[i] = 99;

    length_true = 0;

	if (times == 5)
	{
	start = odd[0];
	endline = odd[9];
}

	else if (times == 4)
	{
	start = odd[1];
	endline = odd[8];
}

	else if (times == 3)
	{
	start = odd[2];
	endline = odd[7];
}

	else if (times == 2)
	{
	start = odd[3];
	endline = odd[6];
}

	else if (times == 1)
	{
	start = odd[4];
	endline = odd[5];
}

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
	cout << "length : " << length_true << endl;


	for (int i =  0; i < length_true; i++)  // update adj matrix
    {
	adj[path[i]][path[i+1]]++;
	adj[path[i+1]][path[i]]++;
	
}

cout << endl;

int l = 0;

    cout << "adj matrix update : " << endl;    // adj. matrix
    for(int i = 0; i < 10; i++)    
    {
	for(int j = 0; j < 10; j++)
	{
	l = l + adj[i][j];
	

	cout << adj[i][j] << " ";
}
	cout << endl;
}
	times--;
}   // end while
}    // end if 

    int array_dfs[10];

for (int i = 0; i < size; i++)
    {
	array_dfs[i] = 0;
    for (int j = 0; j < size; j++)
    {
	
	array_dfs[i] = array_dfs[i] + adj[i][j];
	
}
	cout << array_dfs[i] <<endl;
}
//----------------------------------DFS-----------------------------//
	
int visit[10];
//vector<string> outpath;
int l = 0;
   

    for(int i=0;i<size;i++)
	{
	    names_vector[i]=0;
	    visit[i] = (array_dfs[i]/2);
	    names_vector[i]=i;
        //visited[i]=degree;
	cout << "visit[" << i << "] :" << visit[i] <<endl;
} 
    for(int i=0;i<size;i++)
	{
    		visit[0]++;
    		cout << "visit[" << i << "] :" << visit[i] <<endl;
}

    for(int i = 0; i < 10; i++)    
    {
	for(int j = 0; j < 10; j++)
	{
	l = l + adj[i][j];

}
}

int length_line = 0;
length_line = l/2;


    cout << "length_line : " << length_line << endl;


    DFS(0, length_line, visit, adj, names, /*outpath,*/ size);

stdout = fopen("RESULT.txt", "w");  // write file

	cout << "a" << " ";
	fprintf(stdout,"a");
	fprintf(stdout," ");

char result[100];

    for(int i = 0; i < outpath.size(); i++)
    {	
	//result[i] = outpath[i];
	//cout << result[i] << " ";
	cout << outpath[i] << " ";
	fprintf(stdout, outpath[i].c_str());
	fprintf(stdout," ");
	//fgetc(stdin);   //pause
}


/*    
    for(int k=0;k<n;k++)
   {
        cout << "visited[" << k << "] :" << visited[k] << endl;
	if (visited[k] == 1)
	cnt_dfs++;
	
}
*/
    cout <<endl;
    cout << "adj matrix DFS : " << endl;    // adj. matrix
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
