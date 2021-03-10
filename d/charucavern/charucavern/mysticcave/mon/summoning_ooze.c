#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;
int can_split, delay;

void adjust_hd()
{
    set_hd(10 + random(6),2);
    set_hp(175 + random(55));
    set_max_hp(query_hp());
}

void create()
{
    ::create();
    set_name("gelatinous transparent mass");

    set_id(({"ooze", "mass", "transparent mass", "gelatinous mass", "gelatinous transparent mass", "chsaidemob9x"}));

    set_short("%^RESET%^%^ORANGE%^gelatinous transparent m%^BOLD%^%^RED%^a%^RESET%^%^ORANGE%^"+
    "ss%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This massive creature is perhaps four feet in diameter and two feet "+
    "thick. Its body is composed of an almost entirely transparent gelatinous substance. There are bizarre "+
    "%^BOLD%^%^CYAN%^magical symbols%^RESET%^%^ORANGE%^ floating within its interior protoplasm. The "+
    "%^BOLD%^%^CYAN%^symbols%^RESET%^%^ORANGE%^ are pulsating slowly and erratically as they appear "+
    "to be moving about constantly in an almost circular pattern. This "+
    "strange creature has no visible appendages or mouth but somehow manages to drag its "+
    "massive bulk, leaving a trail of acidic slime in its wake.%^RESET%^");

    set_hd(18,2);
    set_hp(175 + random(35));
    set_max_hp(query_hp());
    set_body_type("ooze");
    set_damage(3,4);
    set_attacks_num(2);
    set_attack_limbs(({"mass"}));
    set_base_damage_type("bludgeoning");
    set_gender("neuter");
    set_race("ooze");
    set_new_exp(18, "normal");
    set_alignment(5);
    set_overall_ac(-2);
    set("aggressive", 30);
    set_property("full attacks", 1);
    set_func_chance(35);
    set_stats("strength", 18);
    set_stats("intelligence", 1);
    set_stats("wisdom", 1);
    set_stats("constitution", 18);
    set_stats("dexterity", 12);
    set_stats("charisma", 6);
    set_funcs(({"summon"}));

    set_resistance_percent("acid", 200);
    set_resistance_percent("cold", -100);
    set_resistance("bludgeoning", 10);
    set_hit_funcs((["mass" : (:TO, "acid_splash":)]));
    can_split = random(2);
    set_moving(1);
    set_speed(55);
    set_nogo(({OE}));
    delay = 3;
}

int acid_splash(object targ)
{
    if(!objectp(targ)) return roll_dice(3,6);
    tell_object(targ, TO->QCN+"%^BOLD%^%^GREEN%^ splashes acidic slime on you!%^RESET%^");
    tell_room(ETO, TO->QCN+"%^BOLD%^%^GREEN%^ splashes acidic slime on "+targ->QCN+
    "%^BOLD%^%^GREEN%^!%^RESET%^", targ);
    targ->cause_typed_damage(targ, 0, roll_dice(3,4), "acid");
}


void summon(object vic)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    tell_room(ETO, TOQCN+"%^BOLD%^%^BLACK%^ emits numerous gutteral groans and the "+
    "%^BOLD%^%^CYAN%^arcane symbols%^BOLD%^%^BLACK%^ within it flash with an eerie "+
    "%^BOLD%^%^YELLOW%^golden light%^BOLD%^%^BLACK%^!%^RESET%^");

    new("/cmds/spells/m/_monster_summoning_vi")->use_spell(TO,0, 18, 100, "mage");
    return;
}

void test() { return CRTRES; }

void die(object ob)
{
    object myOb;
    int flag;
    TO->set_property("dying", 1);
    if(!random(15))
    {
        myOb = test()->find_stuff();
        myOb->move(TO);
        flag = 1;
    }
    if(!random(24))
    {
        myOb = test()->find_stuff();
        myOb->move(TO);
        flag = 1;
    }
    if(!random(30))
    {
        myOb = test()->find_stuff();
        myOb->move(TO);
        flag = 1;
    }
    if(objectp(ETO) && flag)
    {
        tell_room(ETO, "%^BOLD%^%^RED%^You notice something inside %^RESET%^"+
        "%^ORANGE%^gelatinous mass%^BOLD%^%^RED%^"+
        "%^BOLD%^%^RED%^ as "+TOQCN+" collapses into a heap!%^RESET%^");
    }
    return ::die(ob);
}



void heart_beat()
{
    string me;
    object *myEnemies, mon;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(TO->query_property("dying")) return;
    if(query_hp() < (query_max_hp()/2) && !random(3) && query_hp() > 15 && can_split)
    {
        tell_room(ETO, TOQCN+"%^RESET%^%^ORANGE%^ emits a %^BOLD%^%^GREEN%^sickening "+
        "%^RESET%^%^ORANGE%^squish sound as it splits itself in two!%^RESET%^");
        mon = new(CRMON+"summoning_ooze");
        mon->adjust_hd();
        mon->move(ETO);
        can_split = 0;
        return;
    }    
    if(delay > 0)
    {
        delay--;
        return;
    }
    if(delay <= 0) delay = 3;
    myEnemies = all_living(ETO);
    me = TO->query_short();
    for(x = 0; x < sizeof(myEnemies);x++)
    {
        if(!objectp(myEnemies[x])) continue;
        if(!myEnemies[x]->id("chsaideoozefood")) continue;
        tell_room(ETO, me +"%^BOLD%^%^BLACK%^ encompasses "+myEnemies[x]->query_short() +
        " and quickly devours "+myEnemies[x]->QO+" adding to its own mass!%^RESET%^");
        myEnemies[x]->move("/d/shadowgate/void");
        myEnemies[x]->remove();
        set_max_hp(query_max_hp() + 10);
        set_hp(query_hp() + 10);
        break;
    }
    return;   
}
