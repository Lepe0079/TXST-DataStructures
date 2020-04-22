/* Daniel Lepe
   Data Structures 3358
   04/22/20*/
#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}


void bst_insert(btNode*& bst_root, int newVal)
{
   btNode* cursor = bst_root;
   btNode* preCursor = 0;

   btNode* newNode = new btNode;
   newNode->data = newVal; 
   newNode->right = 0;
   newNode->left = 0;

   if(!bst_root)
   {
      bst_root = newNode;
      return;
   }

   while(cursor != 0)
   {
      preCursor = cursor;

      if(cursor->data == newVal)
      {
         cursor->data = newVal;
         return;
      }

      if(newVal < cursor->data)
         cursor = cursor->left;
      else if(newVal > cursor->data)
         cursor = cursor->right;
      
   }


   if(newVal < preCursor->data)
      preCursor->left = newNode;
   else
      preCursor->right = newNode;
}


bool bst_remove(btNode*& bst_root, int remInt)
{
   
   if(bst_root == 0)//base case, nothing on the tree
      return false;
   

   if(remInt > bst_root->data)
      return bst_remove(bst_root->right, remInt);
   
   
   if(remInt < bst_root->data)
      return bst_remove(bst_root->left, remInt);

   
   if(bst_root->data == remInt)//cases where root has the value to be removed
   {
      if(!bst_root->left)//has no left child
      {
         btNode* temp = bst_root;
         bst_root = bst_root->right;
         delete temp;
      }
      else
         bst_remove_max(bst_root->left, bst_root->data);

      return true;
   }
   return false;
}

void bst_remove_max(btNode*& root, int& data)
{
   if(!root->right)
   {
      data = root->data;
      btNode* temp = root;
      root = root->left;
      delete temp;
   }
   else 
      bst_remove_max(root->right, data);   
}

