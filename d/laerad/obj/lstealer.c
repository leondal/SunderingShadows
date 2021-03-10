//Coded by Bane//
//WARNING: This weapon does not auto-load so please do not restore this item//
//to players who complain that they lost it in reboot or whatever//
#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/shortsword.c";
#define MAXUSES 9
int uses;
object owner;

void save_me(string file){return 1;}

void create()
{
    ::create();
    set_id(({"sword","short sword","stealer","Sword","Short sword"}));
    set_name("Short sword, nine lives stealer");
    set_obvious_short("blackened short sword");
    set_short("Nine lives stealer");
    set_long(
       "This %^BOLD%^%^BLACK%^black-bladed %^RESET%^short sword has "+
       "a hilt covered in the decaying skin of a %^BOLD%^%^BLACK%^"+
       "scaly reptile%^RESET%^.  Its blade is extremely sharp and "+
       "is always covered in a %^RED%^red sheen%^RESET%^, almost as "+
       "if it is %^RED%^bleeding%^RESET%^.  %^GREEN%^Runes %^RESET%^cover "+
       "the weapon, etched deeply and glowing a %^GREEN%^faint green%^RESET%^."
    );
    set_lore("The nine lives stealer sucks the very life from a "+
       "target.  It is made using an age-old ritual involving the "+
       "blood of innocents - or their souls, when possible.  The first "+
       "nine lives stealer was made by the Arch Necromancer, Thalonius "+
       "Blackhand, as a simple tool.  In researching certain spells, "+
       "Thalonius often needed souls to practice upon, and this lovely "+
       "little tool captured them with no problems, allowing Thalonius "+
       "to keep them stored in his lab for ease of use.");
    set_weight(10);
    //set_size(1);
    set_value(500);
    //set_wc(1,6);
    //set_large_wc(1,8);
    //set_type("slashing");
    set_property("enchantment",2);
    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"removeme":));
    set_hit((:TO,"exp_steal":));
    uses = 0;
    set_heart_beat(1);
}
void init()
{
    ::init();
    if(ETO != TP) return;
    if(interactive(TP) && !owner) owner = TPQN;
}

void heart_beat()
{
    object holder, env;
    env = ETO;
    if(!objectp(ETO)) return;
    if(objectp(env) && living(env) && interactive(env))
    {
        holder = env->query_name();
    } 
    else { return; }
    
    if(holder != owner)
    {
        tell_object(env,"The Short sword, nine lives stealer, knows you aren't its owner and disappears!");
        TO->remove();
    } 
    else { return; }
}

int wield_me()
{
    if(TP->query_level() < 11)
    {
        write("You try to wield this weapon but it repels your touch!");
        return 0;
    }
    write("The sword sends a chill down your spine.");
    ETO->set_property("evil item",1);
    return 1;
}

int removeme()
{
   ETO->set_property("evil item",-1);
   return 1;
}

int exp_steal(object targ)
{
    int exp,loss,level;

    if(!objectp(targ)) return 0;
    if(!interactive(targ)) return 0;

    if(!avatarp(targ))
    {
        if(random(40) > 38)
        {

            exp = (int)targ->query_exp();
            uses += 1;

            tell_object(targ,"%^BOLD%^The Short sword, nine lives stealer bites into "
                "you draining your life experience!");
            tell_room(ETO,"%^BOLD%^"+targ->query_cap_name()+" howls out in pain as the "
                "Short sword, nine lives stealer bites into "+targ->query_objective()+"!",targ);
        
            if(targ->query_exp() < 1001)
            {
                tell_object(targ,"The Sword takes your life.");
                tell_room(ETO,"The Sword takes "+targ->QCN+"'s life.",targ);
                targ->set_hp(-50);
            }

            level = (int)targ->query_adjusted_character_level();
            loss = to_int(exp * (random(500) * 0.0001)); // between 0 and 5% of their exp
            targ->add_exp(-1 * loss);
            targ->resetLevelForExp(0);
            if((int)targ->query_adjusted_character_level() < level)
            {
                ADVANCE_D->class_news((string)targ->query_class(),targ->QCN+" has lost a level to the "
                    "short sword, nine lives stealer!");
            }

            tell_object(targ,"DEBUG Subtracting "+loss+" exp");
        }
    }

    if(uses == 9)
    {
        tell_room(ETO,"%^BOLD%^BLUE%^The Short sword nine lives stealer takes its "
            "last life and disintegrates!");
        TO->move("/d/shadowgate/void");
        destruct(TO);
        return 1;
    }
}
