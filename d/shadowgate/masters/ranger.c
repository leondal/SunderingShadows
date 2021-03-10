//ranger.c ... for the masters

#include <std.h>
inherit "/d/shadowgate/masters/masters.c";

void create(){
  ::create();
  set_name("ranger master");
  set_id(({"ranger master", "ranger", "master"}));
  set_short("Master of the forest");
  set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of shadowgate and your quest to make a name for you as a 
ranger.
OLI
  );
  set_class("ranger");
}

void init(){
  ::init();
  //To be adjusted as needed
}

void kit_sub_class(){
  write("There are no sub classes for rangers at this time.");
  return 1;
}

void help_file(){
  write("The ranger is a class of warriors.");
  write(
@OLI
  Rangers have special abilities at this time other then spells
Rangers are given the ability to wield two weapons at the same
time without penalty.
  cast -> to cast spells
OLI
  );
  return 1;
}

void done(){
  pick_diety();
  return 1;
}

