#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Town of Sanctuary");
    set_long("%^CYAN%^%^BOLD%^
This street becomes a dead end just north of Sanctuary Pub
This entire place, street and all, looks as though something
terrible has ravaged the very existence of the city.
    ");
    set_exits(([
      "temple":"/d/magic/temples/talos",
       "south" : "/d/dragon/town/roadN1"
    ] ));
    set_items(([
    ] ));
}
