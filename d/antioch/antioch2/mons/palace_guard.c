#include <std.h>
#include <security.h>
#include "../antioch.h"
inherit MONSTER;

void create()
{
        ::create();
//   set_no_clean(1); // I don't think we want or need this *Styx* 12/25/05
        set_name("palace guard");
        set_short("A palace guard");
        set_id(({"guard","palace guard"}));
        set_long(
        "The palace guards are chosen from the elite of the royal guards. This"+
        " one stands at attention in a full plate of armor, with shield and helm."+
        " His visor is raised as a courtesy to the guests of the palace. Steel"+
        " guantlets and boots protect his hands and feet. He looks well protected"+
        " and quite equipped to handle most dangers. A sword is sheathed in its"+
        " scabbard, and he wields a large polearm. The purple crest of Antioch"+
        " is worn over his armor, with a white pegasus standing in the center of"+
        " the field."
        );
        set_gender("male");
        set_race("human");
        set_body_type("humanoid");
        set_alignment(1);
        set_hd(60,15);
        set_max_hp(roll_dice(query_hd(), 40));
        set_hp(query_max_hp());
        set_overall_ac(-50);
        set_class("cavalier");
        set_level(60);
        set_mlevel("cavalier",30);
        set_stats("strength",25);
        set_stats("constitution",25);
        set_stats("dexterity",16);
        set_stats("intelligence",15);
        set_stats("wisdom",14);
        set_stats("charisma",12);
        
        set_monster_feats( ({
                             "toughness",
                             "improved toughness",
                             "resistance",
                             "damage resistance",
                             "improved damage resistance",
                             "regeneration",
                           }) );
                           
        set_property("swarm",1);
        set_property("full attacks",1);
        set_property("no bows",1);
        set_property("no dominate",1);
        set_property("no hold",1);
        set_property("no paralyze",1);
//   set_property("alignment adjustment",-10);  
// too many get summoned and as often as not it's a legit fight rather than someone attacking them
//*Styx* 12/25/05
        set("aggressive",0);
        set_exp(300);
   new("/d/common/obj/weapon/halberd")->move(TO);
        command("wield halberd");
}
void die(object obj) {
  // You love me, Crystal. You know you do.
  // garrett

  object killer;
  seteuid(UID_LOG);
  if (objectp(killer=TO->query_current_attacker()))
   log_file("antioch", killer->query_name()+" killed palace guard on "+ctime(time())+".\n");
  seteuid(getuid(previous_object()));
  return ::die(obj);

}
