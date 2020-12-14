/*
 * ENSF 480 Lab 5 Jiho Kim
 */

import java.util.ArrayList;

// use SelectionSort to sort ArrayList
public class SelectionSorter<E extends Number & Comparable<E>> implements Sorter<E> {

    @Override
    public void sort(ArrayList<Item<E>> vec) {

        int min;


        // One by one move boundary of unsorted subarray  
        for (int i = 0; i < vec.size() - 1; i++) {
            // Find the minimum element in unsorted array  
            min = i;
            for (int j = i + 1; j < vec.size(); j++) {
                if (vec.get(j).getItem().compareTo(vec.get(min).getItem()) < 0) {
                    min = j;
                }
            }
            
            Item<E> temp = vec.get(i);
            vec.set(i, vec.get(min));
            vec.set(min, temp);
            
        } 
    }
}
