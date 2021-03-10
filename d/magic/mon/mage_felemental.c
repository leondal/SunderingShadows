//felemental.c

#include "summoned_monster.h"

inherit WEAPONLESS;

object cast;

void create(){
    ::create();

    set_name("fire elemental");
    set_id(({"fire","fire elemental","elemental","felemental","greater summon"}));
    set_short("%^RESET%^%^RED%^a %^BOLD%^f%^MAGENTA%^i%^RESET%^r%^BOLD%^%^RED%^e %^RESET%^%^RED%^elemental%^RESET%^");
    set_long("%^RESET%^%^RED%^Looming over eight feet tall, this "
             "%^BOLD%^f%^MAGENTA%^i%^RESET%^r%^BOLD%^%^RED%^e elemental "
             "%^RESET%^%^RED%^fills the area with menacing %^BOLD%^fl"
             "%^YELLOW%^a%^RED%^mes%^RESET%^%^RED%^.  Seemingly possessing "
             "no concrete form, the elemental shifts, shrinking and expanding "
             "as it takes a vaguely humanoid form.  Mimicking the appearance "
             "of a normal flame, the base of the fire elemental is %^BLUE%^deep "
             "blue%^RED%^, giving way to %^BOLD%^%^RED%^reds%^RESET%^%^RED%^, "
             "%^ORANGE%^oranges%^RED%^, and %^YELLOW%^yellows %^RESET%^%^RED%^"
             "with flickers of %^BOLD%^%^WHITE%^white %^RESET%^%^RED%^and "
             "%^BOLD%^%^BLACK%^ashy gray%^RESET%^%^RED%^.  Although it has no "
             "visible eyes, this creature seems to have no trouble seeking out its enemies.%^RESET%^");
    set_hd(4 + (4 *(random(3)+1)),1);
    set_hp(query_hd()*8);
    set_exp((query_hd()-6)* 1000);
    set_stats("strength",18);
    set_stats("intelligence",7);
    set_stats("dexterity",4);
    set_race("elemental");
    add_limb("torso","torso",50,0,2);
    add_limb("right flame","torso",50,0,2);
    add_limb("left flame","torso",50,0,2);
    add_limb("base","torso",50,0,2);
    set_attack_limbs(({"left flame", "right flame"}));
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
