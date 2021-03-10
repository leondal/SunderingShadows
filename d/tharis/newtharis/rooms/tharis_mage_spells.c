#include <std.h>
#include "../tharis.h"
inherit ROOM;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Mage Tower - Coded in October 2005 by Circe
// Player Designed Area - Originally Player "shop" 
// Never installed into game prior to Tharis City Remodle
// Design work by Sevotharte & Nightfall, finished by Azalon
// Incorporated into the Tharis City Remodle in February 2009 by Ari

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_name("The Djinn Spell Exchange");    
   set_short("%^MAGENTA%^The Djinn Spell Exchange%^RESET%^");
   set_long("%^ORANGE%^Continuing further eastward down the "+
      "curved corridor you find yourself in a much better lit "+
      "room.  The illumination is %^YELLOW%^gentle%^RESET%^ "+
      "%^ORANGE%^instead of harsh, as the light that comes "+
      "through the windows is %^WHITE%^diffused %^ORANGE%^through "+
      "the %^BOLD%^%^RED%^s%^GREEN%^t%^YELLOW%^a%^BLUE%^i"+
      "%^MAGENTA%^n%^WHITE%^e%^CYAN%^d %^RED%^g%^BLUE%^l%^GREEN%^"+
      "a%^YELLOW%^s%^CYAN%^s%^RESET%^%^ORANGE%^, casting pretty, "+
      "%^BOLD%^%^GREEN%^c%^MAGENTA%^o%^CYAN%^l%^YELLOW%^o%^RED%^r"+
      "%^BLUE%^f%^WHITE%^u%^RESET%^%^MAGENTA%^l %^ORANGE%^shadows "+
      "on the %^BOLD%^%^WHITE%^wh%^YELLOW%^i%^WHITE%^te m%^YELLOW%^"+
      "a%^WHITE%^r%^YELLOW%^b%^WHITE%^le%^RESET%^ %^ORANGE%^floor.  "+
      "There are three narrow shelving unit mahogany cabinets "+
      "around the walls, one containing leather-bound books, the "+
      "other scrolls, and the last one writing supplies like "+
      "%^RED%^feathers%^ORANGE%^, %^BLUE%^ink pots %^ORANGE%^and "+
      "%^BOLD%^%^BLACK%^blotters%^RESET%^%^ORANGE%^.  Instead "+
      "of a dominating, traditional desk, this room contains three "+
      "narrow, strange looking desk-pedestals.  They are all "+
      "identical and made of mahogany.  Each one has a flat base "+
      "from which a single leg rises, ending to a sloping slab, "+
      "used for writing or holding a book open for reading.  "+
      "Behind each narrow desk, a single folding stool can be "+
      "found, crafted once again from mahogany.  The room "+
      "belongs to %^MAGENTA%^Zeki Duman Effendi, %^BOLD%^"+
      "%^CYAN%^Resident Alchemist.%^RESET%^\n\n<help shop> "+
      "will give you help on how to use the shop\n");
   set_smell("default","%^YELLOW%^It smells softly of parchment "+
      "and the musky smell of oil-lamps.%^RESET%^");
   set_listen("default","%^CYAN%^It is quiet, apart from the "+
      "strange tune of the cord instrument somewhere in the distance.%^RESET%^");
   set_exits(([
           "northeast":ROOMS"tharis_mage_entrance"
   ]));
}

void reset(){
   ::reset();
   if(!present("zeki")) new(MOBS"zeki")->move(TO);
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}