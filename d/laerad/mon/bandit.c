//Coded by Bane//
#include <std.h>
inherit "/d/laerad/mon/wander/wander2.c";
void create(){
    ::create();
    set_id(({"bandit","Bandit","sneaky bandit"}));
    set_name("Bandit");
    set_short("A sneaky Bandit");
    set_long(
	"This is a fairly muscular man.  He is dressed in all black and "+
	"can be found hiding in the shadows waiting for some poor "+
	"victim to walk on by.  As you watch him you notice an evil grin spread "+
	"across his face."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(15,5);
    set_hp(125);
    set_alignment(9);
    set_overall_ac(0);
    set_exp(2500);
    set("aggressive","pick_pocket");
    set_class("thief");
    set_guild_level("thief",16);
    set_stats("strength",17);
    set_stats("dexterity",19);
    set_stats("consitution",16);
    set_stats("charisma",18);
    add_search_path("cmds/thief");
    set_thief_skill("pick pockets",95);
    set_thief_skill("move silently",95);
    set_thief_skill("hide in shadows",95);
    set_property("no bump",1);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/deku/weapons/dagger2")->move(this_object());
    command("wield dagger");
    set_invis();
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
void pick_pocket(){
    if(interactive(TP)){
   force_me("pp "+TPQN);
	call_out("picking",5,TP);
    	return 1;
    }
}
int picking(){
    if(interactive(TP)){
   force_me("pp "+TPQN);
	call_out("stealing",10,TP);
	return 1;
    }
}
int stealing(){
    if(interactive(TP)){
   force_me("steal kit from "+TPQN);
	call_out("picking",10,TP);
	call_out("offer",50,TP);
	return 1;
    }
}
int offer(){
    force_me("offer kit");
    return 1;
}
