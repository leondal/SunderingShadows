#include <std.h>

inherit "/d/common/inherit/gs_storage";

void create()
{
    ::create();
    set_property("no teleport", 1);
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "A storage room for the general store.");
    set("long", "Supplies and such are stored here.\n");
}

void reset()
{
    ::reset();
    if (!present("waterskin")) {
        new("/d/antioch/antioch2/obj/waterskin")->move(TO);
    }
}
