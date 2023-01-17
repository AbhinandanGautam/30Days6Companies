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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        ListNode* root = new ListNode(0);
        root->next = head;
        mp[0] = root;

        int sum = 0;

        while(head!=NULL){
            sum += head->val;

            if(mp.find(sum)!=mp.end()){
                ListNode* temp = mp[sum];
                ListNode* node = temp;

                int aux_sum = sum;

                while(temp!=head){
                    temp = temp->next;
                    aux_sum += temp->val;
                    if(temp!=head){
                        mp.erase(aux_sum);
                    }
                }

                node->next = head->next;
            }
            else{
                mp[sum] = head;
            }

            head = head->next;
        }

        return root->next;
    }
};