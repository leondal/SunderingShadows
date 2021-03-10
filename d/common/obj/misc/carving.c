#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("carving");
    set_id(({"carving","wooden carving"}));
    set_short("wooden carving");
    set_long("This is a small statue carved from wood.\n");
    set_weight(1);
    set_value(1);
    set_property("repairtype", ({ "woodwork" }));
}
int is_carving(){return 1;}
