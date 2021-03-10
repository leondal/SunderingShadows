#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit MONSTER;

create() {
   object obj;
   ::create();
   set_name("kronibus the skeletal warrior");
   set_id( ({"kronibus","skeleton","warrior","skeletal warrior"}) );
   set("short","Kronibus the Skeletal warrior");
   set("long","%^BOLD%^BLUE%^The skeleton warrior before you looks "+
       "magnificent. It stands about 6 feet tall with broad shoulders. "+
      "Its two eyes glows bright red and are filled with a sense of great "+
       "evil. It is the dead warriors who have adventured this lone "+
      "island before and fell dead in this deadly trapped chamber. The "+
      "anger and hatred of the lost souls never rest in peace. These "+
       "twisted and deformed remnants of the once great souls of this realm "+
      "resulted in this powerful undead creature.");
   set("race","skeleton");
   set_gender("neuter");
   set_body_type("humanoid");
   set_hd(40,8);
   set_overall_ac(0);
   set_size(2);
   set_class("fighter");
   set_mlevel("fighter",40);
   set_guild_level("fighter",40);
   set_alignment(9);
   set_stats("intelligence",18);
   set_stats("wisdom",18);
   set_stats("strength",22);
   set_stats("charisma",12);
   set_stats("dexterity",18);
   set_stats("constitution",18);
   set("aggressive",16);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_property("no death",1);
   set_property("no animate",1);
   set_property("magic",1);
   set_mob_magic_resistance("average");
   set_hp(420);
   set_max_hp( query_hp() );
   set_exp(30000);
   set_max_level(36);
   set_funcs( ({"flame_of_hell"}) );
   set_func_chance(40);
   add_money( "gold",1000+random(1000) );
   add_money( "silver",500+random(1000) );
   add_search_path("/cmds/fighter");
   obj = new("/d/shadow/obj/weapon/longsword");
   obj->set_property("enchantment",5);
   obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield sword in left hand");
   obj = new(OBJ+"shd_bskeletal");
   if(!random(3))
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   obj = new("/d/shadow/obj/armor/chain");
   obj->set_property("enchantment",3);
   obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wearall");
}

void init()
{
    ::init();
    if (wizardp(TP)) {
        return;
    }
    if (!userp(TP)) {
        return;
    }
    command("say %^BOLD%^BLUE%^You shall join my rank " + TPQCN + "!!!");
    TO->kill_ob(TP, 1);
    command("rush " + (string)TP->query_name());
}

void flame_of_hell(object *vic) {
   int i,all;
   vic = all_living(ETO);
   vic -= ({TO});
   all = sizeof(vic);
    tell_room(ETO,"%^RED%^All of a sudden Kronibus' eyes turns "+
      "blood red.");
    command("say %^BOLD%^BLUE%^Daemons of hell! Strengthen me!");
    command("say %^BOLD%^BLUE%^May the flames of the hell burn your soul "+
      "forever!");
   for(i = 0;i < all;i++) {
       tell_room(ETO,"%^RED%^Two enormous chains of flame strike out "+
          "from his eyes and dash towards everyone in the room!");
      vic[i]->do_damage( "torso",roll_dice(10,16) );
      tell_object(vic[i],"%^BOLD%^RED%^The flame burns you badly!");
   }
}

void die(object obj) {
   command("say %^BOLD%^BLUE%^Your soul cannot excape from this place, "+
      "NEVER!!");
   command("grin");
    tell_room(ETO,"%^BOLD%^BLUE%^As Kronibus uses up the last bits of "+
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
             "drops dead as Kronibus' eyes glow red.");
         living[i]->die();
      }
   }
   return;
}
