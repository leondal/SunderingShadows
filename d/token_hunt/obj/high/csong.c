// cursed songblade, same as songblade
//but recolored by cedric -haded 10/12/11
#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/longsword.c";
int hit_func;
int wield_func;
int unwield_func;

create()
{
    ::create();
    set_id(({ "sword", "long sword", "longsword", "elven long sword", "corrupt songblade", "cursed songblade",
              "elven sword", "elven longsword", "songblade", "song blade", "bladesong", "blade song" }));
    set_name("Corrupt Songblade");
    set_obvious_short("%^BOLD%^%^BLACK%^An %^RESET%^%^WHITE%^o%^BOLD%^%^WHITE%^r%^BLACK%^n%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^m%^BLACK%^e%^RESET%^%^WHITE%^n%^BOLD%^%^WHITE%^t%^BLACK%^a%^RESET%^%^WHITE%^l %^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ngsw%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^rd%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^C%^RESET%^%^WHITE%^u%^BOLD%^%^BLACK%^rsed %^RESET%^%^MAGENTA%^S%^ORANGE%^o%^MAGENTA%^ngbl%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^de%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This is a masterfully created blade of" +
             " elvish design. Long and elegant, the perfectly balanced" +
             " %^BOLD%^%^BLACK%^m%^WHITE%^i%^BOLD%^%^BLACK%^t%^WHITE%^h%^BOLD%^%^BLACK%^r%^WHITE%^i%^BOLD%^%^BLACK%^l " +
             "blade tapers to a sharp point and has d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rk p%^GREEN%^u%^BLACK%^l%^GREEN%^s%^BLACK%^i%^GREEN%^n%^BLACK%^g " +
             "%^BOLD%^%^BLUE%^r%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^n%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^s%^BOLD%^%^BLACK%^" +
             " etched on either side of the narrow groove running the entirity of its " +
             "%^RESET%^%^WHITE%^dull%^BOLD%^%^BLACK%^ length.  The hilt of the weapon" +
             " is made of the same d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rkened%^BOLD%^%^BLACK%^" +
             " %^BOLD%^%^BLACK%^m%^WHITE%^i%^BOLD%^%^BLACK%^t%^WHITE%^h%^BOLD%^%^BLACK%^r%^WHITE%^i%^BOLD%^%^BLACK%^l" +
             " as the blade, with black %^RESET%^%^ORANGE%^leather%^BOLD%^%^BLACK%^ braided about it, " +
             "encrusted with thousands of small, bl%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ck " +
             "%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^p%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ls%^BOLD%^%^BLACK%^ " +
             "that seem to draw all the light around them. The crosspiece too, has been made of the same " +
             "precious %^RESET%^%^WHITE%^metal%^BOLD%^%^BLACK%^, but has been inlaid with hundreds of " +
             "black %^BOLD%^%^WHITE%^di%^CYAN%^a%^WHITE%^monds%^BOLD%^%^BLACK%^, with only a single, " +
             "large %^RESET%^%^MAGENTA%^amethyst%^BOLD%^%^BLACK%^ on either end. On the underside " +
             "of the crosspiece, a single piece of scrolling %^RESET%^%^WHITE%^text%^BOLD%^%^BLACK%^" +
             " has been etched in %^YELLOW%^gold%^BOLD%^%^BLACK%^.%^RESET%^.");

    set_lore("%^BOLD%^%^BLACK%^Everybody knows that many moons ago" +
             " great swords were created for the most revered of the elven " +
             "fighters - the bladesingers.  These swords was imbued with " +
             "arcane powers that would aid the blade singers in combat as " +
             "well as using their powerful spells. This was once such sword," +
             " but at one time it fell into the hand of a dark and powerful" +
             " wizard, who twisted the sword into a cruel echo of its once " +
             "magnificent use. The wizard killed the bladesinger and " +
             "trapped her spirit into the sword, making her wail and " +
             "sing dark songs of death for eternity. The sword was " +
             "used to fuel the spells of the wizard, and with it he was" +
             " feared. The legend says it was lost as the dark wizard " +
             "was slain by a band of heroes. The legend also speaks of" +
             " this blade looking like a normal songblade, until it " +
             "finds it way into the hands of a wizard with the" +
             " potential of doing dark deeds.");
    set_read("%^BOLD%^%^BLACK%^Let the song of death haunt your dreams forever. - Tander al'Thor%^RESET%^");
    set_language("common");
    set_property("lore difficulty", 25);
    set_value(0);
    while ((int)TO->query_property("enchantment") != 5) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment", 5);
    }
    set_item_bonus("caster level", 2);
    set_item_bonus("spell penetration", 1);
    set_hit((: TO, "hit_func" :));
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
    set_overallStatus(220);
    set_property("no disenchant",1);
}
int wield_func()
{
    tell_object(ETO, "%^BOLD%^%^BLACK%^The sword emits a " +
                "%^RESET%^%^CYAN%^d%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^k " +
                "and %^BOLD%^%^GREEN%^ee%^BLACK%^r%^GREEN%^ie%^BLACK%^ %^RESET%^%^MAGENTA%^s%^WHITE%^o%^MAGENTA%^" +
                "ng%^BOLD%^%^BLACK%^ as you grasp the %^RESET%^%^WHITE%^hilt%^BOLD%^%^BLACK%^ of" +
                " the %^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^u%^RESET%^%^WHITE%^n%^BOLD%^%^BLACK%^e" +
                "%^RESET%^%^WHITE%^c%^BOLD%^%^BLACK%^o%^RESET%^%^WHITE%^v%^BOLD%^%^BLACK%^e%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^e%^RESET%^%^WHITE%^d%^BOLD%^%^BLACK%^ sword%^RESET%^");

    tell_room(environment(ETO), "The runes of " + ETO->query_cap_name() +
              "'s sword begin to glow softly as " + ETO->query_subjective() +
              " graps the magnificent hilt.", ETO);
    return 1;
}

int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^BLACK%^The %^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^u" +
                "%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^t%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^g " +
                "song finally recedes and you feel %^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^l%^BOLD%^" +
                "%^BLACK%^i%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^v%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^d%^RESET%^.");
    tell_room(environment(ETO), "" + ETO->query_cap_name() +
              " looks disappointed as " + ETO->query_subjective() + " unwields the sword.", ETO);
    return 1;
}

int hit_func(object target)
{
    object ob;
    if (!objectp(target)) {
        return 0;
    }
    if (random(1000) < 300) {
        switch (random(11)) {
        case 0..4:
            ETO->execute_attack();
            tell_object(ETO, "%^BOLD%^%^BLACK%^The %^BOLD%^%^BLACK%^C%^RESET%^%^WHITE%^u%^BOLD%^%^BLACK%^rsed" +
                        " %^RESET%^%^MAGENTA%^S%^ORANGE%^o%^MAGENTA%^ngbl%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^de%^RESET%^ sings a" +
                        " %^RESET%^%^CYAN%^d%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^k and %^BOLD%^%^GREEN%^ee%^BLACK%^r%^GREEN%^ie%^BLACK%^" +
                        " %^RESET%^%^MAGENTA%^s%^WHITE%^o%^MAGENTA%^ng%^BOLD%^%^BLACK%^ that " +
                        "%^RESET%^%^RED%^f%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^ the urge to " +
                        "%^RED%^maim%^BOLD%^%^BLACK%^ your foe, and with %^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^" +
                        "a%^RESET%^%^CYAN%^t%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^ speed your " +
                        "sword %^BOLD%^%^MAGENTA%^b%^RESET%^%^MAGENTA%^l%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^r%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^s" +
                        "%^BOLD%^%^BLACK%^ and %^BOLD%^%^WHITE%^strikes%^BOLD%^%^BLACK%^ " + target->query_cap_name() + " again!%^RESET%^", ({ environment(ETO), target }));

            tell_room(environment(ETO), "%^BOLD%^%^BLACK%^The %^BOLD%^%^BLACK%^C%^RESET%^%^WHITE%^u%^BOLD%^%^BLACK%^rsed %^RESET%^%^MAGENTA%^S%^ORANGE%^o" +
                      "%^MAGENTA%^ngbl%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^de%^RESET%^ sings a %^RESET%^%^CYAN%^d%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^r%^BOLD%^" +
                      "%^BLACK%^k and %^BOLD%^%^GREEN%^ee%^BLACK%^r%^GREEN%^ie%^BLACK%^ %^RESET%^%^MAGENTA%^s%^WHITE%^o%^MAGENTA%^ng%^BOLD%^%^BLACK%^ that " +
                      "seems to %^RESET%^%^RED%^f%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^l " + ETO->query_cap_name() + " with bloodlust, and with " +
                      "%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^t%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^" +
                      "a%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^ speed " + ETO->query_cap_name() + "'s sword %^BOLD%^%^MAGENTA%^b%^RESET%^%^MAGENTA%^l%^BOLD%^%^MAGENTA%^u" +
                      "%^RESET%^%^MAGENTA%^r%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^ from every direction and " + ETO->query_cap_name() + " %^BOLD%^" +
                      "%^WHITE%^strikes%^BOLD%^%^BLACK%^ " + target->query_cap_name() + " again!", ({ target, ETO }));

            tell_object(target, "%^BOLD%^%^BLACK%^The %^BOLD%^%^BLACK%^C%^RESET%^%^WHITE%^u%^BOLD%^%^BLACK%^rsed %^RESET%^%^MAGENTA%^S%^ORANGE%^o%^MAGENTA%^" +
                        "ngbl%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^de%^RESET%^ sings a %^RESET%^%^CYAN%^d%^BOLD%^%^BLACK%^a%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^k and " +
                        "%^BOLD%^%^GREEN%^ee%^BLACK%^r%^GREEN%^ie%^BLACK%^ %^RESET%^%^MAGENTA%^s%^WHITE%^o%^MAGENTA%^ng%^BOLD%^%^BLACK%^ that seems to " +
                        "%^RESET%^%^RED%^f%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^l " + ETO->query_cap_name() + " with bloodlust, and with " +
                        "%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^t%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^r" +
                        "%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^ speed " + ETO->query_cap_name() + "'s sword %^BOLD%^%^MAGENTA%^b%^RESET%^" +
                        "%^MAGENTA%^l%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^r%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^ from every " +
                        "direction and " + ETO->query_cap_name() + " %^BOLD%^%^WHITE%^strikes%^BOLD%^%^BLACK%^ you again!", ({ environment(ETO), ETO }));
            return roll_dice(1, 8) + 2;

            break;

        case 5..10:

            tell_object(ETO, "%^BOLD%^%^BLACK%^The %^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^u%^RESET%^%^WHITE%^n%^BOLD%^%^BLACK%^e%^RESET%^%^WHITE%^s" +
                        "%^BOLD%^%^BLACK%^ on the sword's %^RESET%^%^WHITE%^hilt%^BOLD%^%^BLACK%^ begin to %^RESET%^%^MAGENTA%^tremble%^BOLD%^%^BLACK%^ " +
                        "underneath your hands and a h%^WHITE%^i%^BLACK%^g%^WHITE%^h %^BLACK%^p%^GREEN%^i%^BOLD%^%^BLACK%^tch%^GREEN%^e%^BOLD%^%^BLACK%^d" +
                        " %^RESET%^%^MAGENTA%^w%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^l of %^RESET%^%^RED%^d%^MAGENTA%^e%^RESET%^%^RED%^s" +
                        "%^MAGENTA%^p%^RESET%^%^RED%^a%^MAGENTA%^i%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^ surges from the %^RESET%^%^WHITE%^hilt%^BOLD%^%^BLACK%^" +
                        " into the blade and blasts " + target->query_cap_name() + " with its %^BOLD%^%^RED%^w%^RESET%^%^RED%^o%^BOLD%^%^RED%^r%^RESET%^%^RED%^s" +
                        "%^BOLD%^%^RED%^t %^BOLD%^%^BLACK%^f%^RED%^e%^BLACK%^a%^RED%^r%^BLACK%^s.%^RESET%^", ({ environment(ETO), target }));

            tell_object(target, "%^BOLD%^%^BLACK%^A loud %^BOLD%^%^BLACK%^h%^CYAN%^u%^BOLD%^%^BLACK%^m%^CYAN%^m%^BOLD%^%^BLACK%^i%^CYAN%^n%^BOLD%^%" +
                        "^BLACK%^g starts to %^RESET%^%^MAGENTA%^emit%^BOLD%^%^BLACK%^ from the %^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^u%^RESET%^%^WHITE%^n%^BOLD%^" +
                        "%^BLACK%^e%^RESET%^%^WHITE%^c%^BOLD%^%^BLACK%^o%^RESET%^%^WHITE%^v%^BOLD%^%^BLACK%^e%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^e%^RESET%^" +
                        "%^WHITE%^d%^BOLD%^%^BLACK%^ sword wielded by " + ETO->query_cap_name() + " and a h%^WHITE%^i%^BLACK%^g%^WHITE%^h %^BLACK%^p%^GREEN%^i" +
                        "%^BOLD%^%^BLACK%^tch%^GREEN%^e%^BOLD%^%^BLACK%^d %^RESET%^%^MAGENTA%^w%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^l of " +
                        "%^RESET%^%^RED%^d%^MAGENTA%^e%^RESET%^%^RED%^s%^MAGENTA%^p%^RESET%^%^RED%^a%^MAGENTA%^i%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^ streaks " +
                        "from the blade and blasts you with your %^BOLD%^%^RED%^w%^RESET%^%^RED%^o%^BOLD%^%^RED%^r%^RESET%^%^RED%^s%^BOLD%^%^RED%^t %^BOLD%^" +
                        "%^BLACK%^f%^RED%^e%^BLACK%^a%^RED%^r%^BLACK%^s.", ({ environment(ETO), ETO }));

            tell_room(environment(ETO), "%^BOLD%^%^BLACK%^A loud %^BOLD%^%^BLACK%^h%^CYAN%^u%^BOLD%^%^BLACK%^m%^CYAN%^m%^BOLD%^%^BLACK%^i%^CYAN%^n" +
                      "%^BOLD%^%^BLACK%^g starts to %^RESET%^%^MAGENTA%^emit%^BOLD%^%^BLACK%^ from the %^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^u%^RESET%^%^WHITE%^" +
                      "n%^BOLD%^%^BLACK%^e%^RESET%^%^WHITE%^c%^BOLD%^%^BLACK%^o%^RESET%^%^WHITE%^v%^BOLD%^%^BLACK%^e%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^e" +
                      "%^RESET%^%^WHITE%^d%^BOLD%^%^BLACK%^ sword wielded by " + ETO->query_cap_name() + " and a h%^WHITE%^i%^BLACK%^g%^WHITE%^h " +
                      "%^BLACK%^p%^GREEN%^i%^BOLD%^%^BLACK%^tch%^GREEN%^e%^BOLD%^%^BLACK%^d %^RESET%^%^MAGENTA%^w%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^i" +
                      "%^BOLD%^%^BLACK%^l of %^RESET%^%^RED%^d%^MAGENTA%^e%^RESET%^%^RED%^s%^MAGENTA%^p%^RESET%^%^RED%^a%^MAGENTA%^i%^RESET%^%^RED%^r" +
                      "%^BOLD%^%^BLACK%^ streaks from the blade and blasts " + target->query_cap_name() + " with " + target->QP + " %^BOLD%^%^RED%^w%^RESET%^" +
                      "%^RED%^o%^BOLD%^%^RED%^r%^RESET%^%^RED%^s%^BOLD%^%^RED%^t %^BOLD%^%^BLACK%^f%^RED%^e%^BLACK%^a%^RED%^r%^BLACK%^s.", ({ target, ETO }));

            return roll_dice(2, 8) + 4;

            break;

        case 11:
            tell_object(ETO, "%^BOLD%^%^BLACK%^As you %^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^p%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^n " +
                        "around you brings the sword down in a %^RESET%^%^MAGENTA%^gr%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^c%^BOLD%^" +
                        "%^BLACK%^e%^RESET%^%^MAGENTA%^f%^BOLD%^%^BLACK%^u%^RESET%^%^MAGENTA%^l %^BOLD%^%^BLACK%^arc upon " + target->query_cap_name() +
                        " the bl%^RESET%^%^WHITE%^ack %^RESET%^%^MAGENTA%^opals %^BOLD%^%^BLACK%^s%^WHITE%^h%^BOLD%^%^BLACK%^i%^WHITE%^m%^BOLD%^" +
                        "%^BLACK%^m%^WHITE%^e%^BOLD%^%^BLACK%^r%^WHITE%^s%^BOLD%^%^BLACK%^ and a %^BOLD%^%^RED%^w%^RESET%^%^RED%^a%^BOLD%^%^RED%^v%^RESET%^%^RED%^" +
                        "e%^BOLD%^%^BLACK%^ of d%^BOLD%^GREEN%^a%^BOLD%^%^BLACK%^rk %^RESET%^%^CYAN%^e%^MAGENTA%^n%^WHITE%^e%^CYAN%^r%^MAGENTA%^g%^WHITE%^y%^BOLD%^" +
                        "%^BLACK%^ flies from the d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rk %^RESET%^%^MAGENTA%^opals%^BOLD%^%^BLACK%^ into " + target->query_cap_name() +
                        ", d%^GREEN%^r%^BOLD%^%^BLACK%^a%^GREEN%^i%^BOLD%^%^BLACK%^n%^GREEN%^i%^BOLD%^%^BLACK%^n%^GREEN%^g%^BOLD%^%^BLACK%^ the %^YELLOW%^l%^RESET%^" +
                        "%^ORANGE%^i%^YELLOW%^g%^RESET%^%^ORANGE%^h%^YELLOW%^t%^BOLD%^%^BLACK%^ and %^WHITE%^sight%^BOLD%^%^BLACK%^ from " + target->QP + " %^YELLOW%^eyes.");

            tell_object(target, "%^BOLD%^%^BLACK%^As " + ETO->query_cap_name() + " %^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^p%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^n%^RESET%^" +
                        "%^CYAN%^s%^BOLD%^%^BLACK%^ around he brings the sword down in a %^RESET%^%^MAGENTA%^gr%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^e" +
                        "%^RESET%^%^MAGENTA%^f%^BOLD%^%^BLACK%^u%^RESET%^%^MAGENTA%^l %^BOLD%^%^BLACK%^arc upon you, the bl%^RESET%^%^WHITE%^ack %^RESET%^%^MAGENTA%^opals" +
                        " %^BOLD%^%^BLACK%^s%^WHITE%^h%^BOLD%^%^BLACK%^i%^WHITE%^m%^BOLD%^%^BLACK%^m%^WHITE%^e%^BOLD%^%^BLACK%^r%^WHITE%^s%^BOLD%^%^BLACK%^ and a %^BOLD%^" +
                        "%^RED%^w%^RESET%^%^RED%^a%^BOLD%^%^RED%^v%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ of d%^BOLD%^GREEN%^a%^BOLD%^%^BLACK%^rk %^RESET%^%^CYAN%^e%^MAGENTA%^n" +
                        "%^WHITE%^e%^CYAN%^r%^MAGENTA%^g%^WHITE%^y%^BOLD%^%^BLACK%^ flies from the d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rk %^RESET%^%^MAGENTA%^opals%^BOLD%^" +
                        "%^BLACK%^ into you,  d%^GREEN%^r%^BOLD%^%^BLACK%^a%^GREEN%^i%^BOLD%^%^BLACK%^n%^GREEN%^i%^BOLD%^%^BLACK%^n%^GREEN%^g%^BOLD%^%^BLACK%^ the " +
                        "%^YELLOW%^l%^RESET%^%^ORANGE%^i%^YELLOW%^g%^RESET%^%^ORANGE%^h%^YELLOW%^t%^BOLD%^%^BLACK%^ and %^WHITE%^sight%^BOLD%^%^BLACK%^ from your %^YELLOW%^eyes.");

            tell_room(environment(ETO), "%^BOLD%^%^BLACK%^As " + ETO->query_cap_name() + "  %^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^p%^RESET%^" +
                      "%^CYAN%^i%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^ around he brings the sword down in a %^RESET%^%^MAGENTA%^" +
                      "gr%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^f%^BOLD%^%^BLACK%^u%^RESET%^%^MAGENTA%^l " +
                      "%^BOLD%^%^BLACK%^arc upon  " + target->query_cap_name() + " the bl%^RESET%^%^WHITE%^ack %^RESET%^%^MAGENTA%^opals %^BOLD%^+" +
                      "%^BLACK%^s%^WHITE%^h%^BOLD%^%^BLACK%^i%^WHITE%^m%^BOLD%^%^BLACK%^m%^WHITE%^e%^BOLD%^%^BLACK%^r%^WHITE%^s%^BOLD%^%^BLACK%^ " +
                      "and a %^BOLD%^%^RED%^w%^RESET%^%^RED%^a%^BOLD%^%^RED%^v%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ of d%^BOLD%^GREEN%^a%^BOLD%^" +
                      "%^BLACK%^rk %^RESET%^%^CYAN%^e%^MAGENTA%^n%^WHITE%^e%^CYAN%^r%^MAGENTA%^g%^WHITE%^y%^BOLD%^%^BLACK%^ flies from the " +
                      "d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rk %^RESET%^%^MAGENTA%^opals%^BOLD%^%^BLACK%^ into " + target->query_cap_name() + ", " +
                      "d%^GREEN%^r%^BOLD%^%^BLACK%^a%^GREEN%^i%^BOLD%^%^BLACK%^n%^GREEN%^i%^BOLD%^%^BLACK%^n%^GREEN%^g%^BOLD%^%^BLACK%^ the " +
                      "%^YELLOW%^l%^RESET%^%^ORANGE%^i%^YELLOW%^g%^RESET%^%^ORANGE%^h%^YELLOW%^t%^BOLD%^%^BLACK%^ and %^WHITE%^sight%^BOLD%^%^BLACK%^ from "
                      + target->QP + " %^YELLOW%^eyes .", ({ ETO, target }));

            target->set_paralyzed(20, "You are trying to get to your feet.");
            if (!random(3)) {
                target->set_blind(1);
            }else {
                target->set_paralyzed(3 + random(4), "You are still trying to recover from the blinding light!");
            }
            break;
        }
    }
}
