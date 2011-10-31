package cg.algorithms.circle;

import cg.GUI.IRasterDevice;
import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.awt.*;

public class MidPointCircleAlgorithm implements ICircleAlgorithm {

	/**
	 * Método que tira partido da simetria do circulo
	 * Calcula um dos octantes o pixel correspondete, de acordo
	 * com 1º Octante (x,y)
	 * 
	 * */
	private void writeCirclePixel(IRasterDevice dc,int x,int y, Color color, Point center)
	{
		dc.writePixel(+ x + center.x, + y + center.y, color);
		dc.writePixel(+ y + center.x, + x + center.y, color);
		dc.writePixel(+ y + center.x, - x + center.y, color);
		dc.writePixel(+ x + center.x, - y + center.y, color);
		dc.writePixel(- x + center.x, - y + center.y, color);
		dc.writePixel(- y + center.x, - x + center.y, color);
		dc.writePixel(- y + center.x, + x + center.y, color);
		dc.writePixel(- x + center.x, + y + center.y, color);
	}
	public void drawCircle(IRasterDevice dc, Point center, int radius) {
		drawCircle(dc, center, radius, Color.BLACK);
	}

	public void drawCircle(IRasterDevice dc, Point center, int radius,Color color) 
	{
		int x=0;
		int y=radius;
		int d=1-radius;
		
		writeCirclePixel(dc,x,y,color, center);
		while( y > x)
		{
			if(d<0) //choose E
			{
				d+=2*x+3;
			}
			else
			{
				d+=2*(x-y)+5;
				--y;				
			}
			++x;
			writeCirclePixel(dc,x,y,color, center);
		}

	}

	public void fillCircle(IRasterDevice dc, Point center, int radius) {
		fillCircle(dc, center, radius, Color.BLACK);
	}
	public void fillCircle(IRasterDevice dc, Point center, int radius, Color color) {
		throw new NotImplementedException();
	}

}
