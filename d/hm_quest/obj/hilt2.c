#include <std.h>
inherit OBJECT;

string owner;
int ATTACH;

void create() {
    ::create();
    set_name("hilt");
    set_id(({"hilt2","hm_quest_mithril","mithril hilt","hilt"}));
    set_short("%^BOLD%^%^CYAN%^Mithril hilt%^RESET%^");
    set_long("%^RESET%^This %^BOLD%^%^CYAN%^mithril hilt %^RESET%^appears to be a remnant of a sword, long since detached from the blade that was once inset to the simple guard it bears at the "
"top. It still %^BOLD%^%^WHITE%^glows %^RESET%^with a faint magical aura, despite being separated from the rest of the weapon. Stranger still, there is a depression in the center of the hilt "
"that appears to have held a %^YELLOW%^jewel %^RESET%^at one time, but it has long since been pried out. At the furthest end, a few notches remain where a pommel-stone must once have been, "
"enough so that you could attach another if you could find one to fit.%^RESET%^");
    set_weight(2);
    set_value(0);
    set_heart_beat(1);
}

void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
    add_action("attach_fun","attach");
}

void heart_beat() {
    string holder;
    if(!objectp(ETO)) return;
    if(!interactive(ETO)) return;
    holder = ETO->query_true_name();
    if(holder != owner) {
      tell_object(ETO,"The mithril hilt vanishes!");
      TO->remove();
    }
}

int attach_fun(string str) {
    object pommel;
    if((string)TP->query_name() != owner) return 0;
    if((int)TP->query_level() < 19) return 0;
    if(!str) {
	notify_fail("Attach what to what?\n");
	return 0;
    }
    if(str != "pommel to hilt" && str != "hilt to pommel") {
      notify_fail("You can't attach that.\n");
      return 0;
    }
    if(ATTACH) {
	notify_fail("A suitable pommel is already attached to this hilt!\n");
	return 0;
    }
    if(!pommel = present("hm_quest_fang",TP)) {
	notify_fail("You don't have a pommel suitable to attach to that hilt!\n");
	return 0;
    }
    if(base_name(pommel) != "/d/hm_quest/obj/pommel2") {
	notify_fail("That pommel refuses to be attached to that hilt!\n");
	return 0;
    }
    tell_object(TP,"%^CYAN%^The magical energy around both the pommel and the hilt flares brightly as they are brought together, and they settle perfectly into place, one attached to the other.%^RESET%^");
    ATTACH = 1;
    pommel->remove();
    set_short("%^BOLD%^%^CYAN%^Mithril hilt (pommel attached)%^RESET%^");
    set_long("%^RESET%^This %^BOLD%^%^CYAN%^mithril hilt %^RESET%^appears to be a remnant of a sword, long since detached from the blade that was once inset to the simple guard it bears at the "
"top. It still %^BOLD%^%^WHITE%^glows %^RESET%^with a faint magical aura, despite being separated from the rest of the weapon. Stranger still, there is a depression in the center of the hilt "
"that appears to have held a %^YELLOW%^jewel %^RESET%^at one time, but it has long since been pried out. At the furthest end lies a fang-shaped pommel-stone, heavy enough to serve as a sturdy "
"counterweight. A narrow notch lies within the guard, where you're sure it could be joined to a suitable blade.%^RESET%^");
    set_weight(4);
    return 1;
}

int is_attached() { return ATTACH; }