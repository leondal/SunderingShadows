#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Barracks of Keep Blacktongue");
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
    set_long(
@KAYLA
%^YELLOW%^Barracks of Keep Blacktongue%^RESET%^
This is the inside of the Keep Blacktongue barracks.  The room
is about 30' across and about 15' high.  There are stairs going
up along eastern wall.  The room is filled with old beds of
all sizes.  Along the side of each bed is a small locker.
KAYLA
    );
     set_smell("default","The musty air is normal for a keep of this size.");
    set_exits(([
       "up" : "/d/deku/keep/barrack_u2",
       "west" : "/d/deku/keep/keepW4"
    ] ));
    set_pre_exit_functions(({"up"}),({"go_up"}));
    set_items(([
       "locker" : "The small lockers hold clothing and various items for the army."
    ] ));
}


void reset() {
  ::reset();
  if(!present("kguard") && !random(2)) {
    new("/d/deku/keep/monster/keep_guard")->move(TO);
    new("/d/deku/keep/monster/keep_guard")->move(TO);
    new("/d/deku/keep/monster/keep_guard")->move(TO);
  }
}
go_up() {
  if(present("kguard")) {
    write("%^MAGENTA%^The guard says: %^RESET%^You cannot go upstairs into "
       "the quarters of my leader.");
    say("%^MAGENTA%^The guard says:  Halt "+TP->query_race()+", you cannot "
       "enter the quarters of my leader.");
    return 0;
  }
  return 1;
}
