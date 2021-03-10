
inherit "/d/deku/open/skull";

void create() {
    ::create();
    set_exits(([
       "south" : "/d/deku/open/skull",
       "north" : "/d/deku/open/skull2"
    ] ));
}
