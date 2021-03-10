#include <std.h>
//#include <daemons.h>
inherit "/d/common/obj/weapon/hammer_sm.c";
int flag;

void create() 
{
    ::create();
    set_id(({"hammer","small hammer","shield breaker","shieldbreaker",
    "elazos hammer","elazos shieldbreaker","stout hammer",
    "elazos stout hammer","elazos stout shieldbreaker"}));
    set_name("small hammer");
    set_obvious_short("A small black hammer");
    
    set_short("%^BOLD%^%^WHITE%^Elazo's %^BOLD%^%^BLACK%^S"+
    "%^BLUE%^to%^BOLD%^%^BLACK%^ut Sh%^RED%^ie%^BOLD%^%^BLACK%^"+
    "ldbr%^RED%^ea%^BOLD%^%^BLACK%^ck%^RED%^e%^BOLD%^%^BLACK%^r"+
    "%^RESET%^");
        
    set_long("%^BOLD%^%^BLACK%^This hammer is made from "+
    "a solid and sturdy steel that has been dyed or %^RED%^charred "+
    "%^BOLD%^%^BLACK%^a sooty black.  The hammer is small, spanning "+
    "only about two feet in length, and the weight of it hangs mostly "+
    "in the larger than normally head.  The head of the hammer "+
    "is more of a bizarre oval shape and littered with rougher "+
    "%^RED%^bumps%^BOLD%^%^BLACK%^ which have been dyed "+
    "a much %^BOLD%^%^WHITE%^ligher color%^BOLD%^%^BLACK%^.  "+
    "The handle of the hammer connects with the head in "+
    "approximately the center and continues downward, its length "+
    "covered in %^BLUE%^symbols%^BOLD%^%^BLACK%^.  The symbols "+
    "are strange and seem to give off a tangible energy, yet "+
    "one that hides behind the veil of invisibility.  They "+
    "are recognizable as %^BLUE%^symbols%^BOLD%^%^BLACK%^ of "+
    "praise to the god of war, %^RED%^Tempus%^BOLD%^%^BLACK%^.  "+
    "The end of the handle mushrooms out, an effort to keep "+
    "the hammer from slipping from the hand of the wielder."+
    "%^RESET%^");

    set_lore("It is said that this hammer was prepared "+
    "for the gluttonous man Elazo, by a priest and a wizard "+
    "who worked together quite at the insistence of the "+
    "greedy man.  The priest served tempus ruthlessly and "+
    "blessed the hammer in the name of his god, leaving "+
    "markings of praise littering the handle, and the mage "+
    "was forced to aid elazo by enchanting the hammer with "+
    "a very precise magic.  Elazo disappeared and is considered dead, this "+
    "hammer went with him, as it was not as common as the other "+
    "he held much more dear.");

    set_property("enchantment",5);    
    set_property("lore difficulty",10);
    set_value(2000);    
    set_weapon_speed(6);
    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"special":));
    set_item_bonus("damage bonus", 1);
    set_item_bonus("attack bonus", 2);
}

int wield_me() 
{
    if(ETO->query_highest_level() < 20) 
    {
        tell_object(ETO,"%^RED%^The runes flash brilliantly "+
        "for a moment and then you feel the power of "+
        "the hammer reject you!%^RESET%^");
        ETO->cause_typed_damage(ETO, "torso",roll_dice(2,8), "mental");
        ETO->add_attacker(TO);
        ETO->continue_attack();
        if(objectp(ETO)) 
        {
            ETO->remove_attacker(TO);
        }
        return 0;
    }
    tell_object(ETO,"%^BLUE%^The runes simultaneously flash "+
    "brilliantly for only a brief moment and you feel "+
    "strengthened by the power of the hammer!%^RESET%^");
    
    tell_room(EETO,ETOQCN+"%^BLUE%^ grips the handle of "+
    ETO->QP+" black hammer and the runes along its handle "+
    "simultaneously flash brilliantly for a brief moment!%^RESET%^",
    ETO);
    return 1;    
}

int unwield_me() 
{
    tell_object(ETO,"%^BLUE%^The feel yourself weakend as you "+
    "release the hammer.%^RESET%^");
    
    if(!ETO->query_invis()) {
        tell_room(EETO,ETOQCN+"%^BLUE%^ looks strangely weaker as "+
        ETO->QS+" releases "+ETO->QP+" black hammer.%^RESET%^");
    }
    return 1;
}

int special(object targ) 
{
    int chance, x;
    object sh, *arm;

    if(random(1000) < 150) 
    {
        arm = targ->all_armour();
        for(x = 0;x < sizeof(arm);x++) 
        {
            if((string)arm[x]->query_type() == "shield") 
            {
                sh = arm[x];
                break;
            }
        }
        if(!objectp(sh)) 
        {
            arm = targ->query_wielded();
            for(x = 0;x < sizeof(arm);x++) 
            {
                if((string)arm[x]->query_type() == "shield") 
                {
                    sh = arm[x];
                    break;
                }
            }
        }
        if(objectp(sh)) 
        {
            tell_object(ETO,"%^BOLD%^%^BLACK%^You direct your "+
            "%^RED%^fi%^YELLOW%^e%^RED%^rce%^BOLD%^%^BLACK%^ blow "+
            "to strike "+targ->QCN+"%^BOLD%^%^BLACK%^'s shield!"+
            "%^RESET%^");
   
            tell_object(targ,ETOQCN +"%^BOLD%^%^BLACK%^ directs "+
            ETO->QP+" %^RED%^fi%^YELLOW%^e%^RED%^rce%^BOLD%^%^BLACK%^ "+
            "blow to strike your shield!%^RESET%^");
                           
            tell_room(EETO,ETOQCN +"%^BOLD%^%^BLACK%^ directs "+
            ETO->QP+"%^RED%^ fi%^YELLOW%^e%^RED%^rce%^BOLD%^%^BLACK%^ "+
            "blow to strike "+targ->QCN+"%^BOLD%^%^BLACK%^'s "+
            "shield!%^RESET%^",({targ,ETO}));
              
            if(roll_dice(1,20) + 9 > ((sh->query_property("enchantment") + 10) * 2) 
            && sh->query_property("enchantment") >= 0 && !random(50)) 
            {
                tell_object(ETO,"%^RED%^The force of your blow "+
                "shatters "+targ->QCN+"%^RED%^'s shield!%^RESET%^");
                    
                tell_object(targ,"%^RED%^The force of the blow "+
                "shatters your shield!%^RESET%^");

                tell_room(EETO,"%^RED%^The force of "+ETOQCN+"%^RED%^'s"+
                " blow shatters "+targ->QCN+"%^RED%^'s shield!"+
                "%^RESET%^",({targ,ETO}));
                sh->remove();
             }
            return targ->cause_typed_damage(targ, "right hand",roll_dice(1,10), "bludgeoning");
		
        }
     
        tell_object(ETO,"%^BOLD%^%^BLACK%^You swing your hammer "+
        "with all of your might and %^RED%^slam%^BOLD%^%^BLACK%^"+
        " it into "+targ->QCN+"%^BOLD%^%^BLACK%^'s torso!%^RESET%^");
        
        tell_object(targ,ETOQCN+"%^BOLD%^%^BLACK%^ swings "+
        ETO->QP+" hammer with all of "+ETO->QP+" might and %^RED%^slams"+
        "%^BOLD%^%^BLACK%^ it into your torso!%^RESET%^");
        
        tell_room(EETO,ETOQCN+"%^BOLD%^%^BLACK%^ swings "+
        ETO->QP+" hammer with all of "+ETO->QP+" might and %^RED%^"+
        "slams it into "+targ->QCN+"%^BOLD%^%^BLACK%^'s "+
        "torso!%^RESET%^",({targ,ETO}));
        
        return targ->cause_typed_damage(targ, "right hand",roll_dice(2,6), "bludgeoning");
    }
}
