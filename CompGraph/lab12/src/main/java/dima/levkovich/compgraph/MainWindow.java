package dima.levkovich.compgraph;

import com.jogamp.opengl.GLCapabilities;
import com.jogamp.opengl.GLProfile;
import com.jogamp.opengl.awt.GLJPanel;

import javax.swing.*;
import java.awt.*;

class MainWindow extends JFrame {
    MainWindow(){
        super("Levkovich Dmitry");
        JPanel contentPanel = new JPanel();
        contentPanel.setLayout(new GridBagLayout());
        final GLProfile glProfile = GLProfile.getDefault();
        GLCapabilities glCapabilities = new GLCapabilities(glProfile);
        System.out.println("start");

        Renderer renderer = new Renderer();
        GLJPanel glJPanel = new GLJPanel(glCapabilities);
        glJPanel.addGLEventListener(renderer);
        JPanel panel = new Panel(glJPanel);
        GridBagConstraints constraints = new GridBagConstraints();
        constraints.fill = GridBagConstraints.HORIZONTAL;
        constraints.weightx = 0.5;
        constraints.gridy   = 0  ;
        setSize(900, 600);
        constraints.gridx = 0;
        contentPanel.add(panel, constraints);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        JPanel rightPanel = new RightPanel(glJPanel, renderer);
        constraints.gridx = 1;      // первая ячейка таблицы по горизонтали
        constraints.gridy = 0;
        constraints.gridheight = 2;
        contentPanel.add(rightPanel, constraints);
        add(contentPanel);
    }
}
