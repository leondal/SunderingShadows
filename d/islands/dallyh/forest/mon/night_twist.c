#include <std.h>
inherit WEAPONLESS;

void create()
{
    object myob;
    ::create();
    set_name("large black leafless tree");
    set_id(({"tree", "leafless tree", "night twist", "dallyhallyevil"}));
    set_short("%^BOLD%^%^BLACK%^large black leafless tree%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^At first glance this appears to be nothing more "+
    "than a large black leafless tree, which seems strangely out of place in "+
    "this forest. You quickly realize, however, that this is a living creature, one "+
    "directly from out of a nightmare. This creature towers nearly thirty feet tall and "+
    "has dozens of withered branches which flay about wildly. Its very shape is quite "+
    "unnatural and it bends and twists in ways which no normal tree would. There is a darkness "+
    "and despair radiating outward from it so powerful that it is literally tangible. "+
    "Just gazing at this creature makes you question your very existence and a "+
    "horrible despair begins to grip soul.%^RESET%^");

    set_gender("neuter");

    set_level(30);
    set_hd(25, 2);
    set_class("cleric");
    set_guild_level("cleric", 25);
    set_new_exp(28, "high");
    set_mlevel("cleric", 25);
    set_alignment(9);
    set_size(4);
    set_overall_ac(-5);
    set_hp(600 + random(601));

    set_body_type("tree");
    set_race("night twist");
    add_limb("trunk", 0, 0, 0, 0);
    add_limb("right withered branch", "trunk", 0, 0, 0);
    add_limb("left withered branch", "trunk", 0, 0, 0);
    set_attack_limbs(({"right withered branch", "left withered branch"}));

    set_num_attacks(4);
    set_damage(4,4);
    set_base_damage_type("bludgeoning");

    set_stats("strength", 20);
    set_stats("dexterity", 6);
    set_stats("intelligence", 12);
    set_stats("wisdom", 14);
    set_stats("charisma", 21);
    set_stats("constitution", 25);
    set_mob_magic_resistance("none");

    set_resistance("slashing", 15);
    set_resistance_percent("fire", -100);

    set("aggressive", 30);

    set_spells(({"phantasmal killer", "fear", "entangle", "darkness"}));
    set_spell_chance(35);

    set_funcs(({"wind_blast"}));
    set_func_chance(15);

    set_property("full attacks",1);

    {
        object obj;
        obj = new("/d/common/obj/brewing/herb_special_inherit");
        obj->set_herb_name("nycissa orchid");
        obj->move(TO);
    }

    add_money("gold",1200 + random(801));
}

void wind_blast(object targ)
{
    object *vics;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    vics = all_living(ETO);
    vics -= ({TO});
    tell_room(ETO, "%^BOLD%^%^CYAN%^A powerful, violent, and unabating wind suddenly "+
    "emanates outward from "+TOQCN+"!%^RESET%^");

    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x])) continue;
        if(vics[x]->id("dallyhallyevil")) continue;
        if(vics[x]->query_true_invis()) continue;
        if(vics[x]->fort_save(12))
        {
            tell_object(vics[x], "%^BOLD%^%^WHITE%^Amazingly you are able to remain "+
            "standing but the %^BOLD%^%^RED%^violent%^BOLD%^"+
            "%^WHITE%^ wind rips at your flesh!%^RESET%^");

            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^WHITE%^ is amazingly able to remain "+
            "standing but the %^BOLD%^%^RED%^violent%^BOLD%^%^WHITE%^"+
            " wind rips at "+vics[x]->QP+" flesh!%^RESET%^", vics[x]);

            vics[x]->cause_typed_damage(vics[x], 0, roll_dice(20,6)/2, "cold");
            continue;
        }
        tell_object(vics[x], "%^BOLD%^%^BLACK%^You are thrown to the ground by the "+
        "violent and unabating wind, as it rips at your flesh!%^RESET%^");
        tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^BLACK%^ is thrown to the ground by "+
        "the violent and unabating wind as it rips at "+vics[x]->QP+
        " flesh!%^RESET%^", vics[x]);

        vics[x]->cause_typed_damage(vics[x], 0, roll_dice(20, 6), "cold");
        vics[x]->set_paralyzed(25, "%^BOLD%^%^CYAN%^You struggle to stand under the "+
        "pressure from the violent wind!%^RESET%^");
        continue;
    }
    tell_room(ETO, "%^BOLD%^%^CYAN%^The powerful and violent wind emanating "+
    "from "+TOQCN+" suddenly dies down!%^RESET%^");
    return;
}
