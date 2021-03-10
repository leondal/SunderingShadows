#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Passageway in a Mine");
    set_long(
@KAYLA
You are standing in a large passage in the huge mine of Shadowgate.
A huge metal door is blocking the passage to the north, glowing
a dull blue color.  
KAYLA
    );
    set_exits(([
       "south" : "minen1"
    ] ));
    set_items(([
       "door" : "The door is firmly bolted shut.",
       "color" : "A sure sign that this door is magically sealed."
    ] ));
}

void init() {
  ::init();
  
  add_action("open_me","open");
}

void open_me(string str) {
  if(str == "door") {
    write("There is no possible way to open this door.");
    return 1;
  }
  return 0;
}