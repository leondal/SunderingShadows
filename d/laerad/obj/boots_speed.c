//Coded by Bane//
#include <std.h>
inherit ARMOUR;
string owner;
void create(){
    ::create();
    set_id(({"boots","boots of speed","speed"}));
    set_name("leather boots");
    set_short("A pair of fine leather boots");
    set_long(
        "These boots are made of a fine quality leather. They look "+
        "quite expensive and nearly brand new. They weigh close to "+
        "nothing and seem to have a shady haze around them, making "+
        "them look as if they are almost shaking."
    );
   set("lore","These boots are imbued with a magical property that allows their wearer to be much quicker than normal.");
    set_weight(5);
    set_value(5000);
    set_type("clothing");
    set_limbs(({"right foot","left foot"}));
   //set_ac(-1)
//taken out to work the same as other boots - Saide
    set_property("enchantment",2);
    set_wear((:TO,"wield_me":));
    set_remove((:TO,"unwield_me":));
    set_heart_beat(1);
}
void wield_me(){
    if((string)TPQN != owner){
         write("These are not your boots.");
        remove();
        return 0;
    }
    write("Your feet feel lighter than air and as if you can run for miles.");
    return 1;
}
void unwield_me(){
    write("You feel tired and sluggish.");
    return 1;
}
void init(){
    ::init();
    if(interactive(TP) && TP == environment(TO) && !owner)
        owner = TPQN;
}
void heart_beat(){
    if(!living(ETO)) return 1;
    if(!TO->query_worn()) return 1;
    if(ETO->query_current_attacker()){
        if(!random(30)){
            tell_object(ETO,"%^BOLD%^The boots give you a burst of speed.");
            ETO->execute_attack();
            if(!random(20)){
                tell_object(ETO,"%^RED%^The boots catch on fire from going so fast.");
                ETO->do_damage(ETO->return_target_limb(), roll_dice(2,6));
                ETO->add_attacker(TO);
                ETO->continue_attack();
                TO->remove();
                return 1;
            }
        }
    }
}
