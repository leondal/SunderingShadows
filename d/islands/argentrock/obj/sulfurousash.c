#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("sulfurous ash");
    set_id( ({"ash","sulfurous ash","component"}) );
    set("short","Sulfurous ash");
     set("long","This is some sulfurous ash, some sort of component.");
    set_weight(2);
    set_value(1);
}
