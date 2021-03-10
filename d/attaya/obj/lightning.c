#include <std.h>

inherit "/std/ammo";

create() {
    ::create();
    set_id(({ "cylinder","object","red lightning" }));
    set_name("red lightning");
    set_short("A small cylindrical object");
    set_long(
      "It is a small, black, cylindrical object with a red lightning bolt printed on the top and bottom."
    );
    set_shots(100);
    set_wc(20,10);
    set_large_wc(10,20);
}
