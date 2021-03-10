//masters.c inheritable for the master's of the classes
//to contain common needs for the masters
//slight alterations so it'll pick up ranger deities. Nienne, 02/07
//Added in line to make layperson alignment mod for deities - Octothorpe 4/4/10
//Updated non-HM cap to level 30 - Octothorpe 4/17/10

#include <std.h>
#include <daemons.h>
#include <psions.h>
#include <dirs.h>
#include <dieties.h>
#define TS_D "/daemon/treesave_d.c"
#define CMD_NOTE "/cmds/avatar/_note.c"
//#define ROOM_START "/d/shadowgate/adv_main"
#define ROOM_START "/d/newbie/ooc/hub_room"

inherit MONSTER;
void finish();
void pick_diety();

string *names, *allowed;
void player_made();
void help_file();

void init(){
    ::init();
    write("Thou shall now be allowed to specialize.");
    write("This will allow thee to center more on certain abilities.");
    write("To find out more about the special abilities that may be granted");
    write("to thee type <%^BOLD%^specialize%^RESET%^>.");
    write("If thou is satisfied with thyself type <%^BOLD%^done%^RESET%^> to live in this world.");
    write("If thou wishes information on chosen class type <%^BOLD%^help%^RESET%^>");
    add_action("kit_sub_class","specialize");
    add_action("help_me","help");
    add_action("done","done");
}

void pick_diety(){
  int inc,align,myrace,mysubrace;
  string myfile,*badgods;
  write("%^GREEN%^%^BOLD%^ Thou dost now choose the light to follow...");
  write("%^BOLD%^%^GREEN%^ Choose the god that thou shall follow.");
  write("%^BOLD%^%^RED%^ May thou receive mercy.");
  allowed = ({});
  align = TP->query_alignment();
  myrace = (string)TP->query_race();
  mysubrace = (string)TP->query("subrace");
  if(TP->is_class("cavalier") || TP->is_class("paladin")) { names = keys(KNIGHTALIGN); }
  else {
      if(TP->is_class("ranger")) { names = keys(RANGERALIGN); }
      else if(TP->is_class("druid")) { names = DRUIDS; }
      else names = keys(DIETIES);
  }
// doing a bit of a rewrite to pick up racial deity restrictions! N, 3/16.
/*  if(TP->is_class("ranger") || TP->is_class("cleric") || TP->is_class("cavalier") || TP->is_class("paladin")){
    for(inc = 0; inc < sizeof(names);inc ++){
      if(member_array(align,DIETIES[names[inc]][2])!=-1) allowed += ({names[inc]});
    }
  }
  else{
    for(inc = 0; inc < sizeof(names);inc ++){
      if(member_array(align,DIETIES[names[inc]][1])!=-1) allowed += ({names[inc]});
    }
  }*/

  myfile = DIR_RACES+"/"+myrace+".c";
  badgods = ({});
  if(file_exists(myfile)) badgods += (string *)myfile->restricted_deities(mysubrace);

  if(TP->is_class("ranger") || TP->is_class("cleric") || TP->is_class("cavalier") || TP->is_class("paladin") || TP->is_class("druid")){ // threw druids in with clergy. N, 3/16
    for(inc = 0; inc < sizeof(names);inc ++){
      if(member_array(align,DIETIES[names[inc]][2]) == -1) continue;
      if(member_array(names[inc],badgods) != -1) continue;
      allowed += ({names[inc]});
    }
  }
  else{
    for(inc = 0; inc < sizeof(names);inc ++){
      if(member_array(align,DIETIES[names[inc]][1]) == -1) continue;
      if(member_array(names[inc],badgods) != -1) continue;
      allowed += ({names[inc]});
    }
  }
  
  write("%^YELLOW%^Diety Name         Sphere of Control");
  write("%^BLUE%^------------         -------------------");
  for(inc = 0; inc < sizeof(allowed);inc ++)
    write(sprintf("%%^CYAN%%^%-20s %%^GREEN%%^%s",capitalize(allowed[inc]),capitalize(DIETIES[allowed[inc]][0])));
  write("%^BOLD%^Please choose thine diety:");
  add_action("diety","pick");
  return 1;
}

int diety(string str)
{
  object ob;

  if(!str) {
    write("Thou dost choose a diety!");
    return 1;
  }
  str = lower_case(str);
  if(member_array(str,allowed) == -1){
    write("%^RED%^Sorry, you are not able to follow "+capitalize(str)+".");
    write("%^RESET%^%^BOLD%^Try Again:");
    return 1;
  }
  write("%^CYAN%^Ok, Thou hast chosen to follow "+capitalize(str)+".");
  write("%^CYAN%^Your sphere of influence is "+capitalize(DIETIES[str][0])+".");
  TP->set_diety(str);
  write("Suddenly, a holy symbol appears in your hand.");
  //if(TP->is_class("cleric")) {
    ob = new("/d/magic/symbols/holy_symbol.c");
    ob->set_short("The holy symbol of "+capitalize(str));
    ob->set_sphere(DIETIES[str][0]);
    ob->move(TP);
    ob->save(TPQN);
  //}
  TP->set_sphere(DIETIES[str][0]);
  TP->set("god changed",1);
  TP->add_mp(TP->query_max_mp()); 
  write("You may enter the world of Shadowgate now...");
  write("Much of thy life is set...but you must always seek");
  write("what you want.");
  write("%^BOLD%^Seek out adventure. Allow the world to benefit ");
  write("%^BOLD%^   you, but never allow it to hurt you.");      
  finish();
  return 1;
}

void finish(){
  int i,j, newmax;
  string *classes,temp;
  string myclass;
  object newroom;

  classes = TP->query_classes();
  i = sizeof(classes);
// Adding automatic non-AP caps for players.
//Updated to level 30 non-HM cap - Octothorpe 4/17/10
  if(i == 1) {
    if(TP->is_class("bard")) TP->set("no advance",30);
    else TP->set("no advance",30);
  }
  else TP->set("no advance",30);
  temp = CMD_NOTE->format_checkpoint((string)TP->query_name(),"%^ORANGE%^Standard non-AP level cap: "+TP->query("no advance")+".%^RESET%^");
  TS_D->add_value_to_array("notes",TP->query_name(),capitalize(TP->query_name()) + ", " + ctime(time()) + " - "+ temp);
  TP->set("new_hp_rolled_two",1);
  TP->set("no pk",1);
  TP->set("new_hm_cap_set",1);
  write("\nMatter folds around you and forms your living self.\n");
  write("You are suddenly transported to a new world.\n");
//  TP->move_player(ROOM_START); - to give a new version for each character so they are uninterrupted
  newroom = new(ROOM_START);
  TP->move_player(newroom);
  TP->add_exp(i);
  for(j=0;j<i;j++){
    TP->set_mlevel(classes[j],0);
    ADVANCE_D->advance(TP,classes[j]);
  }
  TP->setenv("TITLE",ADVANCE_D->get_new_title(TP));
    TP->init_skills("blah");
  TP->setenv("LINES","20");
  TP->add_quenched(50);
  TP->add_stuffed(500);
  TP->add_hp(TP->query_max_hp());
  TP->add_hp(TP->query_max_hp());
  for(j=0;j<i;j++){
    "/d/shadowgate/class_news"->class_news(classes[j],TPQCN+" has joined your ranks.");
   NWP_D->advance_player(TP,classes[j],1);
    }
  TP->update_channels();
  TP->new_body();
  if(TP->query("new_class_type")) catch("/cmds/mortal/_advance.c"->add_class_feats(TP,TP->query_class()));
   TP->set("align ok",1);
  for(j=0;j<i;j++)
    TP->add_search_path("/cmds/"+classes[j]);
  if(TP->is_class("psywarrior")){ //add psions eventually
     newmax = PWPOINTS[0];
     TP->set_max_mp(newmax);
     tell_object(TP,"%^BOLD%^%^GREEN%^As a level 1 psywarrior, you have "
        ""+newmax+" power point(s). You must <prepare psywarrior points (times X)> "
        "to prepare your points for use.%^RESET%^");
  }
//This message is mostly for debugging/information. Can remove later. Also remember to adjust here if we give bonus points for intelligence.

  TP->force_me("save");
  environment(TO)->remove();
//  TP->force_me("save");
// Lines below here are not run because of the implied remove in the masters.
  return 1;
}

void create(){
  ::create();
  set_hd(15,1);
  set_stats("strength",25);
  set_stats("intelligence",25);
  set_stats("wisdom",25);
  set_stats("dexterity",25);
  set_stats("constitution",25);
  set_stats("charisma",25);
  set_body_type("humanoid");
   set_property("no attack",1);
  set_wielding_limbs(({"right hand","left hand"}));
  set("race","immortal helper of the newly born");
}

int is_invincible(){ return 1;}


int help_me(string str){
    if(!str) return help_file();
      return 0;
}

