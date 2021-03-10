//druid.c ... for the masters

#include <std.h>
inherit "/d/shadowgate/masters/masters.c";

void create(){
  ::create();
  set_name("Druidical master");
  set_id(({"Druid master", "Druid", "master"}));
  set_short("Master of the forest");
  set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of shadowgate and your quest to make a name for you as a 
druid.
OLI
);
  set_class("druid");
}

void init(){
  ::init();
  //To be adjusted as needed
}


void kit_sub_class(){
  write("There are no sub classes for Druids at this time.");
  return 1;
}

void help_file(){
  write(
@PATOR
The druid is a subject of the forest and the living.
You have to obey the laws Mother Nature has drawn up
in all her goodness and grandness.
Life as a druid is a life of neutrality. A true druid
will be always neutral and will so benefit of all the
powers of nature. The more you survey the ways of
Panoramix the nestor of all druids, the more you will
learn to love AND control the nature around you.

If you have any questions, just ask the druidmaster who
will always be there for all your druidic questions.
PATOR
  );
  return 1;
}

void done(){
  pick_diety();
  return 1;
}

