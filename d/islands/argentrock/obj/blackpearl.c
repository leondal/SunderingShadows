#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("black pearl");
    set_id( ({"pearl","black pearl","component"}) );
    set("short","Black pearl");
     set("long","This is a black pearl, it is worth a fortune.");
    set_weight(2);
    set_value(3000);
}
