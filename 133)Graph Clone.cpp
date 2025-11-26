#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

class Node
{
    public:
        int val;
        std::vector<Node*> neighbors;

        Node()
        {
            val = 0;
            neighbors = std::vector<Node*>();
        }

        Node(int _val)
        {
            val = _val;
            neighbors = std::vector<Node*>();
        }

        Node(int _val, std::vector<Node*> _neighbors)
        {
            val = _val;
            neighbors = _neighbors;
        }
};

static Node* clone(Node* node)
{
    Node* newNode = new Node(node->val);
    return newNode;
}

class Solution
{
    public:
        Node* cloneGraph(Node* node)
        {
            if (!node) return NULL;

            std::unordered_map<Node*, Node*> uMap;
            std::queue<Node*> q;
            std::vector<bool> isVisited(100, false);

            
        }
};


static void BFS_MAKE_CLONE(Node* node)
{
    //data structures for BFS
    std::unordered_map<Node*, bool> m_IsVisited;
    std::queue<Node*> q;
    std::unordered_map<Node*, Node*> cloneMap;

    q.push(node);
    m_IsVisited[node] = true;
    cloneMap[node] = clone(node);

    printf("root pushed into queue || root visited set || clone made for root\n");

    while (!q.empty())
    {
        printf("While loop runs\n");

        Node* u = q.front();
        q.pop();

        for (int i = 0; i < u->neighbors.size(); i++)
        {
            Node* neighbor = u->neighbors[i];

            if (!m_IsVisited[u->neighbors[i]])
            {
                m_IsVisited[u->neighbors[i]] = true;
                printf("visited : %d node \n", u->neighbors[i]->val);
                cloneMap[neighbor] = clone(neighbor);
                
                printf("Clone made for Node : %d\n", cloneMap[u->neighbors[i]]->val);
                q.push(u->neighbors[i]);

            }

            cloneMap[u]->neighbors.push_back(cloneMap[neighbor]);
        }
    }
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    n1->neighbors = { n2, n3 };
    n2->neighbors = { n1, n3 };
    n3->neighbors = { n1, n2, n4, n6 };
    n4->neighbors = { n3, n5 };
    n5->neighbors = { n4 };
    n6->neighbors = { n3 };

    BFS_MAKE_CLONE(n1);

	return 0;
}

