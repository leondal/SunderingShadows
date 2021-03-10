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
"%^CYAN%^traffic %^RESET%^at most hours of the day.  To the northwest lies a tall stone %^BLUE%^tower%^RESET%^, slightly "
"crooked as it stands.  Its doorway crackles with magical energy.\n");
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way.");
   set_listen("default","An occasional crackle or puff of smoke issues from the tower.");
   set_smell("default","The air carries a whiff of sulfur.");
   set_items(([
     "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  Starlight Avenue leads in an arc around the northern section of town, meeting with Sunrise Way at its "
"eastern-most end, and Sunset Way to the west.%^RESET%^",
     "traffic":"%^CYAN%^A light but steady stream of traffic passes along this street.  Chatter so often fills the air, "
"varying in topic from price bartering, through to tales of grand adventures beyond the gates of the town.%^RESET%^",
     "buildings":"%^RED%^A hodgepodge of buildings rise up along both sides of the street.  Their age and vastly varied "
"styles give a unique appearance to the cosy town around you, where no two buildings are the same.  Nearby stands a tall "
"stone tower.%^RESET%^",
     "tower":"%^BLUE%^A tall tower lies northwest off the main road.  Made of stone, it stands a little crooked, leaving "
"you to wonder if this was by poor crafting, or some later damage inflicted upon the structure.  Its doorway stands open, "
"crackling with magical energy.",
   ]));
   set_exits(([
      "northeast":MAINTOWN"nstreet3",
      "south":MAINTOWN"nstreet1",
      "northwest":MAINTOWN"mtower1",
   ]));
   set_pre_exit_functions(({"northwest"}),({"GoThroughDoor"}));
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new(MISCDIR+"street_light")->move(TO);
}

int GoThroughDoor(){
   if(TP->query_true_invis()) return 1;
   if(TP->is_class("mage") || TP->is_class("bard")) {
     tell_object(TP,"%^BOLD%^%^WHITE%^You feel a tingle as you step into the tower.%^RESET%^");
     tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" pauses at the tower doorway, and shimmers momentarily before entering.",TP);
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^As you approach the tower you feel a small jolt of warning.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^"+TPQCN+" pauses and winces slightly before continuing into the tower.%^RESET%^",TP);
   return 1;
}