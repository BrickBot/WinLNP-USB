/* robot3_6.c
*
* These messages are also used by the Java program robot3.Controller
*
* Messages, PC => RCX
* * R = reset, motor powers to 0 and motors to float
* S = stop (brake, full voltage to motors)
* Mxaybzc = Set motor state and speed, x=speed for A, a=state for A,
* y=speed for B, b=state for B...
* Ax = set motor A's power to the value of x (binary, 0..255)
* Bx = set motor B's power to the value of x (binary)
* Cx = set motor C's power to the value of x (binary)
* 1x = set motor A state to x, (0=off (float), 1=forward, 2=reverse, 3=brake)
* defined in robot.Controller.[FLOAT|FORWARD|REVERSE|BRAKE] )
* 2x = set motor B state to x
* 3x = set motor C state to x
*
* -----------------------------------------------------------------------------
*
*  by Motti Frimer 2003
*/

#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <lnp.h>
#include <dmotor.h>
#include <dsensor.h>
#include <time.h>
#include <lnp-logical.h>

unsigned char sensor_data[18];

unsigned char motor_A_speed;
unsigned char motor_A_dir;
unsigned char motor_B_speed;
unsigned char motor_B_dir;
unsigned char motor_C_speed;
unsigned char motor_C_dir;

unsigned char index;

#define Abs(x)	((x >= 0) ? x : -x)

int  index_out_A;
int  index_out_B;

int  rotation_sens_old_A;
int  rotation_sens_old_B;

unsigned int  wait;
int counter;


/* Brakes with all the motors */
void stop_robot() {
	motor_a_dir(brake);
	motor_b_dir(brake);
	motor_c_dir(brake);
	motor_a_speed(255);
	motor_b_speed(255);
	motor_c_speed(255);
}

void my_integrity_handler(const unsigned char *data, unsigned char len)
{
	if(data[0]=='S') {
		stop_robot();
	}
	else if(data[0]=='R') {
		motor_a_dir(off);
		motor_b_dir(off);
		motor_c_dir(off);
		motor_a_speed(0);
		motor_b_speed(0);
		motor_c_speed(0);
	}
	else if(data[0]=='M') {
		motor_a_dir(data[2]);
		motor_b_dir(data[4]);
		motor_c_dir(data[6]);
		motor_a_speed(data[1]);
		motor_b_speed(data[3]);
		motor_c_speed(data[5]);
	}
	else if(data[0]=='A') {
        	motor_a_speed(data[1]);
                motor_A_speed = data[1];
	}
	else if(data[0]=='B') {
		motor_b_speed(data[1]);
                motor_B_speed = data[1];
	}
	else if(data[0]=='C') {
		motor_c_speed(data[1]);
		motor_C_speed = data[1];
	}
	else if(data[0]=='1') {
		motor_a_dir(data[1] );
                motor_A_dir = data[1];
	}
	else if(data[0]=='2') {
		motor_b_dir(data[1] );
                motor_B_dir = data[1];
	}
	else if(data[0]=='3') {
		motor_c_dir(data[1] );
		motor_C_dir = data[1];
	}
	else if(data[0]=='I') {
		index = data[1];
	}

}



int main()
{
        motor_A_speed = 0;
        motor_A_dir = 0;
        motor_B_speed = 0;
        motor_B_dir = 0;
	motor_C_speed = 0;
	motor_C_dir = 0;

	index = 0;
	index_out_A = 0;
	index_out_B = 0;

	counter=0;

	rotation_sens_old_A = 0;
	rotation_sens_old_B = 0;

	wait = 500;


	ds_active(&SENSOR_1);  /* activates sensor on port 1 */
	ds_rotation_on(&SENSOR_1); /* activates rotation sensor on port 1 */
	ds_rotation_set(1,10); /* sets initial value that sensor returns */

	ds_active(&SENSOR_2);  /* activates sensor on port 2 */
	ds_rotation_on(&SENSOR_2); /* activates rotation sensor on port 2 */
	ds_rotation_set(2,10); /* sets initial value that sensor returns */



	lnp_integrity_set_handler(my_integrity_handler);
	lnp_logical_range(0);  // sets the transmitter mode to the short range

	while(1)
	{



		rotation_sens_old_A = ROTATION_1;
		rotation_sens_old_B = ROTATION_2;

		msleep(wait);

		sensor_data[0]='s';
		sensor_data[1]= (unsigned char)(ROTATION_1 & 0xFF);
		sensor_data[2]= (unsigned char)((ROTATION_1 & 0xFF00) >> 8);
                sensor_data[3]= (unsigned char)(ROTATION_2 & 0xFF);
		sensor_data[4]= (unsigned char)((ROTATION_2 & 0xFF00) >> 8);
                sensor_data[5]= (unsigned char)(TOUCH_3 & 0xFF);
		sensor_data[6]= (unsigned char)((TOUCH_3 & 0xFF00) >> 8);

                /* Motor data */
                sensor_data[7]= motor_A_speed;
		sensor_data[8]= motor_A_dir;
                sensor_data[9]= motor_B_speed;
		sensor_data[10]= motor_B_dir;
		sensor_data[11]= motor_C_speed;
		sensor_data[12]= motor_C_dir;


		/* Multiply by 2=(1/(wait/1000)) in order to compute the speed per sec */
               
		index_out_B=Abs(( ROTATION_2 - rotation_sens_old_B )*2);
                index_out_A=Abs(( ROTATION_1 - rotation_sens_old_A )*2);
                sensor_data[13]= (unsigned char)(index_out_A & 0xFF);
		sensor_data[14]= (unsigned char)((index_out_A & 0xFF00) >> 8);
		sensor_data[15]= (unsigned char)(index_out_B & 0xFF);
		sensor_data[16]= (unsigned char)((index_out_B & 0xFF00) >> 8);

		lnp_integrity_write(sensor_data, sizeof(sensor_data));

		if(TOUCH_3!=0)    //if sensor has been touched
		{
			motor_a_dir(rev);
			motor_b_dir(fwd);
			sleep(3);
			motor_a_dir(brake);
			motor_b_dir(brake);

		}



	}
	return 0;
}
