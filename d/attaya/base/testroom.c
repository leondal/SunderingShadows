#include <std.h>
inherit ROOM;

void create()
{
  ::create();
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("Enterance to the Tower of the Black Dawn.");
   set_long("
Testroom
");
  set_smell("default", "It is terribly cold here.  You are getting frostbite.");
  set_listen("default", "You hear metallic footfalls from within the tower walls.");
  set_items( ([
      "tower" : "You suddenly realize the true scope of the Crystalline Tower.  This massive wall is merely the southeast support structure for an immense crystal tower over a mile in height!  It glistens in the light and looks all at once beautiful and intimidating.",
]) );
  set_exits( ([
     "north" : "/d/attaya/base/oubliette1",
     "south" : "/d/attaya/cliff45"
]) );
  set_invis_exits( ({"north"}) );
}
void init() {
  ::init();
  add_action("enter_mirror", "enter");
  add_action("open_gates", "open");
}
  int enter_mirror(string str) {
  if(str=="mirror") {
 if(present("phalanx")) {
    write("You cannot get past the phalanx.");
    say("The phalanx moves to block "+TPQCN+" as they attempt to enter the mirror.");
    return 1;
}
  write("%^BOLD%^You step through the mirror and find yourself within the tower walls.");
  say(TPQCN+" floats like a wraith through the mirror.");
  set_items( ([
     "mirror" : "You see "+TPQCN+" within a hall of deadly archers."
]) );
  TP->move_player("/d/attaya/base/wall1");
  return 1;
}
  return 0;
}
 int open_gates(string str) {
  if(str=="gates") {
  write("You find an exit leading north.");
  say(TPQCN+" opens the gates and peeks inside.");
  return 1;
}
}

void reset()
{
  ::reset();
if(!present("phalanx"))
     new("/d/attaya/mon/phalanx")->move(TO);
}
