//paladin.c ... for the masters

#include <std.h>
inherit "/d/shadowgate/newmasters/masters.c";

void create()
{
    ::create();
    set_name("paladin master");
    set_id(({"paladin master", "paladin", "master"}));
    set_short("Master Paladin");
    set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of shadowgate and your quest to make a name for you as a 
paladin.
OLI
    );
    set_class("paladin");
}

void init(){
  ::init();
  //To be adjusted as needed
}

void kit_sub_class(){
  write("There are no sub classes for paladins at this time.");
  return 1;
}

void help_file(){
  write("The paladin is a class of warriors");
  write(
@OLI
  charge -> allows a charging attack from horseback
  parry -> allows you to attempt to parry attacks
OLI
  );
  return 1;
}

void done(){
  pick_diety();
  return 1;
}


