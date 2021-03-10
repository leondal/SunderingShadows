#include <std.h>
inherit ROOM;

int open;
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_short("Fortress' Foyer");
    set_long(
@KAYLA
%^YELLOW%^Shadowlord Fortress%^RESET%^
The large entrance hall has been long unused.  Thick dust carpets the
floor.  To either side of the doorway stand antique suits of armor.
The remains of the great oak door lay rotting on the floor just
inside the entrance.
KAYLA
    );
    set_smell("default","A faintly nauseating smell of death and decay hangs in the air.");
    set_exits(([
       "south" : "/d/deku/forest/dforest37-22",
       "north" : "/d/deku/fortress/main_hall"
    ] ));
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_items(([
       "armor" : "Their great age renders them only good for display."
    ] ));
  open = 1;
}

go_north() {
  int lev;
  lev = TP->query_level();
  if(lev < 5) {
    write("%^MAGENTA%^The armor says:%^RESET%^ Young squire, be warned for this isn't a place for you.");
    say("%^MAGENTA%^The armor says:%^RESET%^ Young "+TP->query_race()+" this isn't a place for squires like you, so be warned.");
    say("\n");
    write("\n");
    return 0;
  }
  if(open == 1) {
    tell_room(ETP, "%^RED%^The Knights block your entrance into the fortress.\n");
    new("/d/deku/fortress/monster/knight")->move(TO);
    new("/d/deku/fortress/monster/knight")->move(TO);
    open = 0;
    return 0;
  }
  if(present("knight")) {
    tell_room(ETO,"The knight blocks "+TPQCN+" from entering the fortress!");
    return 0;
  }
  write("%^MAGENTA%^The armor says:%^RESET%^ You think your kind is all powerful, "+TP->query_race()+", but beware the Shadowlord.");
  say("%^MAGENTA%^The armor says:%^RESET%^ The "+TP->query_race()+" thinks they are all powerful, but be warned of the Shadowlord.");
  say("\n");
  write("\n");
  return 1;
}

void reset() {
  ::reset();
  open = 1;
}
