#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
object *enslaved;

void create() 
{
    object weap;
    ::create();
    set_name("elazo");
    set_id(({"elazo","fat and twisted creature","fat creature",
    "twisted creature","creature", "elazohauntedhouse"}));
    
    set_gender("male");

    set_race("fat and twisted creature");
    set_short("A fat and twisted male creature");
    
    set_long("%^YELLOW%^This grotesque creature appears much "+
    "like a shorter than average male human.  His body is "+
    "bulging with layers of fat and the flesh appears "+
    "strangely darkened and twisted, as if the health and life have "+
    "fled from it and left it remaining in a state of almost "+
    "pure %^BOLD%^%^BLACK%^rot%^RESET%^%^YELLOW%^.  His head "+
    "is rounded and greasy, thinning %^RED%^red%^YELLOW%^ hair "+
    "comes down from the scalp.  The eyes that are set into "+
    "this creatures' head are a fiery red, blazing with a "+
    "very real hatred and something deeper, something like "+
    "an unbridled rage.  Each of this creatures' large arms "+
    "holds a small hammer and a suit of mithril chainmail "+
    "is worn on his obese torso.%^RESET%^");    
        
    set_body_type("human");
    set_alignment(9);
    set_hd(35, 10);
    
    set_stats("strength",22);
    set_stats("constitution",15);
    set_stats("wisdom",15);
    set_stats("intelligence",17);
    set_stats("dexterity",19);
    set_stats("charisma",10);

    set("aggressive",30);
    set_overall_ac(-30);

	set_hp(3750 + random(250));
    
    new(HHOB+"elazosshieldbreaker")->move(TO);
    command("wield hammer");
    
    weap = new("/d/deku/keep/obj/elazoshammer");
    weap->set_property("enchantment",2);
    weap->move(TO);
    command("wield hammer");
        
    set_new_exp(30, "boss");
    set_funcs(({"vicious_illusion","mass_charm"}));
    set_func_chance(50); 
    set_property("full attacks",1);
    enslaved = ({});
}

void break_free() 
{
    object *freed;
    int x;
    freed = ({});
    if(!objectp(TO)) return;
    
    for(x = 0;x < sizeof(enslaved);x++) 
    {
        if(!objectp(enslaved[x])) 
        {
            freed += ({enslaved[x]}); 
            continue;
        }
        if(enslaved[x]->will_save(35)) 
        {
            freed += ({enslaved[x]});
            tell_room(ETO,enslaved[x]->QCN+"%^RED%^ seems to "+
            "break free of the creatures' influence!%^RESET%^");
            TO->remove_protector(enslaved[x]);
            enslaved[x]->force_me("kill "+TO->query_name());
            enslaved[x]->remove_property("enslaved");
            continue;
        }
        continue;
    }
    enslaved -= freed;
    if(sizeof(enslaved)) 
    {
        call_out("break_free",25);
    }    
}
        

void mass_charm(object targ) 
{
    object *things;
    int x, dam;

    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;  
    
    tell_room(ETO,"%^RED%^The strange creatures yells out in an "+
    "almost %^CYAN%^soothing%^RESET%^%^RED%^ voice!%^RESET%^");
    
    things = all_living(ETO);
    things -= ({TO});
    for(x = 0;x < sizeof(things);x++) 
    {
        if(!interactive(things[x])) 
        {
            if(!things[x]->will_save(35) && !things[x]->query_property("enslaved")) 
            {
                things[x]->set_property("enslaved",1);
                enslaved += ({things[x]});
                call_out("break_free",25);
                tell_room(ETO,things[x]->QCN+"%^BLUE%^ "+
                "seems to be enthralled by the strange "+
                "creature and stands in protection of it!%^RESET%^");
                TO->add_protector(things[x]);
                continue;
            }
            continue;
        }
        if(interactive(things[x]) && !things[x]->query_true_invis()) 
        {
            if(!things[x]->will_save(35)) 
			{
                tell_object(things[x],"%^RED%^You feel yourself "+
                "weakened by the %^CYAN%^soothing%^RESET%^%^RED%^ "+
                "voice!%^RESET%^");
                set_property("magic",1);
                dam = roll_dice(8, 12);
                things[x]->cause_typed_damage(things[x], "head", dam, "mental");
                TO->add_hp(dam);
                set_property("magic",-1);
                continue;
            }
        }
    }
}
   


void vicious_illusion(object targ) 
{
    int x, hits;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!objectp(ETO)) return;
    tell_object(targ,"%^RED%^The strange creature gazes at you "+
    "for a moment and then %^YELLOW%^shrieks loudly!%^RESET%^");
    
    tell_room(ETO,"%^RED%^The strange creature gazes at "+
    targ->QCN+"%^RED%^ for a brief moment and then "+
    "%^YELLOW%^shrieks loudly!%^RESET%^",targ);
    
    hits = 2 + random(3);

    for(x = 0;x < hits;x++) 
    {
        if(!objectp(targ)) break;
        tell_object(targ,"%^CYAN%^Something slams you in the back "+
        "of the head and a %^BOLD%^%^GREEN%^sickening%^RESET%^"+
        "%^CYAN%^ thud resounds through the chamber!%^RESET%^");
        set_property("magic",1);
        targ->cause_typed_damage(targ, "head",roll_dice(5,12), "mental");
        set_property("magic",-1);
        
        tell_room(ETO,"%^CYAN%^A %^BOLD%^%^GREEN%^sickening%^CYAN%^"+
        " thud resounds through the chamber as "+
        targ->QCN+"%^CYAN%^'s head is suddenly jerked forward!"+
        "%^RESET%^",targ);

        continue;
    }
}   