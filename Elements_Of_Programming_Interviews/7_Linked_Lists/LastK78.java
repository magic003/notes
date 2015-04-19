public class LastK78 {
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

    public Node remove(Node list, int k) {
        if (list == null || k <= 0) return list;

        Node head = new Node(0, list);
        Node advK = head;
        for (int i = 0; i < k && advK != null; i++) {
            advK = advK.next;
        }

        if (advK == null) {
            return list;
        }

        Node prev = head;
        while (advK.next != null) {
            prev = prev.next;
            advK = advK.next;
        }

        prev.next = prev.next.next;

        return head.next;
    }

    private static void printList(Node list) {
        while (list != null) {
            System.out.print(list.data + "->");
            list = list.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        LastK78 lastK = new LastK78();
        Node list = new Node(1, new Node(2, new Node(3, new Node(4))));
        printList(list);
        System.out.println("k = 4");
        printList(lastK.remove(list, 4));

        list = new Node(1, new Node(2, new Node(3, new Node(4))));
        printList(list);
        System.out.println("k = 2");
        printList(lastK.remove(list, 2));
    }
}
