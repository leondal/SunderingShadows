#include <std.h>
inherit "/std/magistrate.c";
void create(){
	::create();
    set_name("Cadaogan Justicar");
    set_short("Cadaogan Justicar, Magistrate of Tabor");
	set_id(({"magistrate","Magistrate","judge","Magistrate of Tabor","magistrate of tabor","cadaogan","cadaogan justicar","Cadaogan Justicar"}));
	set_long(
	"This is the magistrate of Tabor. He presides over the cases that come"+
	" before him. He is dressed in the black robes of a magistrate and"+
	" looks rather stern. He sits atop a large dias in the center of the"+
   " room, looking down at those who come to plead their cases before"+
   " him with a slight air of superiority and boredom."
	);
	set_gender("male");
	set_race("human");
	set_hd(10,1);
	set_exp(1);
	set_class("fighter");
	set_mlevel("fighter",10);
	set_alignment(2);
	set_max_hp(100);
	set_hp(query_max_hp());
	set_overall_ac(6);
	set_stats("charisma",10);
	set_stats("strength",18);
	set_stats("dexterity",12);
	set_stats("wisdom",20);
	set_stats("intelligence",20);
	set_stats("constitution",15);
	set("aggressive",0);
        set_random_act_chance(5);
        set_need_addressed(1);
}
