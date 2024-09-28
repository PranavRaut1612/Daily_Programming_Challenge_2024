#include<iostream>
#include<stack>
using namespace std;
void insertInSortedOrder(stack<int>& s,int element){
    if(s.empty() || s.top()<=element){
        s.push(element);
        return;
    }
    int top = s.top();
    s.pop();
    insertInSortedOrder(s,element);
    s.push(top);
}
void sortStack(stack<int>& s){
    if(s.empty()) return;
    int top = s.top();
    s.pop();
    sortStack(s);
    insertInSortedOrder(s,top);
}
void printStack(stack<int> s){
    stack<int> aux;
    while (!s.empty()) {
        aux.push(s.top());
        s.pop();
    }
    while (!aux.empty()) {
        cout << aux.top() << " ";
        aux.pop();
    }
    cout << endl;
}
int main(){
    stack<int> s;
    int arr[] = {3,1,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        s.push(arr[i]);
    }
    cout<<"Original Stack : ";
    printStack(s);
    //Sort the stack
    sortStack(s);
    cout<<"Sorted Stack : ";
    printStack(s);
}