import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.*;
import java.util.Random;
/*
<applet code="Brick_Breaker.class" width="1000" height="800">
</applet>
*/
//bl=board_length,(x,y)-for board and (x1,y1)-for ball,s-score,f-for random flag
//c-for score and levels and bl decrement,i-for bl decrement
public class Brick_Breaker extends Applet implements Runnable,ActionListener,MouseMotionListener{
	static int xmin=540,xmax=1164,ymin=170,x=700,y=500,x1=835,y1=470,flag=0;
        static int c=0,s=0,i=0,bl=280;
	Thread t;
        Button b,b1;
	boolean value=true;
        int f;
        Random rand;
	public void init(){
		t=new Thread(this);
		t.start();
                b=new Button("Start");
                b1=new Button("Stop");
                add(b);
                b.addActionListener(this);
                add(b1);
                b1.addActionListener(this);
                rand=new Random();
                f=rand.nextInt(4);                
        }
	public void paint(Graphics g){
                if(c==0 && flag==0){		
                    g.setFont(new Font(g.getFont().getFontName(), Font.PLAIN, 20));		
                    g.drawString("!! Welcome to Brick-Breaker Game . !!",860,540);
                    g.dispose();
                }
                //g.setColor(Color.green);
                g.setFont(new Font(g.getFont().getFontName(), Font.PLAIN, 20));
		g.fillRoundRect(x,y,bl,30,10,10);
		//g.setColor(Color.orange);
                g.fillOval(x1,y1,30,30);
                //g.setColor(Color.black);
                g.drawRect(534,169,630,365);
                g.drawString("x = "+x,845,870);
                g.drawString("Hits = "+c,840,895);
                g.drawString("x1 = "+x1+"  y1 = "+y1,790,920);
                /* For levels */
                g.drawString(" You have cleared level "+c/3,775,845);    
                g.drawString("Your score is :"+s,820,820);
                if(bl==30){
                    //r for fun
                    int r=1;
                    r++;
                    if(r>4){
                    g.setFont(new Font(g.getFont().getFontName(), Font.PLAIN, 20));
                    g.drawString("!! Congratulations Game Cleared. !!",760,880);
                    flag=4;
                    }
                }
                if(flag==4){
                    g.setFont(new Font(g.getFont().getFontName(), Font.PLAIN, 20));
                    g.drawString("Game Over",835,795);
                    try{
                    Thread.sleep(5000);
                    }
                    catch(Exception e){}
                    System.exit(1);
                }
                if(flag==5){
                    g.setFont(new Font(g.getFont().getFontName(), Font.PLAIN, 20));
                    g.drawString("Game Paused",835,795);
                }
	}
        public void check(){
            if(x1<=xmin || x1>=xmax){
                value=false;
                //genflag();
            }
            if(y1==ymin){
                value=false;
                //genflag();
            }
            if(x1==535 || x1==1115){
                value=false;
                //genflag();
            }
        }
        public void genflag(){
            f=rand.nextInt(4);
            if(f%3==0)
                flag=3;
            else if(f%2==0)
                flag=2;
            else if(f%1==0)
                flag=1;
        }
	public void run(){
		for(;;){
                    if(flag==1 && value){
                        y1-=30;
                    }
                    else if(flag==1 && !value){
			y1+=30;
                        //genflag();
                        check();
                    }
                    else if(flag==2 && value){
                        x1-=30;
                        y1-=30;
                    }
                    else if(flag==2 && !value){
                        x1+=30;
                        y1+=30;
                        //genflag();
                        check();
                    }
                    else if(flag==3 && value){
                        x1+=30;
                        y1-=30;
                    }
                    else if(flag==3 && !value){
                        x1-=30;
                        y1+=30;
                        //genflag();
                        check();
                    }
                    check();
                    if(ymin==y1){
                        value=false;
                        //genflag();
                        check();
                    }
                    else if(!value && flag!=0 && y1+30==y)
                        if(x1>=(x+15) && x1<=(x+bl+15)){
                            value=true;
                            c++;
                            s=c*10;
                            if(c%3==0 && c<=15){
                                i++;
                                bl-=(i*15);
                            }
                            if(c>15)
                                bl=30;
                            genflag();    
                            check();
                        }
                        else
                            flag=4;
                        try{
                            Thread.sleep(200);
			}
			catch(InterruptedException ie){}
			repaint();
		}
        }
    @Override
    public void mouseDragged(MouseEvent e) {
       x=e.getX();
       repaint();
    }
    @Override
    public void mouseMoved(MouseEvent e) {
       x=e.getX();
       if(x>=534 && x+bl<=1164)
           x=x;
       else
           x=700;
       repaint();
    }
    @Override
    public void actionPerformed(ActionEvent e){
        if(e.getActionCommand()=="Start"){
        genflag();
        check();
        addMouseMotionListener(this);
        }
        if(e.getActionCommand()=="Stop"){
            flag=5;
        }
        repaint();
    }
}