#include <std.h>
inherit DAEMON;

//Ring their Bells

int cmd_ringbells(string str)
{
	TP->force_me("speech sing a jolly tune");
	TP->force_me("emote begins to play a lively tune on "+TP->query_possessive()+" lute.");
	TP->force_me("say Slashing through the Orcs");
	TP->force_me("say With a good two-handed blade");
	TP->force_me("say Over corpses we go");
	TP->force_me("say And through the gore we wade");
	TP->force_me("say Mace on helmet rings");
	TP->force_me("say Making bodies fly");
	TP->force_me("say What fun to sing our Slaying Song");
	TP->force_me("say And watch these suckers DIE!\n");
	call_out("chorus1",12,TP);
	return 1;
}

int chorus1()
{
	TP->force_me("say Oh, ring their bells with swords and spells");
	TP->force_me("say Don't let 'em get away!");
	TP->force_me("say We're brave and bold for fame and gold");
	TP->force_me("say We'll make a lot today!");
	TP->force_me("say Oh, ring their bells with swords and spells");
	TP->force_me("say Don't let 'em get away!");
	TP->force_me("say We'll hack and slash and blast and trash");
	TP->force_me("say And blow these dudes away!\n");
	call_out("verse2",12,TP);
	return 1;
}

int verse2()
{
	TP->force_me("say Crashing through the door");
	TP->force_me("say Into the Dragon's nose");
	TP->force_me("say Our mage whips out a Cone of Cold");
	TP->force_me("say And out his fire goes!");
	TP->force_me("say Elven bowstrings sing");
	TP->force_me("say Making Balrogs fall");
	TP->force_me("say And our theif finds a secret door");
	TP->force_me("say Into the treasure hall!\n");
	call_out("chorus2",12,TP);
	return 1;
}

int chorus2()
{
	TP->force_me("say Oh, ring their bells with swords and spells");
	TP->force_me("say Don't let 'em get away!");
	TP->force_me("say We're brave and bold for fame and gold");
	TP->force_me("say We'll make a lot today!");
	TP->force_me("say Oh, ring their bells with swords and spells");
	TP->force_me("say Don't let 'em get away!");
	TP->force_me("say We'll hack and slash and blast and trash");
	TP->force_me("say And blow these dudes away!\n");
	call_out("verse3",8,TP);
	return 1;
}

int verse3()
{
	TP->force_me("say Then appears the Lich");
	TP->force_me("say With his demon guard");
	TP->force_me("say Our wizard yawns and wishes");
	TP->force_me("say We'd run into something hard.");
	TP->force_me("say He begins to cast");
	TP->force_me("say His 19th level spell");
	TP->force_me("say The damn lich throws a Gate at us");
	TP->force_me("say And drops us all in Hell!\n");
	call_out("chorus3",12,TP);
	return 1;
}

int chorus3()
{
	TP->force_me("say Oh, ring their bells with swords and spells");
	TP->force_me("say Don't let 'em get away!");
	TP->force_me("say We're brave and bold for fame and gold");
	TP->force_me("say We'll make a lot today!");
	TP->force_me("say Oh, ring their bells with swords and spells");
	TP->force_me("say Don't let 'em get away!");
	TP->force_me("say We'll hack and slash and blast and trash");
	TP->force_me("say And blow these dudes away!\n");
	call_out("verse4",8,TP);
	return 1;
}

int verse4()
{
	TP->force_me("say We appear in Hell");
	TP->force_me("say In front of Cyric's throne");
	TP->force_me("say Our Cleric waves us out the door");
	TP->force_me("say And takes him on alone!");
	TP->force_me("say Cyric's legions don't");
	TP->force_me("say Want to let us go");
	TP->force_me("say Our gnome inventor pulls out this wand");
	TP->force_me("say That shoots out an eerie GLOW!\n");
	call_out("verse5",12,TP);
	return 1;
}

int verse5()
{
	TP->force_me("say Oh, ring their bells with Prayers and Spells");
	TP->force_me("say Don't let 'em get away!");
	TP->force_me("say We're brave and bold and CRAZED, we're told");
	TP->force_me("say To think we'll live the day!");
	TP->force_me("say Oh, ring their bells with swords and SPELLS");
	TP->force_me("say Don't let 'em get away!");
	TP->force_me("say We'll hack and slash and blast and trash");
	TP->force_me("say And drag our loot away!\n");
       TP->force_me("emote finishes with a dramatic flurry of chords.");
	"/d/antioch/antioch2/mons/minstrel.c"->call_out("end_song",1,TP);
	return 1;
}
