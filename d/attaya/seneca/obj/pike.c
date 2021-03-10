#include <std.h>
inherit "std/weapon";
string OWNER;
void init() {
    ::init();
    if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
}

void create() {
    ::create();
    set_name("pike");
    set_id(({"bloody pike","pike","polearm"}));
    set_short("%^RED%^Bloody pike%^RESET%^");
    set_long(
      "This is a long polearm with a large spearpoint at the end.  The point itself is gruesome and is a three bladed barb that tapers back to inverted hooks.  It is nearly a foot long and designed to penetrate armor."
    );
    set("value",1000);
    set_weight(50);
    set_wc(2,4);
    set_large_wc(2,6);
    set_size(3);
    set_type("piercing");
    set_property("enchantment",1);
    set_prof_type("polearm");

    set_wield((:this_object(), "extra_wield":));
    set_hit((:this_object(), "extra_hit":));
}
int extra_hit(object ob) {
    int dam;
    dam = random(2) + 1;
    if(random(25) > 1) return 0;
    message("my_action",
      "%^RED%^You draw back your Bloody pike and thrust it foreward piercing "+ob->query_cap_name()+"'s armor and running it through "+ob->query_possessive()+" lung!"
      ,TP);
    message("other_action",
      "%^RED%^"+TPQCN+" draws back "+TP->query_possessive()+" Bloody pike and runs it through "+ob->query_cap_name()+"!\n"
      +ob->query_cap_name()+" screams in pain and horror!"
      ,environment(ob),(({TP, ob})));
    message("my_action",
      "%^BOLD%^%^RED%^"+TPQCN+" draws back "+TP->query_possessive()+" Bloody pike and thrusts it through your lung, piercing your armor!\n"
      "%^CYAN%^You let out a horrible scream of pain!"
      ,ob);
    TP->heal(dam);
    set_property("magic",1);
    ob->do_damage("toroso", random(15)+5);
    remove_property("magic");
    return random(5);
}
int extra_wield() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if(!interactive(tp)) return 1;
    if((int)TP->query_level() < 30) {
	notify_fail("You are not yet experienced enough to benefit from this weapon.");
	return 0;
    }
    if((string)TP->query_name() != OWNER) {
	write("%^RED%^Such a weapon will not obey you.");
	return 0;
    }
    write(
      "You place your hands tightly around the grips on the pike and prepare for combat."
    );
    return 1;
}

