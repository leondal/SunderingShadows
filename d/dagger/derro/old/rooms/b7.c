#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
   set_name("Sharply sloping ramp");
  set_short(
  "%^RED%^%^Sharply sloping ramp%^RESET%^\n"
  );
  set_long(
  "%^RED%^%^Sharply sloping ramp%^RESET%^\n"
"  This patch of the ramp is dark, with the red glow from up to the west and down to the east further along not shedding much light here."
  "\n"
  );
  set_smell("default",
  "You get the occasional whiff of the scent of decaying flesh."
  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globe":"This globe looks like the other red ones but it appears to have stopped functioning and lays cold and dark.",
  "ceiling":"Damn near 25 feet at the peak from the floor, almost making it seem as if you're not actually far underground.  There is a dark globe mounted in the center of the ceiling.",
  ]));
  set_exits(([
  "east":ROOMS"b6",
  "west":ROOMS"b8",
  ]));
}
void init(){
  ::init();
  do_random_encounters(({
  MON"derro1.c",MON"derro2.c",MON"derro3.c"
  }),50,1);
}
