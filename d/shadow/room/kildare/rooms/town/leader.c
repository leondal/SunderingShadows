//leader.c
#include <std.h>
#include "../../kildare.h"

inherit TBUILD;

void create()
{
   ::create();
   set_short("A Foyer");
   set_long(
      "%^RESET%^%^CYAN%^The oak door at the front of the building "+
      "opens into a narrow foyer with a door leading off to the "+
      "right and left.  Narrow tables against each wall hold brass "+
      "oil lamps that light the room and illuminate the single painting "
      "that hangs at the northern end of the foyer.  A long, narrow "+
      "rug ending in tassels muffles the sounds against the stone floor."
   );

   set_smell("default","A faint scent of lavander lingers here.");
   set_listen("default","The thick rug lining the floor muffles sound in this narrow hallway.");
   set_items(([
      (({"foyer","room"})) : "This room is decorated well, though it's "+
         "narrow width prevents much furniture.  Small tables are pressed "+
         "against the stone walls, and between them are set doors on each "+
         "side of the foyer - a pine door leading to the west, and a cypress "+
         "door to the east.",
      (({"table","tables","narrow tables","narrow table"})) : "There are five "+
         "narrow tables in the room, each of them standing about four feet high.  "+
         "They have matching spindle legs and carved tops with simple lines.  Each "+
         "table holds a brass oil lamp that helps light the room.",
      (({"lamp","oil lamp","lamps"})) : "%^YELLOW%^The brass lanterns are simple, "+
         "but well-made.  They have brass bases with curving glass shields "+
         "that reveal a flickering, yellow-orange light.  The oil resevoirs are "+
         "decorated with scrollwork in brass.",
      (({"painting","single painting","picture"})) : "%^GREEN%^The oil painting at the end "+
         "of the hall depicts a simple pastoral scene.  A shepherd reclines against "+
         "a large boulder as he watches the fluffy figures of sheep grazing in "+
         "a rocky clearing.  In the background, mountain peaks rise all around, "+
         "dotted with tall evergreen forests and white snowcaps.  A brass plaque "+
         "has been fastened to the bottom of the cherry frame.",
      (({"rug","narrow rug"})) : "%^ORANGE%^The rug is woven in threads of cream, brown, and "+
         "gold, and seems to have been well-crafted.  Golden tassels are fastened "+
         "to the ends and a golden border has been worked all around the edge."
      ]));
      add_item("plaque","A polished brass plaque with engraved script.");
      set("read",
@CIRCE
%^YELLOW%^%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       %^BOLD%^%^CYAN%^Painted by Tiran Muldan
      in appreciate of kindness
       shown by Caldon Rendar,
        Reeve of Kildare Glen
       May the Winds Favor You
%^YELLOW%^%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
CIRCE
      );

   set_exits(([
      "south" : TROOMS"path11",
      "west" : TROOMS"leader1",
      "east" : TROOMS"leader3",
      ]));
   set_door("oak door",TROOMS"path11","south",0);
   set_door("pine door",TROOMS"leader1","west",0);
   set_door("cypress door",TROOMS"leader3","east",0);
}
