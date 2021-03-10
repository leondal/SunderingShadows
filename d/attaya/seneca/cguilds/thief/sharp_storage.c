#include <std.h>
inherit "/std/obj/fence_store_epic";

void create(){
    ::create();
    set_property("no teleport",1);
    set_properties((["light":2,"indoors":1]));
    set("short","thief storage");
    set("long","If you're here you shouldn't be");
}

void reset() {
   object ob;
   ::reset();
   if(!present("lantern")) new("/d/common/obj/misc/beacon.c")->move(TO);
   if(!present("dark lantern")) new("/d/common/obj/misc/darkbeacon.c")->move(TO);
}
