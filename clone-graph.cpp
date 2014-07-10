class Solution {
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            map<int, UndirectedGraphNode*> visited;
            return cloneGraph(node, visited);
        }

        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, map<int, UndirectedGraphNode*> &visited){
            if(node == NULL) return NULL;
            map<int, UndirectedGraphNode*>::iterator iter = visited.find(node->label);
            if(iter != visited.end()){
                return iter->second;
            }else{
                UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
                visited[node->label] = newNode;
                for(int i = 0; i != node->neighbors.size(); ++i){
                    newNode->neighbors.push_back(cloneGraph(node->neighbors[i], visited));
                }
                return newNode;
            }
        }
};
