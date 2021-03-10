//updated by ~Circe~ 4/1/05 with new desc, etc.
//stand.c
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
   set_name("The Last Stand");
   set_short("The Last Stand");
   set_long("%^YELLOW%^The Last Stand%^RESET%^\n"+
      "%^ORANGE%^The sticky floor here is strewn with "+
      "%^YELLOW%^sawdust%^RESET%^%^ORANGE%^ meant to soak "+
      "up the spilled %^GREEN%^hops %^ORANGE%^and %^RESET%^"+
      "barley %^ORANGE%^knocked over in the fights that "+
      "seem to be a regular occurrence here.  Despite the "+
      "%^YELLOW%^sawdust%^RESET%^%^ORANGE%^, the floor is "+
      "still sticky, and you notice small %^RED%^dark patches "+
      "%^ORANGE%^that look suspiciously like long-dried blood.  "+
      "Still, this place is not a dive, and it is clearly a "+
      "favorite among the hard-working, rougher citizens of "+
      "Tharis.  %^BLUE%^Miners %^ORANGE%^mingle with %^MAGENTA%^"+
      "off-duty guards %^ORANGE%^and the occasional %^RESET%^"+
      "ruffian%^ORANGE%^.  The thick stone walls here are "+
      "covered with rough %^CYAN%^tapestries %^ORANGE%^"+
      "depicting the labors of hard working men alongside "+
      "the rarer victorious adventurer.  A long bar near "+
      "the far side of the room features a menu you could read, "+
      "while odd %^RED%^stools %^ORANGE%^and %^YELLOW%^chairs "+
      "%^RESET%^%^ORANGE%^are placed around mis-matched "+
      "tables to provide seating.\n"
   );
   set_smell("default","The room smells of spilt ale and and oiled leather.");
   set_listen("default","A hard tone pervades.  People complaining a lot mixes with the oft-angry voices.");
   set_items(([
      "walls":"The walls here are thick and the stone and mortar have not begun to weaken.",
      ({"hangings","tapestries"}) : "The hangings in this "+
         "pub clearly cater to the tastes of the rougher hewn - "+
         "the newly rewarded aventurers, the well paid workers "+
         "and foremen.",
      ({"stools","tables","chairs"}) : "The tables, chairs, and "+
         "stools seem to have been gathered from other taverns "+
         "all across the land.  No two match, and many of them "+
         "have a leg or two made of a different wood than the rest, "+
         "attesting to the fact that they are probably broken "+
         "often in the nightly bar fights.",
      ({"bar","menu"}) : "The long bar in the back of the room "+
         "is usually covered with empty plates and beer mugs.  "+
         "Through the clutter, you see a menu announcing the "+
         "foods and drinks served here.",
      ({"floor","dust","sawdust"}) : "The sawdust on the "+
         "floor looks freshly strewn, probably done daily "+
         "to help clean up the beer, urine, and other bodily "+
         "fluids bathing the floor.  Through the sawdust, "+
         "you see a few smaller patches of what looks to be "+
         "dried blood."
   ]));

   set_exits(([
      "west":ROOMS"main4"
   ]));
   set_door("stand door",ROOMS"main4","west",0);
}


void reset(){
   ::reset();
   if(!present("iladeth")){
      find_object_or_load(MON"iladeth")->move(TO);
   }

}

void init(){
   ::init();
   add_action("read","read");

}


int read(string str){
    object ob;
    int i;
    if(str != "menu")  return 0;
    ob = present("iladeth");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
        return 1;
    }
    write("The following great items are served here at the Last Stand.");

    write("--------------------------------------------------------------------");
    write("Tharisian ale\t\t\t\t\t"+ (int)ob->get_price("tharisian ale") + " copper");
    write("Tharisian dark lager\t\t\t\t"+(int)ob->get_price("tharisian dark lager")+" copper");
    write("Dark liquid\t\t\t\t\t"+(int)ob->get_price("dark liquid")+" copper");
    write("Old Bread\t\t\t\t\t"+ (int)ob->get_price("old bread")+" copper");
    write("Meat stew\t\t\t\t\t"+ (int)ob->get_price("meat stew")+" copper");
    write("Full meal\t\t\t\t\t"+ (int)ob->get_price("full meal")+" copper");
    write("The last stand\t\t\t\t\t"+ (int)ob->get_price("the last stand")+" copper");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}