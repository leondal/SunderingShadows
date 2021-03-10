//moving comp shop. I would suggest
//using for other things as well

#include <std.h>
#include <move.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(HUT);
   set_travel(DIRT_ROAD);
   set_name("component shop");
   set_short("The Tent of the traveling Component sales man.");
   set_long(
@OLI
   This quietly furnished tent is much larger inside
than out. You can't imagine why. You look around and see
nothing that strikes you as valuable. Yet stories of old
ring constantly about the grand trader of components. This
man doesn't carry the common components. He only carries
the very best. There is a small chalked sign propped by the
entrance.
OLI
   );
   set_property("no teleport",1);
   set_property("light",2);
   set_property("indoors",1);
   set_exits(([]));
}

void reset(){
::reset();
if(!present("naccoom"))
new("/d/islands/tonerra/naccoom.c")->move(TO);
}

void init(){
::init();
add_action("read", "read");
}

int read(string str){
if(!str || (str != "sign")) return notify_fail("Read what?\n");

write(
    "The dark sign has faint chalk writing on it which reads:\n     Special components sold here.\n     The prices are high, if you have\n     no money go away.\n     <list> shows you what I have today.\n     <buy> buys them."
);
return 1;
}
