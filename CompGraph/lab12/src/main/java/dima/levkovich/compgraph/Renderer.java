package dima.levkovich.compgraph;

import com.jogamp.opengl.*;

import static com.jogamp.opengl.GL.*;

public class Renderer implements GLEventListener {
    private int GLCode = GL2.GL_POINTS;
    private int scissor_x = 600, scissor_y = 600;
    private int AlphaCode = GL_NEVER;
    private float AlphaParam = 0f;
    private int sfactor = GL_ZERO, dfactor = GL_ZERO;
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
        gl2.glAlphaFunc(AlphaCode, AlphaParam);
        gl2.glEnable(GL2.GL_ALPHA_TEST);
        gl2.glEnable(GL_BLEND);
        gl2.glBlendFunc(sfactor, dfactor);
        gl2.glPointSize(2);
        gl2.glBegin (GLCode);
        float x = 0.1f;
        float y = 0.1f;
        int n = 12;
        for (int i = 0; i < n; i++) {
            float angle = (float)(2 * Math.PI * i / (n));
            float x_ = (float)(( -0.2 + Math.cos(angle) * 0.8 + x));
            float y_ = (float)(( -0.1 + Math.sin(angle) * 0.8 + y));
            gl2.glColor3f((float)1/(i+1),(float)2/(i+1),(float)3/(i+1));
            gl2.glVertex2f(x_, y_);
        }
        gl2.glEnd();
        gl2.glEnable(GL_BLEND);
        gl2.glDisable(GL2.GL_ALPHA_TEST);
        gl2.glDisable(GL2.GL_SCISSOR_TEST);
        gl2.glFlush();
    }

    public void reshape(GLAutoDrawable drawable, int x, int y, int width,
                        int height) {
        /* no action to be taken on reshape */
    }

}

