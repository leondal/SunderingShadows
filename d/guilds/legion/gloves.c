#include <std.h>
inherit ARMOUR;

void create() {
     ::create();
    set_name("Gloves of Power");
    set_id( ({"legion gloves","gloves", "gloves of power", "Gloves", "Gloves of Power", "gauntlets"}) );
    set_short("%^BOLD%^%^BLUE%^Gloves of Power%^RESET%^");
    set_long(
      "These gloves are made of a strange silvery cloth, but much stronger.  These gloves slide over your hands and halfway up your forearms, to protect your arms.  The gloves themselves glow with a strange %^BOLD%^power%^RESET%^ that comes from deep from within the soul of the wearer.\n   %^CYAN%^There is an inscription on the gloves."
    );
    set_weight(1);
    set_value(1);
    set_ac(1);
    set_type("ring");
    set_limbs( ({"right hand", "left hand"}) );
}

int wear_me() {
    tell_object(TP, "You slide the gloves on, and a dull %^BOLD%^glow%^RESET%^ spreads across them.");
    tell_room(ETP, TPQCN+" slides on "+TP->query_possessive()+" Gloves of Power, and a dull %^BOLD%^glow%^RESET%^ spreads across them.", TP);
    return 1;
}

int remove_me() {
    tell_object(ETO, "You slide the gloves off, and the glow subsides.");
    tell_room(environment(query_worn()), ETO->query_cap_name()+" slides off the gloves, and they stop glowing.", ETO);
    return 1;
}

