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
    set_id(({"scabbard3","hm_quest_symbols","scabbard of symbols","scabbard"}));
    set_short("%^RESET%^%^MAGENTA%^Scabbard of symbols%^RESET%^");
    set_long(
	"%^MAGENTA%^This fine crafted metal scabbard must have once been home to an ancient "
   "and powerful blade. Its design is the epitomy of perfection "
	"and the entire outer surface of it is covered in strange "
	"glowing symbols of an unknown nature."
	"%^RESET%^"
    );
    set_weight(5);
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
	    "The scabbard of symbols vanishes!"
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
    if(!(pommel = present("hm_quest_bone",TP))) {
	notify_fail("That pommel refuses to be attached to that hilt!\n");
	return 0;
    }
    if(!(hilt = present("hm_quest_brass",TP))) {
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
	"attach the bone pommel to the brass hilt!"
	"%^RESET%^"
    );
    ATTACH = 1;
    pommel->remove();
    hilt->set_short("Brass hilt (pommel attached)");
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
    if(!(blade = present("hm_quest_bronze",TP))) {
	notify_fail("That blade refuses to be joined to that hilt!\n");
	return 0;
    }
    if(!(hilt = present("hm_quest_brass",TP))) {
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
	"join the brass hilt to the bronze blade!"
	"%^RESET%^"
    );
    JOIN = 1;
    hilt->remove();
    blade->set_short("Bronze blade (hilt joined)");
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
    if(!(blade = present("hm_quest_bronze",TP))) {
	notify_fail("That blade refuses to be sheathed in that scabbard!\n");
	return 0;
    }
    if(!(scabbard = present("hm_quest_symbols",TP))) {
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
	"sheath the bronze blade into the scabbard of symbols!"
	"%^RESET%^"
    );
    SHEATH = 1;
    blade->remove();
    scabbard->set_short("Scabbard of symbols (blade sheathed)");
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
    if(str != "diamond into hilt" && str != "diamond into sword") {
        notify_fail("Insert what into what?\n");
        return 0;
    }
    if(!present("scabbard",TP)) {
	notify_fail("Time to think harder!\n");
	return 0;
    }
    if(!present("diamond",TP)) {
	notify_fail("You don't even have a diamond!\n");
	return 0;
    }
    if(!(gem = present("hm_quest_diamond",TP))) {
	notify_fail("That diamond refuses to be inserted "
	"into the sword of that scabbard!\n");
	return 0;
    }
    if(!(scabbard = present("hm_quest_symbols",TP))) {
	notify_fail("That diamond refuses to be inserted into the "
	"sword of that scabbard!\n");
	return 0;
    }
    if(SHEATH != 1) {
	notify_fail("The diamond refuses to be inserted into the hilt of that "
	"scabbard!\n");
	return 0;
    }
    write(
	"%^CYAN%^The scabbard flashes with a blaze!\n"
	"%^RED%^The scabbard's energy flows through you allowing you to "
	"insert the diamond into the sword's brass hilt that lays in the sheath of symbols "
	"and has the bone pommel attached!\n"
	"%^BOLD%^%^BLUE%^The Sword of Fate has been completed!"
	"%^RESET%^"
    );
    gem->remove();
    scabbard->move("/d/shadowgate/void");
// scabbard needs out of inventory so the sword doesn't get lost if they can't carry it, but can't be removed until after the command finishes.  *Styx*  5/20/03
    new("/d/hm_quest/obj/sword3.c")->move(TP);
    scabbard->remove();
    return 1;
}
