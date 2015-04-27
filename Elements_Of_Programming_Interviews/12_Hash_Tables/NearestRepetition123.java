import java.util.*;

public class NearestRepetition123 {
    private static class Pair<T> {
        private T first;
        private T second;

        public Pair(T first, T second) {
            this.first = first;
            this.second = second;
        }
    }

    public Pair<Integer> nearest(String[] strs) {
        if (strs == null) return null;

        Pair<Integer> result = null;
        int minDist = Integer.MAX_VALUE;
        Map<String, Integer> words = new HashMap<String, Integer>();

        for (int i = 0; i < strs.length; i++) {
            String str = strs[i];
            if (words.containsKey(str)) {
                int index = words.get(str);
                int dist = i - index;
                if (dist < minDist) {
                    if (result == null) {
                        result = new Pair<Integer>(index, i);
                    } else {
                        result.first = index;
                        result.second = i;
                    }
                    minDist = dist;
                }
            }
            words.put(str, i);
        }

        return result;
    }

    public static void main(String[] args) {
        NearestRepetition123 repetition = new NearestRepetition123();
        String[] words = new String[] { "All", "work", "and", "no", "play", "makes", "for", "no", "work", "no",
            "fun", "and", "no", "results" };
        Pair<Integer> result = repetition.nearest(words);
        for (int i = 0; i < words.length; i++) {
            System.out.print(words[i] + " ");
        }
        System.out.println();
        System.out.println(result.first + "," + result.second);
    }
}
