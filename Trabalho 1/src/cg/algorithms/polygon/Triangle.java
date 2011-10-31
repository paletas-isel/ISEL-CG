package cg.algorithms.polygon;

import java.awt.*;

public class Triangle {
    public Point _p1, _p2, _p3;
    public Color _p1Color, _p2Color, _p3Color;
    private float det;

    public static float alpha, beta, gama;

    public Triangle(Point p1, Point p2, Point p3, Color p1Color, Color p2Color, Color p3Color) {
        this(p1, p2, p3);

        _p1Color = p1Color;
        _p2Color = p2Color;
        _p3Color = p3Color;
    }

    public Triangle(Point p1, Point p2, Point p3) {
        _p1 = p1;
        _p2 = p2;
        _p3 = p3;

        det = (((_p2.y - _p3.y) * (_p1.x - _p3.x)) + ((_p3.x - _p2.x) * (_p1.y - _p3.y)));
    }

    public static boolean isInTriangle(Point p1, Point p2, Point p3, Point p) {
        float det = (((p2.y - p3.y) * (p1.x - p3.x)) + ((p3.x - p2.x) * (p1.y - p3.y)));

        alpha = (float) (((p2.y - p3.y) * (p.x - p3.x)) + ((p3.x - p2.x) * (p.y - p3.y)))/det;
        beta = (float) (((p3.y - p1.y) * (p.x - p3.x)) + ((p1.x - p3.x) * (p.y - p3.y)))/det;
        gama = 1 - alpha - beta;

        return (alpha >= 0 && alpha <= 1) && (beta >= 0 && beta <= 1) && (gama >= 0 && gama <= 1);
    }

    public boolean isInTriangle(Point p) {
        float alpha = (float) (((_p2.y - _p3.y) * (p.x - _p3.x)) + ((_p3.x - _p2.x) * (p.y - _p3.y)))/det;
        float beta = (float) (((_p3.y - _p1.y) * (p.x - _p3.x)) + ((_p1.x - _p3.x) * (p.y - _p3.y)))/det;
        float gama = 1 - alpha - beta;

        return (alpha >= 0 && alpha <= 1) && (beta >= 0 && beta <= 1) && (gama >= 0 && gama <= 1);
    }
}
