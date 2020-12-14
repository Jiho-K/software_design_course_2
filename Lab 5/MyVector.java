/*
 * ENSF 480 Lab 5 Jiho Kim
 */
 
import java.util.ArrayList;

class MyVector <E extends Number & Comparable<E> >{
	private ArrayList<Item<E>> storageM;
	private Sorter<E> sorter;
	
	// Constructor. Creates an ArrayList and allocates memory for size n.
	MyVector(int n) {
		storageM = new ArrayList<Item<E>>(n);
	}
	
	// Constructor. Copies values of ArrayList into storageM.
	MyVector(ArrayList<Item<E>> arr) {
		storageM = new ArrayList<Item<E>>(arr.size());
		for(int i = 0; i < arr.size(); i++){
			storageM.add( new Item(arr.get(i).getItem() ));
		}
	}
	
	// add a value into storageM.
	public void add(Item<E> value){
		storageM.add(value);
	}
	
	// set what you want to use to sort the ArrayList.
	public void setSortStrategy(Sorter <E> s) {
		sorter = s;
		return;
	}
	
	// sort StorageM using the sort strategy.
	public void performSort() {
		sorter.sort(storageM);
	}
	
	// show onto console values of StorageM.
	public void display() {
		for(Item<E> e: storageM) {
			System.out.print(e.getItem() + " ");
		}
	}
	
	
}