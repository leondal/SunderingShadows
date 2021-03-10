#include <std.h>
#include "/d/islands/elf/elf.h"
inherit MONSTER;

create (){
::create ();
set_name("Skull girl");
set_id( ({"skull girl","undead","girl","skull"}) );
set_short("Skeleton in a Dress");
set_long("This is an undead person who is wearing "+
"a tattered dress from a bygone era.  Bit of flesh are"+
" partly detached and waver in the water. "+
"  It's eyes glow red with hatred.");
set_gender("female");
set_hd(35,10);
set_hp(750+random(1000));
set("race", "undead");
set_body_type("human");
set_property("swarm",1);
set_class("mage");
set_mlevel("mage",46);
    level = 46;
set_guild_level("mage",46);
set_max_level(47);
set_property("full attacks",1);
set_overall_ac(-30);
set_size(2);
set_stats("strength", 16);
set_stats("intelligence", 26);
set_stats("dexterity", 19);
set_stats("charisma", 6);
set_stats("wisdom", 5);
set("aggressive", 25);
set_alignment(4);

set_attacks_num(5);
set_hp(query_max_hp());
set_wielding_limbs( ({"left hand","right hand"}) );
add_money("copper", 200 + random(140));
set_resistance("negative energy",10);
set_resistance("positive energy",-10);
set_resistance_percent("slashing", 70);
set_resistance_percent("bludgeoning", 70);
set_mob_magic_resistance("average");
set_monster_feats(({
    "spell reflection",
    "spell power",
    "damage reduction",
    "regeneration",
    "resistance",
    "spell reflection",
    "improved resistance",
    "damage resistance",
    "damage reduction",
      })); 
set_property("water breather", 1);

new(OBJ"dress")->move(TO);

force_me("wearall");

set_missChance(25);
set_spell_chance(100);
set_spells(({
                 "acid breath",
                 "necrophage",
                 "acid fog"
                 "nightmare maw",
                 "unholy aura",
                 "frightful aspect"
              }));
}

