#include <std.h>
#include <security.h>
#include "../antioch.h"
inherit MONSTER;

int CALL;

void create()
{
        ::create();
        set_no_clean(1);
        CALL = 0;
        set_name("royal guard");
        set_short("A royal guardian of Antioch");
        set_id(({"guard","royal guard","guardian","guardian of Antioch","guardian of antioch","Antioch guardian","antioch guardian","royal guardian","knight"}));
        set_long(
        "This is one of the royal guards of the city of Antioch. They are all"+
        " knights that have dedicated their service to Jarmila and the royal family"+
        " of Antioch. They are responsible for patrolling the palace and keeping"+
        " it safe, and sometimes assist the common guardsmen in times of trouble."+
        " He is wearing the uniform of the royal guard, a red robe and golden belt"+
        " with a silver sword and matching shield and helm. Full plate covers his"+
        " torso, it is enscribed with the ensignia of a unicorn. He stands alert"+
        " and ready for any danger."
        );
        set_gender("male");
        set_race("human");
        set_hd(55,10);
        set_alignment(1);
        set_overall_ac(-40);
        set_max_hp(roll_dice(query_hd(), 40));
        set_hp(query_max_hp());
        set_class("cavalier");
        set_mlevel("cavalier",25);
        set_level(25);
        set_stats("strength",25);
        set_stats("constitution",25);
        set_stats("dexterity",16);
        set_stats("charisma",12);
        set_stats("wisdom",13);
        set_stats("intelligence",15);
        set_exp(200);
        set_property("swarm",1);
        set_property("alignment adjustment",-1);  // was -10 *Styx* 12/25/05
        set_property("no dominate",1);
        set_property("no paralyze",1);
        set_property("no hold",1);
        set_property("no bows",1);
        
        set_monster_feats( ({
                             "damage resistance",
                             "improved damage resistance",
                             "resistance",
                             "toughness",
                             "improved toughness",
                             "death ward",
                             "regeneration",
                           }) );
                           
        set("aggressive",0);
        set_emotes(3,({
        "The royal guard rushes into you!",
        "The royal guard gives out a war cry as he charges!",
        "The royal guard slams his shield into your face.",
        "The royal blocks your strike with his sword.",
        }),1);
        new(OBJ+"unicorn_shield")->move(TO);
        if(!random(2)) {
            present("shield",TO)->set_property("monsterweapon",1);
        }
        new(OBJ+"silvered_helm")->move(TO);
        new(OBJ+"red_robe")->move(TO);
        new(OBJ+"gold_belt")->move(TO);
        new(OBJ+"silver_sword")->move(TO);
        command("wield sword");
        command("wearall");
}
 
void heart_beat()
{
   object ob, *atkrs;
   int x;
   if(!objectp(TO)) return;
   atkrs = TO->query_attackers();
   ::heart_beat();
   if(atkrs != ({ }) && CALL != 1) {
      call_out("summon_guards",5);
      force_me("yell Help, I'm under attack!");
      CALL = 1;
   }
}

int summon_guards()
{
   object ob;
   tell_room(ETO,"several guards rush into the room.");
   new(MONS+"palace_guard")->move(ETO);
   new(MONS+"palace_guard")->move(ETO);
   if(sizeof(TO->query_attackers()) > 1) {
      new(MONS+"palace_guard")->move(ETO);
   }
   if(sizeof(TO->query_attackers()) > 2) {
      new(MONS+"palace_guard")->move(ETO);
   }
   if(sizeof(TO->query_attackers()) > 3) {
      new(MONS+"palace_guard")->move(ETO);
   }
   return 1;
}

void die(object obj) {
  // You love me, Crystal. You know you do.
  // garrett

  object killer;
  seteuid(UID_LOG);
  if (objectp(killer=TO->query_current_attacker()))
   log_file("antioch", killer->query_name()+" killed royal guard on "+ctime(time())+".\n");
  seteuid(getuid(previous_object()));
  return ::die(obj);
}
