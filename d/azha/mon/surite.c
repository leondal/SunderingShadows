// Surite Warrior Cleric
// Thorn@ShadowGate
// 6 April 2001
// Town of Azha
// surite.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

int castOK;
int x;
string id;



create() {
        int level;
        object ob;

        ::create();
        castOK = 1;
        id = random(10)+"surite"+time();
        set_name("Surite");
        set_id(({ "surite", "cleric", "warrior cleric", "surite cleric", id}));
        set_mob_magic_resistance("average");
        set_short("Surite warrior cleric");
        set_long(
@TSARVEN
In his time in Azha, Ayatollah Ishmael al-Sura has not been idle.  He 
has made many converts to his Surite sect and has even trained some to 
the priesthood.  This is one of the chosen, a Surite cleric dedicated 
to the aims of Torm and Tyr.  His dress is simple, but appears to 
almost shimmer, as if made of metal plate instead of cloth.  
TSARVEN
        );
        set_body_type("human");
        set_race("human");
        set_gender("male");
        set_class("cleric");
        level = random(10)+15;
        set_guild_level("cleric",level);
        set_guild_level("priest",level);
        set_alignment(1);
        set_size(2);
        set_level(level);
        set_guild_level("cleric", level);
        set_stats("strength", 25);
        set_stats("constitution", 18);
        set_stats("wisdom", 18);
        set_stats("charisma", 15);
        set_stats("intelligence", 14);
        set_stats("dexterity", 20);
        set_max_mp(0);
        set_mp(query_max_mp());
        set_hp((level*8)+30);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
        set_spells( ({ "limb attack", "bolt of glory"}) );
        set_overall_ac(-6);
        set_spell_chance(10);
        ob=new("/d/shadow/obj/weapon/mace");
        ob->set_property("enchantment", 2);
        ob->move(TO);
        force_me("wield mace in left hand");
}

heart_beat() {
  object atkr;
  int y;
  ::heart_beat();
   if(!objectp(TO)) return;
  atkr = TO->query_current_attacker();

  if(query_hp() <= 50 && y < 10 && atkr) {
  	y += 2;
  	"/cmds/spells/c/_cure_critical_wounds"->use_spell(TO, id ,level, 100, "cleric");
  }
  else if(y > 0) y--;
  
  if(query_hp() < query_max_hp() && !atkr) {
  	"/cmds/spells/c/_cure_light_wounds"->use_spell(TO, id ,level, 100, "cleric");
  }
  if(!atkr && !castOK) {
  	x = 0;
  	castOK = 1;
    return;
  }
  else if(castOK && userp(atkr)) {
    "/cmds/spells/a/_animate_object"->use_spell(TO, atkr->query_name() ,level, 100, "cleric");
    castOK = 0;
  }
  else if(castOK && atkr) {
    "/cmds/spells/d/_dispel_magic"->use_spell(TO, "here" ,level, 100, "cleric");
    castOK--;
  }
}

int OkToCast()
{
  castOK = 1;
  return castOK;
}

