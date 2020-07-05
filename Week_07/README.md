# 双向bfs模板

```
void bfs() {
    unordered_set<T> visited, headSet, tailSet;
        headSet.insert(begin);
        tailSet.insert(end);

        while(!headSet.empty() && !tailSet()) {
            if(headSet.size() > tailSet.size()) swap(headSet, tailSet);
            
            unordered_set<T> tmp;
            for(auto node : headSet) {
                visited.add(node)
		        process(node) 
		        nodes = generate_related_nodes(node) 
                tmp.insert(nodes);
            }
            swap(tmp, headSet);
        }
        # other processing work 
}