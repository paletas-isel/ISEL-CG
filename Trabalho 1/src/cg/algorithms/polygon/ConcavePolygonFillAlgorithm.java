package cg.algorithms.polygon;

import cg.GUI.IRasterDevice;
import cg.algorithms.triangle.TriangleAlgorithmChooser;

import java.awt.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

public class ConcavePolygonFillAlgorithm implements IPolygonFillAlgorithm
{
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

        float cross = d1.x * d2.y - d2.x * d1.y;

        if(cross < 0) { return false; }

        Triangle t = new Triangle(piP, nextP, prevP);

        for(int x = 0; x < polySize; ++x) {
            if(x == pi || x == previous || x == next) continue;
            if(t.isInTriangle(polygon.get(x))) return false;
        }

        return true;
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

        if(triangles == null) return;

        for(Triangle t : triangles) {
            TriangleAlgorithmChooser.getDefaultAlgorithm().fillTriangle(dc, t._p1, t._p2, t._p3, colors[0], colors[1], colors[2]);
        }
	}
	

}
