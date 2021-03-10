#include <std.h>
inherit DAEMON;

//Crying Skies

int cmd_cryingsky(string str)
{
	TP->force_me("speech say quietly");
	TP->force_me("say The %^BOLD%^%^CYAN%^sky%^RESET%^ is %^BOLD%^%^BLUE%^crying%^RESET%^\n"+
   "\t\t  for my broken %^RED%^heart%^RESET%^.");
	TP->force_me("say The %^BLUE%^tears%^RESET%^ are falling\n"+
   "\t\t  as we are forced to part.");
	TP->force_me("say The %^YELLOW%^flowers%^RESET%^ on the window sill\n"+
   "\t\t  I gave you yesterday.");
	TP->force_me("say I can feel your warm %^BOLD%^breath%^RESET%^ still,\n"+
   "\t\t  hear your %^BOLD%^%^RED%^heart%^RESET%^ beating away.");
	call_out("verse1",8,TP);
	return 1;
}

int verse1()
{
	TP->force_me("speech whisper softly");
	TP->force_me("say Yet I stare unbelieving\n"+
   "\t\t     into your unseeing %^CYAN%^eyes%^RESET%^;");
	TP->force_me("say Reality must be deceiving,\n"+
   "\t\t     we didn't even say goodbyes.");
	TP->force_me("emote bows "+TP->query_possessive()+" head solemnly.\n");
	call_out("verse2",8,TP);
	return 1;
}

int verse2()
{
	TP->force_me("speech say sadly");
	TP->force_me("say The bagpipes are playing\n"+
   "\t\tas dirt's shoveled on your %^GREEN%^grave%^RESET%^,");
	TP->force_me("say I hear what no one's saying,\n"+
   "\t\tholding the memories I've saved.");
	call_out("verse3",7,TP);
	return 1;
}

int verse3()
{
	TP->force_me("speech say with feeling");
	TP->force_me("say Your smile, so lovely,\n"+
   "\t\t       your touch, so soft,");
	TP->force_me("say Now I'm so %^BOLD%^%^BLUE%^lonely%^RESET%^,\n"+
   "\t\t       so broken and %^BLUE%^lost%^RESET%^.");
	TP->force_me("emote wipes a few stray tears away.\n");
	call_out("verse4",8,TP);
	return 1;
}

int verse4()
{
	TP->force_me("speech say with sorrow");
	TP->force_me("say The %^BOLD%^%^CYAN%^sky%^RESET%^ is still %^BOLD%^%^BLUE%^crying%^RESET%^\n"+
   "\t\t      for my broken %^RED%^heart%^RESET%^,");
	TP->force_me("say The %^BLUE%^tears%^RESET%^ drip-drop falling,\n"+
   "\t\t      slowly %^CYAN%^tearing%^RESET%^ me apart.");
	TP->force_me("emote swallows the fresh tears and pain of memory as "+TP->query_subjective()+" struggles through the last lines.\n");
	"/d/antioch/antioch2/mons/minstrel.c"->call_out("end_song",1,TP);
	return 1;
}
