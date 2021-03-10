#include "/d/tharis/barrow/short1.h"
#include <std.h>
inherit "std/monster";
void create() {
    :: create();
    set_name("lemure");
    set_id(({
	"lemure","demon"
    }));
    set_short("%^RESET%^%^RED%^a lemure%^RESET%^");
    set_long(
	"%^BOLD%^%^BLACK%^"
        "The Lemure's features are bulbous and distorted. It appears "
	"to be a blubbering mass of flesh resembling an imp. However, "
	"despite its appearance, it emanates feelings of immense power "
	"and great evil. "
    );
    set_gender("male");
    set_hd(20,4);
    set_weight(90);
    set_wielding_limbs(({"right hand","left hand"}));
    set_ac(-5);
    set_alignment(9);
    set_hp(145);
    set_max_hp(145);
    set_exp(6700);
    set_body_type("humanoid");
    set("race","demon");
    set_class("fighter");
    set_stats("strength",20);
    set_stats("constitution",20);
    set_stats("dexterity",22);
    set_stats("wisdom",19);
    set_stats("intelligence",23);
    set_stats("charisma",1);
}
void die(object ob) {
    message("environment",
	"%^BOLD%^%^BLACK%^The lemure melts into the "
	"ground.%^RESET%^"
    ,environment(TO));
    :: die(ob);
}
