//barbarian.c for the masters

#include <std.h>
inherit "/d/shadowgate/newmasters/masters.c";

void create(){
  ::create();
  set_name("barbarian master");
  set_id(({"barbarian master", "barbarian", "master"}));
  set_short("Master Barbarian");
  set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of shadowgate and your quest to make a name for you as a 
barbarian.
OLI
);
  set_class("cleric");
}

void kit_sub_class(){
  write("There are no sub classes for mages at this time.");
  return 1;
}

void help_file(){
   write("The barbarian is a class of enraged primal warriors.");
   write("rage -> This will allow you to enter into a enraged mode");
   return 1;
}

void done(){
   pick_diety();
   return 1;
}