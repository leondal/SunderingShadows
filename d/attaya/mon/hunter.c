#include <std.h>
#include "/d/shadow/mon/melnmarn.h"

inherit MONSTER;

int build,reload;
string *outs,*exit_dir;

void do_check();
void do_bow();

int count;

create() {
    ::create();
    set_name("hunter");
    set_id( ({ "phantom hunter", "hunter", "phantom" }) );
    set_race("undead");
    set_gender("male");
    set("short", "%^BOLD%^%^BLACK%^Nightmarish phantom Hunter%^RESET%^");
    set_long("Among the darkest of legends on Attaya, a place where such"+
	" incredible stories come to pass, there is a tale of a hunter in "+
	"the oubliette.\n The phantom Hunter was supposedly sent by one of "+
	"the gods to kill anything that became trapped in the oubliette.\n "+
	"The Hunter was given amazing strength, speed, and cunning.");
    set_level(50);
    set_hd(50,6);
    set_exp(50000);
    set_body_type("human");
    set_invis();
    set_moving( 1 );
    set_speed ( 30 );
    set_guild_level("fighter",50);
    set("aggressive",22);
    set_alignment(9);
    set_size(3);
    set_stats("intelligence",22);
    set_stats("wisdom",22);
    set_stats("strength",23);
    set_stats("charisma",20);
    set_stats("dexterity",24);
    set_stats("constitution",24);
    //set_max_mp(2050);    
    //set_mp(query_max_mp());
    set_max_hp(3050);
    set_hp(3050);
    set_property("full attacks",1);
    set_mob_magic_resistance("very low");
    set_parrying(1);
    set_wielding_limbs( ({"right hand","left hand"}) );
   // new("/d/attaya/obj/lightning")->move(this_object());
  //  new("/d/attaya/obj/stormsabre")->move(this_object()); taking this out till I get around to repairing it, discern between ranged and melee on the same weapon is buggy - Ares
    new("/d/attaya/obj/gcutlass")->move(this_object());
    command("wield cutlass");
    new("/d/attaya/obj/black_swan")->move(TO);
    command("wield rapier");
    //new("/d/attaya/obj/rustb")->move(this_object());
    //new("/d/attaya/obj/rustb")->move(this_object());
    new("/d/attaya/obj/uarmor")->move(TO);
    command("wear armor");
    add_money("electrum",random(5000)+1000);
    add_money("silver",random(5000)+1000);
    add_money("gold",random(500)+100);
    enable_commands();
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}
void init(){
// added ::init() to fix/prevent bugs 2/23/03 *Styx*
    ::init();
    if(!TP->query_invis() && !wizardp(TP)){
	tell_room(ETO,"%^BOLD%^The hunter shrieks and attacks!");
        if(query_invis()) set_invis();
        kill_ob(TP,1);
    }
    return;
}
void start_heart(){
    set_heart_beat(1);
}

void heart_beat(){
    count++;
   // if(objectp(TO))  do_check();
   // if(objectp(query_weapon("right hand")) &&((string)query_weapon("right hand")->query_name() != "sword" && count > 5))
//	do_bow();  // he doesn't have a bow, so commenting this out *Styx*  2/23/03
    ::heart_beat();
}

/* doesn't have a bow, probably copied from archers and not removed *Styx*  2/23/03
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
			  if(interactive(inven[y])){
				living_bad += ({inven[y]});
			    }

			    if(z = sizeof(living_bad)){
				y = random(z);
				exit = ETO->query_direction(paths[i]);
				  if(!interactive(living_bad[y])){
					ids = living_bad[y]->query_id();
					command("shoot "+ids[0]+" 1 "+exit);
				    }
				    else
					command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
				    break;
				}
			      }
			    }
			}
		  }
		  count = 0;
	      }
*/

void do_check(){
    object *weapons;
    int i;
    weapons = TO->query_wielded();
    if(sizeof(weapons)){
	if((string)weapons[0]->query_name() != "stormsabre"){
	    if((object *)TO->query_attackers() == ({})){
		command("unwield sword");
		command("unwield sword");
		command("wield scimitar");
	    }
	} else
	if((string)weapons[0]->query_name() == "stormsabre"){
	    if((object *)TO->query_attackers() != ({})){
		command("unwield scimitar");
		command("wield sword in right hand");
		command("wield sword 2 in left hand");
	    }
	}
    }
    if(!present("object"))
	new("/d/attaya/obj/lightning")->move(TO);
}
