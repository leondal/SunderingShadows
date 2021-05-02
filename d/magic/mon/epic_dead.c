#include <magic.h>
#include "summoned_monster.h"

inherit WEAPONLESS;

object cast;

void create(){
  ::create();

    set_name("exalted dead");
    set_id(({"dead","exalted dead","a mighty ghostly warrior","warrior","ghostly warrior", "exalted_dead"}));
    set_short("%^RESET%^%^BOLD%^A %^RESET%^m%^BOLD%^ig%^RESET%^h%^BOLD%^ty g%^RESET%^h%^BOLD%^ost%^RESET%^l%^BOLD%^y wa%^RESET%^r%^BOLD%^ri%^RESET%^o%^BOLD%^r%^RESET%^%^BOLD%^%^RED%^");
    set_long("%^BOLD%^Once a %^BLACK%^fierce %^WHITE%^warrior, this ghostly, %^CYAN%^translucent figure %^WHITE%^still rises to the aid of those in need during troubling times. His white eyes shine with %^BLACK%^grim determination %^WHITE%^as he grips tightly to a sword. Even in death he is a strong and proud man, ready to cut down his enemies and to defend the life of his living allies.%^RESET%^");
    set_hd(4,1);
    set_hp(query_hd()*8);
    set_class("fighter");
    set_stats("strength",20);
    set_stats("intelligence",8);
    set_stats("wisdom",20);
    set_stats("dexterity",20);
    set_race("human");
    set_damage(2,10);
    set_attacks_num(5);
    set_base_damage_type("slashing");
    set_gender("other");
    set_overall_ac(4);

    set_property("full attacks",1);
    set_monster_feats(({
                "simple weapon proficiency",
                "opportunity strikes",
                    "swipe",
            }));

    set_alignment(5);

    command("message walks in");
    command("message walks $D");
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
    set_max_hp(clevel*10+100);
    set_hp(query_max_hp());
    set_overall_ac(4-clevel);
    set_attacks_num(clevel/14+2);

    {
        string deity = caster->query_diety();
        string normalizedDeity;
        object wpn;
        int ench;

        normalizedDeity = replace_string(deity," ","_");
        if(deity == "godless" || deity == "callamir")
            normalizedDeity = "kismet";

        wpn=new("/d/magic/obj/weapons/"+normalizedDeity+"");
        ench = clevel/7;
        if(ench < 0)
            ench = 0;
        if(ench > 9)
            ench = 9;
        wpn->set_property("enchantment",ench);
        wpn->move(TO);
        wpn->set_property("monster weapon",1);
        TO->force_me("wield weapon in left hand");
    }

    call_out("protect",ROUND_LENGTH);
}

void protect()
{
    object *foes, foe;

    if(!objectp(cast))
        return;

    call_out("protect",ROUND_LENGTH);
    foes=cast->query_attackers();
    
    if(environment(this_object()) != environment(cast))
    {
        remove();
        return;
    }

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
