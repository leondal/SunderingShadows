//cavalier.c ... for the masters

#include <std.h>
inherit "/d/shadowgate/masters/masters.c";

void create(){
  ::create();
  set_name("cavalier master");
  set_id(({"cavalier master", "cavalier", "master"}));
  set_short("Master Cavalier");
  set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the
world of shadowgate and your quest to make a name for you as a
paladin.
OLI
  );
  set_class("cavalier");
}

void init(){
  ::init();
  //To be adjusted as needed
}

void kit_sub_class(){
     write("The cavalier or knight of Lawful good alignment and proper attributes and determination may aspire to serve a god as a paladin.");
       write("The cavalier or knight of Lawful evil alignment and proper attributes and determination may aspire to serve a god as a antipaladin.");
  return 1;
}

void help_file(){
  write("The cavalier is a class of warriors");
  write(
@OLI
  charge -> allows a charging attack from horseback
  parry -> allows you to attempt to parry attacks
OLI
  );
  return 1;
}

void done(){
  write("You may enter the world of Shadowgate now...");
  write("Much of thy life is set...but you must always seek");
  write("what you want.");
  write("%^BOLD%^Seek out adventure. Allow the world to benefit ");
  write("%^BOLD%^   you, but never allow it to hurt you.");
  pick_diety();
  return 1;
}
