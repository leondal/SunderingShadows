#include "/d/dagger/aketon/short.h"
#include <daemons.h>

inherit MONSTER;

object *bad_list;

int count,blink_count;

void create() {
   object obj;
   ::create();
   set_name("naxterr");
   set_id( ({"naxterr","mayor","leader"}) );
   set("race","elf");
   set_gender("male");
   set_short("Naxterr the mayor");
   set_long("Before you stands this old elf. With grey beard, grey hair "
      "and a suit of grey cloak, his eyes are still bright and clear. "
      "With a strange club and a ordinary dagger in his hand, he watches "
      "your every movement closely. He is the mayor of the town. He is "
      "the oldest elf here with a wide knowledge in the art of magic. "
      "Though he looks clumsy, you are not sure if attacking him is a "
      "wise decision.");
   set_hd(40,8);
   set_max_hp(475);
   set_hp( query_max_hp() );
   set_class("fighter");
   set_class("mage");
   set_class("thief");
   set_mlevel("fighter",37);
   set_mlevel("mage",38);
   set_mlevel("thief",40);
   set_guild_level("fighter",37);
   set_guild_level("mage",38);
   set_guild_level("thief",40);
   set_thief_skill("hide in shadows",95);
   set_thief_skill("move silently",95);
   add_search_path("/cmds/fighter");
   add_search_path("/cmds/thief");
   set_body_type("human");
   set("aggressive",0);
   set_alignment(2);
   set_size(2);
   set_exp(50000);
   set_spells( ({"lightning bolt",
      "magic missile",
      "monster summoning v",
      "monster summoning vi"}) );
   set_spell_chance(40);
   set_property("no bows",1);
   set_property("no rush",1);
   set_property("no death",1);
   set_property("no steal",1);
   set_property("no animate",1);
   set_property("full attacks",1);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("average");
   set_stats("intelligence",25);
   set_stats("wisdom",18);
   set_stats("strength",22);
   set_stats("charisma",18);
   set_stats("dexterity",25);
   set_stats("constitution",18);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_overall_ac(0);
   new(WEAPONPATH+"dagger")->move(TO);
   command("wield dagger");
   new(OPATH+"club_disrup")->move(TO);
   command("wield club");
   new(OPATH+"cloak_elven")->move(TO);
   command("wear cloak");
   add_money( "electrum",2000 + random(1000) );
   add_money( "silver",5000 + random(1000) );
   add_money( "gold",4000 + random(1000) );
   set_stabbed_func( (: TO,"stabbed_func" :) );
   set_scrambling(1);
   set_funcs( ({"blow","bash"}) );
   set_func_chance(35);
   bad_list = ({});
   count = 3;
   blink_count = 50;
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
      member_array(victim,bad_list) == -1)
      call_out("do_it",1,victim);
   hold = ::kill_ob(victim,which);
   return hold;
}

void do_it(object victim) {
   if( !objectp(victim) )
      return;
   if( present( victim->query_name() ) ) {
      bad_list += ({victim});
      cease_all_attacks();
      victim->cease_all_attacks();
      command("stab "+victim->query_name());
      call_out("rush_func",2,victim);
   }
   return;
}

void rush_func(object victim) {
   if( !objectp(victim) )
      return;
   if( present( victim->query_name() ) )
      command("rush "+victim->query_name());
   return;
}

void init() {
   ::init();
   if( wizardp(TP) )
      return;
   if( TP->query_invis() ) {
      tell_object(TP,"Naxterr senses your approach and turns to you.");
      TP->set_invis();
      tell_room(ETO,"Naxterr senses "+TPQCN+"'s approach and turns to "+
         TP->query_possessive()+".",({TP}));
   }
   if( (string)TP->query_race() == "human" ) {
      command("say A human, how dare you spying us!?");
      command("say All spies shall die, "+TPQCN+"!!");
      command("kill "+TPQN);
   }
   if( (int)SAVE_D->is_member("aketon_list",TPQN) == -1 ) {
      if( !random(10) && interactive(TP) ) {
         command("say You have entered a wrong place!");
         command("kill "+TPQN);
      }
   }
}

void heart_beat() {
   int i,all;
   object *living;
   ::heart_beat();
   if( !objectp(TO) )
      return;
   if( !objectp(ETO) )
      return;
   count++;
   living = all_living(ETO);
   all = sizeof(living);
   for(i = 0;i < all;i++) {
      if(!userp(living[i]) && (string)living[i]->query_race() == "snake") {
         tell_room(ETO,"The "+living[i]->query_name()+"shivers and "+
            "drops dead as Naxterr snaps his finger.");
         living[i]->die();
      }
   }
   if( !(int)TO->query_stoneSkinned() && count >= 3 ) {
      new("/cmds/spells/s/_stoneskin")->use_spell(TO,"naxterr",40,100,"mage");
      count = 1;
   }
   if(blink_count < 1)
      blink_count = 50;
   if(blink_count == 50) {
      tell_room(ETO,"%^BOLD%^Naxterr speaks quickly to himself and looks "
         "around furtively.");
   }
   blink_count--;
   return;
}

void blow(object vic) {
   command("say "+vic->query_cap_name()+", let's see if you can handle "
      "this.");
   command("laugh "+vic->query_name());
   set_property("magic",1);
   tell_object(vic,"%^RED%^Naxterr shoots a strong energy blow at you!");
   if(SAVING_D->saving_throw(vic,"paralyzation_poison_death",-4)) {
      tell_room(ETO,"%^RED%^The blow zaps pass "+vic->query_cap_name()+
         " but still dealing some damage!",vic);
      tell_object(vic,"%^RED%^The blow zaps pass you!");
      vic->do_damage( "torso",30 + random(30) );
      tell_object(vic,"%^RED%^But it still deals some damage!");
   }
   else {
      tell_room(ETO,"%^RED%^The blow hits "+
         vic->query_cap_name()+" directly in torso!",vic);
      tell_object(vic,"%^RED%^The blow hits you directly in torso!");
      vic->do_damage( "torso",50 + random(50) );
      tell_object(vic,"%^RED%^You scream in pain!");
      tell_room(ETO,"%^RED%^"+vic->query_cap_name()+" screams in pain!",
         vic);
   }
   remove_property("magic");
}

void bash(object vic) {
   set_property("magic",1);
   tell_object(vic,"%^CYAN%^Naxterr waves his club madly and head-butts "
      "you!");
   tell_room(ETO,"%^CYAN%^Naxterr waves his club madly and head-butts "+
      vic->query_cap_name()+"!",vic);
   if(SAVING_D->saving_throw(vic,"paralyzation_poison_death",-5)) {
      tell_room(ETO,"%^BLUE%^BOOM! The club barely hits.");
      vic->do_damage( "head",30 + random(30) );
   }
   else {
      tell_room(ETO,"%^RED%^BONG! The club hits hard!");
      vic->do_damage( "head",50 + random(50) );
      vic->set_paralyzed(10 + random(5),"You faint by the bash!");
   }
   remove_property("magic");
}

void stabbed_func() {
   if(query_hp() < (query_max_hp()/4))
      tell_room(ETO,"%^BLUE%^Naxterr moves with agility and avoided most "
         "damage from the stab.");
      set_hp(query_max_hp()/4);
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
