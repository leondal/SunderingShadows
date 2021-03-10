//inn3.c - Hallway for Golden Perch Inn.  Circe 7/31/04
#include <std.h>
#include "../lothwaite.h"
inherit VAULT;

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Hallway of the Golden Perch Inn");
   set_short("Hallway of the Golden Perch Inn");
   set_long("%^ORANGE%^The hallway of the Golden Perch in is much "+
      "like the rest of the buildings.  The floor has been crafted of "+
      "dry-fitted %^RESET%^stone %^ORANGE%^and covered in fresh "+
      "%^GREEN%^rushes %^ORANGE%^collected from the %^BLUE%^lake "+
      "%^ORANGE%^to the north.  The walls here are thin, each made of a "+
      "single %^RESET%^wattle panel%^ORANGE%^ that separates the "+
      "hallway from the rooms to either side.  Each wattle wall "+
      "features a single %^YELLOW%^doorway%^RESET%^%^ORANGE%^, and "+
      "the wall to the north seems to be much thicker, with the "+
      "cracks in the wattle filled with mud to prevent the strong "+
      "%^CYAN%^winds %^ORANGE%^that rip through the %^GREEN%^"+
      "valley %^ORANGE%^from chilling the guests.%^RESET%^\n");
   set_items(([
      ({"floor","rush-covered floor","rushes"}) : "%^GREEN%^The "+
         "rushes have been taken from the river and are swept up "+
         "each morning, with those who have outlived their purpose "+
         "being tossed out and the good ones returned.  The floor "+
         "here is made of stone, and the rushes help provide a "+
         "softer footing as well as keeping the stone clean.",
      ({"walls","wall","wattle","wattle walls"}) : "%^ORANGE%^"+
         "The walls are made of wattle - woven panels of osier, or "+
         "willow, that have been packed with mud to seal the cracks "+
         "and keep out the wind.  The thin panels to the east and "+
         "west merely provide separation for the two rooms on "+
         "either side, while the northern wall is reinforced to "+
         "keep out the wind."
   ]));
   set_smell("default","The smell of hearty foods lingers in the air.");
   set_listen("default","The muffled sounds of conversation float through "+
      "the door to the south.");
   set_exits(([
      "south" : PATHEXIT"inn2",
      "east" : PATHEXIT"inn5",
      "west" : PATHEXIT"inn3"
   ]));
   set_door("west door",PATHEXIT"inn3","west",0);
   set_door_description("west door","This door is made from a large pine "+
      "plank sanded smooth.  In the center of the door is the carved "+
      "image of a young girl in profile wearing a %^CYAN%^simple dress "+
      "%^RESET%^with a matching %^CYAN%^bonnet%^RESET%^.");
   set_door("east door",PATHEXIT"inn5","east",0);
   set_door_description("east door","This door is made from a large pine "+
      "plank sanded smooth.  In the center of the door is the carved "+
      "image of a young man dressed in %^GREEN%^trousers %^RESET%^"+
      "and a %^GREEN%^tunic %^RESET%^with a %^CYAN%^fishing rod %^RESET%^"+
      "over his shoulder.");
}