#include <std.h>

inherit "/d/common/obj/jewelry/necklace";

int stored;
string psion_name;

void create() {
    ::create();
    set_name("clasp of attunement");
    set_id(({"clasp","neck clasp","amethyst clasp","attunement clasp"}));
    set_short(
        "%^RESET%^"
        "%^MAGENTA%^C%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^MAGENTA%^s"
        "%^RESET%^%^MAGENTA%^p of "
        "A%^BOLD%^tt%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^n%^RESET%^e"
        "%^MAGENTA%^m%^BOLD%^e%^RESET%^%^MAGENTA%^nt%^WHITE%^"
    );
    set_obvious_short(
        "%^RESET%^"
        "%^MAGENTA%^a simple "
        "a%^BOLD%^m%^WHITE%^e%^MAGENTA%^t%^RESET%^%^MAGENTA%^h%^BOLD%^ys"
        "%^RESET%^%^MAGENTA%^t neck clasp%^WHITE%^"
    );
    set_long(
        "%^MAGENTA%^This simple piece of jewelry is little more than three "
        "intertwined wires of r%^ORANGE%^o%^BOLD%^%^RED%^s%^RESET%^%^MAGENTA%^e "
        "g%^RED%^o%^BOLD%^l%^RESET%^%^MAGENTA%^d that would fit snugly against "
        "the wearer's throat. The wires twist into a simple lattice at the front, "
        "holding a small, uncut piece of "
        "%^BOLD%^a%^RESET%^%^MAGENTA%^m%^BOLD%^et%^RESET%^%^MAGENTA%^h%^BOLD%^y"
        "%^RESET%^%^MAGENTA%^s%^BOLD%^t %^RESET%^%^MAGENTA%^that gives off a "
        "soft purple g%^BOLD%^l%^RESET%^%^MAGENTA%^ow.%^WHITE%^"
    );
    set_lore(
        "%^MAGENTA%^The art of recording sentient thought into crystal, "
        "otherwise known as %^BOLD%^attunement%^RESET%^%^MAGENTA%^, is one "
        "well documented and studied by the psionically inclined, but to date "
        "no reliable methods have been found to produce an attuned gem that might "
        "have its information extracted without cracking or otherwise becoming "
        "unusable. Those that do display these properties tend to arise "
        "naturally, often from exposure to large-scale strife or tragedy. This "
        "particular piece was most likely a simple piece of jewelry at one point, "
        "but the amethyst set into it has become particularly receptive to "
        "psionic energies. A skilled psionicist may be able to "
        "%^BOLD%^%^CYAN%^impart %^RESET%^%^MAGENTA%^a portion of their power "
        "points into the gemstone, and %^BOLD%^%^CYAN%^extract "
        "%^RESET%^%^MAGENTA%^them again at a later time.%^WHITE%^"
    );
    set_wear((:TO, "wear_func":));
    set_remove((:TO, "remove_func":));
    set_value(3000);
    set_property("id difficulty", 20);
    set_property("lore difficulty", 25);
    set_property("enchantment", 4);
    set_item_bonus("mental resistance", 10);
    set_item_bonus("caster level",1);
    psion_name = 0;
    stored = 0;
}

void init() {
    ::init();
    add_action("impart_func","impart");
    add_action("extract_func","extract");
}

int wear_func() {
    if(ETO->query_class_level("psion") || ETO->query_class_level("psywarrior")) {
        tell_object(ETO,
            "%^MAGENTA%^As you affix the simple piece of jewelry to your neck, "
            "you sense the amethyst begin to %^BOLD%^resonate "
            "%^RESET%^%^MAGENTA%^softly with your own %^BOLD%^%^CYAN%^mental "
            "energy%^RESET%^%^MAGENTA%^."
        );
    }
    else {
        tell_object(ETO,
            "%^MAGENTA%^As you affix the simple piece of jewelry to your neck, "
            "you feel a faint %^BOLD%^%^CYAN%^tingle %^RESET%^%^MAGENTA%^run "
            "through you."
        );
    }
    tell_room(EETO,
        "%^MAGENTA%^"+ETO->QCN+" affixes the %^BOLD%^amethyst "
        "%^RESET%^%^MAGENTA%^clasp to "+ETO->QP+" neck."
    ,({ETO}));
    return 1;
}

int remove_func() {
    if(ETO->query_class_level("psion") || ETO->query_class_level("psywarrior")) {
        tell_object(ETO,
            "%^MAGENTA%^You feel your attunement to the %^BOLD%^amethyst "
            "%^RESET%^%^MAGENTA%^slip away as you remove it from your neck."
        );
    }
    else {
        tell_object(ETO,
            "%^MAGENTA%^You remove the %^BOLD%^amethyst "
            "%^RESET%^%^MAGENTA%^clasp, and a faint %^CYAN%^buzzing "
            "%^MAGENTA%^you hadn't noticed grows suddenly silent.%^WHITE%^"
        );
    }
    tell_room(EETO,
        "%^MAGENTA%^"+ETO->QCN+" removes the %^BOLD%^amethyst "
        "%^RESET%^%^MAGENTA%^clasp."
    ,({ETO}));
    return 1;
}

int impart_func(string str) {
    int mp,max_mp,to_store;
    if(!objectp(TO)) { return 0; }
    if(!objectp(ETO)) { return 0; }
    if(ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }
    if(!(ETO->query_class_level("psion") || ETO->query_class_level("psywarrior"))) {
        return notify_fail("You lack the skill to do that.\n");
    }
    if(!query_worn()) {
        tell_object(ETO,
            "%^MAGENTA%^You must be wearing the clasp to do that."
        );
        return 1;
    }
    if (stored) {
        tell_object(ETO,
            "%^BOLD%^%^CYAN%^Mental energies %^RESET%^%^MAGENTA%^already swirl "
            "within the amethyst. You will not be able to add any more.%^WHITE%^"
        );
        return 1;
    }
    mp = ETO->query_mp();
    if (!mp) {
        tell_object(ETO,
            "%^MAGENTA%^You have no power points to store."
        );
        return 1;
    }
    max_mp = ETO->query_max_mp();
    to_store = (int)ETO->query_max_mp() / 10;
    if (to_store > mp) { to_store = mp; }
    tell_object(ETO,
        "%^MAGENTA%^You place a finger to the amethyst upon your neck and close "
        "your eyes, %^BOLD%^%^CYAN%^imbuing %^RESET%^%^MAGENTA%^the gem with a "
        "portion of your consciousness.%^WHITE%^"
    );
    tell_room(EETO,
        "%^MAGENTA%^"+ETO->QCN+" places a finger to the %^BOLD%^amethyst "
        "%^RESET%^%^MAGENTA%^upon "+ETO->QP+" neck and concentrates for a moment."
    ,({ETO}));
    stored = to_store;
    psion_name = ETO->query_name();
    ETO->set_mp(mp - to_store);
    tell_object(ETO,
        "%^YELLOW%^You stored away %^GREEN%^"+to_store+" %^ORANGE%^power points."
    );
    return 1;
}

int extract_func(string str) {
    int mp,max_mp, restored;
    if(!objectp(TO)) { return 0; }
    if(!objectp(ETO)) { return 0; }
    if(ETO->query_unconscious()) {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }
    if(!(ETO->query_class_level("psion") || ETO->query_class_level("psywarrior"))) {
        return notify_fail("You lack the skill to do that.\n");
    }
    if(!query_worn()) {
        tell_object(ETO,
            "%^MAGENTA%^You must be wearing the clasp to do that."
        );
        return 1;
    }
    if (!stored) {
        tell_object(ETO,
            "%^MAGENTA%^There is nothing stored inside of the amethyst."
        );
        return 1;
    }
    if (!psion_name) {
        tell_object(ETO,
            "%^MAGENTA%^The energies inside the amethyst have become corrupted. "
            "(%^BOLD%^%^RED%^OOC: %^RESET%^Error! Please pass this message "
            "on to a wiz.%^MAGENTA%^)"
        );
        return 1;
    }
    if (psion_name != (string)ETO->query_name()) {
        tell_object(ETO,
            "%^MAGENTA%^The psionic energies within the amethyst are foreign to "
            "you - you will not be able to assimilate it with your own."
        );
        return 1;
    }
    // This next check is just to keep players from carrying a billion of these
    // around for infinite power points - may implement a different check later
    // if this doesn't work.
    if (time() - (int)ETO->query_property("last clasp extract") < 300) {
        tell_object(ETO,
            "%^MAGENTA%^Your mind cannot handle another burst of mental "
            "energies so soon!"
        );
        return 1;
    }
    mp = ETO->query_mp();
    max_mp = ETO->query_max_mp();
    if(mp == max_mp) {
        tell_object(ETO,
            "%^MAGENTA%^You have already prepared as much mental energy as your "
            "mind can hold. Extracting more from the amethyst now would be "
            "dangerous."
        );
        return 1;
    }
    tell_object(ETO,
        "%^BOLD%^%^MAGENTA%^You reach out to the amethyst around your neck with "
        "your mind, willing the %^CYAN%^mental energy %^MAGENTA%^stored within "
        "to return!"
    );
    tell_room(EETO,
        "%^BOLD%^%^MAGENTA%^"+ETO->QCN+" closes "+ETO->QP+" eyes and concentrates "
        "for a moment. The amethyst around "+ETO->QP+" neck %^CYAN%^glows "
        "%^MAGENTA%^brightly for an instant!"
    ,({ETO}));
    ETO->set_property("last clasp extract", time());
    restored = 0;
    if (mp + stored > max_mp) {
        restored = max_mp - mp;
        ETO->set_mp(max_mp);
    }
    else {
        restored = stored;
        ETO->set_mp(mp + stored);
    }
    stored = 0;
    psion_name = 0;
    tell_object(ETO,
        "%^YELLOW%^You restored %^GREEN%^"+restored+" %^ORANGE%^power points."
    );
    return 1;
}
