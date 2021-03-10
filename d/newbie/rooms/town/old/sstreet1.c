#include "../../newbie.h"
inherit ROOM;

void create() {
   object ob;
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Goldstone Road in Offestry");
   set_short("%^RESET%^%^GREEN%^Goldstone Road in Offestry");
   set_long("%^RESET%^%^GREEN%^Goldstone Road in Offestry%^RESET%^\n"
"You are standing on Goldstone Road, which leads north to the Offestry town square and south to Shale street.  The "
"cobblestone %^ORANGE%^streets %^RESET%^are smooth beneath your feet, granting passage to the light but steady stream of "
"%^CYAN%^traffic %^RESET%^that passes through the town on a daily basis.  The street is bordered on both sides by a "
"jumble of %^RED%^buildings%^RESET%^, the closest of which are the general store on the western side of the road, and "
"the bank just opposite on the eastern side.  Both have their doors open to welcome customers.%^RESET%^\n");
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way.%^RESET%^");
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_items(([
     "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  Goldstone Road leads towards the square to the north, which serves as the heart of this town, while to the south it intersects with Shale Street.%^RESET%^",
     "traffic":"%^CYAN%^A light but steady stream of traffic passes along this street.  Chatter so often fills the air, "
"varying in topic from price bartering, through to tales of grand adventures beyond the gates of the town.%^RESET%^",
     "buildings":"%^RED%^A hodgepodge of buildings rise up along either side of the street.  Their age and vastly varied "
"styles give a unique appearance to the cosy town around you, where no two buildings are the same.  Nearest are a bank "
"and a general store.%^RESET%^",
   ]));
   set_exits(([
      "north":MAINTOWN"square",
      "south":MAINTOWN"sstreet2",
      "east":MAINTOWN"bank",
      "west":MAINTOWN"general",
   ]));
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new(MISCDIR+"street_light")->move(TO);
}
