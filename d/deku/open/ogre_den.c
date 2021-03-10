#include <std.h>

int open;
inherit "/d/deku/inherits/vexia-lair.c";

void create() {
    ::create();
    set_short("Vexia's Ogre Den");
    set_long(
@KAYLA
This chamber is large and, like the rest, only dimly lit.  The walls are 
stone but unfinished and it reeks of the stench of ogres.  Three piles 
of furs lie on the floor and scattered around them are piles of rocks and 
dirt.  Some large rocks appear to have been used for crude seating.   
KAYLA
    );
    set_smell("default","The room smells strongly of sweat and the "
       "filthy furs.");
    set_exits(([ "east" : "/d/deku/open/cave_r7" ] ));
    set_items(([
       "furs" : "These are nasty, dirty furs the ogres apparently tossed aside.",
       "rocks" : "They are just rocks of various sizes, most very dirty."
    ] ));
    set_search("default","You can't help but notice the large pile of smelly furs.");
    set_search("furs", (: TO, "search_it" :) );
    open = 0;
}

void reset() {
  int r;
  ::reset();
  if(!present("ogre")) {
    new("/d/deku/monster/ogre1")->move(TO);
    new("/d/deku/monster/ogre1")->move(TO);
  }
  if(!present("chest")){
    r=random(2);
    if(r==0)  new("/d/hm_quest/chests/chest14")->move(TO);
    else  new("/d/hm_quest/chests/chest22")->move(TO);
  }
  open = 0;
}

void init() {
  ::init();
}

int search_it(string str) {
  object money;
  if(!str) {
    write("Search what?");
    return 1;
  }
  if(str != "furs") {
    write("You cannot search that.");
    return 1;
  }
  if(present("ogre guard")) {
    tell_room(ETP,"%^ORANGE%^The ogres guard the furs from being searched!");
    return 1;
  }
  if(open || !random(3)) {
    write("You search the furs but find nothing.");
    say(TPQCN+" searches the furs and finds nothing.");
    return 1;
  }
  write("You search the furs and find:  %^YELLOW%^A pile of gold.");
  say(TPQCN+" searches the furs and finds a pile of gold.");
  money = new("/std/obj/coins");
  money ->set_money("gold",random(100)+50);
  money->move(TO);
  if(!random(3)) {
    "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"random");
    tell_room(ETP,"%^BOLD%^Something else falls out of the furs too!");
  }
  open = 1;
  return 1;
}

