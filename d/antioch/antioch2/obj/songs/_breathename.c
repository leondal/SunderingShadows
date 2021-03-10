#include <std.h>
inherit DAEMON;

//Oh, Breathe Not His Name

int cmd_breathename(string str)
{
	TP->force_me("speech begin in a soft whisper");
	TP->force_me("say %^BOLD%^Oh, breathe not %^RESET%^his%^BOLD%^ name,");
	TP->force_me("say %^BOLD%^Let it sleep in the %^RESET%^%^BLUE%^shade,");
	TP->force_me("say %^BOLD%^Where %^BLUE%^cold%^WHITE%^ and %^RESET%^unhonored,");
	TP->force_me("say His%^BOLD%^ relics are laid.");
	TP->force_me("emote crosses "+TP->query_possessive()+" arms and shivers.\n");
	call_out("verse2",9,TP);
	return 1;
}

int verse2()
{
	TP->force_me("speech speak softly");
	TP->force_me("say %^BOLD%^%^BLUE%^Sad, %^RESET%^%^BLUE%^silent %^RESET%^and %^BOLD%^%^BLACK%^dark");
	TP->force_me("say %^BOLD%^Be the %^CYAN%^tears%^WHITE%^ that we shed,");
	TP->force_me("say %^BOLD%^As %^BLACK%^night%^WHITE%^ dew that %^BLUE%^weeps");
	TP->force_me("say %^BOLD%^On the %^RESET%^%^GREEN%^grave%^BOLD%^%^WHITE%^ o'er his head.\n");
	tell_room(ETP,"%^BOLD%^%^CYAN%^A tear slides down "+TP->query_cap_name()+"'s cheek.\n",TP);
	tell_object(TP,"%^BOLD%^%^CYAN%^A tear slides down your cheek.\n");
	call_out("verse3",9,TP);
	return 1;
}

int verse3()
{
	TP->force_me("speech say in a soft voice");
	TP->force_me("say %^BOLD%^But the %^BLACK%^night%^RESET%^ dew that falls,");
	TP->force_me("say %^BOLD%^Tho' in %^RESET%^%^BLUE%^silence%^BOLD%^%^WHITE%^ it %^BLUE%^weeps,");
	TP->force_me("say %^BOLD%^Shall %^YELLOW%^brighten%^WHITE%^ with vendure");
	TP->force_me("say %^BOLD%^The %^RESET%^%^GREEN%^grave%^BOLD%^%^WHITE%^ where %^RESET%^he%^BOLD%^ sleeps.\n");
	tell_room(ETP,"%^CYAN%^A chill breeze blows through the room.\n");
	call_out("verse4",7,TP);
	return 1;
}

int verse4()
{
	TP->force_me("speech speak with gentle confidence");
	TP->force_me("say %^BOLD%^And the %^CYAN%^tears%^WHITE%^ that we shed,");
	TP->force_me("say %^BOLD%^Tho' in %^RESET%^%^CYAN%^secret%^BOLD%^%^WHITE%^ it rolls,");
	call_out("verse5",3,TP);
	return 1;
}

int verse5()
{
	TP->force_me("emote raises "+TP->query_possessive()+" head and meets your gaze.");
	TP->force_me("say %^BOLD%^Shall long keep %^RESET%^his%^BOLD%^ memory");
	TP->force_me("say %^BOLD%^%^GREEN%^Green%^WHITE%^ in our souls.");
	call_out("verse6",2,TP);
	return 1;
}

int verse6()
{
	tell_room(ETP,"%^BOLD%^%^CYAN%^Another tear slides down "+TP->query_cap_name()+"'s cheek.\n",TP);
	tell_object(TP,"%^BOLD%^%^CYAN%^Another tear slides down your cheek.\n");
	TP->force_me("emote bows slowly.");
	TP->force_me("end");
	return 1;
}
