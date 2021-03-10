// /d/guilds/alliance/treasure.c

#include <std.h>

inherit ROOM;

void create(){
   object ob;
   
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no teleport",1);
   set_indoors(1);
   set_light(2);
   set_short("Treasure room");
   set_long(
@DESC
%^YELLOW%^Treasure room%^RESET%^
%^BOLD%^%^WHITE%^This is a small room. In the far corner is a desk and an old 
man, who looks to be the bookie sits by it. He counts the gold
and values of the Alliance's storage. It seems like an 
overwhelming job and you wonder how he can keep count of all this 
gold, which is stored all around him. A few guards walk around 
the room.
DESC
   );
   set_listen("default","You hear the guards talking and the man counting, otherwise it's very quiet.");
   set_smell("default","You smell gold, lots of gold!");
   set_exits(([
      "west":"/d/guilds/alliance/hall/dungeon.c",
   ]));
}
