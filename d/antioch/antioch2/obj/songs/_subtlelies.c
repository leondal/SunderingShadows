#include <std.h>
inherit DAEMON;

//Subtle Lies

int cmd_subtlelies(string str)
{
	TP->force_me("speech say softly");
	TP->force_me("emote looks around at "+TP->query_possessive()+" audience carefully.");
	call_out("start",3,TP);
	return 1;
}

int start()
{
	TP->force_me("say Our subtle %^YELLOW%^lies%^RESET%^,");
	TP->force_me("say Our hidden %^BOLD%^%^BLUE%^shame%^RESET%^;");
	TP->force_me("speech speak louder");
	TP->force_me("say A somber pit");
	TP->force_me("say Of bleak %^RED%^remorse%^RESET%^.");
	TP->force_me("emote walks in a slow circle.\n");
	call_out("verse2",8,TP);
	return 1;
}

int verse2()
{
	TP->force_me("speech say in a questioning tone");
	TP->force_me("say Can we admit");
	TP->force_me("say We are to blame;");
	TP->force_me("say Could we give rise");
	TP->force_me("say To such a force?");
	TP->force_me("emote seems to be looking right at you as "+TP->query_subjective()+" asks this.\n");
	call_out("verse3",8,TP);
	return 1;
}

int verse3()
{
	TP->force_me("emote slowly turns away from you as though thinking out loud to "+TP->query_objective()+"self.");
	TP->force_me("speech say evenly");
	TP->force_me("say We %^YELLOW%^make%^RESET%^ our %^ORANGE%^choice%^RESET%^,");
	TP->force_me("say We %^BLUE%^shed%^RESET%^ our %^BOLD%^%^BLUE%^tears%^RESET%^;");
	call_out("verse4",5,TP);
	return 1;
}

int verse4()
{
	TP->force_me("speech say with wonder");
	TP->force_me("say How great our thirst,");
	call_out("verse5",1,TP);
	return 1;
}

int verse5()
{
	TP->force_me("say How great our goals.");
	call_out("verse6",3,TP);
	return 1;
}

int verse6()
{
	TP->force_me("speech say with venom");
	TP->force_me("say The %^BOLD%^best%^RESET%^ and %^BOLD%^%^BLACK%^worst");
	TP->force_me("say Of %^YELLOW%^hopes%^RESET%^ and %^BOLD%^%^RED%^fears%^RESET%^;");
	call_out("verse7",3,TP);
	return 1;
}

int verse7()
{
	TP->force_me("speech say quietly");
	TP->force_me("say A nameless voice");
	TP->force_me("say Which drinks our souls.\n");
	call_out("verse8",3,TP);
	return 1;
}

int verse8()
{
	TP->force_me("emote looks up at you with imploring, soulful eyes.");
	TP->force_me("emote clenches "+TP->query_possessive()+" fist in sudden anger and turns away, head bowed in agonized silence.");
	"/d/antioch/antioch2/mons/minstrel.c"->call_out("end_song",1,TP);
	return 1;
}
