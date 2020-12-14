import java.util.ArrayList;
/**
 * Display data in five rows 
 * @author Garth-Work
 *
 */
public class FiveRowsTable_Observer implements Observer{
	/**
	 * Subject that is tracked
	 */
	private Subject sub;
	/**
	 * The array of data 
	 */
	private ArrayList<Double> arr;
	
	public FiveRowsTable_Observer(Subject mydata) {
		sub = mydata;
		sub.registerObserver(this);
	}

	@Override
	public void update(ArrayList<Double> arr) {
		this.arr = arr;
		display();
	}
	/**
	 * Display the data in five rows 
	 */
	private void display() {
		System.out.println("\nNotification to FiveRowsTable Observer: Data Changed:");
		
		ArrayList<ArrayList<Double>> temp = new ArrayList<ArrayList<Double>>();
		
		for(int i = 0; i<5; i++) {
			temp.add(new ArrayList<Double>());
		}
		
		for(int i = 0; i < arr.size(); i++) {
			temp.get(i%5).add(arr.get(i));
		}

		for(int i = 0; i<5; i++) {
			for( double d : temp.get(i)) {
				System.out.print(d + "  ");
			}
			System.out.println();
		}
		
		System.out.println();
	}

}
