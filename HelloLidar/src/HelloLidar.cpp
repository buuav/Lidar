#include <time.h>
#include <urg_sensor.h>
#include <urg_utils.h>
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
	urg_t urg;
	int ret;
	long *length_data;
	int length_data_size;

	// "COM1", it is necessary to the device name sensor is recognized
	const char connect_device[] = "/dev/ttyACM0";
	const long connect_baudrate = 115200;

	// make a connection to the sensor.
	ret = urg_open(&urg, URG_SERIAL, connect_device, connect_baudrate);
	// \todo check error code

	// To ensure the area for data reception
	length_data = (long *)malloc(sizeof(long) * urg_max_data_size(&urg));
	// \todo check length_data is not NULL

	// get the distance data from the sensor.
	ret = urg_start_measurement(&urg, URG_DISTANCE, 1, 0);
	// \todo check error code

	length_data_size = urg_get_distance(&urg, length_data, NULL);
	// \todo process length_data array

	// close the connection to the sensor.
	urg_close(&urg);

	for (int i = 0; i<length_data_size; i++){
		printf("%d,%d \n", i, length_data[i]);
	}

	return 0;
}
