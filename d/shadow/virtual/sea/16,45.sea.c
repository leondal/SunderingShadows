// sea description for HM quest island

#include <std.h>

inherit ROOM;

int is_virtual()
{
  return 1;
}

int is_water()
{
  return 1;
}

int is_dockentrance()
{
  return 1;
}

void create()
{
  ::create();
  set_indoors(1);
  set_light(2);
     set_property("no teleport",1);
  set_short("You are in the Desert");
  set_long("	%^BOLD%^You are on a the Saakrune Sea.%^RESET%^\n"
      "You see the dock of an island here.\n");
  set_exits( ([
	       "north" : "/d/shadow/virtual/15,45.sea",
	       "south" : "/d/shadow/virtual/17,45.sea",
	       "east"  : "/d/shadow/virtual/16,46.sea",
	       "west"  : "/d/shadow/virtual/16,44.sea",
          "dock"  : "/d/shadow/virtual/sea/hmquest.dock"
		]));
	
  set_smell("default","You can smell the ocean on the beaches.");
  set_listen("default","You can hear the crashing waves to the south.");
}
		
