
//dieties ... for the Council members

#include <std.h>
#include <druids.h>
#include "/d/shadowgate/diety.h"

inherit ABILITIES_DIR+"is_allowed.c";

void cmd_dieties();

string *names;

void cmd_dieties(){
    int inc;
        if (!is_allowed_wizard(TPTN))
	  { return 0; }
        names = keys(DIETYS);
	write("%^GREEN%^Dieties Name         Sphere of Control");
	write("%^BLUE%^------------         -------------------");
	for(inc = 0; inc < sizeof(names = keys(DIETYS));inc ++)
	write(sprintf("%%^CYAN%%^%-20s %%^GREEN%%^%s",capitalize(names[inc]),capitalize(DIETYS[names[inc]])));
	return 1;
}
