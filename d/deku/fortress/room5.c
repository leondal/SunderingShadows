#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Study Chamber");
    set_long(
@KAYLA
%^YELLOW%^Study Chamber%^RESET%^
This room was once lavishly furnished, but now the red carpeting
is rotted, the once rich tapestries are mildewed, and the shelf of
old spell components has spoiled.
KAYLA
    );
    set_listen("default","You hear disconcerting scuffling sounds in surrounding rooms.");
    set_exits(([
       "west" : "/d/deku/fortress/hallN4"
    ] ));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("knight")) {
    new("/d/deku/fortress/monster/knight")->move(TO);
  }
}
