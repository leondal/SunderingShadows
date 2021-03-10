inherit "/std/monster";
 
create() {
    ::create();
    set_name("boa");
    set("id", ({ "boa" }));
    set("short", "%^RESET%^%^RED%^Large boa%^RESET%^");
    set("aggressive", random(10)+5);
    set_level(6);
	
    set("long", "A large boa constrictor.");
    set_class("fighter");
    set_body_type("snake");
    set_alignment(5);
    set("race", "snake");
    set_overall_ac(4);
    set_guild_level("fighter",6);
    set_hd(6,5);
    set_max_hp(60);
    set_hp(60);
    set_exp(600);	
    set_stats("strength",16);
    set_stats("dexterity",16);
    set_emotes(3,({
	"The snake tries to wrap itself around you!",
	"%^RED%^The boa lashes out at you!%^RESET%^",
	"%^GREEN%^The boa entwines you!%^RESET%^",
    }),1);
}
