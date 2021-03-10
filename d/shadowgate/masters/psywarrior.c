#include <std.h>
#include <psions.h>
inherit "/d/shadowgate/masters/masters.c";

void create(){
  ::create();
  set_name("psywarrior");
  set_id(({"psywarrior", "master"}));
  set_short("Psywarrior");
  set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of Shadowgate and your quest to make a name for you as a 
psion.
OLI
  );
  set_class("psywarrior");
}

void init(){
  ::init();
  //To be adjusted as needed
}

void kit_sub_class(){
  write("There are no sub classes for psywarriors at this time.");
  return 1;
}

void help_file(){
  write("The psywarrior is a creature of melee prowess and intrinsic intellectual abilities.");
  write(
@OLI
  cast -> to manifest powers
  prepare -> to prepare powers
OLI
);
  return 1;
}

void done(){
  object ob, ob2;
  write("The master gives you a psicrystal and a small pouch.");
  ob = new("/d/magic/psicrystal");
  ob->move(TP);	
  ob2 = new("/d/magic/psi_comp_bag");
  ob2->move(TP);
  write("Use these new tools well as you learn to <manifest> powers.");
  write("Armed with your mental abilities, you must choose a deity whose philosophy echoes your own.");
  pick_diety();
  return 1;
}