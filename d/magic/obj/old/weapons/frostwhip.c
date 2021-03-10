// whip of flame for spells

#include <std.h>
#include <daemons.h>

inherit WEAPON;

string owner;

void create(){
    ::create();
    set_id(({"whip","magic whip","frost whip"}));
    set_name("frost whip");
    set_short("%^CYAN%^A frost whip%^RESET%^");
    set_long("This whip is not really a whip but is actually a swilring mass of %^CYAN%^cold%^RESET%^ held in tight formation as a whip by magic.");
    set_type("magicslashing");
    set_weight(0);
    set_value(0);
    set_wield((:TO, "extra_wield":));
    set_wc(1,1);
    set_large_wc(1,1);
    set_hit((:TO,"extra_hit":));
}

int extra_hit(object ob){
    int dam;
    
    dam = roll_dice(4,4);
    if(!objectp(ob)) return dam;
    tell_object(ETO,"The frost whip cuts into "+ob->query_cap_name()+"'s flesh.");
    tell_object(ob,"The frost whip %^RESET%^held by "+ETO->query_cap_name()+" cuts into your flesh.");
    tell_room(environment(ob),"The frost whip held by "+ETO->query_cap_name()+" cracks sharply and cuts into "+ob->query_cap_name()+"'s flesh.",({ob,ETO}));
    if((SAVING_D->saving_throw(ob, "spell",0))){
        dam = dam/2;
    }
    return dam;
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
