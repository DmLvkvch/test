package dima.levkovich.compgraph;

import com.jogamp.opengl.awt.GLJPanel;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ItemEvent;

class RightPanel extends JPanel {

    RightPanel(GLJPanel gljPanel, Renderer renderer){
        JComboBox<String> comboBoxWithPrimitives = new JComboBox<>(Primitives.getPrimitives());
        //add(label);
       // this.setLayout(null);
        this.setPreferredSize(new Dimension(230,700));
        setBackground(Color.blue);
        comboBoxWithPrimitives.addItemListener(e -> {
            if (e.getStateChange() == ItemEvent.SELECTED) {
                String item = (String)e.getItem();
               // gljPanel.removeGLEventListener(renderer);
                renderer.setGLCode(Primitives.getCodeOfPrimitive(item));
                //gljPanel.addGLEventListener(renderer);
                gljPanel.repaint();

            }
        });
        add(comboBoxWithPrimitives);

       // add(comboBoxWithPrimitives)
        JSlider sliderX = new JSlider(0, 600, 0);
        sliderX.addChangeListener(e -> {
            int value = sliderX.getValue();
            renderer.setScissor_x(value);
            gljPanel.repaint();


        });
        add(sliderX);
        JSlider sliderY = new JSlider(0, 600, 0);
        sliderY.addChangeListener(e -> {
            int value = sliderY.getValue();
            renderer.setScissor_y(value);
            gljPanel.repaint();

        });
        add(sliderY);
        JComboBox<String> jComboBoxAlpha = new JComboBox<>(Alpha.geAlpha());
        jComboBoxAlpha.addItemListener(e -> {
            if (e.getStateChange() == ItemEvent.SELECTED) {
                String item = (String)e.getItem();
                // gljPanel.removeGLEventListener(renderer);
                renderer.setAlphaCode(Alpha.getCodeOfAlpha(item));
                //gljPanel.addGLEventListener(renderer);
                gljPanel.repaint();

            }
        });
        add(jComboBoxAlpha);
        JSlider sliderAlpha = new JSlider(0, 100, 0);
        sliderAlpha.addChangeListener(e -> {
            float value = (float)sliderAlpha.getValue()/100;
            System.out.println(value);
            renderer.setAlphaParam(value);
            gljPanel.repaint();

        });
        add(sliderAlpha);
    }

}
