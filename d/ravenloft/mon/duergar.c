// Coded by Bane
// duergar.c
#include <std.h>
inherit MONSTER;
void make_me();
object ob;
void create(){
    ::create();
    set_id(({"duergar"}));
    set_name("duergar");
    set_long(
	"This stocky Duergar, or dark Dwarf, looks extremely nasty.  "+
	"It has a dark complexion and a grayish hair color.  "+
	"Its clothing is drab, designed to blend in with its "+
	"surroundings for defensive purposes.  Duergar are "+
	"known for their evil tendancies."
    );
    set_body_type("human");
    set_race("duergar");
    set_size(1);
    set_gender(random(2)?"male":"female");
    set_overall_ac(random(10));
    set_attack_bonus(5);
    set_damage_bonus(random(5)+1);
    set_stats("dexterity",random(9)+10);
    set_property("swarm",1);
    set_wielding_limbs(({"right hand","left hand"}));
    add_money("gold",random(30));
    add_money("silver",random(30));
    add_money("copper",random(30));
    make_me();
}
void make_me(){
    object ob;
    int i, j, k;
    string *bane, class, verb;
    i = random(6);
    switch(i){
	case 0:
	    set_class("fighter");
	    set_hd(random(17)+4,1);
	    set_mlevel("fighter",query_hd());
	    add_id("fighter");
	    break;
	case 1:
	    set_class("thief");
            set_hd(random(17)+4,1);
	    set_mlevel("thief",query_hd());
	    add_id("thief");
	    break;
	case 2:
	    set_class("cleric");
            set_hd(random(17)+4,1);
	    set_mlevel("cleric",query_hd());
	    set_guild_level("cleric",query_hd());
	    add_id("cleric");
	    break;
	case 3:
	    set_class("thief");
	    set_class("fighter");
            set_hd(random(17)+4,1);
	    set_mlevel("thief",query_hd());
	    set_mlevel("fighter",query_hd());
	    add_id("thief");
	    add_id("fighter");
	    break;
	case 4:
	    set_class("cleric");
	    set_class("fighter");
            set_hd(random(17)+4,1);
	    set_mlevel("cleric",query_hd());
	    set_mlevel("fighter",query_hd());
	    set_guild_level("cleric",query_hd());
	    add_id("cleric");
	    add_id("fighter");
	    break;
	case 5:
	    set_class("thief");
	    set_class("cleric");
            set_hd(random(17)+4,1);
	    set_mlevel("thief",query_hd());
	    set_mlevel("cleric",query_hd());
	    set_guild_level("cleric",query_hd());
	    add_id("thief");
	    add_id("cleric");
	    break;
    }
    set_hp(query_hd()*12);
    set_exp(query_hd()*350);
    switch(query_hd()){
	case 0..5:
	    set_short("A duergar foot soldier");
	    add_id("foot");
	    add_id("soldier");
	    add_id("foot soldier");
	    add_id("duergar foot soldier");
	    break;
	case 6..10:
	    set_short("A duergar major");
	    add_id("major");
	    add_id("duergar major");
	    break;
	case 11..15:
	    set_short("A duergar colonel");
	    add_id("colonel");
	    add_id("duergar colonel");
	    break;
	case 16..20:
	    set_short("An elite duergar general");
	    add_id("elite");
	    add_id("general");
	    add_id("elite duergar");
	    add_id("duergar general");
	    add_id("elite duergar general");
	    break;
    }
    set_alignment(3);
    bane = TO->query_classes();
    switch(query_class()){
    case "thief":
        set_stats("strength",random(6)+13);
        i = random(3);
        switch(i){
            case 0:
                new("/d/shadow/obj/armor/studded")->move(TO);
                command("wear studded");
		new("/d/shadow/obj/weapon/longsword")->move(TO);
		command("wield sword in right hand and left hand");
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
		new("/d/shadow/obj/armor/studded")->move(TO);
                command("wear armor");
		new("/d/shadow/obj/weapon/shortsword")->move(TO);
		command("wield sword");
		new("/d/shadow/obj/weapon/knife")->move(TO);
		command("wield knife");
                break;
        }
        add_search_path("/cmds/thief");
	set_thief_skill("move silently",random(25)+76);
        set_thief_skill("hide in shadows",random(50)+45);
	if(TO->is_class("fighter")) add_search_path("/cmds/fighter");
	if(TO->is_class("cleric")){
	    set_spells(({
		"cause light wounds",
		"cause serious wounds",
		"limb attack",
		"call lightning",
	    }));
	    set_spell_chance(50);
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
	if(TO->is_class("fighter")) add_search_path("/cmds/fighter");
        i = random(3);
        switch(i){
            case 0:
		if((string)TO->query_class() == "thief") return 1;
		new("/d/shadow/obj/armor/splint")->move(TO);
		command("wear armor");
		new("/d/shadow/obj/armor/helm")->move(TO);
		command("wear helm");
                new("/d/shadow/obj/weapon/morningstar")->move(TO);
		command("wield star in right hand and left hand");
                break;
            case 1:
		if((string)TO->query_class() == "thief") return 1;
		new("/d/shadow/obj/armor/banded")->move(TO);
		command("wear banded");
		new("/d/shadow/obj/armor/coif")->move(TO);
		command("wear coif");
                new("/d/shadow/obj/weapon/quarter_staff")->move(TO);
                command("wield staff");
                break;
            case 2:
		if((string)TO->query_class() == "thief") return 1;
		new("/d/shadow/obj/armor/chain")->move(TO);
		command("wear chain");
                new("/d/antioch/armour/robes")->move(TO);
                command("wear robe");
		new("/d/shadow/obj/weapon/flail")->move(TO);
		command("wield flail in right hand and left hand");
                break;
	}
	break;
    case "fighter": 
	set_property("full attacks",1);
	set_stats("strength",random(4)+15);
	add_search_path("/cmds/fighter");
	if((string)TO->query_class() == "thief") return 1;
	if((string)TO->query_class() == "cleric") return 1;
	i = random(3);
	switch(i){
	    case 0:
		new("/d/shadow/obj/armor/banded")->move(TO);
		command("wear armor");
		new("/d/shadow/obj/weapon/broad")->move(TO);
		command("wield sword in right hand and left hand");
		new("/d/shadow/obj/armor/helm")->move(TO);
		command("wear helm");
		break;
	    case 1:
		new("/d/shadow/obj/armor/chain")->move(TO);
		command("wear chain");
		new("/d/shadow/obj/weapon/longsword")->move(TO);
		command("wield sword in right hand and left hand");
		new("/d/shadow/obj/armor/helm")->move(TO);
		command("wear helm");
		break;
	    case 2:
		new("/d/shadow/obj/armor/splint")->move(TO);
		command("wear armor");
		new("/d/shadow/obj/weapon/battle_axe")->move(TO);
		command("wield axe in right hand and left hand");
		new("/d/shadow/obj/armor/coif")->move(TO);
		command("wear coif");
		break;
	}
	break;
    }
}
void heart_beat(){
    int i, j;
    object *att;
    ::heart_beat();
    if(TO->is_class("fighter")){
       if(!objectp(TO)) return;
        if((att = (object *)TO->query_attackers()) != ({})){
            j = sizeof(att);
                for(i = 0;i <j;i++){
                    call_out("force_me",2,"rush "+att[i]->query_name());
                }
        }
    }
    if(TO->is_class("thief")){
	if((string *)TO->query_attackers() != ({})){
	    force_me("scramble");
	}
	if((string *)TO->query_attackers() == ({})){
	    if(!TO->query_invis()) TO->set_invis();
	}
	if((string *)TO->query_attackers() != ({})){
	    if(TO->query_invis()) TO->set_invis();
	}
    }
}
