#include <std.h>
#include "../juran.h"

inherit "/d/common/inherit/wpn_storage_full.c";

void create() {
   	::create();
   	set_property("no teleport",1);
   	set_short("Juran Weapons Storage");
   	set_long("Juran Weapons Storage. You probably shouldn't be here.");
    	set_exits( (["up" : JROOMS+"ws"]) );
}

void reset() {
::reset();
}
