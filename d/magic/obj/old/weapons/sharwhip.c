// whip of shar for spells

#include <std.h>
#include <daemons.h>

inherit WEAPON;

string owner;

void create(){
    ::create();
    set_id(({"whip","magic whip","whip of shar","black whip"}));
    set_name("black whip");
    set_short("A black whip");
    set_long("This whip is not really a whip but is actually a flickering beam of force, surrounded by a %^MAGENTA%^purple%^RESET%^ aura, and held in tight formation as a whip by magic.");
    set_type("magicslashing");
    set_weight(0);
    set_value(0);
    set_wield((:TO, "extra_wield":));
    set_wc(2,4);
    set_large_wc(2,4);
    set_hit((:TO,"extra_hit":));
}

int extra_hit(object ob){
    object *weapons;
    int i;
    string *ids;

    if(!objectp(ob)) return 0;
    tell_object(ETO,"The whip lashes into "+ob->query_cap_name()+"'s flesh.");
    tell_object(ob,"The whip held by "+ETO->query_cap_name()+" lashes into your flesh.");
    tell_room(environment(ob),"The whip held by "+ETO->query_cap_name()+" lashes into "+ob->query_cap_name()+"'s flesh.",({ob,ETO}));
    if(!(SAVING_D->saving_throw(ob, "spell",0))){
        tell_object(ob,"You scream in agony from the sting of "+ETO->query_cap_name()+"'s whip.");
        tell_room(environment(ob),ob->query_cap_name()+" screams in agony and falls to the floor, writhing in pain.",({ob,ETO}));
        ob->set_paralyzed(12,"You are writhing in pain!");
        if(!random(6)){
            weapons = ob->query_wielded();
            if(random(25)> (int)(ob->query_stats("dexterity"))){
                if(sizeof(weapons)) tell_object(ob,"Your pain is so great that you cannot keep hold of your weapons!");
                for(i=0;i<sizeof(weapons);i++){
                    ids = weapons[i]->query_id();
                    ob->force_me("drop "+ids[0]);
                }
            }
        }
    }
    return 0;
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
