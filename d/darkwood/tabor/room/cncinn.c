// Yard of the Crown and Castle Inn, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// cncinn.c

#include <std.h>
#include "../include/tabor.h"

inherit VAULT;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
  ::create();
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_name("Yard of the Crown and Castle Inn, Tabor");
  set_short("Yard of the Crown and Castle Inn, Tabor");
  set_long(
@TABOR
%^BOLD%^Yard of the Crown and Castle Inn, Tabor%^RESET%^
%^GREEN%^This is the yard of the %^YELLOW%^Crown and Castle Inn%^RESET%^%^GREEN%^.  You can see here that the
inn is made up of two %^RESET%^buildings%^GREEN%^.  The first, right in front of the
entrance to the yard, is the %^YELLOW%^inn %^RESET%^%^GREEN%^itself and is a rather large %^RED%^brick
building%^GREEN%^.  The other is the %^ORANGE%^stable building %^GREEN%^where the guests may have
their horses looked after while they frequent the inn.

%^RESET%^There is a %^MAGENTA%^sign %^RESET%^for you to read here.

The door to the inn is to the east, the stable is to the south and the
gate to %^MAGENTA%^Mathowvy Road %^RESET%^is to the west.
TABOR
  );
  set_smell("default","You smell the odor of food as well as horse manure.");
  set_listen("default","You hear the muted babble of people and the sound of horses.");
  set_items(([
     ({"building","buildings"}) : "There are two separate buildings - "+
        "the stable and the inn.  Try looking at each.",
     ({"stable","stable building"}) : "The stables to the south are made "+
        "of bound wooden planks.  The double doors stand wide open, "+
        "allowing you to see the rows of stalls inside.  A back door "+
        "is open as well, showing a large tethering area where you "+
        "may secure your horse.",
     ({"inn","inn building","brick building"}) : "The inn is a squat, "+
        "one-story brick building.  Unlike most other buildings in the "+
        "area, the inn appears quite advanced and even features wooden "+
        "shingles that look as if they have been newly replaced.  The "+
        "door to the inn looks inviting, and you often hear laughter "+
        "coming from inside."
  ]));
  set_exits( ([
    "south" : ROOMDIR+"cncstable",
    "east"  : ROOMDIR+"cnchall",
    "west"  : ROOMDIR+"math2"
  ]) );
  set_door("door","/d/darkwood/tabor/room/cnchall","east","cnc key");
}

int read(string str) {
  object ob;
  int i;
  
  write(
@SIGN
Welcome to the %^BOLD%^Crown and Castle%^RESET%^, in the wonderful town of Tabor, Royal
Capital of Tabor and Seat of House Caerveron.

%^MAGENTA%^Amergin Paladowyn, proprieter%^RESET%^

%^CYAN%^All horses and animals are required to be stabled in the accomodations
to the south.%^RESET%^  

In addition, weapons may %^RED%^not%^RESET%^ be wielded in the Inn. 
Those failing to cooperate with this rule will be denied entrance or
removed from the premises.  

%^RED%^Thieves will be dealt with appropriately by the management.%^RESET%^ 

Please, visit our cafe or the bar for your needs.  Songes and Dramaticks
will be performed in the theatre by the owner or by a special guest
member of the bardaugh. 

Enjoy your stay!
SIGN
  );
  return 1;
}

