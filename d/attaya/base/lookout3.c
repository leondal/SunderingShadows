#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create()
{
  ::create();
  set_property("light", 3);
  set_property("indoors", 1);
  set_short("Gate to the South Wall Fortress.");
   set_long("
    This is the gate to the Southern Wall Fortress, perhaps the oldest part of the crystalline tower.  The rest of the unbelievable tower was built around the fortress that once stood upon this spot.  A crest that is barely recognizable marks the former empire that based itself here before the iron grasp of the Kinnesaruda strangled them.

    It houses guardposts for knights on either side of the gate.
");
  set_listen("default", "Once again, the unsettling sound of metal footsteps echoes inside the fortress..");
  set_items( ([
      "walls" : "The walls are made of granite and are quite solid.  You can see no seams or creases.",
       "outposts" : "They are small shacks with pointy wooden roofs.",
       "fortress" : "The fortress has been built into the southern wall of the crystalline tower.",
      "gate" : "The large metal gate is a remnant of the old fortress.",
]) );
  set_exits( ([
     "north" : "/d/attaya/base/lookout2",
]) );
}
void init() {
  ::init();
  add_action("enter_gate", "enter");
  add_action("open_gate", "open");
}
  int enter_gate(string str) {
  if(str=="gate") {
 if(present("knight")) {
    write("The powerful undead knight blocks you.");
    say("You watch "+TPQCN+" get blocked by the knight.");
    return 1;
}
  write("%^BOLD%^%^GREEN%^You enter the fortress.");
  say(TPQCN+" enters the fortress.");
  set_items( ([
     "gate" : "It is no longer blocked."
]) );
  TP->move_player("/d/attaya/base/lookout10");
  write("%^BOLD%^%^BLUE%^Your eyes adjust to the darkness.");
  return 1;
}
  return 0;
}
 int open_gate(string str) {
  if(str=="gate") {
if(present("knight")) {
  write("It is already open, if ONLY you could get past the knight..");
  return 1;
}
  write("It is no longer guarded.");
}
}

void reset()
{
  ::reset();
if(!present("knight"))
     new("/d/attaya/mon/knight")->move(TO);
}
