//Octothorpe (12/21/09)
//Attaya, Archer
//Original by Thundercracker

#include <std.h>
inherit MONSTER;

int build,reload;
string *outs,*exit_dir;

void do_check();
void do_bow();

int count;

void create(){
    object ob;
    ::create();
    set_name("skeletal archer");
    set_id(({"undead archer","skeletal archer","archer"}));
    set_race("undead");
    set_gender("male");
    set_short("%^RESET%^%^ORANGE%^r%^RED%^u%^ORANGE%^st%^RED%^y %^ORANGE%^"+
      "undead archer%^RESET%^");
    set_long("%^RESET%^%^RED%^This undead archer is outfitted with "+
      "completely rusted equipment. Some vestiges of ancient armor "+
	  "cover parts of its torso, but what remains is in no condition "+
	  "to provide any semblance of protection. The undead's leathery "+
	  "skin also follows the example of the tattered armor, with bits "+
	  "and pieces hanging to and fro over some of the bones.%^RESET%^");
    set_level(30);
    set_hd(30,6);
    set_new_exp(35,"high");
    set_body_type("human");
    set_max_level(36);
    set_class("fighter");
    set_guild_level("fighter",30);
    set("aggressive",25);
    set_property("full attacks",1);
    set_alignment(2);
    set_size(2);
    set_stats("intelligence",3);
    set_stats("wisdom",3);
    set_stats("strength",20);
    set_stats("charisma",3);
    set_stats("dexterity",20);
    set_stats("constitution",20);
    set_max_hp(300);
    set_hp(query_max_hp());
	set_moving(1);
	set_speed(30);
    add_search_path("/cmds/feats");
    set_monster_feats(({
       "point blank shot",
       "manyshot",
       "deadeye",
       "preciseshot",
       "shot on the run"
    }));
    add_search_path("/cmds/fighter");
    set_fighter_style("soldier");
    set_func_chance(50);
    set_funcs(({"preciseit","manyshotit"}));
    set_wielding_limbs(({"right hand","left hand"}));
    ob = new("/d/attaya/obj/arrows");
    if(!random(10)) { ob->set_property("monsterweapon",1); }
    ob->move(TO);
    ob = new("/d/attaya/obj/deathbow");
    if(!random(10)) { ob->set_property("monsterweapon",1); }
    ob->move(TO);
    command("wield bow");
    /*ob = new("/d/attaya/obj/rustb");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    ob = new("/d/attaya/obj/rustb");
    ob->set_property("monsterweapon",1);
    ob->move(TO);*/
    ob = new("/d/attaya/obj/uarmor");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wear armor");
    command("message in shambles in.");
    command("message out shambles to the $D.");
    enable_commands();
    set_resistance("negative energy",20);
    set_resistance("positive energy",-20);
}

void init(){
    string mrace=TP->query_race();
    ::init();
	if(mrace == "undead") return;
    if(wizardp(TP) || TP->query_true_invis()) return;
    if(TP->query_invis(1)) {
	   tell_room(ETO,"%^BOLD%^The archer loads his crossbow and takes "+
	      "aim at you!%^RESET%^");
       force_me("kill "+TPQN);
	}
}

void start_heart(){
    set_heart_beat(1);
}

/*void heart_beat(){
	::heart_beat();
	if(!objectp(TO))  return;
	count++;
	do_check();
	if(objectp(query_weapon("right hand")))
	if((string)query_weapon("right hand")->query_name() != "sword" && count > 5)
	do_bow();
}*/

void preciseit(object targ){
   TO->force_me("preciseshot "+targ->query_name());
}

void manyshotit(object targ){
   TO->force_me("manyshot");
}

void do_bow(){
    int i,j, y,z;
    object ob, *inven, *living_bad;
    string exit,*paths, *ids;

    living_bad = ({});
    if(ETO){
	paths = ETO->query_destinations();
	if(j = sizeof(paths)){
	    for(i=0;i<j;i++){
		if(ob = find_object_or_load(paths[i])){
		    inven = all_inventory(ob);
		    z = sizeof(inven);

		    for(y=0;y<z;y++)
		    if(interactive(inven[y]) && !inven[y]->query_true_invis()){
			living_bad += ({inven[y]});
		    }
		    if(z = sizeof(living_bad)){
			y = random(z);
			exit = ETO->query_direction(paths[i]);
			  if(!interactive(living_bad[y])){
				ids = living_bad[y]->query_id();
				command("shoot "+ids[0]+" "+exit+" 1");
			    }
			    else
				command("shoot "+living_bad[y]->query_name()+" "+exit+" 1");
				break;
		    }
	        }
	     }
	 }
    }
    count = 0;
}

/*void do_check(){
    object *weapons;
    int i;
    weapons = TO->query_wielded();

    if(sizeof(weapons)){
	if((string)weapons[0]->query_name() != "crossbow"){
	    if((object *)TO->query_attackers() == ({})){
		command("unwield sword");
		command("unwield sword 2");
		command("wield bow in right hand and left hand");
	    }
	} else
	if((string)weapons[0]->query_name() == "crossbow"){
	    if((object *)TO->query_attackers() != ({})){
		command("unwield bow");
		command("wield sword in right hand");
		command("wield sword 2 in left hand");
	    }
	}
   }
   if(!present("arrows"))
	new("/d/attaya/obj/arrows")->move(TO);
}*/

void die(object ob){
   tell_room(ETO,"%^BOLD%^The archer becomes rigid and screams out "+
      "in anger!");
   if(!random(20)){
      ob = new("/d/attaya/obj/arrows");
	  ob->move(ETO);
   }
   if(!random(20)){
      ob = new("/d/attaya/obj/deathbow");
	  ob->move(ETO);
   }
   if(!random(20)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("bone dust");
      ob->move(ETO);
   }
   TO->move("/d/shadowgate/void");
   TO->remove();
}
