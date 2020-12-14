/*
 * ENSF 480 Lab 5 Jiho Kim
 */
 
 import java.util.ArrayList;
 
 // Use BubbleSort to sort ArrayList
 public class BubbleSorter <E extends Number & Comparable<E>> implements Sorter<E> {
		@Override
		public void sort(ArrayList<Item <E>> vec)
		{
			Item<E> temp;
			for (int i = 0; i < vec.size()-1; i++) {
				for (int j = 0; j < vec.size()-i-1; j++) {  
					if (vec.get(j).getItem().compareTo(vec.get(j+1).getItem()) > 0) {
						temp = vec.get(j);
						vec.set(j, vec.get(j+1));
						vec.set(j+1, temp);
					}
				}
			}
		}
 }