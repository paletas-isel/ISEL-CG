package cg.algorithms.polygon;

import cg.GUI.IRasterDevice;
import cg.algorithms.triangle.ITriangleFillAlgorithm;
import cg.algorithms.triangle.TriangleAlgorithmChooser;

import java.awt.*;
import java.util.LinkedList;

public class ConvexPolygonFillAlgorithm implements IPolygonFillAlgorithm
{
	public void fillPolygon(IRasterDevice dc, Point[] points, Color[] colors) 
	{
        LinkedList<Triangle> triangleList = DivideInTriangles(points, colors);

        ITriangleFillAlgorithm algorithm = TriangleAlgorithmChooser.getDefaultAlgorithm();

        for(Triangle t : triangleList) {
            algorithm.fillTriangle(dc, t._p1, t._p2, t._p3, t._p1Color, t._p2Color, t._p3Color);
        }
	}

    private LinkedList<Triangle> DivideInTriangles(Point[] points, Color[] colors) {
        LinkedList<Triangle> triangles = new LinkedList<Triangle>();

        int nrOfTriangles = points.length - 2;
        Point centralDivisionPoint = points[0];
        Color centralDivisionColor = colors[0];
        Point firstPoint, secondPoint;
        Color firstColor, secondColor;

        for(int i = 1; triangles.size() < nrOfTriangles; i++) {
            firstPoint = points[i];
            secondPoint = points[i + 1];

            firstColor = colors[i];
            secondColor = colors[i + 1];

            triangles.add(new Triangle(centralDivisionPoint, firstPoint, secondPoint, centralDivisionColor, firstColor, secondColor));
        }

        return triangles;
    }


}
