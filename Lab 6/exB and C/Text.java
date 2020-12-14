import java.awt.Graphics;

// class used to show text.
public class Text implements Component {
  protected int x;
  protected int y;
  protected String text;

  Text(String message, int a, int b) {
    text = message;
    x = a;
    y = b;
  }

  public void draw(Graphics g) {

    g.drawString(text, x, y);
  }
}
