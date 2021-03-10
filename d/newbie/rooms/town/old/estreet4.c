#include "../../newbie.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Sunrise Way in Offestry");
   set_short("%^RESET%^%^GREEN%^Sunrise Way in Offestry");
   set_long("%^RESET%^%^GREEN%^Sunrise Way in Offestry%^RESET%^\n"
"You are standing on Sunrise Way, which turns northwest back toward the Offestry town square and south to Shale Street.  "
"The cobblestone %^ORANGE%^streets %^RESET%^are smooth beneath your feet, granting passage to the light but steady stream "
"of %^CYAN%^traffic %^RESET%^that passes through the town on a daily basis.  The street is bordered on the west by a "
"jumble of %^RED%^buildings%^RESET%^, the closest of which is a stable, with its doors open to welcome customers.  A "
"simple wooden %^ORANGE%^palisade %^RESET%^runs along the eastern side of the street, separating the town from the "
"wilderness beyond.%^RESET%^\n");
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way."); 
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The smell of horses and grass is in the air.");
   set_items(([
     "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  Sunrise Way curves northwest, back towards the square to the north, which serves as the heart of this "
"town.  Further south, it leads towards the eastern town gate.%^RESET%^",
     "traffic":"%^CYAN%^A light but steady stream of traffic passes along this street.  Chatter so often fills the air, "
"varying in topic from price bartering, through to tales of grand adventures beyond the gates of the town.%^RESET%^",
     "buildings":"%^RED%^A hodgepodge of buildings rise up along the western side of the street.  Their age and vastly "
"varied styles give a unique appearance to the cosy town around you, where no two buildings are the same.  Nearest is a "
"stable.%^RESET%^",
     "palisade":"%^ORANGE%^A simple palisade of tree trunks runs the length of the eastern side of Sunrise Way.  It "
"rises about six feet from the ground, forming a wooden barrier against the wilderness beyond.  Small gaps between the "
"trunks offer a view of the thick Offestry forest.%^RESET%^",
   ]));
   set_exits(([
      "south":MAINTOWN"eroad1",
      "northwest":MAINTOWN"estreet3",
      "west":MAINTOWN"stable",
   ]));
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new(MISCDIR+"street_light")->move(TO);
}