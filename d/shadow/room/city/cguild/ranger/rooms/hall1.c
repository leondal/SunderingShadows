#include <std.h>
#include "../ranger.h"
inherit ROOM ;

void create(){
   object ob;
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_property("light",2);
   set_property("indoors",1);
   set_property("no teleport",1);
   set_name("Inside the World Tree");
   set_short("%^RESET%^%^GREEN%^Inside the World Tree%^RESET%^");
   set_long("%^RESET%^%^GREEN%^Inside the World Tree%^RESET%^\n"
"%^RESET%^%^ORANGE%^You find yourself standing within the base of what seems to be an impossibly large "
"%^GREEN%^oak tree%^ORANGE%^.  Easily as large as a hall, this inner area is roughly circular and bordered on "
"all sides by rough walls of %^RED%^wood %^ORANGE%^and %^BOLD%^%^BLACK%^bark%^RESET%^%^ORANGE%^.  Gnarled "
"roots snake their way into the earth beneath your feet, which is hard-packed from the passage of many feet.  "
"%^RED%^Wooden slats%^ORANGE%^, almost like tree limbs, grow outwards from the inside of the trunk, forming a "
"circular pathway of stairs that leads up around the edge of the room to an unseen area above, cut off from "
"view by the flat plane of wood that serves as the roof to this section.  Softly glowing orbs of %^GREEN%^vi"
"%^CYAN%^rid%^GREEN%^ian li%^CYAN%^gh%^GREEN%^t %^ORANGE%^shed a gentle, natural radiance about the otherwise "
"enclosed and darkened room.  The only other way out appears to be a split between some of the tree's thick "
"roots, leading out to the %^CYAN%^fresh air %^ORANGE%^beyond.\n%^RESET%^");
   set_smell("default","The sweet smell of fresh air and greenery surrounds you.");
   set_listen("default","The quiet surroundings are occasionally interrupted by the soft creak of wood.");

   set_items(([
     ({"walls","wood","bark","tree","trunk","stairs","limbs","slats","pathway"}):"%^RESET%^%^ORANGE%^The "
"sturdy trunk of a %^GREEN%^massive oak tree %^ORANGE%^forms this room, enclosed on all sides by %^RED%^rough-"
"barked wood%^ORANGE%^.  Wooden slats, much like tree limbs, have grown outwards from the walls to provide a "
"circular stairway that leads up into rooms above you.%^RESET%^",
     ({"earth","ground","roots"}):"%^RESET%^%^ORANGE%^Thick gnarled roots snake their way into the %^BOLD%^"
"%^BLACK%^hard-packed earth %^RESET%^%^ORANGE%^beneath your feet.  At one point, a gap split between them "
"seems big enough to escape through, into the %^CYAN%^open air %^ORANGE%^beyond.%^RESET%^",
     ({"orbs","light","radiance"}):"%^RESET%^%^ORANGE%^Around the walls, softly glowing orbs of %^GREEN%^vi"
"%^CYAN%^rid%^GREEN%^ian li%^CYAN%^gh%^GREEN%^t %^ORANGE%^shed a gentle radiance upon the room itself."
"%^RESET%^",
   ]));

   set_exits(([
     "out":RROOM"path3",
     "up":RROOM"hall2",
   ]));

   ob=new(BBOARD);
   ob->set_name("board");
   ob->set_id(({"board","notice board","ranger board"}));
   ob->set_board_id("ranger_guild");
   ob->set_max_posts(30);
   ob->set_location(RROOM"hall1");
   ob->set_short("%^YELLOW%^Ranger's notice board%^RESET%^");
   ob->set_long("%^RESET%^%^ORANGE%^A wooden board lies upon the distant wall of the room, pinned with a few "
"notices.%^RESET%^");
}