#include <std.h>
inherit WEAPON;
int charges;

void query_charges();
void set_charges(int x);
void adj_charges(int x);

void create(){
	::create();
	set_name("staff");
	set_id(({ "staff", "winters chill", "staff of winters chill",
    "winters chill staff","graystaff","graywood staff"}));

	set_obvious_short("A gnarled gray wood staff with an ice blue orb");

    set_short("%^BOLD%^%^WHITE%^Staff of w%^BLUE%^i%^BOLD%^%^WHITE%^"+
    "nt%^BLUE%^e%^BOLD%^%^WHITE%^r's ch%^RESET%^%^CYAN%^i"+
    "%^BOLD%^%^WHITE%^ll%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This staff is made from a %^BLUE%^"+
    "mysterious%^BOLD%^%^WHITE%^ gray and gnarled piece of wood "+
    "that spans approximately eight feet in length.  The entire staff "+
    "is strangely thin, yet widens to more than three times its "+
    "thickness right as it reaches its furthest end.  The wood "+
    "is engraved with strange designs that run the entire "+
    "length of the staff, most of the designs are that of "+
    "%^BOLD%^%^BLUE%^icy blue%^BOLD%^%^WHITE%^ fingers that "+
    "twist and stretch toward the top of the staff.  The fingers "+
    "appear to be reaching toward the %^CYAN%^ice blue orb"+
    "%^BOLD%^%^WHITE%^ that sits carefully and firmly at the "+
    "top of the staff.  The %^CYAN%^orb%^BOLD%^%^WHITE%^ is "+
    "set deep into the thickest part of the wood, with only the "+
    "top of its smooth and reflective surface being visible.  "+
    "As you gaze at the staff and let your eyes linger over the "+
    "length of it, you notice another design, this one of two "+
    "%^RESET%^%^BLUE%^deep blue eyes%^BOLD%^%^WHITE%^ in almost "+
    "the exact center of the staff.  An almost invisible "+
    "%^BLUE%^inscription%^BOLD%^%^WHITE%^ rests between the "+
    "two eyes.%^RESET%^");

	set_read("%^CYAN%^Winter's fury is never long dormant, %^RESET%^\n\n"+
    "You may send the %^BLUE%^frost%^RESET%^ of winter against him, \n"+
    "You may make him %^BLUE%^absorb%^RESET%^ the cold\n"+
    "and you may %^BLUE%^chill%^RESET%^ him with its touch.\n");

    set_lore("%^CYAN%^These staves were formed with the sole "+
    "purpose of causing others to respect the cold of winter.  "+
    "They were not formed for either evil or good, but rather to "+
    "open the eyes of those who do not regard winter with respect.  "+
    "Legends suggest that an obsessed mage who may have frequently "+
    "paid homage to the ice maiden created them and bestowed upon them "+
    "several magics that would lend them aid in completing what "+
    "he intended for them.%^RESET%^");

    set("langage",!random(2) ? "elven" : "common");
    set_weight(7);

    set_value(5000);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(3);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",3);
    charges = 10 + random(11);
    set_item_bonus("cold resistance", 10);
    set_wield((:TO,"wield_me":));
}

int wield_me() {
    if(ETO->query_highest_level() < 15) {
        write("The brutal cold of the staff seeps into you and "+
        "prevents you from grasping it!%^RESET%^");
        set_property("magic",1);
        ETO->do_damage("right hand",roll_dice(6,6));
        set_property("magic",-1);
        return 0;
    }
    write("%^BLUE%^You grasp the staff and your hands ache from the "+
    "sudden, intense cold!%^RESET%^");
    ETO->do_damage("left hand",roll_dice(1,6));
    return 1;
}

void query_charges() {
    return charges;
}

void set_charges(int x) {
    charges = x;
}

void adj_charges(int x) {
    charges = charges + x;
}

void init(){
    ::init();
    charges = 10 + random(11);
    add_action("frost_fingers","frost");
    add_action("chill_touch","chill");
    add_action("cone_of_cold","absorb");
}

void failure() {
    write("The staff fails to respond to your command.");
    return 1;
}

void msg(object ob) {
     ETO->set_paralyzed(3,"%^BLUE%^You are using the staff!%^RESET%^");
     write("%^BLUE%^You begin chanting loudly, pointing the "+
     "staff at "+ ob->QCN+"%^BLUE%^!%^RESET%^");
     tell_room(EETO,ETOQCN+"%^BLUE%^ begins chanting loudly, "+
     "pointing "+ETO->QP+" staff at "+ob->QCN+"%^BLUE%^!"+
     "%^RESET%^",({ETO,ob}));
     tell_object(ob,ETOQCN +"%^BLUE%^ begins chanting loudly, "+
     "pointing "+ETO->QP+" staff at you!%^RESET%^");
}

int frost_fingers(string str) {
    object ob;
    int spe;
    spe = 2;

    if(ETO->query_unconscious() || ETO->query_bound()
    || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }

    if(!str && query_wielded()) {
        write("Who do you want to send the %^BLUE%^frost%^RESET%^"+
        " of winter against?");
        return 1;
    }

    if(charges <= 0 || !query_wielded() || charges - spe < 0) {
        failure();
        return 1;
    }

    if(ob = present(str,EETO)) {
        if(living(ob) && objectp(ob)) {
            msg(ob);
            adj_charges(-spe);
            new("/cmds/spells/f/_frost_breath")->use_spell(ETO,ob,10,100,"cleric");
            return 1;
        }
    }
    write("You see no such target here.");
    return 1;
}

int chill_touch(string str) {
    object ob;
    int spe;
    spe = 1;

    if(ETO->query_unconscious() || ETO->query_bound()
    || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }

    if(!str && query_wielded()) {
        write("Who do you want to %^BLUE%^touch%^RESET with the "+
        "chill of winter?");
        return 1;
    }

    if(charges <= 0 || !query_wielded() || charges - spe < 0) {
        failure();
        return 1;
    }

    if(ob = present(str,EETO)) {
        if(living(ob) && objectp(ob)) {
            msg(ob);
            adj_charges(-spe);
            new("/cmds/spells/c/_chill_touch")->use_spell(ETO,ob,10,10,"mage");
            return 1;
        }
    }
    write("You see no such target here.");
    return 1;
}

int cone_of_cold(string str) {
    object ob;
    int spe;
    spe = 3;

    if(ETO->query_unconscious() || ETO->query_bound()
    || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }

    if(!str && query_wielded()) {
        write("Who do you want to force to %^BLUE%^absorb%^RESET%^ "+
        "the cold of winter?");
        return 1;
    }

    if(charges <= 0 || !query_wielded() || charges - spe < 0) {
        failure();
        return 1;
    }

    if(ob = present(str,EETO)) {
        if(living(ob) && objectp(ob)) {
            msg(ob);
            adj_charges(-spe);
            new("/cmds/spells/c/_cone_of_cold")->use_spell(ETO,ob,12,100,"mage");
            return 1;
        }
    }
    write("You see no such target here.");
    return 1;
}
