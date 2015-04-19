import java.util.*;

public class NextPermutation612 {
    public List<Integer> next(List<Integer> perm) {
        if (perm == null || perm.isEmpty()) return perm;

        int len = perm.size();

        for (int i = len-1; i > 0; i--) {
            if (perm.get(i) > perm.get(i-1)) {
                List<Integer> res = new ArrayList<Integer>(perm);

                // find the smallest number which is greater than i-1
                for (int j = len - 1; j >= i; j--) {
                    if (res.get(j) > res.get(i-1)) {
                        swap(res, j, i-1);
                        break;
                    }
                }

                // reverse the tailing numbers
                for (int low = i, high = len - 1; low < high; low++, high--) {
                    swap(res, low, high);
                }

                return res;
            }
        }

        return new ArrayList<Integer>();
    }

    private void swap(List<Integer> list, int i, int j) {
        int tmp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, tmp);
    }

    private static <T> void printList(List<T> list) {
        for (T t : list) {
            System.out.print(t);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        NextPermutation612 permutation = new NextPermutation612();
        List<Integer> perm = new ArrayList<Integer>();
        perm.add(1);
        perm.add(0);
        perm.add(3);
        perm.add(2);
        
        printList(perm);
        printList(permutation.next(perm));
        System.out.println();

        perm = new ArrayList<Integer>();
        perm.add(3);
        perm.add(2);
        perm.add(1);
        perm.add(0);
        
        printList(perm);
        printList(permutation.next(perm));
        System.out.println();
    }
}
