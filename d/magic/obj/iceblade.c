// magic sword for spells

#include <std.h>

inherit WEAPON;

string owner;

void create(){
    ::create();
    set_id(({"sword","magic sword","blade","ice blade"}));
    set_type("magicslashing");
    set_weight(0);
    set_value(0);
    set_name("ice blade");
    set_short("%^CYAN%^An ice blade%^RESET%^");
    set_long("This sword is not really a sword but is actually a swilring mass of ice particles held in tight formation as a sword by magic.");
    set_property("enchantment",1);
    set_wc(3,4);
    set_large_wc(3,4);
    set_wield((:TO, "extra_wield":));
    set_unwield((:TO,"extra_unwield":));
    set_hit((:TO,"extra_hit":));
}

int extra_hit(object ob){
    if(!objectp(ob)) return 1+random(6);
    tell_object(ETO,"The %^CYAN%^ice blade%^RESET%^ chills "+ob->query_cap_name()+"'s flesh.");
    tell_object(ob,"The %^CYAN%^ice blade%^RESET%^ held by "+ETO->query_cap_name()+" chills you to the bone.");
    tell_room(environment(ob),"The %^CYAN%^ice blade%^RESET%^ held by "+ETO->query_cap_name()+" chills "+ob->query_cap_name()+"'s body.",({ob,ETO}));
    return 1+random(6);
}

int query_size(){
   if(living(ETO))
{
      return ETO->query_size();
    }
   else return 3;
}

void init(){
    int clevel, enc;
    
   ::init();
   if(stringp(owner)) return;
   if(interactive(TP) && TP == ETO){
       owner = TPQN;
   }
   clevel = TP->query_guild_level("cleric");
   enc = clevel / 5;
   if(enc > 5) enc = 5;
   set_property("enchantment",enc);
   while((int)(query_property("enchantment")) < 0){
      remove_property("enchantment");
      set_property("enchantment",enc);
   }
}


int extra_wield(){
    if(interactive(TP) && owner != (string)TPQN){ 
        tell_object(TP,"You are not allowed to wield this sword.");
        return 0;
    }
    if(objectp(ETO)) ETO->add_attack_bonus(1);
    return 1;
}

int extra_unwield(){
    if(objectp(ETO)) ETO->add_attack_bonus(-1);
    return 1;
}

int drop(){
    tell_object(TP,"Your hand will not release the divine blade!");
    return 1;
}

int save_me(string file){ return 1;}
