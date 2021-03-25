//k_road09.c - Road through Koenig - coded by Circe 11/15/03
#include <std.h>
#include "../koenig.h"
inherit VILROADS;

void create() {
   ::create();
   set_long(
      "%^ORANGE%^This %^BOLD%^%^BLACK%^na%^RESET%^rr%^BOLD%^o%^BLACK%^w b%^RESET%^r%^BOLD%^o%^RESET%^ke%^BOLD%^%^BLACK%^n r%^WHITE%^oa%^RESET%^dw%^BOLD%^%^BLACK%^ay %^RESET%^%^ORANGE%^leads through a %^CYAN%^ransacked village %^ORANGE%^that has clearly been %^CYAN%^abandoned%^ORANGE%^. North and south small %^BOLD%^%^RED%^buildings %^RESET%^%^ORANGE%^rise up in the village, but the stretch of road here is now %^CYAN%^empty%^ORANGE%^. East and west are patches of %^BOLD%^%^BLACK%^charred %^RESET%^%^ORANGE%^ground and %^BOLD%^%^BLACK%^r%^RESET%^ui%^BOLD%^%^BLACK%^ns %^RESET%^%^ORANGE%^where there were once several houses.  Now, nothing remains but %^BOLD%^%^BLACK%^burned %^RESET%^%^ORANGE%^timbers and fitful patches of %^CYAN%^c%^BOLD%^%^GREEN%^oa%^RESET%^%^CYAN%^r%^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^e g%^BOLD%^%^GREEN%^r%^RESET%^%^CYAN%^a%^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^s %^ORANGE%^trying to grow up throw the %^CYAN%^desolation%^ORANGE%^.%^RESET%^"
      "\n");
   add_item("ruins","To the east and west stand the ruins of several village "+
      "buildings, most likely houses.  Now, timbers stand upright, most burned in "+
      "half, and grass is finally beginning to grow there.");
   add_item("grass","The verdant grass is growing in fitful patches among the "+
      "ruins of the village.  It is coarse and quite short, but it is steadily "+
      "trying to take over the ruins.");
   set_exits(([
      "north" : VILROOMS"k_road08",
      "west" : VILROOMS"ruins1",
      "east" : VILROOMS"ruins2",
	"south" : VILROOMS"k_road10"
   ]));
}