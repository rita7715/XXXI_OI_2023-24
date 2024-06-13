#include <bits/stdc++.h>

using namespace std;


struct dimension_vertex
{
    int approved;
    int disapproved;
    int left;
    set <int> another_coordinates;
};



class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    bool hasCycle(vector<int>& cycleVertices);

private:
    int vertices;
    vector<vector<int>> adjList;
    bool hasCycleUtil(int v, vector<bool>& visited, int parent, vector<int>& cycleVertices);
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjList.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}
bool Graph::hasCycleUtil(int v, vector<bool>& visited, int parent, vector<int>& cycleVertices) {
    visited[v] = true;
    cycleVertices.push_back(v);

    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            if (hasCycleUtil(neighbor, visited, v, cycleVertices))
                return true;
        } else if (neighbor != parent) {
            cycleVertices.push_back(neighbor);
            return true;
        }
    }

    cycleVertices.pop_back();
    return false;
}

bool Graph::hasCycle(vector<int>& cycleVertices) {
    vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            cycleVertices.clear();
            if (hasCycleUtil(i, visited, -1, cycleVertices)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int dimension, vertices;
    //unordered_map <pair <int, int>, int> przyciski;
    unordered_map <int, set <int> > vertical;
    unordered_map <int, set <int> > horizontal;
    unordered_map <int, unordered_map <int, int> > przyciski;
    set <int> approved;
    set <pair <int, int> > disapproved;
    set <int> z_jednym;
    set <int> wiecej;

    cin >> dimension >> vertices;
    int rozmiar = dimension * 2 + vertices + 1;
    Graph g(rozmiar);
    vector <dimension_vertex> wszystko;
    dimension_vertex temporary;
    temporary.approved=0;
    temporary.disapproved=0;
    temporary.left=0;
   for (int i=0;i<=rozmiar;i++)
    {
        wszystko.push_back(temporary);
    }
    int tmp1, tmp2;
    unordered_map <int, pair <int, int> > coordinates;
   // set <pair <int, int> > przyciski;
    for (int i = 1; i <= vertices; i++) {
        cin >> tmp1 >> tmp2;
        g.addEdge(i, vertices + tmp1);
        g.addEdge(i, vertices + dimension + tmp2);
        wszystko[vertices + tmp1].left+=1;
        wszystko[vertices + tmp1].another_coordinates.insert(vertices + dimension + tmp2);
        wszystko[vertices + dimension + tmp2].left+=1;
        wszystko[vertices + dimension + tmp2].another_coordinates.insert(vertices + tmp1);
        przyciski[vertices+tmp2 + dimension][vertices+tmp1] = i;
       // przyciski[{vertices + tmp2 + dimension, vertices + tmp1}] = i;

        if (wszystko[vertices + tmp1].left==1)
        {
            z_jednym.insert(vertices+tmp1);
        }else
        {
            wiecej.insert(vertices+tmp1);
            //cout << vertices+tmp1 << "\n";
            z_jednym.erase(vertices+tmp1);
        }
        if (wszystko[vertices + tmp2 + dimension].left==1)
        {
            z_jednym.insert(vertices + tmp2 + dimension);
        }else
        {
            wiecej.insert(vertices + tmp2 + dimension);
           //  cout << vertices+tmp2+dimension << "\n";
            z_jednym.erase(vertices + tmp2 + dimension);
        }
    }
     set <pair <int, int> > used_coordinates;
    vector<int> cycleVertices;
    int s=0;
    if (g.hasCycle(cycleVertices)) {
        cout << "TAK\n";
        int start;
        for (int i=0;i<cycleVertices.size()-1;i++)
        {
            if (cycleVertices[i] == cycleVertices[cycleVertices.size()-1])
            {
                start = i;
                break;
            }
        }
        s = cycleVertices.size()-start-1;
        s = s/2;
         cout << s << "\n";
        for (int i=start;i<cycleVertices.size()-1;i++)
        {
            if (cycleVertices[i] <= vertices)
            {

                cout << cycleVertices[i] << " ";
                used_coordinates.insert(coordinates[cycleVertices[i]]);
            }
        }


    }else {

       int i=-1;
        int f=10;

        if (z_jednym.size() + wiecej.size() == dimension*2){
while (approved.size() + disapproved.size()<vertices){
        for (auto it = z_jednym.begin();it!= z_jednym.end();++it)
        {


            z_jednym.erase(i);
            i = *it;
            auto itt = wszystko[i].another_coordinates.begin();
            int j = *itt;
            wszystko[i].another_coordinates.erase(j);
             wszystko[j].another_coordinates.erase(i);
            wszystko[i].left -=1;
            wszystko[j].left -=1;
            if (wszystko[i].approved%2==0)
            {
                //cout << i << " " << j << " " << wszystko[i].approved << "\n";
                wszystko[i].approved+=1;
                wszystko[j].approved+=1;
                if (j>i)
                {
                    approved.insert(przyciski[j][i]);
                }else
                {
                   approved.insert(przyciski[i][j]);
                }

            }else
            {

                wszystko[i].disapproved+=1;
                wszystko[j].disapproved+=1;
                if (j>i)
                {
                  //  cout << i << " " << j << " " << wszystko[i].approved << "\n";
                    disapproved.insert({i,j});
                }else
                {
                   // cout << j << " " << i << " " << wszystko[i].approved << "\n";
                    disapproved.insert({j,i});
                }
            }

            if (wszystko[j].left==1)
            {
                z_jednym.insert(j);
            }
            if (wszystko[j].left==0)
            {
                z_jednym.erase(j);
                if (wszystko[j].approved%2==0)
                {
                    vertices=0;
                    cout << "NIE";
                    break;
                }

            }




        }
}
if (vertices!=0){
cout << "TAK\n" << approved.size() << "\n";
        for (auto it = approved.begin();it != approved.end();++it)
        {
            int przycisk = *it;
            cout << przycisk << " ";
        }

}
        }else
        {
            cout << "NIE";
        }

    }







    return 0;
}
