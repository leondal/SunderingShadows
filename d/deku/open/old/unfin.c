#include <std.h>

inherit "/d/deku/inherits/vexia-lair.c";

void create() {
    ::create();
    set_short("Unfinished Chamber");
    set_long(
@KAYLA
Upon entering this large chamber you can see that it obviously has
suffered a collapse in the past.  Large wooden beams brace crumbling
areas of the ceiling.  The beams are held together with ropes, wire
cords, and spikes.  Scattered about the room are mining tools and a
large crude wheelbarrow that is missing its wheel.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/open/cave_r4"
    ] ));
    set_items(([
      "wheelbarrow":"It's obviously useless without the wheel and probably "
        "abandoned when the ceiling gave way.",
      ({"ropes", "beams", "spikes"}): "The wires, cords and beams crisscross "
         "to brace the ceiling and crumbling walls.  Spikes anchor them and "
         "the precarious supports.",
      ({"tools", "mining tools"}): "These tools look old, worn, and useless.  "
         "They are covered in dust and have likely remained here undisturbed "
         "since the ceiling's collapse.",
    ] ));
}
