#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("scythe");
    set_id( ({"scythe", "tool"}) );
    set_short("A mithril scythe");
    set_long("This is a scythe, generally made for cutting wheat in fields although this one is forged from mithril and looks like it was meant to be used as a weapon.");
	 set_property("enchantment", 1);
    set_weight(7);
    set_value(310);
    set_wc(1,6);
    set_large_wc(1,8);
    set_size(2);
    set_type("slash");
    set_prof_type("scythe");
    set_weapon_speed(4);
    set_weapon_prof("exotic");
}
