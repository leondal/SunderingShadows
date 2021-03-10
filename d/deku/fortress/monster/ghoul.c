#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit WEAPONLESS;

void create() 
{
    ::create();
    set_name("ghoul");
    set_id(({"ghoul","man","disfigured man"}));
    set_gender("male");
    set_race("ghoul");
    set_short("A horribly disfigured man");
    set_long("%^BLUE%^This creature was once a human man, "+
    "however, that time is now gone.  The flesh of this "+
    "creature ranges from a sickly gray to a puss green color "+
    "and it has cracked and split open in many places.  "+
    "Most of this creatures hair has fallen out and what "+
    "remains is a stringy, grime laden black.  The mouth of "+
    "this creature is lined with rows of teeth that appear "+
    "razor sharp and have grown abnormally long, forcing "+
    "its mouth to remain constantly open in a grotesque, "+
    "abnormal manner.  The hands of this creature were once "+
    "normal, but they have changed, they now end in long "+
    "sharpened claws that are crusted with dirt and gore.  "+
    "However, the most freightening thing about this "+
    "creature is its eyes, they not only burn with hatred, "+
    "but they glance around constantly with careful "+
    "observation, revealing this creature as not a "+
    "mindless undead, but as an intelligent being.%^RESET%^");
    set_body_type("human");
    set_alignment(9);
    set_hd(24,2);
    set_stats("strength",20);
    set_stats("constitution",16);
    set_stats("wisdom",13);
    set_stats("intelligence",13);
    set_stats("dexterity",12);
    set_stats("charisma",12);
    set("aggressive","agg_func");
    set_overall_ac(0);
    set_property("undead",1);
    set_property("weapon resistance",1);
    set_hp(570 + random(20));
    set_new_exp(20, "normal");
    set_damage(3,8);
    set_attacks_num(2);
    set_base_damage_type("piercing");
    set_funcs(({"attacks"}));
    set_func_chance(100);
    set_speed(10 + random(11));
    set_moving(1);
    set_nogo(({NO,NO2,NO3,NO4,NO5,NO6,NO7}));
}

void attacks(object targ) 
{
    int x, need, tac, roll, hits;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    command("kill "+targ->query_name());
    for(x = 0;x < 2;x++) 
    {
        roll = roll_dice(1,20);
        need = "/daemon/bonus_d.c"->thaco(TO->query_level(), "fighter");
        tac = targ->query_ac();
        if(roll > (need - tac) || roll == 20) 
        {
            tell_room(ETO,"%^YELLOW%^The man sinks his %^MAGENTA%^dirty claws%^YELLOW%^ deep into "+targ->QCN+"%^YELLOW%^'s flesh!%^RESET%^",({targ,TO}));
            tell_object(targ,"%^YELLOW%^The man sinks his %^MAGENTA%^dirty claws%^YELLOW%^ deep into your flesh!%^RESET%^");
            targ->do_damage(targ->return_target_limb(),roll_dice(3,12));
            hits++;
            continue;
        }
        tell_object(targ,"%^YELLOW%^The man swings his dirty claws "+
        "at you but can't find an opening!%^RESET%^");
        tell_room(ETO,"%^YELLOW%^The man swings his dirty claws "+
        "at "+targ->QCN+" but can't find an opening!%^RESET%^",targ);
        continue;
    }
    if(hits == 2) 
    {
        tell_room(ETO,"%^BLUE%^The man grabs "+targ->QCN+"%^BLUE%^ with his claws and bites "+targ->QO+"%^BLUE%^ in the face!%^RESET%^",({targ,TO}));
        tell_object(targ,"%^BLUE%^The man grabs you with his claws and bites you in the face!%^RESET%^");
        targ->do_damage("head",roll_dice(6,6));
        if(!targ->fort_save(25)) 
        { 
            tell_object(targ,"%^RED%^The touch of the old man causes your body to become rigid!%^RESET%^");
            targ->set_paralyzed(roll_dice(3,6),"%^RED%^Your body will not respond!%^RESET%^");
        }
    }
}

void agg_func() 
{
    if(!objectp(TP)) return;
    if(TP->query_invis()) return;
    attacks(TP);
}
