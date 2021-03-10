//Octothorpe (12/13/09)
//Attaya, Necrophidius
//Original by Thundercracker

#include <std.h>
inherit WEAPONLESS;

void create(){
      object ob;
   ::create();
   set_name("necrophidius");
   set_id(({"necrophidius","snake","giant"}));
   set_short("%^BOLD%^%^WHITE%^in%^BOLD%^%^BLACK%^s%^BOLD%^%^WHITE%^id"+
      "%^BOLD%^%^BLACK%^io%^BOLD%^%^WHITE%^us nec%^BOLD%^%^BLACK%^r"+
	  "%^BOLD%^%^WHITE%^oph%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^diu%^BOLD%^%^BLACK%^s%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This creature is a construct composed "+
      "of an animated skeleton of a giant snake.  A fanged, humanoid "+
	  "skull is found at the apex of the spine.  The body of the "+
	  "necrophidius measures just over seven feet in length.%^RESET%^");
   set_race("necrophidius");
   set_hd(20,10);
   set_level(20);
   set_size(2);
   set_overall_ac(-5);
   set_class("fighter");
   set_guild_level("fighter",20);
   set_max_hp(220+random(80));
   set_speed(30);
   set_hp(query_max_hp());
   set_wielding_limbs(({"right claw","left claw"}));
   set_attacks_num(2);
   add_limb("fangs","fangs",96,1,4);
   set_attack_limbs(({"fangs", "tail"}));
   set_base_damage_type("piercing");
   set_damage(2,6);
   set_body_type("snake");
   set_property("swarm",1);
   set_property("no bump",1);
   set_stats("strength",20);
   set_stats("dexterity",16);
   set_stats("constitution",17);
   set("aggressive",25);
   set_mob_magic_resistance("average");
   set_funcs(({"bedazzle"}));
   set_func_chance(15);
   set_exp(10000);
   set_max_level(36);
   set_alignment(9);
   command("message in slithers in.");
   command("message out slithers to the $D.");   
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("bone dust");
      ob->move(TO);
    }  
   set_resistance("negative energy",15);
   set_resistance("positive energy",-15);
}

void die(object ob){
   tell_room(ETO,"%^BOLD%^The necrophidius collapses to the ground "+
      "and spasms violently.");
   ::die(ob);
}
void init(){
   string mrace=TP->query_race();
   ::init();
   if(wizardp(TP)) return;
   if(TP->query_true_invis()) return;
   if(!mrace == "undead"){
      tell_room(ETO,"%^BOLD%^The necrophidius rises to strike...%^RESET%^");
      call_out("bedazzle",0);
   }
}
void bedazzle(object targ){
   object *inv;
   int i;
   if(!targ) return 0;
   if(random(21)>targ->query_stats("strength")){ 
   //if(!"daemon/saving_d"->saving_throw(TP,"paralyzation_poison_death",-3)) { -need to find something more fair to all levels first -tsera
      targ->cease_all_attacks();
	  inv = all_inventory(environment(targ));
	  for(i = 0;i<sizeof(inv);i++){
	     if(!living(inv[i])) continue;
		 if(targ == inv[i]) continue;
		 inv[i]->remove_attacker(targ);
      }
	  tell_room(ETO,"%^MAGENTA%^The necrophidius begins to glimmer "+
	     "and sway.%^RESET%^");
	  tell_room(ETO,"%^MAGENTA%^The necrophidius bobs back and forth "+
	     "rhythmically...%^RESET%^");
	  tell_room(ETO,"%^BOLD%^%^BLUE%^The necrophidius bedazzles "+
	     ""+targ->QCN+"!%^RESET%^",targ);
	  tell_object(targ,"%^BOLD%^%^BLUE%^The necrophidius bedazzles "+
	     "you!%^RESET%^");
	  targ->force_me("drop all");
	  targ->set_paralyzed(random(30)+10,"%^YELLOW%^You gaze helplessly "+
	     "at the dancing form.%^RESET%^");
	  tell_room(ETO,"%^BOLD%^In a trance, "+targ->QCN+" walks up to "+
	     "the necrophidius.%^RESET%^",targ);
	  tell_object(targ,"%^BOLD%^%^CYAN%^You will do anything that "+
	     "this beautiful creature desires.%^RESET%^");
	  tell_object(targ,"%^BOLD%^%^CYAN%^A voice whispers: %^RESET%^"+
	     "Come to me...%^RESET%^");
	  command("get all");
	  return;
   }
   else {
      tell_room(ETO,"%^BOLD%^The necrophidius begins to glimmer and "+
	     "sway.%^RESET%^");
	  tell_object(targ,"%^BOLD%^You turn away quickly!%^RESET%^");
   }
}
