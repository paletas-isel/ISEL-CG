package cg.algorithms.polygon;

import cg.GUI.IRasterDevice;
import cg.algorithms.triangle.TriangleAlgorithmChooser;

import java.awt.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

public class ConcavePolygonFillAlgorithm implements IPolygonFillAlgorithm
{

    private static double getAngle(Point a, Point b, Point c){  //Retorna sempre angulo interior do poligono
        double distAB = Math.sqrt(Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2));
        double distAC = Math.sqrt(Math.pow(a.x - c.x, 2) + Math.pow(a.y - c.y, 2));
        double distBC = Math.sqrt(Math.pow(b.x - c.x, 2) + Math.pow(b.y - c.y, 2));
        double angle =  Math.toDegrees(Math.acos((distAB * distAB + distBC * distBC - distAC * distAC) / (2 * distAB * distBC)));
        return isInteriorTriangle(a, b, c) ? angle : 180 + angle;
    }

    private static boolean isInteriorTriangle(Point a, Point b, Point c){
        return isLeftOrLine(a,b,getTriangleCenterPoint(a,b,c));
    }
    private static boolean isLeftOrLine(Point linePointA, Point linePointB, Point point){
         return ((linePointB.x - linePointA.x) * (point.y - linePointA.y) - (linePointB.y - linePointA.y) * (point.x - linePointA.x)) >= 0;
    }

    private static Point getTriangleCenterPoint(Point a, Point b, Point c){
        return new Point((a.x + b.x + c.x) / 3,(a.y + b.y + c.y) / 3);
    }


    private boolean isAnEar(ArrayList<Point> polygon, int pi) {
        int polySize = polygon.size();

        if(pi >= polySize || pi < 0 || polySize < 3) {
            return false;
        }

        int next = (pi == polySize - 1) ? 0 : pi + 1;
        int previous = (pi == 0) ? polySize - 1 : pi - 1;

        Point piP = polygon.get(pi);
        Point prevP = polygon.get(previous);
        Point nextP = polygon.get(next);

        Point d1 = new Point(piP.x - prevP.x, piP.y - prevP.y);
        Point d2 = new Point(nextP.x - piP.x, nextP.y - piP.y);

        float cross = d1.x * d2.y - d1.x * d2.y;

        if(cross > 0) return false;

        Triangle t = new Triangle(piP, nextP, prevP);

        for(int x = 0; x < polySize; ++x) {
            if(x == pi || x == previous || x == next) continue;
            if(t.isInTriangle(polygon.get(x))) return false;
        }

        return true;
    }

    private Triangle getTriangle(Point[] polygon, int pi) {
        Triangle t;

        int before = pi - 1;
        int after = pi + 1;

        if(pi == polygon.length - 1) {

            after = 0;
        }

        return new Triangle(polygon[before], polygon[pi], polygon[after]);
    }

    private Point[] filterTrianglePoints(Point[] polygon, Triangle t) {
        ArrayList<Point> newPoints = new ArrayList<Point>();

        for(Point p : polygon) {
            if(p.equals(t._p1) || p.equals(t._p2) || p.equals(t._p3)) continue;
            newPoints.add(p);
        }

        return newPoints.toArray(new Point[newPoints.size()]);
    }

    private LinkedList<Triangle> triangulatePolygon(Point[] points) {
        if(points.length < 3) return null;

        LinkedList<Triangle> triangles = new LinkedList<Triangle>();
        ArrayList<Point> polygon = new ArrayList<Point>();
        Collections.addAll(polygon, points);

        while(polygon.size() > 3) {

            int earIdx = -1;
            for(int ix = 0; ix < points.length; ++ix) {
                if(isAnEar(polygon, ix)) {
                    earIdx = ix;
                    break;
                }
            }

            if(earIdx == -1) return null;

            Point previous = polygon.get(((earIdx == 0) ? polygon.size() : earIdx) - 1);
            Point next = polygon.get((earIdx == polygon.size() - 1) ? 0 : earIdx + 1);
            Point current = polygon.get(earIdx);

            triangles.add(new Triangle(current, next, previous));

            polygon.remove(earIdx);
        }

        triangles.add(new Triangle(polygon.get(1), polygon.get(2), polygon.get(0)));

        return triangles;
    }

    public void fillPolygon(IRasterDevice dc, Point[] points, Color[] colors)
	{
        LinkedList<Triangle> triangles = triangulatePolygon(points);

        for(Triangle t : triangles) {
            TriangleAlgorithmChooser.getDefaultAlgorithm().fillTriangle(dc, t._p1, t._p2, t._p3, colors[0], colors[1], colors[2]);
        }
	}
	

}
