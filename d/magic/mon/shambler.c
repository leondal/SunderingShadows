#include <magic.h>
#include "summoned_monster.h"

inherit WEAPONLESS;

object cast;

void create(){
  ::create();

    set_name("shambling mound");
    set_id(({"shambler","shamblind mound","mound",}));
    set_short("%^GREEN%^sh%^RESET%^%^ORANGE%^a%^GREEN%^mbl%^RESET%^%^ORANGE%^i%^GREEN%^ng m%^RESET%^%^ORANGE%^ou%^GREEN%^nd%^RESET%^");
    set_long("%^BOLD%^%^GREEN%^This creature appears to be h%^RESET%^%^ORANGE%^ea%^BOLD%^%^GREEN%^ps %^RESET%^%^ORANGE%^o%^BOLD%^%^GREEN%^f r%^RESET%^%^ORANGE%^o%^BOLD%^%^GREEN%^tt%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^ng v%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^g%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^t%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^t%^RESET%^%^ORANGE%^io%^BOLD%^%^GREEN%^n gathered to roughly resemble giant humanoid form. Numerous vines and roots cover its massive and strong body. It walks slowly on its feet, assisting itself with its massive arms. Several fl%^RESET%^%^MAGENTA%^o%^BOLD%^%^GREEN%^w%^RESET%^%^MAGENTA%^e%^BOLD%^%^GREEN%^rs and plants top its head, forming a miniature meadow.%^RESET%^");
    set_hd(4,1);
    set_hp(query_hd()*8);
    set_class("fighter");
    set_stats("strength",24);
    set_stats("constitution",24);
    set_stats("intelligence",8);
    set_stats("wisdom",20);
    set_stats("charisma",10);
    set_stats("dexterity",12);
    set_race("shambler");
    set_damage(2,10);
    set_attacks_num(5);
    set_base_damage_type("bludgeoning");
    set_gender("other");
    set_overall_ac(4);

    set_monster_feats(({
                "toughness",
                "regeneration",
            }));

    set_alignment(5);

    command("message in %^ORANGE%^shambles in");
    command("message out %^ORANGE%^shambles $D");
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
    set_hd(clevel,14);
    set_max_hp(clevel*10+200);
    set_hp(query_max_hp());
    set_overall_ac(-clevel);
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
    cast->remove_property("has_elemental");
    TO->remove();
    ::die(obj);
    return;
}

void heart_beat()
{
    string party;
    int i;
    ::heart_beat();

    if (query_hp_percent() < 70 && present("vial", TO)) {
        for (i = 0; i < 4; i++) {
            command("quaff vial");
        }
    }

    if (query_hp() < query_max_hp()) {
        add_hp(query_max_hp() / 25);
    }
}
