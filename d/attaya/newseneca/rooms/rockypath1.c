//rockypath1.c - ~Circe~ 6/8/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit RPATH;

void create(){
   ::create();
   set_long(::query_long()+"Just north of here lies the broad "+
      "%^ORANGE%^co%^RED%^b%^ORANGE%^ble%^RESET%^s%^ORANGE%^to"+
      "%^RED%^n%^ORANGE%^e %^RESET%^street bordering the southern "+
      "end of %^BOLD%^Seneca%^RESET%^.  Directly west of the path "+
      "is a tall tower set at the end of the %^BOLD%^co%^MAGENTA%^q%^WHITE%^ui"+
      "%^BLACK%^n%^WHITE%^a walls%^RESET%^ while the path itself "+
      "continues to the east, leading downward to a %^BOLD%^"+
      "stucco building%^RESET%^, and to the west, where it winds "+
      "its way to the %^YELLOW%^b%^WHITE%^e%^RESET%^a%^YELLOW%^c"+
      "%^WHITE%^h%^RESET%^ below.\n");
   set_exits(([
      "north" : ROOMS"sstreet27",
      "east" : ROOMS"rockypath2",
      "southwest" : ROOMS"rockypath4"
   ]));
   add_item(({"cobblestone street","street","cobblestones"}),
      "The %^ORANGE%^co%^RED%^b%^ORANGE%^"+
      "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e street%^RESET%^ "+
      "is created from stones in shades of "+
      "%^ORANGE%^brown%^RESET%^, %^RED%^red%^RESET%^, and "+
      "white, which are arranged to form a pattern of "+
      "zig-zagging lines.  The boulevard is well-crafted and was "+
      "carefully planned, allowing plenty of space for two wagons "+
      "side-by-side for the entire length of the street.");
   add_item(({"building","stucco building"}),"%^BOLD%^%^WHITE%^"+
      "You are looking downward upon a white stucco building "+
      "with a brilliant %^RED%^red tile roof%^WHITE%^.  The path "+
      "eastward leads directly to it.%^RESET%^");
}