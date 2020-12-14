import java.awt.Font;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class DemoDecoratorPattern extends JPanel {
	Component t;

    public DemoDecoratorPattern(){
   	 t = new Text ("Hello World", 60, 80);
   }

    public void paintComponent(Graphics g){
			// set font and show text on jpanel
 	    int fontSize = 10;
 	    g.setFont(new Font("Times New Roman", Font.PLAIN, fontSize));
			t = new Text ("Hello World", 60, 80);
			t.draw(g);

/*
 	    // Now lets decorate t with BorderDecorator: x = 30, y = 30, width = 100, and height 100
 	    t = new BorderDecorator(t, 30, 30, 100, 100);
			t.draw(g);
 	    // Now lets add a ColouredFrameDecorator with x = 25, y = 25, width = 110, height = 110,
 		// and thickness = 10.
 	    t = new ColouredFrameDecorator(t, 25, 25, 110, 110, 10);
*/

		// used to draw the border and fill the rectangle with green colour
		t = new ColouredGlassDecorator(new ColouredFrameDecorator(
				new BorderDecorator(t, 30, 30, 100, 100), 25, 25, 110, 110, 10), 25, 25, 110, 110
				);

 	    // Now lets draw the product on the screen
 	    t.draw(g);
    }

	public static void main(String[] args) {
        DemoDecoratorPattern panel = new DemoDecoratorPattern();
        JFrame frame = new JFrame("Learning Decorator Pattern");
        frame.getContentPane().add(panel);
        frame.setSize(400,400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
	}
}
