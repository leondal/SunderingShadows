#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(RUTTED_TRACK);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Island on a lava sea%^RESET%^"  );
  set_long(
  "%^RED%^Island on a lava sea%^RESET%^\n"
  "  Overhead you can just faintly make out the black shiny roof with its dim reflected red facets but you still can't make out the walls to the north, south and west of the cavern."
  "  Far to the east you can see the edge of the cavern wall you emerged from as it soars up to the domed roof, 300 ft up."
  "  The path ends here on a outcropping of black obsidian that juts out of the lava."
  "  From here the only exit is back on the path to the west which looks more and more inviting as the sulfur and heat burns your lungs."
  "\n"
  );
  set_smell("default", "Your lungs burn with the head and harsh vapors."  );
  set_listen("default",
  "Nothing but silence, not even the stirring of the heavy oppressive air."
  );
  set_items(([
  "floor":"The path you stand on has widened into a island that is clear of everything.   The only ways you can go are to jump in the lava or head back west.",
  "path":"The path you stand on has widened into a island that is clear of everything.   The only ways you can go are to jump in the lava or head back west.",
  "lava":"It's everywhere, black striations on its surface and deep glowing red underneath.  Bubbles pop here and there and the heat is almost too much to withstand.  It calls to you and you feel the urge to jump in for some reason and feel its power.",
  "walls":"You can barely make out the west wall over the heat distortion and the odd lighting reflected from the lava below",

  "ceiling":"200 feet above you although the heat and odd lighting make it difficult to determine its actual height.",
  ]));
  set_exits(([
  "west":ROOMS"c15",
  ]));
// this is the Lava Rex and we do only want one per reboot
  new(MON"elemental.c")->move(TO);  
}

init(){
  ::init();
  add_action("jump_fun","jump");
}

int jump_fun(){
   tell_room(TO, "%^BOLD%^%^RED%^"+TPQCN+" stares into the lava then jumps off the path with a blank look in "+TP->query_possessive()+" eyes!", TP);
  write("You jump down off the edge into the lava sea!");
  TP->move_player(ROOMS"c29");
  return 1;
}
