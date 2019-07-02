package com.company;

import javax.swing.*;
import java.awt.*;

public class Window extends JFrame{
    private JTextField textField1 = new JTextField();
    private JButton createGraphButton = new JButton("press");
    private JButton readFromFileButton = new JButton("read");
    private JButton addVertexButton;
    private JButton addEdgeButton;
    private JButton topSortButton;
    private JButton stepButton;
    private JTextPane textPane1;
    public Window(){
        Container container = this.getContentPane();
        container.setLayout(new GridLayout(3, 3, 2, 2));
        textField1.setText("gergerger");
        createGraphButton.setAlignmentX(0);
        createGraphButton.setAlignmentY(0);
        createGraphButton.setPreferredSize(new Dimension(100, 100));
        container.add(createGraphButton);
        container.add(readFromFileButton);

    }
}
