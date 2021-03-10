#include <std.h>
inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
    set_properties((["light":1, "indoors":1]));
    set_property("no teleport",1);
    set("short", "Torm's General Store Storage Room");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : "/d/dagger/Torm/city/c28"]) );
}

void reset() {
  ::reset();
   while(present("piece of paper")) present("piece of paper")->remove();
  if(!present("map"))
     new("/d/dagger/Torm/obj/map")->move(TO);
   while(!present("papyrus 10")) new("/d/dagger/Torm/obj/papyrus")->move(TO);
}
