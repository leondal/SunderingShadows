#include <std.h>
inherit "/std/food.c";

void create() {
        ::create();
        set_name("dead rat");
        set_id(({"dead rat","rat","dead giant rat","food"}));
        set_short("%^RED%^Dead giant rat%^RESET%^");
        set_weight(1);
        set_value(0);
        set_destroy();
        set_poison(0);
        set_strength(2);
        set_long("This is a partially eaten dead giant rat.  What is left of the fur is matted with dried blood.  Teeth marks look like it might have been gnawed on by a gnoll, bugbear, or other savage carnivore.");
        set_my_mess("The bones crunch and guts squish out when you eat what is left of the rat.");
        set_your_mess("eats what is left of the rat and looks deranged, as you watch the guts squish out of it.");
}
