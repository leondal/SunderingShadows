
//bard.c ... for the masters

#include <std.h>
inherit "/d/shadowgate/masters/masters.c";

void sorcness();

void create(){
  ::create();
  set_name("Sorcerer master");
  set_id(({"Sorcerer master", "sorcerer", "master"}));
  set_short("Master sorcerer");
  set_long(
@OLI
  This is a grand figure, many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of shadowgate and your quest to make a name for you as a 
sorcerer.
OLI
   );
  set_class("sorcerer");
}

void init(){
  ::init();
  //To be adjusted as needed
}


void kit_sub_class(){
  write("There are no sub classes for bards at this time.");
  return 1;
}

void help_file(){
  write("The sorcerer lives by their own innate power.");
  write(
@OLI
 You are granted several abilities:
 
 prepare -> this allows you to prepare levels of spells
 cast -> this will allow you to cast arcane spells

OLI
 );
  return 1;
}

void done(){
  write("You may enter the world of Shadowgate now...");
  write("Much of thy life is set...but you must always seek");
  write("what you want.");
  write("%^BOLD%^Seek out adventure. Allow the world to benefit ");
  write("%^BOLD%^ you, but never allow it to hurt you.");
  sorcness();
  return 1;
}
  
int sorcness() {
  object ob, ob2;

  write("The master hands you a bag.");
  this_player()->add_exp(1);
  ob2 = new("/d/magic/comp_bag");
  ob2->move(TP);
  TP->add_mp(TP->query_max_mp());
  pick_diety();
  return 1;
}