#include <std.h>
inherit DAEMON;

//A Bard's Farewell

int cmd_bardfarewell(string str)
{
	TP->force_me("speech sing in a strong voice");
	TP->force_me("emote tunes "+TP->query_possessive()+" lute and begins a slightly mournful tune.");
   TP->force_me("say You soon will be out facing danger and strife,");
   TP->force_me("say You soon will be fighting and risking your life.");
   TP->force_me("say I know there is use for my saber and knife;");
   TP->force_me("say Alas, I will not be along.\n");
	call_out("verse2",6,TP);
	return 1;
}

int verse2()
{
	TP->force_me("emote looks soulfully into your eyes as "+TP->query_subjective()+" plays the sad tune.");
	TP->Force_me("speech sing in a regretful tone");
   TP->force_me("say We all have our limits, and I'm nearing mine;");
   TP->force_me("say And so, with your pardon, I'll have to decline,");
   TP->force_me("say For I've an appointment with women and wine,");
   TP->force_me("say And gaming and music and song.\n");
	call_out("verse3",7,TP);
	return 1;
}

int verse3()
{
	TP->force_me("speech sing in a tired manner");
	TP->force_me("emote looks down at the ground as "+TP->query_subjective()+" plays the soft melody.");
   TP->force_me("say It's been far too long since I've gambled and drank,");
   TP->force_me("say Too long in that dungeon, disgusting and dank,");
   TP->force_me("say Too long amidst refuse, repulsive and rank,");
   TP->force_me("say Too long without love and romance.\n");
	call_out("verse4",7,TP);
	return 1;
}

int verse4()
{
	TP->force_me("speech sing in a beautiful alto");
   TP->force_me("say Before I embark on some hazardous quest,");
   TP->force_me("say Before once again I am put to the test,");
   TP->force_me("say If I don't take time to recover and rest,");
   TP->force_me("say My sanity hasn't a chance.");
	TP->force_me("emote smiles wryly.\n");
	call_out("verse5",6,TP);
	return 1;
}

int verse5()
{
	TP->force_me("speech sing lightly");
	TP->force_me("winks at you playfully.");
   TP->force_me("say It's not that your company isn't a thrill,");
   TP->force_me("say I'm truly impressed with your courage and skill,");
   TP->force_me("say And happy to journey beside you; but still,");
   TP->force_me("say I need to be free for a time.\n");
	call_out("verse6",6,TP);
	return 1;
}

int verse6()
{
	TP->force_me("speech sing in a quiet voice");
   TP->force_me("say When we meet again, we'll have stories to share,");
   TP->force_me("say So go with the Gods; good luck, and take care.");
   TP->force_me("say May travel be pleasant, and fortune be fair,");
   TP->force_me("say And may you find meter and rhyme.");
	TP->force_me("emote strums the last few chords, coming to a slow finish.\n");
	TP->force_me("end");
	return 1;
}
