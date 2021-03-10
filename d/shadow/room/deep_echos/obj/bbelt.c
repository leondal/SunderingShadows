// belt that steals old beast claws spell :P
#include <std.h>
#include "../deep_echo.h"
inherit "/std/armour";

void create()
{
   ::create();
   set_obvious_short("%^RESET%^%^RED%^A beast hide belt%^RESET%^");
   set_name("Beast Belt");
   set_id(({"belt","beast belt","beast hide belt"}));
   set_short("%^RESET%^%^RED%^Beast Belt%^RESET%^");
   set_long(
   "%^RED%^This belt seems to be made from a mismash of different "+
   "beasts.  The pattern is chaotic as if the creator "+
   "was trying to add a little of every hunting animal "+
   "on hand.  There is a %^BOLD%^bloodstone%^RESET%^%^RED%^"+
   " cut in half for the "+
   "buckle.  It seems to %^BOLD%^glow with rage.%^RESET%^");
   set_lore(
@HADES
Little is known about the horror of Malar's rituals.
This belt is known to be the product of them.  
It brings out the beast within from the wearer 
giving them maddening strength, however those 
weak of will can find themselves victim to a maddening
frenzy.
HADES
   );
   set_size(2);
   set_value(500);
   set_cointype("silver");
   set_weight(3);
   set_property("enchantment",1);
   set_type("clothing");
   set_item_bonus("strength",1);
   set_item_bonus("intelligence",-1);
   set_item_bonus("wisdom",-1);
   set_item_bonus("charisma",-1);
   set_item_bonus("damage resistance",1);
   set_limbs(({"waist"}));
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   set_heart_beat(1);
}
void heart_beat(){
    int i;
    object owner,env,obj,*inv;
   if(!objectp(ETO)) return;
   env = ETO;
    if(!objectp(ETO)) return;
    if(objectp(env) && living(env)) {
        owner = env;
        env = environment(owner);   
    }
        if(!objectp(env)) return;
        if(env->query_property("no attack")) return;
        if(!TO->query_worn()) return;
         inv = all_inventory(env);
         for(i=0; i<sizeof(inv); i++) {
            if(living(inv[i]) 
             && inv[i] != owner 
             && (int)inv[i]->query_level() < 200 
             && !inv[i]->query_ghost()
             && !inv[i]->query_invis()
             && (string)inv[i]->query_diety() != "malar")
            // will save to not kill        
             if(!(owner->query_current_attacker()))
                                
if(!"/daemon/saving_throw_d.c"->will_save(ETO,-10))
                      owner->force_me("kill "+inv[i]->query_name());
                           else
     write("You resist the urge to kill "+inv[i]->query_name()+".");}
          
}
void init()
{
        ::init();
                if(!objectp(ETO)) return; 
                if(!living(ETO)) return;
	set_size((int)ETO->query_size());
     

}

//removes armor from hands and unwield
int preSpell() {
    object *arm, caster;
  object *wielded;
  //string *ids;
   int i , j;
  wielded = ETO->query_wielded(); 
 
    caster = ETO;
    if(caster->query_property("beastclaws")){
        tell_object(caster,"Your claws cannot morph further.");
        return 0;
    }
if(sizeof(wielded)) {
for(i=0;i<sizeof(wielded);i++) { 
 if(wielded[i]->query_property("enchantment") &&
  (int)wielded[i]->query_property("enchantment") < 0){
  write("The curse on this item prevents you from unwielding it.");
   return 1;}
//ids = wielded[i]->query_id();
wielded[i]->__ActuallyUnwield();
//ETO->force_me("unwield "+ids[1]+""); 
} } 

    arm = caster->query_armour("right hand");
    j = sizeof(arm);
    for (i=0;i<j;i++) {
        if (arm[i]->query_property("enchantment"))
            if ((int)arm[i]->query_property("enchantment") < 0)
                continue;
        caster->remove_armour_from_limb(arm[i], (string
*)arm[i]->query_actual_limbs());
        arm[i]->set_not_equipped();
    }

    arm = caster->query_armour("left hand");
    j = sizeof(arm);
    for (i=0;i<j;i++) {
        if (arm[i]->query_property("enchantment"))



            if ((int)arm[i]->query_property("enchantment") < 0)
                continue;
        caster->remove_armour_from_limb(arm[i], (string
*)arm[i]->query_actual_limbs());
        arm[i]->set_not_equipped() ;
    }

    if (sizeof(caster->query_armour("right hand"))) {
        write("You have cursed armour on your right hand.");
        return 0;
    }
    if (sizeof(caster->query_armour("left hand"))) {
        write("You have cursed armour on your left hand.");
        return 0;
    }
    return 1;
}
void spell_effect() {
    int droll,atts;
    object caster;
        caster = ETO;
        if(!ETO) return;
        atts =  ((int)ETO->query_level() / 7)+1 ; 
    tell_object(caster,"Your hands morph slowly into beastial claws.");
    tell_room(ETO,""+caster->query_cap_name()+"'s hands morph into two
massive beastial claws.",caster);
    caster->remove_limb("right hand");
    caster->remove_limb("left hand");
    caster->set_attack_limbs(({"right claw","left claw"}));
    caster->add_limb("right claw","",0,0,0);
    caster->add_limb("left claw","",0,0,0);
    //addSpellToCaster();
    //droll = (int)caster->query_guild_level("cleric")/5;
    if((string)caster->query_diety()=="malar") 
         {droll = 6;
          caster->add_attack_bonus(3);
          caster->add_damage_bonus(3);
         }
    else{ 
          droll = 4;
          caster->add_attack_bonus(2);
          caster->add_damage_bonus(2);
         }
    caster->set_attacks_num(atts);
    caster->set_damage(2,droll);
    caster->set_base_damage_type("slashing");
    caster->set_hit_funcs((["right claw":({"/daemon/specials_d",
"beastclaws"}),"left claw":({"/daemon/specials_d", "beastclaws"})]));
    //caster->set_property("spelled",({TO}));
    caster->set_property("beastclaws",1);
   
}

void dest_effect() {
    object caster;  
    caster = ETO;
    //if (!objectp(caster)){ remove(); return; }

    caster->remove_limb("right claw");
    caster->remove_limb("left claw");
        if((string)caster->query_diety()=="malar") 
         {
          caster->add_attack_bonus(-3);
          caster->add_damage_bonus(-3);
         }
    else{ 
          
          caster->add_attack_bonus(-2);
          caster->add_damage_bonus(-2);
         }

    caster->set_attacks_num(0);
    caster->set_attack_limbs(({}));
    caster->add_limb("left hand","",0,0,0);
    caster->add_limb("right hand","",0,0,0);
    caster->set_wielding_limbs(({"left hand", "right hand"}));
    tell_object(caster,"Your hands return to their natural form.");
    caster->toggle_polymorphed();
    //caster->remove_property_value("spelled", ({TO}) );
    caster->remove_property("beastclaws");

}

int wearme()
{
        if(preSpell()==0) return 0;
                spell_effect();
        tell_object(ETO,"%^RED%^As soon as you put the belt on,"+
                " your body begins to morph into a beast.  Your "+
                "teeth sharpen, hair grows all over your body and "+
                "your hands morph to claws.");
        tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+
                " puts the"+
        " belt around "+ETO->query_possessive()+" waist and morphs "+
                "into a beastlike state.",ETO);
        
        return 1;
}
int removeme()
{       dest_effect();
        tell_object(ETO,"%^RED%^Removing the belt causes your "+
                "body to return to normal.");
                 tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+
		 " removes the"+
        " belt around "+ETO->query_possessive()+" waist and morphs "+
                "back to normal.",ETO);
        return 1;
}
