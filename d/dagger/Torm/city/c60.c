#include <std.h>
#include "../tormdefs.h"
inherit VAULT;
void create()
{
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property("indoors",1);
  set_property("light",2);
  set_door("door",TCITY+"c61","south");  // removed key so can unlock from inside
      set_short("Tailor's shop");
  set_long(
    "Tailor's shop.\n"

        "  A few tailor's mannequins line the back wall and a curtain separates a small changing room from the rest of the shop."
      " This simple tailor's shop is full of clothes of many kinds, mostly local silks but a few from all corners of the lands."
   "  The clothing looks as though it is of good quality, with most pieces being quite fashionably designed.  There are many tools handy to measure customers precisely, ensuring a good fit and helping to secure future business."
    );
   set_smell("default","A pleasant light musk chases away the salty sea air.");
   set_listen("default","You can hear the sounds of the street outside.");
    set_items(([
   "floor" : "The floor is fairly neat, although you can see bits of fabric snippings here and there.",
   ({"mannequins","mannequin"}) : "There are several cloth mannequins about the shop, displaying mostly skirts and dresses, although there are a few that display nicer shirts and pants. The tailor obviously knows that women make up the majority of his customers.",
   ({"clothes","silks"}) : "There are all sorts of clothes and silks carefully stacked about the room. Most of the silks are reserved for the nobility of the town, but a few nice things are sold to the common public.",
   "curtain" : "There is a curtain in the back that separates a small area from the rest of the store, where people can go to change.",
   "tools" : "There are many measuring tools handy so that the tailor can fit all sizes of customers.",
   ]));
    set_exits(([
	"south":TCITY+"c61",
      ]));
   if(query_night() == 1) {
      set_open("door",0);
   }
   else {
      set_open("door",1);
   }
}

void reset(){
    ::reset();
    if(!present("tailor",TO)){
//  new(MON+"clothier.c")->move(TO);
    }
}
