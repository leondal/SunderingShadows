// Logging
// Pator@ShadowGate
// May 15 1996

#include <druids.h>

void log_druids(object who);
void log_entrance(object who);

void log_druids(object who) { 
string str;
	str = capitalize((string)who->query_true_name());
	str+= "\n";
	write_file(DRUID_LOG_NEW, str); }

void log_entrance(object who) {
	string name, tmp;
	name = (string)who->query_true_name();
	tmp = "Name : "+capitalize(name);
	tmp += " diety : "+capitalize((string)who->query_diety());
	tmp += " sphere : "+capitalize((string)who->query_sphere());
	tmp += " time : "+ctime(time());
	tmp += "\n";
	write_file(DRUID_LOG_DATA, tmp);
	}
