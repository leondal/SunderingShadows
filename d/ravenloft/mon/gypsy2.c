// Coded by Bane
// gypsy2.c
#include <std.h>
inherit "/d/ravenloft/mon/wander/wander.c";
void make_me();
object ob;
void create(){
    ::create();
    set_id(({"gypsy"}));
    set_name("gypsy");
    set_long(
	"This is one of Ravenlofts Vistani...or Gypsy.  These "+
	"folk make up the majority of the villages in these parts.  "+
	"It's a bit smaller than your average human and has "+
	"somewhat distorted features.  Gypsies are rumored "+
	"to have the power to tell the future and to place "+
	"horrid curses on any who mistreat their kind."
    );
    set_body_type("human");
    set_race("gypsy");
    set_size(2);
    set_gender(random(2)?"male":"female");
    set_overall_ac(10);
    set_attack_bonus(5);
    set_stats("dexterity",random(9)+10);
    set_property("swarm",1);
    set_wielding_limbs(({"right hand","left hand"}));
    add_money("gold",random(15));
    add_money("silver",random(30));
    add_money("copper",random(30));
    make_me();
}
void make_me(){
    object ob;
    int i, j, k;
    string class, verb;
    i = random(4);
    switch(i){
	case 0: class = "fighter";
	    break;
	case 1: class = "thief";
	    break;
	case 2: class = "mage";
	    break;
	case 3: class = "cleric";
	    break;
    }
    i = random(6);
    switch(i){
	case 0: verb = "grotesque";
	    break;
	case 1: verb = "foul";
	    break;
	case 2: verb = "small";
	    break;
	case 3: verb = "disgusting";
	    break;
	case 4: verb = "shady";
	    break;
	case 5: verb = "cunning";
	    break;
    }
    set_short("A "+verb+" Gypsy");
    set_alignment(random(8)+2);
    set_class(class);
    set_hd(4+random(7),1);
    set_mlevel(class, query_hd());
    set_hp(query_hd()*10);
    switch(class){
    case "fighter": 
	set_property("full attacks",1);
	set_stats("strength",random(4)+15);
	i = random(3);
	switch(i){
	    case 0:
		new("/d/shadow/obj/armor/banded")->move(TO);
		command("wear armor");
		new("/d/shadow/obj/weapon/two_hand_sword")->move(TO);
		command("wield sword in right hand and left hand");
		new("/d/shadow/obj/armor/helm")->move(TO);
		command("wear helm");
		break;
	    case 1:
		new("/d/shadow/obj/armor/chain")->move(TO);
		command("wear chain");
		new("/d/shadow/obj/weapon/longsword")->move(TO);
		command("wield sword");
		new("/d/shadow/obj/armor/shield")->move(TO);
		command("wear shield");
		new("/d/shadow/obj/armor/helm")->move(TO);
		command("wear helm");
		break;
	    case 2:
		new("/d/shadow/obj/armor/splint")->move(TO);
		command("wear armor");
		new("/d/shadow/obj/weapon/lucern_hammer")->move(TO);
		command("wield hammer in right hand and left hand");
		new("/d/shadow/obj/armor/coif")->move(TO);
		command("wear coif");
		break;
	}
	add_search_path("/cmds/fighter");
	break;
    case "thief":
	set_stats("strength",random(6)+13);
	i = random(3);
	switch(i){
	    case 0:
		new("/d/shadow/obj/armor/studded")->move(TO);
		command("wear studded");
		new("/d/shadow/obj/weapon/longsword")->move(TO);
		command("wield sword");
		break;
	    case 1:
		new("/d/shadow/obj/armor/leather")->move(TO);
		command("wear leather");
		new("/d/shadow/obj/weapon/dagger")->move(TO);
		command("wield dagger");
                new("/d/shadow/obj/weapon/dagger")->move(TO);
		command("wield dagger");
		break;
	    case 2:
		new("/d/shadow/obj/armor/leather")->move(TO);
		command("wear leather");
		new("/d/antioch/armour/robes")->move(TO);
		command("wear robe");
		new("/d/shadow/obj/weapon/shortsword")->move(TO);
		command("wield sword");
		new("/d/shadow/obj/weapon/knife")->move(TO);
		command("wield knife");
		break;
	}
	add_search_path("/cmds/thief");
	set_thief_skill("move silently",random(45)+50);
	set_thief_skill("hide in shadows",random(50)+45);
	break;
    case "mage":
	set_stats("strength",random(9)+10);
	set_guild_level("mage",query_hd());
	set_spells(({
	    "magic missile",
	    "burning hands",
	    "acid arrow",
	    "scorcher",
	    "chill touch",
	    "color spray",
	}));
	set_spell_chance(75);
	i = random(2);
	switch(i){
	    case 0:
		new("/d/antioch/armour/robes")->move(TO);
		command("wear robe");
		new("/d/shadow/obj/weapon/dagger")->move(TO);
		command("wield dagger");
		break;
	    case 1:
		ob = new("/d/laerad/obj/bracers2");
		ob->move(TO);
		if(random(10)) ob->set_property("monsterweapon",1);
		if((int)TO->query_level() < 5) set_mlevel("mage",5);
		command("wear bracers");
		new("/d/shadow/obj/weapon/quarter_staff")->move(TO);
		command("wield staff");
		break;
	}
	break;
    case "cleric":
	set_stats("strength",random(5)+14);
	set_spells(({
	    "limb attack",
	    "call lightning",
	    "cause light wounds",
	    "cause serious wounds",
	}));
	set_spell_chance(50);
	i = random(3);
	switch(i){
	    case 0:
		new("/d/shadow/obj/armor/splint")->move(TO);
		command("wear armor");
		new("/d/shadow/obj/armor/helm")->move(TO);
		command("wear helm");
		new("/d/shadow/obj/weapon/morningstar")->move(TO);
		command("wield star");
		break;
	    case 1:
		new("/d/shadow/obj/armor/banded")->move(TO);
		command("wear banded");
		new("/d/shadow/obj/armor/coif")->move(TO);
		command("wear coif");
		new("/d/shadow/obj/weapon/quarter_staff")->move(TO);
		command("wield staff");
		break;
	    case 2:
		new("/d/shadow/obj/armor/chain")->move(TO);
		command("wear chain");
		new("/d/antioch/armour/robes")->move(TO);
		command("wear robe");
		new("/d/shadow/obj/weapon/lucern_hammer")->move(TO);
		command("wield hammer in right hand and left hand");
		break;
	}
	break;
    }
    add_id(verb);
    add_id(query_class());
}
void heart_beat(){
    int i, j;
    object *att, *blah;
    ::heart_beat();
    if((string)TO->query_class() == "fighter"){
	if(!objectp(TO)) return;
        if((att = (object *)TO->query_attackers()) != ({})){
	    j = sizeof(att);
                for(i = 0;i <j;i++){
		    call_out("force_me",2,"rush "+att[i]->query_name());
                }
        }
    }
    if((string)TO->query_class() == "thief"){
	if((string *)TO->query_attackers() != ({})){
	    force_me("scramble");
	}
    }
    if((string)TO->query_class() == "cleric"){
	blah = all_living(ETO);
	i = sizeof(blah);
	for(j=0;j<i;j++){
	    if((string)blah[j]->query_name() == "gypsy" && (int)blah[j]->query_hp() < (int)blah[j]->query_max_hp()/2){
		if(!random(6))
		new("/cmds/spells/c/_cure_serious_wounds")->use_spell(TO,blah[j],query_hd(),100,"cleric");
	    }
	}
    }
}
