#include <std.h>
#include "../elf.h"
inherit INTERACTIVE;

void create()
{
        ::create();
        remove_std_db();
        remove_dbs(({"miscvendors"}));
   remove_random_act_dbs(({"miscvendorsrandom"}));
   set_items_allowed("misc");
        set_name("Shanta");
        set_short("Shanta, a young moon elf");
        set_id(({"shop keeper","elf","shanta","shop keep"}));
        set_long(
        "%^CYAN%^Shanta is a young and beautiful elven maiden who serves the tables and "+
        "entertains guests of the keep.  She has long and flowing"+
		" %^BOLD%^%^BLACK%^black hair%^RESET%^%^CYAN%^ that "+
        "goes down to her waist.  Her eyes are %^GREEN%^Bright Green%^CYAN%^,"+
		" she very cheerful and "+
        "hospitable despite the sufferings of her family back in Tharis.  She works "+
        "here to raise money to buy healing supplies for her home back in the "+
        "dreadful elven quarter.%^RESET%^" );
        set_gender("female");
        set_race("elf");
        set_alignment(1);
        set_hd(20,5);
        set_max_hp(150+random(120));
        set_overall_ac(-7);
        set_class("mage");
        set_class("fighter");
        set_mlevel("mage",20);
        set_mlevel("fighter",20);
        set_level(20);
        set_stats("intelligence",18);
        set_stats("strength",10);
        set_stats("charisma",18);
        set_stats("constitution",15);
        set_stats("dexterity",10);
        set_stats("wisdom",12);
        set_spells(({
        "hideous laughter",
        "magic missile",
        "chain lightning",
        "phantom guardians",
        "fireball",
        "monster summoning vii",
        "web",
        "hold person",
        }));
        set_spell_chance(100);
        set_storage_room(STOR"inn.c");
        set("aggressive",0);
        add_money("copper",random(100));
        force_me("speech smile and says");
	    set_new_exp(30,"very low");
        set_max_level(35);		
		set_base_damage_type("bludgeoning");
}