import javax.swing.*;
import java.awt.*;

public class TestJPanel {
    private void fillComponent(Container c) {
        for (int i = 1; i <= 3; i++)
            c.add(new JButton("°´Å¥" + i));
    }

    public TestJPanel() {
        JFrame frame = new JFrame("testJPanel");
        Container contentPane = frame.getContentPane();
        JPanel jp1 = new JPanel();
        fillComponent(jp1);
        jp1.setBackground(Color.CYAN);
        jp1.setForeground(Color.ORANGE)
        JPanel jp2 = new JPanel();
        fillComponent(jp2);
        jp2.setBackground(Color.LIGHT_GRAY);
        jp2.setForeground(Color.BLUE)
        contentPane.add(jp1, BorderLayout.WEST);
        contentPane.add(jp2, BorderLayout.EAST);

        frame.setSize(450, 100);
        frame.setVisible(true);
    }

    public static void main(String args[]){
        TestJPanel obj = new TestJPanel();

    }
}
