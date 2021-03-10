#include <std.h>
inherit ROOM;

void look_perch(string str);
int piranhabird_wait;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Scary Bedroom");
  set_long("%^RESET%^%^CYAN%^This room looks more like a lair then a bedroom! The floor appears to be covered with %^ORANGE%^dirt%^RESET%^%^CYAN%^ and the walls with %^GREEN%^grime%^RESET%^%^CYAN%^. There really isn't much here except for a %^ORANGE%^bed%^RESET%^%^CYAN%^ and a %^BOLD%^%^BLACK%^perch%^RESET%^%^CYAN%^ in the corner. Talk about getting the willies!%^RESET%^\n");
  set_smell("default", "It smells like an animals den.");
  set_listen("default", "You can barely hear the chanting now.");
  set_listen("chanting", "As you listen carefully you think it may be coming from the room to the west.");
  set_items( ([
     "bed" : "This bed looks more like a nest then anything else."
]) );
  set_exits( ([
     "west" : "/d/koenig/town/house8"
]) );
   piranhabird_wait = 0;
}
void init()
{
  ::init();
  add_action("look_perch", "look");
}
int look_perch(string str)
{
  object p1, p2, p3, fp1, fp2, fp3;
  if(str != "perch" || piranhabird_wait != 0)
  return 0;
  if(present("piranhabird"))
{
tell_object(this_player(),"You find no more birds on the perch.\n");
tell_room(environment(TP),TPQCN+" is looking the perch over again, but finds no more of the strange birds there.\n");
  return 1;
}
  piranhabird_wait = 1;
  p1 = new("/d/koenig/town/mon/piranhabird.c");
  p1 -> move(this_object());
  p1 -> kill_ob(this_player(),1);

  p2 = new("/d/koenig/town/mon/piranhabird.c");
  p2 -> move(this_object());
  p2 -> kill_ob(this_player(),1);

  p3 = new("/d/koenig/town/mon/piranhabird.c");
  p3 -> move(this_object());
  p3 -> kill_ob(this_player(),1);

  fp1 = new("/d/koenig/town/mon/fpiranhabird.c");
  fp1 -> move(this_object());
  fp1 -> kill_ob(this_player(),1);

  fp2 = new("/d/koenig/town/mon/fpiranhabird.c");
  fp2 -> move(this_object());
  fp2 -> kill_ob(this_player(),1);
  fp3 = new("/d/koenig/town/mon/fpiranhabird.c");
  fp3 -> move(this_object());
  fp3 -> kill_ob(this_player(),1);

tell_object(this_player(), "You find a small flock of piranha birds!\n");
tell_room(environment(TP),TPQCN+" is looking the perch over and finds a small flock of piranha birds!\n");
  return 1;
}
void reset()
{
  ::reset();
  if(piranhabird_wait != 0)
  piranhabird_wait--;
}
