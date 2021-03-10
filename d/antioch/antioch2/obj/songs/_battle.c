#include <std.h>
inherit DAEMON;

//The Ballad of Sir Tylorune

int cmd_battle(string str)
{
	TP->force_me("speech sing in a light, lilting voice");
	TP->force_me("emote strums several chords of a lively tune.");
   TP->force_me("say His mithril armor burnished bright,");
   TP->force_me("say One gauntlet %^BOLD%^%^BLACK%^black%^RESET%^, the other %^BOLD%^white%^RESET%^.");
   TP->force_me("say His helm alive with brilliant %^YELLOW%^light%^RESET%^,");
   TP->force_me("say His longsword danced with %^BOLD%^%^RED%^flame%^RESET%^.\n");
	call_out("verse3",8,TP);
	return 1;
}

int verse3()
{
	TP->force_me("emote looks up into the sky as if expecting this great warrior to appear.");
   TP->force_me("say This hero faced his greatest test;");
   TP->force_me("say This battle would complete his quest.");
   TP->force_me("say The shield he carried bore his %^YELLOW%^crest%^RESET%^;");
   TP->force_me("say %^BOLD%^Sir Tylorune%^RESET%^ was his name.\n");
	call_out("verse4",8,TP);
	return 1;
}

int verse4()
{
	TP->force_me("speech sing in a deep bass");
   TP->force_me("say For courage and for strength he prayed,");
   TP->force_me("say To Tyr, the god who he obeyed.");
   TP->force_me("say His %^YELLOW%^trust%^RESET%^ and %^BOLD%^faith%^RESET%^ would give him aid;");
   TP->force_me("say He would not fight alone.\n");
	call_out("verse5",8,TP);
	return 1;
}

int verse5()
{
	TP->force_me("emote throws "+TP->query_possessive()+" lute across his back and strikes a valiant pose.");
    TP->force_me("say '%^BOLD%^For honor, and for Tyr!%^RESET%^', he roared,");
    TP->force_me("say And leapt to battle for his lord.");
	TP->force_me("emote leaps towards you suddenly.");
   TP->force_me("say Opposing that %^BOLD%^%^BLACK%^unholy%^RESET%^ sword,");
   TP->force_me("say He charged to match his own.");
	TP->force_me("emote parries a few imaginary blows with "+TP->query_possessive()+" rapier.\n");
	call_out("verse6",8,TP);
	return 1;
}

int verse6()
{
	TP->force_me("emote begins to circle around the audience as he weaves "+TP->query_possessive()+" song.");
	TP->force_me("speech sing in an entrancing melody");
   TP->force_me("say And locked in battle, toe to toe,");
   TP->force_me("say He stood against his mortal foe,");
   TP->force_me("say Exchanging blow for deadly blow,");
   TP->force_me("say A small and savage war.");
	TP->force_me("emote continues to parry imaginary blows with "+TP->query_possessive()+" rapier as "+TP->query_subjective()+" circles around.\n");
	call_out("verse7",10,TP);
	return 1;
}

int verse7()
{
	TP->force_me("emote stumbles to the ground as though hit, but gets up and continues battling "+TP->query_possessive()+" imaginary opponent.");
	TP->force_me("speech sing in a lively tone");
   TP->force_me("say The damage done by each was vast;");
   TP->force_me("say He knew his %^BOLD%^%^RED%^health%^RESET%^ was failing fast.");
   TP->force_me("say The next exchange might be the last;");
   TP->force_me("say He could not stand much more.");
	TP->force_me("emote falls to "+TP->query_possessive()+" knees, panting.\n");
	call_out("verse8",8,TP);
	return 1;
}

int verse8()
{
	TP->force_me("speech chant in a low bass");
   TP->force_me("say And yet he vowed he would not yield.");
   TP->force_me("say He stood his ground, and raised his shield,");
	TP->force_me("emote stands slowly, bringing "+TP->query_possessive()+" shield up.");
   TP->force_me("say To win or die upon this %^GREEN%^field%^RESET%^;");
   TP->force_me("say The fateful moment neared.");
	TP->force_me("emote circles around the crowd in silence for a moment.\n");
	call_out("verse9",10,TP);
	return 1;
}

int verse9()
{
	TP->force_me("speech sing in a deep voice");
   TP->force_me("say And in his rival, there was doubt.");
   TP->force_me("say Afraid that he might lose this bout,");
   TP->force_me("say The man of evil's nerve gave out;");
   TP->force_me("say The coward disappeared.");
	TP->force_me("emote chases off an imaginary foe.\n");
	call_out("verse10",7,TP);
	return 1;
}

int verse10()
{
	TP->force_me("emote turns back to the audience.");
	TP->force_me("speech sing in resonating tones");
   TP->force_me("say His masquerade of honor gone,");
   TP->force_me("say With craven guile, this evil spawn");
   TP->force_me("say Did soon return, to battle on;");
   TP->force_me("say Most foully did he fight.");
	TP->force_me("emote stands perfectly still.\n");
	call_out("verse11",7,TP);
	return 1;
}

int verse11()
{
	TP->force_me("speech sing in a loud and confident tone");
   TP->force_me("say But at our hero's side now stood");
   TP->force_me("say The valiant Order Knights, who would,");
   TP->force_me("say United on the side of good,");
   TP->force_me("say Prove steadfast in their might.\n");
 	call_out("verse12",7,TP);
	return 1;
}

int verse12()
{
	TP->force_me("emote creates an illusion of a troup of knights with the crest of a %^YELLOW%^metallic dragon%^RESET%^ on their chests standing against several cowardly foes in black armor.");
	TP->force_me("sing proudly");
   TP->force_me("say Courageously, they joined the fray,");
   TP->force_me("say And only Arawn ran away.");
   TP->force_me("say At last the party won the day,");
   TP->force_me("say And killed the wicked beast.");
	TP->force_me("emote swipes away the the illusion of the cowardly knight, the images of the brave knights grow larger, impressive in their shining plate mail.\n");
	call_out("verse13",12,TP);
	return 1;
}

int verse13()
{
	TP->force_me("speech say solemnly");
	TP->force_me("emote looks you directly in the eyes.");
   TP->force_me("say Remember well, and heed this tale;");
   TP->force_me("say The %^BOLD%^noble hearted%^RESET%^ will not fail.");
   TP->force_me("say For in the end, the %^BOLD%^good%^RESET%^ prevail,");
   TP->force_me("say And %^BOLD%^%^BLACK%^evil%^RESET%^ will be greased.");
	say("The brave knights gallop off into the sky, slowly fading out of sight as the bard strums a few last rifts.\n");
	"/d/antioch/antioch2/mons/minstrel.c"->call_out("end_song",1,TP);
	return 1;
}
