#include <std.h>
#include "/d/shadow/room/goblin/short.h"
#define RANDTREAS "/d/common/daemon/randtreasure_d"

inherit ROOM;
int searched;
 
void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_indoors(1);
    set_property("no castle", 1);
    set_property("light", 2);
    set_short("%^BLUE%^Goblin stronghold tower%^RESET%^");
    set_long( "%^BLUE%^"
      "You stand inside the upper chamber of one of the small towers that "
	"are used by the %^CYAN%^goblin archers%^BLUE%^"
	" to stand guard within the "
	"stronghold's walls. A small %^GREEN%^pile %^BLUE%^of %^WHITE%^scraps %^BLUE%^"
      "and %^ORANGE%^skins %^BLUE%^lies along the wall.   %^ORANGE%^Small windows%^BLUE%^"
	" adorn the archer tower for the "
	"archers to fire their arrows out of. From here you have a nice "
	"view of the %^GREEN%^forest%^BLUE%^"
	" which surrounds the stronghold."
        "%^RESET%^"
    );
    set_smell("default","It smells of forest air.");
    set_items(([
        "windows":"You can see the surrounding forest through the windows."
	" The windows are used by the archers to fire arrows at attackers "
	"of the stronghold.",
        "forest":"The forest around the stronghold is dark and dense and most "
	"likely filled with hundreds of goblins.",
    (({"pile","skins","scraps"})) : "The small pile of scraps and skins looks "+
       "to be old.  Parts of it are moldy, but it looks like it could be hiding something.",
    ]));
    set_search("default","The pile of skins and scraps draws your attention.");
    set_search("pile", (: TO, "search_pile" :) );
    set_search("scraps", (: TO, "search_pile" :) );
    set_search("skins", (: TO, "search_pile" :) );
    set_exits(([
        "up":RPATH "roof1",
        "down": RPATH "arch1",
    ]));
}

void reset() {
    ::reset();
    if(!present("stronghold goblin"))
      if(!random(6)) {
        switch(random(5)) {
          case 0:  new( MPATH "ranger.c" )->move(TO);
          case 1:  new( MPATH "archer.c" )->move(TO);      break;
          case 2:  new( MPATH "archer.c" )->move(TO);
          case 3:  new( MPATH "archer.c" )->move(TO);      
          case 4:  new( MPATH "ranger.c" )->move(TO);      break;
        }
      }
}
void search_pile(string str) {
   if(present("stronghold goblin")) {
     if(!present("stronghold goblin")->id("summoned monster")){
//check added by Circe to correct problem of your own monsters 
//keeping you from searching 12/5/04
        write("The goblin will not let you search his pile!");
        return;
      }
   }
   if(searched) {
     write("It looks like someone searched here recently.");
     return;
   }
   if(!random(3)) {
      write("All you find this time are skins and moldy scraps.");
      tell_room(ETP,""+TPQCN+" searches the pile of skins and looks disappointed.", TP);
      searched = 1;
      return;
   }
   RANDTREAS->find_stuff(TO,"random");
   write("%^BOLD%^%^BLUE%^You find stuff a goblin probably hid here.\n");
   tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" finds something in the pile of skins.", TP);
   searched = 1;
   return;
} 
