#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class maxHeap{
    vector<int> heap;
    private:
    void heapifyUp(int index){
        if(index && heap[(index-1)/2]<heap[index]){ 
            /* (index-1)/2 means the parent index of the current index if index is 3
                then index-1/2 srands for 3-1/2=1 so if index is 1 we can say 2*1+1=3 and 2*1+2=4 so 3s parent is 1 same goes for as 
                4-1/2=3/2=1   ,... so everytime we enter a element we check if its parent index ele is greater or smaller and then swap accordingly its like a bst 
                left is smaller and right is greater so we can say its a max heap */
            swap(heap[index],heap[(index-1)/2]);
            heapifyUp((index-1)/2);
        }


    }

    void heapifyDown(int index){
        /*When we delete an element we have to reconstruct the array so whn=en we encounter an index we check for its child 
        2*index+1 and 2*index+2 , first one is left and the other one is right and we swap accoringly it also follows the bst like
        structre ...*/
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        if(left<heap.size() && heap[left]>heap[largest]){
            largest=left;
        }
        if(right<heap.size() && heap[right]>heap[largest]){
            largest=right;
        }
        if(largest!=index){
            swap(heap[largest],heap[index]);
            heapifyDown(largest);
        }
    }

    public :

    void insert(int element){
        heap.push_back(element);
        heapifyUp(heap.size()-1);
    }
    void deleteMax(int index){
        /* Since we are using 0 based indexing so we have to delete the element at index 0 as theres gonnab the max element at top or at first index and
         the minimum at last so we make the first as the last and then we call the heapifyDown function to reconstruct the array */
        if(heap.empty()) return;
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void printHeap(){
        for(int i:heap){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main(){
    maxHeap maxi;
    maxi.insert(10);
    maxi.insert(300);
    maxi.insert(40);
    maxi.insert(4);
    maxi.insert(30);
    maxi.printHeap();
}