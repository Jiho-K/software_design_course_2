import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;
import java.awt.BasicStroke;
import java.awt.Color;

// used to display thick border that's red.
public class ColouredFrameDecorator extends Decorator{

  private int thickness;

  // normal constructor
  ColouredFrameDecorator(Component com, int a, int b, int c, int d, int e) {
    super(com, a, b, c, d);
    thickness = e;
  }

  // constructor for when another Decorator has to be shown.
  ColouredFrameDecorator(Decorator temp, int a, int b, int c, int d, int e) {
    super(temp.cmp, a, b, c, d);
    thickness = e;
    dec = temp;
  }

  public void draw(Graphics g) {
    if(dec != null) {
      dec.draw(g);
    }

    Graphics2D g2d = (Graphics2D) g;

    // save previous stroke style
    Stroke oldStroke = g2d.getStroke();
    Color oldColor = g2d.getColor();

    // set new stroke and draw rectangle
    g2d.setStroke(new BasicStroke(thickness));
    g2d.setColor(Color.red);
    g2d.drawRect(x, y, width, height);

    // set stroke back to what it was previously
    g2d.setStroke(oldStroke);
    g2d.setColor(oldColor);
  }
}
