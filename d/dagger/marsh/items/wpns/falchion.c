
#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
set_id(({"sword","falchion","falchion sword"}));
set_name("falchion sword");
set_short("A falchion sword");
   set_long(
"This is a Falchion sword, it is heavier and larger than a"
" broadsword and does better damage to chainmail. "
   );
set_weight(14);
   set_size(2);
set("value", 25);
set_wc(2,7);
set_large_wc(2,8);
set_type("slashing");
}
