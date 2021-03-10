#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l2a";

void create() {
    ::create();
    set_long("%^ORANGE%^You stand at the base of a spiralling stone staircase, leading upwards out of "
"sight.  It is surrounded by steep walls, that rise to meet the ornate borders edging the roof above, "
"and are covered in dust and the occasional spiderweb. At your feet, %^RED%^dark carpet%^ORANGE%^ "
"cushions your steps upon the tiled floor, leading in from the hallway to the south, and travelling up "
"the centre of the stairs.  Soft breaths of wind swirl up and down the staircase, "
"carrying faint %^CYAN%^whispers%^ORANGE%^ as they brush past you.%^RESET%^\n");
    add_item("stairs","%^ORANGE%^A stone staircase spirals up out of sight, lined with a strip of "
"%^RED%^carpet%^ORANGE%^ down the middle.%^RESET%^");
    add_item("staircase","%^ORANGE%^A stone staircase spirals up out of sight, lined with a strip of "
"%^RED%^carpet%^ORANGE%^ down the middle.%^RESET%^");
    set_exits(([
      "up" : ROOMS+"t1",
      "south" : ROOMS+"u6-3"
    ]));
}

void reset() {
    ::reset();
    if(!present("spirit")) { new(MON+"advspirit")->move(TO); }
}
