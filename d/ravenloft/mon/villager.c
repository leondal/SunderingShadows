// Coded by Bane
// villager.c
#include <std.h>
inherit "/d/ravenloft/mon/wander/wander.c";
void make_me();
object ob;
void create(){
    ::create();
    set_id(({"villager"}));
    set_name("villager");
    set_long(
	"This is one of the common folk of the village of "+
	"Barovia.  The townspeople are a poor bunch who live "+
	"off of their crops and get by on their meager earnings."
    );
    set_body_type("human");
    set_race("human");
    set_size(2);
    set_gender(random(2)?"male":"female");
    set_overall_ac(random(10));
    set_attack_bonus(5);
    set_stats("dexterity",random(9)+10);
    set_property("swarm",1);
    set_wielding_limbs(({"right hand","left hand"}));
    add_money("gold",random(2));
    add_money("silver",random(5));
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
	case 0: verb = "poor";
	    break;
	case 1: verb = "dirty";
	    break;
	case 2: verb = "homeless";
	    break;
	case 3: verb = "disgusting";
	    break;
	case 4: verb = "shady";
	    break;
	case 5: verb = "hungry";
	    break;
    }
    set_short("A "+verb+" Villager");
    set_alignment(random(8)+2);
    set_class(class);
    set_hd(2+random(3),1);
    set_mlevel(class, query_hd());
    set_hp(query_hd()*10);
    set_exp(query_hd()*50);
    switch(class){
    case "fighter": 
	set_property("full attacks",1);
	set_stats("strength",random(4)+15);
	i = random(3);
	switch(i){
	    case 0:
		new("/d/shadow/obj/weapon/two_hand_sword")->move(TO);
		command("wield sword in right hand and left hand");
		break;
	    case 1:
		new("/d/shadow/obj/weapon/longsword")->move(TO);
		command("wield sword");
		new("/d/shadow/obj/armor/shield")->move(TO);
		command("wear shield");
		break;
	    case 2:
		new("/d/shadow/obj/weapon/lucern_hammer")->move(TO);
		command("wield hammer in right hand and left hand");
		break;
	}
	break;
    case "thief":
	set_stats("strength",random(6)+13);
	toggle_steal();
	i = random(3);
	switch(i){
	    case 0:
		new("/d/shadow/obj/weapon/longsword")->move(TO);
		command("wield sword");
		break;
	    case 1:
		new("/d/shadow/obj/weapon/dagger")->move(TO);
		command("wield dagger");
                new("/d/shadow/obj/weapon/dagger")->move(TO);
		command("wield dagger");
		break;
	    case 2:
		new("/d/shadow/obj/weapon/shortsword")->move(TO);
		command("wield sword");
		new("/d/shadow/obj/weapon/knife")->move(TO);
		command("wield knife");
		break;
	}
	set_thief_skill("move silently",random(45)+56);
	set_thief_skill("hide in shadows",random(50)+45);
	set_thief_skill("pick pockets",random(35)+61);
	break;
    case "mage":
	set_stats("strength",random(9)+10);
	set_guild_level("mage",query_hd());
	set_spells(({
	    "magic missile",
	    "burning hands",
	    "scorcher",
	    "chill touch",
	}));
	set_spell_chance(75);
	i = random(2);
	switch(i){
	    case 0:
		new("/d/shadow/obj/weapon/dagger")->move(TO);
		command("wield dagger");
		break;
	    case 1:
		new("/d/shadow/obj/weapon/quarter_staff")->move(TO);
		command("wield staff");
		break;
	}
	break;
    case "cleric":
	set_stats("strength",random(5)+14);
	set_spells(({
	    "limb attack",
	    "cause light wounds",
	}));
	set_spell_chance(50);
	i = random(3);
	switch(i){
	    case 0:
		new("/d/shadow/obj/weapon/morningstar")->move(TO);
		command("wield star");
		break;
	    case 1:
		new("/d/shadow/obj/weapon/quarter_staff")->move(TO);
		command("wield staff");
		break;
	    case 2:
		new("/d/shadow/obj/weapon/lucern_hammer")->move(TO);
		command("wield hammer in right hand and left hand");
		break;
	}
	break;
    }
    add_id(verb);
    add_id(query_class());
}
