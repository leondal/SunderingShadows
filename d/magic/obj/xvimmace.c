// magic mace for spells

#include <std.h>

inherit WEAPON;

string owner;

void create(){
    ::create();
    set_id(({"mace","magic mace","mace of xvim"}));
    set_name("mace of xvim");
    set_short("Mace of Xvim");
    set_long("This mace is a black, spiked, knob-headed, one-piece rod surrounded by a dim, flickering, blue radiance.");
    set_wc(1,14);
    set_large_wc(1,14);
    set_type("bludgeoning");
    set_prof_type("magic weapons");
    set_weight(0);
    set_value(0);
    set_wield((:TO, "extra_wield":));
    set_unwield((:TO,"extra_unwield":));
}

int query_size(){
   if(living(ETO))
      return ETO->query_size();
   else return 3;
}

void init(){
   ::init();
   if(stringp(owner)) return;
   if(interactive(TP) && TP == ETO){
       owner = TPQN;
   }
}

int extra_wield(){
    if(interactive(TP) && owner != (string)TPQN){ 
        tell_object(TP,"You are not allowed to wield this mace.");
        return 0;
    }
    else {
        if(objectp(ETO)) ETO->add_attack_bonus(3);
        return 1;
    }
}

int extra_unwield(){
    if(objectp(ETO)) ETO->add_attack_bonus(-3);
    return 1;
}
int drop(){
    tell_object(TP,"Your hand will not release the divine mace!");
    return 1;
}

int save_me(string file){ return 1;}
