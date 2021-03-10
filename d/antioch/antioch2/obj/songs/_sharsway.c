#include <std.h>
inherit DAEMON;

//Shar's Way

int cmd_sharsway(string str)
{
	TP->force_me("speech say");
	TP->force_me("say This is an older piece entitled Shar's Way.");
	call_out("start",4,TP);
	return 1;
}

int start()
{
	TP->force_me("speech sing in a soft whisper");
	TP->force_me("emote strums the chords of a haunting melody.");
	TP->force_me("say Darkened %^BOLD%^%^BLUE%^whispers%^RESET%^ in the night");
   TP->force_me("say Echo %^BOLD%^%^BLACK%^deeply%^RESET%^ in your mind,");
	TP->force_me("say Nightmares stir a horrid fright,");
   TP->force_me("say You fear for what you just might find.");
	call_out("verse1",5,TP);
	return 1;
}

int verse1()
{
	TP->force_me("say %^BLUE%^Loneliness%^RESET%^ and %^BLUE%^loss%^RESET%^ console you,");
   TP->force_me("say A numbing %^BOLD%^%^BLUE%^cold%^RESET%^ soothes your soul,");
	TP->force_me("say The murky %^BOLD%^%^BLACK%^clouds%^RESET%^ obscure your view,");
   TP->force_me("say %^YELLOW%^Truth%^RESET%^ is a long forgotten goal.");
	call_out("verse2",6,TP);
	return 1;
}

int verse2()
{
	TP->force_me("say You followed a path of %^BOLD%^good%^RESET%^ intentions");
   TP->force_me("say Into the depths of deep %^BLUE%^despair%^RESET%^.");
	TP->force_me("say You've thought of all possible preventions,");
   TP->force_me("say But somehow have simply ceased to care.\n");
	call_out("verse3",7,TP);
	return 1;
}

int verse3()
{
	TP->force_me("say You hear %^BLUE%^Her%^RESET%^ whispers in your mind,");
   TP->force_me("say %^BOLD%^%^BLACK%^Shadows%^RESET%^ caress your aching %^RED%^heart%^RESET%^.");
	TP->force_me("say You leave that miserable life behind");
   TP->force_me("say And yield to %^BLUE%^Her%^RESET%^ darkened art.\n");
	call_out("verse4",6,TP);
	return 1;
}

int verse4()
{
	TP->force_me("say And so another %^YELLOW%^light%^RESET%^ extinguished,");
	TP->force_me("say And so another slips %^BLUE%^Her%^RESET%^ way,");
	TP->force_me("say Will all the %^YELLOW%^lights%^RESET%^ soon be vanquished?");
	TP->force_me("say %^BLUE%^Eternal night%^RESET%^ would swallow day.");
	tell_room(ETP,"The last few chords seem to hang in the air as "+TP->query_cap_name()+" finishes the song.\n");
	"/d/antioch/antioch2/mons/minstrel.c"->call_out("end_song",1,TP);
	return 1;
}
