//Coded by Bane//
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"troll","guard","troll guard"}));
    set_name("troll guard");
    set_short("A Troll guard");
    set_long(
	"This is a rather large troll guard.  He is dressed in a hide "+
	"cloth.  His skin is a putred green and his eyes bulge out of his "+
	"head.  He stands over 7 feet tall and looks extremely fierce."
    );
    set_body_type("human");
    set_race("troll");
    set_gender("male");
    set_size(2);
    set_hd(12,14);
    set_hp(110);
    set_overall_ac(-3);
    set_property("weakness","fire");
    set_property("weakness","acid");
    set_exp(0);
    set_stats("strength",20);
    set_stats("constitution",24);
    set_property("swarm",1);
    add_money("gold",random(200)+300);
    add_money("silver",random(20)+10);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right hand","left hand","head"}));
    set_attacks_num(3);
    set_damage(1,4);
}
void init(){
    ::init();
    if(wizardp(TP)) return 1;
	if((string)TP->query_race() == "human" || (string)TP->query_race() == "elf" || (string)TP->query_race() == "half-elf" || (string)TP->query_race() == "dwarf" || (string)TP->query_race() == "gnome" || (string)TP->query_race() == "halfling"){
	    if(interactive(TP)){
	    force_me("say YOU DO NOT BELONG HERE OUTSIDER!");
	    }
      force_me("kill "+TPQN);
	    return 1;
	}
    }
void heart_beat(){
    ::heart_beat();
   if(!objectp(TO)) return;
    if(TO->query_hp() < 109){
	TO->add_hp(2);
	return 1;
    }
}
void die(object targ){
    object ob;
    if(TO->query_hp() < -15){
	if(query_exp() < 1){
	    set_exp(1700);
	    continue_attack();
	}
	::die(ob);
     return;
    }
    tell_room(ETO,"%^RED%^Troll guard drops dead before you.");
    new("/d/laerad/mon/obj/tcorpse1")->move(ETO);
    ::remove(ob);
}
