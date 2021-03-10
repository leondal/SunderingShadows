#include <std.h>
#include "../tormdefs.h"
inherit VAULT;
void create()
  {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("indoors",1);
   set_short("Entrance to Torm's Church");
  set_long(
   "  This is the entrance to the church in the city of Torm.  It is fairly quiet here and you get the impression that it isn't used much."+
   "  Although the outside was impressive with statues and other ornate architecture, the inside is rather plain."
   "  There aren't many religious symbols around at all, but someone keeps the place relatively free of dust."
   "  The floor is made of simple stone tiles and the walls are also solid stone with only a few openings towards the top of the walls to allow light through."
 );
   set_smell("default","There is a faint musky smell that has invaded the room.");
   set_listen("default","Everything is peacefully quiet.");
  set_exits(([
  "west":TCITY+"c72",
  "east":TCITY+"c101b",
  ]));
  set_property("light",2);
  set_door("door",TCITY+"c72","west","Torm masterkey");
  set_open("door",1);

}
