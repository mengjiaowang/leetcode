class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            std::vector<int> index;
            std::map<int, std::vector<std::vector<int>::size_type> >index_map;
            std::map<int, std::vector<std::vector<int>::size_type> >::iterator iter;

            for(std::vector<int>::size_type i = 0; i != numbers.size(); ++i){
                iter = index_map.find(numbers[i]);
                if(iter == index_map.end()){
                    std::vector<std::vector<int>::size_type> tmp;
                    tmp.push_back(i);
                    index_map[numbers[i]] = tmp;
                }
                else{
                    iter->second.push_back(i);
                }
            }

            std::sort(numbers.begin(), numbers.end());
            std::vector<int>::size_type i = 0, j = numbers.size() - 1;
            while(i != j){
                if(numbers[i] + numbers[j] > target) --j;
                else if(numbers[i] + numbers[j] < target) ++i;
                else{
                    std::vector<int>::size_type index1 = 0, index2 = 0;
                    if(numbers[i] == numbers[j]){
                        index1 = index_map.find(numbers[i])->second[0] + 1;
                        index2 = index_map.find(numbers[i])->second[1] + 1;
                    }
                    else
                    {
                        index1 = index_map.find(numbers[i])->second[0] + 1;
                        index2 = index_map.find(numbers[j])->second[0] + 1;
                        if(index1 > index2){
                            std::vector<int>::size_type tmp = index1;
                            index1 = index2;
                            index2 = tmp;
                        }
                    }
                    index.push_back(index1);
                    index.push_back(index2);
                    break;
                }
            }
            return index;
        }
};
