#include <std.h>
inherit OBJECT;
create() {
    ::create();
    set_id( ({ "storm key", "key" }) );
    set_name("storm key");
    set_short("storm key");
    set_long("A dark ancient key with an ornate handle");
    set_weight(2);
    set_value(10);
}
