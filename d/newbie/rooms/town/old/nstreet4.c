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
"You are walking along Starlight Avenue, which runs in a circuit around the northern section of town.  Here can be found "
"what most consider to be higher arts, including the enclaves and towers so commonly frequented by spellcasters.  Despite "
"this, the area appears much the same as the rest of town, with equally mis-matched %^RED%^buildings %^RESET%^that line "
"the roadside.  Smooth cobblestone %^ORANGE%^streets %^RESET%^lie underfoot, over which travels a steady stream of "
"%^CYAN%^traffic %^RESET%^at most hours of the day.  To the south lies a the entry to a shop full of paper, its doors "
"open to welcome customers.\n");
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way.");
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_items(([
     "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  Starlight Avenue leads in an arc around the northern section of town, meeting with Sunrise Way at its "
"eastern-most end, and Sunset Way to the west.%^RESET%^",
     "traffic":"%^CYAN%^A light but steady stream of traffic passes along this street.  Chatter so often fills the air, "
"varying in topic from price bartering, through to tales of grand adventures beyond the gates of the town.%^RESET%^",
     "buildings":"%^RED%^A hodgepodge of buildings rise up along both sides of the street.  Their age and vastly varied "
"styles give a unique appearance to the cosy town around you, where no two buildings are the same.  Nearby lies a "
"shop full of writings.%^RESET%^",
   ]));
   set_exits(([
      "east":MAINTOWN"nstreet5",
      "west":MAINTOWN"nstreet3",
      "south":MAINTOWN"bardcomps",
   ]));
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new(MISCDIR+"street_light")->move(TO);
}
