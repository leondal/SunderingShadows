//	The Center of The Imperial Gardens of Tsarven
//	Thorn@Shadowgate
//	11/24/95
//	The Emperor's Palace, Tsarven
//	gazebo.c

#include <std.h>

inherit ROOM;

void create() {
  object ob;
    ::create();
    set_light(2);
    set_indoors(0);
    set_short("A Gazebo in the Emperor's Garden");
		set_long(
@THORN
You are now in the shelter of a gazebo in the Emperor's garden.
It sits on an island in the middle of a little duck pond in the 
very center of the garden.  Climatis plants climb the walls of 
little building, and you see some seats where the nobles of the
court take their ladies to read them poetry, romantic tales of
lost love, epic tales of ancient heroes, or just to sit and 
praise their companion's virtues.  Many others who have visited
have left their own verses or tales pinned to the walls to share 
with others.   
THORN
);
    set_exits(
              (["north" : "/d/tsarven/garden/nbridge",
                "south" : "/d/tsarven/garden/sbridge",
                "east" : "/d/tsarven/garden/ebridge",
                "west" : "/d/tsarven/garden/wbridge"]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "darkwood iboard", "wall" }) );
    ob->set_board_id("empgarden");
    ob->set_max_posts(60);
    ob->set_location("/d/tsarven/garden/gazebo");
    ob->set("short", "A wall with a some scraps of paper pinned to it");
    ob->set("long", "This is the poetry corner of the Emperor's garden. Post your verses, noble adventurer.\n");
}
