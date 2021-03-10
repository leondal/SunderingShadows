#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"fountain"}));
    set_name("fountain");
    set_short("A marble fountain");
    set_weight(10000000);
    set_long("This beautiful fountain is made of the purest white marble.  Water is running from spouts on a platform under a great white stallion reared up on its hind legs, seemingly attacking a foe.  The spray from the fountain refreshes you as you walk near.");
    set_value(0);
}
