// magic sword for spells

#include <std.h>

inherit WEAPON;

string owner;

void create(){
    ::create();
    set_id(({"sword","magic sword","blade","sunblade"}));
    set_type("magicslashing");
    set_weight(0);
    set_value(0);
    set_name("sunblade");
    set_short("%^ORANGE%^A sunblade%^RESET%^");
      set_long("This sword is not really a sword but is actually a swirling mass of %^ORANGE%^sunlight%^RESET%^ held in tight formation as a sword by magic.");
    set_wc(1,8);
    set_large_wc(1,8);
    set_wield((:TO, "extra_wield":));
    set_unwield((:TO,"extra_unwield":));
    set_hit((:TO,"extra_hit":));
}

int extra_hit(object ob){
    if(!objectp(ob)) return 3;
    tell_object(ETO,"The %^ORANGE%^sunblade%^RESET%^ flashes and cuts "+ob->query_cap_name()+"'s flesh.");
    tell_object(ob,"The %^ORANGE%^sunblade%^RESET%^ held by "+ETO->query_cap_name()+" cuts into your flesh.");
    tell_room(environment(ob),"The %^ORANGE%^sunblade%^RESET%^ held by "+ETO->query_cap_name()+" flashes brightly and cuts "+ob->query_cap_name()+".",({ob,ETO}));
    return 3;
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
        tell_object(TP,"You are not allowed to wield this sword.");
        return 0;
    }
    if(objectp(ETO)) ETO->add_attack_bonus(2);
    return 1;
}

int extra_unwield(){
    if(objectp(ETO)) ETO->add_attack_bonus(-2);
    return 1;
}

int drop(){
    tell_object(TP,"Your hand will not release the divine blade!");
    return 1;
}

int save_me(string file){ return 1;}
