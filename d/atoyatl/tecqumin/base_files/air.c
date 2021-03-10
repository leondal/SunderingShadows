#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 0);
  set_terrain(DEEP_WATER);
  set_travel(SLICK_FLOOR);
  set_name("In the air");
  set_short("In the %^BOLD%^%^WHITE%^a%^RESET%^i%^BOLD%^%^WHITE%^r");
  set_long( "%^BOLD%^%^CYAN%^You are faling through the %^WHITE%^a%^RESET%^i"
    +"%^BOLD%^%^WHITE%^r%^CYAN%^. The %^BOLD%^%^BLUE%^r%^WHITE%^i%^BLUE%^ver"
    +" w%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^t%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^"
    +"rs %^CYAN%^are rushing up to meet you. If you don't know how to dive,"
    +" this is going to %^RESET%^HURT%^BOLD%^%^CYAN%^!" );
  set_smell("default","The rush of %^BOLD%^%^WHITE%^cold"
    +" a%^RESET%^i%^BOLD%^%^WHITE%^r %^RESET%^%^ORANGE%^fills your nostrils");
  set_listen("default","The roar of the"
    +" %^BOLD%^%^WHITE%^a%^RESET%^i%^BOLD%^%^WHITE%^r%^RESET%^%^GREEN%^"
    +" rushing past stops you hearing anything");
}


