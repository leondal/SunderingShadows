//      _light.c
//      Mage ability
//      created 011192 by Descartes of Borg
//      Totally redone by Valodin, Jan 15, 1993
//      Added the glowing orb part and the light_level part

#include <std.h>

inherit DAEMON;

int cmd_light(string str)
{
  int light_level;
  object orb;
  if(str) return 0;
    if(total_light(this_player()) < -1) {
	notify_fail("It is too dark.\n");
	return 0;
    }
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
  write("Your conjure up a glowing orb of light.\n" +
        "You can \"extinguish orb\" if you need to.\n" 
         "You can also \"darken\" the orb if it is too bright.");
  say(capitalize((string)this_player()->query_name()) +
      " creates a glowing orb.\n");
    orb = new("/std/obj/light_orb");
  orb->set_long("This is a magical, glowing orb created by " +
                capitalize((string)this_player()->query_name()) + ".\n");
  orb->set_creator(this_player());
  orb->move(this_player());
  light_level = ((int)this_player()->query_skill("conjuring") / 20) + 1;
  if (light_level < 1) light_level = 1;
  orb->light(light_level,
             ((int)this_player()->query_skill("conjuring") * 10
              / light_level));
  return 1;
}


void help()
{
  write("Syntax: <light>\n\n"+
        "This spell creates a glowing orb.\n");
}
