// knight.c
// Coded by Bane
// adding id of laeradmon & getting rid of the wander inherit to use normal wandering *Styx* 12/20/03, last change 11/9/02

#include <std.h>
#include <daemons.h>
#define SHIT ({"dragon","elven-dragon","pegataur","alaghi","unborn","wemic","halfling","goblin","gnome","dwarf","kobold", "kender","voadkyn", "titan","ogre","thri-kreen","orc"});

// inherit "/d/laerad/mon/wander/wander4.c";
inherit MONSTER;

void create(){
// also moved these to be local instead of global variables *Styx* 12/20/03
    object ob; 
    string *races;
    ::create();
    set_id(({"knight","rose","knight of the rose", "laeradmon"}));
    set_name("knight");
    set_short("A knight of the rose");
    set_gender(random(2)?"male":"female");
    races = RACE_D->query_races();
    races = races - SHIT;
    set_race(races[random(sizeof(races))]);
    set_body_type(query_race());
    set_alignment(random(3)*3+1);
    set_long(
	"This is one of the infamous knights of the rose.  They are known "+
	"for their courage and honor and are renowned as excellent "+
	"adventurers traveling across the realms in search for "+
	"never before seen treasures and monsters."
    );
    set_hd(random(11)+25,1);
    set_hp(query_hd()*12);
    set_class("fighter");
    set_overall_ac(10);
    set_stats("strength",random(4)+17);
    set_stats("dexterity",random(2)+16);
    set_stats("constitution",random(4)+16);
    set_stats("charisma",random(5)+10);
    set_stats("wisdom",random(10)+5);
    set_stats("intelligence",random(10)+6);
    set_property("full attacks",1);
    set_property("no dominate",1);
    set_property("no animate",1);
    set_mob_magic_resistance("average");
    set_property("no death",1);
    set_exp(query_hd()*500);
    set_wielding_limbs(({"right hand","left hand"}));
    ob = new("/d/common/obj/special/rweapon");
    ob->move(TO);
    if(ob->query_size() < 3){
	command("wield weapon");
    }
    if(ob->query_size() > 2){
	if(query_size() < 3){
	    command("wield weapon in right hand and left hand");
	    } else {
	    command("wield weapon");
	}
    }
    ob = new("/d/common/obj/armour/fullplate");
    ob->set_property("enchantment",1);
    if(random(50)) ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wear armor");
    ob = new("/d/koenig/town/items/cloak_p2");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear cloak");
    ob = new("/d/deku/armours/ring_p");
    ob->move(TO);
    ob->set_property("enchantment",1);
    command("wear ring");
    ob = new("/d/common/obj/potion/healing");
    ob->move(TO);
    ob->set_uses(50);
    add_search_path("/cmds/fighter");
    set_moving(1);
    set_speed(30);
}

void heart_beat(){
    int i, j;
    object *att;
    ::heart_beat();
   if(!objectp(TO))  return;   // added 11/9/02 by Styx to fix bug
    if((att = (object *)TO->query_attackers()) != ({})){
	j = sizeof(att);
	for(i=0;i<j;i++){
	    call_out("force_me",1,"rush "+att[i]->query_name());
	}
    }
    if(present("kit",TO) && query_hp() < query_max_hp()/2){
	force_me("open kit");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
    }
    if(present("bottle",TO)) force_me("offer bottle");
}
