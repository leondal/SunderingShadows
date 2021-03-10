#include <std.h>
inherit WEAPONLESS;
 
create() {
    ::create();
    set_name("thing");
    set("id", ({ "swamp","swamp thing","thing" }));
    set("short", "%^RESET%^%^GREEN%^Swamp thing%^RESET%^");
    set("aggressive", random(10)+9);
    set_level(9);
    set("long", "%^GREEN%^This creature appears to be composed of wood-like skin "
	"covered with various swamp slime. Slightly humanoid it towers 10 feet "
	"in the air above you gazing around looking for food with its "
	"haunting eerie green eyes.%^RESET%^");
    set_class("fighter");
    set("race", "humanoid");
    set_body_type("human");
    set_attacks_num(2); 
    set_damage(2,3);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right hand","left hand"})); 
    set_alignment(6);
    set_overall_ac(4);
    set_guild_level("fighter",9);
    set_hd(9,5);
    set_max_hp(80);
    set_hp(80);
    set_exp(900);	
    set_stats("strength",17);
    set_stats("dexterity",19);
    set_emotes(3,({
	"The swamp thing moans loudly.",
	"%^RED%^The swamp thing attempts to knock you down!%^RESET%^",
	"%^GREEN%^The swamp thing uses the swamp to heal itself!%^RESET%^",
    }),1);
}
