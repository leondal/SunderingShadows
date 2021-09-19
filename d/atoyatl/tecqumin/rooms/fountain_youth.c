#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("In a thick jungle");
  set_short("%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle");
  set_long( (:TO, "long_desc":) );
  set_items(([  ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds.");
}
void init() {
   ::init();
}

string long_desc(){
return "%^GREEN%^A %^BOLD%^%^WHITE%^shining %^BOLD%^%^YELLOW%^g%^BOLD%^"
      +"%^WHITE%^o%^BOLD%^%^YELLOW%^ld f%^BOLD%^%^WHITE%^o%^BOLD%^"
      +"%^YELLOW%^unt%^BOLD%^%^WHITE%^ai%^BOLD%^%^YELLOW%^n%^RESET%^%^GREEN%^"
      +" rises from the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
      +"%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e %^RESET%^"
      +"%^GREEN%^on a %^RESET%^gray stone plinth%^GREEN%^ here. Creeping"
      +" vines and undergrowth have climbed over the %^RESET%^plinth%^GREEN%^"
      +", giving the %^BOLD%^%^YELLOW%^f%^BOLD%^%^WHITE%^o%^BOLD%^%^YELLOW%^"
      +"unt%^BOLD%^%^WHITE%^ai%^BOLD%^%^YELLOW%^n%^RESET%^ %^GREEN%^the"
      +" illusion of sitting on a bed of %^BOLD%^%^GREEN%^j%^RESET%^"
      +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e"
      +" %^RESET%^%^GREEN%^plants.\n";
}

