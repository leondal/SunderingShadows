#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("gar");
    set_id(({
        "gar","fish","giant gar","giant fish"
    }));
   set_short("%^BLUE%^Giant gar%^RESET%^");
    set_long(
        "%^BLUE%^The giant gar is an enormous 30 foot long whale like "
	"creature with long flexible jaws outlined with multiple rows "
   "of razor sharp teeth. Despite its large size, it moves at "
	"lightning fast speeds through the water and is always "
   "looking for a tasty meal to satisfy its hunger."
    );
    set_gender("neuter");
    set_hd(8,2);
    set_size(3);
    set_body_type("fish");
    set_race("fish");
    add_limb("mouth","mouth",75,1,5);
    set_overall_ac(3);
    set_wielding_limbs(({"mouth"}));
    new("/d/dagger/drow/obj/rune.c")->move(TO);
    new("/d/dagger/drow/obj/jaws.c")->move(TO);
    command("wield jaws in mouth");
    set_hp(75);
    set_max_hp(75);
    set_exp(2000);
    set_class("fighter");
    set_guild_level("fighter",8);
    set_stats("strength",17);
    set_stats("constitution",16);
    set_stats("dexterity",16);
    set_stats("wisdom",10);
    set_stats("intelligence",10);
    set_stats("charisma",3);
    set("aggressive",25);
    set_property("swarm",1);
    set_emotes(3, ({
        "%^BLUE%^The Giant Gar swims voilently towards you.%^RESET%^",
   "%^BLUE%^The Giant Gar brushes its scaly skin against you as it swims by.%^RESET%^"
	}),0);
}
