#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <map>
#include "network_manager.h"
#include "gplot.h"
#include "path.h"

using namespace std;

// create NetworkManager first
NetworkManager *nm = new NetworkManager();
map<string, vector<Edge *>> adv;
vector<Edge *> dfs_paths;
vector<Vertex *> existed_vertices;

void dfs(string src);

int main(int argc, char** argv){
    // build basic topo
    // sub1
    nm->add_switch("a");
    nm->add_switch("d");
    nm->add_switch("b");
    nm->add_switch("c");
    // sub2
    //nm->add_switch("e");
    //nm->add_switch("h");
    //nm->add_switch("g");
    //nm->add_switch("f");

    nm->connect_r("a", "b");
	nm->connect_r("b", "c");    
	nm->connect_r("c", "a");
	nm->connect_r("c", "d");

	nm->print_all_e();

	Edge *elist = nm->elist;
	Edge *list = nm->elist;


    // build the edges belong to vertex 
    while(list!=NULL){
        adv[list->head->name].push_back(list);
        list=list->next;
    }

    // DFS
    // push this node into existed list



    existed_vertices.push_back(adv["b"].at(0)->head);
//while(elist!=NULL){
    dfs("b");

    Edge *dfs_elist=NULL, *tmp=dfs_elist;
	
	cout << "path : " << dfs_paths.size() << endl;
	
    cout << "DFS: " << endl;
    for(int i=0;i<dfs_paths.size();i++){
		
		//elist = nm->elist;
		//cout << "elist : " << elist << endl;
        cout << dfs_paths.at(i)->head->name << "->" << dfs_paths.at(i)->tail->name << endl;
		nm->disconnect(dfs_paths.at(i)->head->name, dfs_paths.at(i)->tail->name);
	//list = list->next;
		nm->disconnect(dfs_paths.at(i)->tail->name, dfs_paths.at(i)->head->name);
		nm->print_all_e();
	//list = list->next;
		//try_elist = nm->elist;
		//cout << "try_elist : " << try_elist << endl;
		
        if(tmp==NULL){
            dfs_elist = new Edge(dfs_paths.at(i));
			
            tmp = dfs_elist;
        } else {
            tmp->next = new Edge(dfs_paths.at(i));
			//cout << "dfs_elist : " << dfs_elist << endl;
			//cout << "tmp_elist : " << tmp << endl;
            tmp = tmp->next;
			//cout << "tmp_elist_next : " << tmp << endl;
        }
			//try_elist = nm->elist;
			//cout << "elist : " << try_elist << endl;
			//nm->disconnect(dfs_paths.at(i)->head->name, dfs_paths.at(i)->tail->name);
			//nm->disconnect(dfs_paths.at(i)->tail->name, dfs_paths.at(i)->head->name);
			//nm->print_all_e();
			//try_elist = nm->elist;
			//cout << "elist_next : " << try_elist << endl;
    }


//**********************************************************//

	//list = nm->elist;

while(list!=NULL){
        adv[list->head->name].push_back(list);
        list=list->next;
    }

    // DFS
    // push this node into existed list



    existed_vertices.push_back(adv["b"].at(0)->head);
//while(elist!=NULL){
    dfs("b");

    dfs_elist=NULL;
	tmp=dfs_elist;
	
	cout << "path : " << dfs_paths.size() << endl;
	
    cout << "DFS: " << endl;
    for(int i=0;i<dfs_paths.size();i++){
		
		//elist = nm->elist;
		//cout << "elist : " << elist << endl;
        cout << dfs_paths.at(i)->head->name << "->" << dfs_paths.at(i)->tail->name << endl;
		nm->disconnect(dfs_paths.at(i)->head->name, dfs_paths.at(i)->tail->name);
		//elist = elist->next;
		nm->disconnect(dfs_paths.at(i)->tail->name, dfs_paths.at(i)->head->name);
		nm->print_all_e();
		//elist = elist->next;
		//try_elist = nm->elist;
		//cout << "try_elist : " << try_elist << endl;
		
        if(tmp==NULL){
            dfs_elist = new Edge(dfs_paths.at(i));
			
            tmp = dfs_elist;
        } else {
            tmp->next = new Edge(dfs_paths.at(i));
			//cout << "dfs_elist : " << dfs_elist << endl;
			//cout << "tmp_elist : " << tmp << endl;
            tmp = tmp->next;
			//cout << "tmp_elist_next : " << tmp << endl;
        }
			//try_elist = nm->elist;
			//cout << "elist : " << try_elist << endl;
			//nm->disconnect(dfs_paths.at(i)->head->name, dfs_paths.at(i)->tail->name);
			//nm->disconnect(dfs_paths.at(i)->tail->name, dfs_paths.at(i)->head->name);
			//nm->print_all_e();
			//try_elist = nm->elist;
			//cout << "elist_next : " << try_elist << endl;
    }


//**********************************************************//


    Gplot *gp = new Gplot();
    gp->gp_add(dfs_elist);
    gp->gp_dump(true);
    gp->gp_export("dfs/dfs");
//}
	
    return 0;

}


void dfs(string src){
    for(int i=0;i<adv[src].size();i++){
        // cout << adv[src].at(i)->head->name << "=>" << adv[src].at(i)->tail->name << endl;
        // check edge is already existed or not
        if(find(dfs_paths.begin(), dfs_paths.end(), adv[src].at(i))==dfs_paths.end()){
            // check the tail is in the existed_vertices or not
            if(find(existed_vertices.begin(), existed_vertices.end(), adv[src].at(i)->tail)==existed_vertices.end()){
                // and push this edge into dfs result
                dfs_paths.push_back(adv[src].at(i));
                // not existed, then push into existed
                existed_vertices.push_back(adv[src].at(i)->tail);
                // recursive
                dfs(adv[src].at(i)->tail->name);
            }
        }
    }
}
