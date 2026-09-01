/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr= head->next;
        if(!curr->next) return {-1,-1};
        ListNode* back = head;
        ListNode* front = curr->next;
        vector<int> indices;
        int i = 1, mini = 1e9;
        while(front){
            int a = back->val , b = curr->val, c = front->val;
            if((a<b && b>c) || (a>b && b<c)){
                if(!indices.empty()) mini = min(mini, i - indices.back());
                indices.push_back(i);
            }
            back = curr;
            curr = front;
            front = front -> next;
            i++;
        }
        for(auto& ele : indices) cout<<ele<<" ";
        if(indices.empty() || indices.size()==1) return {-1,-1};
        return {mini, indices.back() - indices[0]};
    }
};