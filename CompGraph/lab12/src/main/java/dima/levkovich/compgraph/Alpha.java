package dima.levkovich.compgraph;

import com.jogamp.opengl.GL2;

import java.util.HashMap;
import java.util.Map;

class Alpha {
    private static String[] list = {"GL_NEVER", "GL_LESS", "GL_EQUAL","GL_LEQUAL", "GL_GREATER", "GL_NOTEQUAL",
            "GL_GEQUAL", "GL_ALWAYS"};
    private static Map<String, Integer> map = new HashMap<>();

    static {
        map.put("GL_NEVER", GL2.GL_NEVER);
        map.put("GL_LESS", GL2.GL_LESS);
        map.put("GL_EQUAL", GL2.GL_EQUAL);
        map.put("GL_LEQUAL", GL2.GL_LEQUAL);
        map.put("GL_GREATER", GL2.GL_GREATER);
        map.put("GL_NOTEQUAL", GL2.GL_NOTEQUAL);
        map.put("GL_GEQUAL", GL2.GL_GEQUAL);
        map.put("GL_ALWAYS",GL2.GL_ALWAYS);
    }

    static String[] getAlpha() {
        return list;
    }


    static Integer getCodeOfAlpha(String string){
        return map.get(string);
    }
}
