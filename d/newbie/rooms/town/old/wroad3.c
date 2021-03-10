#include "../../newbie.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Shale Street in Offestry");
   set_short("%^RESET%^%^GREEN%^Shale Street in Offestry");
   set_long("%^RESET%^%^GREEN%^Shale Street in Offestry%^RESET%^\n"
"You are standing on Shale Street, which leads west to the town gates, and east to a crossroads.  The cobblestone "
"%^ORANGE%^streets %^RESET%^are smooth beneath your feet, granting passage to the light but steady stream of "
"%^CYAN%^traffic %^RESET%^that passes through the town on a daily basis.  The street is bordered on the north by a "
"jumble of %^RED%^buildings%^RESET%^, the closest of which are the tavern to the west, and the general store to the east"
".  Both have doors that open onto the streets just a few paces away.  A simple wooden %^ORANGE%^palisade %^RESET%^runs "
"along the southern side of the road, separating the town from the wilderness beyond.%^RESET%^\n");
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way.");
   set_listen("default","You hear shouting and singing from the tavern.");
   set_smell("default","The air is fresh and clean.");
   set_items(([
     "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  To the west lies the western gate of town, while east is a crossroads.%^RESET%^",
     "traffic":"%^CYAN%^A light but steady stream of traffic passes along this street.  Chatter so often fills the air, "
"varying in topic from price bartering, through to tales of grand adventures beyond the gates of the town.%^RESET%^",
     "buildings":"%^RED%^A hodgepodge of buildings rise up along the northern side of the street.  Their age and vastly "
"varied styles give a unique appearance to the cosy town around you, where no two buildings are the same.  Nearest is a "
"tavern and a general store.%^RESET%^",
     "palisade":"%^ORANGE%^A simple palisade of tree trunks runs the length of the southern side of Shale Street.  It "
"rises about six feet from the ground, forming a wooden barrier against the wilderness beyond.  Small gaps between the "
"trunks offer a view of the thick Offestry forest.%^RESET%^", 
   ]));
   set_exits(([
      "west":MAINTOWN"wroad2",
      "east":MAINTOWN"wroad4"
   ]));
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new(MISCDIR+"street_light")->move(TO);
}