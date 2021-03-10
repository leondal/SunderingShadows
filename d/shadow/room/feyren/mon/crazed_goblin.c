#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"

inherit MONSTER;

void create() 
{
    int myLev;
    object ob;
    ::create();
	
    set_name("pale goblin");
    set_id(({ "goblin", "pale goblin", "crazed goblin" }));

    set_short("%^BOLD%^%^WHITE%^P%^RESET%^%^WHITE%^"+
    "a%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^e %^BOLD%^%^WHITE%^"+
    "g%^RESET%^%^WHITE%^o%^BOLD%^%^WHITE%^bl%^RESET%^%^WHITE%^i%^BOLD%^"+
    "%^WHITE%^n%^RESET%^");
    set("aggressive",25);

    set_long("%^BOLD%^%^YELLOW%^This foul smelling goblin stands "+
    "approximately four feet tall but his form is stooped as if "+
    "he has been chronically bent at the waist. His flesh is pale, "+
    "as if he has not seen the sun in far too long. His clothing "+
    "is tattered to the point of offering almost no covering "+
    "at all. His teeth are "+
    "blackened and chipped and his mouth hangs open constantly "+
    "in a crazed grin. His eyes dart about back and forth "+
    "chaotically, as if expecting something to jump out at "+
    "him.%^RESET%^");

    myLev = 13 + random(3);
    set_hd(myLev,3);
    set_class("fighter");
    set_mlevel("fighter", myLev);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_alignment(9);
    set_stats("intelligence",12);
    set_stats("wisdom",8);
    set_stats("strength",18);
    set_stats("charisma",3);
    set_stats("dexterity",14);
    set_stats("constitution",13);
    set_race("goblin");
    set_gender("male");
    set_overall_ac(-3);
    set_new_exp(14,"normal");
    set_max_hp((myLev*8) + random(15));
    set_hp(query_max_hp());
    set_achats(3,({
    "%^BOLD%^%^WHITE%^Goblin Screams: %^RESET%^%^RED%^WE GUNNA DIE!%^RESET%^",
    "%^BOLD%^%^BLUE%^Goblin Cackles: %^RESET%^%^RED%^Web ya she will!%^RESET%^",
    "%^BOLD%^%^YELLOW%^Goblin Moans: %^RESET%^%^RED%^Oh the sun... no bother me no more!%^RESET%^",
    "The goblin slobbers all over himself and then laughs!"
    "The goblin cowers down close the floor, begging himself for mercy!"
    }));
    set_emotes(3,({
    "The goblin suddenly slaps himself in the face!",
    "The goblin cackles insanely and points at something that isn't there, laughing wildly!",
    "The goblin slaps up at one of the glowing stones, trying to knock it lose!",
    }),0);

    add_money("gold",random(200)+10);

    set_property("full attacks",1);
    add_search_path("/cmds/fighter");

    set_monster_feats(({
        "parry",
    }));
    set_funcs(({"bite", "trip"}));
    set_func_chance(15);
    set_moving(1);
    set_speed(45);

    set_nogo(({FFTR"40", FFGTR"13", FFGTR"28"}));
    if(!random(10)) 
    {
        ob = new(FFOB+"flaming_axe");
        ob->move(TO);
        if(!random(2)) ob->set_property("monsterweapon", 1);
        command("wield axe");
    }
    else 
    {
        ob = new("/d/common/obj/weapon/handaxe");
        ob->move(TO);
        ob->set_property("enchantment", random(3));
        command("wield axe");	
    }
    if(!random(15)) 
    {
        ob = new(FFOB+"flaming_axe");
        ob->move(TO);
        command("wield axe");
    }
    else 
    {
        ob = new("/d/common/obj/weapon/club");
        ob->move(TO);
        ob->set_property("enchantment", random(3));
        command("wield club");	
    } 
}

void bite(object targ)
{
    string limb;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    
    tell_object(targ, TOQCN+"%^BOLD%^%^YELLOW%^ "+
    "jumps at you, his %^BOLD%^%^BLACK%^black "+
    "%^BOLD%^%^YELLOW%^and broken teeth %^BOLD%^"+
    "%^RED%^gnashing%^BOLD%^%^YELLOW%^ wildly!%^RESET%^");
	
    tell_room(ETO, TOQCN+"%^BOLD%^%^YELLOW%^ "+
    "jumps at "+targ->QCN+"%^BOLD%^%^YELLOW%^ his "+
    "%^BOLD%^%^BLACK%^black and %^BOLD%^%^YELLOW%^broken "+
    "teeth %^BOLD%^%^RED%^gnashing%^BOLD%^%^YELLOW%^ wildly"+
    "!%^RESET%^", targ);

    if(targ->reflex_save(18)) 
    {
	
        tell_object(targ, "%^BOLD%^%^GREEN%^You quickly "+
        "avoid the "+TOQCN+"%^BOLD%^%^GREEN%^ and watch "+ 
        "him fall flat on his face!%^RESET%^");
		
        tell_room(ETO, targ->QCN +"%^BOLD%^%^GREEN%^ quickly "+
        "avoid the "+TOQCN+"%^BOLD%^%^GREEN%^ and he "+
        "falls flat on his face!%^RESET%^", targ);
        TO->set_tripped(1);
        return;
    }
    limb = targ->return_target_limb();

    tell_object(targ,TOQCN+
    "%^BOLD%^%^GREEN%^ sinks his %^BOLD%^%^BLACK%^"+
    "black %^BOLD%^%^GREEN%^and broken teeth into "+
    "your "+limb+"!%^RESET%^"); 		
    tell_room(ETO, TOQCN+"%^BOLD%^%^GREEN%^ sinks his "+
    "%^BOLD%^%^BLACK%^black %^BOLD%^%^GREEN%^and broken "+
    "teeth into "+targ->QCN+"%^BOLD%^%^GREEN%^'s "+
    limb+"!%^RESET%^", targ);
    targ->cause_typed_damage(targ,limb,roll_dice(3,6),"piercing");
    return;
}

void trip(object targ)
{
    string limb;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
	
    tell_object(targ, TOQCN+"%^BOLD%^%^RED%^ kicks wildly "+
    "at you, trying to knock you down!%^RESET%^");

    tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ kicks wildly "+
    "at "+targ->QCN+"%^BOLD%^%^RED%^, trying to knock "+
    targ->QO+" down!%^RESET%^", targ);

    if(targ->reflex_save(20)) 
    {
        tell_object(targ, "%^BOLD%^%^BLUE%^You effortlessly "+
        "avoid the kicks and watch as "+TOQCN+"%^BOLD%^%^BLUE%^"+
        " loses his balance and trips!%^RESET%^");

        tell_room(ETO, targ->QCN+"%^BOLD%^%^BLUE%^ effortlessly "+
        "avoids the kicks and "+TOQCN+"%^BOLD%^%^BLUE%^ "+	    
        "loses his balance and trips!%^RESET%^", targ);
        return; 
    }
    limb = targ->return_target_limb();

    tell_object(targ, TOQCN+"%^BOLD%^%^BLUE%^ makes contact "+
    "with your "+limb+" and you fall to the ground!%^RESET%^");
	
    tell_room(ETO, TOQCN+"%^BOLD%^%^BLUE%^ makes contact "+
    "with "+targ->QCN+"%^BOLD%^%^BLUE%^'s "+limb+
    " and "+targ->QS+" falls to the ground!%^RESET%^", targ);
	
    targ->cause_typed_damage(targ, limb, roll_dice(2,4),"bludgeoning");
    targ->set_tripped(1);
    return;
}