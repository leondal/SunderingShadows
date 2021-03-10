#include <std.h>

inherit ROOM;

void create(){
    ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(STAIRWAY);
    set_short("dark room");
//    set_property("no teleport", 1);  removing safe haven from guild halls *Styx*  4/6/03
    set_property("indoors", 1);
    set_property("light", 1);
    set_long(
      "This dark room houses many shadows.  A ladder leads up into the shack, and one leads down, to where, you may only guess."
    );
    set_exits( ([
      "up" : "/d/laerad/parnelli/cguild/assassin/shack",
      "down" : "/d/laerad/parnelli/cguild/assassin/aguild1",
    ]) );
    set_smell("default", "You smell blood.");
    set_listen("default", "Is that breathing you hear?");
//    set_pre_exit_functions( ({"down"}), ({"GoThroughDoor"}) );
}

int GoThroughDoor(){
   if(TP->is_class("assassin") || TP->query("is_assassin")) return 1;
    tell_object(TP, "You may not pass at this time!");
    return 0;
}
