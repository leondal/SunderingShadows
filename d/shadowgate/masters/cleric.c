//cleric.c ... for the masters

#include <std.h>
inherit "/d/shadowgate/newmasters/masters.c";

void create()
{
    ::create();
    set_name("clerical master");
    set_id(({"cleric master", "cleric", "master"}));
    set_short("Divine master");
    set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of shadowgate and your quest to make a name for you as a 
cleric.
OLI
);
    set_class("cleric");
}

void init()
{
    ::init();
    //To be adjusted as needed
}

void kit_sub_class()
{
    write("There are no sub classes for clerics at this time.");
    return 1;
}

void help_file()
{
  write("The cleric is a subject of the gods.");
  write(
@OLI
  cast -> to cast your spells
  Other abilities have been granted in association with you class.
OLI
);
  return 1;
}

void done() 
{
    pick_diety();
    return 1;
}
