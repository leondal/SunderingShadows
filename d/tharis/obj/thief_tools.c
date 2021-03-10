#include <std.h>
inherit OBJECT;
void create(){
        ::create();
        set_name("Thief's tools");
        set_id(({"tools","thief toolx","lock picks","picks"}));
        set("short","Thief's tools");
        set_long(
@OLI
These are the tools of the trade for a thief.
They consist of wire and small tools for lock picking and such.
OLI
);
        set_value(30);
}
void break_picks(){
	TO->set_id(({"tools","broken tool","lock picks","picks"}));
	TO->set_long(
@OLI
	This is a set of thief's tools these. Normally they would consist of
many things useful in picking locks. These, however, appear to be broken.
OLI
);
	TO->set_value(0);
	
}
