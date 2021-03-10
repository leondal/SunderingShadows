//updated by Circe 6/2/04 with color, etc.
// Caerveron Square, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// square.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_light(2);
  set_short("Caerveron Square, Tabor");
  set_name("Caerveron Square, Tabor");
  set_long(
@DAI
%^BOLD%^Caerveron Square, Tabor%^RESET%^
You are in Tabor, the capital town of the Kingdom of Tabor.  This is
%^YELLOW%^Caerveron Square%^RESET%^, the great crossroads of the town of Tabor.  In the
center of the square is an ancient, but gigantic %^YELLOW%^golden statue %^RESET%^of a king
on a pedestal. People seem to be moving through the square at all hours
of the day, small surprise given the number of streets that intersect
here.  At times of %^MAGENTA%^festivals %^RESET%^and %^GREEN%^outdoor gatherings%^RESET%^, many %^YELLOW%^lanterns %^RESET%^
are raised on poles about the square and the entire town gathers 
here for a night of %^CYAN%^revelry%^RESET%^, usually involving feasting, dancing, 
and storytelling.

%^MAGENTA%^Mathowvy Road %^RESET%^is to the north and south.  You see %^BOLD%^%^CYAN%^Vala Street %^RESET%^to the
east, and %^GREEN%^Greene Street%^RESET%^ is to the west.
DAI
    );
  set_exits(([
    "east" : ROOMDIR+"vala1",
    "west" : ROOMDIR+"greene1",
    "south" : ROOMDIR+"math4",
    "north" : ROOMDIR+"math5"
  ]));
  set_listen("default","You hear the chatter of townspeople as they "+
     "go about their business.");
  set_smell("default","The slightly rank scent of a busy city "+
     "lingers in the air.");
  set_items(([
    "statue" : "This statue is plated in %^YELLOW%^gold %^RESET%^and "+
       "seems to depict a great king.  He is an aged man with a head "+
       "of thick, curly hair, upon which sits a %^BOLD%^%^RED%^j"+
       "%^WHITE%^e%^CYAN%^w%^BLUE%^e%^GREEN%^l%^RED%^e%^WHITE%^d "+
       "crown%^RESET%^.  He wears a long, flowing robe belted at the "+
       "waist, and a shirt of chainmail peeks out from the sleeves.  "+
       "A great scepter has been placed in his hand, and he stands "+
       "with his eyes proudly focused on the east.\n\n%^BOLD%^An inscription "+
       "on the pedestal reads%^RESET%^: Caerveron, First King of Tabor.",
    "road" : "%^MAGENTA%^Mathowvy Road%^RESET%^: North to Tabor, south to Azha in Tsarven."
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

