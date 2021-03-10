inherit "std/room";

void create() {
    ::create();
    set("short", "The cache");
    set("long", "Things are hidden here.");
    set_property("storage room", 1);
    set_property("no teleport", 1);
}
