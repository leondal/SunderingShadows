#include <std.h>
#include <daemons.h>
inherit DAEMON;

int cmd_weather() {
	WEATHER_D->weather();
	return 1;
}
void help() {
    write(
"
%^CYAN%^NAME%^RESET%^

weather - display weather

%^CYAN%^DESCRIPTION%^RESET%^

This command will show the current area's weather.

%^CYAN%^SEE ALSO%^RESET%^

date, look
"
);
}
