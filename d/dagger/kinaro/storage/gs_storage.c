#include "std.h"

inherit "/d/common/inherit/gs_storage";

void create() {
    ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set("short","A storage room for the general store.");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : "/d/dagger/kinaro/general"]) );
}

void reset() {
    object ob;
    ::reset();
    if(!present("pouch 2")) {
       ob = new("d/common/obj/misc/pouch");
       ob->set_size(1);
       ob->move(TO);
    }
}
