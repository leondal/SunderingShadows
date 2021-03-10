#include <std.h>
#include "/d/dagger/drow/short.h"
inherit MONSTER; 
int xx,THIEF1,FIGHTER1;
object FIGHTER,THIEF,VICTIM;
void create() {
    :: create();
    set_name("tyvicus");
    set_id(({
        "tyvicus","drow","mage"
    }));
    set_short("%^RESET%^%^RED%^Tyvicus, Drow High Mage%^RESET%^");
    set_long(
	"The wizardly drow elf before you is clad in a black robe covered in "
	"runes. His eyes show an ancient stark gaze of death and "
	"knowledge of forbidden things. His short black hair is drawn "
	"back within the cowl of his robe. Wispy shadows dance about "
	"his black leather boots. A chill grin seems permanently etched "
	"on his blackened lips, one of either insanity or possession."
    );
    set_gender("male");
    set_level(25);
    set_hd(25,7);
    set_size(2);
    set_weight(180);
    set_wielding_limbs(({"right hand","left hand"})); 
    set_overall_ac(-4);
    set_property("no bump",1);
    set_property("no steal",1);
    set_body_type("humanoid");
    set_race("drow");
    set_class("mage");
    set_guild_level("mage",25);
    set_stats("strength",16);
    set_stats("constitution",22);
    set_stats("dexterity",20);
    set_stats("wisdom",40);
    set_stats("intelligence",40);
    set_stats("charisma",20);
    set_alignment(9);
    set_mob_magic_resistance("average");
    set_exp(80000);
    set_max_hp(400);
    set_hp(400);
    add_money("gold",random(2000)+500);
    set_emotes(1,({
        "%^MAGENTA%^Tyvicus says: %^RESET%^We do not know what they look like, they "
	"have blended in with the humanoid merchants we allow passage within the city.",
        "%^MAGENTA%^Tyvicus says: %^RESET%^Gurn, watch my back closely, I can not afford to "
	"take combat hits.",
        "%^MAGENTA%^Tyvicus says: %^RESET%^He hides well.",
        "%^MAGENTA%^Tyvicus says: %^RESET%^The infidels are strong, they have slain many of us already.",
        "%^MAGENTA%^Tyvicus says: %^RESET%^We will be wise to keep our hellish eyes open.",
        "%^MAGENTA%^Tyvicus says: %^RESET%^They shall meet their doom if they confront us, Gurn.",
    }),0);	
    set_funcs(({"special"}));
    set_func_chance(40);
}
int special() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    int xx;
    xx = random(2)+1;
    switch(xx) {
    case 1:
        set_property("magic",1);
	tell_object(targ,
	    "%^BLUE%^%^BOLD%^Tyvicus mutters nonsense while pointing at you!%^RESET%^"
	);
	tell_room(environment(targ),
	    "%^RED%^%^BOLD%^Tyvicus mutters nonsense while pointing at "
	    +targ->query_cap_name()+"!%^RESET%^"
	,targ);
	tell_object(targ,
	    "%^RED%^%^BOLD%^You fall to your knees in contorted agony!%^RESET%^"
	);
	tell_room(environment(targ),
	    "%^RED%^%^BOLD%^"+targ->query_cap_name()+" falls to the ground twisting and screaming!%^RESET%^"
	,targ);
            targ->do_damage("torso",random((int)targ->query_level())+(int)targ->query_level());
            targ->set_paralyzed(8,"You are in to much pain to stand!");
           remove_property("magic");
            return 1; 
     case 2:
	ob->force_me("say Magik of this world, I do not fear!");
	ob->force_me("cast dispel magic");
	return 1;
     case 3:
	ob->force_me("say I will end this impudent invasion now!");
	ob->force_me("cast domination at "+targ->query_name());
     call_out("flames",15,ob,targ);
     return 1;
}
}
void flames(object ob, object targ) {
      if(!ob) {return;}
      if(!targ) {return;}
      if(!environment(ob)) {return;}		
      ob->force_me("make "+targ->query_name()+" drop all");
      ob->force_me("get all");
      return;
}
void_set_paralyzed(int time,string message){return 1;}
void heart_beat() {
    ::heart_beat();
    if(!TO) {return;}
    if(!ETO) {return;}
    if(TO->query_hp() < 100) {
	TO->add_hp(random(20));
        return;
    }
    if(FIGHTER == present("gurn") && FIGHTER1 == 0 && FIGHTER->query_current_attacker() != 0) {   
        VICTIM == (object)FIGHTER->query_current_attacker();
	force_me("fireball "+VICTIM->query_name());
	FIGHTER1 = 1;
	return;
    }
    if(THIEF == present("shadowspawn") && THIEF1 == 0 && THIEF->query_current_attacker() != 0) {    
        VICTIM == (object)THIEF->query_current_attacker();
	force_me("kill "+VICTIM->query_name());
	THIEF1 = 1;
	return;
    }
    return;
}
