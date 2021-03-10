#include <std.h>
inherit "/std/weapon";
/* these variables aren't even used.  Last change was 10/98, *Styx*  8/19/2003
object old;
object owner;
int duration;
*/
create(){
    ::create();
set_id(({"rapier","sword","foil"}));
    set_name("rapier");
set_short("%^BOLD%^%^WHITE%^rapier%^RESET%^");
    set_long("This rapier is the standard pirate weapon. Durable, light, and easy to maintain.");
set_wc(1,7);
set_large_wc(1,9);
    set_weight(4);
set_size(1);
    set("value",15);
set_property("enchantment",1);
set_type("slashing");
    set_prof_type("rapier");
}
