#include <iostream>
using namespace std;

class Graph {
   private:
  bool** adjMatrix;
  int vertex;

   public:
  Graph(int vertex) {
    this->vertex = vertex;
    adjMatrix = new bool*[vertex];
    for (int i = 0; i < vertex; i++) {
      adjMatrix[i] = new bool[vertex];
      for (int j = 0; j < vertex; j++)
        adjMatrix[i][j] = false;
    }
  }

  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }
  
  void showGraph() {
    for (int i = 0; i < vertex; i++) {
      cout << i << " : ";
      for (int j = 0; j < vertex; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }

  ~Graph() {
    for (int i = 0; i < vertex; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};

int main() {
  Graph g(4);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);

  g.showGraph();
}
