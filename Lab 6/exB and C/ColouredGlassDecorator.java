import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Color;
import java.awt.AlphaComposite;

// class used to fill rectangle with a transparent background.
public class ColouredGlassDecorator implements Component{

  protected ColouredFrameDecorator cfd;
  protected int x;
  protected int y;
  protected int width;
  protected int height;

  ColouredGlassDecorator(ColouredFrameDecorator a, int b, int c, int d, int e) {
    cfd = a;
    x = b;
    y = c;
    width = d;
    height = e;
  }

  public void draw(Graphics g) {
    cfd.draw(g);
    Graphics2D g2d = (Graphics2D) g;
    g2d.setColor(Color.green);
    g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 1*0.1f));
    g2d.fillRect(x, y, width, height);
  }
}
