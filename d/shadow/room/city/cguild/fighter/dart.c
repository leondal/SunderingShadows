#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_id( ({"dart","darts","gamedart999"}) );
    set_name("dart");
    set_short("A sharp dart");
    set_long("This is a standard dart which you can throw at the "
        "dartboard in a pub. To hit the bull's-eye you need some practice.");
    set_weight(1);
    set("value",1);
}
