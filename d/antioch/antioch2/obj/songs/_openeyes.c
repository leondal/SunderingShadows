#include <std.h>
inherit DAEMON;

//Open Your Eyes

int cmd_openeyes(string str)
{
	TP->force_me("speech say gently");
	TP->force_me("say Open your %^CYAN%^eyes%^RESET%^ little one,");
	TP->force_me("say And see the world around you.");
	TP->force_me("say There are wonders you have never explored,");
	TP->force_me("say Never dreamed of or imagined.");
	TP->force_me("say There's a world out there, take a look and see.");
	TP->force_me("say %^BOLD%^%^CYAN%^Open your eyes.\n");
	call_out("verse1",8,TP);
	return 1;
}

int verse1()
{
	TP->force_me("say Open your %^RED%^heart%^RESET%^ little one,");
	TP->force_me("say Don't be afraid to feel.");
	TP->force_me("say Going through life cold and numb is a waste.");
	TP->force_me("say There is so much warmth out there,");
	TP->force_me("say The people who love you are real.");
	TP->force_me("say %^BOLD%^%^RED%^Open your heart.\n");
	call_out("verse2",8,TP);
	return 1;
}

int verse2()
{
	TP->force_me("say Open your %^ORANGE%^arms%^RESET%^ little one,");
	TP->force_me("say Embrace the ones you care about.");
	TP->force_me("say You never know when it's the last time you'll see,");
	TP->force_me("say Show them how much you care,");
	TP->force_me("say Quickly before their time runs out.");
	TP->force_me("say %^YELLOW%^Open your arms.\n");
	"/d/antioch/antioch2/mons/minstrel.c"->call_out("end_song",1,TP);
	return 1;
}