// magic sword for spells

#include <std.h>

inherit WEAPON;

string owner;

void create(){
    ::create();
    set_id(({"sword","magic sword","wood sword"}));
    set_type("magicslashing");
    set_weight(0);
    set_value(0);
    set_name("wood sword");
    set_short("A wood sword");
    set_long("This sword is a piece of wood molded into a powerful sword by magic.");
    set_wc(1,1);
    set_large_wc(1,1);
    set_wield((:TO, "extra_wield":));
    set_hit((:TO,"extra_hit":));
}

int extra_hit(object ob){
    if(!objectp(ob)) return 1;
    tell_object(ETO,"The wood sword sinks into "+ob->query_cap_name()+"'s flesh.");
    tell_object(ob,"The wood sword held by "+ETO->query_cap_name()+" sinks into your flesh.");
    tell_room(environment(ob),"The wood sword held by "+ETO->query_cap_name()+" sinks into "+ob->query_cap_name()+"'s flesh.",({ob,ETO}));
    if(ETO->is_class("cleric") && !ETO->is_class("fighter"))
        return ETO->query_guild_level("cleric");
    else
        if(ETO->query_guild_level("cleric") > 10) 
            return random(10);
        else
            return ETO->query_guild_level("cleric");
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
    return 1;
}

int drop(){
    tell_object(TP,"Your hand will not release the divine blade!");
    return 1;
}

int save_me(string file){ return 1;}
