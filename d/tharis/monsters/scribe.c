//Changing his description slightly since more than one 
//of him can load in Tharis at the same time
//Looks odd to have 3 Gorraphas ;) ~Circe~ 6/4/07
#include <std.h>
#include <langs.h>

inherit SCRIBE;

int end_game(string str, object ob, string lang);


void create() {
    ::create();
//    set_name("Gorrapha the scribe");
    set_name("A wandering scribe");
    set_id(({"scribe","vendor"}));
    set_race("human");
    set_gender("male");
//    set_short("Gorrapha, Scribe of Tharis");
/*    set("long", "This tiny little man looks under nourished with an unkept goetee and boney fingers. He is dressed in a typical and plain uniform of sorts and awaits your command or for you to move on so that a real customer may inquire about his services. He will write anything for you, for a price. type <write>.\n");
*/
    set_short("A wandering scribe");
    set_long("This tiny little man looks as if he has missed a few meals.  "+
       "He is dressed in a plain uniform of sorts, and he awaits your "+
       "command - or for you to move on so that a real customer "+
       "may inquire about his services.  He will <write> anything for you, "+
       "for a price.  He will <translate [item] to [language] for you.  "+
	"He can also give you an estimate of how much it will cost to translate an "+
	"item, by using <estimate [item]>");
    set_level(1);
	set_scribe_name("gorrapha");
	set_region("tharis");
    set_body_type("human");
    set_class("mage");
    set("aggressive", 0);
    set_alignment(3);
    set_size(2);
    set_stats("intelligence",6);
    set_stats("wisdom",4);
    set_stats("strength",13);
    set_stats("charisma",3);
    set_stats("dexterity",8);
    set_stats("constitution",7);
    set_max_mp(0);
    set_mp(query_max_mp());
    set_hd(1, 1);
    set_exp(10);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    add_money("silver",random(10));
    add_money("gold",random(5));
    add_money("copper",random(20));
}  
