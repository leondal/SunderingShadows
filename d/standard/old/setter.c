#include <std.h>
#include <daemons.h>
#include <rooms.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("The Setter");
    set_long(
@KAYLA
Your soul floats casually around in the huge void that surrounds you.
There are other spirits in the void with you, some are lost souls,
waiting for reincarnation.  Suddenly the room is filled with a loud
noise, like an angelic intercom.  It informs you to <press button>
to press the button on the wall to start your journey into the world of
ShadowGate.
KAYLA
);
    set_items(
	(["room" : "The nothingness from which you will be born "
	    "into "+mud_name()+".",
	  "list" : "A list of races and classes that exist in the world of "+mud_name()+"."]) ); }

void init() {
    ::init();
    add_action("begin","press");
    add_action("begin","push");
}

int begin(string str) {
  object ob;
  
  write("You press the button, and are suddenly transported to a small room.");
  ob = new("/d/standard/begin");
  this_player()->set_stats("strength",0);
  this_player()->set_stats("dexterity",0);
  this_player()->set_stats("intelligence",0);
  this_player()->set_stats("charisma",0);
  this_player()->set_stats("wisdom",0);
  this_player()->set_stats("constitution",0);
  this_player()->move(ob);
  return 1;
}

