#include <std.h>
#include "../antioch.h"
inherit TOWNSMAN;

int CALL;

void create()
{
	::create();
   CALL = 0;
	set_name("Vardot");
	set_short("Vardot, the palace chef");
	set_id(({"vardot","Vardot","chef","palace chef","cook","palace cook"}));
	set_long(
	"Vardot is the renowned chef of the Antioch palace. He was chosen by the"+
	" king himself for his fine pastries and tasty meats. He spends almost"+
	" all of his time in the kitchen, cooking is his life. He is wearing a"+
   " white apron that is slightly covered in flour and herbs. A long red"+
	" ponytail flows from beneath his white cap. He is almost six feet tall"+
	" and is slightly on the plump side, though you can see many muscles"+
	" beneath his shirt. His blue eyes hold a happy twinkle, and he seems"+
	" quite engrossed with making sure everything in the kitchen meets his"+
	" standards."
	);
	set_gender("male");
	set_race("human");
	set_alignment(1);
	set_hd(15,5);
	set_overall_ac(-3);
	set_class("fighter");
	set_mlevel("fighter",15);
	set("aggressive",0);
	set_stats("strength",18);
	set_stats("wisdom",16);
	set_stats("intelligence",13);
	set_stats("dexterity",8);
	set_stats("charisma",13);
	set_stats("constitution",17);
	set_exp(10);
	command("set speech say in a jolly tone");
	set_emotes(5,({
	"Vardot stirs the soup slowly.",
	"Vardot mixes some batter in a bowl.",
	"Vardot adds a few herbs and spices to the soup.",
	"Vardot checks on the roasting meat.",
	"Vardot chops up some fresh vegetables.",
	"Vardot samples some of the fruit.",
	"Vardot slices a fresh loaf of bread.",
	}),0);
}

void heart_beat()
{
	object ob, *atkrs;
	int x, CALL;
	if(!objectp(TO)) return;
	atkrs = TO->query_attackers();
	::heart_beat();
	if(atkrs != ({ }) && CALL != 1) {
		call_out("summon_guards",5);
		force_me("yell Help, I'm being attacked! Someone call the guards!");
         CALL = 1;
	}
}

int summon_guards()
{
	object ob;
	tell_room(ETO,"%^BOLD%^Several guards burst into the room.");
	new(MONS+"royal guard")->move(ETO);
	if(sizeof(TO->query_attackers()) > 1) {
		new(MONS+"royal_guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 2) {
		new(MONS+"royal_guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 3) {
		new(MONS+"royal_guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 4) {
		new(MONS+"royal_guard")->move(ETO);
	}
	if(sizeof(TO->query_attackers()) > 5) {
		new(MONS+"royal_guard")->move(ETO);
	}
	return 1;
}
