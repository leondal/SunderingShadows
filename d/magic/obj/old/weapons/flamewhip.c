// whip of flame for spells

#include <std.h>

inherit WEAPON;

string owner;

void create(){
    ::create();
    set_id(({"whip","magic whip","whip of flames"}));
    set_name("whip of flames");
    set_short("%^RED%^A whip of flames%^RESET%^");
    set_long("This whip is not really a whip but is actually a swilring mass of %^RED%^fire%^RESET%^ held in tight formation as a whip by magic.");
    set_type("magicslashing");
    set_weight(0);
    set_value(0);
    set_wield((:TO, "extra_wield":));
    set_wc(1,8);
    set_large_wc(1,8);
    set_hit((:TO,"extra_hit":));
}

int extra_hit(object ob){
    if(!objectp(ob)) return 3;
    tell_object(ETO,"The whip of %^RED%^flames %^RESET%^burns into "+ob->query_cap_name()+"'s flesh.");
    tell_object(ob,"The whip of %^RED%^flames %^RESET%^held by "+ETO->query_cap_name()+" burns into your flesh.");
    tell_room(environment(ob),"The whip of %^RED%^flames %^RESET%^held by "+ETO->query_cap_name()+" burns into "+ob->query_cap_name()+"'s flesh.",({ob,ETO}));
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
