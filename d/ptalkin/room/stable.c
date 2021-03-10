#include <std.h>

#include "/d/ptalkin/ptalkin.h"
inherit STABLE;

void create(){
	::create();
	set_id("stables");
	set_short("%^GREEN%^Ptalkin Stables");
	set_long("%^ORANGE%^Hay, oats and water greets your eyes.  You are in the Ptalkin Stables run by D'rater.  A great many horses are kept here waiting to be purchased.  Most are in very good shape and appear to be good, healthy, sturdy mounts.  A few seem to be just resting after long and ardurous journeys.  A small boy runs back and forth watering and feeding the horses while D'rater checks the horses.  You may purchase a horse <buy horse> for 75 gold from this stable.");
set_exits((["out" : PROOM+"room59.c"]));
    set_items(([
       "horses":"You see a row of stalls down the length of the main aisle of the barn.  Over the top of many stall doors, you can see horses looking at you curiously.",
         "aisle":"The aisle is long and wide with a hard packed dirt floor that looks recently raked.  You see stable hands tacking up horses for customers.  Half way down the barn you notice a door with %^CYAN%^Tack Room%^RESET%^ written on it.",
        "stalls":"The stalls all have split doors, an upper and a lower.  During the day, the upper doors are generally open allowing the horses to look out."
    ]));
	set_smell("default","The smell of hay and manure mix together.");
	set_listen("default","An occassional whiny reaches your ears, along with a snort or so.");
set_animal(({"horse"}),({"/realms/tristan/horse"}));
set_animal_price(({"horse"}),({75}));
}

void init(){
  ::init();
add_action("go_enter","enter");
}

int go_enter(string str){
  if(str!="tack room") return 0;
  else{
      this_player()->move_player("/d/shadow/guilds/riders/guild1.c");
    return 1;
  }
}
void reset() {
::reset();
if(!present("d'rater"))
new("/d/ptalkin/mon/d'rater")->move(TO);
}
