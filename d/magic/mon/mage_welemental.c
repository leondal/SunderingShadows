//welemental.c

#include "summoned_monster.h"

inherit MONSTER;
object cast;

void create(){
  ::create();

    set_name("water elemental");
    set_id(({"elemental","water elemental","welemental","greater summon"}));

    set_short("%^BOLD%^%^BLUE%^a w%^RESET%^%^CYAN%^a%^RESET%^%^BOLD%^t%^RESET%^e%^BOLD%^%^BLUE%^r elemental%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^Like a tidal wave just before it crashes, this "
             "water elemental %^WHITE%^crests %^BLUE%^at just over eight feet tall.  "
             "Its body is a churning mass of water, full of the %^RESET%^%^BLUE%^"
             "deep blues %^BOLD%^and %^RESET%^%^CYAN%^vibrant greens %^BOLD%^%^BLUE%^"
             "of the sea.  The humanoid body splits and combines, forming arms here "
             "and there that lash out, ready to smite its targets with the relentless "
             "power of %^RESET%^%^CYAN%^water%^BOLD%^%^BLUE%^.  Although it has no "
             "visible eyes, this creature seems to have no trouble seeking out its enemies.%^RESET%^");
    set_hd(4 + (4 *(random(3)+1)),1);
    set_hp(query_hd()*8);
    set_exp((query_hd()-6)* 1000);
    set_stats("strength",18);
    set_stats("intelligence",7);
    set_stats("dexterity",10);
    add_limb("torso","torso",50,0,2);
    add_limb("right crest","right crest",50,0,2);
    add_limb("left crest","left crest",50,0,2);
    add_limb("upper crest","upper crest",50,0,2);
    add_limb("base","base",50,0,2);
    set_race("elemental");
    set_gender("sexless");
    set_wielding_limbs(({"right crest","left crest"}));
    set_overall_ac(2);
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
    set_stats("dexterity",10);
}

void die(object obj)
{
    cast->remove_property("has_elemental");
    ::die(obj);
    return;
}
