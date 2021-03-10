inherit "std/room";

void create() {
  ::create();
    set("short", "Adventurer's Supply Storage Room");
    set("long", "Horace stores weapons and such here.\n");
    set_exits( (["south" : "/d/standard/supply"]) );
}

