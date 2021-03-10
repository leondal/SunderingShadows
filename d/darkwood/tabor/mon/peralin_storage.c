#include <std.h>
inherit "/std/obj/fence_store_lesser";

void create(){
        ::create();
        set_property("no teleport",1);
        set_properties((["light":2,"indoors":1]));
        set_short("Raetsel's Storage Room");
        set_long("Better get out of here before Raetsel finds you.");
}

void reset() {
   ::reset();
   if(!present("lantern")) new("/d/common/obj/misc/beacon.c")->move(TO);
}
