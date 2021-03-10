#include <std.h>
inherit OBJECT;
create() {
    ::create();
    set_id( ({ "small boulder", "boulder" }) );
    set_name("small boulder");
    set_short("small boulder");
    set_long("A large chunk of granite and earth");
    set_weight(400);
    set_value(10);
}
