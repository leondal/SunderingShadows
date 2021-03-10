//updated by Circe 6/2/04 with color, etc
// Mathowvy Road, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// math8.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Mathowvy Road, Tabor");
  set_short("Mathowvy Road, Tabor");
  set_long(
@DAI
%^BOLD%^Mathowvy Road, Tabor%^RESET%^
You are on %^MAGENTA%^Mathowvy Road%^RESET%^, just north of an intersection.  Here you
appear to be on a slope at the foot of Mount Tabor.  If you proceed
north here, you will also be moving uphill towards the %^YELLOW%^Royal castle
of Caer Tabor %^RESET%^on the hilltop.  If you move south, you will enter the
center of the town.  Just to the east stands a massive %^BOLD%^stone building%^RESET%^,
chimneys pouring out smoke.  A %^YELLOW%^sign %^RESET%^hangs above the door that 
you could read.

%^MAGENTA%^Mathowvy Road %^RESET%^continues to the north and south. 
DAI
    );
  set_exits(([
    "south" : ROOMDIR+"math7",
    "north" : ROOMDIR+"math9",
    "east" : ROOMDIR+"firbolg_smith",
    "west" : ROOMDIR+"taborbardcomps"
  ]));
  set_listen("default","You hear the busy sounds of a large town.");
  set_smell("default","The slightly rank scent of a busy city "+
     "lingers in the air.");
  set_items(([
    "castle" : "Caer Tabor is a rather imposing looking structure from here.",
    ({"building","shop","stone building","forge"}) : "The stone "+
       "building looks to have vaulted ceilings, but it otherwise "+
       "appears to be a smithy of some sort.  There is a sign just "+
       "above the door.",
    ({"sign","wooden sign","shop sign"}) : ({"This is a simple wooden "+
       "sign that bears a message you could read.","%^BOLD%^%^RED%^"+
       "Anvil of the Colossus%^RESET%^","common"})
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

