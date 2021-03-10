//Updated description and mechanics - Octothorpe 8/14/09
//Coded by the one and only master of monsters...BANE//
// updated to use WEAPONLESS by Dinji & Styx 7/2003

#include <std.h>
inherit MONSTER;

void create(){
   object ob;
   object ob1;
    ::create();
    set_id(({"Thri-Kreen","thri","kreen","thri-kreen","thrikreen","laeradmon","magical beast" }));
    set_name("thri-kreen");
    set_short("%^ORANGE%^s%^YELLOW%^a%^RESET%^%^ORANGE%^nd%^YELLOW%^"+
	   "y%^RESET%^%^ORANGE%^-h%^YELLOW%^ue%^RESET%^%^ORANGE%^d thr"+
	   "%^YELLOW%^i%^RESET%^%^ORANGE%^-kr%^YELLOW%^ee%^RESET%^"+
	   "%^ORANGE%^n%^RESET%^");
    set_long("%^ORANGE%^This strange, insectoid creature resembles "+
	   "a praying mantis.  It reaches to a height just over seven feet, "+
	   "complete with a slightly oversized head for its size.  Two "+
	   "large, %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^%^BLACK%^mp%^RESET%^"+
	   "ou%^BOLD%^%^BLACK%^nd %^RESET%^%^ORANGE%^eyes dominate its "+
	   "head, perpetually gleaming, even in low light. This creature's "+
	   "mouth is a complex pair of mandibles, that appear to be as "+
	   "deadly as any other conventional weapon.  Its sandy-hued "+
	   "exoskeleton offers some camouflage in the desert wasteland.%^RESET%^");
    set_body_type("human");
    set_race("thri-kreen");
    set_gender("male");
    set_alignment(8);
    set_size(2);
    set_hd(17,5);
    set_max_level(22);
    set_hp(200);
	set_max_hp(query_hp());
	set_class("fighter");
	set_class("psion");
	set_mlevel("fighter",17);
	set_mlevel("psion",17);
	set_guild_level("fighter",17);
	set_guild_level("psion",17);
	add_search_path("/cmds/psionics");
    set_exp(12000);
	set_moving(1);
	set_speed(40);
	set_nogo(({"/d/laerad/wasteland/waste1"}));
    set_overall_ac(-4);
    set("aggressive",16);
    set_stats("strength",20);
    set_stats("dexterity",18);
    set_stats("intelligence",18);
    set_stats("wisdom",8);
    set_stats("constitution",13);
    set_stats("charisma",5);
	set_property("full attacks",1);
	set_spells(({"mind thrust","swarm of crystals","ultrablast"}));
	set_spell_chance(15);
	set_monster_feats(({"crushingstrike","blade block"}));
	set_funcs(({"bite","leap"}));
	set_func_chance(15);
    ob = new("/d/laerad/obj/gythka.c");
	ob->move(TO);
	ob->set_property("monsterweapon",1);
	if(!random(6)){
	   ob->set_property("monsterweapon",-1);
	}
	ob1 = new("/d/laerad/obj/harness.c");
	ob1->move(TO);
	ob1->set_property("monsterweapon",1);
	if(!random(6)){
	   ob1->set_property("monsterweapon",-1);
	}
    command("wield pike");
	command("wear harness");
        set_achats(5,({"The %^ORANGE%^thr%^YELLOW%^i%^RESET%^%^ORANGE%^-kr"+
	   "%^YELLOW%^ee%^RESET%^%^ORANGE%^n%^RESET%^ chitters angrily in "+
	   "its unintelligible language.",
	   "With great agility, the %^ORANGE%^thr%^YELLOW%^i%^RESET%^"+
	   "%^ORANGE%^-kr%^YELLOW%^ee%^RESET%^%^ORANGE%^n%^RESET%^ leaps "+
	   "about during the fray!"}));
        set_emotes(5,({"The %^ORANGE%^thr%^YELLOW%^i%^RESET%^%^ORANGE%^-kr"+
	   "%^YELLOW%^ee%^RESET%^%^ORANGE%^n's%^RESET%^ antennae twitch "+
	   "inquisitively.",
	   "The %^ORANGE%^thr%^YELLOW%^i%^RESET%^%^ORANGE%^-kr%^YELLOW%^ee"+
	   "%^RESET%^%^ORANGE%^n%^RESET%^ readjusts a strap on his harness."}),0);
}

void init(){
   string mrace=TP->query_race();
   ::init();
   if(TP->query_invis()) return;
   if(mrace == "elf" || mrace == "drow"){
      command ("kill "+TPQN);
   }
   return;
}

void bite(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   tell_object(targ,"%^BOLD%^%^WHITE%^The snapping mandible of the "+
      "%^ORANGE%^thr%^YELLOW%^i%^RESET%^%^ORANGE%^-kr%^YELLOW%^ee"+
	  "%^RESET%^%^ORANGE%^n %^BOLD%^%^WHITE%^finds its target!");
   tell_room(ETO,"%^BOLD%^%^WHITE%^The snapping mandible of the "+
      "%^ORANGE%^thr%^YELLOW%^i%^RESET%^%^ORANGE%^-kr%^YELLOW%^ee"+
	  "%^RESET%^%^ORANGE%^n %^BOLD%^%^WHITE%^finds an unarmored spot "+
	  "on "+targ->QCN+"!",targ);
   targ->do_damage(targ->return_target_limb(),random(20)+4);
   if(!"/daemon/saving_throw_d.c"->fort_save(targ,-15)){
      tell_object(targ,"%^BOLD%^%^GREEN%^The bite introduces a painful "+
	     "poison that begins paralyzing your body!%^RESET%^");
	  targ->add_poisoning(10);
	  targ->set_paralyzed(random(6),"%^RED%^You are paralyzed from the poison!%^RESET%^");
   }
   return;
}

void leap(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   tell_object(targ,"%^BOLD%^%^WHITE%^The %^ORANGE%^thr%^YELLOW%^i"+
      "%^RESET%^%^ORANGE%^-kr%^YELLOW%^ee%^RESET%^%^ORANGE%^n "+
	  "%^BOLD%^%^WHITE%^pushes off its legs and pounces on you!");
   tell_room(ETO,"%^BOLD%^%^WHITE%^The %^ORANGE%^thr%^YELLOW%^i"+
      "%^RESET%^%^ORANGE%^-kr%^YELLOW%^ee%^RESET%^%^ORANGE%^n "+
	  "%^BOLD%^%^WHITE%^pushes off its legs and pounces on "+
	  ""+targ->QCN+"!",targ);
   targ->do_damage(targ->return_target_limb(),random(20)+4);
   return;
}

void die(object ob){
   object ob2;
   if(!random(6)){
      ob2 = new("/d/laerad/obj/thri_head.c");
      ob2->move(TO);
   }
   ::die();
}
