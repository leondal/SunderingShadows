//Octothorpe (2/4/17)
//Three Coins Inn Gold Room
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("Golden Guest Room, Three Coins Inn, Shadow");
   set_short("%^BOLD%^%^WHITE%^Golden Guest Room, Three Coins "+
      "Inn, Shadow%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Golden Guest Room, Three Coins "+
      "Inn, Shadow%^RESET%^\n"+
      "%^YELLOW%^A large, %^RESET%^%^ORANGE%^curtained bed%^BOLD%^, "+
      "set upon a raised dais, takes centerstage in this %^MAGENTA%^"+
      "charming %^ORANGE%^room. Behind it, two shallow %^BLACK%^alcoves "+
      "%^ORANGE%^lead to large windows that allow light to spill across "+
      "the dark %^RESET%^%^ORANGE%^wooden floors%^BOLD%^. The walls are "+
      "in part carved from the same %^BLACK%^light gray stones %^ORANGE%^"+
      "as the rest of the inn, but the upper halves has been painted a "+
      "lovely hue of %^MAGENTA%^lavender%^ORANGE%^, and decorated with "+
      "pictures. One side of the room is home to a %^RESET%^%^ORANGE%^"+
      "table %^BOLD%^and %^RESET%^%^ORANGE%^two grand chairs%^BOLD%^, "+
      "while the other wall features a functioning %^BLACK%^fireplace"+
      "%^ORANGE%^, lined in %^BLACK%^black stones%^ORANGE%^. Lanterns "+
      "are placed strategically around the room, providing a calming "+
      "%^WHITE%^glow %^ORANGE%^to the cozy space. Nearly almost "+
      "everything is accented with at least a touch of g%^RESET%^"+
      "%^ORANGE%^o%^BOLD%^ld. A small, shuttered window allows you to "+
      "peer out the way you came in.%^RESET%^\n");
   set_smell("default","%^BOLD%^%^MAGENTA%^The room smells faintly of "+
      "lavender.%^RESET%^");
   set_listen("default","%^BOLD%^%^WHITE%^The only sounds you hear "+
      "are your own.%^RESET%^");
   set_items(([
      ({"bed","dais"}) : "%^RESET%^%^ORANGE%^This bed is made from "+
         "%^BOLD%^%^BLACK%^dark mahogany wood %^RESET%^%^ORANGE%^that "+
         "is carved into a stately and ornate design. The posts are "+
         "carved into a design of creeping ivy with broad leaves, while "+
         "the foundation of the bed features a forest of large trees and "+
         "impressively detailed fauna and animals. The 4-posted bed is "+
         "draped in %^WHITE%^sheer white curtains %^ORANGE%^that can be "+
         "pulled back or closed, while a thick %^MAGENTA%^purple blanket "+
         "%^ORANGE%^would provide a great amount of comfort and warmth. "+
         "The bed sits upon a raised dais that is covered in a thin "+
         "golden rug.%^RESET%^",
      ({"alcoves","windows"}) : "%^RESET%^%^ORANGE%^The windows are "+
         "tucked away in stone, arched alcoves, and are tucked behind "+
         "sheer %^BOLD%^golden curtains%^RESET%^%^ORANGE%^. A regular "+
         "sized human could easily stand in an alcove and peer out at "+
         "the street below.%^RESET%^",
      "shuttered window" : "%^RESET%^%^ORANGE%^This is a small window "+
         "that opens onto the balcony. It is neatly trimmed in %^BOLD%^"+
         "gold paint%^RESET%^%^ORANGE%^.%^RESET%^",
      ({"walls","pictures"}) : "%^RESET%^%^ORANGE%^The pictures seems "+
         "largely to consist of landscapes from faraway lands such as "+
         "the green forests of Dallyh, the dark, vast keeps of Deku, "+
         "the sandscapes of Eldebaro, and the volcano rising up from "+
         "the middle of Tonerra, to name a few. Perhaps you recognize "+
         "some of them, or perhaps someday you hope see them with your "+
         "own eyes.%^RESET%^",
      ({"table","chairs"}) : "%^RESET%^%^ORANGE%^A simple wooden "+
         "table, draped in a %^BOLD%^golden cloth%^RESET%^%^ORANGE%^, "+
         "sits between two grandly appointed wooden chairs that are "+
         "padded in %^BOLD%^gold velvet%^RESET%^%^ORANGE%^.%^RESET%^",
      "fireplace" : "%^RESET%^%^ORANGE%^Trimmed in gleaming %^BOLD%^"+
         "%^BLACK%^black stone %^RESET%^%^ORANGE%^flecked with "+
         "%^BOLD%^gold%^RESET%^%^ORANGE%^, the fireplace adds a nice "+
         "touch of warmth and light to the room. The fireplace features "+
         "a wide mantle, upon which sits a %^BOLD%^gold vase "+
         "%^RESET%^%^ORANGE%^of %^BOLD%^%^MAGENTA%^lavender%^RESET%^"+
         "%^ORANGE%^.%^RESET%^",
      "lanterns" : "%^RESET%^%^ORANGE%^These old fashioned oil lanterns "+
         "provide a flickering light to the room. They are gilt in "+
         "%^BOLD%^gold %^RESET%^%^ORANGE%^and hang from matching "+
         "hooks.%^RESET%^"
   ]));
   set_exits(([
      "out" : ROOMS"3coinsbalcony",
      "window" : ROOMS"3coinsbalcony"
   ]));
   set_invis_exits(({"window"}));
   set_pre_exit_functions(({"window"}),({"GoThroughDoor"}));
   set_door("gold door",ROOMS"3coinsbalcony","out",0,0);
   set_door_description("gold door","%^YELLOW%^This wooden door is "+
      "painted gold. The top of the door is rounded, but otherwise "+
      "it is plain.%^RESET%^");
}

void init()
{
   ::init();
   add_action("peer_window","peer");
}

int GoThroughDoor()
{
   if(query_verb() == "window")
   {
      tell_object(TP,"You can't fit through the window.");
      return 0;
   }
   return ::GoThroughDoor();
}

int peer_window(string str)
{
   if(!str)
   {
      tell_object(TP,"Peer where");
      return 1;
   }
   if(str == "window" || str == "out window")
   {
      tell_object(TP,"%^BOLD%^You peer out the window and look out onto "+
         "the balcony.%^RESET%^\n");
      tell_room(ETP,"%^BOLD%^"+TPQCN+"peers out the window and "+
         "takes a look outside.\n%^RESET%^",TP);
      TP->force_me("peer window 1");
      return 1;
   }
   return 0;
}