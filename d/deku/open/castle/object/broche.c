// broche.c
// Pator@Shadowgate
// May 19 1995

#include <std.h>

inherit OBJECT;

int times;

void create()
{
::create();
set_id(({"adventurer's broche","broche","gem broche"}));
set_name("adventurer's broche");
set_short("the famous adventurer's broche, with a transparant gem on it.");
set_long(
@BROCHE
This is the famous adventurers broche. It has a transparent gem on it that makes it possible to search for other players within these realms.
To use it type find <player> and for safety check count lights because only a limited number of find's can be done !!
BROCHE
);
set_weight(1);
set_value(5);
}

int count(string str)
{
	if (!str) { notify_fail("wise guy .. counting nothing ????\n");
	return 0; }
	else	{
	if (!(str == "lights" ))
	{ notify_fail("forever... forever... counting something ?\n");
	  return 0;
	}
	else
	{
        if (wizardp(this_player()))
	{
        write("Immortal as you are, all the lights in this world seem to glow inside this gem !\n");
	return 1;
	}
	if (times > 1)
	{ write("You count "+times+" lights inside the gem !!");
	write("You know you can still use it several times.\n");
	return 1;
	}
	else
	{
	write("You notice that just 1 light, so it will be over soon !!\n");
	return 1;
}
}
}
}

int find(string str)
{ int x = 1;
  object ob;
  if (!str)
{ notify_fail("Find nothingness ?? \n");
return 0;
}
	else
	{
	ob = find_player(str);
	if (!ob)
	{
	notify_fail("The gem shows you a gigantic void !!\n");
	 return 0;
	}
	else
	{
          string room = (string)environment(ob)->query_short();
          string name = (string)ob->query_cap_name();
          write("You can find "+name+" in : "+room+"\n");
          if (!(wizardp(this_player())))
	  times--;
	  if (times > 0)
	  { write("You look at the gem : ");
	    x = count("lights");
	    return 1;
	}
	else
	{ write("As the lights in the gem diminsh, the broche breaks down into pieces !\n");
	  destruct(this_object());
	}
	}
	}
}
void init()
{ ::init();
	add_action("find","find");
	add_action("count","count");
	times = (int)this_player()->query_stats("wisdom");
	if (times > 7) {times = 7;}
}
