//altered by Circe for the new flash styles 5/13/04
//fighter.c ... for the masters

#include <std.h>
inherit "/d/shadowgate/masters/masters.c";

void pick_style();
int style(string str);

string *styles = ({ "peasant","swashbuckler","thug","soldier","dervish" });

void create(){
  ::create();
  set_name("fighter master");
  set_id(({"fighting master", "fighter", "master"}));
  set_short("Master Fighter");
  set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of shadowgate and your quest to make a name for you as a 
fighter.
OLI
  );
  set_class("fighter");
}

void init(){
  ::init();
  //To be adjusted as needed
}


void kit_sub_class(){
  write("There are no sub classes for fighters at this time.");
  return 1;
}

void help_file(){
  write("The fighter is a class of warriors");
  write(
@OLI
  parry -> This will allow you to enter into a defensive mode
  rescue -> This will allow you to intercept hits from monsters 
            attacking a friend
  flash -> this is along the lines of wrestling
OLI
  );
  return 1;
}

void done(){
   object ob, ob2;

  pick_style();
  return 1;
}

void pick_style(){
  int inc;

  write("%^YELLOW%^Style Type");
  write("%^BLUE%^-------------");
  for(inc = 0; inc < sizeof(styles);inc ++)
    write(capitalize(styles[inc]));
  write("%^BOLD%^Please pick your Style of Fighting:");
  add_action("style","pick");
  return 1;
}
  
int style(string str){
  object ob, ob2;
  int i;
    
  if(!str) {
    write("You must pick a style!");
    return 1;
  }
  str = lower_case(str);
  if(member_array(str,styles) == -1){
    write("%^RED%^Sorry, that is not a style you can choose.");
    write("%^RESET%^%^BOLD%^Please pick a style from the list:");
    return 1;
  }
  TP->set_fighter_style(str);
  ::init();
  TP->set_fighter_style(str);
  write("%^BOLD%^%^BLUE%^You learned the ways of fighting within the "+capitalize(TP->query_fighter_style())+" style.");
  write("You may enter the world of Shadowgate now...");
  write("Much of thy life is set...but you must always seek");
  write("what you want.");
  write("%^BOLD%^Seek out adventure. Allow the world to benefit ");
  write("%^BOLD%^ you, but never allow it to hurt you.");
  pick_diety();
  return 1;
}
