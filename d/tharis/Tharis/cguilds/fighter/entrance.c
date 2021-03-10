#include <std.h>

inherit ROOM;

void create(){
    ::create();
   set_property("light",0);
    set_short("dark room");
    set_long(
      "This dark room houses many shadows.  A ladder leads up into the shack, and one leads down, to where, you may only guess."
    );
    set_exits( ([
      "out" : "/d/tharis/Tharis/warehouse1",
      "north" : "/d/tharis/Tharis/cguilds/fighter/fhall",
    ]) );
    set_smell("default", "You smell blood.");
    set_listen("default", "Is that breathing you hear?");
// removing access restrictions *Styx*  4/20/03
//    set_pre_exit_functions( ({"north"}), ({"GoThroughDoor"}) );
}

int GoThroughDoor(){
    if(TP->is_class("fighter")) return 1;
    tell_object(TP, "You may not pass at this time!");
    return 0;
}
