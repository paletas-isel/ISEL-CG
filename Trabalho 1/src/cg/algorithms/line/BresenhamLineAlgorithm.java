package cg.algorithms.line;

import cg.GUI.IRasterDevice;

import java.awt.*;

public class BresenhamLineAlgorithm implements IScanLineAlgorithm 
{

	public void drawLine(IRasterDevice dc, Point start, Point end) 
	{
		drawLine(dc,start,end,Color.BLACK); 

	}
	
	public void drawLine(IRasterDevice dc, Point start, Point end, Color color) 
	{
        double dec = getGradient(start, end);

        if(isBefore(end, start, dec)) {
            Point temp = end;
            end = start;
            start = temp;
        }

		int dx = end.x - start.x;
        int dy = end.y - start.y;
		 
		int e=0;

        int dif;

        if(dy < 0 || dx < 0) {
            dif = -1;
            if(dy < 0)
                dy *= -1;
            else
                dx *= -1;
        }
        else
        {
            dif = 1;
        }

        if(dec >= -1 && dec <= 1)
            iterateByX(dc, color, start, end, dx, dy, e, dif);
        else
            iterateByY(dc, color, start, end, dx, dy, e, dif);

    }

    private void iterateByX(IRasterDevice dc, Color color, Point start, Point end, int dx, int dy, int e, int dif) {
		int y = start.y;
		int x= start.x;

        for( ; x < end.x; ++x)
        {
            dc.writePixel(x, y, color);

            e+=dy;
            if(2*e >= dx)
            {
                y += dif;
                e-=dx;
            }
        }
    }

    private void iterateByY(IRasterDevice dc, Color color, Point start, Point end, int dx, int dy, int e, int dif) {
        int y = start.y;
        int x= start.x;

        for( ; y < end.y; ++y)
        {
            dc.writePixel(x, y, color);

            e+=dx;
            if(2*e >= dy)
            {
                x += dif;
                e-=dy;
            }
        }
    }


    private double getGradient(Point start, Point end) {
        return (end.getY() - start.getY()) / (end.getX() - start.getX());
    }

    private boolean isBefore(Point initial, Point after, double dec) {
        if(dec >= -1 && dec <= 1)
            return initial.getX() < after.getX();
        else
            return initial.getY() < after.getY();
    }
}
