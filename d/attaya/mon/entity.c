//Octothorpe (12/13/09)
//Attaya, Skeletal Entity
//Original by Thundercracker

#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("skeletal entity");
   set_id(({"skeletal entity","entity","skeleton"}));
   set_short("%^BOLD%^%^WHITE%^gh%^RESET%^o%^BOLD%^%^WHITE%^stly "+
      "skeletal %^RESET%^e%^BOLD%^%^WHITE%^nt%^RESET%^i%^BOLD%^"+
	  "%^WHITE%^t%^RESET%^y");
   set_long("%^BOLD%^%^WHITE%^This entity is a skeletal figure in a "+
      "ghostly form.  The skull is clearly defined, but the rest of "+
	  "the skeletal frame seems to dissolve into the air.  The skull's "+
	  "eye sockets are engulfed with a radiant, %^RESET%^s%^BOLD%^i"+
	  "%^RESET%^lv%^BOLD%^e%^RESET%^r %^BOLD%^flame.");
   set_gender("male");
   set_hd(16,6);
   set_size(2);
   set_overall_ac(-10);
   set_class("fighter");
   set_guild_level("fighter",16);
   set_max_hp(150+random(100));
   set_hp(query_max_hp());
   set_wielding_limbs(({"right hand","left hand"}));
   set_body_type("human");
   set_race("undead");
   set_property("swarm",1);
   set_moving(1);
   set("aggressive",25);
   set_speed(90);
   set_property("no_bump",1);
   set_stats("dexterity",18);
   set_stats("constitution",17);
   set_stats("strength",22);
   set_stats("intelligence",3);
   set_stats("wisdom",3);
   set_stats("charisma",3);
   set_mob_magic_resistance("average");
   set_property("weapon resistance",2+random(2));
   set_alignment(2);
   set_new_exp(35,"high");;
   set_funcs(({"desoul"}));
   set_func_chance(15);
   command("message in flies in slowly.");
   command("message out flies slowly to the $D.");
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void init(){
   string mrace=TP->query_race();
   ::init();
   if(TP->query_true_invis()) return;
   if(mrace == "undead" || mrace == "necrophidius" || mrace == "snake" || mrace == "demonic entity" || mrace == "wyvern" || mrace == "influence" || mrace == "king scorpion" || mrace == "will-o-wisp" || mrace == "toc'lahar" || mrace == "elemental") return;
   if(TP->query_invis()){
      tell_room(ETO,"%^BOLD%^%^BLACK%^You feel a hush like a shadow "+
	     "fall upon you!%^RESET%^");
   }
   tell_room(ETO,"%^RED%^The skeletal entity lets out a %^BOLD%^%^RED%^"+
      "blood%^RESET%^%^RED%^-curdling scream, and flies towards "+
	  ""+TP->QCN+"!%^RESET%^",TP);
   tell_object(TP,"%^RED%^The skeletal entity lets out a %^BOLD%^%^RED%^"+
      "blood%^RESET%^%^RED%^-curdling scream, and flies towards "+
	  "you!%^RESET%^");
}

void die(object ob){
   tell_room(ETO,"%^BOLD%^With a horrible shriek, the skeletal entity "+
      "disperses into nothingness.%^RESET%^");
   TO->remove();
}

void desoul(object targ){
   string dam;
   set_property("magic",1);
   if("/daemon/saving_throw_d.c"->fort_save(targ,-20)){
      dam="hurts";
   }
   else{
      dam="poisons";
   }
   tell_object(targ,"%^BOLD%^%^BLUE%^You suddenly scream in pain as "+
      "the skeletal entity bites into your neck and "+dam+" "+
	  "you!%^RESET%^");
   tell_room(ETO,"%^BLUE%^You watch helplessly as "+targ->QCN+" is "+
      "bitten in the neck by the skeletal entity!%^RESET%^",targ);
   if(dam=="poisons"){
	  targ->do_damage("torso",roll_dice(6,12));
      targ->add_poisoning(50);
	  tell_object(targ,"%^MAGENTA%^An ancient virus flows into your "+
	     "body and you collapse!%^RESET%^");
	  targ->set_paralyzed(random(30)+10,"%^BOLD%^%^RED%^You feel your "+
	     "blood boiling in your veins!%^RESET%^");
   }
   else{
      targ->do_damage("torso",roll_dice(3,12));
   }
   remove_property("magic");
   return;
}
