#include <std.h>
inherit "/std/weapon";
create(){
    ::create();
set_id(({"hook","vicious hook"}));
set_name("hook");
set_short("Hook");
set_long("This is a vicious looking hook.  It has a mean curve and a sharp point."
"You see engravings around its steel base.  All and all this is definitely a nasty looking weapon.");
set_wc(1,5);
set_large_wc(1,5);
set_weight(6);
    set_size(1);
set("value", 200);
set_type("slashing");
set_prof_type("tool");
set_property("enchantment",2);
}
