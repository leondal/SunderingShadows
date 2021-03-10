// whip of flame for spells

#include <std.h>

inherit WEAPON;

string owner;

void create(){
    ::create();
    set_id(({"lash","magic lash","wind lash"}));
    set_name("wind lash");
    set_short("%^CYAN%^A wind lash%^RESET%^");
    set_long("This lash is not really a lash but is actually a swilring mass of %^CYAN%^air%^RESET%^ held in tight formation as a lash by magic.");
    set_type("magicslashing");
    set_weight(0);
    set_value(0);
    set_wield((:TO, "extra_wield":));
    set_wc(1,1);
    set_large_wc(1,1);
    set_hit((:TO,"extra_hit":));
}

int extra_hit(object ob){
    if(!objectp(ob)) return (2*(int)(ETO->query_guild_level("cleric")));
    tell_object(ETO,"The wind lash cuts into "+ob->query_cap_name()+"'s flesh.");
    tell_object(ob,"The wind lash %^RESET%^held by "+ETO->query_cap_name()+" cuts into your flesh.");
    tell_room(environment(ob),"The wind lash held by "+ETO->query_cap_name()+" cracks sharply and cuts into "+ob->query_cap_name()+"'s flesh.",({ob,ETO}));
    if(ETO->is_class("cleric") && !ETO->is_class("fighter"))
        return 1*(int)ETO->query_guild_level("cleric");
    else
        if(ETO->query_guild_level("cleric") > 10) 
            return random(15);
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
        tell_object(TP,"You are not allowed to wield this whip.");
        return 0;
    }
    return 1;
}

int drop(){
    tell_object(TP,"Your hand will not release the divine whip!");
    return 1;
}

int save_me(string file){ return 1;}
