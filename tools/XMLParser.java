import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;


public class XMLParser {
	
	private static DocumentBuilderFactory docFactory = DocumentBuilderFactory.newInstance();
	private static DocumentBuilder docBuilder;

	public static Document readXMLFile(String fileName){
		try {
			docBuilder = docFactory.newDocumentBuilder();
		} catch (ParserConfigurationException e) {
			e.printStackTrace();
		}
		
		StringBuffer buffer = new StringBuffer();
		String text;
					
		FileReader freader;
		try {
	
			freader = new FileReader(fileName);
			
			BufferedReader in = new BufferedReader(freader);

			// read the text into the buffer line by line
			while((text = in.readLine()) != null)
				buffer.append(text + "\n");

			freader.close();
			text = new String(buffer);

			// produce a Document from the XML-input
			Document out;
			
			StringReader inStream = new StringReader(text);
			InputSource inSource = new InputSource(inStream);
			
			out = docBuilder.parse(inSource);
			 
			return out;
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			e.printStackTrace();
		}
			
		return null;
	}
	
	public static ArrayList<State> getStateList(Document doc){
		Element startState = (Element) doc.getElementsByTagName("startState").item(0);
		String start = startState.getAttribute("name");
		
		NodeList states = doc.getElementsByTagName("state");
		
		ArrayList<State> stateList = new ArrayList<State>();
		for(int i=0; i<states.getLength(); i++){
			String name = ((Element) states.item(i)).getAttribute("name");
			boolean accepting = ((Element) states.item(i)).getAttribute("accepting").equals("true");
			boolean isStart = name.equals(start);
			State s = new State(name,accepting,isStart);
			stateList.add(s);
		}
		return stateList;
	}
	
	public static ArrayList<Transition> getTransitionList(Document doc){
		NodeList transitions = doc.getElementsByTagName("transition");
		
		ArrayList<Transition> transList = new ArrayList<Transition>();
		for(int i=0; i<transitions.getLength(); i++){
			String begin = ((Element) transitions.item(i)).getAttribute("start");
			String end = ((Element) transitions.item(i)).getAttribute("end");
			String label = ((Element) transitions.item(i)).getAttribute("token");
			Transition t = new Transition(begin,end,label.charAt(0));
			transList.add(t);
		}
		return transList;
	}
}
