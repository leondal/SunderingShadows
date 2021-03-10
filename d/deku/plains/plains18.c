inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_long(this_object()->query_long()+"The path looks more heavily traveled "
       "to the east here.");
    set_listen("default","You hear what sounds like whimpering or crying to "
       "the west.");
    set_exits(([
       "east" : "/d/deku/plains/plains17",
       "north" : "/d/deku/plains/plains21",
       "west" : "/d/deku/plains/plains19"
    ] ));
}
