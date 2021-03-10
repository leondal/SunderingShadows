#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("grey key");
    set_id( ({"key","grey","grey key"}) );
    set("short","Grey key");
     set("long","This a grey key. It is made of unknown materials and is "
   "extremely light in weight.");
    set_weight(3);
    set_value(5);
}
