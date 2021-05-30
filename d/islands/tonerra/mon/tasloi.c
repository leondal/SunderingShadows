//Added set_max_level to retard cycling - Octothorpe 6/4/09
//tasloi.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit MONSTER;

void create(){
	::create();
	
	set_name("tasloi");
	set_short("Tasloi");
	set_id(({"tasloi","Tasloi"}));
	set_long(
@OLI
        These flat headed humanoids reek of evil. They walk in a crouching 
posture, touching knuckles to the ground from time to time. They are
green with coarse dark hair. Slit, golden eyes peer at you.
OLI
	);
	set_hd(15,1);
	set_hp(roll_dice(15,10) + 10);
	//set_exp(600);
    set_new_exp(15, "normal");
    set_max_level(25);
	set_body_type("humanoid");
	set_wielding_limbs(({"right hand","left hand"}));
	set_overall_ac(-10);
	set_size(1);
	if(!random(5)){
		new("/d/shadow/obj/weapon/longsword")->move(TO);
		command("wield sword in left hand and right hand");
	} else if(!random(5)){
		new("/d/shadow/obj/weapon/club")->move(TO);
		new("/d/shadow/obj/armor/sshield")->move(TO);
		command("wear shield");
		command("wield club in left hand ");
	} else {
		new("/d/shadow/obj/weapon/shortsword")->move(TO);
		command("wield sword in left hand");
		new("/d/shadow/obj/armor/sshield")->move(TO);
		command("wear shield");
	}
	set_race("tasloi");
	set_gender("male");
	set_alignment(9);
	add_money("gold",random(100));
	set_property("swarm",1);
	if(random(4))
		set_invis();
}
