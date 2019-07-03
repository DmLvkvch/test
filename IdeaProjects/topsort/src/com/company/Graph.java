package com.company;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

public class Graph {
    private int VCount = 0;
    private int ECount = 0;
    private HashMap<Integer, Vertex> graph = new HashMap<>();//список смежности
    private LinkedList<Integer> vertexes = new LinkedList<>();
    public Graph(){}

    public void addV(int v){
        if(!graph.containsKey(v)){
            graph.put(v, new Vertex(v));
            vertexes.add(v);
            VCount++;
        }
        else
            throw new RuntimeException("already exists");
    }

    public void addE(int v1, int v2){
        if(!graph.containsKey(v1))
            addV(v1);
        if(!graph.containsKey(v2))
            addV(v2);
        graph.get(v1).way.add(v2);
        ECount++;
    }

    public void removeV(int v){
        if(graph.containsKey(v)) {
            graph.remove(v);
            vertexes.remove(new Integer(v));
            for (Map.Entry<Integer, Vertex> k :
                    graph.entrySet()) {
                if (k.getValue().way.contains(v)) {
                    k.getValue().way.remove((Integer) v);
                }
            }
            VCount--;
        }
        else
            return;
    }

    public void removeE(int v1, int v2){
        if(!vertexes.contains(v1))
            return;
        if(!vertexes.contains(v2))
            return;
        graph.get(v1).way.remove((Integer)v2);
    }

    public void print(){
        for (Map.Entry<Integer, Vertex> k:
                graph.entrySet()) {
            System.out.print(k.getKey()+"->");
            for(int i = 0;i<k.getValue().way.size();i++)
                System.out.print(k.getValue().way.get(i)+" ");
            System.out.println();
        }
        System.out.println("END");
    }

    public int V(){
        return VCount;
    }

    public LinkedList<Integer> VertexList(){
        return vertexes;
    }

    public int E(){
        int count = 0;
        for (Map.Entry<Integer, Vertex> k:
                graph.entrySet()) {
            count+=k.getValue().way.size();
        }
        ECount = count;
        return ECount;
    }

    public Vertex checkV(int v){
        return graph.get(v);
    }

    public int EdgesAtVertex(int v){
        return graph.get(v).way.size();
    }

}
