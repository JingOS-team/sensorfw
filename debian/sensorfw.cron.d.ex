#
# Regular cron jobs for the sensorfw package
#
0 4	* * *	root	[ -x /usr/bin/sensorfw_maintenance ] && /usr/bin/sensorfw_maintenance
