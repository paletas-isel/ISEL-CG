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

        int m = (end.y - start.y) / (end.x - start.x);
		int dx=end.x-start.x, dy=end.y-start.y;
		 
		int e=0;
		int y=start.y;
		int x=start.x;			  
		 
		for( ; x < end.x; ++x)
		{	
			dc.writePixel(x,y,color); 
			e+=dy; 				
			if(2*e >= dx)
		    {
			    ++y;
			    e-=dx;	
			}
		}		
	}

    ,
}
