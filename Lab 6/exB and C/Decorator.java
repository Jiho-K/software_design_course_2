// abstract class used to implement component. This will be used as the parent class to many different classes.
public abstract class Decorator implements Component {
  protected Decorator dec = null;
  protected Component cmp;
  protected int x;
  protected int y;
  protected int width;

  public int height;

   // constructor
  Decorator(Component com, int a, int b, int c, int d) {
    cmp = com;
    x = a;
    y = b;
    width = c;
    height = d;
  }
}
