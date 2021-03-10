//cath_kitchen.c 
//for new Seneca ~Circe~ 4/4/08
#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Kitchen of the Cathedral, Seneca");
   set_short("Kitchen of the Cathedral, Seneca");
   set_long("%^BOLD%^Kitchen of the Cathedral, Seneca%^RESET%^\n"+
      "Rather than the typical %^BOLD%^white%^RESET%^, the stone "+
      "walls here have been dressed in %^ORANGE%^tan%^RESET%^, "+
      "likely to help mask the effects of the grated %^BOLD%^"+
      "%^RED%^fi%^YELLOW%^r%^RED%^es%^RESET%^ that line the "+
      "eastern wall.  It is here that many of the monks fulfill "+
      "their vows to serve their brethren and contribute to the "+
      "cathedral by preparing meals.  Two large %^BOLD%^%^BLACK%^"+
      "iron stoves %^RESET%^brace the fires, providing ample "+
      "room for baking %^ORANGE%^bread%^RESET%^ and the like.  "+
      "%^BOLD%^%^BLACK%^Cauldrons %^RESET%^of boiling stew "+
      "are bubbling here at all hours, while those supplies "+
      "not in use hang neatly from %^ORANGE%^wooden racks %^RESET%^"+
      "suspended from the ceiling in easy reach.  The floor "+
      "of the kitchen is dominated by simple round %^ORANGE%^"+
      "tables %^RESET%^with mostly matching %^ORANGE%^stools"+
      "%^RESET%^, all of which have been made and replaced by "+
      "monks over the years.\n");
   set_exits(([
      "west" : ROOMS"cath_basement"
   ]));
   set_smell("default","The hearty aroma of stew reaches you.");
   set_listen("default","The crackling fire and boiling stew "+
      "compete with the low murmur of conversing monks.");
   set_items(([
      ({"wall","walls"}) : "%^ORANGE%^The stone walls are "+
         "smooth and painted a light tan.%^RESET%^",
      "floor" : "The smooth stone floor was hewn at one point but "+
         "has also been worn by countless feet over the years, "+
         "making it seem almost soft.",
      ({"fires","fire","grated fire","grated fires"}) : "%^BOLD%^"+
        "%^BLACK%^Thick black grates have been placed across the "+
        "wide firepits, providing stability.  The %^RED%^fi%^YELLOW%^"+
        "r%^RED%^es%^BLACK%^ themselves are kept low and at the "+
        "perfect temperature.%^RESET%^",
      ({"stove","stoves","iron stoves"}) : "%^BOLD%^%^BLACK%^Each "+
        "of the stoves features a large cast iron door with a "+
        "narrow grate so the baker may peer inside.  They are "+
        "placed at either end of the firepits, allowing for more "+
        "baking to be done at once.%^RESET%^",
      ({"cauldron","cauldrons","stew","boiling stew"}) : "The "+
        "thick %^BOLD%^%^BLACK%^iron cauldrons%^RESET%^ are "+
        "kept filled on the grates at all times, allowing monks "+
        "to serve themselves.  The stew looks to be a decent "+
        "concoction of meat and vegetables.",
      ({"racks","wooden racks","utensils","pots","pans"}) : 
        "Suspended on thick lengths of rope are several %^ORANGE%^"+
        "wooden racks%^RESET%^ fitted with %^BOLD%^hooks%^RESET%^ "+
        "to hold large utensils, pots, and pans.  You notice there "+
        "seems to be nowhere to store bowls, which likely means "+
        "each monk brings his own.",
      ({"table","tables","stool","stools"}) : "The rustic tables "+
        "and stools feature wonderful craftsmanship, indicating "+
        "the dedication of each monk to his work.  They are "+
        "so that three may sit together at one table."

   ]));
}
