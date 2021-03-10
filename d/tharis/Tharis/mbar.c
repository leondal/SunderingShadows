//mbar.c

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

   set_short(
@JAVAMAKER
Turning Spit Tavern
JAVAMAKER
   );

   set_long(
@JAVAMAKER
    %^BOLD%^%^MAGENTA%^Turning Spit Tavern%^RESET%^
This is the famous Turning Spit Tavern. Famous for its foods,
its drinks, its conversation, and its atmosphere. The dark room
is filled with tables. There is a serving counter to the back of the
room. The old stone floor is swept clean but still dirty from the years.
The clientele here varies from laborers to servants to petty
merchants. Regardless they like to drink here and they like
to talk here. Some of the great rumors of the world are rumored
to have started here. In the middle of the room is a large well
cooked animal on a turning spit. Every few minutes one of the
workers pours something over it.
JAVAMAKER
   );

   set_smell("default","You smell the searing meat from the spit.");
   set_listen("default","You hear the yells of the crowd currently in here mixed with the popping of fats dropping into the fire.");
   set_items(([
      "spit":"This large turning animal is truly impressive. It looks as if someone has put an entire cow on the spit and and is slow roasting it to perfection. You know that with this sized beast it will take over a day to cook.",
      "tables":"These chipped and dented tables have seen and heard everything.",
      "counter":"This counter is where the waitresses pick up the orders and where some of the regulars lean against. ",
   ]));

   set_exits(([
      "southwest":ROOMS"market2",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
   set_door("door",ROOMS"market2","southwest","blah");
}


void reset(){
   ::reset();
   if(!present("sacretel")){
      find_object_or_load(MON"sacretel")->move(TO);
   }
}

void init(){
   ::init();
      add_action("sign","sign");
      add_action("read","read");

}

int sign(string str){
   if(!present("Sacretel")) return notify_fail("Barkeep isn't here.\n");
   if(!str || (lower_case(str) != "sacretel" && str != "barkeeper" && str != "to the barkeeper")) return 0;
     tell_object(TP,"You flash the barkeeper a sign and he nods to you.");
     tell_room(TO,"The barkeeper nods to "+TPQCN,TP);
     TP->move(ROOMS"sbar");
     return 1;
}


int read(string str){
    object ob;
    int i;
    if(str != "menu")  return 0;
    ob = present("sacretel");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
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


