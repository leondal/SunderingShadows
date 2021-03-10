#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit MONSTER;

create() {
   object obj;
   ::create();
   set_name("fernibus the skeletal warrior");
   set_id( ({"fernibus","skeleton","warrior","skeletal warrior"}) );
   set("short","Fernibus the Skeletal warrior");
   set("long","%^BOLD%^BLUE%^The skeleton warrior before you looks "+
      "magnificent. It stands about 6 feets tall with a broad shoulder. "+
       "Its two eyes glows bright red and are filled with a sense of great "+
       "evil. It is one of the warriors who had adventured this lone "+
      "island before and fell dead in this deadly trapped chamber. The "+
      "anger and hatred of the lost souls never rest in peace. These "+
       "twisted and deformed of the once great souls of this realm "+
      "resulted in this powerful undead creature.");
   set("race","skeleton");
   set_gender("neuter");
   set_body_type("humanoid");
   set_hd(45,8);
   set_overall_ac(-10);
   set_size(2);
   set_class("ranger");
   set_mlevel("ranger",45);
   set_guild_level("ranger",45);
   set_alignment(9);
   set_stats("intelligence",25);
   set_stats("wisdom",18);
   set_stats("strength",25);
   set_stats("charisma",14);
   set_stats("dexterity",20);
   set_stats("constitution",18);
   set("aggressive",16);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_property("no rush",1);
   set_property("no death",1);
   set_property("no animate",1);
   set_property("magic",1);
   set_mob_magic_resistance("average");
   set_hp(480);
   set_max_hp( query_hp() );
   set_exp(40000);
   set_max_level(36);
   set_funcs( ({"flame_of_hell"}) );
   set_func_chance(40);
   add_money( "gold",2000+random(1000) );
   add_money( "silver",100+random(1000) );
   obj = new("/d/shadow/obj/weapon/longsword");
   obj->set_property("enchantment",5);
   obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield sword in left hand");
   obj = new("/d/shadow/obj/weapon/longsword");
   obj->set_property("enchantment",5);
   obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield sword in right hand");
   obj = new("/d/shadow/obj/armor/studded");
   obj->set_property("enchantment",3);
   obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wearall");
}

void init() {
   ::init();
   if( wizardp(TP) )
      return;
   if( TP == present("horse") ){
       tell_room(ETO,"%^BOLD%^BLUE%^The horse fell immediately dead as "+
          "the skeletal warrior's eyes began to glow!");
      TP->die(TO);
   }
   if( !interactive(TP) )
      return;
   command("say %^BOLD%^BLUE%^Your soul will strengthen me further, "+
      TPQCN+"!!!");
   command("say %^BOLD%^BLUE%^I can feel the hatred in you, come on, "+
      "join us now, you foolish mortal!");
   TO->kill_ob(TP,1);
}

void flame_of_hell(object *vic) {
   int i,all;
   vic = all_living(ETO);
   vic -= ({TO});
   all = sizeof(vic);
   tell_room(ETO,"%^RED%^Out of a sudden, Fernibus' eyes turns "+
      "blood red.");
   command("say %^BOLD%^BLUE%^Daemons of the hell! Strengthen me!");
    command("say %^BOLD%^BLUE%^May the flames of hell burn your soul "+
      "forever!");
   for(i = 0;i < all;i++) {
       tell_room(ETO,"%^RED%^Two enormous chains of flame strike out "+
         "from his eyes and dashes at everyone in the room!");
      vic[i]->do_damage( "torso",roll_dice(10,20) );
      tell_object(vic[i],"%^BOLD%^RED%^The flame burns you badly!");
   }
}

void die(object obj) {
   command("say %^BOLD%^BLUE%^No one can leave this cursed place, not "+
       "even as one powerful as you!!");
   command("grin");
   tell_room(ETO,"%^BOLD%^BLUE%^As Fernibus used up that last bit of "+
      "energy, it turns back into bones.");
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
            "drops dead as Fernibus' eyes glows red.");
         living[i]->die();
      }
   }
   return;
}
