#include <std.h>

inherit MONSTER;

reset()
{
::reset();
}

void create() {
	int resist;
	object weapon;
	object armor;
	::create();

set_author("Svaha");
set_name("");
set_id("");
set("race","");
set_gender("");
set("short", "");
set("long", "");
set_level(#);
set_body_type("");
set_class("");
set("aggressive", #);
set_size(#);
set_stat("strength", #);
set_state("intelligence", #);
set_stat("wisdom", #);
set_stat("dexterity", #);
set_stat("constitution", #);
set_stat("charisma", #);
set_overall_ac(#);
set_max_mp(#);
set_mp(query_map_mp());
set_hd(#,#);
set_hp(#);
set_max_hp(#);
set_max_hp(query_hp());
set_sp(#);
set_wielding_limbs(({"", "", ""}));
set_languages(({'", ""}));
set_emotes(1, ({""}),0);
resist = +random(#) + random(#);
set_property("magical resistance", resist);
set_guild_level("");
st_spell_chance(#);
set_spells(({"", ""}));
set_achats(#, ({""}));
weapon = new("/d/etc/");
weapon->set_id(({""}));
weapon->set_author("");
weapon->set_name("");
weapon_set_id(({""}));
weapon->set_short("");
weapon->set_long("");
weapon->set_large_wc(#,#);
weapon->set_weight(#);
weapon->set_value(#);
command("wield");
armor = new("/d/dagger/etc");
armor->set_id(({""}));
armor->set_name("");
armor->set_id(({""}));
armor->set_short("");
armor->set_long("");
armor->set_limbs(({""}));
armor-set_ac(#);
armor->set_decay_rate(#);
armor->set_author("");
armor->move(this_object());
command("wield");
add_money("type", (#));
add_money("type", (#));
add_money("type", (#));

}
