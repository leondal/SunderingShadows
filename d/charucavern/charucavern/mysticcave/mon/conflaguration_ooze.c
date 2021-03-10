#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;
int delay;

void create()
{
    ::create();
    set_name("massive puddle of flame");

    set_id(({"ooze", "puddle", "massive puddle", "conflaguration ooze", "flame puddle",
    "puddle of flame", "chsaidemob9x"}));

    set_short("%^BOLD%^%^RED%^massive p%^BOLD%^%^YELLOW%^u%^BOLD%^%^RED%^ddl%^BOLD%^%^YELLOW%^"+
    "e%^BOLD%^%^RED%^ of fl%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^e%^RESET%^");

    set_long("%^BOLD%^%^RED%^This massive creature is approximately eight feet in diameter and "+
    "several feet thick. It is composed of a thick, almost leatherly membrane, that has split "+
    "open in several places, allowing a fiery liquid to splash out in its wake. Within the "+
    "membrane you can see roaring, uncontrollable fl%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^m"+
    "%^BOLD%^%^YELLOW%^e%^BOLD%^%^RED%^. It has no appendages or no visible mouth but somehow "+
    "manages to drag its massive fiery bulk. The very fact that the creature is not overwhelmed "+
    "by the roaring inferno within it suggests that a powerful magic was involved with its "+
    "creation.%^RESET%^");

    set_hd(17,2);
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
    set_funcs(({"hold", "grip"}));
    set_resistance("bludgeoning", 10);
    //set_invis();
    set_hit_funcs((["mass" : (:TO, "flame_em":)]));
    set_moving(1);
    set_speed(55);
    set_nogo(({OE}));
    delay = 3;
}

int flame_em(object targ)
{
    if(!objectp(targ)) return roll_dice(3,6);
    tell_object(targ, TO->QCN+"%^BOLD%^%^RED%^ splashes fiery slime on you!%^RESET%^");
    tell_room(ETO, TO->QCN+"%^BOLD%^%^RED%^ splashes fiery slime on "+targ->QCN+
    "%^BOLD%^%^RED%^!%^RESET%^", targ);
    targ->cause_typed_damage(targ, 0, roll_dice(3,6), "fire");
}

void grip(object vic)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(vic)) return;

    tell_object(vic, TOQCN+"%^BOLD%^%^RED%^ suddenly lurches toward you!%^RESET%^");

    tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ suddenly lurches toward "+vic->QCN+
    "%^BOLD%^%^RED%^!%^RESET%^", vic);

    if(vic->reflex_save(25))
    {
        tell_object(vic, "%^BOLD%^%^WHITE%^You easily move out of the way of "+TOQCN+
        "%^BOLD%^%^WHITE%^!%^RESET%^");

        tell_room(ETO, vic->QCN+"%^BOLD%^%^WHITE%^ easily moves out of the way of "+TOQCN+
        "%^BOLD%^%^WHITE%^!%^RESET%^", vic);
        return;
    }

    tell_object(vic, "%^BOLD%^%^RED%^You are engulfed by "+TOQCN+"%^BOLD%^%^RED%^, "+
    "pinned down by its incredible bulk, as an %^BOLD%^%^YELLOW%^fiery slime%^BOLD%^"+
    "%^RED%^ eats into your flesh!%^RESET%^");

    tell_room(ETO, vic->QCN+"%^BOLD%^%^RED%^ is engulfed by "+TOQCN+"%^BOLD%^%^RED%^, "+
    "pinned down by its incredible bulk!%^RESET%^", vic);

    vic->cause_typed_damage(vic, 0, roll_dice(12,6), "fire");

    vic->set_paralyzed(2 + random(2), "%^BOLD%^%^RED%^You struggle to free yourself "+
    "from "+TOQCN+"%^BOLD%^%^RED%^'s incredible bulk!%^RESET%^");
    return;
}

void hold(object vic)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(vic)) return;

    tell_room(ETO, TOQCN+"%^BOLD%^%^BLUE%^ emits numerous gutteral groans while focusing on "+
    vic->QCN+"%^BOLD%^%^BLUE%^!%^RESET%^", vic);

    tell_object(vic, TOQCN+"%^BOLD%^%^BLUE%^ emits numerous gutteral groans while focusing on "+
    "you!%^RESET%^");

    if(interactive(vic)) new("/cmds/spells/h/_hold_person")->use_spell(TO,vic, 18, 100, "mage");
    else new("/cmds/spells/h/_hold_monster")->use_spell(TO, vic, 18, 100, "cleric");
    return;
}

void die(object ob)
{
    object *vics;
    int x;
    if(random(2)) return ::die(ob);
    tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ E%^BOLD%^%^YELLOW%^X%^BOLD%^%^RED%^P%^BOLD%^%^YELLOW%^"+
    "L%^BOLD%^%^RED%^O%^BOLD%^%^YELLOW%^D%^BOLD%^%^RED%^E%^BOLD%^%^YELLOW%^S%^BOLD%^%^RED%^ into "+
    "massive chunks of flaming goo!%^RESET%^");
    vics = TO->query_attackers();
    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x])) continue;
        if(vics[x]->reflex_save(17))
        {
            tell_object(vics[x], "%^BOLD%^%^RED%^You are able to move out of the way of most of "+
            "the flaming chunks of goo but are pelted by a few of them!%^RESET%^");
            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^RED%^ manages to move out of the way of most of "+
            "the flaming chunks of goo but is pelted by a few of them!%^RESET%^", vics[x]);
            vics[x]->cause_typed_damage(vics[x], 0, roll_dice(8,6)/2, "bludgeoning");
            vics[x]->cause_typed_damage(vics[x], 0, roll_dice(4,6)/2, "fire");
            continue;
        }
        tell_object(vics[x], "%^BOLD%^%^RED%^You are unable to move out of the way in time and "+
        "are pelted by numerous chunks of flaming goo!%^RESET%^");
        tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^RED%^ is unable to move out of the way in time and "+
        "is pelted by numerous chunks of flaming goo!%^RESET%^", vics[x]);
        POISON_D->ApplyPoison(vics[x], CROB+"fiery_toxin", TO, "contact");
        vics[x]->cause_typed_damage(vics[x], 0, roll_dice(8,6), "bludgeoning");
        vics[x]->cause_typed_damage(vics[x], 0, roll_dice(4,6), "fire");
        continue;
    }

    return ::die(ob);
}

void heart_beat()
{
    string me;
    object *myEnemies;
    int x;
    if(!objectp(TO)) return;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(delay > 0)
    {
        delay--;
        return;
    }
    if(delay <= 0) delay = 3;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
	
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
