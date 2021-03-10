// sea description for Ovadexel island

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
  set_short("You are on the Saakrun Sea");
  set_long("	%^BOLD%^You are on a the Saakrune Sea.%^RESET%^\n"
      "You see the dock of an island here.\n");
  set_exits( ([
	       "north" : "/d/shadow/virtual/45,21.sea",
	       "south" : "/d/shadow/virtual/47,21.sea",
	       "east"  : "/d/shadow/virtual/46,22.sea",
	       "west"  : "/d/shadow/virtual/46,20.sea",
          	 "dock"  : "/d/shadow/virtual/sea/ovadexel.dock"
		]));
	
  set_smell("default","The salty air fills your senses.");
  set_listen("default","The waves lap up against the white sand beaches.");
}
		
