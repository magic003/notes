public class CircularQueue810 {
    private int capacity;
    private int size;
    private int[] arr;
    private int head;
    private int tail;

    public CircularQueue810(final int capacity) {
        this.capacity = capacity;
        arr = new int[capacity];
        size = 0;
        head = -1;
        tail = 0;
    }

    public int size() {
        return size;
    }

    public void enqueue(int x) {
        if (size == capacity) {
            capacity *= 2;
            int[] newArr = new int[capacity];
            int i = 0;
            while (i < size) {
                newArr[i] = arr[(head+i)%size];
                i++;
            }
            arr = newArr;
            head = 0;
            tail = size;
        }

        arr[tail] = x;
        tail = (tail+1) % capacity;
        size++;
    }

    public int dequeue() {
        if (size == 0) {
            throw new RuntimeException();
        }

        int res = arr[head];
        head = (head + 1) % capacity;
        size--;
        return res;
    }
}
