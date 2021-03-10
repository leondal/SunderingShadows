#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 0);
  set_terrain(DEEP_WATER);
  set_travel(SLICK_FLOOR);
  set_name("Falling from a tower");
  set_short("%^BOLD%^%^WHITE%^Falling%^RESET%^ from a %^ORANGE%^tower");
  set_long( "%^BOLD%^%^CYAN%^You are faling through the %^WHITE%^a%^RESET%^i"
    +"%^BOLD%^%^WHITE%^r%^CYAN%^. The %^RESET%^%^ORANGE%^ground"
    +" %^BOLD%^%^CYAN%^ is rushing up to meet you. This is going to"
    +" %^RESET%^HURT%^BOLD%^%^CYAN%^!" );
  set_smell("default","The rush of %^BOLD%^%^WHITE%^cold"
    +" a%^RESET%^i%^BOLD%^%^WHITE%^r %^RESET%^%^ORANGE%^fills your nostrils");
  set_listen("default","The roar of the"
    +" %^BOLD%^%^WHITE%^a%^RESET%^i%^BOLD%^%^WHITE%^r%^RESET%^%^GREEN%^"
    +" rushing past stops you hearing anything");
}


