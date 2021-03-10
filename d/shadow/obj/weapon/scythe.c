#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("scythe");
    set_id( ({"scythe", "tool"}) );
    set_short("Scythe");
    set_long(
      "This is a scythe, made for cutting wheat in fields."
    );
    set_weight(7);
    set_value(10);
    set_wc(1,6);
    set_large_wc(1,8);
    set_size(2);
   
set_type("slashing");
    set_prof_type("scythe");
   set_weapon_speed(4);
}
