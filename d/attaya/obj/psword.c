#include <std.h>
inherit "/std/weapon";
create() {
    ::create();
    set_name("cursed sword");
    set_id(({"cursed sword","cursed","titanium sword","sword"}));
    set_short("Holy Blade");
    set_long(
    "This is a strange sword."
     );
    set_weight(15);
    set_size(2);
    set_value(500);
    set_wc(1,8);
    set_large_wc(1,14);
    set_type("slashing");
    set_property("enchantment",4);
    set_hit((:TO,"extra_hit":));
    set_property("monsterweapon", 1);
}

int extra_hit(object targ){
    if(interactive(targ)) return 0;
    if(!objectp(TO)) { return 0; }
    if(!objectp(ETO)) { return 0; }
    tell_room(ETO, "%^BOLD%^The sword blazes with a great blue flame as it strikes "+targ->query_cap_name()+"!!!");
    targ->add_hp(-1 * (int)targ->query_max_hp()/5);
    return 1;
}
