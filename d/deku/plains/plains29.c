inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_listen("default","You hear what sounds like whimpering or crying to "
       "the west.");
    set_exits(([
       "east" : "/d/deku/plains/plains26",
       "west" : "/d/deku/plains/plains30"
    ] ));
}
