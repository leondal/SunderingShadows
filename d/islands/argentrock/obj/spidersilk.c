#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("spider silk");
    set_id( ({"silk","spider silk","component"}) );
    set("short","Spider silk");
    set("long","This is a bit of spider silk, some sort of component.");
    set_weight(2);
    set_value(1);
}
