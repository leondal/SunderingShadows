#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/longsword.c";
int hit_func;
int wield_func;
int unwield_func;

create()
{
    ::create();
    set_id(({ "sword", "long sword", "longsword", "elven long sword", "elven
sword", "elven longsword", "songblade", "song blade", "bladesong", "blade song" }));
    set_name("%^BOLD%^%^MAGENTA%^S%^YELLOW%^o%^MAGENTA%^ngbl%^CYAN%^a%^MAGENTA%^de%^RESET%^");
    set_obvious_short("%^RESET%^%^MAGENTA%^An %^BOLD%^or%^YELLOW%^n%^RESET%^%^CYAN%^a%^BOLD%^%^MAGENTA%^ment%^YELLOW%^a%^MAGENTA%^l %^RESET%^%^MAGENTA%^longsword%^RESET%^");
    set_short("%^BOLD%^%^MAGENTA%^S%^YELLOW%^o%^MAGENTA%^ngbl%^CYAN%^a%^MAGENTA%^de%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This is a masterfully created blade designed for the most"
             " %^RESET%^%^MAGENTA%^delicate %^BOLD%^%^WHITE%^of hands.  Long and elegant, the perfectly "
             "%^RESET%^b%^BOLD%^a%^BLACK%^l%^RESET%^a%^BOLD%^n%^RESET%^%^CYAN%^c%^BOLD%^%^WHITE%^e%^RESET%^d"
             " %^BOLD%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l %^RESET%^b%^BOLD%^l%^BLACK%^a%^WHITE%^d%^RESET%^e %^BOLD%^tapers to a sharp point and has %^MAGENTA%^softly glowing runes %^WHITE%^etched on either"
             " side of the narrow groove running the entirity of its shining length.  The hilt of the weapon"
             " is made of the same shining mithril as the blade, with %^RESET%^%^ORANGE%^soft, supple leather"
             " %^BOLD%^%^WHITE%^braided about it, encrusted with thousands of %^RESET%^%^MAGENTA%^small, smooth"
             " %^BOLD%^a%^RESET%^%^MAGENTA%^m%^BOLD%^eth%^RESET%^%^MAGENTA%^y%^BOLD%^sts %^WHITE%^that create"
             " a %^MAGENTA%^d%^YELLOW%^a%^MAGENTA%^zzl%^YELLOW%^i%^MAGENTA%^ng %^WHITE%^displays of"
             " refl%^MAGENTA%^e%^WHITE%^ct%^MAGENTA%^i%^WHITE%^ve l%^MAGENTA%^i%^WHITE%^ght with the slightest of"
             " movement. The crosspiece too, has been made of the same precious metal, but has been inlaid with"
             " hundreds of glimmering %^CYAN%^d%^WHITE%^ia%^CYAN%^m%^WHITE%^ond%^CYAN%^s%^WHITE%^, with"
             " only a single, large sp%^MAGENTA%^a%^WHITE%^rkl%^MAGENTA%^i%^WHITE%^ng %^MAGENTA%^amethyst"
             " %^WHITE%^on either end.  On the underside of the crosspiece, a single piece of scrolling text"
             " has been etched in %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld.%^RESET%^");
    set_lore("%^BOLD%^%^WHITE%^Everybody knows that many moons ago great swords were created for the most revered of the elven fighters - the bladesingers.  What is not known however, is how such swords would come into the posession of a gnomish vendor.  Rumors run rampant however, ranging in everything from great defeats of the elven fighters to rumors stating that they were given as gifts to the vendors so they may reward only the greatest and most brave of the adventurers"
             " whom slay the most of the vile shifters.  Even with all the rumors floating about, it is still not known what exactly the sword does, so closely guarded were its secrets amongst the elven kind.");
    set_read("%^BOLD%^%^YELLOW%^Let the song of your heart forever guide you. - Thelloria Bladesong%^RESET%^");
    set_language("elven");
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
    if ((string)ETO->query_race() == "elf") {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The %^MAGENTA%^runes %^WHITE%^on the blade begin to %^YELLOW%^gl%^MAGENTA%^o%^YELLOW%^w br%^MAGENTA%^i%^YELLOW%^ght%^MAGENTA%^l%^YELLOW%^y %^WHITE%^as you take hold of the blade, filling the whole area with %^MAGENTA%^magical energy!%^RESET%^");
        tell_room(environment(ETO), "%^BOLD%^%^WHITE%^The %^MAGENTA%^runes %^WHITE%^of  " + ETO->query_cap_name() + "'s sword begin to %^YELLOW%^gl%^MAGENTA%^o%^YELLOW%^w br%^MAGENTA%^i%^YELLOW%^ght%^MAGENTA%^l%^YELLOW%^y %^WHITE%^as " + ETO->query_subjective() + " takes hold of the blade, filling the whole area with %^MAGENTA%^magical energy!%^RESET%^", ETO);
        TO->set_property("able to cast", 1);
        return 1;
    }else {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The %^MAGENTA%^runes %^WHITE%^of the sword begin to %^RESET%^%^MAGENTA%^gl%^BOLD%^o%^RESET%^%^MAGENTA%^w s%^BOLD%^o%^RESET%^%^MAGENTA%^ftly %^BOLD%^%^WHITE%^as you grasp its magnificent hilt.%^RESET%^");
        tell_room(environment(ETO), "%^BOLD%^%^WHITE%^The %^MAGENTA%^runes %^WHITE%^of " + ETO->query_cap_name() + "'s sword begin to %^RESET%^%^MAGENTA%^gl%^BOLD%^o%^RESET%^%^MAGENTA%^w s%^BOLD%^o%^RESET%^%^MAGENTA%^ftly %^BOLD%^%^WHITE%^as " + ETO->query_subjective() + " grasps the magnificent hilt.%^RESET%^", ETO);
        return 1;
    }
}

int unwield_func()
{
    if ((string)ETO->query_race() == "elf") {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The bright %^YELLOW%^gl%^MAGENTA%^o%^YELLOW%^w %^WHITE%^of the %^MAGENTA%^runes %^WHITE%^die back down to the normal, %^MAGENTA%^s%^RESET%^%^MAGENTA%^o%^BOLD%^ft gl%^RESET%^%^MAGENTA%^o%^BOLD%^w %^WHITE%^as you unwield the beautiful blade.%^RESET%^");
        tell_room(environment(ETO), "%^BOLD%^%^WHITE%^The bright %^YELLOW%^gl%^MAGENTA%^o%^YELLOW%^w %^WHITE%^of the %^MAGENTA%^runes %^WHITE%^on " + ETO->query_cap_name() + "'s sword die down to normal as " + ETO->query_subjective() + " unwields it.%^RESET%^", ETO);
        TO->set_property("able to cast", -1);
        return 1;
    }else {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You feel a sense of disappointment as you unwield the sword.%^RESET%^");
        tell_room(environment(ETO), "%^BOLD%^%^WHITE%^" + ETO->query_cap_name() + " looks disappointed as " + ETO->query_subjective() + " unwields the sword.%^RESET%^", ETO);
        return 1;
    }
}

int hit_func(object target)
{
    object ob;
    if (!objectp(target)) {
        return 0;
    }
    if (random(1000) < 300) {
        switch (random(12)) {
        case 0..4:
            ETO->execute_attack();
            tell_room(environment(ETO), "%^BOLD%^%^WHITE%^" + ETO->query_cap_name() + " and the %^MAGENTA%^S%^YELLOW%^o%^MAGENTA%^ngbl%^CYAN%^a%^MAGENTA%^de %^CYAN%^sing %^WHITE%^out in unison as " + ETO->query_subjective() + " spins quickly, hitting " + target->query_cap_name() + " again!", ({ target, ETO }));
            tell_object(ETO, "%^BOLD%^%^WHITE%^As the %^MAGENTA%^S%^YELLOW%^o%^MAGENTA%^ngbl%^CYAN%^a%^MAGENTA%^de %^WHITE%^sings out, you find yourself joining in while you quickly spin around to hit " + target->query_cap_name() + " again!%^RESET%^", ({ environment(ETO), target }));
            tell_object(target, "%^BOLD%^%^WHITE%^" + ETO->query_cap_name() + " and the %^MAGENTA%^S%^YELLOW%^o%^MAGENTA%^ngbl%^CYAN%^a%^MAGENTA%^de%^RESET%^ sing out in unison as " + ETO->query_subjective() + " spins quickly around to attack you again!%^RESET%^", ({ environment(ETO), ETO }));
            return roll_dice(1, 8) + 2;

            break;

        case 5..10:
            tell_room(environment(ETO), "%^BOLD%^%^WHITE%^" + ETO->query_cap_name() + "'s sword and hand begin to %^MAGENTA%^glow brightly %^WHITE%^in a dazzling display of %^CYAN%^arcane energy %^WHITE%^that is quickly released upon " + target->query_cap_name() + "in a forceful %^YELLOW%^explosion %^WHITE%^of energy!", ({ target, ETO }));
            tell_object(ETO, "%^BOLD%^%^WHITE%^The hilt of your sword begins to %^MAGENTA%^glow brightly %^WHITE%^in a dazzling display of %^CYAN%^arcane energy %^WHITE%^that is quickly released upon " + target->query_cap_name() + " in a forceful %^YELLOW%^explosion %^WHITE%^of energy!%^RESET%^", ({ environment(ETO), target }));
            tell_object(target, "%^BOLD%^%^WHITE%^" + ETO->query_cap_name() + "'s sword and hand begin to %^MAGENTA%^glow brightly %^WHITE%^in a dazzling display of %^CYAN%^arcane energy %^WHITE%^that is quickly released upon you in a forceful %^YELLOW%^explosion %^WHITE%^of energy!%^RESET%^", ({ environment(ETO), ETO }));
            return roll_dice(2, 8) + 4;

            break;

        case 11:
            tell_room(environment(ETO), "%^BOLD%^%^WHITE%^As " + ETO->query_cap_name() + " spins around and brings the sword down in a graceful arc upon " + target->query_cap_name() + ", the diamonds in the crosspiece catch the %^YELLOW%^light %^WHITE%^and reflects it at " + target->query_objective() + " in a %^YELLOW%^dazzling %^WHITE%^display of %^YELLOW%^blinding %^WHITE%^light!", ({ target, ETO }));
            tell_object(ETO, "%^BOLD%^%^WHITE%^You quickly spin around and bring the sword down in a graceful arc upon " + target->query_cap_name() + ", causing the diamonds in the crosspiece to catch the %^YELLOW%^light %^WHITE%^and reflect it at " + target->query_objective() + " in a %^YELLOW%^blinding flash %^WHITE%^of %^YELLOW%^light!%^RESET%^", ({ environment(ETO), target }));
            tell_object(target, "%^BOLD%^%^WHITE%^As " + ETO->query_cap_name() + " quickly spins around and then brings the sword down in a graceful arc upon you, the pommel catches the %^YELLOW%^light %^WHITE%^and reflects it at you in a %^YELLOW%^blinding flash %^WHITE%^of %^YELLOW%^light!", ({ environment(ETO), ETO }));
            target->set_paralyzed(20, "You are trying to get to your feet.");
            if (!random(3)) {
                target->set_blind(1);
            }else {
                target->set_paralyzed(3 + random(4), "%^YELLOW%^You are still trying to recover from the blinding light!");
            }
            break;
        }
    }
}
