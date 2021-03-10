#include <std.h>

inherit ROOM;

object ob;
void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_short("Tower into the heavens");
    set_long(
@KAYLA
The massive structure of the tower looms overhead as you stand at the
foot of the steps leading to the front door.  A broken door hangs  
crookedly from the top hinges leaving the small entrance into the 
tower open.
KAYLA
    );
    set_listen("default","The silence gives you a eerie feeling.");
    set_exits(([
       "enter" : "/d/deku/open/stair1",
       "west" : "/d/deku/open/open"
    ] ));
    set_pre_exit_functions(({"enter"}),({"go_enter"}));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("guard")) {
    new("/d/deku/monster/guard1")->move(this_object());
    return 1;
    }
}

int go_enter() {
  if(present("guard")) {
    write("%^MAGENTA%^Brunwick says: %^RESET%^Foolish mortal, you cannot enter.");
    write("               For your foolishness you must pay!");
    say("%^MAGENTA%^Brunwick says: %^RESET%^foolish mortal, you cannot enter.");
    say("              For "+this_player()->query_cap_name()+" foolishness, everyone must pay!");
    if(ob=present("guard",this_object()))ob->kill_ob(this_player(),1);
    return 0;
  }
  return 1;
}
