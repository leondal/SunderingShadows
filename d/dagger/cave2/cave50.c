#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(3);
    ::create();
    set_long(
      "In this far corner of the caves you have found a strange room.  It looks much the same as the rest, except for a huge crack running up and down the north wall.  From that crack a strange blue light flows, lighting the room."
    );
    set_exits( ([
      "northeast" : "/d/dagger/cave2/cave53",
      ]));
    add_item("crack", "The crack is large enough for you to walk into, but you wonder what that soft blue light shining from it is.");
    add_item("light", "The soft blue light coming from the crack fills the room, giving it an eerie glow.");
}

void init() {
    ::init();
    add_action("crack_fcn", "enter");
}

void reset(){
    ::reset();

}
