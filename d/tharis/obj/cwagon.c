#include <std.h>
inherit OBJECT;
void create() {
        ::create();
    set_id( ({"wagon"}) );
    set_name("wagon");
    set("short", "A large wagon stuck in the mud");
set("long",
@OLI
This is a large wagon stuck in the mud.
It appears to be carrying items of no worth to you.
The guards are trying push the wagon while the driver is yelling at them.
The driver sees you and yells, "Hey, you there, come over here and help!"
OLI
);
     set_weight(10000);
    set_value(2);
    }
