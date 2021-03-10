//Coded by Bane//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"staff","staff of souls"}));
    set_name("Staff of souls");
    set_obvious_short("black quarter staff");
    set_short("A staff of souls");
    set_lore("It is said that the staff of souls draws the very life force from the target into the wielder.");
    set_long(
    "This is a long black quarterstaff. An eerie light emits from the "+
    "the staff. There are some runes that run along the shaft of the "+
    "weapon."
    );
    set_size(3);
    set_weight(20);
    set_value(2500);
    set_wc(1,6);
    set_large_wc(1,6);
    set_type("bludgeoning");
    set_prof_type("staff");
    set_property("enchantment",1);
    set_hit( (:TO,"extra_hit":) );
}
int extra_hit(object ob){
    int roll, dam;
    roll=random(100)+1;
    dam=random(6)+1;
    if(roll > 90){
    tell_object(ob,"%^BOLD%^MAGENTA%^The staff draws in your life energy!");
        tell_room(environment(query_wielded()),"%^BOLD%^MAGENTA%^The staff glows as it strikes "+ob->query_cap_name()+"!",ob);
    ob->do_damage(ob->return_target_limb(),(dam));
       ETO->add_hp(dam);
    return 1;
    }
}
