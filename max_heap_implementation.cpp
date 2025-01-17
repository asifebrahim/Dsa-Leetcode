#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class maxHeap{
    vector<int> heap;
    private:
    void heapifyUp(int index){
        if(index && heap[(index-1)/2]<heap[index]){
            swap(heap[index],heap[(index-1)/2]);
            heapifyUp((index-1)/2);
        }


    }

    void heapifyDown(int index){
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