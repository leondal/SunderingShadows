//eelemental.c

#include "summoned_monster.h"

inherit WEAPONLESS;

object cast;

void create(){
  ::create();

    set_name("earth elemental");
    set_id(({"elemental","earth elemental","eelemental","greater summon"}));
    set_short("%^RESET%^%^ORANGE%^an %^YELLOW%^e%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^t%^YELLOW%^h%^RESET%^%^ORANGE%^ elemental%^RESET%^");
    set_id(({"elemental","earth elemental","ancient earth elemental" }));
    set_long("%^RESET%^%^ORANGE%^This hulking eight-foot tall elemental "
             "looks like a small moving mountain covered in plates of %^BOLD%^%^BLACK%^"
             "sha%^WHITE%^l%^BLACK%^e%^RESET%^%^ORANGE%^ and %^RESET%^q%^CYAN%^u%^BOLD%^"
             "%^WHITE%^a%^RESET%^r%^YELLOW%^t%^BOLD%^%^BLACK%^z %^RESET%^s%^ORANGE%^p"
             "%^BOLD%^%^WHITE%^i%^RESET%^k%^RED%^e%^RESET%^s%^ORANGE%^.  Every movement "
             "of the vaguely humanoid shape is punctuated with the sound of rocks grinding, "
             "and its powerful arms look as though they could crush any foe despite the "
             "elemental's relatively small size.  Although it has no "
             "visible eyes, this creature seems to have no trouble seeking out its enemies.%^RESET%^");
    set_hd(4 + (4 *(random(3)+1)),1);
    set_hp(query_hd()*8);
    set_exp((query_hd()-6)* 1000);
    set_stats("strength",18);
    set_stats("intelligence",7);
    set_stats("dexterity",4);
    set_race("elemental");
    add_limb("torso","torso",50,0,2);
    add_limb("right appendage","torso",50,0,2);
    add_limb("left appendage","torso",50,0,2);
    add_limb("base","torso",50,0,2);
    set_attack_limbs(({"left appendage", "right appendage"}));
    set_damage(4,8);
    set_attacks_num(1);
    set_base_damage_type("bludgeoning");
    set_gender("sexless");
    set_overall_ac(4);
}

void setup_elemental(object caster)
{
    int level;
    if(!objectp(caster)) { return; }
    cast = caster;
    level = (int)caster->query_guild_level("mage");

    set_hd(level,10);
    set_max_hp(level * 10);
    set_hp(level * 10);
    set_overall_ac(level * -1);
    set_mlevel("fighter",level);
//adding stats here too so they aren't overridden by HD. ~Circe~ 9/21/09
    set_stats("strength",18);
    set_stats("intelligence",7);
    set_stats("dexterity",4);
}

void die(object obj)
{
    cast->remove_property("has_elemental");
    ::die(obj);
    return;
}
