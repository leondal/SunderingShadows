#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_id( ({"medallion","cave medallion"}) );
    set_name("medallion");
    set("short", "A medallion");
    set_weight(0);
    set("long", "A medallion. 	");
    set_value(0);
}

