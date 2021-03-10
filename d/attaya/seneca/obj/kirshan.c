#include <std.h>
inherit "std/weapon";
string OWNER;
void init() {
    ::init();
    if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
}

void create() {
    ::create();
    set_name("dark kirshan");
    set_id(({"dark kirshan","kirshan","lightning dagger","dagger","lightning kirshan","dark lightning kirshan"}));
    set_short("Dark lightning kirshan");
    set_long(
      "This is a long black dagger used in the finest of the black arts.  It is carefully weighted and it's black steel blade is forged with runes said to have the power to chanel lightning from the gods.\nThe Dark Kirshan is hilted with black leather and the hilt end has a spine protruding from it."
    );
    set("value",2500);
    set_weight(10);
    set_wc(2,8);
    set_large_wc(2,10);
    set_size(1);
    set_type("slashing");
    set_property("enchantment",4);
    set_property("monsterweapon",1);

    set_wield((:this_object(), "extra_wield":));
    set_hit((:this_object(), "extra_hit":));
}
int extra_hit(object ob) {
    int dam;
    dam = random(2) + 1;
    if(random(25) > 1) return 0;
    message("my_action",
      "%^WHITE%^A bolt of lightning suddenly strikes the Dark kirshan and the blade glows white hot!"
      ,TP);
    message("other_action",
      "%^BOLD%^%^WHITE%^A bolt of lightning suddenly strikes "+TPQCN+"'s Dark kirshan and the blade glows white hot.\n"
      +ob->query_cap_name()+" is horribly burned in a blinding flash that leaves a trail of light in it's wake!%^RESET%^"
      ,environment(ob),(({TP, ob})));
    message("my_action",
      "%^BOLD%^%^WHITE%^A bolt of lightning suddenly strikes "+TPQCN+"'s Dark kirshan and the blade glows white hot!\n"
      "As the blade is thrust into you, you can feel a horrible searing of your flesh and bone and witness a brilliant flash of light!"
      ,ob);
    TP->heal(dam);
    set_property("magic",1);
    ob->do_damage("torso", random(150));
    remove_property("magic");
    return random(10)+5;
}
int extra_wield() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if(!interactive(tp)) return 1;
    if((int)TP->query_level() < 30) {
	notify_fail("%^BOLD%^%^RED%^A shadowy presence tells you: %^RESET%^You pathetic little fool, you cannot handle such power!");
	return 0;
    }
    if(!TP->is_class("thief")) {
	write("%^WHITE%^You are struck by lightning. It burns you horribly!");
	say("%^WHITE%^A bolt of lightning strikes "+TPQCN+"!");
	TP->do_damage("torso", random(150));
	return 0;
    }
    if((string)TP->query_name() != OWNER) {
	write("%^RED%^Such a weapon will not obey you.");
	return 0;
    }
    write(
      "The evil runes crackle with electricity as you grip this weapon"
    );
    say(
      "Something is not quite right with "+TPQCN+"."
    );
    return 1;
}

