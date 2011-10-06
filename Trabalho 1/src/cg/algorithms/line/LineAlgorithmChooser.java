package cg.algorithms.line;

import java.util.Dictionary;
import java.util.Enumeration;
import java.util.Hashtable;


public final class LineAlgorithmChooser {

	private static Dictionary<String, IScanLineAlgorithm> algorithms = new Hashtable<String, IScanLineAlgorithm>();
	
	static {		
		algorithms.put("Basic Scan", new BasicScanLineAlgorithm());
		//algorithms.put("MidPoint", new MidPointLineAlgorithm());
		algorithms.put("Bresenham", new BresenhamLineAlgorithm());
	}
	
	public static Enumeration<String> getAvailableAlgorithms() {
		return algorithms.keys();
	}
	
	public static String getDefaultAlgorithmName() {
		return "Basic Scan";
	}
	
	public static IScanLineAlgorithm getAlgorithm(String algName) {
		return algorithms.get(algName);
	}
	
	public static IScanLineAlgorithm getDefaultAlgorithm() {
		return algorithms.get(getDefaultAlgorithmName());
	}
	
	
	
}
