#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

int count;
void create()
{
	::create();
      set_terrain(WOOD_BUILDING);
      set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_name("Empty Lot");
	set_short("Empty Lot");
	set_long(
         "%^BOLD%^Empty Lot, Tabor%^RESET%^\n"+
         "%^GREEN%^This empty lot is covered with short %^BOLD%^grass "+
         "%^RESET%^%^GREEN%^that has been trampled by recent work here.  "+
         "Piles of %^BOLD%^%^WHITE%^stones %^RESET%^%^GREEN%^and the "+
         "beginnings of walls hint at the future progress.  A %^ORANGE%^"+
         "wooden sign %^GREEN%^has been staked into the ground here "+
         "that you could read.%^RESET%^\n"
	);
	set_smell("default","The scent of fresh grass masks the odors of the city.");
      set_listen("default","The sounds of the city seem muffled here.");
	set_items(([
         ({"sign","wooden sign"}) : ({"This is a wooden sign bearing a "+
            "painted message you could read.",(:TO,"read_sign":),"common"})
	]));
	set_exits(([
      "east" : ROOMDIR+"math10",
	]));
}

void read_sign(){
    string tmp;
    write("%^BOLD%^%^GREEN%^--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--");
    tmp = "
      %^BOLD%^%^BLUE%^       Future Home of the

          %^ORANGE%^  Tabor Potions Shop";

   return tmp;
}
