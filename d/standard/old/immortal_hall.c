#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
      set("short", "The Hall of Immortals");
      set("long",
        "Welcome to the hall of immortals!\n"
	  "High mortals come here to seek mentors who will guide them into "
	  "the world of immortality.  Mortals come here to prove "
	  "their worthiness for high mortalhood.  A spiral flight "
	  "of stairs leads up out of the cellar.");
      set_exits( 
		(["up" : "/d/standard/stairs"]) );
    set_property("no castle", 1);
}

void reset() {
  ::reset();
    if(!present("unity")) 
      new("/d/standard/obj/mon/unity")->move(this_object());
}

