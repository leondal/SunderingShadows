#include <std.h>
inherit OBJECT;
object owner;
int ATTACH,JOIN,SHEATH;

void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
    add_action("join_fun","join");
    add_action("insert_fun","insert");
    add_action("attach_fun","attach");
    add_action("sheath_fun","sheath");
}
void create() {
    ::create();
    set_name("scabbard");
    set_id(({"scabbard2","hm_quest_runes","scabbard of runes","scabbard"}));
    set_short("%^RESET%^%^GREEN%^Scabbard of runes%^RESET%^");
    set_long(
	"%^GREEN%^This fine crafted metal scabbard must have once been home to an ancient "
   "and powerful blade. Its design is the epitomy of perfection "
	"and the entire outer surface of it is covered in strange "
	"glowing runes of an unknown nature."
	"%^RESET%^"
    );
    set_weight(2);
    set_value(500);
    set_heart_beat(1);
}
void heart_beat() {
    object holder,env;
    if(!objectp(ETO)) return;
    env = ETO;
    if(interactive(env) ) {
        holder = env->query_true_name();
    } else {
	return;
    }
    if(holder != owner) {
	tell_object(env,
	    "The scabbard of runes vanishes!"
	);
	TO->remove();
        return;
    } else {
	return;
    }
}
int attach_fun(string str) {
    object hilt;
    object pommel;
    if((string)TP->query_name() != owner) return 0;
    if((int)TP->query_level() < 19) return 0;
    if(!str) {
	notify_fail("Attach what to what?\n");
	return 0;
    }
    if(str != "pommel to hilt") {
        notify_fail("Attach what to what?\n");
        return 0;
    }
    if(!present("pommel",TP)) {
	notify_fail("You don't even have a pommel!\n");
	return 0;
    }
    if(!present("hilt",TP)) {
	notify_fail("You don't even have a hilt!\n");
	return 0;
    }
    if(!(pommel = present("hm_quest_fang",TP))) {
	notify_fail("That pommel refuses to be attached to that hilt!\n");
	return 0;
    }
    if(!(hilt = present("hm_quest_mithril",TP))) {
	notify_fail("That pommel refuses to be attached to that hilt!\n");
	return 0;
    }
    if(ATTACH == 1) {
	notify_fail("This scabbard has already performed that action and may never do so again.\n");
	return 0;
    }
    write(
	"%^CYAN%^The scabbard flashes with a blaze!\n"
	"%^RED%^The scabbard's energy flows through you allowing you to "
	"attach the fang pommel to the mithril hilt!"
	"%^RESET%^"
    );
    ATTACH = 1;
    pommel->remove();
    hilt->set_short("Mithril hilt (pommel attached)");
    hilt->set_weight(4);
    return 1;
}
int join_fun(string str) {
    object hilt;
    object blade;
    if((string)TP->query_name() != owner) return 0;
    if((int)TP->query_level() < 19) return 0;
    if(!str) {
	notify_fail("Join what to what?\n");
	return 0;
    }
    if(str != "hilt to blade") {
        notify_fail("Join what to what?\n");
        return 0;
    }
    if(!present("hilt",TP)) {
	notify_fail("You don't even have a hilt!\n");
	return 0;
    }
    if(!present("blade",TP)) {
	notify_fail("You don't even have a blade!\n");
	return 0;
    }
    if(!(blade = present("hm_quest_silver",TP))) {
	notify_fail("That blade refuses to be joined to that hilt!\n");
	return 0;
    }
    if(!(hilt = present("hm_quest_mithril",TP))) {
	notify_fail("That blade refuses to be joined to that hilt!\n");
	return 0;
    }
    if(ATTACH != 1) {
	notify_fail("The blade fails to be joined to the hilt!\n");
        return 0;
    }
    if(JOIN == 1) {
	notify_fail("This scabbard has already performed that action and may never do so again.\n");
	return 0;
    }
    write(
	"%^CYAN%^The scabbard flashes with a blaze!\n"
	"%^RED%^The scabbard's energy flows through you allowing you to "
	"join the mithril hilt to the silver blade!"
	"%^RESET%^"
    );
    JOIN = 1;
    hilt->remove();
    blade->set_short("Silver blade (hilt joined)");
    blade->set_weight(14);
    return 1;
}
int sheath_fun(string str) {
    object scabbard;
    object blade;
    if((string)TP->query_name() != owner) return 0;
    if((int)TP->query_level() < 19) return 0;
    if(!str) {
	notify_fail("Sheath what in what?\n");
	return 0;
    }
    if(str != "blade in scabbard") {
        notify_fail("Sheath what in what?\n");
        return 0;
    }
    if(!present("scabbard",TP)) {
	notify_fail("You don't even have a scabbard!\n");
	return 0;
    }
    if(!present("blade",TP)) {
	notify_fail("You don't even have a blade!\n");
	return 0;
    }
    if(!(blade = present("hm_quest_silver",TP))) {
	notify_fail("That blade refuses to be sheathed in that scabbard!\n");
	return 0;
    }
    if(!(scabbard = present("hm_quest_runes",TP))) {
	notify_fail("That blade refuses to be sheathed in that scabbard!\n");
	return 0;
    }
    if(JOIN != 1) {
	notify_fail("The blade refuses to be sheathed in the scabbard!\n");
	return 0;
    }
    if(SHEATH == 1) {
	notify_fail("This scabbard has already performed that action and may never do so again.\n");
	return 0;
    }
    write(
	"%^CYAN%^The scabbard flashes with a blaze!\n"
	"%^RED%^The scabbard's energy flows through you allowing you to "
	"sheath the silver blade into the scabbard of runes!"
	"%^RESET%^"
    );
    SHEATH = 1;
    blade->remove();
    scabbard->set_short("Scabbard of runes (blade sheathed)");
    scabbard->set_weight(16);
    return 1;
}
int insert_fun(string str) {
    object scabbard;
    object gem;
    if((string)TP->query_name() != owner) return 0;
    if((int)TP->query_level() < 19) return 0;
    if(!str) {
	notify_fail("Insert what into what?\n");
	return 0;
    }
    if(str != "emerald into hilt" && str != "emerald into sword") {
        notify_fail("Insert what into what?\n");
        return 0;
    }
    if(!present("scabbard",TP)) {
	notify_fail("Time to think harder!\n");
	return 0;
    }
    if(!present("emerald",TP)) {
	notify_fail("You don't even have an emerald!\n");
	return 0;
    }
    if(!(gem = present("hm_quest_emerald",TP))) {
	notify_fail("That emerald refuses to be inserted "
	"into the sword of that scabbard!\n");
	return 0;
    }
    if(!(scabbard = present("hm_quest_runes",TP))) {
	notify_fail("That emerald refuses to be inserted into the "
	"sword of that scabbard!\n");
	return 0;
    }
    if(SHEATH != 1) {
	notify_fail("The emerald refuses to be inserted into the hilt of that "
	"scabbard!\n");
	return 0;
    }
    write(
	"%^CYAN%^The scabbard flashes with a blaze!\n"
	"%^RED%^The scabbard's energy flows through you allowing you to "
	"insert the emerald into the sword's mithril hilt that lays in the sheath of runes "
	"and has the fang pommel attached!\n"
	"%^BOLD%^%^BLUE%^The Sword of the Ages has been completed!"
	"%^RESET%^"
    );
    gem->remove();
// scabbard needs out of inventory so the sword doesn't get lost if they can't carry it, but can't be removed until after the command finishes.  *Styx*  5/20/03
    scabbard->move("/d/shadowgate/void");
    new("/d/hm_quest/obj/sword2.c")->move(TP);
    scabbard->remove();
    return 1;
}
