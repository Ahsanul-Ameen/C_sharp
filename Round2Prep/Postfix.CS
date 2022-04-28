using System;
using System.Collections.Generic;


class Node {
    public char op;
    public int value;
    public Node left, right;
    public Node(int operand) {
        this.op = '$';
        this.value = operand;
    }
    public Node(char op, int value, Node left, Node right) {
        this.op = op;
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

public class Starter {
    static bool isop(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'; 
    }

    static int evaluate(char op, int op1, int op2) {
        switch (op)
        {   
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            case '*':
                return op1 * op2;
            case '/':
                return op1 / op2;
            case '^':
                return op1 ^ op2;
            default:
                return 0;
        }
    }

    static Node ExpressionTree(string postfix) {
        if (postfix.Length == 0) {
            return null;
        }
        Stack<Node> st = new Stack<Node>();
        foreach (char item in postfix)
        {
            if (isop(item)) {
                Node right = st.Peek(); st.Pop();
                Node left = st.Peek(); st.Pop();
                st.Push(new Node(item, evaluate(item, left.value, right.value), left, right));
            } else {
                st.Push(new Node((int)(item - '0')));
            }
        }

        return st.Pop();
    }

    static void InOrder(Node root) {
        if (root == null)
            return;
        InOrder(root.left);
        if (root.op == '$') 
            Console.Write(root.value);
        else Console.Write(root.op);
        InOrder(root.right);
    }

    public static void Main(string[] args) {
        string postfix = "359+2*+";
        Node root = ExpressionTree(postfix);
        Console.WriteLine(root.op + ", " + root.value);
        InOrder(root);
        Console.WriteLine();
    }

}