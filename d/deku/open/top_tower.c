//made giant only randomly appear (using "reload" variable) - Styx 7/22/01

#include <std.h>

inherit ROOM;
int reload;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_short("Top of the Tower");
    set_long(
@KAYLA
Chill winds whip your clothing as you stand atop the great wall of the
tower.  Through the windows you can see that the Shadowlord forest
stretches to the horizon with its dark leaves shivering in the wind.
Above it all, to the northeast, the tower of the Fortress can be
seen through the dark and gray clouds.
KAYLA
    );
    set_exits(([
       "down" : "/d/deku/open/stair3"
    ] ));
    set_items(([
    ] ));
}

void init(){
   ::init();
   if( TP->is_player() && interactive(TP) && !present("giant") && !reload 
       && !random(2)) {
     reload = 1;
// to watch what all is calling the inits for debugging resets of the flag.
//   if(objectp(find_player("styx")) && interactive(find_player("styx")))
//   tell_object(find_player("styx"),"%^BOLD%^Reload on in "+base_name(TO)+".\n");
   }
//   if(objectp(find_player("styx")) && interactive(find_player("styx")))
//   tell_object(find_player("styx"),"Init was called in "+base_name(TO)+".\n");
}

void reset() {
  ::reset();
  if(reload && !present("giant")) {
    new("/d/deku/monster/cloud")->move(TO);
    reload = 0;
    return 1;
  }
}
