#include <std.h>
inherit WEAPONLESS;
 
create() {
    ::create();
    set_name("bogger");
    set("id", ({ "bogger","bog thing","thing" }));
    set("short", "%^RESET%^%^RED%^Bog thing");
    set("aggressive", random(8)+5);
    set_level(10);
    set("long", "%^GREEN%^This creature appears to be composed of stony skin "
	"covered with various bog slime.  Slightly humanoid, it towers 12 feet "
	"in the air above you gazing around looking for food with its "
	"haunting %^RED%^eerie red eyes.%^RESET%^");
    set_class("fighter");
    set("race", "humanoid");
    set_body_type("human");
    set_attacks_num(2); 
    set_damage(2,4);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right hand","left hand"})); 
    set_alignment(5);
    set_overall_ac(2);
    set_guild_level("fighter",12);
    set_hd(12,5);
    set_max_hp(95);
    set_hp(95);
    set_exp(1000);	
    set_stats("strength",18);
    set_stats("dexterity",18);
    set_emotes(3,({
	"The bog thing shambles around you!",
	"%^RED%^The bog thing's eyes blaze brightly!%^RESET%^",
	"%^GREEN%^The bog thing uses the swamp to heal itself!%^RESET%^",
    }),1);
}
