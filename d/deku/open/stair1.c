#include <std.h>

inherit ROOM;
int reload;
object ob;

void create() {
    ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_short("Darken Stairway");
    set_long(
@KAYLA
As you enter the tower, reek of decay rushes into your lungs making it
hard to breath.  Only a small amount of light enters from the front
door which hangs in the wind.  The stairway is in complete darkness.
The steps creak as you walk upward into the darkness.
KAYLA
    );
    set_smell("default","The smell of death is all around you.");
    set_listen("default","You hear your breathing echo off the stone walls.");
    set_exits(([
       "up" : "/d/deku/open/stair2",
       "out" : "/d/deku/forest/dforest35-15",
    ] ));
    set_items(([
    ] ));
}

void init(){
   ::init();
   if(userp(TP) && interactive(TP) && !reload && !random(3))
   reload = 1;
}

void reset() {
  ::reset();
  if(reload && !present("bandit") && !random(2)) {
    ob = new("/d/deku/monster/bandit");
      ob->set_speed(150);
      ob->move(TO);
    ob = new("/d/deku/monster/bandit");
      ob->move(TO);
      ob->command("block up");
    if(!random(3)) new("/d/deku/monster/bandit")->move(TO);
    reload = 0;
    return;
  }
  return;
}
