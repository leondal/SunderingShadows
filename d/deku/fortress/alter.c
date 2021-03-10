#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Altar Chamber");
    set_long(
@KAYLA
%^YELLOW%^Alter Chamber%^RESET%^
Against the west wall is an altar-like arrangement made of alabaster.
A thick black cloth is partially draped over this altar.  Atop the
cloth are two unlit black candles in gold candlesticks and a smoking
censer filled with a bitter incense.  Hanging on the wall behind the
altar is a tapestry bearing the image of a black dragon on a maroon
background.
KAYLA
    );
     set_smell("default","You smell a bitter incense coming from the censer.");
    set_exits(([
       "east":"/d/deku/fortress/study"
    ] ));
    set_items(([
       "altar" : "This altar must be used for sacrificing.",
       "tapestry" : "This tapestry is long and looks very heavy."
    ] ));
}

void reset() {
  ::reset();
  if(!present("cleric")) {
    new("/d/deku/monster/priest")->move(TO);
    new("/d/deku/monster/priest")->move(TO);
  }
}
