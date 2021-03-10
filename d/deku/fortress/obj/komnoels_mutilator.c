#include <std.h>

inherit "/d/common/obj/weapon/handaxe.c";
int chance, enabled;
object bro;

void normal() 
{
    ETO->add_attack_bonus(-1);
    chance = 0;
    enabled = 0;
    bro = 0;
    tell_object(ETO,"%^YELLOW%^The laughter within your mind "+
    "finally ceases, leaving you %^RED%^alone%^YELLOW%^ "+
    "once more.%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETOQCN+"%^YELLOW%^ shakes "+ETO->QP+
        " head slowly.%^RESET%^",ETO);
    }
}

void create()
{
    ::create();
    set_name("A crimson hand axe");
    set_id(({ "handaxe", "axe", "small axe", "komnoels axe",
    "mutilating axe", "komnoels handaxe", "mutilating handaxe",
    "mutilator","komnoels mutilator","hand axe","crimson axe",
    "crimson hand axe" }));
	
    set_short("%^BOLD%^%^BLACK%^K%^RED%^o%^BOLD%^%^BLACK%^"+
    "mn%^RED%^oe%^BOLD%^%^BLACK%^l's %^BOLD%^%^BLACK%^M%^RED%^"+
    "u%^BOLD%^%^BLACK%^t%^RED%^i%^BOLD%^%^BLACK%^l%^RED%^"+
    "a%^BOLD%^%^BLACK%^t%^RED%^o%^BOLD%^%^BLACK%^r%^RESET%^");
    set_obvious_short("A crimson hand axe");
	
    set_long("%^RED%^This small axe is made from a solid "+
    "piece of crimson material.  The material is solid and "+
    "perhaps as hard as metal, but the surface of it is "+
    "entirely porous.  The blade of the axe is stained with "+
    "mysterious spots of a darker red and seems to pull "+
    "in the light from around it, creating a tangible "+
    "darker aura.  The handle of the axe is approximately "+
    "one foot long and the end of it has been wrapped "+
    "with a thick soiled and stained red cloth to provide "+
    "a comfortable method of holding the weapon.  A small, "+
    "red ruby, that appears to be filled with a darker "+
    "substance, is set into the end of the handle.%^RESET%^");

    set_value(1000);
    set_lore("The legends attached to this axe are bloody "+
    "indeed.  It was said to have been burried with the "+
    "murderer Komnoel who used it some centuries ago.  "+
    "It was rumoured to have a thirst for blood and some "+
    "even suggest that the thirst of the weapon is actually "+
    "what drove Komnoel into his murderous rampage, others "+
    "suggest Komnoel himself imbued the axe with its bloodlust.  "+
    "It is certain that from the time this weapon was "+
    "known is has always been infamous, and some stories suggest "+
    "that it was created side by side with another silver "+
    "axe that was its compliment in every way, regardless, the truth of "+
    "its creation may forever be masked, but the murders "+
    "that have been commited by its blade will "+
    "not be easily forgotten.");

    set_property("enchantment",3);
    //set_item_bonus("damage bonus", 1);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
}

void bonus(object ob) 
{
    bro = ob;
    ETO->add_attack_bonus(1);
    chance = 400;
    enabled = 1;
    tell_object(ETO,"%^RED%^A more intense laughter briefly fills "+
    "your mind as the blade of the crimson axe pulses a "+
    "%^BOLD%^%^BLACK%^darker%^RESET%^%^RED%^ hue.%^RESET%^");
    
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETOQCN+"%^RED%^ suddenly seems "+
        "startled as the blade of "+ETO->QP+" crimson axe "+
        "pulses a %^BOLD%^%^BLACK%^darker%^RESET%^%^RED%^ hue."+
        "%^RESET%^",ETO);
    }    
}

int wield_func()
{
    int x;
    object *weapons;
    weapons = ETO->query_wielded();
    if(TO->query_property("enchantment") > 0) 
    {
        for(x = 0;x < sizeof(weapons);x++) {
            if(weapons[x]->id("komnoels penetrator")
            && weapons[x]->query_property("enchantment") > 0) 
            {
                weapons[x]->bonus(TO);
                TO->bonus(weapons[x]);      
                return 1;
            }
        }
    }

    tell_room(EETO,ETO->QCN+"%^RED%^ laughs wildy as "+
    ETO->QS + " wields the axe.%^RESET%^",ETO);
	
    tell_object(ETO,"%^RED%^You take the handle of "+
    "the axe firmly in hand and burst into wild laughter "+
    "as its bloodlust calls out to you.%^RESET%^");
    
    //ETO->set_property("evil item",1);

    return 1;
}

int unwield_func()
{
    if(enabled) 
    {
        if(objectp(bro)) bro->normal();
        normal();
    }
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETO->QCN+"%^BOLD%^%^WHITE%^ seems to calm "+
        "down considerably as "+ETO->QS+" lets go of the axe."+
        "%^RESET%^",ETO);
    }
    tell_object(ETO,"%^RED%^You feel the call of bloodlust "+
    "lessen as you release the axe.%^RESET%^");    
   
    //was for the way the axe originally worked - before it 
    //began working together with the komnoels penetrator - Saide
    //ETO->set_property("evil item",-1);

    return 1;
}

int hit_func(object targ)
{
    if(!objectp(targ)) return 0;
    if(random(1000) < chance) 
    {
        switch(random(20)) 
        {
            case 0..18:

                tell_room(EETO,ETO->QCN+"%^RED%^ screams out in bloodlust "+
                "as "+ETO->QS+" mutilates "+targ->QCN+"%^RED%^ with "+ETO->QP+
                " axe!%^RESET%^",({ETO,targ}));
	
                tell_object(ETO,"%^RED%^You scream out in bloodlust as you "+
                "mutilate "+targ->QCN+"%^RED%^ with your axe!%^RESET%^");
	
                tell_object(targ,ETO->QCN+"%^RED%^ screams out in bloodlust "+
                "as "+ETO->QS+" mutilates you with "+ETO->QP+" axe!%^RESET%^");
                ETO->set_property("magic",1);
                targ->cause_typed_damage(targ, "head", roll_dice(3,3), "piercing");
                ETO->set_property("magic",-1);
                break;
            case 19:
                
                tell_room(EETO,ETO->QCN+"%^YELLOW%^ mumbles a soft "+
                "chant, causing the blade of "+ETO->QP+" %^RED%^"+
                "crimson axe%^YELLOW%^ to %^CYAN%^glow brightly."+
                "%^YELLOW%^ before striking "+targ->QCN+
                "%^YELLOW%^!%^RESET%^",({targ,ETO}));

                tell_object(ETO,"%^YELLOW%^You suddenly mumble a soft "+
                "chant that causes the blade of your %^RED%^crimson "+
                "axe%^YELLOW%^ to %^CYAN%^glow brightly%^YELLOW%^ "+
                "before striking "+targ->QCN+"%^YELLOW%^!%^RESET%^");
                
                tell_object(targ,ETOQCN+"%^YELLOW%^ mumbles a soft "+
                "chant that causes the blade of "+ETO->QP+
                " %^RED%^crimson axe%^YELLOW%^ to %^CYAN%^glow "+
                "brightly%^YELLOW%^ before it strikes you!%^RESET%^");

                set_property("magic",1);
                targ->cause_typed_damage(targ, "head", roll_dice(3,3), "piercing");
                set_property("magic",-1);
                break;
        }
    }               
}