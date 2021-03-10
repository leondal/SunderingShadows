#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit MONSTER;


void create() {
   object ob;
    ::create();
  set_name("Vendire");
  set_id(({"elf","ranger","elven ranger", "elf ranger","vendire","vendire the ranger"}));
  set_short("Vendire, elven ranger");
    set_long(
  "  Vendire looks haggard and full of a deep sorrow, which mars his unearthly elven good looks."
  "  He watches the old king with pity and the look of a friend who's long seen the suffering of his comrade."
  "  A smile tugs at the edges of his lips when he sees anyone nearby enjoying the garden but his hands never leave his weapons as he stands near the old king."
    );
  set_mob_magic_resistance("average");
    set_property("swarm", 1);
  set_overall_ac(-12);
  set_attack_bonus(20);
    set_class("ranger");
  set_class("cleric");
  set_spells(({"call lightning", "call lightning", "dispel magic"}));
  set_spell_chance(40);
  set_property("magic",1);
    set_mlevel("ranger", 35);
  set_mlevel("cleric",20);
  set_property("full attacks",1);
  set_guild_level("cleric",20);
    set_guild_level("ranger", 35);
  command("pose ranger");
  set_hd(35,10);
  set_max_hp(300);
  set_hp(300);
    set_gender("male");
    set("race", "elf");
    set_body_type("human");
    set_size(2);
  set_stats("strength",19);
    set_stats("dexterity", 19);
    set_stats("constitution", 15);
    set_stats("intelligence", 14);
    set_stats("charisma", 14);
    set_stats("wisdom", 14);
    set_alignment(4);
    set("aggressive", 2);
  ob=new("/d/dagger/derro/obj/scimitar.c");
  ob->set_property("monsterweapon",1);
    ob->move(TO);
  new("/d/dagger/road/obj/studded+3.c")->move(TO);
  ob=new("/d/dagger/Torm/obj/Mlong+2.c");
  ob->set_property("monsterweapon",1);
  ob->move(TO);
    command("wield longsword");
  command("wield scimitar");
    command("wearall");
	set_invis();
    add_money("gold", 150 + random(100));
    add_money("platinum", 50 + random(10));
}


int query_watched(){
  return 150;
}

void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(query_night()){
    if(ETO->query_property("indoors")) return 1;
    TO->move("/d/shadowgate/void.c");
    TO->remove();
  }
}
