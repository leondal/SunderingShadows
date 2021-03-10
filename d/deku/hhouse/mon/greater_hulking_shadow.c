#include <std.h>
#include "../inherits/area_stuff.h"

inherit MONSTER;
int is_voided;

void shadow_me(object targ)
{
    object ob;
    if(!objectp(targ)) return;

    set_short("%^BOLD%^%^BLACK%^Monstrous hulking shadow of "+targ->getWholeDescriptivePhrase() + "%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This monstrous being is the shadowly outline of "+
    targ->query_description()+"%^BOLD%^%^BLACK%^.%^RESET%^");
    set_overall_ac((int)targ->query_ac() - 10);
    set_hp(((int)targ->query_max_hp() * 10));

    set_size(targ->query_size());

    set_gender(targ->query_gender());
    ob = new(HHOB+"blackthornscythe");
    //ob->set_property("enchantment", 2);
    ob->move(TO);
    command("wield scythe");
    set_stats("strength", 20);
    set_stats("intelligence", 8);
    set_stats("wisdom", 8);
    set_stats("dexterity", 17);
    set_stats("charisma", 8);
    set_stats("constitution", 8);
}


void create()
{
    ::create();
    set_name("monstrous hulking shadow");
    set_id(({"shadow", "Shadow", "hulking shadow", "hhouseshadow"}) );
    set_short("%^BOLD%^%^BLACK%^monstrous hulking shadow%^RESET%^");
    set_race("undead");
    set_long("%^BOLD%^%^BLACK%^This monstrous hulking shadow "+
    "lumbers perhaps eight feet tall. Its eyes are a "+
    "%^RESET%^%^RED%^dull red%^BOLD%^%^BLACK%^ and "+
    "it wavers in and out of existence, as if it is "+
    "has no actual form of its own.%^RESET%^");

    set_gender("female");
    set_level(32);
  	set_alignment(9);
    set_hd(32,1);
    set_body_type("human");
    set_overall_ac(-18);
    set_class("fighter");
    set_size(2);
    set_stats("strength", 20);
    set_property("undead",1);
    set_property("swarm",1);
    set_property("no death",1);
    set_property("full attacks",1);
    set_property("no paralyze",1);

    set("aggressive",26);

    set_func_chance(55);
    set_new_exp(32, "boss");
    set_hp(random(15)+40);
    set_monster_feats(({
        "parry",
        "scramble",
        "stab",
    }));
    set_funcs(({"shadowvoid", "dark_bolt"}));
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(is_voided && random(2))
    {
        if((int)TO->query_hp() < (int)TO->query_max_hp())
        {
            tell_room(ETO, TO->query_short() + " %^BOLD%^%^BLACK%^"+
            "draws forth energy from the %^BOLD%^%^WHITE%^S%^BOLD%^%^BLACK%^"+
            "H%^BOLD%^%^WHITE%^A%^BOLD%^%^BLACK%^D%^BOLD%^%^WHITE%^O"+
            "%^BOLD%^%^BLACK%^W plane to heal itself!%^RESET%^");
            TO->set_hp((int)TO->query_hp() + 50 + random(100));
        }
	}
	return;
}

void dark_bolt(object targ)
{
    string me;
    int dam;
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();

    tell_object(targ, me+" %^BOLD%^%^BLACK%^launches a %^BOLD%^%^YELLOW%^BOLT"+
    "%^BOLD%^%^BLACK%^ of pure darkness at you!%^RESET%^");

    tell_room(ETO, me+"%^BOLD%^%^BLACK%^ launches a %^BOLD%^%^YELLOW%^BOLT"+
    "%^BOLD%^%^BLACK%^ of pure darkness at "+targ->QCN+
    "%^BOLD%^%^BLACK%^!%^RESET%^", targ);

    dam = roll_dice(14, 12);

    if(targ->reflex_save(30))
	{
        tell_object(targ, "%^BOLD%^%^WHITE%^You are able to move just in "+
        "time and the bolt only %^BOLD%^%^RED%^GRAZES%^BOLD%^%^WHITE%^ "+
        "you!%^RESET%^");

        tell_room(ETO, targ->QCN+"%^BOLD%^%^WHITE%^ is able to move just in "+
        "time and the bolt only %^BOLD%^%^RED%^GRAZES%^BOLD%^%^WHITE%^ "+
        targ->QO+"!%^RESET%^", targ);

        targ->cause_typed_damage(targ, targ->return_target_limb(), (dam/2), "cold");
    }
    else
    {
        tell_object(targ, "%^BOLD%^%^BLACK%^You are unable to move "+
        "in time and the bolt %^BOLD%^%^RED%^SLAMS%^BOLD%^%^BLACK%^ "+
        "into you!%^RESET%^");

        tell_room(ETO, targ->QCN+"%^BOLD%^%^BLACK%^ is unable to move "+
        "in time and the bolt %^BOLD%^%^RED%^SLAMS%^BOLD%^%^BLACK%^ "+
        "into "+targ->QO+"!%^RESET%^", targ);

        targ->cause_typed_damage(targ, targ->return_target_limb(), dam, "cold");
    }
    return;
}

void complete_void()
{
    int x;
    string me;
    object *vics;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    vics = all_living(ETO);
    vics -= ({TO});
    is_voided = 0;

    TO->remove_property("damage resistance");

    tell_room(ETO, "%^BOLD%^%^BLACK%^The %^BOLD%^%^RED%^"+
    "VOID%^BOLD%^%^BLACK%^ of dark energy suddenly "+
    "and %^BOLD%^%^BLACK%^V%^BOLD%^%^WHITE%^I%^BOLD%^%^BLACK%^"+
    "O%^BOLD%^%^WHITE%^L%^BOLD%^%^BLACK%^E%^BOLD%^%^WHITE%^N"+
    "%^BOLD%^%^BLACK%^T%^BOLD%^%^WHITE%^L%^BOLD%^%^BLACK%^Y "+
    "%^BOLD%^%^RED%^EXPLODES%^BOLD%^%^BLACK%^ and a shockwave "+
    "of energy erupts rapidly out from it!%^RESET%^");

    for(x = 0; x < sizeof(vics);x++)
    {
        if(vics[x]->query_true_invis()) continue;
        if(strsrch(base_name(vics[x]), HHMON) != -1) continue;
        if(vics[x]->will_save(45))
        {
            tell_object(vics[x], "%^BOLD%^%^CYAN%^You are able "+
            "to shake off most of the effects of the "+
            "%^BOLD%^%^BLACK%^shockwave%^BOLD%^%^CYAN%^ but "+
            "your body suddenly aches all over!%^RESET%^");

            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^CYAN%^ seems to "+
            "shrug off most of the effects of the "+
            "%^BOLD%^%^BLACK%^SHOCKWAVE%^BOLD%^%^CYAN%^!%^RESET%^", vics[x]);
            vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), roll_dice(8,10), "negative energy");
            continue;
        }
        else
        {
            tell_object(vics[x], "%^BOLD%^%^RED%^You are thrown "+
            "backwards by the tremendous force of the "+
            "%^BOLD%^%^BLACK%^SHOCKWAVE%^BOLD%^%^RED%^ and "+
            "are left unable to move in agonizing pain!%^RESET%^");

            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^RED%^ is "+
            "thrown backwards by the tremendous force of "+
            "%^BOLD%^%^BLACK%^SHOCKWAVE%^BOLD%^%^RED%^!%^RESET%^", vics[x]);

            vics[x]->set_paralyzed(20, "%^BOLD%^%^RED%^You are recovering from the "+
            "%^BOLD%^%^BLACK%^SHOCKWAVE%^BOLD%^%^RED%^!%^RESET%^");

            vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), roll_dice(16,10), "negative energy");
            continue;
        }
        continue;
    }
    return;
}

void shadowvoid(object targ)
{
    string me;
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(is_voided)
    {
        dark_bolt(targ);
        return;
    }
    me = TO->query_short();
    is_voided = 1;
    tell_room(ETO, me +"%^BOLD%^%^GREEN%^ S%^BOLD%^%^YELLOW%^H"+
    "%^BOLD%^%^GREEN%^R%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^E"+
    "%^BOLD%^%^YELLOW%^K%^BOLD%^%^GREEN%^S loudly and "+
    "begins absorbing power from a %^BOLD%^%^RED%^VOID"+
    "%^BOLD%^%^BLACK%^ of %^BOLD%^%^BLACK%^dark"+
    "%^BOLD%^%^GREEN%^ energy!%^RESET%^");

    TO->set_property("damage resistance", 1000);
    call_out("complete_void", 10);
    return 0;
}
