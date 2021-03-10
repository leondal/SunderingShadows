//cornelia.c - Jeweler for Tabor.  Circe 6/1/04
#include <std.h>
inherit "/std/vendor";

void create()
{
	::create();
	set_name("Cornelia");
	set_short("Cornelia, gnomish jeweler");
	set_id(({"cornelia","Cornelia","jeweler"}));
	set_long(
         "%^RESET%^%^CYAN%^Cornelia is a young gnomish woman barely "+
         "in her early thirties.  Her long, %^WHITE%^silver hair "+
         "%^CYAN%^is worn flowing well past her waist with the front "+
         "pulled back into an elaborate coiffure of tiny braids "+
         "decorated and arranged with %^BOLD%^%^RED%^c%^RESET%^"+
         "%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^f%^RESET%^"+
         "%^BLUE%^u%^MAGENTA%^l %^CYAN%^strands of %^YELLOW%^crystals "+
         "%^RESET%^%^CYAN%^in all %^BOLD%^h%^MAGENTA%^u%^RED%^e%^GREEN%^"+
         "s%^RESET%^%^CYAN%^.  She has %^BOLD%^%^BLUE%^bright blue eyes "+
         "%^RESET%^%^CYAN%^that sparkle at the mention of gems, and "+
         "she seems to enjoy spending all her time working in her "+
         "shop.  A long, %^YELLOW%^flowing dress %^RESET%^%^CYAN%^"+
         "reaches all the way to her "+
         "toes - not much of a feat for a gnome, really - and touches "+
         "only on her shoulders and waist, where it is secured with "+
         "a velvet sash."
	);

	set_race("gnome");
	set_gender("female");
	set_hd(20,4);
	set_max_hp(150+random(50));
	set_hp(query_max_hp());
	set_overall_ac(-12);
	set_alignment(4);
	set_class("mage");
	set_class("cleric");
	set_mlevel("mage",20);
	set_mlevel("cleric",20);
	set_level(20);
	set_stats("intelligence",18);
	set_stats("wisdom",18);
	set_stats("charisma",16);
	set_stats("strength",9);
	set_stats("constitution",8);
	set_stats("dexterity",14);
	set_diety("tymora");
	set_spells(({
	"meteor swarm",
	"flame strike",
	"mystic bolt",
	"limb attack",
	"monster summoning vii",
	"chain lightning",
	}));
	set_spell_chance(100);
	set_exp(100);
	set("aggressive",0);
	add_money("gold",random(50));
	set_storage_room("/d/darkwood/tabor/include/jeweler.c");
        force_me("speech speak in a calm, fluid voice");
      set_nwp("jewelling",15);
      set_mymaxvalue(8);
}

void reset(){
   ::reset();
   if(query_night()){
      tell_room(ETO,"%^BOLD%^%^GREEN%^Cornelia packs up her things and heads home.");
      TO->move("/d/shadowgate/void");
      destruct(TO);
   }
}
