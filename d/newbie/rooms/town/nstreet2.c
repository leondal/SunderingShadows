#include "../../newbie.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Starlight Avenue in Offestry");
   set_short("%^RESET%^%^GREEN%^Starlight Avenue in Offestry");
   set_long("%^RESET%^%^GREEN%^Starlight Avenue in Offestry%^RESET%^\n"
"You are standing on Starlight Avenue, which leads south back to the Offestry town square and continues north a little further.  The cobblestone %^ORANGE%^streets %^RESET%^are smooth beneath your feet, granting passage to the light but "
"steady stream of %^CYAN%^traffic %^RESET%^that passes through the town on a daily basis.  The street is bordered on both "
"sides by a jumble of %^RED%^buildings%^RESET%^. To the east the closest of which is the church with its doors open to welcome all. "
"To the west the closet of which is a strange shop full of paper with its doors open to welcome potential customers.%^RESET%^\n");
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way.");

   
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_items(([
     "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  Starlight Avenue leads south back to the Offestry town square and continues north.%^RESET%^",
     "traffic":"%^CYAN%^A light but steady stream of traffic passes along this street.  Chatter so often fills the air, "
"varying in topic from price bartering, through to tales of grand adventures beyond the gates of the town.%^RESET%^",
     "buildings":"%^RED%^A hodgepodge of buildings rise up along both sides of the street.  Their age and vastly varied "
"styles give a unique appearance to the cosy town around you, where no two buildings are the same.  Nearby is the church and "
"a strange store full of paper.%^RESET%^",
   ]));
   set_exits(([
      "north":MAINTOWN"nstreet3",
      "south":MAINTOWN"nstreet1",
      "east":MAINTOWN"church",
      "west":MAINTOWN"bardcomps",
   ]));
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new(MISCDIR+"street_light")->move(TO);
}