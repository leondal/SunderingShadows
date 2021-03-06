#include <std.h>
#include <objects.h>
inherit VAULT;
void create() {
   ::create();
   set_light(2);
   set_indoors(1);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_short("War Museum");
   set_long(
@FIST
%^CYAN%^%^BOLD%^This is the War Museum of Shadow. On display here are armor and weaponry 
from a thousand lands. From the exquisite ceremonial plate armor of %^YELLOW%^Tharis,
%^CYAN%^to the smelly wolfskins worn by the %^RED%^Orc%^CYAN%^ tribes. Katanas crafted by the 
elder smiths of the east lay next to primitive yet wickedly serrated and 
spiked weapons of the %^RED%^Goblins.%^CYAN%^ Even, in a specially %^BLUE%^darkened%^CYAN%^ display, are 
the exotic and horrible weapons of the mysterious and evil %^RED%^Drow. %^CYAN%^Toward 
the back of the massive hall, is a pedestal with an iron sculpture of an 
immense gauntleted %^RED%^Fist%^CYAN%^ atop it.
FIST
   );
   set_smell("default","Your nostrils detect a faint odor of long dried blood.");
   set_listen("default","The hall is silent, but somehow your ears pick up the ghostly sounds of distant battle.");
   set_items((["sculpture":"This is a detailed sculpture of an immense, gauntleted fist, atop a pedestal of the purest clear crystal. You have the urge to touch it.",
               "fist":"This is a detailed sculpture of an immense, gauntleted fist, atop a pedestal of the purest clear crystal. You have the urge to touch it."
              ]));
   set_exits(([
                  "west":"/d/shadow/city/room/southcross",
              "north":"/d/guilds/consortium/hall/library",

              ]) );
   set_door("museum door","/d/guilds/consortium/hall/library","north","library key");
   
}


void init() {
   ::init();
   add_action("touch_fist","touch");
}

int touch_fist(string str) {
   if(str !="fist") {
      return 0;}
   tell_object(TP,"You touch the Iron Fist, you feel a tingling, and you suddenly find yourself in another place.");
   tell_room(TO,TP->query_cap_name()+" touches the Iron Fist and disappears.",TP);
   TP->move_player("/d/guilds/fist/hall/guild2.c");
   return 1;
}

