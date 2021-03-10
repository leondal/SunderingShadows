#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(BARREN);
    set_travel(PAVED_ROAD);
    set_short("%^BOLD%^%^BLACK%^Bridge of Darkness");
    set_long(
@KAYLA
%^BOLD%^%^BLACK%^This ornately carved and sculptured bridge arches about 50 ft. over the river.  It has many strange forms and shapes in bold relief such as gargoyle-like monsters leering from it.  A distant rumbling and thundering can also be heard from the vast river down below.  As you walk across the bridge, light turns into darkness.  You leave any goodness that exists on this island behind and there is a distinct feeling that you are walking into death's hands.
KAYLA
    );
    set_smell("default","The mist carries the smell of death and decay.");
    set_listen("default","You hear the crashing water from down below.");
    set_exits(([
      "west":"/d/deku/open/hermit",
      "east":"/d/deku/open/pass1"
    ] ));
    set_items(([
      "river" : "You might wonder if there's anything worthwhile in the river or what would happen if someone would fall or jump.",
    ] ));
}

void init() {
  ::init();
  add_action("fall","fall");
  add_action("fall","jump");
}

int fall() {
  write("You step to the edge of the bridge and jump off.\n");
  say(TPQCN+" steps to the edge of the bridge and jumps into the river.");
  write("Why would you do such a stupid thing?  You are falling to your death!");
  
  call_out("reply_back",2);
  call_out("reply_back2",5);
  call_out("reply_back3",8);
  write("\n\n");
  return 1;
}

void reply_back(string str) {
  write("You start falling, at a very rapid pace.\n\n");
}

void reply_back2(string str) {
  write("You think you'll never hit water.\n\n\n");
}

void reply_back3(string str) {
  write("%^RED%^SPLASH%^RESET%^, you slam into the water hard!");
  TP->move_player("/d/deku/open/river");
}
