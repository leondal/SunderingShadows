//fnewt.c
//fixed the priest so it will actually cast
//10/18/11 -hades
#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

void create()
{
    object ob;
   ::create();

   set_nwp("riding",50);
   set_name("firenewt");
   set_body_type("human");
   add_limb("tail","torso",0,0,0);
   set_gender("male");
   set_property("full attacks",1);
   set("aggressive","sicem");
   set_race("fire newt");
   switch (random(18)) {
   case 0..15:
      set_short("%^RESET%^%^RED%^F%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^enewt%^RESET%^");
      set_id(({"firenewt","Firenewt"}));
      set_long(
@OLI
   This smallish leathery skinned creature looks much like a
dinosaur missed by extinction. Supported by crooked powerful
hind legs, he wields weapons in the powerful clawed hands.
OLI
      );
      set_hd(36 + random(6), 10);
      ob = new("/d/shadow/obj/weapon/bastard");
      ob->set_property("monsterweapon", 1);
      ob->set_property("enchantment", 5);
      ob->move(TO);
      command("wield sword");
      add_money("gold", random(500));
      add_money("platinum", random(50));
      set_damage_bonus(8);
      set_overall_ac(-10);
      set_monster_feats(({
                  "rush",
                      }));
      set_func_chance(35);
      set_funcs(({ "rushit" }));
      set_resistance("fire", 10);
       set_resistance("cold", -10);
      break;
   case 16:
      set_short("%^RED%^E%^BOLD%^%^BLACK%^li%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^e %^RESET%^%^RED%^F%^BOLD%^%^BLACK%^irenewt%^RESET%^");
      set_id(({"firenewt","Firenewt","elite","elite firenewt"}));
      set_long(
@OLI
   This leathery creature is a bit larger then its saller brothers.
It supports itself with powerful bent hind legs and wields weapons
with its powerful claws.
OLI
      );
      set_hd(40+random(4),10);
      ob = new(OBJ+"faxe");
      if(random(3)) { ob->set_property("monsterweapon",1); }
      ob->move(TO);
      command("wield axe");
      add_money("gold",random(600));
      add_money("platinum",random(100));

      ob = new("/d/shadow/obj/weapon/bastard");
      ob->set_property("monsterweapon",1);
      ob->move(TO);
      command("wield sword");
      set_overall_ac(-20);
         set_monster_feats(({
        "spell reflection",
       "ambidexterity",
       "evasion",
       "dodge",

      "mobility",
      "scramble",
      "spring attack",
       "defensive roll",
          "two weapon fighting",
          "improved two weapon fighting",
          "unassailable parry",
          "whirl"
      "resistance",
        "increased resistance",
        "damage resistance",
       "improved damage resistance",
       "toughness",
        }));
      set_damage_bonus(10);
      set_func_chance(35);
      set_funcs(({"whirlit"}));
      call_out("do_horse",1);
      set_resistance("fire",15);
      set_resistance("cold",-15);
      break;
   case 17:
      set_short("Firenewt priest");
      set_id(({"firenewt","Firenewt","priest"}));
      set_long(
@OLI
This leathery creature is a bit larger then its saller brothers.
It supports itself with powerful bent hind legs and wields weapons
with its powerful claws.
OLI
      );
      set_hd(34+random(10),10);
      ob = new("/d/shadow/obj/weapon/mace");
      ob->set_property("monsterweapon",1);
      ob->move(TO);
      command("wield mace");
      set_overall_ac(-55);
      set_damage_bonus(7);
      set_guild_level("cleric",44);
      set_spells(({"flame strike","handfire","fear","fire storm","flameburst","greater dispel magic"}));
      set_monster_feats(({
                  "spellpower",
                      "spell focus",
                      "spell penetration",
                      "greater spell penetration",
                      "toughness",
                      "damage resistance",
                      "improved damage resistance",
         }));
      set_spell_chance(90);
      call_out("do_horse",1);
      set_resistance("fire",15);
      set_resistance("cold",-15);
      break;
   }

   //set_exp(450*query_hd());
   set_new_exp(32,"very high");
   set_property("add kits",roll_dice(1, 4) * 5);
   set_hp(20*query_hd());
   set_property("swarm",1);
   set_mob_magic_resistance("average");
   set_property("spell damage resistance",20);
   set_resistance_percent("fire", 133);
   set_resistance_percent("cold", -33);
   set_damage(2,10);
   set_attacks_num(5);
   set_attack_limbs(({"mouth","right claw","left claw"}));
   set_funcs(({"fire"}));
   set_func_chance(30);
    add_id("newt");
    set_stats("strength",25);
    if(!random(20)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("eye of newt");
      ob->move(TO);
    }
}

void fire(object targ)
{
    if (!objectp(targ)) {
        return;
    }

    tell_room(ETO, "%^RED%^A shot a flame bellows toward "
              + targ->query_cap_name() + ".", targ);
    tell_object(targ, "%^RED%^A shot of flame bellows toward you.");
    set_property("magic", 1);
    targ->do_damage("torso", random(75));
    remove_property("magic");
}

void whirlit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("whirl " + targ->query_name());
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

void do_horse(){
    object horse;

    if (!objectp(ETO)) {
        return;
    }

    horse = new(MON + "strider");
    horse->set_owner(TO);
    horse->move(ETO);
        command("mount strider");
}

void sicem()
{
    command("sic "+TP->query_true_name());
    command("kill "+TP->query_true_name());
    set("aggressive",100);
}
