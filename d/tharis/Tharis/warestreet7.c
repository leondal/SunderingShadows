//altered by Circe 2/10/08 for Lurue's plot stuff
//warestreet1.c

#include <std.h>

inherit VAULT;

void create(){
  ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
  set_properties((["indoors":1,"light":2]));
  set_short("Ware street");
  set_long(
@OLI
%^BOLD%^%^YELLOW%^Ware Street%^RESET%^
To each side of you rise large warehouses and minor places of
operations.  Not an extremely clean area, the warehouse district leaves
much to be desired for those who enjoy the finer things in life.
However, this is where the wealth of Tharis lies, as many people
realize. In these warehouses are stored the gold, the copper, the
silver, the lumber and everything else that the city sends to Shadow and
to the Tsarvan Empire.

Few people walk through here.  Only the private security guards and the
occasional drunk wander these streets.
OLI
  );
  set_items(([
    "warehouses":"These large buildings contain inside them great riches."
  ]));
  set_exits(([
    "south":"/d/tharis/Tharis/warestreet6",
    "east" : "/d/av_rooms/lurue_tharis1"
  ]));
//Door and east exit added for plot
   set_door("warehouse door","/d/av_rooms/lurue_tharis1","east",0);
  set_smell("default","A dusty and dirty area brings dust and dirt.");
   set_listen("default","An occasional drunk sings loudly and a security guard yells.");
}

void init(){
  ::init();
        
  do_random_encounters(({"/d/tharis/monsters/security"}),30,2);
}
