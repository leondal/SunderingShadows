#include <std.h>
#include "../../elfisland1.h";

inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^There appears to be a break in the forest here. To the east the"+
     " forest breaks into a more spacious setting where the trees do not grow so close together."+
     " Off to the west the forest closes in on itself, leaving little space in between tree growth. There"+
      " appears to be a path that heads off to the west. However, it is hard to see too far to the east as"+
      " what little of the path you can see is now hidden by an overgrowth of forest plant life."
   );
   set_search("default","You find some footprints heading into the forest.");
    set_items( ([
      "grass":"Between the thick of the forest and the path, there is several feet of tall grass.",
      "forest":"The forest rises all around you, looking thicker to the east than the west, but looking closely, you see a pathway through it."
   ]) );
   set_exits( ([
      "west" : PATH+"path14",
      "east" : TOWN+"road12",
   ]) );
//   set_invis_exits(({"forest"}));
//The pathway from the other side is completely clear, so removing the invis exit and changing it to east ~Circe~ 7/24/19
}

void reset()
{
   ::reset();
   if(!present("guard")) {
    new(MON+"elguard")->move(TO);
    new(MON+"elguard")->move(TO);
   }
}

