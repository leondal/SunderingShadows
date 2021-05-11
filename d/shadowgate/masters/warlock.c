//adapted from psion.c by N for warlocks 12/15

#include <std.h>
inherit "/d/shadowgate/masters/masters.c";

void pick_school();
int school(string str);

string *heritages;

void create(){
  ::create();
  set_name("warlock");
  set_id(({"high warlock", "warlock", "master"}));
  set_short("High warlock");
  set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
her job is simple now.... she is to make you ready for the 
world of Shadowgate and your quest to make a name for you as a 
warlock.
OLI
  );
  set_class("warlock");
}

void init(){
  ::init();
  //To be adjusted as needed
}


void kit_sub_class(){
  write("There are no sub classes for warlocks at this time.");
  return 1;
}

void help_file(){
  write("The warlock is a being of instinctive power, channeled by their pact with a being from beyond.");
  write(
@OLI
  cast -> to invoke a spell-like ability
OLI
);
  return 1;
}

void done(){
   object ob, ob2;

  pick_school();
  return 1;
}

void pick_school(){
  int i, align;
// these are reliant on alignment, and must be within one step of base align
// CG: celestial; CN: fey; CE: abyssal; NE: gloom; LE: infernal; TN: astral.

  write("%^YELLOW%^Warlock Heritage");
  write("%^BLUE%^-------------");
  align = TP->query_alignment();
  switch(align) {
    case 7: heritages = (({ "celestial", "fey" })); break;
    case 8: heritages = (({ "celestial", "fey", "abyssal", "astral" })); break;
    case 9: heritages = (({ "fey", "abyssal", "gloom" })); break;
    case 5: heritages = (({ "astral", "gloom", "fey" })); break;
    case 6: heritages = (({ "abyssal", "gloom", "infernal", "astral" })); break;
    case 3: heritages = (({ "gloom", "infernal" })); break;
    default: tell_object(TP,"You have an alignment that does not work for a warlock! Please contact a wiz or reroll."); return; break;
  }
  for(i = 0; i < sizeof(heritages);i ++)
    write(capitalize(heritages[i]));
  write("%^BOLD%^Please select your character's heritage.");
  write("%^BOLD%^%^RED%^For more information about the warlock heritages, see "+
     "<help warlock heritages>.%^RESET%^");
  add_action("school","pick");
  return 1;
}
  
int school(string str){
  int i;
    
  if(!str) {
    write("You must pick a heritage!");
    return 1;
  }
  str = lower_case(str);
  if(member_array(str,heritages) == -1){
    write("%^RED%^Sorry, that is not a warlock heritage that you can choose.");
    write("%^RESET%^%^BOLD%^Please pick a heritage from the list:");
    for(i = 0; i < sizeof(heritages);i ++) write(capitalize(heritages[i]));
    return 1;
  }
  TP->set("warlock heritage",str);
  ::init();
  TP->set("warlock heritage",str);
  TP->add_mp(TP->query_max_mp());
  write("%^CYAN%^Ok, Thou hast chosen your heritage to be "+capitalize(str)+".");
  write("You may enter the world of Shadowgate now...");
  write("Much of thy life is set...but you must always seek");
  write("what you want.");
  write("%^BOLD%^Seek out adventure. Allow the world to benefit ");
  write("%^BOLD%^ you, but never allow it to hurt you.");
  pick_diety();
  return 1;
}

