#include <iostream>
#include <stack>
#include "Graph.h"
using namespace std;

int main(int argc, char *argv[]){
    graph g;
    vector<graph::vertex_label> vertexLabels;

    if (argc != 5){
        cout << "Error, must provide 5 command line arguments" << endl;
        return 1;
    }
    else{
        if(!g.read_file(argv[1])){
            std::cout << "could not open file '" << argv[1] << "'\n";
            return 0;
        }
    }

    int budget = atoi(argv[4]);

    int source = g.name2id(argv[2]);
    int sink = g.name2id(argv[3]);
    
    cout << endl;
    cout << "calculating paths from " << argv[2] << " to " << argv[3] << "..." << endl;
    g.dijkstraHEAP(argv[2], budget, vertexLabels);
    cout << "calculation finished..." << endl << endl;


    if (!vertexLabels[sink].queue.size()){
        cout << "ERROR! The vertex " << argv[3] << " is not reachable from " << argv[2] << endl;
        return 1;
    }
    else if (vertexLabels[sink].queue.top().weights.first > budget){
        cout << "***Notice! - The total cost from " << argv[2] << " to " << argv[3] << " is greater than the allocated cost of " << budget << endl << endl;
    }

    int c = vertexLabels[sink].queue.top().weights.first, t = vertexLabels[sink].queue.top().weights.second;
    stack<graph::element> s;
    while (sink != source){
        s.push(graph::element(c,t,sink));

        sink = vertexLabels[sink].queue.top().id;
        c = vertexLabels[sink].queue.top().weights.first;
        t = vertexLabels[sink].queue.top().weights.second;
    }

    s.push(graph::element(c,t,sink));

    cout << "Printing path: " << endl;
    while (s.size()){
        graph::element temp = s.top();
        string name = g.id2name(temp.id);
        c = temp.weights.first, t = temp.weights.second;

        if (s.size() > 1)
            cout << "Vertex: " << name << " Cost: " << c << " Time: " << t << " -> ";
        else 
            cout << "Vertex: " << name << " Cost: " << c << " Time: " << t;
        s.pop();
    }
    cout << endl << endl;

    return 0;
}