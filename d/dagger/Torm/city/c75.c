#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_door("door",TCITY+"c74","west","Torm masterkey");
  set_door("carved door","/d/player_houses/slore/comp_store","east",0);
//  set_door("carved door","/d/player_houses/slore/comp_store","opening",0);
  set_door_description("carved door","In addition to the carving, this wooden "
      "door also an opening cut all the way through it in the shape of a "
      "crescent moon.");
  set_short("South road");
  set_long(
  "South road.\n"
    "  A great sound of business fills the air here from the marketplace to "
    "the north.  A sign of a shield over the door to the west signifies a "
    "armorer's shop, and you can see Torm's city gates further south on "
    "this road.  The door to the east has a curious carving in the door and "
    "a half-moon cut all the way through."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled over the city, it keeps low to the ground,"+
  " obscuring the road from view and making it difficult to tell where"+
  " you're going if you don't already know the way.  The marketplace"+
  " north of you is quiet and still, completely blanketed by the fog.  "
  "The door to the east has a curious carving in the door and "
    "a half-moon cut all the way through."
  );
   set_items(([
     "building" : "The building to the west is well built and has the sign "
        "of a shield over its door.",
     "sign" : "The metal sign hangs above the western door.  It is the image "
        "of a shield, signaling that this is the armor shop.",
     ({"carving", "picture" }) : "The carving depicts an old wizard, stave in "
        "one hand and book in the other, looking up at a waning moon.  He "
        "appears to be reciting something.",
     ({"opening","moon"}) : "The shape of a crescent moon cut all the way "
        "through the door above the carving of the wizard.",
    ]));
     
  set_smell("default", "You smell a sweet vapor coming from the eastern door.");
  set_exits(([
  "north":TCITY+"c64",
  "south":TCITY+"c81",
  "west":TCITY+"c74",
//  "opening" : "/d/player_houses/slore/comp_store",
//  "moon" : "/d/player_houses/slore/comp_store",
  "east" : "/d/player_houses/slore/comp_store",
  ]));
//  set_invis_exits(({"opening", "moon" }));
//  set_pre_exit_functions( ({"opening", "moon"}), ({"GoThroughDoor", "GoThroughDoor"}) );
}
