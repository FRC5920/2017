//this is for Logitech F310 controller
#include "WPILib.h"
#include "AHRS.h"
#include "Timer.h"
#include "Math.h"
#include <CameraServer.h>
//#include declares stuff

class Robot: public SampleRobot
{
	    //Declaration List
		VictorSP climber;//VictorSP refers to motor control type
	    VictorSP rightDrive;
	    VictorSP inBounder;
	    VictorSP shooter;
	    VictorSP leftDrive;
	    VictorSP inFeed;
	    VictorSP blender;
	    Joystick controller1, controller2;// only joystick
	    //Encoder encoder1, encoder2;
	    Timer t1, t2;
	    float leftSpeed = -.25, rightSpeed = .265;
	    //bool powerinBounder;
	    //AHRS *ahrs;
	    //const double kUpdatePeriod = 0.005; // 5milliseconds / 0.005 seconds.
	    //int autMode=0, lockedMode=2;
	    /*bool prevStateBtn1=controller1.GetRawButton(1);
	    bool prevStateBtn2=controller1.GetRawButton(2);
	    bool prevStateBtn3=controller1.GetRawButton(3);
	    bool prevStateBtn4=controller1.GetRawButton(4);*/
public:
   Robot():
        climber(8),//assign climber PWM port 8
        rightDrive(0),//Assigned PWM as shown
        inBounder(2),//Assigned PWM as shown
        shooter(7),//Assigned PWM as shown
        leftDrive(1),//Assigned PWM as shown
        inFeed(3),//Assigned PWM as shown
        blender (4),//Assigned PWM as shown
        controller1(0),//Named as Joytsicks so USB port #
        controller2(1)//Named as Joytsicks so USB port #
        //encoder1(0, 1, false, Encoder::k2X),
        //encoder2(2, 3, false, Encoder::k2X),
        //powerL(0.5),//limit switch power... not used yet
        //powerR(0.5),//limit switch power... not used yet
        //powerinBounder(0.5)//limit switch power... not used yet
        //ahrs(NULL)
{
	   /*SmartDashboard::PutString("DB/String 0", "Autonomous Mode:");
	   SmartDashboard::PutString("DB/String 1", "Left Side Gear: 1");
	   SmartDashboard::PutString("DB/String 2", "Center/Straight: 2");
	   SmartDashboard::PutString("DB/String 3", "Right Side Gear: 3");
	   SmartDashboard::PutString("DB/String 4", "To Lock: Press both");
	   SmartDashboard::PutString("DB/String 5", "Use Controller 2");//Clear selection
	   SmartDashboard::PutString("DB/String 6", "Button 1");
	   SmartDashboard::PutString("DB/String 7", "Button 2");
	   SmartDashboard::PutString("DB/String 8", "Button 3");
	   SmartDashboard::PutString("DB/String 9", "Button# & Button: 4");
	   SmartDashboard::PutBoolean("DB/LED 1", false);//Clear LEDs
	   SmartDashboard::PutBoolean("DB/LED 2", false);
	   SmartDashboard::PutBoolean("DB/LED 3", false);*/
	   //remm'd due to problems deploying while in match
}

	   void Autonomous()
	   {  //auto starts
		   t2.Reset();	//resetting timer
		   t2.Start();	//starting timer
		   t1.Reset();
		   t1.Start();
	           while(IsAutonomous() && IsEnabled())
	           {
	               //while(t2.Get()>0 && t2.Get()<1)
	               //{
	                  //SmartDashboard::PutNumber("t2", t2.Get());  //puts "t2" to smartdashboard for monitoring
	               //}
	               //______________________________________________________________________________________
//shooting BLUE
	         /*if(t1.Get()>0 && t1.Get()<3)
	           {
	              shooter.Set(.62);
	           }
	          else if(t1.Get()>3 && t1.Get()<12)
	           {
	              inFeed.Set(.65);
	              blender.Set(-.6);
	              inBounder.Set(.5);
	           }
	          else if(t1.Get()>12 && t1.Get()<12.85)
	           {
	        	 inBounder.Set(0);
	        	 shooter.Set(0);
	        	 inFeed.Set(0);
	        	 blender.Set(0);
	             leftDrive.Set(-.2);
	           }
	          else if(t1.Get()>13 && t1.Get()<15)
	          {
	        	  rightDrive.Set(rightSpeed);
	        	  leftDrive.Set(leftSpeed);
	          }
	          else
	           {
	             leftDrive.Set(0);
	             rightDrive.Set(0);
	           }*/
	               	 //_______________________________________________________________________________________
	               //______________________________________________________________________________________
//shooting RED
	         /*
	          * if(t1.Get()>0 && t1.Get()<3.5)
	           {
	              shooter.Set(.6);
	           }
	          else if(t1.Get()>3.5 && t1.Get()<12)
	           {
	              inFeed.Set(.65);
	              blender.Set(-.6);
	              inBounder.Set(.5);
	           }
	          else if(t1.Get()>12 && t1.Get()<12.85)
	           {
	        	 inBounder.Set(0);
	        	 shooter.Set(0);
	        	 inFeed.Set(0);
	        	 blender.Set(0);
	             rightDrive.Set(.4);
	           }
	          else if(t1.Get()>13 && t1.Get()<15)
	          {
	        	  rightDrive.Set(rightSpeed);
	        	  leftDrive.Set(leftSpeed);
	          }
	          else
	           {
	             leftDrive.Set(0);
	             rightDrive.Set(0);
	           }*/
	               	 //_______________________________________________________________________________________
	                 //______________________________________________________________________________________
//straight
	           /*if(t1.Get()>1 && t1.Get()<3.75)//Good time for 58 inch progression; goes 57.6 inches
	        //if "    " = this then "   " happens
	           {
	        		  rightDrive.Set(-.285);
	        		  leftDrive.Set(.25);
	           }
	           else
	        //if the first statement is wrong then this happens
	           {
	               rightDrive.Set(0);
	               leftDrive.Set(0);
	           }*/
	               //_______________________________________________________________________________________
//left side turn right
	           if(t1.Get()>1 && t1.Get()<3.05)//Good time for 58 inch progression; goes 57.6 inches
	           {
	              rightDrive.Set(-.3);
	        	  leftDrive.Set(.25);
	           }
	           else if(t1.Get()>3.5 && t1.Get()<5)//Good time for 60* turn
	           //"else if" is for multiple if  statements
	           {
	               rightDrive.Set(.28);  // Only right side moves for less error and better consistency
	               leftDrive.Set(0);
	           }
	           else if(t1.Get()>6.5 && t1.Get()<8.1)//Good time for 58 inch progression; goes 57.6 inches
	           {
	               rightDrive.Set(rightSpeed);
	               leftDrive.Set(leftSpeed);
	           }
	           else
	           {
	               rightDrive.Set(0);
	               leftDrive.Set(0);
	           }
	               //________________________________________________________________________________________________
//right side turn left
	          /*if(t1.Get()>1 && t1.Get()<2.95)//Good time for 58 inch progression; goes 57.6 inches
	          {
	              rightDrive.Set(rightSpeed);
	        	  leftDrive.Set(leftSpeed);
	          }
	          else if(t1.Get()>3.5 && t1.Get()<5)//Good time for 60* turn
	          {
	               rightDrive.Set(0);  // Only right side moves for less error and better consistency
	               leftDrive.Set(-.3);
	          }
	          else if(t1.Get()>6.5 && t1.Get()<8.1)//Good time for 58 inch progression; goes 57.6 inches
	          {
	               rightDrive.Set(rightSpeed);
	               leftDrive.Set(leftSpeed);
	          }
	          else
	          {
	               rightDrive.Set(0);
	               leftDrive.Set(0);
	          }*/
	               //________________________________________________________________________________________________
	           }
	       }  //auto ends

/*void Disabled()
{
   	while (IsDisabled()){}
};
  //Runs the motors with arcade steering.*/
	   //______________________________________________________________
  void RobotInit()
  {
	  CameraServer::GetInstance()->StartAutomaticCapture();
  };
    void OperatorControl()
    {
        //_____________________________________________________________________
//blender & inFeed drives
        while (IsOperatorControl() && IsEnabled())	//Teleop starts
        {
            if(controller1.GetRawButton(2)==true)	//Checking for button 3 on controller 1
            {
                inFeed.Set(.7);//fuel in
                Wait(.5);
                blender.Set(-.7);
            }
            else if(controller1.GetRawButton(1)==true)
            {
                inFeed.Set(-.8);//fuel out - consider for purposes of clearing of fuel for climbing

            }
            else
            {
            	inFeed.Set(0);
            	blender.Set(0);

            }
//Feeding help
            if(controller2.GetRawButton(2)==true)	//Checking for button 2 on controller 2
            {
                 inBounder.Set(.5);
            }
            else if(controller2.GetRawButton(1)==true)
            {
                //Clear code for the shooting system
                inBounder.Set(-.5);
            }
            else
            {
                inBounder.Set(0);
            }
            //_____________________________________________________________________
            //Shooter wheels
            if(controller2.GetRawButton(6)==true)	//Checking for button 8 on controller 2
                        {
                             shooter.Set(.62);
                            //Wait(2); //Allow shooter speed to get to maximum
                        }
                        else if(controller1.GetRawButton(7)==true)
                        {
                            shooter.Set(.62);
                        }
                        else
                        {
                            shooter.Set(0);
                        }
            //______________________________________________________________________
//climber
            if(controller2.GetRawButton(7) ==true)	//Checking for the slow button on controller 2
                 /*left joystick, forward & back*/
            			{
                        climber.Set(1);
                        }
            else if(controller2.GetRawButton(8) ==true)
            			{
                        climber.Set(.5);
                        }
            else
                        {
       			       climber.Set(0);
                        }



            //_____________________________________________________________________
//leftDrive
            if(fabs(controller1.GetRawAxis(5)) > 0.2)	//Checking for the left joystick on controller 1 (Fabs is how far you push the joystick
            			/*left joystick, forward & back*/
            			{
            			      leftDrive.Set(controller1.GetRawAxis(5) * .8);
            	        }
            			else
            			{
            			       leftDrive.Set(0);
            			}
//rightDrive
            if(fabs(controller1.GetRawAxis(1)) > 0.2)	//Checking for the right joystink on controller 1
            			 {
            			       rightDrive.Set(controller1.GetRawAxis(1) * -.8);
            			 }
            			else
            	         {
            			       rightDrive.Set(0);
            			 }
            //_____________________________________________________________________
            //SmartDashboard::PutNumber("Angle", ahrs->GetAngle());
            Wait(0.005);
        }
    }
};
START_ROBOT_CLASS(Robot);