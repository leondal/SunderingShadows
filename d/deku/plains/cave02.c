#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Abandoned Cave");
    set_terrain(NAT_CAVE);
    set_travel(FOOT_PATH);
    set_long(
@KAYLA
%^YELLOW%^Abandoned Cave%^RESET%^
This is a natural cave.  Lying upon the dirt floor are many bones
of humanoid creatures.  Cobwebs hang from the ceiling and walls.
Small creatures scurry away from the light.
KAYLA
    );
     set_smell("default","There is an overwhelming stench of humanoid flesh.");
    set_exits(([
       "south" : "/d/deku/plains/cave01"
    ] ));
    set_items(([
       "bones" : "A wide variety of humanoid bones, some with decaying flesh "
          "still on them.  Most look to have been gnawed clean, however."
    ] ));
}

void reset() {
  ::reset();
  if(!present("troll")) {
    new("d/deku/monster/troll")->move(this_object());
    new("/d/deku/monster/troll")->move(this_object());
  }
}
