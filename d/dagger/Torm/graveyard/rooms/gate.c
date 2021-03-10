#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
set_property("light",1);
set_property("outdoors",1);
set_short("Graveyard Gate");
    set_long(
"You see before you a massive, rusty gate, separating you from the horrors "+
"of the graveyard on the other side. On the gate, you see the poor "+
"remains of a creature, impaled upon the spikes of the gate. There is a "+
"worn sign which lies beside the gate, fallen off from age. "+
"This is definetly no place to rest...");
set_exits(([
"north":"/d/dagger/Torm/road/path5.c",
  ]));
set_items((["sign":"The worn sign reads : \n%^BOLD%^%^RED%^Beyond this gate "+
"lies horrors \nthat no mortal should wish to experience. \nYou have been "+
"warned...","gate":"This old, rusty gate looks like it never opens. Years "+
"of wear and abuse has made this gate nearly inoperable. The only way to "+
"enter the graveyard is to open the gate." ]));
set_smell("default","You smell the decaying corpse of a poor animal.");
set_listen("default","Beyond the gate, you hear terrible screaming...");
}

void init() {
  :: init();
add_action("open","open"); }

int open(string str){
if (str == "gate") {
  tell_object(this_player(),"The gate slowly creaks open, allowing you to enter the graveyard.");
  say ("The gate opens, allowing you to enter the graveyard");
  add_exit("/d/dagger/Torm/graveyard/rooms/grave4.c","south");
}
return 1;
}
