#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_short("Under the Piano");
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    set_property("light", 1);
    set_property("indoors", 1);
    set_long(
      "You have entered a small room under the piano that houses the workings that allows the bards to get into their hall.  There is a ladder leading back up to the smashed piano, and another one leading down into the Bard's hall.  As you look around, you sense an eerie presence near you."
    );
    set_items( ([
      "ladder" : "It goes up and down.",
    ]) );
    set_exits( ([
      "up" : "/d/dagger/tonovi/town/hotelpiano.c",
      "down" : "/d/dagger/tonovi/town/cguilds/bard1.c",
    ]) );
    set_listen("default", "Is that breathing you hear?");
    set_pre_exit_functions( ({"down"}), ({"GoThroughDoor"}) );
}

int GoThroughDoor(){
    if(TP->is_class("bard")) return 1;
    tell_object(TP, "Right now you can't go down there.  You will be able to soon, but the G man has to finish up some stuff first.");
    return 0;
}
