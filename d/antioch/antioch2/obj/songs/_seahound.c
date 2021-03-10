#include <std.h>
inherit DAEMON;

//The Howl of the Sea Hound, by Androkk

int cmd_seahound(string str)
{
	TP->force_me("speech say");
	TP->force_me("say This is a song that I learned from the bard Androkk.");
	TP->force_me("emote strums a slow, haunting melody on "+TP->query_possessive()+" lute as "+TP->query_subjective()+" begins the song.");
	call_out("verse1",6,TP);
	return 1;
}

int verse1()
{
	TP->force_me("speech sing a slow melody");
	TP->force_me("say Under the %^BLUE%^deep%^RESET%^ dark waters of the %^BOLD%^%^BLUE%^sea");
	TP->force_me("say Lies a friend in sad company");
	TP->force_me("say From the %^BLUE%^deepest%^RESET%^ depths you can hear his call");
	TP->force_me("say But do not try to see him or you will surely fall");
	call_out("verse2",8,TP);
	return 1;
}

int verse2()
{
	TP->force_me("say Staring up through endless churning %^CYAN%^waves");
	TP->force_me("say Every moment he sees, he saves");
	TP->force_me("say For on the clearest %^BOLD%^%^BLACK%^nights%^RESET%^ when heaven's up above");
	TP->force_me("say He thinks they %^YELLOW%^shine%^RESET%^ for him, he thinks they %^YELLOW%^shine%^RESET%^ for %^BOLD%^%^RED%^love");
	call_out("verse3",8,TP);
	return 1;
}

int verse3()
{
	TP->force_me("say Crying in the %^BOLD%^starlight%^RESET%^ appearing for the faith");
	TP->force_me("say Wondering about his friend drifting in the %^CYAN%^waves");
	TP->force_me("say Some %^BOLD%^%^BLACK%^nights%^RESET%^ they say you can hear his howl");
	TP->force_me("say From the darkest %^BLUE%^depths%^RESET%^ of %^BOLD%^%^BLUE%^ocean%^RESET%^ foul");
	call_out("verse4",8,TP);
	return 1;
}

int verse4()
{
	TP->force_me("say Painless memories of the %^RED%^burning%^RESET%^ past");
	TP->force_me("say They do not appear, they do not seem to last");
	TP->force_me("say The %^BLUE%^sadness%^RESET%^ in his voice, the %^BOLD%^%^BLACK%^darkness%^RESET%^ of his choice");
	TP->force_me("say Will be remembered, in this song...");
	call_out("verse5",8,TP);
	return 1;
}

int verse5()
{
	TP->force_me("say He left his pack a %^BOLD%^%^BLACK%^night%^RESET%^ so long");
	TP->force_me("say To search the %^BOLD%^%^BLUE%^seas%^RESET%^ for his %^BOLD%^%^RED%^love%^RESET%^ evermore");
	TP->force_me("say But got lost, he did, on his tour");
	TP->force_me("say And he never found his way");
	TP->force_me("say Still you hear his howls to this very day...");
	TP->force_me("emote finishes the last haunting chords.");
	tell_room(ETP,"%^BOLD%^%^BLUE%^You hear a chilling howl that seems to echo in the air.");
	"/d/antioch/antioch2/mons/minstrel.c"->call_out("end_song",1,TP);
	return 1;
}
