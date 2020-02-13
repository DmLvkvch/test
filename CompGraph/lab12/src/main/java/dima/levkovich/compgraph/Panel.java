package dima.levkovich.compgraph;
import com.jogamp.opengl.awt.GLJPanel;

import javax.swing.*;
import java.awt.*;

class Panel extends JPanel {
    Panel(GLJPanel gljPanel){
        setPreferredSize(new Dimension(600, 600));
        gljPanel.setPreferredSize(new Dimension(600, 600));
        add(gljPanel);
        setBackground(Color.red);
    }
}
