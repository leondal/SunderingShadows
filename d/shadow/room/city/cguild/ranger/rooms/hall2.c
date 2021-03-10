#include <std.h>
#include "../ranger.h"
inherit ROOM ;

void create(){
   ::create();
   set_terrain(BRANCHES);
   set_travel(DIRT_ROAD);
   set_property("light",2);
   set_property("indoors",1);
   set_property("no teleport",1);
   set_name("Inside the World Tree");
   set_short("%^RESET%^%^GREEN%^Inside the World Tree%^RESET%^");
   set_long("%^RESET%^%^GREEN%^Inside the World Tree%^RESET%^\n"
"%^RESET%^%^ORANGE%^This tall, oval enclosure seems to be partway up the trunk of an impossibly large %^GREEN%^"
"oak tree%^ORANGE%^.  The room is roughly circular and bordered on all sides by rough walls of %^RED%^wood "
"%^ORANGE%^and %^BOLD%^%^BLACK%^bark%^RESET%^%^ORANGE%^.  Beneath your feet, a relatively smooth level of wood "
"seems to have grown to form a floor, while another above serves as a makeshift roof to the room.  %^RED%^"
"Wooden slats%^ORANGE%^, almost like tree limbs, grow outwards from the inside of the trunk, forming a "
"circular pathway of stairs that leads both up and down around the edge of the room to unseen areas above and "
"below.  Softly glowing orbs of %^GREEN%^vi%^CYAN%^rid%^GREEN%^ian li%^CYAN%^gh%^GREEN%^t %^ORANGE%^shed a "
"gentle, natural radiance about the partially enclosed and darkened room.  A natural outcropping of the trunk "
"partitions a %^BLUE%^small alcove %^ORANGE%^away from the main room, which seems to contain a store of some "
"kind, while an opening upon the other side of the room leads out to a thick branch and the %^CYAN%^fresh air "
"%^ORANGE%^beyond.\n%^RESET%^");
   set_smell("default","The sweet smell of fresh air and greenery surrounds you.");
   set_listen("default","The quiet surroundings are occasionally interrupted by the soft creak of wood.");

   set_items(([
     ({"walls","wood","bark","tree","trunk","stairs","limbs","slats","pathway","roof","floor"}):"%^RESET%^"
"%^ORANGE%^The sturdy trunk of a %^GREEN%^massive oak tree %^ORANGE%^forms this room, enclosed on all sides by "
"%^RED%^rough-barked wood%^ORANGE%^.  The floor and roof are formed of the same wood, which appear to have "
"grown naturally into the flat layers that provide the remaining enclosure to the room.  %^RED%^Wooden slats"
"%^ORANGE%^, much like tree limbs, have grown outwards from the walls to provide a circular stairway that "
"leads up and down into rooms above and below you.%^RESET%^",
     ({"alcove","store","outcrop","outcropping"}):"%^RESET%^%^ORANGE%^A natural outcropping of the trunk has "
"grown across to form a partition between this room and a %^BLUE%^small side alcove%^ORANGE%^.  Within it "
"seems to be a store of some kind.%^RESET%^",
     ({"orbs","light","radiance"}):"%^RESET%^%^ORANGE%^Around the walls, softly glowing orbs of %^GREEN%^vi"
"%^CYAN%^rid%^GREEN%^ian li%^CYAN%^gh%^GREEN%^t %^ORANGE%^shed a gentle radiance upon the room itself."
"%^RESET%^",
   ]));

   set_exits(([
     "down":RROOM"hall1",
     "up":RROOM"hall3",
     "out":RROOM"archery",
     "alcove":RROOM"shop",
   ]));
}