import java.util.*;

public class TwoStacks812 {
    public class Queue<T> {
        private Stack<T> s1;
        private Stack<T> s2;

        public void enqueue(final T t) {
            s1.push(t);
        }

        public T dequeue() {
            if (!s2.isEmpty()) {
                while (!s1.isEmpty()) {
                    s2.push(s1.pop());
                }
            }

            if (!s2.isEmpty()) {
                return s2.pop();
            }

            throw new RuntimeException();
        }
    }
}
