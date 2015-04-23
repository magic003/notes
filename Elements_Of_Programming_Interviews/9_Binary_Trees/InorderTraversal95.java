import java.util.*;

public class InorderTraversal95 {
    public static class TreeNode {
        private int data;
        private TreeNode left;
        private TreeNode right;
        private TreeNode parent;

        public TreeNode(int data, TreeNode left, TreeNode right, TreeNode parent) {
            this.data = data;
            this.left = left;
            this.right = right;
            this.parent = parent;
        }
    }

    public List<Integer> inorder(TreeNode tree) {
        List<Integer> res = new ArrayList<Integer>();

        TreeNode prev = null;
        TreeNode curr = tree;
        TreeNode next = null;

        while (curr != null) {
            if (prev == curr.parent) { // move down
                if (curr.left != null) {
                    next = curr.left;
                } else {    // curr.right != null
                    res.add(curr.data);
                    next = curr.right != null ? curr.right : curr.parent;
                }
            } else if (prev == curr.left) {
                res.add(curr.data);
                next = curr.right != null ? curr.right : curr.parent;
            } else { // prev == curr.right
                next = curr.parent;
            }

            prev = curr;
            curr = next;
        }

        return res;
    }

    public static void main(String[] args) {
        InorderTraversal95 traversal = new InorderTraversal95();

        //          6
        //      /       \
        //     3         8
        //    / \       /
        //   1   4     7
        //        \
        //         5
        TreeNode n5 = new TreeNode(5, null, null, null);
        TreeNode n4 = new TreeNode(4, null, n5, null);
        n5.parent = n4;

        TreeNode n1 = new TreeNode(1, null, null, null);
        TreeNode n3 = new TreeNode(3, n1, n4, null);
        n4.parent = n3;
        n1.parent = n3;

        TreeNode n7 = new TreeNode(7, null, null, null);
        TreeNode n8 = new TreeNode(8, n7, null, null);
        n7.parent = n8;

        TreeNode n6 = new TreeNode(6, n3, n8, null);
        n3.parent = n6;
        n8.parent = n6;

        List<Integer> res = traversal.inorder(n6);
        for (int num : res) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
