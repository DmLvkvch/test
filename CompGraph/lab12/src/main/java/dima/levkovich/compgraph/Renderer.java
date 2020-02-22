package dima.levkovich.compgraph;

import com.jogamp.opengl.*;

import static com.jogamp.opengl.GL.*;

public class Renderer implements GLEventListener {
    private int GLCode = GL2.GL_POINTS;
    private int scissor_x = 600, scissor_y = 600;
    private int AlphaCode = GL_NEVER;
    private float AlphaParam = 0f;
    private int sfactor = GL_ZERO, dfactor = GL_ZERO;
    private float alpha = 0.5f;
    Renderer(){

    }
    void setAlphaParam(float alphaParam) {
        AlphaParam = alphaParam;
    }

    void setAlphaCode(int alphaCode) {
        AlphaCode = alphaCode;
    }

    public void setSfactor(int sfactor) {
        this.sfactor = sfactor;
    }

    public void setDfactor(int dfactor) {
        this.dfactor = dfactor;
    }

    public void init(GLAutoDrawable drawable) {
        /* nothing to initiate yet */
    }

    public void dispose(GLAutoDrawable drawable) {
        /* nothing to dispose yet */
    }

    void setGLCode(int GLCode) {
        System.out.println(GLCode);
        this.GLCode = GLCode;
    }

    void setScissor_x(int scissor_x) {
        this.scissor_x = scissor_x;
    }

    void setScissor_y(int scissor_y) {
        this.scissor_y = scissor_y;
    }

    public void display(GLAutoDrawable glAutoDrawable) {
        GL2 gl2 = glAutoDrawable.getGL().getGL2();
        // gl2.glViewport(0, 0, 600, 600);
        gl2.glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        gl2.glScissor(0, 0, scissor_x, scissor_y);
        gl2.glEnable(GL2.GL_SCISSOR_TEST);
        gl2.glEnable(GL2.GL_ALPHA_TEST);
        gl2.glAlphaFunc(AlphaCode, AlphaParam);
        gl2.glEnable(GL_BLEND);
        gl2.glBlendFunc(sfactor, dfactor);
        gl2.glBegin (GLCode);
        gl2.glPointSize(2);
        float x = 0.1f;
        float y = 0.1f;
        int n = 12;
        for (int i = 0; i < n; i++) {
            float angle = (float)(2 * Math.PI * i / (n));
            float x_ = (float)(( -0.2 + Math.cos(angle) * 0.8 + x));
            float y_ = (float)(( -0.1 + Math.sin(angle) * 0.8 + y));
            gl2.glColor4f((float)1/(i+1),(float)2/(i+1),(float)3/(i+1), 0.5f);
            gl2.glVertex2f(x_, y_);
        }/*
        gl2.glColor4f(1, 0 ,0, 1);
        drawCircle(gl2, 0.1f, 0.1f);

        gl2.glColor4f(0, 1 ,0, 1);
        drawCircle(gl2, 0.1f, 0.3f);

        gl2.glColor4f(0, 0 ,1, 1);
        drawCircle(gl2, 0.1f, -0.3f);*/
        gl2.glEnd();
        gl2.glDisable(GL2.GL_SCISSOR_TEST);
        gl2.glDisable(GL2.GL_ALPHA_TEST);
        gl2.glDisable(GL_BLEND);
        gl2.glFlush();
    }

    private void drawCircle(GL2 gl2, float cx, float cy){
        float r = 0.3f;
        gl2.glBegin(GL2.GL_POLYGON);
        for(float t = 0f;t<2*Math.PI;t+=0.1){
            float x = r*(float)Math.cos(t);
            float y = r*(float)Math.sin(t);
            gl2.glVertex2f(x+cx, y+cy);
        }
        gl2.glEnd();
    }

    public void reshape(GLAutoDrawable drawable, int x, int y, int width,
                        int height) {
        /* no action to be taken on reshape */
    }

}
