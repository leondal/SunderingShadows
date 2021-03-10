#include <std.h>
inherit "/std/comp_vend.c";

void create(){
    ::create();
    set_name("aemilia");
    set_id(({"aemilia","clerk","shop keeper","human","woman","shopkeeper","lanyer"}));
    set_short("Aemilia Lanyer, an elderly woman");
    set("aggressive", 0);
    set_long(
       "Aemilia Lanyer is an aging woman who wears her long silver "+
       "hair wound into a bun at the base of her neck.  She wears a "+
       "well-made, though shapeless, dress of light linen, the hem "+
       "reaching all the way to the tops of her comfortable boots.  "+
       "She is never seen without a cat or two following at her heels, "+
       "and she peers down at them over the tops of her half-moon "+
       "spectacles.  While slow moving, Aemilia possesses the ability "+
       "to call crystals to her, making her lack of speed less of "+
       "an impediment.  Something in the twinkle of her green eyes "+
       "hints that she is not as helpless as she seems.\n\n"+
       "To get you a list of shop commands, type <help shop>."
	);
    set_gender("female");
    set_alignment(5);
    set_race("human");
    set_class("psion");
    set_hd(30,2);
    set_level(30);
    set_guild_level("psion",30);
    set_property("no bump", 1);
    set_shop_type("psion");
      set_components(100);
    set_spell_chance(100);
    set_spells(({"mind thrust","mind thrust","mind thrust","microcosm",
       "energy bolt","energy bolt"}));
}
