// updated bonuses to meet current standards. N, 24/1/20.
#include <std.h>
inherit "/std/armour";

int OWNED;
string* owners;

void create()
{
    ::create();
    set_name("bracelets");
    set_short("%^BOLD%^%^WHITE%^twin pl%^CYAN%^a%^WHITE%^tin%^CYAN%^u%^WHITE%^m bracelets%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^twin pl%^CYAN%^a%^WHITE%^tin%^CYAN%^u%^WHITE%^m bracelets%^RESET%^");
    set_id(({ "bracelets", "twin bracelets", "platinum bracelets", "twin platinum bracelets" }));
    set_long("Fine strands of pristine %^BOLD%^%^WHITE%^pl%^CYAN%^a%^WHITE%^tin"
             "%^CYAN%^u%^WHITE%^m %^RESET%^metal shapes these twin bracelets, each a perfect "
             "%^BOLD%^%^CYAN%^mir%^WHITE%^r%^CYAN%^or %^RESET%^image of the other. The "
             "strands themselves appear to be interwoven along the upper surface of each, "
             "though underneath they form a flat, melded surface that sits %^RED%^co"
             "%^MAGENTA%^mf%^RED%^or%^MAGENTA%^ta%^RED%^bl%^MAGENTA%^y %^RESET%^upon the arm"
             ". In amongst the strands are tiny flecks of %^BOLD%^%^BLUE%^sa%^CYAN%^p%^BLUE%^"
             "phi%^CYAN%^r%^BLUE%^e%^RESET%^, cut to catch and refract light in %^GREEN%^ex"
             "%^CYAN%^qu%^GREEN%^is%^CYAN%^it%^GREEN%^e %^RESET%^patterns. Upon the underside "
             "of the bracelet are etched runes in some ornate, unfamiliar script that forms "
             "flowing whorls across the %^BOLD%^%^WHITE%^br%^CYAN%^i%^WHITE%^ght %^RESET%^"
             "metal.\n");
    set_lore("These pristine bracelets are known throughout history's pages as a "
             "highly prized artifact of ancient high-elven make. Crafted by the unparalleled "
             "magics that have long since been lost to the centuries after the Crown Wars, "
             "they were said to be so skillfully made that they would adapt to any person "
             "that wore them, enhancing and empowering the magical capacity of any kind of "
             "spellcaster.");
    set_property("lore difficulty", 35);
    set_property("id difficulty", 35);
    set_weight(5);
    set_value(2000);
    set_type("clothing");
    set_limbs(({ "right arm", "left arm" }));
    set_ac(0);
    set_size(-1);
    set_wear((: TO, "wearme" :));
    set_remove((: TO, "removeme" :));
    set_property("repairtype", ({ "jewel" }));
    set_property("no alter", 1);
    set_item_bonus("spell penetration", 3);
    set_item_bonus("caster level", 2);
    owners = ({});
}

int wearme()
{
    if (member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^", ETO->query_mini_quests()) == -1) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
        return 0;
    }
    if (!ETO->is_class("cleric") && !ETO->is_class("oracle") && !ETO->is_class("mage") && !ETO->is_class("psion") && !ETO->is_class("psywarrior") && !ETO->is_class("bard") && !ETO->is_class("sorcerer") && !ETO->is_class("druid") && !ETO->is_class("warlock") && !ETO->is_class("inquisitor") && !ETO->is_class("magus")) {
        tell_object(ETO, "You cannot seem to focus clearly enough to wear the bracelets.");
        return 0;
    }
    if (ETO->query_level() < 35) {
        tell_object(ETO, "You are not experienced enough to use these bracelets.");
        return 0;
    }
    tell_object(ETO, "%^RESET%^%^CYAN%^You feel your concentration %^BOLD%^"
                "sharpen %^RESET%^%^CYAN%^as you slide the bracelets over each wrist, and they "
                "begin to %^ORANGE%^glow%^CYAN%^ with a soft magical aura.%^RESET%^");
    tell_room(EETO, "%^RESET%^%^CYAN%^" + ETO->QCN + " slides the bracelets over each "
              "wrist, and they begin to %^ORANGE%^glow%^CYAN%^ with a soft magical aura."
              "%^RESET%^", ETO);
    if (ETO->is_class("cleric")) {
        TO->set_short("%^BOLD%^%^WHITE%^Bracelets of %^RESET%^%^ORANGE%^Di%^YELLOW%^vi%^RESET%^%^ORANGE%^ne %^YELLOW%^Fo%^RESET%^%^ORANGE%^cu%^YELLOW%^s%^RESET%^");
    }
    if (ETO->is_class("psion") || ETO->is_class("psywarrior")) {
        TO->set_short("%^BOLD%^%^WHITE%^Bracelets of %^RESET%^%^RED%^Me%^BOLD%^%^BLACK%^nt%^RESET%^%^RED%^al %^BOLD%^%^BLACK%^Cl%^RESET%^%^RED%^ar%^BOLD%^%^BLACK%^it%^RESET%^%^RED%^y%^RESET%^");
    }
    if (ETO->is_class("mage") || ETO->is_class("sorcerer")) {
        TO->set_short("%^BOLD%^%^WHITE%^Bracelets of %^RESET%^%^CYAN%^Ar%^GREEN%^ca%^CYAN%^ne %^GREEN%^Pr%^CYAN%^ec%^GREEN%^is%^CYAN%^io%^GREEN%^n%^RESET%^");
    }
    if (ETO->is_class("bard")) {
        TO->set_short("%^BOLD%^%^WHITE%^Bracelets of %^BOLD%^%^CYAN%^Ha%^BOLD%^%^BLUE%^rm%^BOLD%^%^CYAN%^on%^BOLD%^%^BLUE%^ic %^BOLD%^%^CYAN%^At%^BOLD%^%^BLUE%^tu%^BOLD%^%^CYAN%^ne%^BOLD%^%^BLUE%^me%^BOLD%^%^CYAN%^nt%^RESET%^");
    }
    if (ETO->is_class("druid")) {
        TO->set_short("%^BOLD%^%^WHITE%^Bracelets of %^RESET%^%^GREEN%^Na%^BOLD%^t%^RESET%^%^GREEN%^u%^YELLOW%^r%^RESET%^%^GREEN%^e's B%^BOLD%^a%^RESET%^%^GREEN%^la%^RESET%^n%^GREEN%^ce%^RESET%^");
    }
    if (ETO->is_class("warlock")) {
        TO->set_short("%^BOLD%^%^WHITE%^Bracelets of %^RESET%^%^MAGENTA%^Pl%^BOLD%^%^MAGENTA%^an%^RESET%^%^MAGENTA%^ar %^BOLD%^%^MAGENTA%^Po%^RESET%^%^MAGENTA%^te%^BOLD%^%^MAGENTA%^nc%^RESET%^%^MAGENTA%^y%^RESET%^");
    }
    if (ETO->is_class("magus")) {
        TO->set_short("%^BOLD%^%^WHITE%^Bracelets of %^RESET%^%^RED%^Au%^MAGENTA%^gm%^RED%^en%^MAGENTA%^te%^RED%^d P%^MAGENTA%^r%^RED%^ow%^MAGENTA%^e%^RED%^ss%^RESET%^");
    }
    while ((int)TO->query_property("enchantment") != 5) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment", 5);
    }
    return 1;
}

void clear_enchantment()
{
    if (!objectp(TO)) {
        return;
    }
    TO->remove_property("enchantment");
}

int removeme()
{
    tell_object(ETO, "%^RESET%^%^CYAN%^Your mental focus wanes as you remove the "
                "twin bracelets, and they cease %^ORANGE%^glowing%^CYAN%^.%^RESET%^");
    tell_room(EETO, "%^RESET%^%^CYAN%^The twin bracelets cease %^ORANGE%^glowing"
              "%^CYAN%^ as " + ETO->QCN + " removes them.%^RESET%^", ETO);

    TO->set_short("%^BOLD%^%^WHITE%^twin pl%^CYAN%^a%^WHITE%^tin%^CYAN%^u%^WHITE%^m bracelets%^RESET%^");
    call_out("clear_enchantment", 0.001);
    return 1;
}

void init()
{
    ::init();
    if (!interactive(ETO)) {
        return;
    }
    if (interactive(TP) && TP == environment(TO)) {
        set_size(TP->query_size());
    }
    if (!query_property("no alter")) {
        set_property("no alter", 1);
        set_name("bracelets");
        set_short("%^BOLD%^%^WHITE%^twin pl%^CYAN%^a%^WHITE%^tin%^CYAN%^u%^WHITE%^m bracelets%^RESET%^");
        set_obvious_short("%^BOLD%^%^WHITE%^twin pl%^CYAN%^a%^WHITE%^tin%^CYAN%^u%^WHITE%^m bracelets%^RESET%^");
        set_id(({ "bracelets", "twin bracelets", "platinum bracelets", "twin platinum bracelets" }));
        set_long("Fine strands of pristine %^BOLD%^%^WHITE%^pl%^CYAN%^a%^WHITE%^tin"
                 "%^CYAN%^u%^WHITE%^m %^RESET%^metal shapes these twin bracelets, each a perfect "
                 "%^BOLD%^%^CYAN%^mir%^WHITE%^r%^CYAN%^or %^RESET%^image of the other. The "
                 "strands themselves appear to be interwoven along the upper surface of each, "
                 "though underneath they form a flat, melded surface that sits %^RED%^co"
                 "%^MAGENTA%^mf%^RED%^or%^MAGENTA%^ta%^RED%^bl%^MAGENTA%^y %^RESET%^upon the arm"
                 ". In amongst the strands are tiny flecks of %^BOLD%^%^BLUE%^sa%^CYAN%^p%^BLUE%^"
                 "phi%^CYAN%^r%^BLUE%^e%^RESET%^, cut to catch and refract light in %^GREEN%^ex"
                 "%^CYAN%^qu%^GREEN%^is%^CYAN%^it%^GREEN%^e %^RESET%^patterns. Upon the underside "
                 "of the bracelet are etched runes in some ornate, unfamiliar script that forms "
                 "flowing whorls across the %^BOLD%^%^WHITE%^br%^CYAN%^i%^WHITE%^ght %^RESET%^"
                 "metal.\n");
        set_lore("These pristine bracelets are known throughout history's pages as a "
                 "highly prized artifact of ancient high-elven make. Crafted by the unparalleled "
                 "magics that have long since been lost to the centuries after the Crown Wars, "
                 "they were said to be so skillfully made that they would adapt to any person "
                 "that wore them, enhancing and empowering the magical capacity of any kind of "
                 "spellcaster.");
    }
}

void bind_me(string* pplz)
{
    owners += pplz;
    OWNED = 1;
}

string* bound_to()
{
    if (sizeof(owners)) {
        return owners;
    }
    return 0;
}
