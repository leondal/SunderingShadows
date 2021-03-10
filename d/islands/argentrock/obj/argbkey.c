#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("brown key");
    set_id( ({"key","brown","brown key"}) );
    set("short","Brown key");
     set("long","This a brown key. It is made of unknown materials and is "
         "extremely light in weight.");
    set_weight(3);
    set_value(5);
}
