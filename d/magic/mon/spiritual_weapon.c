#include <magic.h>
#include "summoned_monster.h"

inherit WEAPONLESS;

object cast;

void create(){
  ::create();

    set_name("spiritual weapon");
    set_id(({"weapon","spiritual weapon","summoned monster"}));
    set_short("%^CYAN%^a spiritual weapon%^RESET%^");
    set_long("%^CYAN%^Spiritual weapon.%^RESET%^");
    set_hd(4,1);
    set_hp(query_hd()*8);
    set_class("fighter");
    set_stats("strength",20);
    set_stats("intelligence",8);
    set_stats("wisdom",20);
    set_stats("dexterity",20);
    set_race("weapon");
    add_limb("torso","torso",50,0,2);
    set_attack_limbs(({"torso"}));
    set_damage(2,10);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_gender("other");
    set_overall_ac(4);

    set_alignment(5);
    command("speak common");
    command("message floats in.");
    command("message floats $D.");
    set_property("knock unconscious",1);
}

void setup_servant(object caster, int clevel)
{
    int level;
    if(!objectp(caster)) { return; }

    cast = caster;

    level = clevel;

    set_mlevel("fighter",clevel);
    set_guild_level("fighter",clevel);
    set_level(clevel);
    set_hd(clevel,8);
    set_max_hp(clevel*12+100);
    set_hp(query_max_hp());
    set_overall_ac(4-clevel);
    set_attacks_num(clevel/8+2);
    set_property("effective_enchantment",clevel/7);
    call_out("protect",ROUND_LENGTH);
}

void protect()
{
    object *foes, foe;

    if(!objectp(cast))
        return;

    call_out("protect",ROUND_LENGTH);
    foes=cast->query_attackers();

    foreach(foe in foes)
    {
        if(!objectp(foe))
            continue;
        if(!present(foe,ENV(TO)))
            continue;
        TO->kill_ob(foe);
    }
}

void die(object obj)
{
    cast->remove_property("spiritual_weapon");
    TO->remove();
    ::die(obj);
    return;
}
