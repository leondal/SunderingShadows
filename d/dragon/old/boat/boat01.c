#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Dark Oliphant");
    set_long("%^BLUE%^%^RED%^
The ship's top deck consists only of weapons cockpits with ladderwells leading
down from them into lower decks of the Dark Oliphant.  The weapons topside 
are obviously ruined, with mosses and ferns tenaciously rooted in the bare deck.
");
    set_exits(([
       "down" : "/d/dragon/boat/boat02",
       "jump" : "/d/dragon/boat/wreck"
    ] ));
    set_listen("default","There is a very slight howl within the wind.");
    set_items(([
       "weapons":"The weapons include six large ballistas, and two large catapults."
    ] ));
    set_invis_exits(({"jump"}));
    set_pre_exit_functions(({"down"}),({"go_dowm"}));
}

void reset() {
    ::reset();
   if(!present("fpirate")) {
    new("/d/dragon/mon/pirate")->move(this_object());
    new("/d/dragon/mon/pirate")->move(this_object());
    new("/d/dragon/mon/pirate")->move(this_object());
    new("/d/dragon/mon/pirate")->move(this_object());
  }
  if(!present("yarik")) {
      new("/d/dragon/mon/pirate")->move(TO);
  }
}

int go_down() {
  if(this_player()->query_invis()) {
    if(present("pirate")) {
      write("%^GREEN%^You somehow tripped on something before entering the cabins below.");
      this_player()->kill_ob(this_object(),0);
      return 0;
    }
      write("%^GREEN%^You manage to go downard before you started any commotion.");
      return 1;
      }
  if(present("pirate")) {
    write("You cannot go down stairs and disturb the master.");
    return 0;
    }
   write("%^GREEN%^You managed to move downstairs without a problem.");
  return 1;
}
