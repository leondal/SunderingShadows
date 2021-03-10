//added exit for hitching post.  Circe 4/23/04
#include <std.h>
#include "../defs.h"

inherit STABLE;

void create(){
	::create();
	set_id("stables");
	set_name("Shadow Stables");
	set_short("Shadow Stables");
	set_indoors(1);
      set_terrain(WOOD_BUILDING);
      set_travel(DIRT_ROAD);
	set_long("%^RESET%^%^ORANGE%^These stables stretch for a great distance. "+
"They obviously contain a "+
"great many horses. Here is where folks hoping to set out on new adventures "+
"will get the mounts that will carry them. Posted around the stable "+
"are small notices of returning adventurer's stories of how their mounts "+
"were priceless during their trials. The aisle is lined with stalls. To "+
"the east, there is another large room set with %^RESET%^hitching posts%^RESET%^%^ORANGE%^ where it "+
"looks like riders may leave their mounts while in the city.\n\n"+
"%^RESET%^%^CYAN%^You may %^BOLD%^<buy horse>%^RESET%^%^CYAN%^ for a small price.\n"
);
    set_exits(([ "north": ROOMS"westcross",
             "tackroom" : "/d/shadow/room/city/cguild/cavalier/guild1",
             "east" : ROOMS"shadowtether",
    ]));
    set_items(([
       "horses":"You see a row of stalls down the length of the main aisle of the barn.  Over the top of many stall doors you can see horses looking at you curiously.",
         "aisle":"The aisle is long and wide with a hard packed dirt floor that looks recently raked.  You see stable hands tacking up horses for customers.  Half way down the barn you notice a door with %^CYAN%^Tack Room%^RESET%^ written on it.",
        ({"door","tack room"}) : "You notice the tack room door is open.",
        "stalls":"The stalls all have split doors, an upper and a lower.  "
           "During the day, the upper doors are generally open allowing the "
           "horses to look out."
    ]));
	set_smell("default","The smell of hay and manure mix together.");
	set_listen("default","An occassional whinny reaches your ears, along with a snort or so.");
    set_animal(
        ({"horse","donkey", "pony"}),
        ({"/d/shadow/mon/horse","/d/common/mounts/donkey", "/d/common/mounts/pony"})
        );
    set_animal_price(
        ({"horse","donkey", "pony"}),
        ({75,50,60})
        );
   set_stalls(20);
   ::fill_stalls();
}

/****  Per T and discussions, letting the guild entrance be more obvious now.
Styx 11/20/01

void init(){
  ::init();
add_action("go_enter","enter");
}

int go_enter(string str){
  if(str!="tack room") notify_fail("Enter what?  There are many doors but most are for horses.");
  else{
      TP->move_player("/d/shadow/room/city/cguild/cavalier/guild1.c");
    return 1;
  }
}
**********/
