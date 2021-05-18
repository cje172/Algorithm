#include <iostream>
using namespace std;

struct node 
{
    char left;
    char right;
};

struct node arr[27];

void preOrder(char root) // 전위 순회
{
    if (root == '.')
        return;
    cout << root;
    preOrder(arr[root].left);
    preOrder(arr[root].right);
}

void inOrder(char root) // 중위 순회
{
    if (root == '.')
        return;
    inOrder(arr[root].left);
    cout << root;
    inOrder(arr[root].right);
}

void postOrder(char root) // 후위 순회
{
    if (root == '.')
        return;
    postOrder(arr[root].left);
    postOrder(arr[root].right);
    cout << root;
}

int main() 
{
    int n; // 노드 개수
    cin >> n;

    char a, b, c;

    for (int i = 0; i < n; i++) 
    {
        cin >> a >> b >> c;
        arr[a].left = b;
        arr[a].right = c;
    }

    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout << "\n";

    return 0;
}
