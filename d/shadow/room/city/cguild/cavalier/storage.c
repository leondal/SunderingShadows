#include <std.h>
#include "/d/shadow/room/city/cguild/cavalier/cav.h"
inherit ROOM;
 
void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":0, "indoors":1]));
    set("short", "Cavalier Storage Room");
    set("long", "Only supplies and such here.\n");
    set_exits( (["up" : RPATH "store"]) );
}
 
void reset() {
 
::reset();
if(!present("light lance"))
 new( "/d/common/obj/weapon/lhlance")->move(this_object());
if(!present("medium lance"))
 new( "/d/common/obj/weapon/mhlance")->move(this_object());
if(!present("heavy lance"))
 new( "/d/common/obj/weapon/hhlance")->move(this_object());
if(!present("jousting lance"))
 new( "/d/common/obj/weapon/jlance")->move(this_object());
}
