// updating to conversion of what was a bar and alley to Girruuth's shop

#include <std.h>
#define TCITY "/d/dagger/Torm/city/"
// #define GHOUSE "/d/player_houses/girruuth/"

inherit "/d/dagger/Torm/inherits/whatever";
int searched;

void create() {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_short("Tanar road on the Dagger Sea");
   set_long("A boardwalk starts here on the rocky shore of the Dagger Sea right on the edge of the city itself."
  "  You can see the water drop off sharply into the depths of the harbor south of here, perfect for even the ships with the greatest depth of keel."
   "  Tanar road lies to the west.  A %^BOLD%^%^CYAN%^sign %^RESET%^hangs next to the door of the building to the north, declaring the name of the establishment '%^BOLD%^%^GREEN%^GiGi's%^RESET%^'.  The sign bears depictions of an anvil, axe, and armor."
   );
  set("night long",
   "%^BLUE%^To the north is a building that appears to be undergoing extensive "
   "expansion and remodeling.  A %^BOLD%^%^CYAN%^sign %^RESET%^%^BLUE%^next to the door "
   "proclaims it to be "
   "'%^BOLD%^%^GREEN%^GiGi's%^RESET%^%^BLUE%^' and bears depictions of an anvil, "
   "axe, and armor.  A light fog has settled over the rest of the city, but the "
   "%^YELLOW%^light from the shop to the north %^RESET%^%^BLUE%^seems to chase it away here."
  );
  set_exits(([
    "north":TCITY+"c38",
    "east":TCITY+"c39",
    "south":TCITY+"c49",
    "west":TCITY+"c36",
  ]));
  set_search("sign", (: TO, "search_it" :) );
   set_door("door",TCITY+"c38","north", "gir_key");
   set_open("door",0);
   set_locked("door",0);
   set_items( ([ "sign": "%^BOLD%^%^CYAN%^The sign looks recently painted "
	"and is mounted on the wall to the right of the door at what would "
	"be human eye level.",
   ]));
}

void init() {
   ::init();
   add_action("get_key","retrieve");
}

void reset() {
   ::reset();
   if(!random(10))  searched = 0;
}

int get_key(string str) {
   if( (string)TPQN != "girruuth" && (string)TPQN != "gwenhwyfar" && (string)TPQN != "godzilla" && !avatarp(TP) ) return 1;
   if(str != "key")   
	return notify_fail("Try <retrieve key>");
   if(searched == 1) {
      tell_object(TP,"Your key is missing.");
      return 1;
   }
   new("/d/player_houses/obj/gir_key")->move(TP);
   tell_room(ETP,TPQCN+" reaches behind the sign and pulls out a key.", TP);
   tell_object(TP,"You reach up and retrieve your hidden key from behind the sign.");
   searched = 1;
   return 1;
}

void search_it(string str) {
   if(searched) {
     write("You notice some scratches and find an empty ledge behind the sign "
	"but don't find anything else.");
     return;
   }
   write("You search the sign and find a key on a ledge behind it.");
   tell_room(ETP,TPQCN+" reaches behind the sign and pulls out a key.", TP);
   new("/d/player_houses/obj/gir_key")->move(TP);
   searched = 1;
   return;
} 
