#include <std.h>
#define RPATH "/d/shadow/room/city/cguild/paladin/"+
#define WPATH "/d/common/obj/weapon/"+
#define OPATH "/d/shadow/room/city/cguild/paladin/"+
inherit ROOM;
 
void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":0, "indoors":1]));
    set_property("no teleport", 1);
    set("short", "Paladin Storage Room");
    set("long", "Only supplies and such here.\n");
    set_exits( (["up" : RPATH "store"]) );
}
 
void reset() {
 
::reset();
if(!present("coif"))
 new( OPATH "hlycoif")->move(this_object());
if(!present("coif"))
 new( OPATH "hlycoif")->move(this_object());
if(!present("plate"))
 new( OPATH "hlyplate")->move(this_object());
 
if(!present("light lance"))
 new( WPATH "lhlance")->move(this_object());
if(!present("medium lance"))
 new( WPATH "mhlance")->move(this_object());
if(!present("heavy lance"))
 new( WPATH "hhlance")->move(this_object());
if(!present("jousting lance"))
 new( WPATH "jlance")->move(this_object());
}
