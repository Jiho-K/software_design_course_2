import java.util.ArrayList;
/**
 * A subject with a array list of doubles
 * @author Garth-Work
 *
 */
public class DoubleArrayListSubject implements Subject {
	/**
	 * The data to be stored
	 */
	private ArrayList<Double> data;
	/**
	 * All observers tracking this data 
	 */
	private ArrayList<Observer> observers;	
	
	public DoubleArrayListSubject() {
		data = new ArrayList<Double>();
		observers = new ArrayList<Observer>();
	}
	/** 
	 * Add an entry to the list and notify all obervers 
	 * @param d Double to be added
	 */
	public void addData(double d) {
		data.add(d);
		notifyAllObervers();
	}
	/**
	 * Change a list entry and notify all observers 
	 * @param d Double to be added
	 * @param postion Postion to change
	 */
	public void setData(double d, int postion) {
		data.set(postion, d);
		notifyAllObervers();
	}
	/**
	 * Copy double array to array list 
	 * @param arr Array to be populated to array 
	 */
	public void populate(double[] arr){
		for(double d : arr) {
			data.add(d);
		}
		notifyAllObervers();
	}
	
	@Override
	public void registerObserver(Observer o) {
		observers.add(o);
		o.update(data);
	}

	@Override
	public void remove(Observer o) {
		observers.remove(o);
	}

	@Override
	public void notifyAllObervers() {
		for(Observer o: observers)
			o.update(data);
	}
	/**
	 * Display the list through all observers 
	 */
	public void display() {
		if(data.size() == 0)
		{
			System.out.println("Empty List ..");
		}
		else {
			notifyAllObervers();
		}
	}

}
