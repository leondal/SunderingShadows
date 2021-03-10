#include <std.h>
inherit DAEMON;

//Black is the Color of my True Love's Hair

int cmd_blackhair(string str)
{
	TP->force_me("speech recite slowly");
	TP->force_me("say %^BOLD%^%^BLACK%^Black, black, black");
	TP->force_me("say Is the color of my true love's hair");
	TP->force_me("say Her lips are like a %^BOLD%^%^RED%^rose%^RESET%^ so fair");
	TP->force_me("say And the prettiest face and the neatest hands.");
	TP->force_me("say I love the %^BOLD%^%^GREEN%^grass%^RESET%^ whereon she stands");
	TP->force_me("say She with the wondrous hair.\n");
	call_out("verse1",8,TP);
	return 1;
}

int verse1()
{
	TP->force_me("speech speak passionately");
	TP->force_me("say %^BOLD%^%^BLACK%^Black, black, black");
	TP->force_me("say Is the color of my true love's hair");
	TP->force_me("say Her face is something truly rare.");
	TP->force_me("say Oh I do love my love and so well she knows");
	TP->force_me("say I love the ground whereon she goes.");
	TP->force_me("say She with the wondrous hair.\n");
	call_out("verse2",8,TP);
	return 1;
}

int verse2()
{
	TP->force_me("speech speak reverntly");
	TP->force_me("say %^BOLD%^%^BLACK%^Black, black, black");
	TP->force_me("say Is the color of my true love's hair");
	TP->force_me("say Alone, my life would be so bare.");
	TP->force_me("say I would sigh, I would %^BOLD%^%^BLUE%^weep,");
	TP->force_me("say I would never fall asleep");
	TP->force_me("say My love is 'way beyond compare");
	TP->force_me("say She with the wondrous hair.");
	call_out("verse3",8,TP);
	return 1;
}

int verse3()
{
	TP->force_me("speech say wistfully");
	TP->force_me("say %^BOLD%^%^BLACK%^Black, black, black");
	TP->force_me("say Is the color of my true love's hair.");
	TP->force_me("emote sighs wistfully as "+TP->query_subjective()+" finishes the poem.\n");
	TP->force_me("end");
	return 1;
}
