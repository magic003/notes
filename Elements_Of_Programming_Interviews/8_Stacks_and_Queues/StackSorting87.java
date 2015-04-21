import java.util.*;

public class StackSorting87 {
    public void sort(Stack<Integer> stack) {
        if (stack == null || stack.isEmpty()) return;

        int top = stack.pop();
        sort(stack);

        insert(stack, top);
    }

    private void insert(Stack<Integer> stack, int num) {
        if (stack.isEmpty() || num <= stack.peek()) {
            stack.push(num);
        } else {
            int top = stack.pop();
            insert(stack, num);
            stack.push(top);
        }
    }

    public static void main(String[] args) {
        StackSorting87 stackSorting = new StackSorting87();
        Stack<Integer> st = new Stack<Integer>();
        st.push(3);
        st.push(2);
        st.push(5);
        st.push(7);
        st.push(7);
        st.push(10);

        stackSorting.sort(st);
        while (!st.isEmpty()) {
            System.out.print(st.pop() + " ");
        }
        System.out.println();
    }
}
