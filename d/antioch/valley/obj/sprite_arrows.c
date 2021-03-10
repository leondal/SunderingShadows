#include <std.h>
#include "../valley.h"
inherit "/std/ammo";

void create()
{
      ::create();
	set_name("sprite arrows");
        set_id(({"sprite arrows","arrows","sea sprite arrows","tiny arrows", "quiver"}));
        set_short("%^BOLD%^%^CYAN%^quiver of sea sprite arrows%^RESET%^");
	set_long(
        "%^BOLD%^%^CYAN%^These are arrows made from a %^RESET%^pale white wood%^BOLD%^%^CYAN%^. The tips are"+
        " of some sort of %^BOLD%^%^BLACK%^black stone%^BOLD%^%^CYAN%^. They are reported to fire"+
        " straight and true despite their deceptively %^RESET%^%^CYAN%^light %^BOLD%^%^CYAN%^weight.%^RESET%^"
	);
        set_shots(-1);
        set_wc(2,4);
       set_large_wc(2,4);
   set_ammo_type("sprite arrows");
}
