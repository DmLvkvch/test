package com.company;

import java.awt.*;
import java.util.*;

class Vertex {
    public int v;
    public LinkedList<Integer> way = new LinkedList<>(); // смежные вершины
    public Vertex(int v) {
        this.v = v;
    }
}

class Graph{
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

//enum color{red, gree, bloe}

class TopSort{
    private Graph graph;
    private int V;
    private int E;
    private boolean[] used;
    private Stack<Integer> stack;

    public TopSort(Graph g){
        graph = g;
        V = g.V();
        E = g.E();
        used = new boolean[V+1];
        stack = new Stack<>();
        for(int i = 0;i<V+1;i++)
            used[i] = false;
    }

    private void DFS(int pos){
        used[pos] = true;
        System.out.println(pos);
        for(int i = 0;i<graph.checkV(pos).way.size();i++){
            if(!used[graph.checkV(pos).way.get(i)])
                DFS(graph.checkV(pos).way.get(i));
        }
        stack.push(pos);
    }

    void Alg(){
        for(int i = 0;i<V;i++){
            if(!used[i])
                DFS(i);
        }
        int k = stack.size();
        for(int i = 0;i<k;i++) {
            System.out.print(stack.peek() +1 + " ");
            stack.pop();
        }
    }
}

public class Main {

    public static void main(String[] args) {
	    Graph g = new Graph();
	    /*
	    g.addE(0, 1);
        g.addE(0, 2);
        g.addE(0 ,3);
        g.addE(0, 4);
        g.addE(1, 2);
        g.addE(2, 4);
        g.addE(3, 2);
        g.addE(3, 4);
	     */
        g.addE(5,5);
        g.addE(0, 1);
        g.addE(2 ,1);
        g.addE(3, 1);
        g.addE(1, 4);
        g.addE(5, 4);
        g.addE(3, 5);
        TopSort t = new TopSort(g);
        t.Alg();
        Window w = new Window();
        w.setVisible(true);
        w.setSize(200, 200);


    }
}
