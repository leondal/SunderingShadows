#include <std.h>
inherit "/std/magistrate.c";
void create(){
	::create();
    set_name("Yuan-Tam Kim");
    set_short("Yuan-Tam Kim, Magistrate of Shadow");
	set_id(({"magistrate","Magistrate","judge","Magistrate of Shadow","magistrate of shadow"}));
	set_long(
	"This is the magistrate of Shadow. He presides over the cases that come"+
	" before him. He is dressed in the black robes of a magistrate and"+
	" looks rather stern."
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
