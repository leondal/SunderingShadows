#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("An Elevator System");
    set_long(
@KAYLA
You are standing in a small alcove housing a person sized hole in the
ground.  A system of pullies and ropes are here, guiding small
metal platforms up and down the hole.  Apparently, this is how
the miners get from one level of the mine to another.  The
platform on the railway is to the south.
KAYLA
    );
    set_exits(([
       "south" : "track3"
    ] ));
    set_items(([
       "hole" : "The hole leads down to the next level of the mine.  Maybe you should <ride> the elevator.",
       "pullies" : "The pullies are set up with the ropes to raise and lower the elevator.  Maybe you should <ride> the elevator down to the next level.",
       "ropes" : "The ropes are set up with the pullies to raise and lower the elevator.  Maybe you should <ride> the elevator down to the next level.",
       "platforms" : "These metal platforms raise and lower to give access to the lower part of the mine.  Maybe you should <ride> the elevator down to the next level."
    ] ));
}

void init() {
  ::init();
  
  add_action("ride_it","ride");
}

void ride_it(string str) {
  tell_room(environment(this_player()),this_player()->query_cap_name()+
            " hops on the elevator and rides down.",this_player());
  write("You jump onto the platform and ride the elevator down.");          
  this_player()->move(find_object_or_load("/d/mine/lvl2room/enter"));
  
  tell_room(environment(this_player()),this_player()->query_cap_name()+
            " hops off the elevator.",this_player());  
  return 1;
}