//Updated to try and fix the fire flag resetting problem on Klauth - Octothorpe 11/19/09
//Coded by Bane//
#include <std.h>
#include <daemons.h>
inherit MONSTER;
object *attackers;
string mrace;
object ob,obx;

void create(){
    ::create();
    set_id(({"devil","fiend","pit fiend","Pit Fiend","Qualtatoth","qualtatoth"}));
    set_name("Qualtatoth");
    set_short("Qualtatoth, Commander of the Sixth");
    set_long(
        "The creature standing before you is one of the Pit Fiends from the Sixth level of Hell."+
        "One of the strongest of all devils, the Pit Fiend is a Commander "+
        "of that terrible domain.  It stands over 12 feet tall, its body is "+
        "enormously powerful looking.  Two huge wings waver on its back.  "+
        "Its head is topped with two massive horns that could rend buildings "+
        "apart.  This is a truly fearsome beast."
    );
    set_body_type("daemon");
    set_race("devil");
    set_gender("male");
    set_size(3);
    set_alignment(3);
    set_overall_ac(-40);
    set_hd(70,500);
    set_hp(35000);
    set_exp(75000);
    set_stats("strength",25);
    add_limb("right wing","torso",0,0,0);
    add_limb("left wing","torso",0,0,0);
    add_limb("tail","torso",0,0,0);
    set_guild_level("fighter",70);
    set_mob_magic_resistance("average");
    set_property("no bows",1);
    set_property("magic",1);
    set_property("no animate",1);
    set_property("no steal",1);
    set_property("no knockdown",1);
    set_property("no dominate",1);
    set_property("no death",1);
    set_property("no rush",1);
    set_property("full attacks",1);
    add_money("gold",random(2500)+1000);
    add_money("silver",random(5000)+2000);
    add_money("copper",random(2000)+500);
    add_search_path("/cmds/fighter");
    set_wielding_limbs(({"right hand","left hand"}));
    ob=new("/d/common/obj/weapon/two_hand_sword");
    ob->set_property("enchantment",10);
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wield sword in right hand");
    set_funcs(({"hug","flame","equip","charge","heal_me"}));
    set_func_chance(45);
    set_emotes(9,({"Qualtatoth spreads "+
        "his wings and releases an ear shattering howl.","%^RESET%^%^MAGENTA%^Qualtatoth "+
        "says%^RESET%^: You cannot possibly fathom my unearthly power.","Qualtatoth "+
        "cracks his knuckles and cackles.","%^RESET%^%^MAGENTA%^Qualtatoth says%^RESET%^: "+
        "This realm will fall to its knees in wake of my destruction.",""+
        "%^RESET%^%^MAGENTA%^Qualtatoth says%^RESET%^: I will crush any mortal who dares "+
        "to challenge my absolute power!","Qualtatoth stomps on the ground a few "+
        "times, the tremors nearly knocking you off your feet."}),0);
   set_skill("perception",50); //make it stabbable by a highly skilled thief so they're not useless. Nienne, 04/10.
   set_monster_feats(({
      "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));
   set_resistance("electricity",15);
   set_resistance("acid",5);
   set_resistance("cold",5);
   set_resistance("fire",5);
}


void init() {
   ::init();
   add_action("no_cast","toss");
   add_action("no_cast","throw");
    mrace=TP->query_race();
    if (mrace == "clayman") {
        return 1;
    }
    if (mrace == "dragon") {
        force_me ("say I have no choice but to obey...");
        return 1;
    } else {
   if(TP->query_invis() && !avatarp(TP)) {
      TO->force_me("kill "+TP->query_name()+"");
   }
   if(!TP->query_invis() && !avatarp(TP)) {
      TO->force_me("kill "+TP->query_name()+"");
   }
}
}


void hug(object targ){
    if(!"/daemon/saving_throw_d"->fort_save(targ,-15)) {
        tell_object(targ,"%^BOLD%^%^BLUE%^Qualtatoth grabs you up in a massive bear hug!");
        tell_room(ETO,"%^BOLD%^%^BLUE%^Qualtatoth grabs "+targ->query_cap_name()+" up in a massive bear hug!",targ);
        targ->set_paralyzed(50,"%^RESET%^%^BLUE%^You are being held tight.");
        return 1;
    }
    tell_object(targ,"%^BOLD%^%^BLUE%^Qualtatoth grabs at you but misses!");
    tell_room(ETO,"%^BOLD%^%^BLUE%^Qualtatoth grabs at "+targ->query_cap_name()+" but misses!",targ);
    return 1;
}
void flame(object targ){
   tell_room(ETO, "%^BOLD%^%^RED%^Qualtatoth slams a fist to his chest and coughs %^BOLD%^%^BLACK%^black smoke!", targ);
   tell_room(ETO, "%^BOLD%^%^RED%^Qualtatoth spews flames from his mouth all over "+targ->query_cap_name()+"!", targ);
   tell_object(targ, "%^BOLD%^%^RED%^Qualtatoth slams a fist to his chest and coughs %^BOLD%^%^BLACK%^black smoke%^BOLD%^%^RED%^!");
   tell_object(targ, "%^BOLD%^%^RED%^Qualtatoth spews flame from his mouth all over you!");
   targ->do_damage("torso", random(200)+200);

}

void equip(object targ){
    if(!objectp(targ)) return;
    tell_object(targ,"%^RESET%^%^RED%^Qualtatoth stares at you...");
    tell_room(ETO,"%^RESET%^%^RED%^Qualtatoth stares at "+targ->query_cap_name()+".",targ);
    tell_room(ETO,"%^RESET%^%^RED%^Qualtatoth waves his hand around in the air.");
    if(!targ->query_paralyzed()){
    return 1;
    }
    tell_object(targ,"%^RESET%^%^RED%^You roar out in pain!");
    tell_room(ETO,"%^RESET%^%^RED%^"+targ->query_cap_name()+" roars out in pain!",targ);
    targ->do_damage(targ->return_target_limb(),roll_dice(40,16));
    return 1;
}
void charge(object targ){
    tell_room(ETO,"%^RESET%^%^MAGENTA%^Qualtatoth gets down on all fours and digs his back feet into the ground.");
if(!"/daemon/saving_throw_d"->reflex_save(targ,-15)) {   
        tell_object(targ,"%^RESET%^%^MAGENTA%^Qualtatoth rushes at you with incredible speed and slams into you full force!");
        tell_room(ETO,"%^RESET%^%^MAGENTA%^Qualtatoth rushes at "+targ->query_cap_name()+" with incredible speed and slams into "+targ->query_objective()+" full force!",targ);
        targ->do_damage(targ->return_target_limb(),roll_dice(40,16));
        targ->set_tripped(5,"You are recovering from that trampling.",5);
        return 1;
    }
    tell_object(targ,"%^RESET%^%^MAGENTA%^Qualtatoth rushes at you with incredible speed but you manage to dodge out of the way!");
    tell_room(ETO,"%^RESET%^%^MAGENTA%^Qualtatoth rushes at "+targ->query_cap_name()+" with incredible speed but "+targ->query_subjective()+" manages to dodge out of the way!",targ);
    return 1;
}
void heal_me(){
    tell_room(ETO,"%^BOLD%^%^YELLOW%^Qualtatoth chants an unholy prayer of healing!");
    if(TO->query_hp() < 30000){
            TO->add_hp(2000);
            return 1;
    }
    TO->set_hp(35000);
    return 1;
}
void set_paralyzed(int time,string message){return 1;}
void heart_beat(){
    int i, j;
    object *att;
    object *inven;
    object targ;
    ::heart_beat();
    if(!objectp(TO)) return;
    if((att = (object *)TO->query_attackers()) != ({})){
        j = sizeof(att);
    TO->set_tripped(0);
    TO->set_unconscious(0);
        for(i=0;i<j;i++){
            if(base_name(att[i]) != base_name(TO) != base_name("klauth"))
                call_out("force_me",2,"rush "+att[i]->query_name());
            TO->set_paralyzed(0);
            TO->set_disable(0);
        }
    }


    if(TO->query_hp() < 35000){
        TO->add_hp(20);
        return 1;
    }
   if(query_attackers() == ({})){
      force_me("say I go.");
      tell_room(ETO,"The Pit Fiend rips out of his body, his spirit flying into a fiery gate and leaving his corpse behind.");
	  obx = find_object_or_load("/d/islands/common/mon/klauth");
      obx->call_out("reset_fire",0);
      ::die();
  }
}
/*
void die(object ob) { 
    message("info","%^RESET%^%^RED%^The hell frozen over as the %^BOLD%^%^BLACK%^Pit Fiend %^RESET%^%^RED%^meets his destiny!",
        users());
    ::die();
}
*/
