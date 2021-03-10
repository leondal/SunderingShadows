#include <std.h>
#include <daemons.h>
inherit OBJECT;

int original_light;

void create() {
    ::create();
    set_id( ({"street light","street_light","light"}) );
    set_name("street light");
    set_short("A sculptured street light");
    set_weight(1000000);
    set_long(
      "The tall streetlamp is made of cast bronze and depicts two snakes intertwined climbing a center pole before branching outwards in opposing directions.\nThe lanterns have not been hung from the street lights yet."
    );
    set_value(0);
}
