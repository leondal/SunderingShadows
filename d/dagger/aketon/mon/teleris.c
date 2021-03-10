#include "/d/dagger/aketon/short.h"
#include <daemons.h>

inherit MONSTER;

object *bad_list;

void unwield_func();
int skin_count,skin_time,corpse_count,corpse_time,blink_count,heal_count;

void create() {
   object obj;
   ::create();
   set_name("teleris");
   set_id( ({"teleris","queen","queen teleris"}) );
   set_race("elf");
   set_gender("female");
   set_short("Teleris the queen");
   set_long("This elegant female grey elf is the queen of the elven "
       "civilization in the Kilkean forest of the Dagger area. Upon your first "
      "glimpse of her face, you could never believe she has approached "
      "her middle age and lived over one hundred years. As the queen of "
      "the place, she is the spiritual and military leader of the city. "
      "During important days or festivals, she will lead the crowd and "
       "perform rutual offerings to the gods. On other days, she rules the "
      "city with the mayor and gives orders to the military leaders upon "
       "the issues of defense. She is the highest power of Aketon. Even "
      "from a distance, you can still sense the strong arua of magic "
      "radiating from her.");
   set_hd(40,10);
   set_max_hp(540);
   set_hp( query_max_hp() );
   set_class("fighter");
   set_class("cleric");
   set_class("mage");
   set_mlevel("fighter",40);
   set_mlevel("cleric",41);
   set_mlevel("mage",44);
   set_guild_level("fighter",40);
   set_guild_level("cleric",41);
   set_guild_level("mage",44);
   add_search_path("/cmds/fighter");
   set_body_type("human");
   set("aggressive",0);
   set_alignment(2);
   set_size(2);
   set_exp(80000);
   set_spells( ({"limb attack",
      "cause blindness",
      "flame strike",
      "lightning bolt",
      "magic missile",
      "meteor swarm",
      "cone of cold",
      "monster summoning ii",
      "monster summoning vi"}) );
   set_spell_chance(60);
   set_property("no bows",1);
   if(random(2))
   set_property("no rush",1);
   set_property("no death",1);
   set_property("no steal",1);
   set_property("no animate",1);
   set_property("no dominate",1);
   set_property("full attacks",1);
   set_property("weapon resistance",3);
   set_mob_magic_resistance("average");
   set_stats("intelligence",25);
   set_stats("wisdom",24);
   set_stats("strength",23);
   set_stats("charisma",25);
   set_stats("dexterity",20);
   set_stats("constitution",18);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_overall_ac(-10);
   new(OPATH+"mace_dragon")->move(TO);
   new(OPATH+"ring_ram")->move(TO);
   command("wear ring");
   new(OPATH+"cloak_elven")->move(TO);
   command("wear cloak");
   add_money( "electrum",4000 + random(2000) );
   add_money( "silver",6000 + random(2000) );
   add_money( "gold",5000 + random(2000) );
   set_stabbed_func( (: TO,"stabbed_func" :) );
   set_funcs( ({"strand","bash"}) );
   set_func_chance(30);
   bad_list = ({});
   skin_count = 5;
   skin_time = 3;
   corpse_count = 5;
   corpse_time = 3;
   blink_count = 50;
   heal_count = 5;
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
      member_array(victim,bad_list) == -1)
      call_out("do_it",1,victim);
   hold = ::kill_ob(victim,which);
   return hold;
}

void do_it(object vic) {
   if(!objectp(vic)) return;
   if( present( vic->query_name() ) ) {
      bad_list += ({vic});
      cease_all_attacks();
      unwield_func();
      new("/cmds/spells/s/_slay_living")->use_spell(TO,vic->query_name(),41,100,"cleric");
      call_out("rush_func",5,vic);
   }
   return;
}

void rush_func(object vic) {
   if(!objectp(vic)) return;
   if( present( vic->query_name() ) ) {
      command("wield mace");
      command("rush "+vic->query_name());
      call_out("unwield_func",7);
   }
   return;
}

void unwield_func() {
   command("unwield mace");
   return;
}

void init() {
   ::init();
   if(wizardp(TP)) return;
   if( (string)TP->query_race() == "human" ) {
      command("say Humans die on sight!");
      if( TP->query_invis() ) TP->set_invis();
      command("kill "+TPQN);
      return;
   }
   if( TP->query_invis() ) {
      tell_object(TP,"Teleris senses your approach and turns to you.");
      TP->set_invis();
      tell_room(ETO,"Teleris senses "+TPQCN+"'s approach and turns to "+
         TP->query_possessive()+".",({TP}));
      command("say Sneaky type dies on sight!");
      command("kill "+TPQN);
   }
   return;
}

void heart_beat() {
   int i,all;
   object *living;
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   skin_time++;
   corpse_time++;
   living = all_living(ETO);
   all = sizeof(living);
   for(i = 0;i < all;i++) {
      if(!userp(living[i]) && (string)living[i]->query_race() == "snake") {
         tell_room(ETO,"The "+living[i]->query_name()+"shivers and "+
            "drops dead as Teleris snaps her finger.");
         living[i]->die();
      }
   }
   if( heal_count && (query_hp() < (query_max_hp()/2)) ) {
      new("/cmds/spells/h/_heal")->use_spell(TO,"teleris",41,100,"cleric");
      heal_count--;
   }
   if( skin_count && !(int)TO->query_stoneSkinned() && skin_time >= 3 ) {
      new("/cmds/spells/s/_stoneskin")->use_spell(TO,"teleris",44,100,"mage");
      skin_time = 1;
      skin_count--;
   }
   if( corpse_count && present("corpse") && corpse_time >= 3) {
      new("/cmds/spells/a/_animate_dead")->use_spell(TO,"corpse",41,100,"mage");
      corpse_time = 1;
      corpse_count--;
   }
   if(blink_count < 1) blink_count = 50;
   if(blink_count == 50)
      tell_room(ETO,"%^BOLD%^Teleris speaks quickly to herself and looks "
      "around furtively.");
   blink_count--;
   return;
}

void strand(object vic) {
   set_property("magic",1);
   tell_room(ETO,"%^RED%^Teleris raises her index finger...");
   tell_room(ETO,"%^RED%^She shoots a strand of energy at "+
      vic->query_cap_name()+"!",vic);
   tell_object(vic,"%^RED%^She shoots a strand of energy at you!");
   if(SAVING_D->saving_throw(vic,"paralyzation_poison_death",-4)) {
      vic->do_damage( "torso",50 + random(30) );
      tell_object(vic,"%^BOLD%^%^GREEN%^You resisted some damage!");
   }
   else {
      vic->do_damage( "torso",80 + random(50) );
      tell_object(vic,"%^BOLD%^%^BLUE%^You failed your attempt to avoid "
         "the strand!");
   }
   remove_property("magic");
}

void bash(object vic) {
   set_property("magic",1);
   tell_object(vic,"%^CYAN%^Teleris waves her mace madly and head-butts "
      "you!");
   tell_room(ETO,"%^CYAN%^Teleris waves her mace madly and head-butts "+
      vic->query_cap_name()+"!",vic);
   if(SAVING_D->saving_throw(vic,"paralyzation_poison_death",-5)) {
      tell_room(ETO,"%^BLUE%^The mace barely hit!");
      vic->do_damage( "head",50 + random(30) );
   }
   else {
      tell_room(ETO,"%^RED%^BONG! The mace hits hard!");
      vic->do_damage( "head",80 + random(50) );
      vic->set_paralyzed(10 + random(5),"You faint by the bash!");
   }
   remove_property("magic");
}

void stabbed_func() {
   if(query_hp() < (query_max_hp()/2)) {
      tell_room(ETO,"%^BLUE%^Teleris moves with agility and avoided most "
         "damage from the stab.");
      set_hp(query_max_hp()/2);
   }
}

int query_watched() {
   return 80;
}

void set_paralyzed(int time,string message) {
   return 1;
}

int query_blinking() {
   return 50;
}
