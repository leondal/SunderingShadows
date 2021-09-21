// Foo! - LoKi

#include <std.h>
#include "../jarmila.h"

inherit WEAPONLESS;

void create()
{
    object ob;
   ::create();


   set_name("foo creature");
   set_body_type("quadruped");
   set_gender("neuter");
   set_property("full attacks",1);
   set("aggressive","sicem");
   set_race("foo creature");
   switch (random(18)) {
   case 0..11:
      set_short("%^C136%^go%^C185%^l%^C136%^den "+
	  "fur%^C185%^r%^C136%^ed Foo Dog%^CRST%^");
      set_id(({"Foo Dog","foodog","dog"}));
      set_long("%^C185%^This massive beast looks walks on four legs and "+
	  "is %^C088%^bristling with muscles%^C185%^ under its %^C136%^golden "+
	  "fur%^C185%^. While it resembles a %^C094%^monstrous dog%^C185%^, "+
	  "its face has an oddly %^C101%^human%^C185%^ quality to it. Each "+
	  "of its paws end in %^C244%^wicked claws%^C185%^ and %^C015%^two "+
	  "massive fangs%^C185%^ hang out from its mouth.%^CRST%^\n");
      set_hd(36 + random(6), 10);
      add_money("gold", random(500));
      add_money("platinum", random(50));
      set_damage_bonus(8);
      set_overall_ac(-20);
      set_monster_feats(({
                  "rush",
                      }));
      set_func_chance(35);
      set_funcs(({ "rushit" }));
      set_resistance("divine", 10);
       set_resistance("unholy", -10);
      break;
   case 12..17:
      set_short("%^C254%^whi%^C246%^t%^C254%^e fu%^C246%^r%^C254%^red "+
	  "Foo L%^C246%^i%^C254%^on%^CRST%^");
      set_id(({"foo lion","lion","foo","foolion"}));
      set_long("%^C254%^This massive beast looks walks on four legs "+
	  "and is %^C088%^bristling with muscles%^C254%^ under its "+
	  "%^C246%^snow white fur%^C254%^. While it resembles a "+
	  "%^C094%^monstrous lion%^C254%^, its face has an oddly "+
	  "%^C101%^human%^C254%^ quality to it. Each of its paws "+
	  "end in %^C244%^wicked claws%^C254%^ and %^C241%^two massive "+
	  "fangs%^C254%^ hang out from its mouth.%^CRST%^\n");
	  set_hd(40+random(4),10);
      add_money("gold",random(600));
      add_money("platinum",random(100));
      set_overall_ac(-30);
         set_monster_feats(({
         "unarmed parry",
         "rapid strikes",
         "precise strikes",
         "dodge",
         "mobility",
         "scramble",
         "spring attack",
         "defensive roll",
         "resistance",
         "increased resistance",
         "damage resistance",
         "improved damage resistance",
         "toughness",
		 "rush",
        }));
      set_damage_bonus(10);
      set_func_chance(35);
      set_funcs(({"rushit"}));
      set_resistance("divine",25);
      set_resistance("unholy",-15);
      break;
  
   }

   set_new_exp(32,"very high");
   set_property("add kits",roll_dice(1, 4) * 5);
   set_hp(20*query_hd());
   set_property("swarm",1);
   set_mob_magic_resistance("average");
   set_property("spell damage resistance",20);
   set_damage(2,10);
   set_attacks_num(5);
   set_attack_limbs(({"mouth","right claw","left claw"}));
   set_func_chance(30);
   set_stats("strength",25);
    if(!random(30)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("divine essence");
      ob->move(TO);
    }
}

void rushit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("rush " + targ->query_name());
}

void sicem()
{
    command("sic "+TP->query_true_name());
    command("kill "+TP->query_true_name());
    set("aggressive",100);
}

