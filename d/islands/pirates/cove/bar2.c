#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create() {
   set_monsters(({MON"citizen"}),({2}));
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Seaman's Fare Inn");
   set_short("Seaman's Fare Inn");
   set_long("%^BOLD%^Seaman's Fare Inn%^RESET%^\n"+
"You have wandered into one of the local bars.  It seems a little more quiet here, and better %^YELLOW%^lit"
"%^RESET%^, than the bar across the street, but not by much.  Tables and chairs are scattered around the "
"room, filled with all sorts of patrons, some more shady-looking than others.  The room is relatively clean "
"in comparison to most of the town around you, though patches of %^ORANGE%^dust%^RESET%^ and%^BLACK%^%^BOLD%^"
" dirt%^RESET%^ still cover much of the furniture.  From behind the counter waft the sounds and smells of a "
"busy kitchen.\n");
   set_smell("default","The aroma of fresh seafood reaches your nose.");
   set_listen("default","You hear the murmur of the crowd, over the sound of frying fish.");

   set_items(([
     "menu":"Try reading the menu?",
     ({"counter","kitchen"}):"From behind the counter, the smells and sounds of a busy kitchen are carried "
"through the air.",
     ({"tables","chairs","furniture"}):"Tables and chairs are scattered around the room, mostly filled by a "
"variety of patrons.  A few patches of dirt and dust coat some of the furniture.",
     ({"patrons","crowd"}):"The crowd here seems somewhat varied - some patrons are quite clean and quiet, "
"while others have the rough appearance and demeanor of a common street-rogue.",
   ]));
   set_exits(([
     "north":COVE"path7",
   ]));
}

void init() {
   ::init();
   add_action("read", "read");
}

void reset() {
   ::reset();
   if(!present("soren")) 
     find_object_or_load(MON"barkeep2")->move(TO);
   if(!present("grizon")) 
     find_object_or_load("/d/islands/coralsea/mon/coral_grizon")->move(TO);
}

int read(string str) {
   object ob;
   int i;

   if(str!="menu")
   return notify_fail("Read what?");
   ob=present("soren");
   if (!ob){
     write("The cook seems to be out right now.");
     return 1;
   }
   else{
     write("%^BOLD%^%^CYAN%^\n\t---------------------- %^BLUE%^FOOD %^CYAN%^----------------------");
     write("%^BOLD%^%^WHITE%^\t Seafood basket\t\t\t\t"+ (int)ob->get_price("seafood basket")+" silver");
     write("%^BOLD%^%^WHITE%^\t Swordfish steak\t\t\t"+(int)ob->get_price("swordfish steak")+" silver");
     write("%^BOLD%^%^WHITE%^\t Fresh Salmon\t\t\t\t"+(int)ob->get_price("fresh salmon")+" silver");

     write("%^BOLD%^%^CYAN%^\n\t--------------------- %^BLUE%^DRINKS %^CYAN%^---------------------");
     write("%^BOLD%^%^WHITE%^\t Water\t\t\t\t\t "+(int)ob->get_price("water")+" silver");
     write("%^BOLD%^%^WHITE%^\t Silent Killer\t\t\t\t"+ (int)ob->get_price("silent killer")+" silver");
     write("%^BOLD%^%^WHITE%^\t Rogues Rum\t\t\t\t"+(int)ob->get_price("rogues rum")+" silver");
     write("%^BOLD%^%^WHITE%^\t Ocean Storm\t\t\t\t"+(int)ob->get_price("ocean storm")+" silver");

     write("%^BOLD%^%^CYAN%^\n\t--------------------------------------------------");
     return 1;
   }
}
