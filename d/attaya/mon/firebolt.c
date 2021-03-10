#include <std.h>
inherit WEAPONLESS;
void create() {
    ::create();
    set_name("firebolt influence");
    set_id(({"firebolt influence","influence","firebolt"}));
    set_short("%^RED%^Firebolt Influence%^RESET%^");
    set_long(
      "The Firebolt Influence is a mysterious living flame.  It has been rumored that such influences are created when a person is incinerated by lava so quickly that the soul has no chance to escape the body!  It has a shifting shape, but can compress itself to a humanoid appearance where the fires inside whip around like tornados."
    );
    set_race("elemental");
    set_hd(20,30);
    set_level(20);
    set_property("magic",1);
    set_size(3);
    set_overall_ac(-10);
    set_class("fighter");
    set_guild_level("fighter",20);
    set_max_hp(350);
    set_hp(350);
    set_moving( 1 );
    set_speed ( 20 );
    set_wielding_limbs(({"flame wisp","s"}));
    add_limb("flame wisp","flame wisp",96,1,4);
    add_limb("fire tornado","fire tornado",96,1,4);
    add_limb("flaming skull like appendage","flaming skull like appendage",96,1,4);
    add_limb("intense heat","intense heat",96,1,4);
    set_attacks_num(2);
    set_attack_limbs(({"fire tornado","flame wisp","flaming skull like appendage","intense heat"}));
    set_base_damage_type("piercing");
    set_damage(1,12);
    set_body_type("arachnid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_mob_magic_resistance("high");
    set_property("full attacks",1);
    set_stats("strength",16);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(3500);
    set_alignment(9);
    set_emotes(3,({
	"%^BOLD%^%^RED%^Firebolt Influence torments you with words that strike you from within!",
      }),0);
      set_resistance("fire",20);
      set_resistance("cold",-20);
}
void die(object ob) {
    message("environment",
      "%^BOLD%^%^RED%^The flaming form dissipates before you.\n"
      "%^BOLD%^%^MAGENTA%^A glowing purple form rises from the ashes and vanishes into the sky!"
      ,environment(TO));
    :: die(ob);
}
int aggfunc() {
    string mrace=TP->query_race();
    if (mrace == "influence") {
	force_me ("say Greetings, brother...  Today, we kill.");
	return 1;
    } else {
	if(wizardp(TP)) return 1;
	TP->kill_ob(TO,0);
	force_me("emote grasps you with limbs of pure fire!");
    }
}
