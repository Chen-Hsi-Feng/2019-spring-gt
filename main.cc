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
	cout << "array[" << i << "]" << array[i] << endl;
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



	//-------------------------path--------------------------//

	Path *path;
	path = new Path();
	path->append(nm->elist);
	std::vector<std::vector<Edge *>> avail_paths = path->find_paths(std::string("b"), std::string("e"));
	path->debug();


	//-------------------------path--------------------------//


    Gplot *gp = new Gplot();
    gp->gp_add(nm->elist);



    gp->gp_dump(true);
    gp->gp_export("plot");


    return 0;
}
