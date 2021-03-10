#include <std.h>
inherit OBJECT;
create() {
    ::create();
    set_id( ({ "large rock", "rock" }) );
    set_name("large rock");
    set_short("large rock");
    set_long("A chunk of granite and earth");
    set_weight(100);
    set_value(10);
}
