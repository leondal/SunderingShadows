#include <std.h>
#include <objects.h>

inherit ROOM;

int num;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(BUILT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_short("Passageway to the Abyss");
    set_long(
@KAYLA
%^YELLOW%^Passageway to the Abyss%^RESET%^
This passageway provides access to a network of caverns that connects
the Underdark to the surface world.  To the north there is a large
boulder.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/dark/droom9",
       "west" : "/d/deku/dark/droom7"
    ] ));
    set_items(([
       "boulder":"It's very large but maybe one could roll it out of the way."
    ] ));
  num = 1;
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

void reset() {
  ::reset();
  num = 1;
}

int GoThroughDoor() {
  if(num == 1) {
    write("The boulder blocks the entrance.  How do you expect to get past it?");
    return 0;
  }
  if(present("darkelf")) {
    write("The Drow fighter blocks the northward passage!");
    return 0;
  }
  write("The boulder is already rolled to the side, making the northward passage possible.");
  return 1;
}

void init() {
  ::init();
  add_action("roll_b","roll");
}

int roll_b(string str) {
  if(!str) {
    write("You do a nice low roll, coming back up to the standing position.");
    tell_room(ETP,TPQCN+" does a nice low roll, coming back up to the standing position.",TP);
    return 1;
  }
  if(str != "boulder") {
    write("You try to roll around "+str+", with no effect.");
    tell_room(ETP,"%^GREEN%^"+TPQCN+" tries to roll around "+str+", with no effect.",TP);
    return 1;
  }
  if(num == 0) {
    write("The boulder is already rolled off to the side.");
    return 1;
  }
  write("You roll the boulder off to the side, making northward passage possible.");
  tell_room(ETP,TPQCN+" rolls the boulder off to the side.", TP);
  if(!present("darkelf")) {
    tell_room(ETP,"%^YELLOW%^Darkelves surprise you from all sides of the cavern.");
    new("/d/deku/monster/elf")->move(TO);
    new("/d/deku/monster/elf")->move(TO);
    switch(random(3)) {
      case 0:  new("/d/deku/monster/captain")->move(TO);
      case 1:  new("/d/deku/monster/elf")->move(TO);
      case 2:  new("/d/deku/monster/elf")->move(TO);
      break;
    }
  }
  num = 0;
  return 1;
}
