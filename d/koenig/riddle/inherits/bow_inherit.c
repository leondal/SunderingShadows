//bow_inherit.c - for Riddle Quest.  Circe 1/19/04
#include <std.h>
inherit LRWEAPON;

int OWNED;
string owner;

void create() {
    ::create();
    set_weight(2);
    set_size(3);
    set_value(0);
    set_prof_type("staff");
    set_lr_prof_type("long bow");
    set_name("longbow");
    set_two_handed();
    set_wc(1,8);
    set_large_wc(1,8);
    set_type("bludgeoning");
    set_rate_of_fire(2);
    set_range(7,15,21);
    set_ammo("longbow arrow");
    set_decay_rate(100);
    set_lr_type("piercing");
    set_property("enchantment",2);
      if(TO->query_property("enchantment")< 2){
         remove_property("enchantment");
         set_property("enchantment",2);
      }
    set_wield((:TO,"extra_wield":));
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
}

int extra_wield()
{
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The bow refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" screams"+
                " in pain as "+ETO->QS+" tries wield the bow.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^The bow forms perfectly to your hand, bringing to mind "+
           "the blessings of your deity.");
        return 1;
}