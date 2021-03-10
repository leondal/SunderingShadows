#include <std.h>
#include "../defs.h"
inherit "/std/obj/fence_store_lesser";

void create(){
        ::create();
        set_property("no teleport",1);
        set_properties((["light":0,"indoors":1]));
        set_short("Raetsel's Storage Room");
        set_long("Better get out of here before the immortals find you.");
   set_exits(([
     "out":ROOMS"thief",
   ]));
}

void reset() {
   ::reset();
   if(!present("dark lantern")) new("/d/common/obj/misc/darkbeacon.c")->move(TO);
}
