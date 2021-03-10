#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("invisemoter");
  set_property("no detect",1);
  set_id(({"InvisEmoter"}));
  set_short(0);
  set_invis();
  add_limb("body","",0,0,0);
  set("not living",1);
  set_emotes(20,({
	"Good?  You call yourself GOOD?  Where do you think these images "+
	"come from?  This is YOUR dream, from your mind.  You imagined it, "+
	"I've just made it a reality."
    }),0);
}
