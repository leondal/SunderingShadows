#include <std.h>
inherit DAEMON;

//Blow the Candles Out

int cmd_candlesout(string str)
{
	TP->force_me("speech sing a jaunty tune");
	TP->force_me("emote begins to strum a merry tune with "+TP->query_possessive()+" lute.");
	TP->force_me("say When I was apprenticed in Shadow");
	TP->force_me("say I went to see my dear");
	TP->force_me("say The %^YELLOW%^candles%^RESET%^ all were burning");
	TP->force_me("say The %^BOLD%^%^CYAN%^moon%^RESET%^ shone bright and clear.");
	call_out("verse1",6,TP);
	return 1;
}

int verse1()
{
	TP->force_me("say I knocked upon her window");
	TP->force_me("say To ease her of her pain");
	TP->force_me("say She rose up to let me in");
	TP->force_me("say Then barred the door again.");
	TP->force_me("emote winks playfully.\n");
	call_out("verse2",6,TP);
	return 1;
}

int verse2()
{
	TP->force_me("speech sing sincerely");
	TP->force_me("say I like your well behaviour");
	TP->force_me("say And this I often say");
	TP->force_me("say I cannot rest contented");
	TP->force_me("say When I am far away.");
	call_out("verse3",8,TP);
	return 1;
}

int verse3()
{
	TP->force_me("say The roads they are so muddy");
	TP->force_me("say We cannot walk about");
	TP->force_me("say So roll me in your arms my %^BOLD%^%^RED%^love");
	TP->force_me("say And blow the %^YELLOW%^candles%^RESET%^ out.");
	TP->force_me("emote blows out an illusionary candle that appears in "+TP->query_possessive()+" hand.\n");
	call_out("verse4",10,TP);
	return 1;
}

int verse4()
{
	TP->force_me("speech sing in a loud whisper");
	TP->force_me("say Your father and your mother");
	TP->force_me("say In yonder room do lie");
	TP->force_me("say A-hugging one another");
	TP->force_me("say So why not you and I?");
	TP->force_me("emote winks at you.");
	call_out("verse5",7,TP);
	return 1;
}

int verse5()
{
	TP->force_me("speech sing loudly");
	TP->force_me("say A-hugging one another");
	TP->force_me("say Without a fear or doubt");
	TP->force_me("speech whisper passionately");
	TP->force_me("say So roll me in your arms my %^BOLD%^%^RED%^love");
	TP->force_me("say And blow the %^YELLOW%^candles%^RESET%^ out.\n");
	call_out("verse6",8,TP);
	return 1;
}

int verse6()
{
	TP->force_me("speech sing quietly");
	TP->force_me("say I prithee speak more softly");
	TP->force_me("say Of what we have to do");
	TP->force_me("say Lest that our noise of talking");
	TP->force_me("say Should make our pleasure rue.");
	TP->force_me("emote stops suddenly, listening intently for any noises.");
	call_out("verse7",8,TP);
	return 1;
}

int verse7()
{
	TP->force_me("speech sing even softer");
	TP->force_me("say The streets they are so nigh, %^BOLD%^%^RED%^love");
	TP->force_me("say The people walk about");
	TP->force_me("say They may peep in and spy, %^BOLD%^%^RED%^love");
	TP->force_me("say So blow the %^YELLOW%^candles%^RESET%^ out.");
	TP->force_me("emote looks you over carefully as though you are a spy.\n");
	call_out("verse8",7,TP);
	return 1;
}

int verse8()
{
	TP->force_me("speech sing happily");
	TP->force_me("say And if we prove successful, %^BOLD%^%^RED%^love");
	TP->force_me("say Please name it after me.");
	TP->force_me("say Treat it neat and kiss it sweet");
	TP->force_me("say And daff it on your knee.");
	call_out("verse9",7,TP);
	return 1;
}

int verse9()
{
	TP->force_me("speech sing gently");
	TP->force_me("say When my three years are over");
	TP->force_me("say My time it will be out");
	TP->force_me("say And I will pay my debt to you");
	TP->force_me("say By blowing the %^YELLOW%^candles%^RESET%^ out.");
	TP->force_me("emote blows out an illusionary candle and the room darkens.\n");
	TP->force_me("emote strums the last chords softly.");
	call_out("verse10",7,TP);
	return 1;
}

int verse10()
{
	tell_room(ETP,"%^YELLOW%^After a moment the room brightens once more.");
	TP->force_me("emote smiles and bows.");
	TP->force_me("end");
	return 1;
}
