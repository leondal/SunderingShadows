
inherit "/d/deku/open/skull";

void create() {
    ::create();
    set_exits(([
       "south" : "/d/deku/open/skull2",
       "north" : "/d/deku/open/skull4"
    ] ));
}

void reset() {
  ::reset();
  if(!present("babu")) {
    new("/d/deku/monster/babu")->move(this_object());
  }
}
