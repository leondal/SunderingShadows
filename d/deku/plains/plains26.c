inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_listen("default","You hear what sounds like whimpering or crying to "
       "the west.");
    set_exits(([
       "south" : "/d/deku/plains/plains28",
       "east" : "/d/deku/plains/plains25",
       "west" : "/d/deku/plains/plains29"
    ] ));
}
