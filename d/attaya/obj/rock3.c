#include <std.h>
inherit OBJECT;
create() {
    ::create();
    set_id( ({ "large boulder", "boulder" }) );
    set_name("large boulder");
    set_short("large boulder");
    set_long("A chunk of granite and earth larger than you are");
    set_weight(800);
    set_value(10);
}
