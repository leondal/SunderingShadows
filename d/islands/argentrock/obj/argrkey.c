#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("red key");
    set_id( ({"key","red","red key"}) );
    set("short","Red key");
     set("long","This a red key. It is made of unknown materials and is "
   "extremely light in weight.");
    set_weight(3);
    set_value(5);
}
