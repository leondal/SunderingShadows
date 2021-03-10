#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Shadowlord forest");
    set_terrain(HEAVY_FOREST);
    set_travel(FOOT_PATH);
    set_long(
@KAYLA
%^GREEN%^An old footpath meanders through this section of the forest.  The 
trees seem to be greener and much healthier here than what you can
see of the rest of the forest.  Even the undergrowth is more vibrant
as if something is healing this area of whatever ails the rest.
KAYLA
    );
    set_listen("default","You hear a few normal forest sounds here.");
    set_smell("default","A slight scent of peaches wafts on the wind.");
    set_exits(([
      "temple":"/d/magic/temples/silvanus",
       "north" : "/d/deku/open/dforest3-1",
       "east" : "/d/deku/open/dforest3-2a",
    ] ));
    set_items(([
    ] ));
}
void init() {
  ::init();
//    add_action("enter","enter");
}

int enter(string str){
  if(!str) {
    write("what?");
    return 1;
  }
  if(str == "brush") {
    write("You enter the brush, while getting scraped and cut by the vegetation.");
    TP->move_player("/d/guilds/pack/hall/firedock");
    return 1;
  }

}
