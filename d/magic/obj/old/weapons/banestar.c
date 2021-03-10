// Magic morningstar for Bane spell Circe 4/14/04

#include <std.h>

inherit WEAPON;

string owner;

void create(){
    ::create();
    set_id(({"morningstar","magic morningstar","tyrants morningstar","star"}));
    set_name("tyrants morningstar");
    set_short("%^BOLD%^%^BLACK%^Tyrant's Morningstar%^RESET%^");
    set_long("This morningstar is a black, spiked one-piece rod fitted with a round, spiked head.  It is surrounded by a dim, flickering, green aura.");
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
    int clevel;
    
   ::init();
   if(stringp(owner)) return;
   if(interactive(TP) && TP == ETO){
       owner = TPQN;
   }
   clevel = TP->query_guild_level("cleric");
   set_property("enchantment",clevel/10);
   while((int)(query_property("enchantment")) < 0){
      remove_property("enchantment");
      set_property("enchantment",clevel/10);
   }
}


int extra_wield(){
    if(interactive(TP) && owner != (string)TPQN){ 
        tell_object(TP,"You are not allowed to wield this mace.");
        return 0;
    }
    if(objectp(ETO)) ETO->add_attack_bonus(3);
    return 1;
}

int extra_unwield(){
    if(objectp(ETO)) ETO->add_attack_bonus(-3);
    return 1;
}
int drop(){
    tell_object(TP,"Your hand will not release the divine morningstar!");
    return 1;
}

int save_me(string file){ return 1;}
