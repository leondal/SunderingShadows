// chilling scythe for spells

#include <std.h>

inherit WEAPON;
string owner;

void create(){
    ::create();
    set_id(({"scythe","magic scythe","chilling scythe"}));
    set_type("magicslashing");
    set_weight(0);
    set_value(0);
    set_name("scythe");
    set_short("A scythe");
    set_long("This scythe is a 7-foot long, but it is absolutely weightless.");
    set_wc(2,4);
    set_large_wc(1,8);
    set_wield((:TO, "extra_wield":));
    set_unwield((:TO, "extra_unwield":));
    set_hit((:TO,"extra_hit":));
}

int extra_hit(object ob){
    if(!objectp(ob)) return 3+random(4);
    tell_object(ETO,"The scythe sinks deep into "+ob->query_cap_name()+"'s flesh, chilling "+ob->query_objective()+".");
    tell_object(ob,"The scythe held by "+ETO->query_cap_name()+" sinks into your flesh, chilling you.");
    tell_room(environment(ob),"The scythe held by "+ETO->query_cap_name()+" sinks into "+ob->query_cap_name()+".",({ob,ETO}));
    return 3+random(4);
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
        tell_object(TP,"You are not allowed to wield this scythe.");
        return 0;
    }
    if(objectp(ETO)){
        ETO->add_attack_bonus(1);
        ETO->add_damage_bonus(1);
    }
    return 1;
}

int extra_unwield(){
    if(objectp(ETO)){
        ETO->add_attack_bonus(-1);
        ETO->add_damage_bonus(-1);
    }
    return 1;
}

int save_me(string file){ return 1;}
