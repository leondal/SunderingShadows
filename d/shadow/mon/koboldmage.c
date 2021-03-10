//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//koboldmage - for new Kobold lair in DD caves.  Circe 6/8/04
#include <std.h>
#include "/d/common/common.h"
#include "/d/shadow/room/cave/ddcaves.h"

inherit MONSTER;

void create() {
object obj;
int droll;
   ::create();
   set_name("kobold mage");
   set_id(({"kobold","mage","kobold mage","rogue","kobold wizard","monster","cave kobold","scaly kobold"}) );
   set_race("kobold");
   set_gender(random(2)?"male":"female");
   set_short("A scaly kobold");
   if((string)TO->query_gender() == "female"){
      set_long("This small reptillian humanoid is surrounded by "+
         "an aura of unusual smells.  Sulfur, bat guano, and the "+
         "scent of moss seem to linger around her.  She wears a "+
         "long robe that drags the ground, which she seems rather "+
         "proud of, despite the holes in the material.  She keeps "+
         "the hood pulled up, leaving her face shrouded save for "+
         "the glittering red eyes beneath.  A battered leather "+
         "bag is at her side, along with a tattered old spellbook "+
         "she probably pulled off some dead explorer.");
   }else{
      set_long("This small reptillian humanoid is surrounded by "+
         "an aura of unusual smells.  Sulfur, bat guano, and the "+
         "scent of moss seem to linger around him.  He wears a "+
         "long robe that drags the ground, which he seems rather "+
         "proud of, despite the holes in the material.  He keeps "+
         "the hood pulled up, leaving his face shrouded save for "+
         "the glittering red eyes beneath.  A battered leather "+
         "bag is at his side, along with a tattered old spellbook "+
         "he probably pulled off some dead explorer.");
   }
   set_level(10);
   set_hd(10,1);
   set_hp(random(15)+80);
   set_body_type("human");
   set("aggressive","aggfunc");
   set_alignment(3);
   set_class("thief");
   set_mlevel("thief",10);
   add_search_path("/cmds/thief");
   set_guild_level("thief",10);
   set_class("mage");
   set_mlevel("mage",10);
   set_guild_level("mage",10);
   add_search_path("/cmds/mage");
   if(!random(5)) set_scrambling(1);
   set_size(1);
   set_overall_ac(2);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",16);
   set_stats("charisma",3);
   set_stats("dexterity",16);
   set_stats("constitution",7);
   set_max_hp(query_hp());
   if(!random(4)) set_mob_magic_resistance("average");
   set_wielding_limbs( ({ "right hand", "left hand"}) );
   set_monster_feats(({
	  "dodge",
      "mobility",
	  "evasion",
	  "combat reflexes"
   }));    
   switch(random(10)){
      case 0..3:  obj = new(CARMOR"robe");
                  obj->move(TO);
                  command("wear robe");
                  break;
      case 4:  obj = new("/d/shadow/room/cave/obj/rattyrobe");
                  if(!random(4)){
                     obj->set_property("enchantment",1);
                  }
                  obj->move(TO);
                  command("wear robe");
                  break;
      case 5:  obj = new(CARMOR"bracers");
                  if(!random(2)){
                     obj->set_property("enchantment",1);
                  }
                  obj->move(TO);
                  command("wear bracers");
                  break;
      case 6:  obj = new("/d/deku/armours/ring_p");
                  obj->move(TO);
                  command("wear ring");
                  break;
      case 7..9:  break;
   }
   if(!random(4)){
      droll = random(3)+2;
      obj = new("/d/magic/scroll");
      obj->set_av_spell(droll);
      obj->move(TO);
   }
//adjusted scroll level and frequency - trying to tone down and balance
//Circe 8/23/04
   if(!random(5)){
      "/d/common/daemon/randstuff_d"->find_stuff(TO,"component",random(6)+3);
   }
   add_money("silver",random(20));
   add_money("gold",random(10)+25);
   //set_exp(600);
//   set_exp(3600);
   set_new_exp(10,"normal");
   set_max_level(12);
   force_me("speech bark");
   set_spells(({"burning hands","magic missile","magic missile","magic missile","hold person"}));
   set_spell_chance(20);
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
      force_me("say Hey you!  Back to your post!");
      force_me("emoteat "+TPQN+" smacks $N on the head and darts away.");
      return 1;
   }else{
      force_me("say You taste my magicks, baddie "+mrace+"!");
      force_me("kill "+TPQN+"");
      return 1;
   }
}
