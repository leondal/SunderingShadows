//aelemental.c

#include "summoned_monster.h"

inherit WEAPONLESS;
object cast;


void create(){
  ::create();

    set_name("air elemental");
    set_id(({"elemental","air elemental","aelemental","greater summon"}));
    set_short("%^RESET%^%^CYAN%^an a%^BOLD%^%^WHITE%^i%^CYAN%^r %^RESET%^%^CYAN%^elemental%^RESET%^");
    set_long("%^RESET%^%^CYAN%^Like an eight-foot tall %^BOLD%^%^BLACK%^"
             "cyclone%^RESET%^%^CYAN%^, this elemental creates a miniature storm "
             "around it, full of fierce %^BOLD%^winds %^RESET%^%^CYAN%^and a biting "
             "chill.  A gaping %^BOLD%^%^BLACK%^black maw %^RESET%^%^CYAN%^appears "
             "and vanishes where the creature's head should be, and thunderous, "
             "thick columns of air make up its arms.  At times, portions of the "
             "elemental seem to dissipate into the wind, only to reform into a "
             "translucent shape of %^BOLD%^%^BLACK%^gray%^RESET%^%^CYAN%^, "
             "%^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^, and %^BOLD%^sky blue%^RESET%^%^CYAN%^.  Although it has no "
             "visible eyes, this creature seems to have no trouble seeking out its enemies.%^RESET%^");
    set_hd(4 + (4 *(random(3)+1)),1);
    set_hp(query_hd()*8);
    set_exp((query_hd()-6)* 1000 + 1000);
    set_stats("strength",18);
    set_stats("intelligence",7);
    set_stats("dexterity",25);
    set_race("elemental");
    add_limb("torso","torso",50,0,2);
    add_limb("right spindal","torso",50,0,2);
    add_limb("left spindal","torso",50,0,2);
    add_limb("base","torso",50,0,2);
    set_attack_limbs(({"base"}));
    set_damage(2,10);
    set_attacks_num(2);
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
    set_stats("dexterity",25);
}

void die(object obj)
{
    cast->remove_property("has_elemental");
    ::die(obj);
    return;
}
