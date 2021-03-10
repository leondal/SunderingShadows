//general.c - General Store for Lothwaite.  Circe 9/18/04
#include <std.h>
#include "../lothwaite.h"
inherit VAULT;

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Lothwaite Trading Post");
   set_short("Lothwaite Trading Post");
   set_long("%^ORANGE%^This simple shop is much like the other "+
      "buildings in the quiet village of Lothwaite.  The walls "+
      "are made mostly of %^BOLD%^wattle panels %^RESET%^%^ORANGE%^"+
      "set upon low %^RESET%^stone bases %^ORANGE%^and packed with "+
      "mud to combat the wind of the valley.  A massive %^RESET%^"+
      "wicker chair %^ORANGE%^sits almost in the center of the room, "+
      "and it is from here that the aged shopkeeper conducts his "+
      "business when he is here.  There are also a few other clerks, "+
      "though none of them ever sits in the elder's chair.  Several "+
      "shelves support various goods, with larger items standing "+
      "on the floor.  It seems one could find most anything here.  "+
      "The room is lit and heated by a small %^RED%^fireplace "+
      "%^ORANGE%^in the southern end of the room.\n");
   set_items(([
      ({"chair","wicker chair"}) : "The ancient wicker chair has a back "+
         "that rises over ten feet tall.  The seat sags dramatically "+
         "and seems to have molded itself to one back over time.",
      ({"shelves","items","goods"}) : "Spaced around the room at "+
         "various heights, the shelves support goods of all kinds.  "+
         "Unlike the general stores in most towns that cater to "+
         "adventurers, the goods here suggest that they are mostly "+
         "for the townspeople.  Barrels of flour, wheels of cheese, "+
         "and other such goods are mixed with the typical pouches, "+
         "sacks, and tools needed by those who live by adventure.",
      ({"walls","wall","wattle","wattle walls","panels"}) : "%^ORANGE%^"+
         "The walls are made of wattle - woven panels of osier, or "+
         "willow, that have been packed with mud to seal the cracks "+
         "and keep out the wind.  The very bottom of the walls are "+
         "made of %^RESET%^stones %^ORANGE%^shaped to fit without "+
         "mortar.  The wall facing the road is set with two large "+
         "open windows, which may be closed with shutters during "+
         "inclement weather.",
      ({"floor","dirt floor","rushes"}) : "The dirt floor is covered "+
         "with a layer of rushes taken from the lake nearby.  The "+
         "rushes look to be changed ever so often to keep them "+
         "clean.  They add a slight grassy fragrance to the shop.",
      ({"fireplace","fire","fire place"}) : "The small fireplace in "+
         "the southern end of the room provides ample lighting as well "+
         "as heat at all times of the year."
   ]));
   set_smell("default","The clean mountain air blows in through the windows.");
   set_listen("default","The crackling of the fire seems soothing.");
   set_exits(([
      "north" : PATHEXIT"pathway26"
   ]));
   set_door("door",PATHEXIT"pathway26","north",0);
   set_door_description("door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
}

void reset(){
   ::reset();
   if(!present("clerk")){
      new(MON"lothwaite_clerk")->move(TO);
   }
}