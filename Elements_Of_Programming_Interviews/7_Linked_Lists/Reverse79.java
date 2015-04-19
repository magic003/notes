public class Reverse79 {
    private static class Node {
        private int data;
        private Node next;

        public Node(int data, Node next) {
            this.data = data;
            this.next = next;
        }

        public Node(int data) {
            this(data, null);
        }
    }

    public Node reverse(Node list) {
        Node prev = null;
        Node curr = list;

        while (curr != null) {
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    private static void printList(Node list) {
        while(list != null) {
            System.out.print(list.data + "->");
            list = list.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Reverse79 reverse = new Reverse79();

        Node list = new Node(1, new Node(2, new Node(3, new Node(4))));
        printList(list);
        printList(reverse.reverse(list));
    }
}
