// The Royal Bank of Tabor
// Thorn@ShadowGate
// 010118
// Tabor
// bank.c

#include <std.h>
#include "../include/tabor.h"

inherit BANK;
string getBankId() { return "azha";}

void create() 
{
  ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
  set_light(2);
  set_short("The Royal Bank of Tabor");
  set_long(
@TABOR
%^BOLD%^The Royal Bank of Tabor, Branch of Azha's Merchant Bank%^RESET%^
This is the lobby of the small, but very ornate Royal Bank of Tabor. 
Founded by royal charter, this bank controls the finances in the city 
and the surrounding areas.  On the floor are relatively good-quality 
rugs covering a stone floor, not too strange considering that the 
patrons of the bank are of the middle to upper class.

As you look around the room, you notice there is a counter on the far 
wall, with a teller behind it. He looks bored. The rest of the bank is 
busy with customers. 

A sign by the teller details all commands.
TABOR
  );
  set_items(
	(["bank" : "You are in its huge lobby. There is a counter in "
	    "front of you\nand and exit behind you.",
	  "customers" : "They are wandering about aimlessly.",
	  "sign" : "Reading it will give you a list of commands.",
	  "counter" : "A teller waits behind it for you to do something.",
	  "exit" : "It leads out into the street."]));
  set_exits( ([ 
    "north" : ROOMDIR+"gwy3", 
    "west" : ROOMDIR+"math6"   
  ]) );
  set_smell("default","The smell of money fills your nostrils.");
  set_listen("default","The sounds of rustling coins fill your ears.");
}

void reset(){
   ::reset();
   if(!present("ash")) new("/d/npc/ash")->move(TO);
   if(!present("guard")) new("/d/darkwood/tabor/mon/guard")->move(TO);
}
