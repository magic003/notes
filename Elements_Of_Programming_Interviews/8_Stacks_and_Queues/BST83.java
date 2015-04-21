import java.util.*;

public class BST83 {
    private static class TreeNode {
        private int data;
        private TreeNode left;
        private TreeNode right;

        public TreeNode(int data, TreeNode left, TreeNode right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    public List<Integer> preorder(TreeNode tree) {
        List<Integer> res = new ArrayList<Integer>();

        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode curr = tree;

        while (!stack.isEmpty() || curr != null) {
            if (curr == null) {
                TreeNode top = stack.pop();
                res.add(top.data);
                curr = top.right;
            } else {
                stack.push(curr);
                curr = curr.left;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        BST83 bst = new BST83();
        TreeNode tree = new TreeNode(6,
                            new TreeNode(3,
                                new TreeNode(1, null, null),
                                new TreeNode(4,
                                    null,
                                    new TreeNode(5, null, null))),
                            new TreeNode(8,
                                new TreeNode(7, null, null),
                                null));
        List<Integer> res = bst.preorder(tree);

        for (Integer i : res) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
