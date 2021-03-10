// /d/guilds/alliance/gate.c

#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_indoors(1);
   set_light(2);
   set_property("no teleport",1);
   set_short("At the Drawbridge gate");
   set_long(
@DESC
%^CYAN%^At the Drawbridge gate%^RESET%^
%^BOLD%^%^WHITE%^You are walking past the gate that secures the castle and 
controls the drawbridge. You see the iron gates hanging above 
your head. On each side you see a door that leads to the 
drawbridge control. In the ceiling you see a hole where archers 
can send arrows or rocks down at attacking troops. You also see 
a few torches on the wall.%^RESET%^
DESC
   );
   set_listen("default","The sound of the drawbridge chains fills the gate.");
   set_smell("default","You can smell a combination of iron, rock and torches.");
   set_exits(([
      "north":"/d/guilds/alliance/hall/yard.c",
      "south":"/d/guilds/alliance/hall/bridge.c",
   ]));
}
