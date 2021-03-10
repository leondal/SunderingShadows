#include <std.h>
inherit "/std/comp_vend";

void create(){
        ::create();
        set_name("joran");
        set_short("Joran, a short and scruffy man");
        set_id(({"joran","Joran","gemshaper","man","shaper"}));
        set_long("%^RESET%^%^ORANGE%^Standing an an unimpressive four feet "
"tall, this man looks more like a begger than a shopkeeper.  He looks like he "
"%^BOLD%^%^BLACK%^hasn't slept in weeks %^RESET%^%^ORANGE%^and %^WHITE%^hasn't"
" eaten in months%^ORANGE%^.  However, his eyes are %^BOLD%^%^WHITE%^keen "
"%^RESET%^%^ORANGE%^and his wits sharp.  He sorts %^BOLD%^%^MAGENTA%^c%^RESET%^"
"%^MAGENTA%^r%^BOLD%^ys%^RESET%^%^MAGENTA%^t%^BOLD%^als %^RESET%^%^ORANGE%^on "
"the counter with a quick deft hand, mumbling all the time.  He wears a dun "
"colored robe covered with the %^RED%^stains %^ORANGE%^of life.  Obviously his "
"mind is on other things.%^RESET%^");
        set_race("human");
        set_gender("male");
        set_hd(20,4);
        set_max_hp(150+random(50));
        set_hp(query_max_hp());
        set_overall_ac(-14);
        set_alignment(5);
        set_class("psion");
        set_class("thief");
        set_mlevel("psion",20);
        set_mlevel("thief",20);
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
    set_shop_type("psion");
    set_components(100);
}
