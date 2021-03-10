inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_long(this_object()->query_long()+"The path comes to a dead end here "
      "and is too thick for you to go further.");
    set_exits(([
       "west" : "/d/deku/plains/plains51"
    ] ));
}
