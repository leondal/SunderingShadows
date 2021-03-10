#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("white key");
    set_id( ({"key","white","white key"}) );
    set("short","White key");
     set("long","This a white key. It is made of unknown materials and is "
   "extremely light in weight.");
    set_weight(3);
    set_value(5);
}
