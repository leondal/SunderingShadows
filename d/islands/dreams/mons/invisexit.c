#include <std.h>
inherit MONSTER;
#include "../defs.h"

void create()
{
  ::create();
  set_name("invisexitmaker");
  set_id(({"InvisExitMaker"}));
  set_short("A floating portal");
  add_limb("body","",0,0,0);
  set_speed(50);
  set("not living",1);
}

void init()
{
  ::init();
  add_action("enter","enter");
  add_action("look","look");
}

void enter(string str)
{
  if(!str)
  {
    tell_room(TP,"Enter what?");
    return 1;
  }
  if(str == "portal")
  {
    TP->move_player(ROOMS+"maze1");
    return 1;
  }
  else
  {
    tell_room(TP,"It doesn't look like you can enter that.");
    return 1;
  }
}

void look(string str)
{
  if(str == "portal")
  {
    tell_room(TP,"A glowing portal hovers before you.  Perhaps "+
	"you can enter it.");
    return 1;
  }
  else
  {
    return;
  }
}
