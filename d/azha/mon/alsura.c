// Ishmael al-Sura, visiting Holy Man
// Thorn@ShadowGate
// 4/13/96
// Town of Azha
// alsura.c
// modified holy orb to flame strike, was leaving the room in constant combat with the surites and killing people. Nienne, 12/05.

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

int castOK;
object *platoon;



void create() {
        int level;
        object ob;

        ::create();
        castOK = 1;
        set_name("Ayatollah al-Sura");
        set_id(({ "ayatollah", "alsura", "ishmael", "al-sura" }));
        set_mob_magic_resistance("average");
        set_short("Ishmael al-Sura, visiting Holy Man");
        set_long(
@TSARVEN
  A former Imperial officer, Ishmael al-Sura saw a vision while on a
campaign on the eastern frontier.  Called to defend justice and law
throughout the world, al-Sura became a travelling holy man and the
leader of a military order of clerics.  Ayatollah al-Sura is fanatically
devoted to his mission of bringing evil men to justice and ridding the
world of the destructive effects of Chaos.
TSARVEN
        );
        set_body_type("human");
        set_race("human");
        set_gender("male");
        set_class("cleric");
        level = 37;
        set_guild_level("cleric",level);
        set_guild_level("priest",level);
        set_alignment(1);
//        set_size(2);
        set_mlevel("cleric",level);
        set_guild_level("cleric", level);
        set_stats("strength", 25);
        set_stats("constitution", 25);
        set_stats("wisdom", 16);
        set_stats("charisma", 17);
        set_stats("intelligence", 14);
        set_stats("dexterity", 25);
//        set_max_mp(0);
//        set_mp(query_max_mp());
        set_hp(340);
        set_max_hp(query_hp());
//        set_max_sp(query_hp());
//        set_sp(query_max_sp());
//        set_wielding_limbs( ({ "right hand", "left hand" }) );
//        set_spells( ({ "limb attack", "bolt of glory", "holy orb" }) );
        set_spells( ({ "limb attack", "bolt of glory", "flame strike" }) );
        set_overall_ac(-10);
        set_spell_chance(55);
        ob=new("/d/azha/obj/rift_key");
        if(random(5)) ob->set_property("monsterweapon",1);
        ob->move(TO);
        force_me("wear key");
        ob=new("/d/shadow/obj/weapon/mace");
        ob->set_property("enchantment", 3);
        ob->move(TO);
        force_me("wield mace");
}

heart_beat() {
  object atkr;
  int x,y;
  ::heart_beat();
   if(!objectp(TO)) return;
  atkr = TO->query_current_attacker();
  
  if(query_hp() <= 50 && y <= 10 && atkr) {
  	y += 2;
  	"/cmds/spells/c/_cure_critical_wounds"->use_spell(TO, "alsura" ,level, 100, "cleric");
  }
  else if(y > 0) y--;
  
  if(query_hp() < 75 && x++ < 5 && atkr) {
    "/cmds/spells/h/_heal"->use_spell(TO, "al-sura" ,37, 100, "cleric");
  }
  if(!atkr) {
  	if(platoon) remove_surites();
    if(x) x = 0;
    if(!castOK) OkToCast();
    return;
  }
  if(castOK && atkr) {
    "/cmds/spells/d/_dispel_magic"->use_spell(TO, "here" ,37, 100, "cleric");
    summon_surites();
    castOK = 0;
  }
}

int OkToCast()
{
  castOK = 3;
  return castOK;
}

void summon_surites() {
	int y, block;
	string sfile = "/d/azha/mon/surite";
	object surite;
	
	platoon = ({ });
	tell_room(ETO, "%^BOLD%^WHITE%^A group of Surite priests comes to their leader's aid!");
	y = random(2)+1;
	block = 1;
	while(y--) {
		surite = new(sfile);
		surite->move(ETO);
		surite->set_attackers(query_attackers());
		if(block) {
			surite->force_me("block south");
			block = 0;
		}
		else surite->force_me("protect alsura");
		platoon += ({ surite });
	}
}

void remove_surites() {
	int y;
	
	tell_room(ETO, "%^BOLD%^WHITE%^The Surite clerics return to their meditations.");
	for(y=0;y<sizeof(platoon);y++) {
         if(platoon[y] && objectp(platoon[y])){
		platoon[y]->move("/d/shadowgate/void.c");
		platoon[y]->remove();
         }
	}
	platoon = 0;
}

void die(mixed ob) {
	if(platoon) remove_surites();
	::die(ob);
}
