#include "/d/dagger/aketon/short.h"

inherit WANDER;

object *bad_list;

void create() {
   ::create();
   set_name("aketon city guard");
   set_id( ({"guard","city guard"}) );
   set("race","elf");
   set_gender("male");
   set_short("city guard");
   set_long("This guard is assigned by the Aketon government to guard "
      "the city from intruders and all sorts of criminals as well as "
      "protect the citizens of the city.");
   set_level( random(13) + 18 );
   set_hd(query_level(),4);
   set_hp(query_level() * 10);
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel( "fighter",query_hd() );
   set_guild_level( "fighter",query_hd() );
   add_search_path("/cmds/fighter");
   set_class("cleric");
   set_mlevel( "cleric",query_hd() );
   set_guild_level( "cleric",query_hd() );
   set_spells( ({"limb attack",
      "call lightning",
      "cause critical wounds",
      "cause serious wounds"}) );
   set_spell_chance(100);
   set_body_type("human");
   set("aggressive",0);
   set_alignment(2);
   set_size(2);
   set_exp(query_hd() * 200);
   set_property("swarm",1);
   set_property("no steal",1);
   set_property("full attacks",1);
   set_stats("intelligence",12);
   set_stats("wisdom",20);
   set_stats("strength",20);
   set_stats("charisma",5);
   set_stats("dexterity",20);
   set_stats("constitution",8);
   set_overall_ac(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   new(ARMORPATH+"chain")->move(TO);
   command("wearall");
   add_money( "electrum",random(20) );
   add_money( "silver",random(30) );
   add_money( "gold",random(30) );
   bad_list = ({});
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
      member_array(victim,bad_list) == -1 && !random(50) ) {
      bad_list += ({victim});
      new("/cmds/spells/a/_animate_object")->use_spell( TO,victim->query_name(),query_level(),100,"cleric" );
   }
   hold = ::kill_ob(victim,which);
   return hold;
}

void init() {
   ::init();
   if( wizardp(TP) )
      return;
   if( (string)TP->query_race() == "human" && !random(10)
      && !TP->query_invis() ) {
      command("say You are not welcomed here "+TPQCN+"!");
      command("rush "+TPQN);
   }
}

int test_heart() {
   return 1;
}
