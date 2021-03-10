//apothecary.c - Coded by Circe 11/27/03 
#include <std.h>
#include "../koenig.h"

inherit ROOM;

int items;

void create() {
items = 1;
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_short("An abandoned apothecary");
    set_name("An abandoned apothecary");
    set_long(
      "This building seems to be in slightly better shape than most of the "+
      "others lining the street.  However, it too has been mangled and burned "+
      "beyond repair.  Tall, wooden %^ORANGE%^bookshelves %^RESET%^line three "+
      "of the four walls.  They are set within shallow %^BOLD%^%^BLACK%^alcoves "+
      "%^RESET%^and were obviously very well made.  Now, they hold only broken "+
      "%^CYAN%^jars %^RESET%^filled with %^BOLD%^%^BLACK%^blackened liquids %^RESET%^"+
      "and other disturbing items.  Tiny %^BLUE%^boxes %^RESET%^and %^GREEN%^barrels "+
      "%^RESET%^hold various other supplies that were once useful in the arcane arts.  "+
      "A burned %^MAGENTA%^sign %^RESET%^hanging on the eastern wall behind a "+
      "long, low %^ORANGE%^counter%^RESET%^.  The room is covered in %^BOLD%^%^BLACK%^soot "+
      "%^RESET%^that stirs and rises on the wind."+
      "\n"
    );
    set_listen("default","The sound of water dripping reaches your ears.");
    set_smell("default","The acrid scent of sulfur mixes with an earthy fragrance of mold.");
    set_listen("water","The liquid seems to be dripping on the shelves from one of the jars.");
    set_listen("dripping","The liquid seems to be dripping on the shelves from one of the jars.");
    set_items(([
      ({"shelf","shelves","bookshelves","book shelves"}) : "The wooden bookshelves "+
         "reach from floor to ceiling and line three of the walls.  Many of the shelves "+
         "themselves have collapsed and the few remaining ones hold various odds and ends.",
      ({"alcoves","alcove"}) : "The recessed alcoves are set within the walls, allowing the "+
         "bookshelves to hold many supplies while still leaving the small building plenty of "+
         "floor space.",
      ({"jars","liquids","boxes","barrels"}) : "Bits of fur, bat guano, crystals, and other "+
         "remnants of magical supplies lie in ruins on the shelves.  The jars have been "+
         "filled with soot and ash, and most of the boxes have been destroyed as well.  It "+
         "looks as though most have been destroyed, but it might be possible to find something "+
         "of use.",
      ({"sign","burned sign"}) : "The sign, though charred, still reveals that this shop "+
         "was once an apothecary that provided the small village with healing as well as "+
         "with the few strange supplies it required for the occasional arcane caster.",
      ({"soot","ash"}) : "The fine layer of soot and ash covers every surface with a "+
         "gray sheen",
      ({"counter","wooden counter"}) : "The long counter was once used to treat patients "+
         "as well as conduct transactions.  Now only dust and ash lies there."
    ]));
    set_search("default","The shelves look like they may hold a few items of use.");
    set_search("shelves",(:TO, "search_shelves":) );
    set_search("bookshelves",(:TO, "search_shelves":) );
    set_exits(([
      "west" : VILROOMS"k_road11"
    ]));
}

void search_shelves(){
   if(!items){
      tell_object(TP,"All the shelves are disturbed as if they have been searched thoroughly.");
      return;
   }
   switch(random(6)){
      case 0..2:  tell_object(TP,"You search the jars but find nothing of interest.");
                  tell_room(ETP,""+TPQCN+" searches the shelves but finds nothing.",TP);
                  break;
      case 3:  "/d/common/daemon/randstuff_d"->find_stuff(TO,"kit",random(4)+2);
               tell_object(TP,"You find a few healing vials in the rubble of the shelves!");
               tell_room(ETP,"Searching the shelves, "+TPQCN+" finds something!",TP);
               break;
      case 4..5:  "/d/common/daemon/randstuff_d"->find_stuff(TO,"component",random(4)+2);
               tell_object(TP,"You find something in the rubble of the shelves!");
               tell_room(ETP,"Searching the shelves, "+TPQCN+" finds something!",TP);
               break;
   }
   items = 0;
}
