package dima.levkovich.compgraph;

import com.jogamp.opengl.GL2;

import java.util.HashMap;
import java.util.Map;

class Primitives{
    private static String[] list = {"GL_POINTS", "GL_LINES", "GL_LINE_STRIP","GL_LINE_LOOP", "GL_TRIANGLES", "GL_TRIANGLE_STRIP",
            "GL_TRIANGLE_FAN", "GL_QUADS", "GL_QUAD_STRIP", "GL_POLYGON"};
    private static Map<String, Integer> map = new HashMap<>();

    static {
        map.put("GL_POINTS", GL2.GL_POINTS);
        map.put("GL_LINES", GL2.GL_LINES);
        map.put("GL_LINE_STRIP", GL2.GL_LINE_STRIP);
        map.put("GL_LINE_LOOP", GL2.GL_LINE_LOOP);
        map.put("GL_TRIANGLES", GL2.GL_TRIANGLES);
        map.put("GL_TRIANGLE_STRIP", GL2.GL_TRIANGLE_STRIP);
        map.put("GL_TRIANGLE_FAN", GL2.GL_TRIANGLE_FAN);
        map.put("GL_QUADS",GL2.GL_QUADS);
        map.put("GL_QUAD_STRIP", GL2.GL_QUAD_STRIP);
        map.put("GL_POLYGON", GL2.GL_POLYGON);
    }

    static String[] getPrimitives(){
        return list;
    }

    static Integer getCodeOfPrimitive(String string){
        return map.get(string);
    }
}
