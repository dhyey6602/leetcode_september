class node{

 public:
 
//here the left node represents bit is 0 and right node represents bit is 1
 
node* left;
node* right;
 
 node(){
  this->left=NULL;
  this->right=NULL;  
 }
};
 class Trie{
node* head;
int max_xor_so_far(int number){   
      node* temp = head;
      if(temp->left==NULL && temp->right==NULL){       
          // if we are adding the first node we have to handle this case just return 0 as xor of any number with itself is 0 
          return 0;
      }
      int value =0;
      for(int i=31;i>=0;i--){
          bool bit_present =  number &(1<<i) ;
          if(bit_present){
              if(temp->left){             
                  value += pow(2,i);
                  temp=temp->left;
              }
              else{
                  temp=temp->right;   
              }
          }
          else{
              if(temp->right){
                  value += pow(2,i);
                  temp=temp->right;
              }
              else{
                  temp=temp->left;
              }
          }
      } 
    return value;
}
void add_in_trie(int num){
    node* temp =head;
    for(int i=31;i>=0;i--){
        if(num & (1<<i)){        
            if(temp->right){
                temp=temp->right;
            }
            else{          
                temp->right= new node;
                temp=temp->right;
            }
        }
        else{
            if(temp->left){
                temp=temp->left;
            }
            else{        
                temp->left = new node;
                temp= temp->left;
            }
        }
    }   
}
public:
int max_xor_value;
Trie (){   
    head= new node;
    max_xor_value=0;   
}
     void add_values(vector<int> & nums){
    
   for(int i=0;i<nums.size();i++){
       //before adding that number we check if this number return a xor value greater than the max_xor_value than we update the max_xor_value 
          int k= max_xor_so_far(nums[i]);
       
          max_xor_value = max(max_xor_value, k);
        // after the comparisons have been done just add this value in our trie
          add_in_trie(nums[i]);
       
    }
}


};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
    t.add_values(nums);
    return t.max_xor_value;
    }
};
