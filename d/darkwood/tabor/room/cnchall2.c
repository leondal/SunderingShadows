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
        "stand seems "+
        "to be made of %^ORANGE%^light oak%^RESET%^ and supports a "+
        "sturdy %^BOLD%^pitcher %^RESET%^and %^BOLD%^basin%^RESET%^, "+
        "both of which have been hand painted with %^MAGENTA%^wild "+
        "irises%^RESET%^.  A round %^CYAN%^mirror %^RESET%^hangs on "+
        "the wall just above the basin, braced on either side by "+
        "%^ORANGE%^wooden shelves%^RESET%^.  One shelf holds a vase "+
        "of %^MAGENTA%^irises%^RESET%^, while the old holds folded "+
        "%^BOLD%^%^BLUE%^hand towels%^RESET%^ and a small dish of "+
        "%^BOLD%^soap%^RESET%^.  Using these things, you could "+
        "probably %^BOLD%^%^CYAN%^wash%^RESET%^ in the basin.",
     ({"rug","runner"}) : "%^GREEN%^The runner covers the center of "+
        "the wooden floor, reaching all the way from one end to the "+
        "other.  It has been edged in %^YELLOW%^thin gold braid "+
        "%^RESET%^%^GREEN%^and seems worn in a few places, though "+
        "well-repaired."
  ]));
  set_exits( ([
    "west" : ROOMDIR+"cnchall1",
    "north" : ROOMDIR+"guestroom2"
  ]) );
  set_door("door",ROOMDIR+"guestroom2","north",0);
  set_door_description("door","This is a solid oak door carved with "+
     "the image of a crown hovering above a castle.");
}

void init(){
   ::init();
   add_action("wash_em","wash");
}

int wash_em(string str){
   if(!str){
      tell_object(TP,"You might want to try washing in the basin.");
      return 1;
   }
   if(str == "in basin" || str == "in the basin"){
      tell_object(TP,"Using the soap and lukewarm water, you scrub your "+
         "face and wash your hands, then rinse throroughly.  You dry "+
         "your hands and face on one of the warm towels on the shelf.  "+
         "Ahh...much better.  It feels good to get rid of that grime.");
      tell_room(ETP,""+TPQCN+" washes "+TP->QP+" face and hands in "+
         "the basin.",TP);
      TP->set("long");
      return 1;
   }
   tell_object(TP,"You want to wash where??");
   return 1;
}