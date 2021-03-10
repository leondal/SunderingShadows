#include <std.h>

inherit "/d/common/obj/weapon/handaxe";
int chance, enabled;
object bro;

void normal() 
{
    ETO->add_damage_bonus(-1);
    tell_object(ETO,"%^BOLD%^%^BLACK%^You feel the power "+
    "from the axe %^RED%^leave%^BOLD%^%^BLACK%^ you.%^RESET%^");
    tell_room(EETO,ETOQCN+"%^BOLD%^%^BLACK%^ sighs heavily.%^RESET%^",ETO);
    chance = 0;
    enabled = 0;
    bro = 0;
}


void create()
{
    ::create();
    set_name("A silver hand axe");
    set_id(({"hand axe", "axe", "handaxe", "komnoels penetrator",
    "silver axe", "silver hand axe", "silver handaxe", 
    "komnoels silver axe","penetrator"}));

    set_short("%^BOLD%^%^WHITE%^K%^BOLD%^%^BLACK%^o"+
    "%^BOLD%^%^WHITE%^mn%^BOLD%^%^BLACK%^oe%^BOLD%^%^WHITE%^l's "+
    "P%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^e"+
    "%^BOLD%^%^WHITE%^tr%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^t"+
    "%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^r%^RESET%^");

    set_obvious_short("A silver hand axe");
    set_long("%^BOLD%^%^WHITE%^This small axe spans almost "+
    "two feet in length and is made from a silver steel.  "+
    "The head of the axe is thicker than normal and becomes "+
    "thinner and sharper at its darker colored "+
    "edge.  The handle of the axe has been kept shiny and has "+
    "a barely recognizable inscription written onto it.  The "+
    "far end has been wrapped with a thick %^BOLD%^%^BLACK%^"+
    "black cloth%^BOLD%^%^WHITE%^ to allow for a more secure and "+
    "warmer hold on the weapon.  The opposite end extends through "+
    "the head before flattening out.%^RESET%^");

    set_read("Strike deep my friend, the skull is your home.");
    set_language("common");	
    set_value(1000);
    set_lore("Said to have been wielded by the "+
    "murderer komnoel, this weapon was forged by a mage "+
    "centuries ago and imbued with a magic that would make "+
    "certain it never dulled.  It is uncertain how it fell into "+
    "komnoels hands, some say that he retrieved it from his "+
    "first victim and inscribed it with his own cryptic "+
    "and horrid message.  Another more quiet legend suggests that "+
    "this weapon was formed side by side with a crimson axe that "+
    "was its compliment in everyway, apparently until komnoel "+
    "they were almost always kept seperate.  This weapon was "+
    "thought burried with komnoel some years ago.");
    set_property("enchantment",3);
    //set_item_bonus("attack bonus", 2);
    set_wield((:TO,"wieldme":));
    set_unwield((:TO,"unwieldme":));
    set_hit((:TO,"hit_func":));
}

void bonus(object ob) 
{
    bro = ob;
    ETO->add_damage_bonus(1);
    chance = 400;
    tell_object(ETO,"%^BOLD%^%^BLACK%^You feel a power flow "+
    "out from the %^BOLD%^%^WHITE%^silver axe%^BOLD%^%^BLACK%^ "+
    "and seep into you!%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETOQCN+"%^RED%^ grins and appears strangely "+
        "more powerful.%^RESET%^",ETO);
    }   
    enabled = 1; 
}

int wieldme() 
{
    int x;
    object *weapons;
    weapons = ETO->query_wielded();
    
    if(TO->query_property("enchantment") > 0) 
    {
        for(x = 0;x < sizeof(weapons);x++) {
            if(weapons[x]->id("komnoels mutilator")
            && weapons[x]->query_property("enchantment") > 0) 
            {
                weapons[x]->bonus(TO);
                TO->bonus(weapons[x]);      
                return 1;
            }
        }
    }
    return 1;
}

int unwieldme() 
{
    if(enabled) 
    {
        if(objectp(bro)) bro->normal();
        normal();
    }
    return 1;
}

int hit_func(object targ) 
{
    int time;
    if(!objectp(targ)) return 0;
    if(random(1000) < chance) 
    {
        switch(random(20)) 
        {
            case 0..18:
                tell_room(EETO,ETO->QCN+"%^BOLD%^%^BLACK%^ growls "+
                "loudly before %^RED%^SMASHING%^BOLD%^%^BLACK%^ "+
                targ->QCN+"%^BOLD%^%^BLACK%^ in the nose with "+
                "the end of "+ETO->QP+" %^BOLD%^%^WHITE%^"+
                "silver%^BOLD%^%^BLACK%^ axe!%^RESET%^",({targ,ETO}));
                
                tell_object(ETO,"%^BOLD%^%^BLACK%^You growl loudly "+
                "before %^RED%^SMASHING%^BOLD%^%^BLACK%^ "+
                targ->QCN+"%^BOLD%^%^BLACK%^ in the nose with the "+
                "end of your %^BOLD%^%^WHITE%^silver%^BOLD%^%^BLACK%^ "+
                "axe!%^RESET%^");

                tell_object(targ,ETOQCN+"%^BOLD%^%^BLACK%^ growls "+
                "loudly before %^RED%^SMASHING%^BOLD%^%^BLACK%^ "+
                "you in the nose with the end of "+ETO->QP+" "+
                "%^BOLD%^%^WHITE%^silver%^BOLD%^%^BLACK%^ axe!%^RESET%^");
                set_property("magic",1);
                targ->cause_typed_damage(targ, "head", roll_dice(3,3), "piercing");
                set_property("magic",-1);   
                break;
            case 19:
                time = random(2) + 2;
                tell_room(EETO,ETO->QCN+"%^BOLD%^%^BLACK%^ imbeds "+
                ETO->QP+" axe deep into "+targ->QCN+"%^BOLD%^%^BLACK%^'s "+
                "%^BOLD%^%^WHITE%^skull%^BOLD%^%^BLACK%^"+
                "!%^RESET%^",({targ,ETO}));

                tell_object(ETO,"%^BOLD%^%^BLACK%^You imbed your axe "+
                "%^RED%^deep%^BOLD%^%^BLACK%^ into "+targ->QCN+
                "%^BOLD%^%^BLACK%^'s %^BOLD%^%^WHITE%^skull%^BOLD%^%^BLACK%^"+
                "!%^RESET%^");

                tell_object(targ,ETO->QCN+"%^BOLD%^%^BLACK%^ imbeds "+
                ETO->QP+" axe %^RED%^deep%^BOLD%^%^BLACK%^ into your "+
                "%^BOLD%^%^WHITE%^skull%^BOLD%^%^BLACK%^!%^RESET%^");

                ETO->set_property("magic",1);
                targ->cause_typed_damage(targ, "head", roll_dice(3,3), "piercing");
                ETO->set_property("magic",-1);
                
                targ->set_paralyzed(time * 3,"%^RED%^You are trying "+
                "to recover from the searing pain!%^RESET%^");
                break;
        }
    }
}