import java.util.ArrayList;
/**
 * Display the data in three columns 
 * @author Garth-Work
 *
 */
public class ThreeColumnTable_Observer implements Observer {
	/**
	 * Subject that is tracked
	 */
	private Subject sub;
	/**
	 * The array of data 
	 */
	private ArrayList<Double> arr;
	
	public ThreeColumnTable_Observer(Subject mydata) {
		sub = mydata;
		sub.registerObserver(this);
	}

	@Override
	public void update(ArrayList<Double> arr) {
		this.arr = arr;
		display();
	}
	/** 
	 * Display data in three columns 
	 */
	private void display() {
		System.out.println("\nNotification to Three-Column Table Observer: Data Changed:");
		int i;
		for(i = 0; i < arr.size()-2; i+=3) {
			System.out.println(arr.get(i) + "     " + arr.get(i +1) + "     " + arr.get(i+2));
		}
		while(i < arr.size()) {
			System.out.print(arr.get(i++) + "     " );
		}
		System.out.println();
	}

}
