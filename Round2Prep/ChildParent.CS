using System;
using System.Collections.Generic;


class Node {
    public int data;
    public Node left;
    public Node right;
    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Solution
{   
    //Function to construct binary tree from parent array.
    public static Node CreateTree(int[] parent,int N)
    {
        //code here
        List<int>[] adjList = new List<int>[N];
        for (int i = 0; i < N; ++i) {
            adjList[i] = new List<int>();
        }
        Queue<int> q = new Queue<int>();
        
        for (int child = 0; child < N; ++child) {
            int par = parent[child];
            if (par != -1) {
                adjList[par].Add(child);
            } else {
                q.Enqueue(child);   
            }
        }

        Console.WriteLine(q.Peek());
        for (int i = 0; i < N; ++i) {
            Console.Write(i + " : ");
            foreach(int v in adjList[i].ToArray()) {
                Console.Write(v + " ");
            }
            Console.WriteLine();
        }

        
        
        Node[] nodes = new Node[N];
        
        while (q.Count > 0) {
            int u = q.Dequeue();
            nodes[u] = new Node(u);

            Console.WriteLine("------" + nodes[u].data);
            
            if (parent[u] != -1) {
                int p = parent[u];
                if (nodes[p].left == null) {
                    nodes[p].left = nodes[u];
                } else {
                    nodes[p].right = nodes[u];
                }
            }
            
            foreach (int v in adjList[u]) {
               q.Enqueue(v);
            }
        }
        
        for (int u = 0; u < N; ++u) {
            if (parent[u] == -1) {
                return nodes[u];
            }
        }
        
        return null;
    }

    static void PreOrder(Node root) {
        if (root == null)
            return;

        Console.Write(root.data + " ");
        PreOrder(root.left);
        PreOrder(root.right);
    }

    public static void Main(string[] args) {
        Node root = CreateTree(new int[]{-1, 0, 0, 1, 1, 3, 5}, 7);
        PreOrder(root);
        Console.WriteLine();
        Console.WriteLine();
        root = CreateTree(new int[]{2, 0, -1}, 3);
        PreOrder(root);
        Console.WriteLine();
    }
}