#include "../../newbie.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("The Wizard's Hat");
   set_short("%^MAGENTA%^The Wizard's Hat%^RESET%^");
   set_long("%^MAGENTA%^The Wizard's Hat%^RESET%^\n"
"You are standing in the Offestry component shop, known as the Wizard's Hat.  There are scores of %^ORANGE%^shelves "
"%^RESET%^around the room, all filled with various %^CYAN%^potions %^RESET%^and %^RED%^powders%^RESET%^.  There are a "
"few %^BOLD%^cages %^RESET%^in the back of the room that seem to be holding some live animals so that the owner of the "
"shop can harvest the necessary spell components at need.  The shop is a little cluttered, but it isn't hard to find "
"things here.\n\n"
"%^YELLOW%^<help shop> %^RESET%^will give you help on how to use this shop.\n");
   set_smell("default","Your nose itches with all the different musky odors in the shop.");
   set_listen("default","You can hear the soft rustling of the caged animals.");
   set_items(([
     ({"cage","cages","animals"}) : "%^BOLD%^In the back of the room are a few cages that hold animals.  You can see one "
"cage that is kept covered up, and the smell of bat guano comes from it.  It is obvious that these animals are being kept "
"because they produce an easy supply of certain spell components.%^RESET%^",
     "shelves" : "%^ORANGE%^There are dozens of tall, sturdy shelves around the room.  Each one seems to have a wide "
"varity of unusual items that are all needed in spell casting.%^RESET%^",
     "potions" : "%^CYAN%^There are potions of all different colors lining the room.  Some are filled with bubbling "
"liquids, others with what appears to be ordinary water, and some even with blood!  What odd things mages need for their "
"spells.%^RESET%^",
     "powders" : "%^RED%^Numerous bags of powders dot the shelves around the room.  There is everything from diamond dust "
"to ground lizard tail.%^RESET%^",
   ]));
   set_exits(([
     "south" : MAINTOWN"mtower1",
   ]));
}

void reset() {
   ::reset();
   if(!present("breilia")) find_object_or_load(MON"breilia")->move(TO);
}