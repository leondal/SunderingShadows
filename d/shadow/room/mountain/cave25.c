//cave25.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "The smooth, %^BOLD%^%^BLACK%^dark gray walls %^RESET%^of this "+
      "tunnel through Echoes Mountains seem "+
      "partially naturally carved.  Some signs of fantastic "+
      "workmanship suggest "+
      "that the dwarves who make their home here have expanded and "+
      "improved upon "+
      "nature's beauty.  The %^BOLD%^%^BLUE%^vaulted ceilings "+
      "%^RESET%^are supported and decorated by "+
      "%^YELLOW%^archways %^RESET%^carved of stone and placed every "+
      "fifteen feet without variance.  "+
      "%^BOLD%^%^BLUE%^Columns %^RESET%^carved in relief march along "+
      "the walls between the arches, "+
      "creating a sense of being in the open air despite the drab "+
      "walls of the tunnels.  Here, "+
      "the tunnel curves sharply, and a %^BOLD%^%^RED%^grand statue "+
      "%^RESET%^has been carved from the protruding southeastern "+
      "corner."
      "\n"
    );
    add_item("statue","%^BOLD%^The dauntless statue carved from the "+
      "southeastern corner depicts a massive "+
      "%^BLUE%^male dwarf %^WHITE%^who stands over ten feet tall.  "+
      "His body is powerfully muscular and clad in "+
      "%^YELLOW%^dwarven platemail%^WHITE%^.  His large shield bears "+
      "a crest of a %^BLACK%^hammer %^WHITE%^and "+
      "%^BLACK%^anvil%^WHITE%^, and a massive %^BLUE%^dwarven hammer "+
      "%^WHITE%^is hoisted over his shoulder.  "+
      "His hair is long and flowing, matching his beard, "+
      "which reaches past his knees.  On his forearms are %^YELLOW%^"+
      "bright, golden bracers%^WHITE%^.");
    add_item("corner","The corner where the southern and eastern walls "+
      "of the respective tunnels "+
      "meet has been carved into a fantastic statue you could take a "+
      "closer look at.");
    set_exits(([
        "south" : ROOMS"cave24",
        "east" : ROOMS"cave26"
   	]));
}
