// changed to inherit and have a chance of the troll turning up in them

#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
inherit CROOM;

int troll;

void create() {
    ::create();
   if(!random(5))
      troll = 1;
   if(troll)   
	set_monsters( ({ MON"troll" }), ({ 1 }) ); 
   set_repop(50);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
  set_property("indoors",1);
    set_short("A fisherman's hut");
    set_long( (: TO, "ldesc" :) );
    set_items(([
  "loft":"Nothing really up there except a bed and some minor personal effects.",
  "pallet":"Set up for a small child you would assume from the toys nearby.",
  "stove":"A small potbellied stove for maximum efficiency over a fireplace.",
  "kitchen": (: TO, "kitchen" :),
      ]));

    set_exits(([
      ]));

  set_listen("default","Seabirds chirp in the air outside.");
  set_smell("default", (: TO, "smell" :) );
}

void reset() {
   ::reset();
}

string kitchen() {
  if(!troll) {
     return("Small and well organized, someone spends a lot of time keeping it neat.");
  } else {
     return("It's an absolute mess and some of the mess looks like blood and pieces "
            "of raw and rotting flesh.");
  }
}

string smell() {
  if(!troll) {
    return("Salt sea air mixes with the smells of many types of cooking.");
  } else {
    return("You smell something rotten and disturbing.");
  }
}


string ldesc() {
  if(!troll) {
  return(  "%^CYAN%^"
    "  This small neat house is better than you expected for a fisherman's residence."
    "  It appears the fishing around these parts is more profitable than other places."
    "  A small kitchen stands to one side of the house."
    "  A loft above you has a bed and a small pallet is set up beside the stove."
  );
  }  else {
  return(  "%^ORANGE%^"
    "This small house is, or appears to have been, a fisherman's residence.  "
    "It appears the fishing around these parts has been more profitable than "
    "many, but this one looks ransacked and as though inhabited by something "
    "else recently.  A small kitchen stands to one side "
    "of the house and the food has been drug from cabinets and remnants are "
    "strewn about.  A loft above you has a bed and a small pallet, set up "
    "beside the stove, has been torn to shreds and a horrid stench emanates "
    "from it, perhaps from the rotting flesh on the bones lying nearby.\n"
  );
  }
}

