#include <std.h>
#include "../arctic.h"
inherit CREATURE;

int i;
int FLAG = 0;

void create() 
{
   object ob;
    ::create();
    set_name("Winter Wolf");
    set_id(({"wolf", "white wolf", "large white wolf", "arcticmon"}));
    set_race("wolf");
    set_body_type("quadruped");
    set_gender((random(2)?"male":"female"));
    set_size(2);
    set_short("large white wolf");
    set_long("%^RESET%^%^BOLD%^The muscules of this massive "
             "white wolf ripple beneath a beautiful coat of "
             "glistening white fur.  This wolf is perhaps four "
             "times the size of a normal variety, standing over "
             "five feet at the shoulder, and running nearly "
             "twelve feet from the tip of the nose to the end "
             "of the bushy white tail.  Its pale silver eyes "
             "show an intelligence beyond that of an "
             "animal.%^RESET%^");
    set_hd(16,1);
    set_level(16);
    set_class("fighter");
    set_mlevel("fighter", 16);
    set_hp((random(250)+250));
    set_exp(7000);
    set_property("swarm", 1);
    set_overall_ac(-4);
    set_stats("strength",18);
    set_stats("dexterity",12);
    set_stats("intelligence",8);
    set_stats("wisdom",8);
    set_stats("constitution",21);
    set_stats("charisma",5);
    set_attacks_num(3);
    set_damage(3,3);
    set_base_damage_type("piercing");
    add_limb("teeth", "head", 0, 0, 0);
    set_attack_limbs(({"teeth"}));
    set("aggressive", 20);
    set_funcs( ({"wolf_call"}) );
    set_func_chance(30);
    set_speed(30);
    nogo("NOGO1");
    add_money("platinum",random(100));
    if(!random(10)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("breath of winter");
      ob->move(TO);
    }
    set_resistance("cold",15);
    set_resistance("fire",-15);
}


void wolf_call()
{
    object *live;
    object *fodder;
    object targ;

    if(!random(5))
    {
        tell_room(ETO, "%^BOLD%^The large white wolf throws "
        "its head back and howls!%^RESET%^",ETO);
        call_out("howl",10,TO);
        return;
    }

    live = all_inventory(ETO);
    fodder = live;
    fodder = filter_array(fodder, "is_fodder", CREATURE);
    live = filter_array(live, "is_non_immortal_player", FILTERS_D);
    live += fodder;
    // Thanks to Garrett for the help with filter array -Ares

    for(i=0;i<sizeof(live);i++)
    {
        targ = live[i];
        if(!objectp(targ)) continue;

        if(!ROLLSAVE(targ, BW ))
        {
            tell_object(targ,"%^CYAN%^A small cone of frigid air "
                "from the white wolf's mouth slams into you!%^RESET%^");
            tell_room(ETO,"%^CYAN%^"+targ->QCN+" "
                "staggers backwards as a small cone of cold air from "
                "the white wolf's mouth slams into "
                ""+targ->QO+"!%^RESET%^",targ);
            TO->set_property("magic", 1);
            targ->do_damage("torso", roll_dice(8,8));
            TO->set_property("magic", -1);
            continue;            
        }


        tell_object(targ,"%^CYAN%^A small cone of frigid air "
            "from the white wolf's mouth grazes you!%^RESET%^");
        tell_room(ETO,"%^CYAN%^"+targ->QCN+" "
            "is grazed by a small cone of cold air from the mouth "
            "of the white wolf!%^RESET%^",targ);
        TO->set_property("magic", 1);
        targ->do_damage("torso", roll_dice(8,8)/2);
        TO->set_property("magic", -1);

        if(i > 1000) { tell_room(ETO,"loop error wolf_call "
            "in "+MON+"winterwolf.c"); break; } 

    }

}

void howl()
{
    if(!objectp(TO)) return;
    if(FLAG == 1) return;

    switch(random(5))
    {
    case 0..2:
        tell_room(ETO, "%^BOLD%^Howls echo back "
        "from all around the mountains!%^RESET%^");
        break;
    case 3:
        tell_room(ETO, "%^RED%^Several wolves answer "
        "the howl and attack!%^RESET%^");
        for(i=0;i<((random(5)+1));i++)
        {
            new(MON"wolf")->move(ETO);
            if(i > 10) {tell_room(ETO,"loop error howl "
            "in "+MON+"winterwolf.c"); break;} 
        }
        break;
    case 4:
        tell_room(ETO, "%^RED%^Several wolves answer "
        "the howl and attack!%^RESET%^");
        for(i=0;i<((random(10)+1));i++)
        {
            new(MON"wolf")->move(ETO);
            if(i > 20) {tell_room(ETO,"loop error howl "
            "in "+MON+"winterwolf.c"); break;}
        }
        break;
    }

    FLAG = 1;
}
