package Appsurfer;
import com.xuggle.mediatool.IMediaReader;
import com.xuggle.mediatool.IMediaWriter;
import com.xuggle.mediatool.ToolFactory;
import com.xuggle.xuggler.*;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        System.out.println( "Hello World!" );
        IMediaReader reader = ToolFactory.makeReader("barsandtone.flv");
      IMediaWriter writer = ToolFactory.makeWriter("sample.mov",reader);
      reader.addListener(writer);
		 
      while(reader.readPacket()==null)
			 ;


    }
}
