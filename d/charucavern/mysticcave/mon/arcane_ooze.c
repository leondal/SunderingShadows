#include <std.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

mixed forget_string;
int delay;

void create()
{
    ::create();
    set_name("mass of green protoplasm");

    set_id(({"ooze", "mass", "arcane ooze", "mass of protoplasm", "green mass", "chsaidemob9x"}));

    set_short("%^BOLD%^%^GREEN%^mass of gr%^RESET%^%^GREEN%^ee%^BOLD%^n pr%^RESET%^"+
    "%^GREEN%^o%^BOLD%^t%^RESET%^%^GREEN%^o%^BOLD%^pl%^RESET%^%^GREEN%^a%^BOLD%^"+
    "sm%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This monstrous mass of protoplasm is perhaps eight feet in "+
    "diameter and three feet thick. Its insides are bulging and pulsing with thick "+
    "veins which give off a %^BOLD%^%^WHITE%^weird%^BOLD%^%^GREEN%^ fluoresent light "+
    "which highlights the other globs of material situated throughout the mass. "+
    "It has no visible appendages or mouth but its body is outlined by a "+
    "%^RESET%^%^GREEN%^much darker green%^BOLD%^%^GREEN%^. It somehow "+
    "manages to drag its massive bulk and leaves in its wake an "+
    "acidic slime.%^RESET%^");

    set_hd(18,2);
    set_hp(175 + random(35));
    set_max_hp(query_hp());
    set_body_type("ooze");
    set_damage(2,5);
    set_attacks_num(3);
    set_attack_limbs(({"mass"}));
    set_base_damage_type("bludgeoning");
    set_gender("neuter");
    set_race("ooze");
    set_new_exp(18, "normal");
    set_alignment(5);
    set_overall_ac(-2);
    set("aggressive", 30);
    set_stats("strength", 18);
    set_stats("intelligence", 1);
    set_stats("wisdom", 1);
    set_stats("constitution", 18);
    set_stats("dexterity", 12);
    set_stats("charisma", 6);
    set_property("full attacks", 1);
    set_func_chance(35);
    set_funcs(({"absorb", "grip"}));
    set_resistance("acid", 1500);
    set_resistance("bludgeoning", 10);
    set_resistance("cold", -100);
    set_hit_funcs((["mass" : (:TO, "acid_splash":)]));
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
    targ->cause_typed_damage(targ, 0, roll_dice(3,6), "acid");
}

void forget_random(object vic)
{
    string *classes, myclass, spell, *spells;
    int x, max = 0, y;
    mapping tmp=([]);
    int *lvls;

    forget_string = 0;
    if(!objectp(vic)) return;
    classes = vic->query_classes();

    for(x = 0;x< sizeof(classes);x++)
    {
       tmp = vic->query_all_memorized(classes[x]);
       lvls = keys(tmp);
       if(!sizeof(lvls)) continue;
       for(y = 0;y < sizeof(lvls);y++)
       {
           spells = keys(tmp[lvls[y]]);
           if(!sizeof(spells)) continue;
           if(max < lvls[y])
           {
               max = lvls[y];
               myclass = classes[x];
               spell = spells[random(sizeof(spells))];
               continue;
           }
           continue;
        }
     }
     if(max && stringp(spell))
     {
         if(spell == "generic")
         {
             vic->forget_memorized(myclass, "level "+max);
             forget_string = "%^BOLD%^%^CYAN%^The knowledge of your preparation of one of your level "+max+" spells suddenly "+
             "slips your mind!%^RESET%^";
         }
         else
         {
             vic->forget_memorized(myclass, spell);
             forget_string = "%^BOLD%^%^CYAN%^The knowledge of your preparation of "+spell+" suddenly slips your "+
             "mind!%^RESET%^";
         }
     }
     //tell_object(vic, forget_string);
     return;
}

void absorb(object vic)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(vic)) return;

	tell_object(vic, TO->QCN+"%^BOLD%^%^BLACK%^ turns toward you and you feel a strange sensation "+
    "pulling at your mind!%^RESET%^");
    tell_room(ETO, TO->QCN+"%^BOLD%^%^BLACK%^ turns toward "+vic->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^", vic);

	if(vic->fort_save(25))
	{
		tell_object(vic, "%^BOLD%^%^WHITE%^The sensation passes and you are left unfazed!%^RESET%^");
        tell_room(ETO, vic->QCN+"%^BOLD%^%^WHITE%^ looks unfazed!%^RESET%^", vic);
		return;
	}
	else
	{
		forget_random(vic);
        if(!forget_string)
        {
            tell_object(vic, "%^BOLD%^%^WHITE%^The sensation passes and you are left unfazed!%^RESET%^");
            tell_room(ETO, vic->QCN+"%^BOLD%^%^WHITE%^ looks unfazed!%^RESET%^", vic);
            return;
        }
        tell_object(vic, "%^BOLD%^%^RED%^You feel a strange force pull something from your mind!%^RESET%^");
        tell_object(vic, forget_string);

        tell_room(ETO, vic->QCN+"%^BOLD%^%^RED%^ suddenly looks confused!%^RESET%^", vic);
        return;
	}
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
    "pinned down by its incredible bulk, as an %^BOLD%^%^GREEN%^acidic slime%^BOLD%^"+
    "%^RED%^ eats into your flesh!%^RESET%^");

    tell_room(ETO, vic->QCN+"%^BOLD%^%^RED%^ is engulfed by "+TOQCN+"%^BOLD%^%^RED%^, "+
    "pinned down by its incredible bulk!%^RESET%^", vic);

    vic->cause_typed_damage(vic, 0, roll_dice(12,6), "acid");

    vic->set_paralyzed(2 + random(4), "%^BOLD%^%^GREEN%^You struggle to free yourself "+
    "from "+TOQCN+"%^BOLD%^%^GREEN%^'s incredible bulk!%^RESET%^");
    return;
}

int cause_typed_damage(object targ, string limb, int damage, string type)
{
    if(targ != TO || !objectp(targ)) return ::cause_typed_damage(targ, limb, damage, type);
    if(type == "electricity")
    {
        tell_room(ETO, TO->QCN + "%^BOLD%^%^GREEN%^'s veins pulse and throb quicker still as "+
        "the electricity seems to undulate throughout its body!%^RESET%^");
        new("/cmds/spells/b/_blink")->use_spell(TO, TO, 20, 100, "mage");
    }
    return ::cause_typed_damage(targ, limb, damage, type);
}

void test() { return CRTRES; }

void die(object ob)
{
    object myOb;
    int flag;
    if(!random(10))
    {
        myOb = test()->find_stuff();
        myOb->move(TO);
        flag = 1;
    }
    if(!random(15))
    {
        myOb = test()->find_stuff();
        myOb->move(TO);
        flag = 1;
    }
    if(!random(20))
    {
        myOb = test()->find_stuff();
        myOb->move(TO);
        flag = 1;
    }
    if(objectp(ETO) && flag)
    {
        tell_room(ETO, "%^BOLD%^%^RED%^You notice something inside the mass of %^BOLD%^%^GREEN%^protoplasm"+
        "%^BOLD%^%^RED%^ as "+TOQCN+" collapses into a heap!%^RESET%^");
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
    if(TO->query_property("dying")) return;
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
