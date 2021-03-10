inherit "/std/monster";
 
create() {
    ::create();
    set_name("lizard");
    set_id(({ "lizard" }));
    set_short("%^RESET%^%^RED%^Scaled lizard%^RESET%^");
    set("aggressive",random(10)+5);
    set_level(5);
    set_long("A small lizard with a plethora of scales.");
    set_body_type("reptile");
    set_alignment(5);
    set_race("lizard");
    set_overall_ac(5);
    set_guild_level("fighter",5);
    set_hd(5,5);
    set_max_hp(50);
    set_hp(50);
    set_exp(500);	
    set_stats("strength",15);
    set_stats("dexterity",15);
    set_emotes(3,({
	"The lizard bites you!",
	"%^RED%^The lizard spits a vile liquid at you!%^RESET%^",
	"%^GREEN%^The lizard lashes out with it's sharp fangs!%^RESET%^",
    }),1);
}
