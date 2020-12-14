/*
 * ENSF 480 Lab 5 Jiho Kim
 */
 
 import java.util.ArrayList;
 
 // use InsertionSort to sort ArrayList.
 public class InsertionSorter <E extends Number & Comparable<E>> implements Sorter<E> {
		@Override
		public void sort(ArrayList<Item <E>> vec)  
		{  
			Item<E> key;
			int j;  
			for (int i = 1; i < vec.size(); i++) 
			{  
				key = vec.get(i);  
				j = i - 1;

				while (j >= 0 && vec.get(j).getItem().compareTo(key.getItem()) > 0) 
				{  
					vec.set(j +1, vec.get(j));  
					j = j - 1;  
				}

				vec.set(j+1, key);  
			}  
		}  
 }
