#include <std.h>
inherit DAEMON;

//Creepie Crawlies

int cmd_creepiecrawlies(string str)
{
	TP->force_me("speech sing in a hushed whisper");
	TP->force_me("say Do you hear the %^BLUE%^whispered%^RESET%^ voices");
	TP->force_me("say In the %^BOLD%^%^BLACK%^darkness%^RESET%^ of the night?");
	call_out("verse1",3,TP);
	return 1;
}

int verse1()
{
	TP->force_me("say Do you hear the little 'uns crying");
	TP->force_me("say As they're hidden out of sight?");
	call_out("verse2",3,TP);
	return 1;
}

int verse2()
{
	TP->force_me("say Do you hear the creepie crawlies");
	TP->force_me("say As they sneak into the town?");
	call_out("verse3",3,TP);
	return 1;
}

int verse3()
{
	TP->force_me("say Do %^BOLD%^they%^RESET%^ hear the pounding of your %^BOLD%^%^RED%^heart");
	TP->force_me("say As you're pressed against the %^GREEN%^ground%^RESET%^?\n");
	call_out("chorus1",2,TP);
	return 1;
}

chorus1()
{
	TP->force_me("speech sing loudly");
	TP->force_me("say They howl and they slither and run on many legs,");
	TP->force_me("say And the monster hunters catch 'em and throw 'em into bags!");
	TP->force_me("say They hiss and they chatter and flap their filthy wings,");
	TP->force_me("say And the monster hunters stalk 'em and kill the wretched things!\n");
	call_out("verse4",8,TP);
	return 1;
}

int verse4()
{
	TP->force_me("speech sing very softly");
	TP->force_me("say Do you fear the moving %^BOLD%^%^BLACK%^shadows");
	TP->force_me("say As you're walking all alone?");
	call_out("verse5",3,TP);
	return 1;
}

int verse5()
{
	TP->force_me("say Do you fear that something %^BOLD%^%^BLACK%^evil");
	TP->force_me("say Might slip into your home?");
	call_out("verse6",3,TP);
	return 1;
}

int verse6()
{
	TP->force_me("say Do you fear the %^ORANGE%^hot%^RESET%^ breath");
	TP->force_me("say That breathes upon your neck,");
	TP->force_me("say When nothing seems to be there");
	TP->force_me("say each time you turn around to check?\n");
	call_out("chorus2",5,TP);
	return 1;
}

int chorus2()
{
	TP->force_me("speech sing loudly");
	TP->force_me("say They howl and they slither and run on many legs,");
	TP->force_me("say And the monster hunters catch 'em and throw 'em into bags!");
	TP->force_me("say They hiss and they chatter and flap their filthy wings,");
	TP->force_me("say And the monster hunters stalk 'em and kill the wretched things!\n");
	call_out("verse7",6,TP);
	return 1;
}

int verse7()
{
	TP->force_me("speech sing in quiet tones");
	TP->force_me("say Do you believe in the %^GREEN%^monster");
	TP->force_me("say That's hiding beneath your bed?");
	call_out("verse8",3,TP);
	return 1;
}

int verse8()
{
	TP->force_me("say Do you believe in the many voices");
	TP->force_me("say That %^BLUE%^whisper%^RESET%^ in your head?");
	call_out("verse9",3,TP);
	return 1;
}

int verse9()
{
	TP->force_me("say Do you believe that someone's coming");
	TP->force_me("say To lend a helping hand?");
	call_out("verse10",5,TP);
	return 1;
}

int verse10()
{
	TP->force_me("say Or do you believe the one who's coming");
	TP->force_me("say Is the %^FLASH%^%^BOLD%^%^BLUE%^BOOGEYMAN%^RESET%^?!?\n");
	call_out("chorus3",2,TP);
	return 1;
}

int chorus3()
{
	TP->force_me("speech sing loudly");
	TP->force_me("say They howl and they slither and run on many legs,");
	TP->force_me("say And the monster hunters catch 'em and throw 'em into bags!");
	TP->force_me("say They hiss and they chatter and flap their filthy wings,");
	TP->force_me("say And the monster hunters stalk 'em and kill the wretched things!");
	call_out("verse11",4,TP);
	return 1;
}

int verse11()
{
	TP->force_me("speech sing slowly");
	TP->force_me("say But in the %^BOLD%^%^BLACK%^darkness%^RESET%^ of the night, your %^RED%^fears%^RESET%^ become undone,");
	TP->force_me("say And from the %^BLUE%^recesses%^RESET%^ of your mind, the %^FLASH%^%^GREEN%^c%^RESET%^%^GREEN%^r%^FLASH%^e%^RESET%^%^GREEN%^e%^FLASH%^p%^RESET%^%^GREEN%^i%^FLASH%^e %^RESET%^%^GREEN%^c%^FLASH%^r%^RESET%^%^GREEN%^a%^FLASH%^w%^RESET%^%^GREEN%^l%^FLASH%^i%^RESET%^%^GREEN%^e%^FLASH%^s%^RESET%^ come!\n");
	TP->force_me("end");
	return 1;
}
