#include <std.h>
#include <daemons.h>
#include "/d/islands/argentrock/argabbr.h"

inherit MONSTER;

create() {
   object obj;
   ::create();
   set_name("jarkunish the great skeletal warrior");
   set_id( ({"jarkunish","skeleton","warrior","skeletal warrior"}) );
   set("short","Jarkunish the Great skeletal warrior");
   set("long","%^BOLD%^BLUE%^The great skeleton warrior before you looks "+
      "magnificent. He stands over 10 feet tall and holds two swords. His "+
      "eye sockets are hollow yet radiate a strange blue arua. You get "+
      "a sense of peace when you look through his eyes. It is the fallen "+
       "warriors who have adventured this lone island before and been "+
      "defeated by this creation of good souls combined their power of "+
       "the good and might. The creature is the symbol of the good side "+
      "of the realms. He will fight all the evil forces he encounters "+
      "yet test the combat skills of the good in heart. He has a job "+
       "assigned by the gods to guard the sacred Great sword of Light.");
   set("race","skeleton");
   set_gender("male");
   set_body_type("humanoid");
   set_hd(50,8);
   set_overall_ac(-16);
   set_size(3);
   set_class("ranger");
   set_mlevel("ranger",60);
   set_guild_level("ranger",60);
   set_alignment(1);
   set_stats("intelligence",20);
   set_stats("wisdom",25);
   set_stats("strength",25);
   set_stats("charisma",18);
   set_stats("dexterity",25);
   set_stats("constitution",22);
   set("aggressive",16);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_property("no death",1);
   set_property("no animate",1);
   set_property("no steal",1);
   set_property("magic",1);
   set_property("no web",1);
   set_property("no bow",1);
   set_mob_magic_resistance("average");
   set_property("weapon resistance",3);
   set_hp(1200);
   set_max_hp( query_hp() );
   set_exp(65000);
   set_max_level(36);
   set_funcs( ({"flame_of_heaven",
      "holy_cross"}) );
   set_func_chance(60);
   add_money( "gold",2000+random(1000) );
   obj = new(OBJ+"sword_light");
   obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield sword in left hand");
   obj = new(OBJ+"sword_light");
   obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield sword in right hand");
   obj = new("/d/shadow/obj/armor/studded");
   obj->set_property("enchantment",3);
   obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wearall");
   new(OBJ+"shd_gskeletal")->move(TO);
}

void flame_of_heaven(object *vic) {
   int i,all;
   vic = all_living(ETO);
   vic -= ({TO});
   all = sizeof(vic);
    tell_room(ETO,"%^RED%^All of a sudden Jarkunish's eyes turn blood "+
      "red.");
   command("say %^RED%^Taste the flame of heaven!");
   for(i = 0;i < all;i++) {
       tell_room(ETO,"%^RED%^Two enormous chains of flame strike out "+
          "from his eyes and dash towards everyone in the room!");
      vic[i]->do_damage( "torso",roll_dice(15,20) );
      tell_object(vic[i],"%^BOLD%^RED%^The flame burns you badly!");
   }
}

void holy_cross(object vic) {
   tell_room(ETO,"%^BLUE%^Jarkunish steps aside from you and put his two "+
      "swords in a cross position.");
   command("say %^RED%^Master of the world bless me with thy power!");
   tell_object(vic,"%^BLUE%^The two swords emit a blue cross at you!");
   tell_room(ETO,"%^BLUE%^The two swords emit a blue cross at "+
      vic->query_cap_name()+"!",vic);
   vic->do_damage( "torso",roll_dice(12,20) );
   if( !SAVING_D->saving_throw(vic,"rod_staff_wand") )
      vic->set_paralyzed(random(20) + 30,"%^BLUE%^The blue cross holds "+
         "you in position.");
}

void die(object obj) {
   object who;
   who = TO->query_current_attacker();
   if( ALIGN->is_good(who) )
       command("say %^BOLD%^BLUE%^You have proven your mastery in the "+
          "art of combat, yet you still have to master the sacred sword itself.");
   if( ALIGN->is_evil(who) ) {
      command("say %^BOLD%^BLUE%^You are the offspring of the ancient "+
          "demons, even though you have defeated me, you cannot master the holy "+
         "sword itself!");
      command("cackle");
   }
   if( ALIGN->is_neutral(who) )
      command("say %^BOLD%^BLUE%^You have achieved mastery in combat, "+
          "you may have a glance at the holy sword, be warned, you need "+
         "the acceptance of the spirits within the sword.");
    tell_room(ETO,"%^BOLD%^BLUE%^As Jarkunish uses up that last bit of "+
       "energy, he turns back into bones.");
   :: die(obj);
}

void heart_beat() {
   int i,all;
   object *living;
   ::heart_beat();
   if( !objectp(TO) )
      return;
   if( !objectp(ETO) )
      return;
   living = all_living(ETO);
   all = sizeof(living);
   for(i = 0;i < all;i++) {
      if(!userp(living[i]) && (string)living[i]->query_race() == "snake") {
         tell_room(ETO,"The "+living[i]->query_name()+"shivers and "+
            "drops dead as Jarkunish's eyes glow red.");
         living[i]->die();
      }
   }
   return;
}
