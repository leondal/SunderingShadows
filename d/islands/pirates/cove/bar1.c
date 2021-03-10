#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create() {
   set_monsters(({MON"citizen",MON"cedwin"}),({2,1}));
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("The Lazy Sailor Tavern");
   set_short("The Lazy Sailor Tavern");
   set_long("%^BOLD%^The Lazy Sailor Tavern%^RESET%^\n"
"You have wandered into one of the local bars.  All sorts of riff-raff are gathered here, yelling and "
"drinking, and generally having what seems like a good time.  From the look of the crowd, most of them are "
"probably smugglers, thieves, cut-throats and who knows what else.  The room itself is a little %^BLUE%^dark "
"%^RESET%^and smelly, and filled with a %^BLACK%^%^BOLD%^light smoky haze%^RESET%^, but the fire is %^RED%^"
"warm%^RESET%^ and the ale is cheap.\n");
   set_smell("default","You smell the scent of stale beer and unwashed bodies.");
   set_listen("default","You hear the rowdy shouts of the bar's patrons.");
   set_items(([
     "menu":"Try reading the menu?",
     ({"patrons","riff-raff","crowd"}):"You can only begin to imagine at the passtimes of the crowd around "
"you - they all have the rough, sinister appearance of smugglers, thieves and cut-throats.",
     ({"fire","fireplace"}):"The lit fireplace sends %^RED%^warmth%^RESET%^ throughout the entire room.",
   ]));
   set_exits(([
     "south":COVE"path7",
   ]));
}

void init() {
    ::init();
    add_action("read", "read");
}

void reset() {
    ::reset();
    if(!present("gatanth"))
	find_object_or_load(MON"barkeep1")->move(TO);
}

int read(string str) {
   object ob;
   int i;

   if(str!="menu") return notify_fail("Read what?");
   ob=present("gatanth");
   if (!ob){
     write("There's noone here to serve you right now.");
     return 1;
   }
   else{
     write("%^GREEN%^\t  =+=+=+=+=+=+=+=+=+= FOOD +=+=+=+=+=+=+=+=+=+=");
     write("%^YELLOW%^\tFish and chips\t\t\t\t %^WHITE%^"+ (int)ob->get_price("fish and chips") + " silver");
     write("%^YELLOW%^\tSeafood surprise\t\t\t %^WHITE%^"+ (int)ob->get_price("seafood surprise") + " silver");
     write("%^YELLOW%^\tChowder\t\t\t\t\t %^WHITE%^"+ (int)ob->get_price("chowder")+" silver");

     write("%^GREEN%^\n\t  =+=+=+=+=+=+=+=+=+ DRINKS =+=+=+=+=+=+=+=+=+=");
     write("%^YELLOW%^\tWater\t\t\t\t\t %^WHITE%^"+(int)ob->get_price("water")+" silver");
     write("%^YELLOW%^\tAle\t\t\t\t\t %^WHITE%^"+(int)ob->get_price("ale")+" silver");
     write("%^YELLOW%^\tBoom-boom\t\t\t\t%^WHITE%^"+(int)ob->get_price("boom-boom")+" silver");
     write("%^YELLOW%^\tWhiskey\t\t\t\t\t%^WHITE%^"+(int)ob->get_price("whiskey")+" silver");
     write("%^YELLOW%^\tBurning Horizon\t\t\t\t%^WHITE%^"+(int)ob->get_price("burning horizon")+" silver");

     write("%^GREEN%^\n\t  =+=+=+=+=+=+=+=+=+=+=+=+=+++=+=+=+=+=+=+=+=+=");
     return 1;
   }
}
