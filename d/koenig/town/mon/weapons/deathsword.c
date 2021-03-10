
#include <std.h>

inherit WEAPON;

void create()
{
  ::create();
    set_property("monsterweapon",1);
    set_name("deathsword");
    set_id( ({"deathsword","sword"}) );
    set_short("a Deathsword");
    set_long("This sword is scorched black by fire but remains sharp "
             "and deadly. The hand guard and hilt look alot like a "
             "bat.");
    set_weight(15);
    set_size(3);
    set_value(5000);
  set_type("slashing");
    set_wc(1,10);
    set_large_wc(3,6);
    set_property("enchantment",4);
    set_wield( (:this_object(), "eventSkill":) );
}

int eventSkill() {
   if((int)TP->query_level() < 20)
{
    message("info","You are not skilled enough to wield this exceptional "
            "weapon.", this_player());
    return 0;
}
    message("info","This exceptional weapon feels good in your hands.",
             this_player());
    return 1;
}
