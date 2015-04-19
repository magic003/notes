public class Merge71 {
    private static class Node<T> {
        private T data;
        private Node<T> next;

        public Node(T data) {
            this(data, null);
        }

        public Node(T data, Node<T> next) {
            this.data = data;
            this.next = next;
        }
    }

    public Node<Integer> merge(Node<Integer> l1, Node<Integer> l2) {
        Node<Integer> res = new Node<Integer>(0);
        Node<Integer> curr = res;

        while (l1 != null && l2 != null) {
            if (l1.data <= l2.data) {
                curr.next = l1;
                l1 = l1.next;
            } else {
                curr.next = l2;
                l2 = l2.next;
            }
            curr = curr.next;
        }

        if (l1 != null) {
            curr.next = l1;
        }

        if (l2 != null) {
            curr.next = l2;
        }

        return res.next;
    }

    private static <T> void printList(Node<T> list) {
        while (list != null) {
            System.out.print(list.data + "->");
            list = list.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Merge71 merge = new Merge71();
        Node<Integer> l1 = new Node<Integer>(2, new Node<Integer>(5, new Node<Integer>(7)));
        Node<Integer> l2 = new Node<Integer>(3, new Node<Integer>(11));
        printList(l1);
        printList(l2);
        printList(merge.merge(l1,l2));
    }
}
