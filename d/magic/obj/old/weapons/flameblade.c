// flame blade for spells

#include <std.h>

inherit WEAPON;

string owner;

void create(){
    ::create();
    set_id(({"sword","magic sword","blade","flame blade"}));
    set_type("magicslashing");
    set_weight(0);
    set_value(0);
    set_name("flame blade");
    set_short("%^RED%^A flame blade");
    set_long("This sword is not really a sword but is actually a swirling mass of %^RED%^fire%^RESET%^ held in tight formation by magic to create the appearance of one.");
    set_wc(1,8);
    set_large_wc(1,8);
    set_wield((:TO, "extra_wield":));
    set_hit((:TO,"extra_hit":));
}

int extra_hit(object ob){
    if(!objectp(ob)) return 5;
    tell_object(ETO,"The %^RED%^flame blade%^RESET%^ sears "+ob->query_cap_name()+"'s flesh.");
    tell_object(ob,"The %^RED%^flame blade%^RESET%^ held by "+ETO->query_cap_name()+" burns into your flesh.");
    tell_room(environment(ob),"The %^RED%^flame blade%^RESET%^ held by "+ETO->query_cap_name()+" burns into "+ob->query_cap_name()+".",({ob,ETO}));
    return 5;
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
