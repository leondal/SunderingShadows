#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("Front of the church commune.");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",3);
   set_long(
@DESC
You are standing on a small cobblestone path beneath the %^CYAN%^Cathedral 
of Seneca%^RESET%^. A few overgrown bushes surround you and you are forced to 
push through them at one point as they reach out over the path. The 
church building itself is a gothic style cathedral complete with a bell 
tower rising to dwarf most of the surrounding structures, and great 
sweeping angled rooves upon which gargoyles perch peering menacingly 
down upon you. You stand upon holy ground. A small cemetary lies just
to the east of here.
DESC
   );
   set_exits(([
      "enter" : "/d/attaya/seneca/church",
      "north" : "/d/attaya/seneca/street4",
   ]));
   set_items(([
      "path" : "It is a small cobblestone path.",
      "grass" : "The healthy green grass has been recently cut.",
      "cathedral" : "The cathedral towers over you, casting you in shadow.  It has a central structure with a tall angled roof and stained glass windows, and it also has a bell tower rising tfrom one side.",
      "bushes" : "They have been allowed to grow unchecked and are taking over the churchyard.",
      "cemetary" : "Seven rows of old stone markers rise from burial plots in a small cemetary.  Trees cast shade down upon them.",
      "gargoyles" : "Evil looking gargoyles may actually serve as guardians to this place.",
   ]));
}
