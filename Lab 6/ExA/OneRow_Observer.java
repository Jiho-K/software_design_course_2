import java.util.ArrayList;
/**
 * Display the data in one row 
 * @author Garth-Work
 *
 */
public class OneRow_Observer implements Observer{
	/**
	 * Subject that is tracked
	 */
	private Subject sub;
	/**
	 * The array of data 
	 */
	private ArrayList<Double> arr;
	
	public OneRow_Observer(Subject mydata) {
		sub = mydata;
		sub.registerObserver(this);
	}

	@Override
	public void update(ArrayList<Double> arr) {
		this.arr = arr;
		display();
	}
	/**
	 * Display the data in one row
	 */
	private void display() {
		System.out.println("\nNotification to OneRow_Table Observer: Data Changed:");
		for(double d : arr)
			System.out.print(d + "  ");
		System.out.println();
	}
}
