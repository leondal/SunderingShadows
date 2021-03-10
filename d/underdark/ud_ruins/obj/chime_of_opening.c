#include <std.h>
#include <daemons.h>

inherit OBJECT;


void out_of_charges(object user);
void failure_msg(object user);
void do_locks();
int charges;

void create() {
    ::create();
    set_id(({"chime","tube","chime of opening","mithril tube"}));
    set_short(
        "%^RESET%^"
        "%^CYAN%^C%^BOLD%^h%^RESET%^%^CYAN%^i%^BOLD%^m%^RESET%^%^CYAN%^e "
        "%^BOLD%^of "
        "%^RESET%^%^CYAN%^O%^BOLD%^p%^RESET%^%^CYAN%^e%^BOLD%^n"
        "%^RESET%^%^CYAN%^i%^BOLD%^n%^RESET%^%^CYAN%^g%^WHITE%^"
    );
    set_obvious_short(
        "%^BOLD%^%^CYAN%^a thin "
        "m%^RESET%^%^CYAN%^i%^BOLD%^t%^RESET%^%^CYAN%^h%^BOLD%^r"
        "%^RESET%^%^CYAN%^i%^BOLD%^l tube%^RESET%^"
    );
    set_long(
        "%^CYAN%^This appears to be little more than a hollow tube of "
        "%^BOLD%^mithril%^RESET%^%^CYAN%^, about one foot long and slightly "
        "over an inch in diameter. While the metal is of high quality and would "
        "doubtless fetch a high price, there is little to hint at what its "
        "purpose might be."
    );
    set_lore(
        "%^CYAN%^The %^BOLD%^Chime of Opening %^RESET%^%^CYAN%^is a magical item "
        "commonly found in the employ of adventurers of bolder and overt "
        "dispositions, who often find themselves opposed by locked doors over "
        "the course of looting some random stranger's property. Fortunately, "
        "such annoyances are easily overcome with the use of this item - simply "
        "%^BOLD%^%^GREEN%^sound %^RESET%^%^CYAN%^the chime with a firm strike, "
        "and all doors within the user's proximity will spring their locks, "
        "provided they are not too complex.%^WHITE%^"
    );
    set_value(10000);
    set_weight(10);
    set_property("id difficulty", 20);
    set_property("lore difficulty", 20);
    charges = 10;
}

void init() {
    ::init();
    add_action("unlock", "sound");
}

int unlock(string str) {
    if (!objectp(TO)) { return 0; }
    if (!objectp(ETO)) { return 0; }
    if (!objectp(EETO)) { return 0; }
    if(ETO->query_bound() || ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }
    if (str != "chime") {
        return notify_fail("Sound what?");
    }
    if(charges <= 0) {
        out_of_charges(ETO);
        return 1;
    }
    charges--;
    if (!EETO->is_vault()) {
        failure_msg(ETO);
        return 1;
    }
    tell_object(ETO,
        "%^CYAN%^You strike the mithril chime, and a clear %^BOLD%^note "
        "%^RESET%^%^CYAN%^rings out over the area..."
    );
    tell_room(EETO,
        "%^CYAN%^"+ETO->QCN+" strikes a mithril chime, and a clear %^BOLD%^note "
        "%^RESET%^%^CYAN%^rings out over the area..."
    ,({ETO}));
    do_locks();
    return 1;
}

void out_of_charges(object user) {
    tell_object(user,
        "%^CYAN%^You strike the mithril chime, but it produces only a "
        "%^BOLD%^%^BLACK%^dull%^RESET%^%^CYAN%^, passionless tone."
    );
    tell_room(EETO,
        "%^CYAN%^"+user->QCN+" strikes a long mithril chime, but it produces only a "
        "%^BOLD%^%^BLACK%^dull%^RESET%^%^CYAN%^, passionless tone."
    ,({user}));
}

void failure_msg(object user) {
    tell_object(user,
        "%^CYAN%^The chime produces a clear, %^BOLD%^ringing "
        "%^RESET%^%^CYAN%^note that echoes throughout the area. ...however, "
        "nothing seems to have been affected."
    );
    tell_room(EETO,
        "%^CYAN%^As "+user->QCN+" strikes a long mithril chime, it produces a "
        "clear, %^BOLD%^ringing %^RESET%^%^CYAN%^note that echoes throughout "
        "the area. ...however, nothing seems to have been affected."
    ,({user}));
}

void do_locks() {
    mapping doors;
    string *dkeys, *tkeys;
    int i,j,opened;
    // Get a list of all doors with locked locks.
    doors = EETO->query_doors_map();
    if (!sizeof(doors)) {
        failure_msg(ETO);
        return;
    }
    opened = 0;
    dkeys = keys(doors);
    j = sizeof(dkeys);
    for(i=0;i<j;i++) {
        mapping door;
        string *cur_keys;
        int x,y;
        door = doors[dkeys[i]];
        cur_keys = keys(door);
        // Lock data should be the only mappings inside this mapping.
        y = sizeof(cur_keys);
        for(x=0;x<y;x++) {
            if (mapp(door[cur_keys[x]])) {
                int score;
                if(!EETO->query_locked(dkeys[i],cur_keys[x])) { continue; }
                score = 20 + roll_dice(1,10);
                if(door[cur_keys[x]]["mod"]) { score += door[cur_keys[x]]["mod"]; }
                if (score > 20) {
                    tell_room(EETO,
                        "%^CYAN%^The "+cur_keys[x]+" of the "+dkeys[i]+" clicks "
                        "open."
                    );
                    if(door[cur_keys[x]]["direction"]) {
                        tell_room(door[cur_keys[x]]["direction"],
                            "%^CYAN%^The "+cur_keys[x]+" of the "+dkeys[i]+" clicks "
                            "open."
                        );
                    }
                    EETO->set_locked(dkeys[i],0,cur_keys[x]);
                    opened++;
                }
            }
        }
    }
    if (!opened) {
        tell_room(EETO,
            "%^CYAN%^...nothing seems to have happened."
        );
    }
}

int isMagic() {
    if (charges <= 0) { return 0; }
    return 4;
}
