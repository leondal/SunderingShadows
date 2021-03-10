//Coded by Bane//
//Revamped by Ares

#include <std.h>


inherit "/d/common/obj/weapon/longsword";


int COUNTER;
string owner;


void create()
{
    ::create();
    set_id(({"sword","long sword","ragnarok","Ragnarok"}));
    set_name("%^RED%^Ragnarok");
    set_obvious_short("%^BOLD%^%^BLACK%^an %^RED%^ominous%^BLACK%^ sword as black as co%^RED%^a%^BLACK%^l%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^R%^RESET%^%^RED%^a%^BOLD%^g%^BLACK%^n%^RESET%^%^RED%^a"
        "%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^o%^BOLD%^%^RED%^k%^BLACK%^ destroyer of worlds.%^RESET%^");    
   set_long("%^BOLD%^%^BLACK%^An %^RED%^a%^BLACK%^st%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^"
       "n%^RED%^i%^BLACK%^sh%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^ng %^RESET%^%^RED%^a%^BOLD%^"
       "u%^RESET%^%^RED%^r%^BOLD%^a %^BLACK%^of terrible %^RED%^po%^RESET%^%^RED%^w%^BOLD%^"
       "er %^BLACK%^radiates from this r%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^m%^RED%^a%^BLACK%^"
       "rk%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^bl%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^sw%^RED%^o"
       "%^BLACK%^rd. Its double-edged coal black blade is wrought with %^RED%^gl%^RESET%^"
       "%^RED%^o%^BOLD%^w%^RESET%^%^RED%^i%^BOLD%^ng %^RESET%^%^RED%^d%^BOLD%^e%^BLACK%^m"
       "%^RED%^o%^BLACK%^n%^RESET%^%^RED%^i%^BOLD%^c r%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^"
       "n%^RESET%^%^RED%^e%^BOLD%^s %^BLACK%^that p%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^ls"
       "%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^te and cr%^RED%^a%^BLACK%^ckl%^RED%^e%^BLACK%^ "
       "as if in anticipation of %^RED%^violence%^BLACK%^. Traveling up the center of the "
       "blade is the %^RED%^cr%^RESET%^%^RED%^i%^BOLD%^ms%^RESET%^%^RED%^o%^BOLD%^n "
       "%^BLACK%^line of the %^RESET%^%^RED%^blood %^BOLD%^%^BLACK%^groove, ve%^RED%^i"
       "%^BLACK%^ns of it branching off throughout the flat on both sides. The blade flows "
       "smoothly into the j%^RED%^a%^BOLD%^%^BLACK%^gg%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d "
       "gu%^RED%^a%^BOLD%^%^BLACK%^rd which has been forged in the semblance of a %^RESET%^"
       "%^RED%^l%^BOLD%^ee%^RESET%^%^RED%^r%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g d%^RESET%^"
       "%^RED%^e%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^o%^BOLD%^n%^RESET%^%^RED%^i%^BLACK%^"
       "%^BOLD%^c v%^RED%^i%^BLACK%^s%^RED%^a%^BLACK%^g%^RED%^e%^BLACK%^. A smoky black "
       "essence wafts from its empty eyes and fanged maw. Cool %^RESET%^%^RED%^d%^BOLD%^e"
       "%^RESET%^%^RED%^m%^BOLD%^o%^RESET%^%^RED%^nsk%^BOLD%^i%^RESET%^%^RED%^n %^BLACK%^"
       "%^BOLD%^h%^RED%^i%^BLACK%^d%^RED%^e%^BLACK%^ wraps the hilt providing a "
       "comfortable grip. Resting at the bottom of the hilt, a fractured obs%^WHITE%^i"
       "%^BLACK%^d%^RESET%^i%^BOLD%^%^BLACK%^an orb makes up the pommel, a faint "
       "%^RESET%^%^RED%^red l%^BOLD%^i%^RESET%^%^RED%^ght %^BOLD%^burning %^BLACK%^from "
       "between the web of cracks.%^RESET%^");
    set_lore("This is rumored to be the most destructive weapon ever created. The story goes"
        " the sword was born with the world and its destiny is linked with the end"
        " of the world. The exact metal or maker is not known, but the sword was first"
        " seen in the possession of a demon known as Qualtatoh. Rumors say Klauth"
        " banished the demon from the prime material plane and took the sword as trophy.");
    set_weight(6);
    set_size(2);
    set_value(100000);
    set_property("enchantment",6);
    set_hit((:TO,"strike":));
    set_wield((:TO,"extra_wield":));
    set_unwield((:TO,"removeme":));
    set_heart_beat(1);
}


int extra_wield()
{
    object obj;

    if((string)ETO->query_true_name() != owner && !ETO->query_true_invis())
    {
        tell_object(ETO,"%^BOLD%^The sword begins to vibrate uncontrollably and shakes "
            "free of your grasp!%^RESET%^");
        tell_room(EETO,"%^BOLD%^The sword vibrates out of "+ETO->QCN+"'s hand!%^RESET%^",ETO);
        TO->move(EETO);
        if(obj = present(owner,ETO))
        {   
            tell_object(obj,"%^GREEN%^The sword recognizes you as its owner and "
                "skitters across to your hand!%^RESET%^");
            tell_room(environment(obj),"%^GREEN%^The sword skitters across "
                "to "+obj->QCN+"'s hand!",obj);
            TO->move(obj);
            if(obj->query_bound())
            {
                tell_object(obj,"%^YELLOW%^The sword slashes through your bonds!%^RESET%^");
                tell_room(environment(obj),"%^YELLOW%^The sword slashes through "+obj->QCN+"'s "
                    "bonds!%^RESET%^",obj);
                obj->set_bound(0);
            }
        }
        return 0;
    }

    if((int)ETO->query_lowest_level() < 40)
    {
        tell_object(ETO,"%^BOLD%^%^RED%^The sword glows with a demonic light and heats in "
            "your hand.%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^RED%^The sword held by "+ETO->QCN+" begins to glow "
            "with a eerie demonic light!",ETO);
        tell_object(ETO,"%^RED%^A painful voice grates in your mind: %^RESET%^You can "
            "never possess Ragnarok mortal.  YOU ARE WEAK!%^RESET%^");
        tell_room(EETO,"%^BOLD%^"+ETO->QCN+" suddenly stills as "+ETO->QP+" expression "
            "goes blank.%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^%^CYAN%^A surge of energy shoots up your arm from "
            "the hilt of the sword and to the base of your skull!%^RESET%^");
        tell_room(EETO,"%^RED%^"+ETO->QCN+" gasps as "+ETO->QP+" body jolts in "
            "agonizing pain!%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^%^RED%^Your head throbs with a blinding pain and "
            "you collapse to the ground vomiting!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" collapses to the ground and "
            "starts to vomit uncontrollably!%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^The sword is jolted from your hand!%^RESET%^");
        tell_room(EETO,"%^BOLD%^The sword is jolted from "+ETO->QCN+"'s hand!%^RESET%^",ETO);
        ETO->set_paralyzed(25,"%^RED%^You are vomiting too hard to move!%^RESET%^");
        ETO->set_blind(1);
        TO->move(EETO);
        return 0;
    }

    tell_object(ETO,"%^BOLD%^%^BLACK%^The power of the %^RED%^demonic%^BOLD%^%^BLACK%^ "
        "sword surges into your veins, swelling the muscles of your arm and filling you "
        "with an unnatural strength!");
    tell_object(ETO,"%^RED%^You can feel your eyes change and your vision is tinted "
        "a deep red as the essense of the lower planes seeps into your very soul!");
    tell_room(EETO,"%^BOLD%^%^RED%^"+ETO->QCN+"'s muscles swell and "+ETO->QP+" eyes "
        "flash red as "+ETO->QS+" grips the hilt of the blade!",ETO);
    ETO->add_attack_bonus(3);
    ETO->add_damage_bonus(3);
    ETO->add_sight_bonus(3);
    ETO->set_property("evil item",1);
    return 1;
}


int removeme()
{
    tell_object(ETO,"%^BOLD%^%^BLUE%^The sword hums for a moment and then grows cool "
        "to the touch as you release the hilt.");
    tell_object(ETO,"%^BOLD%^%^RED%^You blink your eyes as the eerie red "
        "light seeps from your vision.");
    tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+"'s muscles return to normal and the "
        "%^BOLD%^%^RED%^light%^BOLD%^%^GREEN%^ fades from "+ETO->QP+" eyes as "+ETO->QS+" "
        "releases the hilt of the sword.",ETO);
    ETO->add_attack_bonus(-3);
    ETO->add_damage_bonus(-3);
    ETO->add_sight_bonus(-3);
    ETO->set_property("evil item",-1);
    return 1;
}


int strike(object targ)  // It's intentional that more than one special is possible at once
{
    int rand;
    rand = roll_dice(1,10);

    if(roll_dice(1,100) > 37) { COUNTER++; return roll_dice(1,4); }


    if(rand > 0 && rand < 5) // between 1 and 4 or 40%
    {
        tell_object(ETO,"%^BOLD%^%^CYAN%^Special 1.%^RESET%^");

        targ->do_damage("torso",roll_dice(1,8));
        COUNTER--;
    
    }

    if(rand > 2 && rand < 6) // between 3 and 5 or 30%
    {

        tell_object(ETO,"%^BOLD%^%^CYAN%^Special 2.%^RESET%^");

        targ->do_damage("torso",roll_dice(3,10));
        COUNTER--;

    }

    if(rand > 4 && rand < 7) // between 4 and 6 or 20%
    {

        tell_object(ETO,"%^BOLD%^%^CYAN%^Special 3.%^RESET%^");

        targ->set_paralyzed(roll_dice(1,10) + 10, "You can't move.");
        COUNTER--;

    }

    if(rand > 6 && rand < 10) // between 7 and 9 or 20%
    {

        tell_object(ETO,"%^BOLD%^%^CYAN%^Special 4.%^RESET%^");

        COUNTER--;

    }

    if(rand == 10 && COUNTER > 999) // 10 and counter 1000 or higher
    {

        tell_object(ETO,"%^BOLD%^%^CYAN%^Special 5.%^RESET%^");

        COUNTER = 0;

    }

    else if(rand == 10 && COUNTER < 999) { strike(targ); } // try again if the counter isn't 1000

    return 0;
}

int query_counter()
{
    return COUNTER;
}


void init()
{
    ::init();
    if(!owner || owner == "")
    {
        if(interactive(ETO) && !ETO->query_true_invis())
        {
            owner = ETO->query_true_name();
        }
    }
}


void heart_beat()
{
    if(!objectp(ETO)) { return; }
    if(interactive(ETO) && present("ragnarok 2",ETO))
    {
        tell_object(ETO,"%^RED%^The two swords tremble when brought "
            "together.  In a flash, they merge together into a single "
            "blade!");
        present("ragnarok 2",ETO)->set_property("enchantment",1);
        TO->remove();
    }
}


string query_owner() { return owner; }
