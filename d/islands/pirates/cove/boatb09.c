#include <std.h>
#include "../piratedefs.h"
inherit VAULT;

int searchflag;
object ob;

void create(){
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Sleeping quarters");
   set_short("Sleeping quarters");
   set_long("%^BOLD%^Sleeping quarters%^RESET%^\n"
"This room is of a moderate size, sparsely furnished for easy movement throughout.  Despite it being "
"entirely closed in, it's still partially %^YELLOW%^lit %^RESET%^by several small, round windows that have "
"been placed within the far wall.  The roof, walls and floor are made of the same %^ORANGE%^timber%^RESET%^, "
"a little weathered by time, but have been recently %^WHITE%^%^BOLD%^polished%^RESET%^.  Across the room is "
"a single low-set bed, and a short table with a single drawer.  The doorway leads back to the north, into a "
"short hallway.\n");
   set_smell("default","You smell fresh ocean air, lightly spiced with hints of tobacco.");
   set_listen("default","The waves of the ocean lap at the boat's sides.");
   set_items(([
     ({"deck","boards","wooden boards","roof","walls"}):"Wooden boards form the entirety of the roof, floor "
"and walls.  They are a little weathered over time, but they've obviously been polished recently.",
     "bed":"A single low-set bed sits across the room, beside a short table.",
     "table":"This short table rests on the floor beside the bed.  It has only a single drawer.",
     "drawer":""
   ]));
   set_exits(([
     "north":COVE"boatb08",
     "drawer":STORAGE"general"
   ]));
   set_pre_exit_functions(({"drawer",}),({"GoThroughDoor",}));
   set_invis_exits(({"drawer"}));
   set_door("drawer",STORAGE"general","drawer","nokeyatall");
   set_locked("drawer",1);
   set_door_description("drawer","The table has only a single drawer.");
   set_lock_description("drawer","lock","This is a tiny lock that would probably only fit a very slender key.");
   set_string("drawer","open","stuff");
   set_string("drawer","close","stuff");
   set_alt_doorname("drawer");
}

int GoThroughDoor() {
   tell_object(TP,"What?");
   return 0;
}

void reset() {
    ::reset();
    searchflag = random(2);
}

void init() {
   ::init();
   add_action("peer_fun","peer");
}

int peer_fun(string str) {
   if(str != "drawer") return 0;
   tell_object(TP,"You cannot see far in that direction.");
   return 1;
}

void set_open(string id, int open) {
    if(!id) return;
    if(!doors) return;
    if(!doors[id]) return;
    doors[id]["open"] = open;
    if (open == 1) {
      set_string(id,"open","stuff");
      if(!searchflag) {
        ob = new("/std/obj/coins");
        ob->set_money("platinum", random(5)+5);
        ob->set_money("gold", random(500)+50);
        ob->set_money("silver", random(400)+100);
        ob->set_money("electrum", random(50)+20);
        ob->move(TO);
        searchflag = 1;
      }
    }
    else { set_string(id,"close","stuff"); }
}

void set_string(string id, string which, string str) {
   if(!id) return;
   if(!which) return;
   if(!doors) return;
   if(!doors[id]) return;
   if (which == "open") {
     if(searchflag) str = "You open the drawer, but there's nothing inside it.";
     else str = "You open the drawer, and find a little pouch of coins inside.";
   }
   else str = "The drawer shuts with a click.";
   doors[id][which+" string"] = str;
}
