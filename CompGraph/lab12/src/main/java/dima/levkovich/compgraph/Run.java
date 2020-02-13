package dima.levkovich.compgraph;
import javax.swing.*;
public class Run extends Thread{
    @Override
    public void run() {
        JFrame jFrame = new MainWindow();
        jFrame.pack();
        jFrame.setVisible(true);

    }

}
