//Updated description and mechanics - Octothorpe 10/22/09
//Coded by the one and only master of monsters...BANE//

#include <std.h>
inherit WEAPONLESS;

void create()
{
    ::create();
    set_id(({ "leucrotta", "Leucrotta", "beast", "laeradmon" }));
    set_name("leucrotta");
    set_short("%^BOLD%^%^BLACK%^dr%^RESET%^%^RED%^oo%^BOLD%^%^BLACK%^l" +
              "%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^ng l%^RESET%^%^RED%^eu%^BOLD%^" +
              "%^BLACK%^cr%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^tt%^RESET%^" +
              "%^RED%^a%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This creature reeks of an absolutely " +
             "horrid stench, which seems even more appalling than that of " +
             "rotting flesh.  A constant stream of dr%^RESET%^%^RED%^oo%" +
             "^BOLD%^%^BLACK%^l emits from the l%^RESET%^%^RED%^eu%^BOLD%^" +
             "%^BLACK%^cr%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^tt%^RESET%^" +
             "%^RED%^a%^BOLD%^%^BLACK%^'s badger-like head.  Glowing %^RED%^" +
             "r%^RESET%^%^RED%^e%^BOLD%^d %^BOLD%^%^BLACK%^eyes and a " +
             "mouthful of jagged, bony ridges lends it an appearance " +
             "comparable to a beast from a nightmare.  It appears to have " +
             "been assembled from an assortment of different animal body " +
             "parts.  Its body is that of a stag, the tail of a lion, and " +
             "the head of a badger.%^RESET%^");
    set_body_type("equine");
    set_race("leucrotta");
    set_gender("male");
    set_alignment(9);
    set_size(2);
    set_hd(17, 14);  // was 7,14
    set_max_level(20); // was 15
    set_hp(190);    // was 70
    set_exp(10000);
    set_overall_ac(-5);  // was 3
    set("aggressive", 25);
    set_attack_limbs(({ "head", "right fore hoof", "left fore hoof" }));
    set_attacks_num(3);   // was 1
    set_base_damage_type("bludgeoning");
    set_damage(3, 6);
    set_moving(1);
    set_speed(40);
    set_nogo(({ "/d/laerad/wasteland/waste1" }));
    set_stats("strength", 20);
    set_stats("dexterity", 16);
    set_stats("intelligence", 12);
    set_stats("wisdom", 10);
    set_stats("constitution", 12);
    set_stats("charisma", 2);
}
