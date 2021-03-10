//mage.c ... for the masters

#include <std.h>
inherit "/d/shadowgate/masters/masters.c";

void pick_school();
int school(string str);

string *schools = ({ "abjuration", "conjuration_summoning", "divination", "enchantment_charm","illusion", "invocation_evocation", "necromancy", "alteration" });

void create(){
  ::create();
  set_name("paladin mage");
  set_id(({"arch mage", "mage", "master"}));
  set_short("Arch mage");
  set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of shadowgate and your quest to make a name for you as a 
mage.
OLI
  );
  set_class("mage");
}

void init(){
  ::init();
  //To be adjusted as needed
}


void kit_sub_class(){
  write("There are no sub classes for mages at this time.");
  return 1;
}

void help_file(){
  write("The mage is a creature of mystic abilities.");
  write(
@OLI
  cast -> to cast spells
  other commands must be must be used in conjunction with spellbook
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

  write("%^YELLOW%^School Name");
  write("%^BLUE%^-------------");
  for(inc = 0; inc < sizeof(schools);inc ++)
    write(capitalize(schools[inc]));
  write("%^BOLD%^Please pick your School of Magic");
  write("%^BOLD%^%^RED%^For more information about the schools, see "+
     "<help schools>.%^RESET%^");
  add_action("school","pick");
  return 1;
}
  
int school(string str){
  object ob, ob2;
  int i;
    
  if(!str) {
    write("You must pick a school!");
    return 1;
  }
  str = lower_case(str);
  if(member_array(str,schools) == -1){
    write("%^RED%^Sorry, that is not a school in this reality.");
    write("%^RESET%^%^BOLD%^Please pick a school from the list:");
    return 1;
  }
  TP->set_school(str);
  ::init();
  TP->set_school(str);
  TP->add_mp(TP->query_max_mp());
  write("%^CYAN%^Ok, Thou hast chosen to study "+capitalize(TP->query_school())+".");
  write("The master gives thee a bag and a large book.");
  ob = new("/d/magic/magic_book");
  ob->move(TP);	
  ob->set_spellbook("magic missile");
  ob2 = new("/d/magic/comp_bag");
  ob2->move(TP);
  write("The master also gives you a sack filled with scrolls.");
  write("You know that these scrolls won't backfire.");
  ob = new("/d/common/obj/misc/sack");
  for(i=0;i<15;i++){
      ob2 = new("/d/magic/safe_scroll");
      ob2->move(ob);
  }
  ob->move(TP);
  write("You may enter the world of Shadowgate now...");
  write("Much of thy life is set...but you must always seek");
  write("what you want.");
  write("%^BOLD%^Seek out adventure. Allow the world to benefit ");
  write("%^BOLD%^ you, but never allow it to hurt you.");
  pick_diety();
  return 1;
}
