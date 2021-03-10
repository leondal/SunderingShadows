#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("General store");
   set_short("%^BLUE%^General store%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^General store%^RESET%^\n"
"%^BLUE%^This small, yet tidy shop lies nestled upon the main stretch of the docks and warehouse district.  The front "
"of the shop consists of two large, %^CYAN%^gla%^BOLD%^s%^RESET%^%^CYAN%^s windows %^BLUE%^interlaced with slender "
"veins of %^BOLD%^%^BLACK%^iron%^RESET%^%^BLUE%^, to prevent any unwelcome access.  Around the walls are several shelves, "
"each stacked with %^RESET%^simple %^BLUE%^but important items for travellers.  Behind the counter at the back of the room is "
"a list of all the items available in the store, and their prices.  A small, open doorway allows access to the street to "
"the north.%^RESET%^\n");
   set_smell("default","%^ORANGE%^The air in here is thick and a little %^GREEN%^mu%^ORANGE%^st%^GREEN%^y%^ORANGE%^.");
   set_listen("default","%^GREEN%^The soft %^ORANGE%^m%^RESET%^u%^ORANGE%^r%^RESET%^mu%^ORANGE%^r %^GREEN%^of speech "
"heralds customers as they come and go.");

   set_items(([
     ({"wall","walls","roof"}):"%^BLUE%^Seemingly adapted from one of many of the warehouses along the dockfront, the walls "
"and roof of this shop are made of solid %^RED%^zurk%^MAGENTA%^hw%^RED%^ood%^BLUE%^, rather than the stone that shapes most "
"habitations here.  The building is relatively free of dirt and grime, unlike so many of the structures in the area.  Along "
"each of the walls are several shelves, all fully stacked with a variety of wares.%^RESET%^",
     "shelves":"%^BLUE%^The walls are lined with long, %^RED%^zurk%^MAGENTA%^hw%^RED%^ood %^BLUE%^shelves, each carrying "
"simple but important items that a traveller would use.%^RESET%^",
     ({"windows","glass windows"}):"%^BLUE%^Two large, %^CYAN%^gla%^BOLD%^s%^RESET%^%^CYAN%^s windows%^BLUE%^ grant a "
"view of the warehouse district outside the shop, and the gleaming black lake beyond.  Slender veins of metal run through "
"the glass, making them secure from intrusion.%^RESET%^",
   ]));
   set_exits(([
     "north":ROOMS"dock6",
   ]));
}

void reset(){
   ::reset();
   if(!present("gstore")) new(MON"vuzlyn")->move(TO);
}
