inherit "std/room";

void create() {
	::create();
    set_property("light", 1);
    set("short", "Outland Supply storage");
    set("long", "Outland Supply storage");
    set_exits( (["south" : "/d/standard/outlands/shop"]) );
}

