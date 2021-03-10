//CT closed for repairs/updates until further notice, enter_mirror function commented out to prevent entry - Octothorpe 1/13/10
//Provisionally reopening CT, even though all the bosses are not updated. - Octothorpe 2/28/10
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create()
{
  ::create();
  set_property("light", 3);
  set_property("indoors", 0);
  set_short("Entrance to the Tower of the Black Dawn.");
   set_long("%^BOLD%^%^RED%^Entrance to the Tower of the Black Dawn
%^BOLD%^%^BLACK%^You stand before the massive gates to the Crystalline Tower of the Kinnesaruda Empire.  It is now that the true scope of the tower grasps you.  The massive walls before you are mearly the southeast support structure for the crystal tower that is over a mile high!  The tower glistens in the soft light.
%^BOLD%^%^WHITE%^A large mirror stands before you, fastened to one of the massive doors..
");
  set_smell("default", "It is terribly cold here.  You are getting frostbite.");
  set_listen("default", "You hear metallic footfalls from within the tower walls.");
  set_items( ([
      "tower" : "You suddenly realize the true scope of the Crystalline Tower.  This massive wall is merely the southeast support structure for an immense crystal tower over a mile in height!  It glistens in the light and looks all at once beautiful and intimidating.",
      "mirror" : "The mirror is nearly 9 feet tall and as wide as the gates upon which it is fastened.  You can see yourself reflected within.  The edges of the mirror seem unstable, almost as if it were made of a liquid.",
      "walls" : "The walls are made of granite and are quite solid.  You can see no seams or creases.",
]) );
  set_exits( ([
     "north" : "/d/attaya/base/oubliette20",
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
 if(present("bishimon")) {
    write("You cannot get past bishimon.");
    say("Bishimon moves to block "+TPQCN+" as they attempt to enter the mirror.");
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
if(!present("bishimon"))
     new("/d/attaya/mon/bishimon")->move(TO);
}
