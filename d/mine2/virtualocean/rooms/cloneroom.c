#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_property("indoors",0);
    set_short("");
set_long("this is the cloneroom for ships");
}
