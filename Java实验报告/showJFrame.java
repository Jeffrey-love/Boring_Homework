import javax.swing.*;
import java.awt.*;

public class showJFrame {
    public static void main(String args[]) {
        showJFrame obj = new showJFrame();
        obj.testJFrame();
    }

    public void testJFrame() {
        JFrame frame = new JFrame("JAVATest");
        Container cotenPane = frame.getContentPane();
        cotenPane.setLayout(new FlowLayout());
        cotenPane.add(new JButton("SUBMIT"));
        cotenPane.add(new JTextField(10));
        frame.setSize(300, 200);
        frame.setVisible(true);
    }
}
