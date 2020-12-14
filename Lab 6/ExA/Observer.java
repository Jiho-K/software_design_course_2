import java.util.ArrayList;
/**
 * The interface for an observer
 * @author Garth-Work
 *
 */
public interface Observer {
	/**
	 * Change the data stored
	 * @param arr Data to be changed to 
	 */
	void update(ArrayList<Double> arr);
}
