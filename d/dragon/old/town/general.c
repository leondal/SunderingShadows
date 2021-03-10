// /d/dragon/town/general.c
#include <std.h>
#include <objects.h>
      
inherit ROOM;
      
void create() {
  room::create();
  set_light(2);
  set_indoors(1);
  set_short("General Store of Sanctuary");
  set_long("%^BLUE%^%^BOLD%^
Above the counter a sign reads %^CYAN%^'Sanctuary Traders' Hall'%^BLUE%^.  The walls
of this building are in desperate need of paint, yet the structure
itself seems to have weathered the passage of time and war.  The
Hall actually consists of two buildings:  the trade-hall and an
adjoining stable sealed by a pair of heavy wooden doors to the east.
  ");
     set_exits((["south":"/d/dragon/town/roadE1",
                 "north":"/d/dragon/town/tchamber",
                 "east":"/d/dragon/town/stable"]));
      set_items(([
"shelves":"These shelves are stocked with the goods of adventure."
        ] ));
    set_pre_exit_functions(({"north"}),({"go_north"}));
  set_pre_exit_functions(({"east"}),({"go_east"}));
  }
void reset(){
  ::reset();
  if(!present("skaldar")) {
    new("/d/dragon/mon/skaldar")->move(this_object());
  }
}

int go_east() {
  tell_room(ETP,"%^GREEN%^"+TPQCN+" moves through the double doors, and an overwhelming smell of horse enters the room.\n",TP);
  return 1;
}

int go_north() {
  write("You entered the north door, into the Trading Chamber.");
  tell_room(ETP,"%^GREEN%^"+TPQCN+" goes through the north door, into the Trading Chamber.\n",TP);
  return 1;
}
