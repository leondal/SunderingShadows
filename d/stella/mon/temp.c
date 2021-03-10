/*  Mundanoid   by Killashandra  */

#include <std.h>
#include "/d/stella/short.h"
inherit MONSTER;

int hd,xx;

void create() {
    :: create();
    set_name("Mundanoid");
    set_id(({
      "mundanoid","humanoid"
      }));
    set_short("%^RESET%^%^CYAN%^Mundanoid%^RESET%^");
    set_long(
        "%^RESET%^%^CYAN%^This creature appears human in form "
	"except for its dark grey skin and deep black eyes.");
    hd=5;
    set_gender("male");
    set_num_attacks(3); 
    set_alignment(9);
    set_size(2);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(5-hd);
    set_hp(50);
    set_property("no bump",1);
    set_property("no steal",1);
    set_max_hp(400);
    set_exp(20000);
    set_body_type("humanoid");
    set_race("mundanoid");
    set_class("fighter");
    set_stats("strength",18);
    set_stats("constitution",18);
    set_stats("dexterity",19);
    set_stats("wisdom",20);
    set_stats("intelligence",14);
    set_stats("charisma",5);
    set("aggressive",10);
    set_funcs(({"moves"}));
    set_func_chance(hd*5);
    set_emotes(5, ({
        "%^CYAN%^The mundanoid looks at you hungrily!%^RESET%^",
        "%^BLUE%^The mundanoid's eyes glow briefly%^RESET%^",
    }),1);
    }

int do_damage(string limb, int dam) {
    object prev = previous_object();
    object targ = TO->query_current_attacker();
    int newhd,xx;

    if (!prev->is_spell() && !prev->query_property("magic")
	&& !prev->query_property("enchantment"))
      return ::do_damage(limb,dam);

    return 1;
}


int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();

    if (hd<8) xx=1;
    else if (hd<10) {xx=2;}
    else if (hd<14) {xx=3;}
    else if (hd<18) {xx=4;}
    else if (hd<22) {xx=5;}
    else if (hd<26) {xx=6;}
    else if (hd<30) {xx=7;}
    else {xx=8;}
    switch(xx) {
    case 1:
    	tell_object(targ,
    	    "%^BLUE%^The Mundanoid lands a solid blow with its fist.%^RESET%^"
    	);
    	tell_room(environment(targ),
    	    "%^GREEN%^The Mundanoid lands a solid blow on "
	    +targ->query_cap_name()+"%^RESET%^",targ);
    	targ->do_damage("head",roll_dice(2,8));
    	return 1;
    case 2:
    	tell_object(targ,
    	    "%^RED%^The Mundanoid throws a massive fireball at you!%^RESET%^"
    	);
    	tell_room(environment(targ),
    	    "%^RED%^The Mundanoid throws a massive fireball at "
	    +targ->query_cap_name()+"%^RESET%^",targ);
	if("daemon/saving_d"->saving_throw(ob,"spell")) {
            tell_object(targ,
                "%^RED%^The fireball hits you!%^RESET%^"
            );
            tell_room(environment(targ),
                "%^RED%^The fireball hits "
                +targ->query_cap_name()+"!%^RESET%^",targ);
            targ->do_damage("torso",roll_dice(10,6));
    	} else {
            tell_object(targ,
               "%^MAGENTA%^You avoid the worst of the fireball!%^RESET%^"
            );
            tell_room(environment(targ),
                "%^MAGENTA%^"+targ->query_cap_name()+
                " avoids the worst of the fireball!%^RESET%^"
            ,targ);
	    targ->do_damage("torso",roll_dice(5,6));
    	}
	return 1;
    case 3:
	/* cast cone of cold */
        new("/cmds/spells/c/_cone_of_cold.c")->use_spell(TO,targ->query_name(),hd*3,100,"mage");
	return 1;
    case 4:
	/* cast chain lighting */
        new("/cmds/spells/c/_chain_lightning.c")->use_spell(TO,targ->query_name(),hd*3,100,"mage");
	return 1;
    case 5:
	/* blindness /paralyzation? */
        tell_object(targ,
            "%^BOLD%^%^WHITE%^The Munanoid's eyes are so "
	    "bright that they blind you!%^RESET%^"
        );
        tell_room(environment(targ),
            "%^BOLD%^%^WHITE%^"+targ->query_cap_name()+
	    " is blinded by the Mundanoid's glowing eyes!%^RESET%^"
        ,targ);
        targ->set_paralyzed(30+random(20),
            "%^WHITE%^%^BOLD%^You can't see anything!"
            "%^RESET%^"
        );
	return 1;
    case 6:
	/* cast firestorm */
	return 1;
    case 7:
	/* prismatic sphere */
	return 1;
    case 8:
	/* Mordenkainen's Disjunction */
	return 1;
      }
    return 1;
}
