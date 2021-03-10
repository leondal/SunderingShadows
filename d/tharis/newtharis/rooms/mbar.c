#include <std.h>
#include "../tharis.h"
inherit VAULT;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no sticks", 1);
   set_property("light",2);
   set_property("indoors",1);
   set_short("Turning Spit Tavern");
   set_long("%^RESET%^%^ORANGE%^This tavern is odd for the fact that the room is almost a perfect circle. "
"Tables are arranged on different tiers facing the center of the circle, where a giant series of "
"%^BLACK%^%^BOLD%^spits%^RESET%^%^ORANGE%^ are located. Each spit is tended to by its own cook and each "
"cooks a different sized animal. Conversations are drowned out by the %^RED%^crackling%^ORANGE%^ of the "
"many %^RED%^fires%^ORANGE%^ cooking the food, and laughter from tables of happily drinking citizens of "
"Tharis. There is a counter around the outside of the circle, where waitresses mingle with the customers.");
   set_smell("default","You smell the searing meat from the spit.");
   set_listen("default","You hear the yells of the crowd currently in here mixed with the popping of fats dropping into the fire.");

   set_items(([
      "spit":"%^RED%^This large turning animal is truly impressive. It looks as if someone has put an entire cow on the spit and "
"and is slow roasting it to perfection. You could only guess that with this sized beast it might take more than a day to cook.",
      "tables":"%^ORANGE%^These chipped and dented tables have seen and heard everything.",
      "counter":"%^ORANGE%^This counter is where the waitresses pick up the orders and where some of the regulars lean against.",
   ]));

   set_exits(([
      "west":ROOMS"north4",
   ]));
}

void reset(){
   ::reset();
   if(!present("sacretel")) find_object_or_load(MOBS"sacretel")->move(TO);
}

void init(){
   ::init();
   add_action("read","read");
   if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}

int read(string str){
    object ob;
    int i;
    if(str != "menu")  return 0;
    ob = present("sacretel");
    if(!ob) {
      write("The barkeeper isn't here right now.");
      return 1;
    }
    write("The following great foods are served here at the Turning Spit Tavern.");

    write("--------------------------------------------------------------------");
    write("Tharisian Dark Lager\t\t\t\t"+(int)ob->get_price("tharisian dark lager")+" silver");
    write("Fire Roasted Nuts\t\t\t\t"+(int)ob->get_price("fire roasted nuts")+" silver");
    write("Verbonese Ale\t\t\t\t\t"+ (int)ob->get_price("verbonese ale")+" silver");
    write("Traveler's Meal\t\t\t\t\t"+ (int)ob->get_price("traveler's meal")+" silver");
    write("Spit Turned Meat\t\t\t\t"+ (int)ob->get_price("spit turned meat")+" silver");
    write("Cravnarian Wine\t\t\t\t\t"+ (int)ob->get_price("cravnarian wine")+" silver");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}


