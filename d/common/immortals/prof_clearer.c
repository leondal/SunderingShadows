// coded by Lujke for Cythera

#include <std.h>
inherit OBJECT;

create(){
  ::create();
  set_name("prof clearer");
  set_id(({"clearer","prof clearer", "device" }));
  set_short("a strange device called a prof clearer");
  set_long("This odd little device was designed to help wizzes remove"
         +" profs from players. It has some instructions written on it."); 
  set_weight(8);
  set_value(0);
  set_read("%^YELLOW%^ How to use -\n%^YELLOW%^<clearprof [username] prof>\n\n"+
  " Example - clearprof franklin piano - this would remove the prof piano "
	"from franklin.\n  Once this is done, you may need to use <fixprofs>.");
}


void init(){
  ::init();
  add_action("clear_prof", "clearprof"); 
}

int clear_prof(string str){
//  clears the named player's prof and skill settings in the named prof
//  should also return any profs previously applied to the named prof to
// their stock of unused profs
// In this file, 'skill refers to the player's skill with a weapon type, 
// while prof refers to the number of profs applied in it. So, a character
// with 100(2) in medium blades would be said to have a skill of 100 and
// a prof of 2 in medium blades.

  object pc;
  mapping skilllist, proflist;
  string profname, charname, * skillnames, skillname;
  int i, j, prof, skill;
  if (!objectp(ETO)){return 0;}
// initialise the mappings and arrays used
  skilllist = ([]);
  proflist = ([]);
  skillnames = ({});

//separate the two parts of the string to be used

  sscanf(str, "%s %s", charname, profname);
  tell_object(ETO, "Trying to remove the " + profname + " prof from "
                  + charname);
  pc = find_player(charname);
  if (!objectp(pc)){return 1;}

//set skilllist to a mapping of the skillnames(strings):skilllevels (ints)
  skilllist = pc->query_skills();
  if (sizeof(skilllist)<1){
    tell_object(ETO, charname + " does not appear to have any skills!");
    return 1;
  }

// set skillnames to an array of the names of the weapon types the player 
// has some skills or profs in
  skillnames = keys(skilllist);

// cycle through the list of skillnames and record the player's current
// prof in each one in the proflist mapping

  for (i=0;i<sizeof(skillnames);i++){
    skillname = skillnames[i];
    proflist[skillname]=pc->query_profs(skillname);
    tell_object(ETO, "Current skill in " + skillname + " is " 
    + proflist[skillname]);
  }
// reset the player's profs
  pc->reset_profs();


// re-apply all profs, except the one you are removing
  for (i=0;i<sizeof(skillnames);i++){
    // check to make sure the next prof on the list is not the one you are
    // removing
    skillname = skillnames[i];
    if (skillname!=profname){
      // then re-apply the correct number of profs. Used a loop because I
      // couldn't find a way to apply more than one prof at a time
      prof = proflist[skillname];
      if (prof>0){
        tell_object(ETO, "Reapplying " + prof + " proficiencies to " 
                        + skillname + ".");
        for (j=0;j<prof;j++){
          pc->use_prof(skillname);
        }
      }
    }
  }
//Finally, delete the skill for the proftype you are removing
  tell_object(ETO, "\nDeleting skill for " + profname + ".");
  pc->delete_skill(profname);  
  tell_object(ETO, "Process finished. Prof removed");
  return 1;
}