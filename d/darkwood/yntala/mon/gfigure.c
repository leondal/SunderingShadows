#include <std.h>
#include <daemons.h>
#include "/d/darkwood/yntala/yntala.h"
inherit MONSTER;
object ob,obj;


void create (){

::create ();
   set_name("%^BOLD%^%^WHITE%^Forest Ghost%^RESET%^");
   set_id(({"ghost","forest ghost","evil forest ghost","evil ghost","evil spirit","spirit"}));
   set_short("%^BOLD%^%^BLACK%^A ghostly figure%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This %^RESET%^t%^BOLD%^r%^RESET%^ans%^BOLD%^l%^RESET%^uc%^BOLD%^e%^RESET%^nt"
" %^BOLD%^spirit looks like %^BLACK%^death %^RESET%^itself.  Wearing a %^BOLD%^%^BLACK%^long black cape "
" %^RESET%^with the %^BOLD%^%^BLACK%^hood %^RESET%^pulled down low over its face, only a few ghostly bones"
" are visible.  %^BOLD%^%^BLACK%^An inky black darkness %^WHITE%^fills the eye sockets, and"
" though no eyes are visible, the creature is clearly looking straight at you.%^RESET%^");
   set_race("ghost");
   set_gender("male");
   set_body_type("humanoid");
   set_hd(40,2);
   set_overall_ac(-52);
   set_size(2);
   set_stats("intelligence",25);
   set_stats("strength",25);
   set_stats("wisdom",15);
   set_stats("dexterity",25);
   set_stats("constitution",15);
   set_stats("charisma",11);
   set_money("platinum",random(1000));
   set_money("gold",random(7000));
   set_money("silver",random(7500));
   set_money("copper",random(500));
   set_money("electrum",random(3000));
   set_class("mage");
   set_exp(10000);
   set_max_level(32);
   set_alignment(9);
   set_hp(random(1500)+2250);
   set_attacks_num(7);
   set_property("weapon resistance", 1);
   set_property("no steal", 1);
   set_property("no paralyze", 1);
   set_property("no tripped",1);
   set_property("no powder",1);
   set_max_hp(query_hp());  
   set_property("full attacks",1);
   set("aggressive","aggfunc");
   set_mlevel("mage",42);
   set_guild_level("mage",42);
   set_spell_chance(100);
   set_spells(({"lightning bolt","fireball","chain lightning","lower resistance","meteor swarm","hideous laughter","meteor swarm","greater shout","scorcher","scorcher","meteor swarm","scorcher","ice storm","storm of vengeance","chain lightning","chain lightning","ice storm","ice storm","storm of vengeance","wall of fire","wall of fire","chain lightning","chain lightning","chain lightning","phantom guardians","phantom guardians"}));
   set_mlevel("thief",32);
   set_guild_level("thief",40);
   add_search_path("/cmds/thief");
   set_thief_skill("move silently",95);
   set_thief_skill("hide in shadows",95);
   set_mob_magic_resistance("average");
   ob=new(OBJD+"gdagger.c");
   ob->move(TO);
   ob->set_property("enchantment",1);
   ob->set_property("monsterweapon",1);
   command("wield dagger");
   new(OBJD+"blackcloak.c")->move(TO);
   command("wear cloak");
   new("/d/laerad/obj/bracers5.c")->move(TO);
   command("wear bracers");
//   ob = new("/d/magic/scroll");
//   ob->set_av_spell(8-random(2));
   ob->move(TO);
   obj=new("/d/common/obj/potion/legendary_heal.c");
   obj->move(TO);
   obj->set_uses(60);
   set_property("knock unconscious",1);
   set_monster_feats(({ "perfect caster","spell penetration","greater spell penetration","spell power","improved spell power","greater spell power", "resistance", "improved resistance", "scramble","damage resistance","improved damage resistance","regeneration","powerattack","rush" }));
}
int aggfunc(object target) {
    if(!interactive(TP)) { return 0; }
  force_me("emote shimmers into view right in front of you.");
  force_me("emote laughs in a dry, dark tone.");
if(TP->query_highest_level()<18){
     force_me("emoteat "+TPQN+ " takes one last glance at $N and shakes his head.");
      force_me("say %^BOLD%^%^BLACK%^You are not worthy of my attention little one, best you keep going before something very bad happens to you.");
      return 0;
   }
  force_me("say %^BOLD%^%^BLACK%^'%^RESET%^%^BLUE%^The powers that have created this forest have also created me, little one.  For they fear you will inbalance the evils of this forest... So they created me, Tluklengrie to ensure you cannot do that.  I think I will enjoy some of your things while you ponder not wasting your time on something clearly beneath your skill.%^BOLD%^%^BLACK%^'");
   call_out("follower",1); //added this to get them to follow
   force_me("kill "+TPQN+ "");
   force_me("cast phantom guardians on soldiers");
   call_out("spell_effect",1);
   switch(random(3)){
      case 0..1:
      break;
      case 2:
      ETO->set_property("no teleport",1);
      break;
   }
   force_me("scramble");
}
int spell_effect(){
   force_me("watch");
   new("/cmds/spell/b/_blink.c")->use_spell(TO, TO,30,100,"mage");
   new("/cmds/spell/s/_stoneskin.c")->use_spell(TO, TO,30,100,"mage");
}
int follower(){
   TP->add_follower(TO);
}

void heart_beat() {
   object *livings;
   int i,j;
  ::heart_beat();
   if (!objectp(TO)) return;
   if (!objectp(ETO)) return;
   livings = ({});
   livings =filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
   j = sizeof(livings); 
   for(i=0;i<j;i++){
      if(livings[i]->query_unconscious()){
         force_me("strip "+livings[i]->query_name()+" of armor");
      force_me("strip "+livings[i]->query_name()+" of money");
      force_me("strip "+livings[i]->query_name()+" of bracers");
      force_me("strip "+livings[i]->query_name()+" of cloak");
      force_me("strip "+livings[i]->query_name()+" of amulet");
      force_me("strip "+livings[i]->query_name()+" of sheath");
   //force_me("strip "+livings[i]->query_name+" of ring");
         force_me("strip "+livings[i]->query_name()+" of sack");
         force_me("strip "+livings[i]->query_name()+" of sack");
         force_me("strip "+livings[i]->query_name()+" of sack");
         force_me("strip "+livings[i]->query_name()+" of sack");
         force_me("strip "+livings[i]->query_name()+" of sack");
         force_me("strip "+livings[i]->query_name()+" of robes");
         force_me("strip "+livings[i]->query_name()+" of money");
         force_me("strip "+livings[i]->query_name()+" of components bag");
     call_out("kick_em",5);
   /*
      force_me("emoteat "+livings[i]->query_name()+" picks $N up and drop kicks $), sending $O flying.");
         switch(random(3)){
            case 0:
               tell_room(find_object_or_load("/d/darkwood/tabor/room/math2.c"),"%^BOLD%^%^BLACK%^"+livings[i]->query_name()+" comes flying in and lands limply on the ground with a THUMP!!%^RESET%^");
               livings[i]->move_player("/d/darkwood/tabor/room/math2.c");
            break;
            case 1:
               tell_room(find_object_or_load(INRMS+"forest33.c"),"%^BOLD%^%^BLACK%^"+livings[i]->query_name()+" comes flying in and lands limply on the ground with a THUMP!!%^RESET%^");
               livings[i]->move_player(INRMS+"forest33.c");
            break;
            case 2:
               tell_room(find_object_or_load(INRMS+"forestpath.c"),"%^BOLD%^%^BLACK%^"+livings[i]->query_name()+" comes flying in and lands limply on the ground with a THUMP!!%^RESET%^");
               livings[i]->move_player(INRMS+"forestpath.c");
            break;
         }
 */
      }
   }
   switch(random(50)){
      case 0..48:
         break;
      case 49:
      if(sizeof(TO->query_attackers()) == 0){
      force_me("emote cackles insanely as he disappears into the forest!");
      TO->move("/d/shadowgate/void");
      remove();
      break;
      }
   return 0;
}
   if (!objectp(TO)) return;
   if (!objectp(ETO)) return;
if(query_hp()<2500 && present("vial",TO)){
   command("open vial");
   command("drink vial");
    command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   }
}
void kick_em(){
   object *livings;
   int i,j;
   livings=({});
   livings=filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
   j= sizeof(livings);
   for(i=0;i<j;i++){
      force_me("emoteat "+livings[i]->query_name()+" picks $N up and drop kicks $O, sending $O flying.");
      switch(random(3)){
         case 0:
tell_room(find_object_or_load("/d/darkwood/tabor/room/math2.c"),"%^BOLD%^%^BLACK%^"+livings[i]->query_name()+" comes flying in and lands limply on the ground with a THUMP!!");
         livings[i]->move_player("/d/darkwood/tabor/room/math2.c");
         break;
      case 1:
tell_room(find_object_or_load(INRMS+"forest33.c"),"%^BOLD%^%^BLACK%^"+livings[i]->query_name()+" comes flying in and lands limply on the ground with a THUMP!!");
         livings[i]->move_player(INRMS+"forest33.c");
         break;
      case 2:
         tell_room(find_object_or_load(INRMS+"forestpath.c"),"%^BOLD%^%^BLACK%^"+livings[i]->query_name()+" comes flying in and lands limply on the ground with a THUMP!!");
         livings[i]->move_player(INRMS+"forestpath.c");
       break;
         }
   }
}
