#include <std.h>
inherit "/std/psi_comp_vend";

void create(){
        ::create();
        set_name("mohsen");
        set_short("Mohsen, a vivacious young man");
        set_id(({"mohsen","Mohsen","gemshaper","man","shaper"}));
        set_long("%^GREEN%^Mohsen appears quite young yet, perhaps only just "
"out of his teens, with %^BOLD%^%^BLACK%^long black hair%^RESET%^%^GREEN%^ "
"bound away from his face in a ponytail at his neck. He is clad quite simply "
"in a %^WHITE%^white toga %^GREEN%^and %^ORANGE%^simple leather sandals"
"%^GREEN%^, with only the beautiful %^BOLD%^%^WHITE%^cryst%^CYAN%^a%^WHITE%^l "
"%^RESET%^%^GREEN%^bound at his throat serving as decoration to his plain "
"attire. His eyes are so dark they could almost be called%^BOLD%^%^BLACK%^ "
"black%^RESET%^%^GREEN%^, with only tiny hints at a %^ORANGE%^deep brown hue "
"%^GREEN%^within them. He seems quite energetic and eager to help anyone that "
"walks into his shop.%^RESET%^");
        set_race("human");
        set_gender("male");
        set_hd(20,4);
        set_max_hp(150+random(50));
        set_hp(query_max_hp());
        set_overall_ac(-14);
        set_alignment(5);
        set_class("psion");
        set_class("fighter");
        set_mlevel("psion",20);
        set_mlevel("fighter",20);
        set_level(20);
        set_stats("intelligence",18);
        set_stats("wisdom",18);
        set_stats("charisma",16);
        set_stats("strength",9);
        set_stats("constitution",8);
        set_stats("dexterity",14);
        set_spells(({"mind thrust","mind thrust","call crystals","energy bolt","energy bolt","ultrablast"}));
        set_spell_chance(70);
        set_exp(1);
        set("aggressive",0);
        add_money("gold",random(50));
        set_components(100);
}
