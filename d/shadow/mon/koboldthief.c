//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//koboldthief - for new Kobold lair in DD caves.  Circe 6/8/04
#include <std.h>
#include "/d/common/common.h"
#include "/d/shadow/room/cave/ddcaves.h"

inherit MONSTER;

void create() {
object obj;
int droll;
   ::create();
   set_name("kobold thief");
   set_id(({"kobold","thief","kobold thief","rogue","sneaky kobold","monster","cave kobold","sneaky little kobold"}) );
   set_race("kobold");
   set_gender(random(2)?"male":"female");
   set_short("A sneaky little kobold");
   if((string)TO->query_gender() == "female"){
      set_long("This small reptilian humanoid stands just under "+
         "three feet tall.  Her scaly skin is a light tan color with "+
         "deep russet patches, though that could be dirt.  She has "+
         "beady eyes the striking color of rubies, and her gnarled "+
         "fingers end in short claws.  She is wearing what was "+
         "perhaps the dress of a human child at one time, though "+
         "it is little more than rags now.  She wears a leather "+
         "pouch at her side, bursting with various rusted tools.");
   }else{
      set_long("This small reptillian humanoid stands just under "+
         "three feet tall.  His scaly skin is a deep chestnut color with "+
         "darker russet patches, though that could be dirt.  He has "+
         "beady eyes the striking color of topaz, and his gnarled "+
         "fingers end in short claws.  He is wearing a filthy vest "+
         "over torn and faded pants, though "+
         "they are little more than rags now.  He wears a leather "+
         "pouch at his side, bursting with various rusted tools.");
   }
   set_level(10);
   set_hd(10,1);
   set_hp(random(15)+100);
   set_body_type("human");
   set("aggressive","aggfunc");
   set_alignment(3);
   set_class("thief");
   set_mlevel("thief",10);
   add_search_path("/cmds/thief");
   set_guild_level("thief",10);
   set_class("fighter");
   set_mlevel("fighter",10);
   set_guild_level("fighter",10);
   add_search_path("/cmds/fighter");
   set_scrambling(1);
   if(!random(4)) set_property("full attacks",1);
   set_size(1);
   set_overall_ac(2);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",14);
   set_stats("charisma",3);
   set_stats("dexterity",16);
   set_stats("constitution",7);
   set_max_hp(query_hp());
   set_wielding_limbs( ({ "right hand", "left hand"}) );
   "/d/common/daemon/randgear_d"->arm_me(TO,"edgeds",10,1,50);
   "/d/common/daemon/randgear_d"->arm_me(TO,"edgeds",10,1,50);
   set_monster_feats(({
	  "dodge",
      "mobility",
	  "evasion",
	  "combat reflexes",
	  "parry"
   }));    
   switch(random(9)){
      case 0..3:  obj = new(CARMOR"leather");
                  if(!random(6)){
                     obj->set_property("enchantment",1);
                  }
                  obj->move(TO);
                  command("wear leather");
                  break;
      case 4:  obj = new(CARMOR"studded");
                  if(!random(6)){
                     obj->set_property("enchantment",1);
                  }
                  obj->move(TO);
                  command("wear studded");
                  break;
      case 5:  obj = new(CARMOR"bracers");
                  if(!random(4)){
                     obj->set_property("enchantment",1);
                  }
                  obj->move(TO);
                  command("wear bracers");
                  break;
      case 6:  obj = new("/d/deku/armours/ring_p");
                  obj->move(TO);
                  command("wear ring");
                  break;
      case 7..8:  break;
   }
   if(!random(5)){
      droll = random(2)+2;
      obj = new("/d/magic/scroll");
      obj->set_av_spell(droll);
      obj->move(TO);
   }
//adjusted scroll level and frequency - trying to tone down and balance
//Circe 8/23/04
   if(!random(6)){
      new(CMISC"thief_tools")->move(TO);
   }
   add_money("silver",random(50));
   add_money("gold",random(50)+25);
   //set_exp(500);
//   set_exp(6000);
   set_new_exp(10,"normal");
   set_max_level(12);
   force_me("speech bark");
   switch(random(20)){
      case 0: new(DDOBJ"electrumring")->move(TO);
              command("wear ring");
              break;
      case 1: new(DDOBJ"leatherring")->move(TO);
              command("wear ring");
              break;
      case 2: new(DDOBJ"lightningring")->move(TO);
              command("wear ring");
              break;
      case 3: new(DDOBJ"glassmedallion")->move(TO);
              command("wear medallion");
              break;
      case 4: new(DDOBJ"rosemedallion")->move(TO);
              command("wear medallion");
              break;
      case 5: new(DDOBJ"lavamedallion")->move(TO);
              command("wear medallion");
              break;
      case 6: new(DDOBJ"platinumwand")->move(TO);
              break;
      case 7: new(DDOBJ"granitewand")->move(TO);
              break;
      case 8: new(DDOBJ"stormwand")->move(TO);
              break;
      default: break;
   }
}

int aggfunc(){
   object shape;
   string mrace;
   if(TP->query_invis()) return 1;

   mrace = TP->query_race();
   if(objectp(shape = TP->query_property("shapeshifted"))) mrace = (string)shape->query_shape_race();

   if(mrace == "kobold"){
      force_me("say Where you goin'?  You're supposed to be on guard!");
      force_me("emoteat "+TPQN+" smacks $N on the head and darts away.");
      return 1;
   }else{
      switch(random(4)){
         case 0:  
                  force_me("say Aiyee!!  How you get in here?!");
                  force_me("stab "+TPQN+"");
                  break;
         case 1:  force_me("say You think you're so smart?!");
                  force_me("rush "+TPQN+"");
                  break;
         case 2..3:  force_me("say You smell like orc!");
                     force_me("kill "+TPQN+"");
                     break;
      }
      force_me("say You die now, baddie "+mrace+"!");
      return 1;
   }
}
