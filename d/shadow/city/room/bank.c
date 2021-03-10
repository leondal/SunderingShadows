// Written by Fire Dragon. (Descriptions by Melnmarn)

#include <std.h>
#include "../defs.h"

inherit BANK;

void create() {
  ::create();
  set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
  set_short("The Bank of Shadow");
 // set_long("%^BOLD%^Welcome to the Bank of Shadow.%^RESET%^\n"
   //        "This is one of many banks connected to the network. As you "
    //       "look around the room, you notice there is a counter "
      //     "on the far wall with a teller behind it. He looks bored. "
        //   "The rest of the bank is busy with customers. "
          // "A sign by the teller details all commands.");
	set_long("%^BOLD%^%^BLUE%^Made from %^BLACK%^Shadowtop%^BLUE%^"+
		" wood, the inside of the bank has a dark feeling.  "+
		"%^RESET%^%^BLUE%^Deep blue%^BOLD%^ velvet tapestries"+
		" of %^RESET%^%^ORANGE%^c%^BOLD%^%^WHITE%^o%^CYAN%^i"+
		"%^YELLOW%^n%^WHITE%^s%^BLUE%^ and %^CYAN%^p%^YELLOW%^r"+
		"%^BLACK%^e%^RESET%^%^ORANGE%^c%^CYAN%^i%^BOLD%^%^WHITE%^"+
		"o%^YELLOW%^u%^CYAN%^s%^BLUE%^ metals hang around the "+
		"inside of the bank, paying homage to the money that keeps"+
		" them in business.  The floor of the bank is covered with a"+
                " %^RESET%^%^BLUE%^dark blue %^BOLD%^carpet - only bringing "+
		"out the %^BOLD%^%^BLACK%^deeper%^BLUE%^ colors of the wood."+
		"  Blue shaded lamps hang from the ceiling and provide plenty "+
		"of %^WHITE%^light%^BLUE%^ to the inside of the bank - some might"+
		" even say too much light for there doesn't seem to be any shadows."+
		"  A single high desk is built into the northern wall of the bank.  "+
		"A rounded arched opening shows one man sitting behind the desk on the"+
		" other side of the wall.  Next to the opening in the wall is a "+
		"%^YELLOW%^large sign%^BLUE%^ that is clearly lighted for all to "+
		"read.");
  set_items(([
	"lamps" : "%^BOLD%^%^BLUE%^Frosted blue glass lamps hang from the"+
		" ceiling and dispel any shadows that might be within the bank.",
	  "customers" : "They are wandering about aimlessly.",
	  "sign" : "Reading it will give you a list of commands.",
	  "counter" : "A teller waits behind it for you to do something.",
	  "exit" : "It leads out into the street.",
	  "tapestries" : "%^BLUE%^Woven from wool and accented with precious"+
		" metals, each tapestry hangs on a thick %^YELLOW%^gold%^RESET%^"+
		"%^BLUE%^ bar.  The tapestries pay homage to the coins and "+
		"precious metals that require people to safely stroe their "+
		"money in a bank.  One tapestry though stands out from the others,"+
		" showing the image of a windblow man in a long cloak.  "+
		"This tapestry represents Shaundakul, god of trade." ]));
  set_exits( ([ "northwest":ROOMS"plaza" ]) );
  set_smell("default","The smell of money fills your nostrils.");
  set_listen("default","The sounds of rustling coins fill your ears.");
}

void reset(){
   ::reset();
//   if(!present("calcistor")) find_object_or_load("/d/npc/calcistor")->move(TO);
// changing to use one of the new guards so undesirables can't sneak in to use the bank *Styx* 3/27/06
   if(!present("shadow guard")) new("/d/shadow/city/mon/city_guard")->move(TO);
   /* if(!present("shadow guard 2")) new("/d/shadow/city/mon/city_guard")->move(TO); */
}
