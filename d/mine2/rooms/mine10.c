#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;

object ob;
void create() {
          ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("A mine shaft");
    set_long(""
"%^BOLD%^ORANGE%^ "
"This mine shaft is so slanted that it is hard for you to not fall over.  "
"There is a small hole in one side on the cavern, that looks like it may be "
"some type of passage way.  This room has not been mined at to much because there "
"are not a lot of rock chips on the ground.  There are several spots where water "
"is dripping from the top of the room.");

     set_listen("default","You hear driping water.");
     set_smell("default","You smell somthing decaying.");
    set_exits(([
       "east" : "/d/mine2/rooms/mine11",
       "west" : "/d/mine2/rooms/mine9",
    ] ));
    set_items(([
         "cavern" : "This cavern is sloped, and makes it hard to stand up in.",
         "water" : "The water is dripping from little another mine shaft up above.",
         "marks" : "There are not to many marks in this room.",
         "shaft" : "It is very sloped.",
         "hole" : "It is a passage that has been made from someone picking at that one spot for a long time.",
         "drips" : "They are drips of water.",
         "passage" : "It is a small hole that you could probably enter.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
void init()
{
  ::init();
  add_action("enter","enter");
}
int enter(string str)
{
  if(str != "passage") {
 write("You stand on a small rock and climb up into the passage way.");
 this_player()->move("/d/mine2/rooms/secret1");
 say(this_player()->query_cap_name()+" climbs into a hole");
}
}

