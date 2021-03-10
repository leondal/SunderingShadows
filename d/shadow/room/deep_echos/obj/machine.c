#include <std.h>
inherit OBJECT;
void create() {
        ::create();
    set_id( ({"machine"}) );
    set_name("machine");
    set("short", "A gnomish mining machine");
set("long",
@OLI
This steam powered brass and wood contraption appears
to be a mining tool of sorts.  However there is a 
drill missing off the front.  It doesn't seem 
like it is working right now.
OLI
);
    set_weight(10000);
	set_property("no animate", 1);
    set_value(2);
    }
