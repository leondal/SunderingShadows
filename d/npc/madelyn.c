#include <std.h>
#include <daemons.h>

inherit NPC;
//Disguise teacher - Cythera 4/05
void create(){
::create();
	set_name("madelyn");
	set_short("Madelyn Pallisade, actress");
	set_id(({"Madelyn Pallisade","madelyn","pallisade","human","actress"}));
	set_long("%^CYAN%^One of Torm's favored actresses, Madelyn Pallisade"+
		" is a regular at any of the productions held at the Coral "+
		"Sky Amphitheater.  Dressed in a %^BLUE%^dark blue%^CYAN%^ "+
		"silk gown with %^BOLD%^%^GREEN%^bright green%^RESET%^%^CYAN%^"+
		" lace trim, Madelyn moves through the streets studying the "+
		"people who passes her by.  Her long %^RED%^auburn%^CYAN%^ "+
		"hair is pinned up under her %^BLUE%^%^BOLD%^blue%^RESET%^"+
		"%^CYAN%^ velvet hat.  Madelyn is well known for her "+
		"ability to disguise her striking features to fit any "+
		"role she plays.  It's said that the inspiration she "+
		"gets for her many roles come from those she witnesses on"+
		" the streets of Torm.");
	set_gender("female");
	set_race("human");
	set_hd(30,10);
	set_max_hp(200+random(250));
	set_hp(query_max_hp());
	set_alignment(5);
	set_body_type("human");
	set_size(2);
	set_overall_ac(-7);
	set_class("bard");
	set_mlevel("bard",30);
	set_level(30);
	set_property("full attacks",1);
   	set_exp(100);
	command("speech intone carefully");
	command("speak wizish");
  	set_speed(40);
   set_nwp("disguise",13,500);
	set_emotes(10, ({"%^BOLD%^%^BLUE%^Madelyn carefully watches the crowd.","%^BOLD%^%^GREEN%^Madelyn studies the movements and dress of a young woman carefully.","%^BLUE%^Madelyn observes the actions of a group of older women, taking notes in her book","%^GREEN%^Madelyn carefully watches the body language of an female elf."}), 0);

}