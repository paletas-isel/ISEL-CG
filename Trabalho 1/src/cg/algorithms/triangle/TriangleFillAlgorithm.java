package cg.algorithms.triangle;

import cg.GUI.IRasterDevice;

import java.awt.*;

public class TriangleFillAlgorithm implements ITriangleFillAlgorithm
{

	public void fillTriangle(IRasterDevice dc, Point p1, Point p2, Point p3, Color c1, Color c2, Color c3) 
	{
        for(int x = min(p1.x, p2.x, p3.x); x <= max(p1.x,p2.x,p3.x); ++x) {
            boolean wasIn = false;
            for(int y = min(p1.y, p2.y, p3.y); y <= max(p1.y, p2.y, p3.y); ++y) {
                float det = (((p2.y - p3.y) * (p1.x - p3.x)) + ((p3.x - p2.x) * (p1.y - p3.y)));

                float alpha = (float) (((p2.y - p3.y) * (x - p3.x)) + ((p3.x - p2.x) * (y - p3.y)))/det;
                float beta = (float) (((p3.y - p1.y) * (x - p3.x)) + ((p1.x - p3.x) * (y - p3.y)))/det;
                float gama = 1 - alpha - beta;

                if((alpha >= 0 && alpha <= 1) && (beta >= 0 && beta <= 1) && (gama >= 0 && gama <= 1)) {
                    wasIn = true;
                    dc.writePixel(x, y, shade(alpha, beta, gama, c1, c2, c3));
                }
                else if(wasIn)
                    break;
            }
        }
    }

    private int max(int p1, int p2, int p3) {
        return Math.max(Math.max(p1, p2), p3);
    }

    private int min(int p1, int p2, int p3) {
        return Math.min(Math.min(p1, p2), p3);
    }

    public Color shade(float alfa, float beta, float gama, Color cAlfa, Color cBeta, Color cGama){
		float r = (alfa * cAlfa.getRed()   + beta * cBeta.getRed()   + gama * cGama.getRed())   / 255.0f;
		float g = (alfa * cAlfa.getGreen() + beta * cBeta.getGreen() + gama * cGama.getGreen()) / 255.0f;
		float b = (alfa * cAlfa.getBlue()  + beta * cBeta.getBlue()  + gama * cGama.getBlue())  / 255.0f;
		r = Math.min(r, 1.0f);
		g = Math.min(g, 1.0f);
		b = Math.min(b, 1.0f);
		return new Color(r, g, b);
	}

}
