//CNC hallways & rooms by Circe 6/1/04

#include <std.h>
#include "../include/tabor.h"

inherit VAULT;

void create() {
  ::create();
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_name("Hallway of the Crown and Castle, Tabor");
  set_short("Hallway of the Crown and Castle, Tabor");
  set_long(
"%^BOLD%^Hallway of the Crown and Castle, Tabor%^RESET%^\n"+
"%^ORANGE%^This hallway has been fashioned of wood highly polished "+
"to a bright shine.  The planks are set close in a tongue and groove "+
"manner, providing ample insulation and making the hallway rather "+
"cozy.  A long, thin %^GREEN%^runner %^ORANGE%^edged in %^YELLOW%^"+
"thin gold braid %^RESET%^%^ORANGE%^cushions your footsteps, and a "+
"standing %^WHITE%^washstand %^ORANGE%^with a %^BOLD%^%^WHITE%^porcelain "+
"basin %^RESET%^%^ORANGE%^and %^BOLD%^%^WHITE%^pitcher %^RESET%^%^ORANGE%^"+
"has been placed at "+
"the far end of the hall.\n\n"+
"%^RESET%^From here, you can see the entryway back to the southwest, "+
"and two doorways are set into the northern side of the hall.\n"
  );
  set_smell("default","You smell a faint scent of wildflowers.");
  set_listen("default","You hear the muted babble of the socializing guests.");
  set_items(([
     ({"washstand","stand","basin","pitcher","flowers","irises","towels"}) : "The "+
        "stand seems is at the end of the hall.  You could go closer "+
        "for a better look.",
     ({"rug","runner"}) : "%^GREEN%^The runner covers the center of "+
        "the wooden floor, reaching all the way from one end to the "+
        "other.  It has been edged in %^YELLOW%^thin gold braid "+
        "%^RESET%^%^GREEN%^and seems worn in a few places, though "+
        "well-repaired."
  ]));
  set_exits( ([
    "southwest" : ROOMDIR+"cnchall",
    "north" : ROOMDIR+"guestroom1",
    "east" : ROOMDIR+"cnchall2"
  ]) );
  set_door("door",ROOMDIR+"guestroom1","north",0);
  set_door_description("door","This is a solid oak door carved with "+
     "the image of a crown hovering above a castle.");
}

void init(){
   ::init();
   add_action("wash_em","wash");
}

int wash_em(string str){
   tell_object(TP,"The basin is at the end of the hall.  You'll "+
      "need to go there before you do that.");
   return 1;
}