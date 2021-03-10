//Octothorpe (5/31/10)
//Attaya, Seneca Outskirts
//Borrows color codes and some describes from Circe's boardwalk upgrade
//for continuity
///d/attaya/newseneca/rooms/boardwalk1.c

#include <std.h>

inherit ROOM;

void create() {
   ::create();
   set_property("light",1);
   set_property("indoors",0);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set_climate("tropical");
   set_name("Before the Boardwalk");
   set_short("Before the Boardwalk");
   set_long("This well-worn dirt road travels past the head of a "+
      "%^ORANGE%^wooden boardwalk%^RESET%^.  The %^ORANGE%^boardwalk "+
	  "%^RESET%^leads south from this bluff, rising over the %^YELLOW%^"+
	  "g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e%^RESET%^n beach, "+
	  "before reaching the main gate of Seneca after some distance.  "+
	  "The %^BOLD%^co%^MAGENTA%^q%^WHITE%^ui%^BLACK%^n%^WHITE%^a "+
	  "walls %^RESET%^of the city conceal much of the town, except "+
	  "for the belltowers of the %^BOLD%^Castillo Blanco %^RESET%^"+
	  "and the %^YELLOW%^Cathedral %^RESET%^of Seneca.  A towering "+
	  "ruin lies along the north side of the dirt road, guarded by a "+
	  "complement of granite gargoyles.%^RESET%^\n");
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   set_listen("default","The nearby ocean waves cast a rhythmic roar "+
      "that seems almost soothing at this distance.");
   set_exits(([
      "north" : "/d/attaya/seneca7",
      "south" : "/d/attaya/newseneca/rooms/boardwalk1",
	  "west" : "/d/attaya/seneca2",
	  "east" : "/d/attaya/seneca4"
   ] ));
   set_items(([
      ({"boardwalk","wooden boardwalk"}) : "%^ORANGE%^The boardwalk is "+
         "made of wooden slats and supports and is very well-maintained.  "+
		 "It runs between the wilder regions of Attaya over a chasm to "+
		 "the walled city of %^BOLD%^%^WHITE%^Seneca%^RESET%^%^ORANGE%^.%^RESET%^",
	  ({"town","city","Seneca","seneca"}) : "More properly called a city "+
          "than a town, Seneca has grown over the past several hundred years "+
          "despite the menace of the one called Intruder.  From here, you "+
          "can see many shops and homes, all crowded together within the "+
          "white walls that surround the city protectively.",
      ({"castillo","castillo blanco","Castillo Blanco"}) : "The pure white "+
          "walls of Castillo Blanco shimmer in the light.  The building "+
          "rises three stories, with a belltower soaring high above the walls.",
      ({"cathedral","Cathedral"}) : "The cathedral is encased in gold and "+
          "silver leaf, making it positively sparkle as long as there is "+
          "even a tiny bit of light.  It is almost dazzling to look upon "+
          "from here.",
	  ({"sand","golden sand","beach"}) : "Looking down, you see the "+
          "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
          "%^RESET%^n sand of the beach below.  It looks to be a drop of "+
          "about fifteen feet, though the boardwalk is not very wide.  "+
          "Still, you can't help but wonder if it was a man-made defense after "+
          "Intruder first made himself known.",
      "ruin" : "This sturdy building was constructed out of granite and "+
	      "appears to predate the construction found on the other side "+
		  "of the boardwalk in Seneca.  Along the walls there are a "+
		  "handful of gargoyles which still are poised to protect "+
		  "this ancient structure.",
      "bluff" : "This bluff rises above the beach below and is covered "+
	     "by a smattering of grasses and sea oats."
   ]));
   if(!present("shopkeeper"))   new("/d/token_hunt/high_vendor")->move(TO);
   if(!present("dino"))         new("/d/token_hunt/high_dino")->move(TO);
   if(!present("wagon"))        new("/d/token_hunt/wagon")->move(TO);
}


void reset()
{
    ::reset();
   if(!present("shopkeeper"))   new("/d/token_hunt/high_vendor")->move(TO);
   if(!present("dino"))         new("/d/token_hunt/high_dino")->move(TO);
   if(!present("wagon"))        new("/d/token_hunt/wagon")->move(TO);
}
