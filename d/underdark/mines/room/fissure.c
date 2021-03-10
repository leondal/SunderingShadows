//Octothorpe (8/6/08)
//Underdark Mining Caverns, link to Nienne's Mushroom Cavern

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
   :: create();
   set_property("indoors",1);
   set_property("light",-2);
   set_property("no teleport",1);
   set_travel(RUBBLE);
   set_terrain(NAT_TUNNEL);

   set_name("%^BOLD%^%^BLACK%^A fissure in the %^RESET%^limestone");
   set_short("%^BOLD%^%^BLACK%^A fissure in the %^RESET%^limestone");
   set_long("%^BOLD%^%^BLACK%^A fissure in the %^RESET%^limestone\n "+
   "%^BOLD%^%^BLACK%^This fissure travels through the "+
   "%^RESET%^limestone %^BOLD%^%^BLACK%^for a distance of forty feet "+
   "or so.  The passage is generally four feet wide, but narrows at "+
   "some points to nearly two feet.  A tattered piece of dull %^RESET%^"+
   "%^RED%^red %^BOLD%^%^BLACK%^cloth is snagged on an outcropping of "+
   "%^RESET%^limestone%^BOLD%^%^BLACK%^, about two feet above the bottom "+
   "of the fissure. The bottom of the fissure is choked with detritus,  "+
   "making any progress through the fissure a chore. A narrow crack is "+
   "found on the northern end of the fissure.%^RESET%^\n");
   set_items(([
      "limestone" : "The limestone bears some ripple indentations, and "+
      "periodically displays an unusual assortment of fossils.",
      "fossils" : "These fossils appear to be the remains of a sundry "+
      "variety of exotic marine life.",
      "cloth" : "This piece of cloth is made of a dull %^RED%^red "+
      "%^RESET%^fabric that smells vaguely of a musty canine. It is "+
      "snagged pretty well on an outcropping of limestone.",
      "detritus" : "An assortment of rocky debris is covering the ground.",
      "crack" : "Through the crack you can see an adjoining adjoining "+
      "cavern to the north. Perhaps you can %^BOLD%^enter %^RESET%^the "+
      "crack.",
    ]));
   set_smell("default","The vague scent of a dog permeates the "+
   "fissure.");
   set_listen("default","The sound of dripping water echoes from all "+
   "around.");
   set_exits(([
      "south" :RMS"nucaverna2",
   ]));

}

void init(){
   ::init();
   add_action("enter_fun", "enter");
}

int enter_fun(string str){
   if(!str){
      tell_object(TP,"Enter what?");
      return 1;
   }
   if(str == "crack"){
      tell_object(TP,"You slide through the crack and enter the cavern to "+
      "the north.");
      tell_room(ETP,""+TPQCN+" slides through the crack on the north "+
      "wall.",TP);
      TP->move_player("d/underdark/upper/cross10");
      return 1;
   }
   return 0;
}