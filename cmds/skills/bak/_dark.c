//      _dark.c
//      Mage ability
//      Created by Valodin, Jan 16, 1993

#include <std.h>

inherit DAEMON;

int cmd_dark(string str)
{
  int dark_level;
  object orb;
  if(str) return 0;
  if((int)this_player()->query_skill("conjuring") < 10)
  {
    notify_fail("You are not skilled enough to cast that spell.\n");
    return 0;
  }
  if((int)this_player()->query_mp() < 7)
  {
    notify_fail("Too low on magic power.\n");
    return 0;
  }
  if(environment(this_player())->query_property("no magic"))
  {
    notify_fail("Something seems to be blocking your concentration.\n");
    return 0;
  }
  this_player()->add_skill_points("conjuring", 10);
  this_player()->add_mp(-7);
  write("Your conjure up an orb of darkness.\n" +
        "You can \"shatter orb\" if you need to.\n");
  say(capitalize((string)this_player()->query_name()) +
      " creates an orb of darkness.\n");
    orb = new("/std/obj/dark_orb");
  orb->set_long("This is a magical orb of darkness created by " +
                capitalize((string)this_player()->query_name()) + ".\n");
  orb->set_creator(this_player());
  orb->move(this_player());
  dark_level = ((int)this_player()->query_skill("conjuring") / 20) + 1;
  if (dark_level < 1) dark_level = 1;
  orb->dark(dark_level,
            ((int)this_player()->query_skill("conjuring") * 10
             / dark_level));
  return 1;
}


void help()
{
  write("Syntax: dark\n\n"+
        "This spell creates an orb of darkness.\n");
}
