#include <std.h>
inherit DAEMON;

//The Glory of Adventure

int cmd_gloryadventure(string str)
{
	TP->force_me("speech sing in a jaunting voice");
   TP->force_me("say When the enemy's surrounding,");
   TP->force_me("say And we think our nerves will fail,");
   TP->force_me("say When we hear the trumpets sounding,");
   TP->force_me("say And they make us quake and quail,");
   TP->force_me("say Grab your mug and we'll be pounding");
   TP->force_me("say Down another round of ale!\n");
	call_out("chorus1",2,TP);
	return 1;
}

int chorus1()
{
	TP->force_me("speech belt out");
	TP->force_me("emote tosses "+TP->query_possessive()+" arm over your shoulder.");
   TP->force_me("say And we'll drink,");
   TP->force_me("say To the glory of adventure!\n");
	call_out("verse2",8,TP);
}

int verse2()
{
	TP->force_me("speech sing in a jaunting voice");
   TP->force_me("say If there ever comes the day");
   TP->force_me("say When we think that we are lost,");
   TP->force_me("say When we think that we must pay");
   TP->force_me("say That most dear and final cost,");
   TP->force_me("say We'll just pass around the tray,");
   TP->force_me("say And feel better when we're sauced!\n");
	call_out("chorus2",3,TP);
}

int chorus2()
{
	TP->force_me("speech crie out");
	TP->force_me("emote motions for the crowd to sing along with "+TP->query_objective()+".");
   TP->force_me("say And we'll drink,");
   TP->force_me("say To the glory of adventure!\n");
	call_out("verse3",8,TP);
}

int verse3()
{
	TP->force_me("speech sing in a jaunting voice");
   TP->force_me("say When we're angry and upset,");
   TP->force_me("say 'Cause we ain't been getting paid,");
   TP->force_me("say When we're tired, cold and wet,");
   TP->force_me("say And a little bit afraid,");
   TP->force_me("say We'll keep drinking and forget");
   TP->force_me("say that we ever were dismayed!\n");
	call_out("chorus3",2,TP);
}

int chorus3()
{
	TP->force_me("speech shout out");
	TP->force_me("emote tosses back a shot glass that appears in "+
	  TP->query_possessive()+" hand.");
   TP->force_me("say And we'll drink,");
   TP->force_me("say To the glory of adventure!\n");
	call_out("verse4",8,TP);
}

int verse4()
{
	TP->force_me("speech sing in a jaunting voice");
   TP->force_me("say When the boredom makes us jumpy,");
   TP->force_me("say And the motion makes us ill,");
   TP->force_me("say When the food is cold and lumpy,");
   TP->force_me("say A disgusting, slimy swill,");
   TP->force_me("say There's no reason to be grumpy;");
   TP->force_me("say Tap the keg, and drink your fill!\n");
	call_out("chorus4",8,TP);
}

int chorus4()
{
	TP->force_me("speech sing joyously");
	TP->force_me("emote winks merrily at you.");
   	TP->force_me("say And we'll drink,");
   	TP->force_me("say To the glory of adventure!\n");
	call_out("verse5",8,TP);
}

int verse5()
{
	TP->force_me("speech sing in a jaunting voice");
   TP->force_me("say When the captain's really sore,");
   TP->force_me("say 'Cause he thinks he's being mocked,");
   TP->force_me("say When he's pounding on our door,");
   TP->force_me("say And we're certain to get socked,");
   TP->force_me("say Have a drink, and tease him more;");
   TP->force_me("say We'll feel nothing if we're crocked!\n");
	call_out("chorus5",4,TP);
}

int chorus5()
{
	TP->force_me("speech sing loudly");
	TP->force_me("emote spreads "+TP->query_possessive()+" arms out, motioning"+
	" everyone to join in.");
	call_out("chorus6",2,TP);
}

int chorus6()
{
   TP->force_me("say And we'll drink,");
	call_out("chorus7",1,TP);
}

int chorus7()
{
   TP->force_me("say To the glory of adventure!\n");
	TP->force_me("emote finishes with a flourish of "+TP->query_possessive()+""+
	" hat.");
	"/d/antioch/antioch2/mons/minstrel.c"->call_out("end_song",1,TP);
	return 1;
}
