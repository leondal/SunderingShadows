#include <std.h>
#include "../marsh.h"

inherit MINH;

void create()
{
    ::create();

    set_long(""+ ::query_long() + "\n%^BLUE%^A boggy lake lies to the east blocking "
        "any passage further in that direction. The lake is large and could be explored "
        "only by boat.%^RESET%^");

    add_item("lake","The lake is quite slimy and filled with reeds and weeds.");


    set_exits(([
                   "north" : RPATH "m_n001_n012",
                   "west" : RPATH "m_n002_n013",

                   ]));
}

void reset()
{
    ::reset();
    if (!present("sorrow_cleric")) {
        new(MON "harv.c")->move(TO);
    }
}
