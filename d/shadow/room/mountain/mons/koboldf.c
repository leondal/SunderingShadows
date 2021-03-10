//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

void kill_baddies(object targ);

void create() {
    ::create();
       set_name("kobold");
       set_id( ({ "kobold", "koboldf" }) );
       set("race", "kobold");
       set_gender("female");
       set_short("A threatening kobold");
       set_long( 
@STYX
This ugly little creature has beady red eyes and two small horns that protrude from the top of its head.  Almost lizardlike in appearance with large pointy ears, it has dark rusty-brown scaly hide and a long hairless tail but stands upright on two legs.  Long skinny fingers end in sharp-looking and pointy fingernails that look more like animal claws.  This one looks a little tougher than some who roam in packs.
STYX
   );
     set_class("fighter");
     set_class("cleric");
     set_hd(6,2);
     set_level(6);
     set_mlevel("fighter",6);
     set_mlevel("cleric",6);
     set_guild_level("cleric",6);
     set_body_type("human");
     set("aggressive", "hate_types");
     set_alignment(6);
     set_size(1);
     set_hp(55+random(15));
     set_overall_ac(7);
     set_stats("intelligence",6);
     set_stats("wisdom",16);
     set_stats("strength",15);
     set_stats("charisma",5);
     set_stats("dexterity",16);
     set_stats("constitution",12);
     set_wielding_limbs( ({ "right hand", "left hand" }) );
     set_monster_feats(({"parry"}));
     switch(random(3)) {
        case 0 : "/d/common/daemon/randgear_d"->arm_me(TO,"blunts",10,1);
        case 1 : "/d/common/daemon/randgear_d"->arm_me(TO,"blunts",40,1);
           break;
        case 2 : "/d/common/daemon/randgear_d"->arm_me(TO,"bluntm",20,1);
           break;
     }
     if(!random(4)) {
       new("/d/deku/armours/ring_p")->move(TO);
       command("wear ring");
     }
     if(random(5) < 4) {
       new(CMISC"sack")->move(TO);
       new(CMISC"climb_tool")->move(TO);
       new(CMISC"lantern")->move(TO);
       command("put tools in sack");
       command("put lantern in sack");
     }
     add_money("gold",random(50)+20);
     add_money("silver",random(150)+30);
     add_money("copper",random(520)+50);
//     set_exp(650);
     set_new_exp(8,"normal");
     set_moving(1);
     set_speed(80);
     set_property("swarm",1);
     set_spell_chance(75);
     set_spells(({"cause light wounds", "hold person", "limb attack", 
        "cause light wounds"}));
     set_achats(2, ({
        "%^RED%^The kobold hides around a corner and throws rocks.%^RESET%^",
        "%^RED%^The kobold's tail twitches as she jumps around.%^RESET%^",
        "%^RED%^The kobold waves her weapon meanacingly.%^RESET%^"
     }) );
	  set_emotes(3, ({"The kobold smirks and licks some blood from its weapon.", 
		  "The kobold's tail twitches as she swings her weapon at you.", 
		  "The kobold's beady red eyes seem to be sizing you up.", 
		  "The kobold darts past and seems to try to frighten you.",
		  "The kobold yelps loudly trying to scare you away.",
	  }),0 );
}

int hate_types(){
   if(wizardp(TP))          return 1;
   if(TP->query_invis())    return 1;
   if(!TO->query_invis())   kill_baddies(TP);
}

void kill_baddies(object targ) {
   string race;
   race = (string)targ->query_race();
   if(race == "human" || race == "elf" || race == "half-elf" || race == 
   "halfling" || race == "gnome") {
        force_me("say Ah, fresh "+targ->query_race()+" meat for the tribe!!");
        force_me("kill "+targ->query_name());
        return;
   }
   if(race == "drow" || race == "goblin" || race == "bugbear") {
      force_me("say You won't be makin' me a slave you "+targ->query_race()+"!!");
      force_me("kill "+targ->query_name());
      return;
   }
}
