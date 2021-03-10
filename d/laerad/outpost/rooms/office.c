#include <std.h>
#include "../outpost.h"
inherit CROOM;
void create()
  {
  ::create();
   set_travel(DIRT_ROAD);
   set_terrain(WOOD_BUILDING);
    set_short("Captains Office");
  set_property("light",2);
  set_property("indoors",1);
  set_long(
    "%^BOLD%^%^YELLOW%^Captain Dailvins Office\n"+
    "The office is a %^ORANGE%^large wooden room %^WHITE%^like most other houses in the "+
	"%^BOLD%^%^BLACK%^outpost%^RESET%^. In here there is a %^YELLOW%^welcome mat %^RESET%^at "+
	"the door and a %^BOLD%^%^CYAN%^bowl of water %^RESET%^to %^CYAN%^wash the hands and face "+
	"%^WHITE%^with. Besides a few paintings on the walls it is only the large "+
	"%^GREEN%^m%^ORANGE%^a%^GREEN%^h%^ORANGE%^o%^GREEN%^g%^ORANGE%^a%^GREEN%^n%^ORANGE%^y "+
	"%^GREEN%^t%^ORANGE%^a%^GREEN%^bl%^ORANGE%^e %^WHITE%^and large %^GREEN%^c%^ORANGE%^h%^GREEN%^a%^ORANGE%^i%^GREEN%^r "+
	"%^WHITE%^in same wood which make this look like a %^MAGENTA%^official building%^WHITE%^. "+
	"In the back of the room a bunk-bed and large chest makes it evident that besides being his "+
	"office. The Captain most likely lives here.%^RESET%^.\n"
  );
   set_smell("default","%^ORANGE%^The whole building still smell of freshly sawed wood.");
    set_listen("default","%^MAGENTA%^You hear the workers doing their job all around the outpost.");
   set_items(([
   ({"table"}) : "There are 3 documented on the table.",
   ({"floor"}) : "The floor is kept immaculately clean.",
   ({"chair"}) : "It is a large mahogany chair with a plush comfortable looking pillow.",
   ({"document 1"}) : ({"%^ORANGE%^This is a document with Torms sigil on it. You could read it.","%^YELLOW%^Captain Dalvin, please do report back regarding the rumours regarding formian sightings-- Regards Office of Torm.","common"}),
   ({"document 2"}) : ({"%^ORANGE%^This document looks like one being written by Dalvin. You could read it.","%^YELLOW%^The rumors as to a cave with the mindflayer or so called 'illithids' seem true. We have yet to investigate further.","common"}),
   ({"document 3"}) : ({"%^ORANGE%^This document looks like an inventory list. You could read it.","%^YELLOW%^This is indeed a list of inventory. Listen weapons, armors, food and other supplies going to the ruins of Asgard in near future.","common"}),
   
   ]));
  set_name("Dalvins office");
  set_exits(([
  "east":ROOMS"8",
  ]));
}

void reset(){
  ::reset();
  if(!present("dalvin")){ new(MOBS"dalvin")->move(TO);}
  
  }

  
