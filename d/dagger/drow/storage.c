inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
    set_properties((["light":1, "indoors":1]));
    set_property("no teleport", 1);
    set("short", "Drow Store Storage Room");
    set("long", "Supplies and such are stored here and mortals should NOT be here.\n");
    set_exits( (["south" : "/d/dagger/drow/rooms/store"]) );
}

void reset() {
    ::reset();
}
