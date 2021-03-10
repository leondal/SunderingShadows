//adapted from mage.c by ~Circe~ for psions 7/16/05

#include <std.h>
inherit "/d/shadowgate/masters/masters.c";

void pick_school();
int school(string str);

string *schools = ({ "egoist","kineticist","nomad","seer","shaper","telepath" });

void create(){
  ::create();
  set_name("paladin psion");
  set_id(({"arch psion", "psion", "master"}));
  set_short("Arch psion");
  set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of Shadowgate and your quest to make a name for you as a 
psion.
OLI
  );
  set_class("psion");
}

void init(){
  ::init();
  //To be adjusted as needed
}


void kit_sub_class(){
  write("There are no sub classes for psions at this time.");
  return 1;
}

void help_file(){
  write("The psion is a creature of intrinsic powers and intellectual abilities.");
  write(
@OLI
  manifest -> to manifest powers
  other commands must be must be used in conjunction with a psicrystal
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
  int inc;

  write("%^YELLOW%^Discipline Name");
  write("%^BLUE%^-------------");
  for(inc = 0; inc < sizeof(schools);inc ++)
    write(capitalize(schools[inc]));
  write("%^BOLD%^Please pick your psionic discipline");
  write("%^BOLD%^%^RED%^For more information about the disciplines, see "+
     "<help disciplines>.%^RESET%^");
  add_action("school","pick");
  return 1;
}
  
int school(string str){
  object ob, ob2;
  int i;
    
  if(!str) {
    write("You must pick a discipline!");
    return 1;
  }
  str = lower_case(str);
  if(member_array(str,schools) == -1){
    write("%^RED%^Sorry, that is not a discipline in this reality.");
    write("%^RESET%^%^BOLD%^Please pick a discipline from the list:");
    return 1;
  }
  TP->set_discipline(str);
  ::init();
  TP->set_discipline(str);
  TP->add_mp(TP->query_max_mp());
  write("%^CYAN%^Ok, Thou hast chosen to become a "+capitalize(TP->query_discipline())+".");
  write("The master gives thee a psicrystal and a small pouch.");
  ob = new("/d/magic/psicrystal");
  ob->move(TP);	
  ob2 = new("/d/magic/psi_comp_bag");
  ob2->move(TP);
  write("You may enter the world of Shadowgate now...");
  write("Much of thy life is set...but you must always seek");
  write("what you want.");
  write("%^BOLD%^Seek out adventure. Allow the world to benefit ");
  write("%^BOLD%^ you, but never allow it to hurt you.");
  pick_diety();
  return 1;
}
