//Coded by Bane//
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"troll","thug","troll thug"}));
    set_name("troll thug");
    set_short("A Troll thug");
    set_long(
	"This is a vicious troll thug.  He is dressed in heavy leather clothing, "+
	"and covered in spiked chains.  His skin is a putred green, his hair "+
	"a tangled mess.  He stands nearly 8 feet tall and wanders the forest "+
	"searching for any stray humans or Asgardians to slaughter."
    );
    set_body_type("human");
    set_race("troll");
    set_gender("male");
    set_size(2);
    set_hd(15,5);
    set_hp(125);
    set_overall_ac(-4);
    set_property("weakness","fire");
    set_property("weakness","acid");
    set_exp(0);
    set_stats("strength",19);
    set_stats("constitution",24);
    set_property("swarm",1);
    add_money("gold",random(50)+10);
    add_money("silver",random(20)+10);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right hand","left hand","head"}));
    set_attacks_num(3);
    set_damage(1,6);
}
void init(){
    ::init();
    if(wizardp(TP)) return 1;
	if((string)TP->query_race() == "human" || (string)TP->query_race() == "elf" || (string)TP->query_race() == "half-elf" || (string)TP->query_race() == "dwarf" || (string)TP->query_race() == "gnome" || (string)TP->query_race() == "halfling"){
	    if(interactive(TP)){
	    force_me("say ARGH! Die scum!");
	    }
      force_me("kill "+TPQN);
	    return 1;
	}
}
void heart_beat(){
    ::heart_beat();
    if(!objectp(TO)) return;
    if(TO->query_hp() < 124){
	TO->add_hp(2);
	return 1;
    }
}
void die(object targ){
    object ob;
    if(TO->query_hp() < -15){
	if(query_exp() < 1){
	    set_exp(3500);
	}
	::die(ob);
   return;
    }
    tell_room(ETO,"%^RED%^Troll thug drops dead before you.");
     new("/d/laerad/mon/obj/tcorpset")->move(ETO);
    ::remove(ob);
}
