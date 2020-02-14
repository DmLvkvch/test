package dima.levkovich.compgraph;
import java.util.HashMap;
import java.util.Map;

import static com.jogamp.opengl.GL.*;

public class Blend {
    private static String[] sfactor = {"GL_ZERO", "GL_ONE", "GL_DST_COLOR", "GL_ONE_MINUS_DST_COLOR", "GL_SRC_ALPHA",
            "GL_ONE_MINUS_SRC_ALPHA", "GL_DST_ALPHA", "GL_ONE_MINUS_DST_ALPHA", "GL_SRC_ALPHA_SATURATE"};
    private static String[] dfactor = {"GL_ZERO", "GL_ONE", "GL_SRC_COLOR", "GL_ONE_MINUS_SRC_COLOR", "GL_SRC_ALPHA",
            "GL_ONE_MINUS_SRC_ALPHA", "GL_DST_ALPHA", "GL_ONE_MINUS_DST_ALPHA"};
    private static Map<String, Integer> sfactorMap = new HashMap<>();
    private static Map<String, Integer> dfactorMap = new HashMap<>();
    static {
        sfactorMap.put("GL_ZERO",GL_ZERO);
        sfactorMap.put("GL_ONE",GL_ONE);
        sfactorMap.put("GL_DST_COLOR", GL_DST_COLOR);
        sfactorMap.put("GL_ONE_MINUS_DST_COLOR", GL_ONE_MINUS_DST_COLOR);
        sfactorMap.put("GL_SRC_ALPHA", GL_SRC_ALPHA);
        sfactorMap.put("GL_ONE_MINUS_SRC_ALPHA", GL_ONE_MINUS_SRC_ALPHA);
        sfactorMap.put("GL_DST_ALPHA", GL_DST_ALPHA);
        sfactorMap.put("GL_ONE_MINUS_DST_ALPHA",GL_ONE_MINUS_DST_ALPHA);
        sfactorMap.put("GL_SRC_ALPHA_SATURATE", GL_SRC_ALPHA_SATURATE);

        dfactorMap.put("GL_ZERO",GL_ZERO);
        dfactorMap.put("GL_ONE",GL_ONE);
        dfactorMap.put("GL_SRC_COLOR", GL_SRC_COLOR);
        dfactorMap.put("GL_ONE_MINUS_SRC_COLOR", GL_ONE_MINUS_SRC_COLOR);
        dfactorMap.put("GL_SRC_ALPHA", GL_SRC_ALPHA);
        dfactorMap.put("GL_ONE_MINUS_SRC_ALPHA", GL_ONE_MINUS_SRC_ALPHA);
        dfactorMap.put("GL_DST_ALPHA", GL_DST_ALPHA);
        dfactorMap.put("GL_ONE_MINUS_DST_ALPHA",GL_ONE_MINUS_DST_ALPHA);
    }

    public static String[] getSfactor() {
        return sfactor;
    }

    public static String[] getDfactor() {
        return dfactor;
    }

    static Integer getCodeOfSfactor(String string){
        return sfactorMap.get(string);
    }

    static Integer getCodeOfDfactor(String string){
        return dfactorMap.get(string);
}
}
