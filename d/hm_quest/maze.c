// Basic Inheritable file for "THE" MAZE
// Fire Dragon 

#include <std.h>

inherit ROOM;

void create() 
{
  ::create();
  set_name("MAZE");
  set_properties( ([ "light" : 2 ]) );
	set_short("Grassy hedge maze");
	set_long("You are in a grassy hedge maze.  All you can do is just TRY to "
	"figure your way through.  Although you're not sure there really "
	"IS a way through this thing!!!");
	set_smell("default", "%^GREEN%^The odours of new leaves, fragrant flowers and freshly mown grass invade your senses.");
	set_listen("default", "%^BOLD%^BLUE%^You hear birds chirping, small creatures scurrying and the wind through the hedge.");
  set_exits( ([ ]) );
	set_items( ([ ({"hedge", "grass"}) : "The hedges look nicely trimmed "
	"and the grass freshly cut, so you "
                                          "think that this is no ordinary "
                                          "maze. There must be something REAL "
                                          "special at the center!" 
           ]) );
}

void init()
{
  ::init();
  add_action("xyzzy", "xyzzy");
}

int xyzzy()
{
  write("As you speak the words \"XYZZY\", You feel light headed, and find"
        "yourself standing at the start of the maze again. And wondering if "
        "there is an easier way to get through the maze!");
  this_player()->move("/d/hm_quest/enterence");
  return 1;
}

string pass_exit(string str, string dept)
{

  string sub;

  switch(random(4))
   {
     case 0: sub = "a";
             break;
     case 1: sub = "b";
             break;
     case 2: sub = "c";
             break;
     case 3: sub = "d";
             break;
   }

  return "/d/hm_quest/"+ str +"/"+ sub +"/"+ dept +"";

}

int new_disc(int section)
{
  switch(section)
   {
	case 1: set_long("You are in a grassy hedge maze.  All you can do is "
	"just TRY to figure your way through.  Although you're "
	"not sure there really is a way through this thing!!!");
             break;
	case 2: set_long("The large hedges around you are so thick and tall, "
                      "they serve almost as brick walls keeping you on a "
                      "path to somewhere. Though as you look at all the paths "
                      "up ahead of you.. You wonder if this isn't more of a "
	"maze than a large hedge forest.");
             break;
	case 3: set_long("You are in a grassy hedge maze.  All you can do is "
	"just TRY to figure your way through.. Although you're "
	"not sure there really IS a way through this thing!!!");
             break;
	case 4: set_long("You are in a grassy hedge maze.  All you can do is "
	"just TRY to figure your way through.. Although you're "
	"not sure there really IS a way through this thing!!!");
             break;
	case 6: set_long("You are in a grassy hedge maze.  All you can do is "
	"just TRY to figure your way through.. Although you're "
	"not sure there really IS a way through this thing!!!");
             break;
	case 7: set_long("You are in a grassy hedge maze.  All you can do is "
	"just TRY to figure your way through.. Although you're "
	"not sure there really IS a way through this thing!!!");
             break;
	case 8: set_long("You are in a grassy hedge maze.  All you can do is "
	"just TRY to figure your way through.. Although you're "
	"not sure there really IS a way through this thing!!!");
             break;
	case 9: set_long("You are in a grassy hedge maze.  All you can do is "
	"just TRY to figure your way through.. Although you're "
	"not sure there really IS a way through this thing!!!");
             break;
   }
}

