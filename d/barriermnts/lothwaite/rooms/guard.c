//guard.c - Guard tower for Lothwaite.  Circe 8/16/04
#include <std.h>
#include "../lothwaite.h"
inherit VAULT;

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Wooden Guard Tower");
   set_short("Wooden Guard Tower");
   set_long("%^ORANGE%^This imposing tower rises dozens of feet "+
      "above the %^GREEN%^valley %^ORANGE%^below.  Wide "+
      "%^RED%^stairs %^ORANGE%^climb the northern wall, leading "+
      "up into the guard barracks on the upper floor.  No fire "+
      "burns in this building, leaving it much colder than the "+
      "others in the village.  Tall %^BLUE%^arrowslits %^ORANGE%^"+
      "open all around the tower, allowing a view of the %^GREEN%^"+
      "valley%^ORANGE%^.  In the southeastern portion of the tower "+
      "stands a %^RESET%^pine rack %^ORANGE%^supporting massive "+
      "%^RED%^mauls%^ORANGE%^, %^GREEN%^bows%^ORANGE%^, and "+
      "%^YELLOW%^swords%^RESET%^%^ORANGE%^ "+
      "with various bits of leather armor as well.  It seems this "+
      "tower stands in defense of the village, though it is unlikely "+
      "any force could readily get through the %^GREEN%^ramparts "+
      "%^ORANGE%^outside.%^RESET%^\n");
   set_items(([
      ({"tower","room"}) : "This tower rises several dozen feet above "+
         "the valley, allowing a commanding view of all the land "+
         "surrounding the village.  The tower is made mostly of wood "+
         "and has been set on top of a stone base.",
      ({"stairs","stair","staircase","steps"}) : "The wooden stairs "+
         "rising up the northern wall lead through an open hole "+
         "in the ceiling, through which you can see pallets and "+
         "blankets.  The upper floor must be where the guards rest "+
         "when not on duty.",
      ({"arrowslits","slits"}) : "The narrow arrowslits are quite "+
         "tall and placed high up on the wall in the perfect position "+
         "for a firbolg guard.  They provide a commanding view of the "+
         "valley outside.",
      ({"valley","village","outside"}) : "The valley outside looks "+
         "quite peaceful, with smoke rising through holes in the "+
         "roofs of the buildings.  The grass seems to be verdant "+
         "year round, and it seems hard to believe such a place "+
         "would need the defenses it has set up.  The earthen "+
         "ramparts are topped with high wooden walls reinforced "+
         "in places with iron.",
      ({"rack","pine rack","weapons","bows","swords","mauls"}) : "The "+
         "simple pine rack has been placed in the corner to hold "+
         "the large mauls, swords, bows, and other weapons used "+
         "by the firbolg guards of the valley.  It seems they must "+
         "keep their weapons here, though there are clearly enough "+
         "for nearly all the villagers.  Leather breastplates, "+
         "greaves, and gauntlets are also piled nearby."
   ]));
   set_smell("default","A slightly musty scent hangs in the air here.");
   set_listen("default","The swish of whetstones can occasionally be heard.");
   set_exits(([
      "south" : PATHEXIT"grass1"
   ]));
   set_door("guard door",PATHEXIT"grass1","south",0);
   set_door_description("guard door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
}
