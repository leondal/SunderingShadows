#include <std.h>
#include <move.h>
#include <money.h>

inherit HEALER;

void create() {
    ::create();
  set_light(2);
  set_indoors(1);
  set_short("%^RED%^%^BOLD%^V%^RESET%^%^RED%^erbobone %^BOLD%^H%^RESET%^%^RED%^ealer");
  set_long("%^RED%^%^BOLD%^V%^RESET%^%^RED%^erbobone %^BOLD%^H%^RESET%^%^RED%^ealer
%^ORANGE%^You have entered a dimly lit, decrepit, old building. The room is in shambles. It looks like it has recently been ransacked. An old, haggard looking man sits behind a counter in the back of the room.
%^RESET%^");
  set_smell("default", "The room has a distinct musty odor to it.");
  set_listen("default", "The room is almost totally quiet, except for the labored breathing of the old man.");
  set_exits(([
     "east" : "/d/deku/town/road10"
  ] ));
  set_name("Korindell");
  if(!present("korindell")) 
  { 
    find_object_or_load("/d/deku/monster/korindell")->move(TO);
  }
}

void reset() {
  ::reset();
  if(!present("korindell")) {
    find_object_or_load("/d/deku/monster/korindell")->move(TO);
  }
}

