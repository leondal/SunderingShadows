#include <std.h>
inherit DAEMON;

//Enraptured I Gaze

int cmd_enraptured(string str)
{
	TP->force_me("speech sing in a soft alto");
	TP->force_me("say Enraptured I gaze, when my Delia is by,");
	TP->force_me("say And drink the sweet %^BOLD%^%^GREEN%^poison%^RESET%^ of %^BOLD%^%^RED%^love%^RESET%^ from her eye;");
	TP->force_me("say I feel the soft %^RED%^passion%^RESET%^ pervade ev'ry part,");
	TP->force_me("say And pleasures unusual play round my fond %^BOLD%^%^RED%^heart%^RESET%^.");
	TP->force_me("emote puts "+TP->query_possessive()+" hand over "+TP->query_possessive()+" heart and sighs.\n");
	call_out("verse1",10,TP);
	return 1;
}

int verse1()
{
	TP->force_me("speech sing dazedly");
	TP->force_me("say I hear her %^BOLD%^%^MAGENTA%^sweet%^RESET%^ voice, and am charm'd with her song,");
	TP->force_me("say I think I could hear her %^BOLD%^%^MAGENTA%^sweet%^RESET%^ voice all day long;");
	TP->force_me("say My senses %^CYAN%^enchanted%^RESET%^ are lost in %^YELLOW%^delight");
	TP->force_me("say When %^BOLD%^%^RED%^love%^RESET%^ and soft music their rapture unite.");
	tell_room(ETP,"%^BOLD%^A few bars of a gentle melody echo through the room.\n");
	call_out("verse2",10,TP);
	return 1;
}

int verse2()
{
	TP->force_me("speech sing with conviction");
	TP->force_me("say Beyond all expression my Delia I %^BOLD%^%^RED%^love%^RESET%^;");
	TP->force_me("say My %^BOLD%^%^RED%^heart%^RESET%^ is so fix'd that it never can rove;");
	TP->force_me("say When I see her I think 'tis an %^BOLD%^angel%^RESET%^ I see,");
	TP->force_me("say And the charms of her mind are a %^YELLOW%^heav'n%^RESET%^ to me.");
	TP->force_me("emote sighs softly and rests "+TP->query_possessive()+" head on "+TP->query_possessive()+" chin as "+TP->query_subjective()+" finishes the song.\n");
	TP->force_me("end");
	return 1;
}
