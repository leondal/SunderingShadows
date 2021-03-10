#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/brewing/herb_special_inherit";

int FLAG;

void create() {
	::create();
      set_herb_name("nycissa orchid");
	set_name("%^MAGENTA%^orchid%^RESET%^");
	set_id(({"orchid","flower","bloom","Orchid","an orchid","beautiful orchid","nycissa orchid"}));
	set_short("%^RESET%^%^MAGENTA%^A beautiful nycissa orchid%^RESET%^");
	set_long(
	"%^WHITE%^This exotic flower is an orchid, and looks to be of the"+
	" rare nycissa variety. It is a %^MAGENTA%^deep purple%^WHITE%^ shade with streaks of"+
	" %^YELLOW%^yellow%^RESET%^ and %^BOLD%^%^WHITE%^white%^RESET%^ emerging from the center. It has a few"+
	" %^GREEN%^green leaves%^RESET%^ and some %^BOLD%^white tendrils%^RESET%^ attached to it still."
	);
      set_lore("%^RESET%^This particular orchid is rare and prized for its magical qualities.  While not familiar "
"to most, specialists of enchantment and alchemy alike often enlist the procurement of such a blossom to enhance "
"certain enchantments of permanence.");
      set_property("lore difficulty",25);
	set_weight(1);
	set_value(75);
}

void init() {
	::init();
	add_action("sniff","sniff");
	add_action("smell","smell");
}

int smell(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(str == "orchid") {
		tell_object(ETO,"%^MAGENTA%^The fragrance of the orchid"+
		" is unusual and faint, perhaps you should <sniff> it for"+
		" a better scent.");
		tell_room(ETO,"%^MAGENTA%^"+ETO->query_cap_name()+" smells"+
		" the lovely fragrance of "+ETO->query_possessive()+" orchid.",ETO);
		return 1;
	}
}

int sniff(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(FLAG == 1) {
		tell_object(ETO,"%^BOLD%^There is almost no fragrance"+
		" left to this flower.");
		return 1;
	}
	if(str == "orchid") {
		tell_object(ETO,"%^BOLD%^%^MAGENTA%^You take in a deep breath"+
		" of the orchid's scent and you become a little light"+
		" headed.");
		tell_room(ETO,"%^BOLD%^%^MAGENTA%^"+ETO->query_cap_name()+""+
		" sniffs the orchid and looks a little dazed.",ETO);
		ETO->set_paralyzed(random(100)+100,"%^BOLD%^%^MAGENTA%^You"+
		" are still dazed from the scent of the orchid.");
		FLAG = 1;
		return 1;
	}
}
