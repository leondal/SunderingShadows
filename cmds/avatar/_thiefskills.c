//_thiefskills.c - Modified by Circe from _skills.c 
//to show any players' skills 9/11/04

#include <std.h>

inherit DAEMON;

void display_skills();
object targ;

int cmd_thiefskills(string str){
	string cl;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

	if(!avatarp(TP)) return notify_fail("You cannot do that.\n");
      if(!str){
         tell_object(TP,"You must specify a player.");
         return 1;
      }
      if(!(targ = find_player(str)) || (targ->query_invis() && wizardp(targ))) {
         tell_object(TP,"No such player found online.");
         return 1;
      }
	if(!targ->is_class("thief") && !targ->is_class("bard") && !targ->is_class("assassin")) 
		return notify_fail("That person doesn't seem to have "+
               "any skills.  Poor wretch.\n");
      if(targ->query_ghost()){
         tell_object(TP,"That person seems to be lifeless at the moment.");
         return 1;
      }
      tell_object(TP,""+targ->QCN+"'s skills are as follows:");
	display_skills();
	return 1;
}


void display_skills() {
	int OL,PP,FRT,MS,HIS,DN,CW,RL;

	PP = targ->query_thief_skill("pick pockets");
	OL = targ->query_thief_skill("open lock");
	FRT = targ->query_thief_skill("find/remove traps");
	MS = targ->query_thief_skill("move silently");
	HIS = targ->query_thief_skill("hide in shadows");
	DN = targ->query_thief_skill("detect noise");
	CW = targ->query_thief_skill("climb walls");
	RL = targ->query_thief_skill("read languages");
	if(targ->is_class("assassin"))
		write("\n%^BOLD%^%^GREEN%^     The Assassin's");
	if(targ->is_class("bard"))
		write("\n%^BOLD%^%^GREEN%^     The Bard's");
	write("\n%^BOLD%^%^GREEN%^     Thieving Skills");
	write("%^BOLD%^%^BLUE%^____________________________\n");
	if(targ->is_class("thief") || targ->is_class("bard"))
		write("%^CYAN%^  Pick pockets%^BOLD%^ ...... : %^YELLOW%^"+PP);
	if(targ->is_class("assassin") || targ->is_class("thief")){
		write("%^CYAN%^  Open locks%^BOLD%^ ........ : %^YELLOW%^"+OL);
		write("%^CYAN%^  Find/Remove traps%^BOLD%^ . : %^YELLOW%^"+FRT);
		write("%^CYAN%^  Move silently%^BOLD%^ ..... : %^YELLOW%^"+MS);
		write("%^CYAN%^  Hide in shadows%^BOLD%^ ... : %^YELLOW%^"+HIS);
	}
	write("%^CYAN%^  Detect noise%^BOLD%^ ...... : %^YELLOW%^"+DN);
	write("%^CYAN%^  Climb walls%^BOLD%^ ....... : %^YELLOW%^"+CW);
	write("%^CYAN%^  Read languages%^BOLD%^ .... : %^YELLOW%^"+RL+"\n");
	write("%^BOLD%^%^BLUE%^____________________________\n");
}
int help(){
   write(
@CIRCE
    Usage: thiefskills <target>
This command will allow immortals to see any player's thief skills.
The player must be online - and alive - at the time.
CIRCE
);
return 1;
}
