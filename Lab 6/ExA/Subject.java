/**
 * An interface for subject
 * @author Garth-Work
 *
 */
public interface Subject {
	/**
	 * Add an observer 
	 * @param o Observer to be addded 
	 */
	void registerObserver(Observer o);
	/**
	 * Remove an observer 
	 * @param o Observer to be removed 
	 */
	void remove(Observer o);
	/**
	 * Notify all obervers 
	 */
	void notifyAllObervers();
}
