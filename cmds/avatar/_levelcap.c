#include <std.h>
#include <objects.h>

#define TS_D "/daemon/treesave_d.c"
#define CMD_NOTE "/cmds/avatar/_note.c"
inherit DAEMON;

int cmd_levelcap(string str){

    string who,temp;
    int level;
    object ob;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if (!str || str == "") return notify_fail("Levelcap <player> || levelcap <player> <level>\n");

    if (sscanf(str,"%s %d",who, level) != 2) {
        if (sscanf(str, "%s",who) != 1) return notify_fail("levelcap <player> || levelcap <player> <level>\n");
        level = -1;
    }
    if (!ob = find_player(who)) return notify_fail("Failed to find player "+who+"\n");
    if (level == -1) 
	{
		if(!OB_ACCOUNT->is_high_mortal(ob->query_true_name())) 
		{
        	write("%^BOLD%^"+capitalize(who)+" is currently level capped at "+ob->query("no advance")+".");
		}
		else
		{
			write("%^BOLD%^"+capitalize(who)+" has a high mortal on "+ob->QP+" and is not levelcapped.");
		}
        return 1;
    }
    ob->set("no advance",level);
    temp = CMD_NOTE->format_checkpoint(who,"%^ORANGE%^Level capped at " + level +".%^RESET%^");
    TS_D->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - "+ temp);
    write("%^BOLD%^"+capitalize(who)+" is now level capped at "+level+".");
    return 1;
}

int help(){
    write(
@OLI
levelcap <player> || levelcap <player> <level>

This will prevent a player from gaining any exp when at or above the level indicated. Without the level it will return the current level cap for a player. 0 or -1 indicates no level cap.
OLI
"%^BOLD%^%^RED%^Current guidelines (updated Oct. 2015)%^RESET%^\n"
"   First of all, be sure to talk to the player and let them know there is an issue when you are concerned, whether you actually cap them or not.  Be sure to make a note (ckpt) about the discussion.\n"
"%^BOLD%^ABSOLUTE CAPS are addressed in <help levelcaps>\n"
"   The new PLing guideline is to allow adventuring up to 50% of their playtime.  We want to encourage adventuring but _without_ ooc info. abuse or cycling just to level.  Those who actively engage others in RP at every opportunity and take appropriate risks should be fine.\n\n"
"%^GREEN%^1 Play Days = Level 10\n"
"%^GREEN%^2 Play Days = Level 14\n"
"%^GREEN%^3 Play Days = Level 17\n"
"%^GREEN%^4 Play Days = Level 20\n"
"%^GREEN%^5 Play Days = Level 22\n"
"%^GREEN%^6 Play Days = Level 24\n"
"%^GREEN%^7 Play Days = Level 26\n"
"%^GREEN%^8 Play Days = Level 28\n"
"%^GREEN%^9 Play Days = Level 29\n"
"%^GREEN%^10 Play Days = Level 30\n"
"%^GREEN%^11 Play Days = Level 31 (HM/HM alt)\n"
"%^GREEN%^12 Play Days = Level 32 (HM/HM alt)\n"
"%^GREEN%^13 Play Days = Level 33 (HM/HM alt)\n"
"%^GREEN%^14 Play Days = Level 34 (HM/HM alt)\n"
"%^GREEN%^15 Play Days = Level 35 (HM/HM alt)\n"
"%^GREEN%^16 Play Days = Level 36 (HM/HM alt)\n"
"%^GREEN%^17 Play Days = Level 37 (HM/HM alt)\n"
"%^GREEN%^18 Play Days = Level 38 (HM/HM alt)\n"
"%^GREEN%^19 Play Days = Level 39 (HM/HM alt)\n"
"%^GREEN%^20 Play Days = Level 40 (HM/HM alt)\n"

"%^RESET%^\n   Early danger sign - more than one class level/hr. for lowbies, remind them about the rules re: abuse of ooc info. and the expectation of RP, that it's not a video game, etc.\n"
"   %^YELLOW%^Characters who display consistently poor/unacceptable RP should be capped until their RP'ing improves.  Immortals who cap characters for poor RP _MUST_ work with them (and make notes accordingly about their recommendations) to improve their roleplaying.  %^RESET%^If you can't spend some time to work with them, don't cap them for poor RP'ing.  However, capping for PL'ing is acceptable at any time.\n\n"
"    See also:  levelcaps (mortals view)"
);
    return 1;
}

/************* removed 11/06
"   Mids - 1 mil exp./day online time total (mostly applicable to high mids) is excessive and warrants a cap.  Hopefully they've been warned before they get to that point.\n"
"   Gaining 1 mil exp/day is generally considered PLing but obviously depends on class/levels.  "
"However, regaining lost levels if their total exp./day is reasonable or they are a higher level char. with a lot of online time otherwise (esp. if they complete a quest in that time, etc.) as long as they aren't solely cycling is likely to be fine, esp. if it's the exception to their normal pattern."
--------------
removed 02/08
As a rough guide, levels 6-11 should take at least 1 day, 12-17 should take 2 (more), 18-23 should take 3 (total of 6 since leaving Offestry), and 23-30 should take 4 days (now we're at 10+).
********************/
