import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;
import java.awt.BasicStroke;

// this class is used to display the dashed border
public class BorderDecorator extends Decorator{

  // normal constructor
  BorderDecorator(Component com, int a, int b, int c, int d) {
    super(com, a, b, c, d);
  }

  // this constructor is used when another Decorator is used as a parameter. Displays the Decorator by setting dec.
  BorderDecorator(Decorator temp, int a, int b, int c, int d) {
    super(temp.cmp, a, b, c, d);
    dec = temp;
  }

  public void draw(Graphics g) {
    if(dec != null) {
      dec.draw(g);
    }

    Stroke dashed = new BasicStroke(3, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 0, new float[]{9}, 0);
    Graphics2D g2d = (Graphics2D) g;
    g2d.setStroke(dashed);

    g.drawRect(x,y,width,height);
  }
}
