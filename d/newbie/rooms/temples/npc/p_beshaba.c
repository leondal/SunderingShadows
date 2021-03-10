//NPC priest for newbietown temples 
#include <std.h>

inherit NPC;

void create() {
        ::create();
        set_name("Deandra Lafolge");
        set_short("Deandra Lafolge, Doomservant");
        set_id(({"npc cleric","cleric", "deandra", "Deandra", "priestess"}));
        set_long("%^MAGENTA%^Deandra Lafolge is large and voluptuous "+
		"woman.  Her soft curvaceous body is stuffed into a %^BOLD%^"+
		"%^MAGENTA%^mauve%^RESET%^%^MAGENTA%^ robe accented with "+
		"%^BOLD%^%^BLACK%^black%^RESET%^%^MAGENTA%^ chiffon gores "+
		"that flare outwards.  The robes are slit to show off a pair"+
		" of opaque %^BOLD%^%^BLACK%^black%^RESET%^%^MAGENTA%^ silk "+
		"stockings that cover each leg.  Her long %^YELLOW%^light "+
		"blonde%^RESET%^%^MAGENTA%^ hair has been teased to give the"+
		" blonde curls lots of volume.  Her plump lips have been "+
		"stained a bright shade of %^BOLD%^%^RED%^red%^RESET%^"+
		"%^MAGENTA%^ that clashes with her %^BOLD%^%^MAGENTA%^mauve"+
		"%^RESET%^%^MAGENTA%^ robe.  A slightly deranged and crazed"+
		" light shines in her %^BOLD%^%^BLUE%^azure blue%^RESET%^"+
		"%^MAGENTA%^ eyes.  Cradled in her right hand is a pampered"+
		" %^BOLD%^%^BLACK%^black rat%^RESET%^%^MAGENTA%^ with a "+
		"%^BOLD%^%^RED%^bright red%^RESET%^%^MAGENTA%^ ribbon tied"+
		" around its neck.");
      set_race("human");
      set_body_type("human");
      set_gender("female");
     	set_alignment(8);
   	set_diety("beshaba");
   	new("/d/magic/symbols/beshaba_symbol")->move(TO);
     	set_guild_level("cleric",25);
      set_class("cleric");
      add_search_path("/cmds/priest");
      set_spells( ({ "limb attack", "hold person", "cause critical wounds",
"hold person" }) );
   	set_spell_chance(50);
      set_hd(30,5);
      set_max_hp(200);
      set_hp(200);
      set_exp(10);
      set_stats("strength", 17);
   	set_stats("dexterity", 14);
   	set_stats("constitution", 16);
   	set_stats("intelligence", 10);
   	set_stats("charisma", 15);
   	set_stats("wisdom", 18);
      set_db("temple_cleric");
      remove_std_db();
}