/*
 * ENSF 480 Lab 5 Jiho Kim
 */
 
 import java.util.ArrayList;
 
 // interface to implement sorter.
 public interface Sorter <E extends Number & Comparable<E>> {
		public abstract void sort(ArrayList<Item <E>> vec);
 }