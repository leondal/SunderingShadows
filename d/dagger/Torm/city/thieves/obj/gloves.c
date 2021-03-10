#include <std.h>
inherit "/d/common/obj/clothing/gloves";

void create() {
     ::create();
    set_name("Gloves of Power");
    set_id( ({"legion gloves","gloves", "gloves of power", "Gloves", "Gloves of Power", "gauntlets"}) );
    set_short("%^BOLD%^%^BLUE%^Gloves of Power%^RESET%^");
    set_long(
      "These gloves are made of a strange silvery cloth, but much stronger.  These gloves slide over your hands and halfway up your forearms, to protect your arms.  The gloves themselves glow with a strange %^BOLD%^power%^RESET%^ that comes from deep from within the soul of the wearer.\n   %^CYAN%^There is an inscription on the gloves."
    );
    set_lore("These silvery gloves were crafted "+
    "for the Legion of Lost Souls guild, dedicated"+
    " to the acquisition of power at any cost.  "+
    "Nobody knows where Beowulf had them commissioned,"+
    " but only a limited number were ever constructed.  "+
    "Legends speak of a unique power granted by the "+
    "gloves.  When worn, they would allow the wearer"+
    " to throw their voice and mimic others, tricking"+
    " any listeners into thinking someone else had"+
    " spoken.  Unfortunately, it appears whatever"+
    " enchantment they had once been imbued with "+
    "has long since faded.");
    set_property("lore difficulty",26);
    set_wear((:TO,"wear_me":));
    set_remove((:TO,"remove_me":));
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

