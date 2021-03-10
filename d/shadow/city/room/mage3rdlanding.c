//Octothorpe (1/21/17)
//Shadow, Mage Tower Third Floor Landing
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_climate("temperate");
   set_name("Third Floor Landing in the Shadow Mage Tower");
   set_short("%^BOLD%^%^MAGENTA%^Third Floor Landing in the "+
      "%^BOLD%^%^BLACK%^Shadow %^MAGENTA%^Mage Tower%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Third Floor Landing in the "+
      "%^BOLD%^%^BLACK%^Shadow %^MAGENTA%^Mage Tower\n"+
      "%^RESET%^%^MAGENTA%^The long and winding staircase finally "+
      "comes to an end here. A small incline leads to a %^BOLD%^"+
      "%^WHITE%^silver door%^RESET%^%^MAGENTA%^. A %^ORANGE%^wooden "+
      "door %^MAGENTA%^off to the west is rather ordinary. "+
      "%^YELLOW%^G%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^%^ORANGE%^"+
      "e%^BOLD%^n pip%^RESET%^%^ORANGE%^e%^BOLD%^s %^RESET%^%^MAGENTA%^"+
      "snake their way along the ceiling in no discernible pattern, "+
      "and it is from here the wind's strange and %^BOLD%^cacophonic "+
      "%^RESET%^%^MAGENTA%^music comes. It is quite loud and a little "+
      "bit disorienting.%^RESET%^\n");
   set_smell("default","%^RESET%^%^CYAN%^There is very little to smell "+
      "here.%^RESET%^");
   set_listen("default","%^BOLD%^%^MAGENTA%^The music is louder here as "+
      "you grow closer to its source.%^RESET%^");
   set_items(([
      "pipes" : "%^RESET%^%^YELLOW%^G%^RESET%^%^ORANGE%^o%^BOLD%^ld"+
         "%^RESET%^%^ORANGE%^e%^BOLD%^n pipes %^RESET%^%^CYAN%^push "+
         "through the walls from above, likely leading to a point "+
         "outside. They snake around the ceiling above your head, "+
         "some larger than others. When the wind blows - and the wind "+
         "always blows at this height - they play a discordant, "+
         "%^BOLD%^%^BLACK%^haunting %^RESET%^%^CYAN%^song. The song "+
         "fills the entire tower, although right here it is almost "+
         "overbearing. This is not a place to stand for very long.%^RESET%^"
   ]));
   set_exits(([
      "west" : ROOMS"magelab",
      "down" : ROOMS"mage2ndlanding",
      "up" : ROOMS"mageroof"
   ]));
   set_door("silver door",ROOMS"mageroof","up",0,0);
   set_door_description("silver door","%^RESET%^%^CYAN%^The door is "+
      "made from %^WHITE%^light metal%^CYAN%^. A circle of %^BOLD%^"+
      "%^BLUE%^seven silver stars %^RESET%^%^CYAN%^are engraved into "+
      "its otherwise seamless surface.%^RESET%^");
   set_door("wooden door",ROOMS"magelab","west",0,0);
   set_door_description("wooden door","%^RESET%^%^CYAN%^It is a door "+
      "that's made from %^ORANGE%^wood%^CYAN%^. There is nothing "+
      "extraordinary about it.%^RESET%^");
}