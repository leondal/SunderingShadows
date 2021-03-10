//An abomidable snowman ... by Killashandra//
#include <std.h>
#include "short.h"
inherit MONSTER;

object *vars;
int i, count;
void create()
{
	::create();
	set_id(({ "yeti", "snowman", "abomidable snowman","monstrous humanoid" }));
	set_name("Yeti");
	set_short("A large Yeti");
	set_long(
		"%^WHITE%^%^BOLD%^This is a giant abomidable snowman covered by a thick coat of white " +
		"fur which blends in with the snow, making it hard to see.  It has " +
		"giant bare feet, strange tufted ears and small beady silver eyes. " +
		"This creature appears uneffected by the frigid cold ... don't you " +
		"wish you knew it's secret.  In it's hand it has a huge icicle which "
		"looks very sharp.%^RESET%^"
		);
	set_body_type("giant");
	set_race("yeti");
	set_gender("male");
	set_class("fighter");
	set_guild_level("fighter", 60);
	set_alignment(5);
	set_size(3);
	set_hd(35, 150);
	set_hp(350);
	set_exp(30000);
	set_overall_ac(-8);
	set("aggressive", 14);
	set_property("full attacks", 1);
	set_mob_magic_resistance("average");
	set_wielding_limbs(({ "left hand", "right hand" }));
	set_stats("strength", 20);
	set_stats("dexterity", 14);
	add_money("gold", random(5000) + 3000);
	set_funcs(({ "breath", "snowball", "spells" }));
	set_func_chance(40);
	new(OPATH "icicle.c")->move(this_object());
	command("wield icicle");
	new(OPATH "icicle.c")->move(this_object());
	command("wield icicle");
	new(OPATH "yeti_fur.c")->move(this_object());
	command("wear fur");
}


void breath(object targ)
{
	if (!"/daemon/saving_d"->saving_throw(targ, "breath_weapon", -4)) {
		tell_object(targ, "%^BOLD%^WHITE%^The Yeti takes a deep breath and blows a freezing coud of icy air in your face!%^RESET%^");
		tell_room(ETO, "%^BOLD%^WHITE%^The Yeti blows it's frosty breath on " + targ->query_cap_name() + " causing them to freeze in their tracks!%^RESET%^", targ);
		targ->cause_typed_damage(targ, "torso", roll_dice(5, 10), "cold");
		targ->set_paralyzed(40, "You are frozen stiff");
		return 1;
	}
	tell_object(targ, "%^BOLD%^WHITE%^The Yeti blows it's frosty breath at you but you dodge out of the way!%^RESET%^");
	tell_room(ETO, "%^BOLD%^WHITE%^The Yeti blows it's frosty breath on " + targ->query_cap_name() + ", but " + targ->query_objective() + " manages to dodge out of the way.", targ);
	return 1;
}


void snowball(object targ)
{
	int roll, ac;
	roll = random(20);
	ac = targ->query_ac();
	if (roll > 0 - ac) {
		tell_object(targ, "%^BOLD%^CYAN%^The Yeti hits you with a massive snowball!%^RESET%^");
		tell_room(ETO, "%^BOLD%^CYAN%^The Yeti hits " + targ->query_cap_name() + " with a giant snowball!%^RESET%^", targ);
		targ->cause_typed_damage(targ, "torso", roll_dice(4, 12), "bludgeoning");
	} else {
		tell_object(targ, "%^BOLD%^CYAN%^The Yeti throws a giant snowball at you but misses!%^RESET%^");
		tell_room(ETO, "%^BOLD%^CYAN%^The Yeti throws a giant snowball at " + targ->query_cap_name() + "  but misses!%^RESET%^", targ);
	}
	return 1;
}


int spells()
{
	object ob = this_object();
	object targ = ob->query_current_attacker();
	int xx;

	xx = random(4) + 1;
	switch (xx) {
	case 1:
		/* cast chill touch */
		new("/cmds/spells/c/_chill_touch.c")->use_spell(TO, targ->query_name(), 40, 100, "mage");
		return 1;
	case 2:
		/* cast cone of cold */
		new("/cmds/spells/c/_cone_of_cold.c")->use_spell(TO, targ->query_name(), 40, 100, "mage");
		return 1;
	case 3:
		/* cast ice storm */
		new("/cmds/spells/i/_ice_storm.c")->use_spell(TO, targ->query_name(), 40, 100, "mage");
		return 1;
	case 4:
		/* cast stoneskin */
		new("/cmds/spells/s/_stoneskin.c")->use_spell(TO, TO->query_name(), 40, 100, "mage");
		return 1;
	}
	return 1;
}


void heart_beat()
{
	::heart_beat();
	if (query_hp() < 20 && count > 10) {
		count = 0;
		vars = all_living(ETO);
		for (i = 0; i < sizeof(vars); i++) {
			if (vars[i] == TO) continue;
			tell_object(vars[i], "%^BOLD%^WHITE%^The Yeti tries to step on you!%^RESET%^");
			if (!"/daemon/saving_d"->saving_throw(vars[i], "paralyzation_poison_death", -4)) {
				tell_object(vars[i], "%^BOLD%^WHITE%^You are squished under the Yeti's massive foot!%^RESET%^");
				vars[i]->cause_typed_damage(vars[i], "torso", roll_dice(3, 20), "bludgeoning");
			} else {
				tell_object(vars[i], "%^BOLD%^WHITE%^You only get a glancing blow from the descending foot!%^RESET%^");
				vars[i]->cause_typed_damage(vars[i], "torso", roll_dice(3, 10), "bludgeoning");
			}
		}
	}
	if (query_hp() < 20) count++;
}
void set_paralyzed(int time, string message)
{
	return 1;
}
