//wimp.c
// several fixes in various places to try to fix bugs -
// fixed attack limbs to be valid limbs, set body types after race & before 
// adding limbs, moved settings for limbs to after they are added, body type on
// spider to arachnid from arachnoid (which didn't exist in mraces)
// added checks for valid object & objectp(target), etc.
// *Styx*  5/15/02

#include <std.h>

inherit "/d/tharis/monsters/wfwander";

string current;

void make_me();
void new_form();
void make_imp();

void create() {
   ::create();
   set_name("imp");
   set_id(({"imp","rat","spider","Imp"}));
   set_hd(4,8);
   set_hp(80);
   add_money("gold",random(50));
   add_money("copper",random(35));
   set_attacks_num(1);
   make_me();
   set_gender("male");
   set_exp(1500);
   set_alignment(3);
   set_max_level(20);
}

void make_me() {
   set_long(
@OLI
This heinous little creature has vaguely human form.  It has thick,
leathery skin covering its body and two small wings protrude from its back.
It seems that this monster has been summoned from the depths of some
horrible dream.
OLI
   );
   set_short("A leathery little imp");
   set_race("imp");
   set_body_type("human");
   add_limb("tail","torso",0,0,0);
   add_limb("left wing","torso",0,0,0);
   add_limb("right wing","torso",0,0,0);
   set_damage(1,6);
   set_hit_funcs((["tail":(:TO,"poison_me":)]));
   set_base_damage_type("piercing");
   set_attack_limbs(({"tail"}));
   set_overall_ac(0);
}

int poison_me(object targ) {
   if(random(100) < 5) {
      tell_object(targ,"%^BOLD%^%^RED%^The poison reaches your heart and you feel it slow to stopping.\n");
      tell_object(targ,"%^BOLD%^%^RED%^Your lungs seem to be colapsing there is no more air in the world.\n");
      tell_object(targ,"%^BOLD%^%^RED%^Your brain slow shuts down! You slip from conciousness..........and life!");
      if(!objectp(targ)) return 40;
      targ->add_poisoning(60000);
      targ->setPoisoner(TO);
   }
   else {
      tell_object(targ,"%^BOLD%^%^CYAN%^You feel your body fighting off the poison flowing through it!\n");
      tell_object(targ,"%^BOLD%^%^CYAN%^You feel you will live!");
      return 0;
   }
}

void heart_beat() {
   ::heart_beat();
// moved to init to try to fix conflicts with scavengers and other hb bugs
// 8/02 got a too deep recursion so trying it back here now that other forest
// bugs are fixed
   if(!objectp(TO)) return;
   if(random(4))  return;
   if(query_race() == "imp" && query_attackers() == ({}))
      new_form();
   if(query_race() != "imp" && query_attackers() != ({}))
      make_imp();
   if(query_hp() < 10) {
      run_away();
      set_invis();
   }
}

void new_form() {
   int my_hp;
   object ob;
   if(!objectp(TO)) return;
   seteuid(getuid());
   switch(random(2)) {
    case 0:
      set_name("giantrat");
      set_id( ({ "giantrat","giant","rat","giant rat"}) );
      set_short("A giant rat");
      set_level(2);
      set("long", "A giant rat.\n");
      set_gender("male");
      set_race("rat");
      set_body_type("quadruped");
      set("aggressive",20);
      set_size(1);
      set_attacks_num(2);
      set_base_damage_type("slashing");
      set_attack_limbs(({"right forepaw", "left forepaw"}));
      break;
    case 1:
      set_name("spider");
      set_id(({"spider","giant spider"}));
      set_short("A giant spider");
      set_level(5);
      set("long", "This large spider is very uncommon in the Shadowgate\n"+
          "realm.  They are not web builders, they are raving\n"+
          "hunters.\n");
      set_gender("female");
      set_race("spider");
      set_body_type("arachnid");
      set_alignment(5);
      set_size(2);
      set_class("fighter");
      set_attack_limbs(({"left pincer", "right pincer"}));
      break;
   }
   tell_room(ETO,"%^BOLD%^%^YELLOW%^You witness a wondrous transformation as this creature changes form!");
   return;
}

void make_imp() {
   set_name("imp");
   set_id(({"imp","rat","spider","Imp"}));
   set_hd(4,8);
   set_hp(80);
   add_money("gold",random(50));
   add_money("copper",random(35));
   set_attacks_num(1);
   make_me();
   set_gender("male");
   set_exp(1500);
   set_alignment(3);
   set_long(
@OLI
This heinous little creature has vaguely human form. It has thick,
leathery skin covering its body. Two small wings protrude from its back.
It seems that this monster has been summoned from the depths of some
horrible dream.
OLI
   );
   set_short("A leathery little imp");
   set_body_type("human");
   add_limb("tail","torso",0,0,0);
   add_limb("left wing","torso",0,0,0);
   add_limb("right wing","torso",0,0,0);
   set_attack_limbs(({"tail"}));
   set_damage(1,6);
   set_hit_funcs((["tail":(:TO,"poison_me":)]));
   set_race("imp");
   set_base_damage_type("piercing");
   set_overall_ac(0);
   tell_room(ETO,"%^BOLD%^%^YELLOW%^You witness a wondrous transformation as this creature reveals its true form!");
}

void init() {
   ::init();
/* putting this back into hb since got a too deep recursion error after other
   bugs were fixed from scavengers  *Styx*  8/18/02

if(query_hp() < 10) {
      run_away();
      set_invis();
      return;
   }
   if(ALIGN->is_good(TP) && !TP->query_invis())
      kill_ob(TP,1);
   if(query_race() == "imp" && query_attackers() == ({})) {
      new_form();
      return;
   }
   if(query_race() != "imp" && query_attackers() != ({})) {
      make_imp();
      return;
   }
*/
}

int kill_ob(object victim, int which) {
   object *inven;
   int i,k;
//   if(!objectp(victim) || !objectp(TO))  return 1;  not sure to use 1 or 0
   if(!swarm) {
      if(victim == TP && interactive(TP)) {
         swarm = 1;
         inven = all_inventory(environment(TO));
         k = sizeof(inven);
         for(i=0;i<k;i++) {
            if(living(inven[i])) {
               if(ALIGN->is_evil(inven[i])) {
                  if(inven[i] != TP)
                     inven[i]->kill_ob(TP,1);
               }
            }
         }
      }
      swarm = 0;
   }
   return ::kill_ob(victim,which);
}
