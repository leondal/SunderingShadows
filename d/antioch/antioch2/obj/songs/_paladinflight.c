#include <std.h>
inherit DAEMON;

//The Flight of the Paladins

int cmd_paladinflight(string str)
{
	TP->force_me("speech sing in a soft alto");
	TP->force_me("emote strums a few chords on "+TP->query_possessive()+" lute.");
   TP->force_me("say The %^BOLD%^%^CYAN%^sky%^RESET%^ is the stage, with a storm all around;");
   TP->force_me("say The audience helplessly waits on the ground.");
   TP->force_me("say The %^ORANGE%^dragons%^RESET%^ above claim the %^BOLD%^%^CYAN%^sky%^RESET%^ as their own,");
   TP->force_me("say And %^BOLD%^%^RED%^flame%^RESET%^ marks the path over which they have flown.");
	tell_room(ETP,"%^RED%^A flight of dragons appears high overhead.\n");
	call_out("verse2",9,TP);
	return 1;
}

int verse2()
{
	TP->force_me("speech raise "+TP->query_possessive()+" voice louder");
   TP->force_me("say Then up from below comes a thunderous cry;");
   TP->force_me("say The %^YELLOW%^paladin%^RESET%^ airborne appears in the %^BOLD%^%^CYAN%^sky%^RESET%^!");
   TP->force_me("say Each knight on his %^BOLD%^Pegasus%^RESET%^, lances at hand;");
   TP->force_me("say To battle they ride, in a glorious stand.");
	tell_room(ETP,"%^BOLD%^A troup of brave paladins in shining armor appear in the sky to fight the dragons.\n");
	call_out("verse3",9,TP);
	return 1;
}

int verse3()
{
	TP->force_me("emote plays along with "+TP->query_possessive()+" lute.");
	TP->force_me("speech sing in an awed tone");
   TP->force_me("say Mere words can't describe the magnificent fight,");
   TP->force_me("say As %^ORANGE%^dragon%^RESET%^ and %^YELLOW%^paladin%^RESET%^ battle this night.");
   TP->force_me("say Raw courage and steel against talon and breath,");
   TP->force_me("say As more than one hero earns %^YELLOW%^honor%^RESET%^ in %^BOLD%^%^BLACK%^death%^RESET%^.");
	TP->force_me("emote strums a few melancholy chords.\n");
	call_out("verse4",9,TP);
	return 1;
}

int verse4()
{
	TP->force_me("speech sing with pride in "+TP->query_possessive()+" voice");
   TP->force_me("say The %^RED%^blood%^RESET%^ of both %^BOLD%^%^BLACK%^evil%^RESET%^ and %^BOLD%^good%^RESET%^ falls like %^BLUE%^rain%^RESET%^,");
   TP->force_me("say But when it is over, no %^ORANGE%^dragons%^RESET%^ remain.");
	call_out("verse5",5,TP);
	return 1;
}

int verse5()
{
	TP->force_me("speech sing softly");
   TP->force_me("say Perhaps but a %^BOLD%^dream%^RESET%^, or a vision, and yet,");
   TP->force_me("say Those sharing this %^BOLD%^%^CYAN%^vision%^RESET%^ shall never forget.");
	TP->force_me("emote finishes with a few slow chords.\n");
	"/d/antioch/antioch2/mons/minstrel.c"->call_out("end_song",1,TP);
	return 1;
}
