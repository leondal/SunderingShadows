// ultra-huge Setter Room
// made by Kayla of ShadowGate
// 9/24/94
// colorized by Melnmarn@ShadowGate & Ted Turner
// 03/05/95
// Revamped and updated by TRISTAN

#include <std.h>
#include <daemons.h>
#include <rooms.h>
#define STATS ({"strength","wisdom","intelligence","dexterity","constitution","charisma"})
#include "ansi.h"

#define CLS ESC+"[H"+ESC+"[2J"

inherit ROOM;

void okdone();
void roll();
void upstats();

int receive, rolled;
int doneroll, donedone;
mapping donestats;
string currentstr;
mixed final;
int astr, adex, acon, acha, awis, aint;
int bonus;

void create() {
    ::create();
    rolled = 0;
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_short("The Setting Room");
    set_long(
@KAYLA
%^BOLD%^%^WHITE%^You are standing in a small room with white walls and a tiled
ceramic floor.  On the wall there is a list of instructions that read:
%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  %^CYAN%^Step 1.  %^YELLOW%^Thou shalt <assign> your rolls to statistics.
  %^CYAN%^Step 2.  %^YELLOW%^Thou shalt type <done> when you have assigned all your stats
            and not before.
  %^CYAN%^Step 3.  %^YELLOW%^Thou willst then <pick> thy race.
%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
%^WHITE%^  Shouldst thou need to read these intructions again, thou shalt
  type <look> and thou willt be informed.

  If thou does not like they stats you can now <reroll>

  Please note that you willst be given further instructions and details
  upon the execution of said commands.
KAYLA
);

}

void init(){
   ::init();
    donestats = allocate_mapping(10);
    donestats["strength"] = 0;
     TP->set_stats("strength",0);
    donestats["dexterity"] = 0;
    TP->set_stats("dexterity",0);
    donestats["constitution"] = 0;
    TP->set_stats("constitution",0);
    donestats["charisma"] = 0;
    TP->set_stats("charisma",0);
    donestats["wisdom"] = 0;
    TP->set_stats("wisdom",0);
    donestats["intelligence"] = 0;
    TP->set_stats("intelligence",0);
    add_action("reroll","reroll");
    roll();
}

int reroll() {
    rolled=0;
    doneroll=0;
    donedone=0;
    init();
    astr=0; adex=0; acon=0; acha=0; awis=0; aint=0;
    return 1;
}

int okdone(){
  int fail;

  awis = TP->query_stats("wisdom");
  astr = TP->query_stats("strength");
  adex = TP->query_stats("dexterity");
  aint = TP->query_stats("intelligence");
  acon = TP->query_stats("constitution");
  acha = TP->query_stats("charisma");
  fail = ((!awis) || (!astr) || (!adex) || (!aint) || (!acon) || (!acha));
  if(fail){
    write("%^BOLD%^%^RED%^Thou has not completed assigning your stats!");
    write("%^BOLD%^%^MAGENTA%^Pay attention to the intructions.");
    write("%^BOLD%^%^WHITE%^A lightning bolt hits the floor two feet from you.");
    donedone = 0;
    TP->force_me("look");
    return 1;
  }
  TP->set_stats("exceptional_strength",-1);
  if(!donedone){
    upstats();
    donedone = 1;
    return 1;
  }
  if(donedone == 2) {
    write("Thou hast already typed done!  Proceed to pick thy race!");
    return 1;
  }
  if(!rolled) {
    write("Thou hast not yet <roll>ed thy stats.");
    return 1;
  }
  if(donedone != 2) {
    donedone = 2;
  }
  TP->move(new("/d/shadowgate/race_set"));
}

void already(){
  write("%^YELLOW%^You have already finished the use of that command.");
  write(currentstr);
  return 1;
}


int get_num(string str) {
  int i;

  if(!sscanf(str,"%d",i)) {
    write("I'm sorry, that's not a number!");
    receive = 0;
    return 1;
  }
  if ((i > 0) && (i < 7)) {
    receive = i;
    return 1;
  }
  write("That is not a valid entry!");
  receive = 0;
  return 1;
}

void roll() {
    string *which;
    mapping borg;
    int i, tmp, tot, rollnum;
    mixed rollz;

    TP->new_body();
    if(rolled) {
        write("You can roll your stats no more.");
        return 1;
    }
    rolled = 1;  doneroll = 1;
    rollnum = 1;
    rollz=allocate(5);
    final=allocate(8);
    for(rollnum = 1; rollnum < 7; rollnum++) {
      for (i=1;i<5;i++) {
       rollz[i] = random(6)+1;
      }
      tmp = 1;
      for (i=2; i<5; i++) {
        if(rollz[i] < rollz[tmp]) tmp=i;
      }
      if(tmp == 5) tmp = 1;
      tot = 0;
      for (i=1; i<5; i++) {
        if(i != tmp) tot+=rollz[i];
      }
      final[rollnum] = tot;
    }
    write("%^BOLD%^%^BLUE%^-=-*-=- %^GREEN%^Your rolls %^BLUE%^-=-*-=-");
    for (i=1; i < 7; i++)
      write("%^BOLD%^%^CYAN%^Roll number: %^YELLOW%^"+i+"   %^BLACK%^=    %^RED%^"+final[i]);
    write("%^BOLD%^%^BLUE%^-=-*-=-=-=-=**=-=-=-=-*-=-");
    write("%^BOLD%^Now you can %^BLACK%^<%^CYAN%^assign%^BLACK%^> %^WHITE%^a roll number to a stat.");
    write("For instance '%^BOLD%^assign 2 strength%^RESET%^' will assign roll #2 to strength.");
    write("%^BOLD%^You can type %^BLACK%^<%^CYAN%^show%^BLACK%^> %^WHITE%^at any point to list your rolls.");
    write("%^BOLD%^You can also type %^BLACK%^<%^CYAN%^stats%^BLACK%^> %^WHITE%^to show your current stats.");
    write("%^BOLD%^Note that you can just type %^BLACK%^<%^CYAN%^quick%^BLACK%^> %^WHITE%^to quickly associate them.");
    write(
@PATOR
%^BOLD%^Note that you can %^BLACK%^<%^CYAN%^reroll%^BLACK%^>%^RESET%^%^BOLD%^ if you are not satisfied
with your stats.
Remember that this command will remove your old stats!
PATOR
    );
    write("%^BOLD%^Type %^BLACK%^<%^CYAN%^done%^BLACK%^> %^WHITE%^when you are finished with your stats.");
    currentstr = "%^BOLD%^You must %^BLACK%^<%^CYAN%^assign%^BLACK%^> %^WHITE%^your rolls.  Type %^BLACK%^<%^CYAN%^assign%^BLACK%^> %^WHITE%^for help.";
    add_action("quick","quick");
    add_action("show","show");
    add_action("assign","assign");
    add_action("okdone","done");
    return 1;
}

int quick(string str) {
  if(!donedone) {
    write("%^BOLD%^Thou art lazy... %^RESET%^CYAN%^Your stats are complete.");
    TP->set_stats("strength",final[1]);
    TP->set_stats("dexterity",final[2]);
    TP->set_stats("constitution",final[3]);
    TP->set_stats("intelligence",final[4]);
    TP->set_stats("wisdom",final[5]);
    TP->set_stats("charisma",final[6]);
    final[1] = 0; final[2] = 0; final[3] = 0;
    final[4] = 0; final[5] = 0; final[6] = 0;
    okdone();
    return 1;
  }
  else
  {
    write("%^BOLD%^%^RED%^You are finished with your stats.");
    write(currentstr);
    return 1;
  }

}

int show(string str) {
  int i;
    write("%^BOLD%^%^BLUE%^-=-*-=- %^GREEN%^Your rolls %^BLUE%^-=-*-=-");
    for (i=1; i < 7; i++)
      write("%^BOLD%^%^CYAN%^Roll number: %^YELLOW%^"+i+"   %^BLACK%^=    %^RED%^"+final[i]);
    write("%^BOLD%^%^BLUE%^-=-*-=-=-=-=**=-=-=-=-*-=-");
  return 1;
}

int assign(string str) {
  int i,j,tmp;
  string stt,stat;
	remove_action("quick","quick");
  if (!doneroll) {
    write("Thou must first <roll> your stats!");
    return 1;
  }
  if(donedone) {
    write("%^BOLD%^%^RED%^Thou art done with your stats!");
    write(currentstr);
    return 1;
  }
  if(!str) {
   write("%^BOLD%^Now you can %^BLACK%^<%^CYAN%^assign%^BLACK%^> %^WHITE%^a roll number to a stat.");
    write("For instance '%^BOLD%^assign 2 strength%^RESET%^' will assign roll #2 to strength.");
    write("%^BOLD%^You can type %^BLACK%^<%^CYAN%^show%^BLACK%^> %^WHITE%^at any point to list your rolls.");
    write("%^BOLD%^You can also type %^BLACK%^<%^CYAN%^stats%^BLACK%^> %^WHITE%^to show your current stats.");
    write("%^BOLD%^Note that you can just type %^BLACK%^<%^CYAN%^quick%^BLACK%^> %^WHITE%^to quickly associate them.");
    write("%^BOLD%^Type %^BLACK%^<%^CYAN%^done%^BLACK%^> %^WHITE%^when you are finished with your stats.");
    return 1;
  }
  if(!sscanf(str,"%d %s",i,stt)) {
    write("%^MAGENTA%^Format%^BOLD%^%^BLACK%^: %^WHITE%^assign [roll#] [stat]");
    write("Ex: '%^BOLD%^assign 2 strength%^RESET%^ ' to assign roll 2 to strength.");
    return 1;
  }
  if( (i < 1) || (i > 6) ) {
    write("BOLD%^%^RED%^Invalid roll number.  Enter a number between %^WHITE%^1 %^RED%^and %^WHITE%^6.");
    return 1;
  }
  stat = stt;
  if(stt == "str") stat = "strength";
  if(stt == "int") stat = "intelligence";
  if(stt == "dex") stat = "dexterity";
  if(stt == "con") stat = "constitution";
  if(stt == "cha") stat = "charisma";
  if(stt == "wis") stat = "wisdom";
  if(donestats[stat]) {
    write("%^BOLD%^%^RED%^You've already assigned that stat!");
    return 1;
  }
  if((stat != "strength") && (stat != "dexterity") && (stat != "constitution") &&
    (stat != "intelligence") && (stat != "wisdom") && (stat != "charisma"))  {
    write("%^BOLD%^%^RED%^Invalid stat.");
    return 1;
  }
  if(!final[i]) {
    write("%^BOLD%^%^RED%^That stat is already used.");
    return 1;
  }
  TP->set_stats(stat,final[i]);
  write("%^BOLD%^%^MAGENTA%^"+capitalize(stat)+"%^WHITE%^ set to %^YELLOW%^"+final[i]+".");
  donestats[stat]=1;
  final[i]=0;
  return 1;
}

int add_stat(string str)
{
  int amount;
  string stat;

   if(donedone == 2){ return 0;}
  if(!str) {
    write("%^BOLD%^%^YELLOW%^ Syntax: add # to stat");
    return 1;
  }
  if(sscanf(str,"%d to %s",amount,stat)!= 2){
    write("%^BOLD%^%^YELLOW%^ Syntax: add # to stat");
    return 1;
  }
  if(amount > bonus) {
    write("%^BOLD%^%^RED%^ AHHH no.  Less than "+bonus+".");
    return 1;
  }
  if(member_array(stat, STATS) == -1){
   write("%^BOLD%^%^CYAN%^ please use a the full stat name.");
   return 1;
  }
  if((int)TP->query_stats(stat)+amount > 18 ){
    write("%^RED%^That score will exceed 18. %^WHITE%^ Please reenter.");
    return 1;
  }
  if(amount < 0){
    write("%^GREEN%^Nice try but I thought of this too.");
    return 1;
  }

  TP->set_stats(stat, ((int)TP->query_stats(stat)+amount));
  bonus -= amount;
  if(bonus == 0)
    write("You are finished. Please type %^MAGENTA%^done%^RESET%^ to continue.");
  else
    write("You have "+bonus+" left to add.");
  write("");
  write("");
  write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  write("%^BOLD%^%^MAGENTA%^    Current scores   %^RESET%^");
  write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  write("%^BOLD%^%^BLUE%^ strength     --- "+TP->query_stats("strength"));
  write("%^BOLD%^%^BLUE%^ intelligence --- "+TP->query_stats("intelligence"));
  write("%^BOLD%^%^BLUE%^ dexterity    --- "+TP->query_stats("dexterity"));
  write("%^BOLD%^%^BLUE%^ constitution --- "+TP->query_stats("constitution"));
  write("%^BOLD%^%^BLUE%^ wisdom       --- "+TP->query_stats("wisdom"));
  write("%^BOLD%^%^BLUE%^ charisma     --- "+TP->query_stats("charisma"));

  return 1;
}

void upstats(){
  bonus = roll_dice(1,6);
  write("%^MAGENTA%^NOW thee may adjust thine scores with a bonus we give thee.");
  write("%^BOLD%^%^CYAN%^Your scores may not exceed %^BLUE%^ 18.%^RESET%^");
  write("This will allow you to make changes to your scores to allow ");
  write("for specific classes you may wish to be.");
  write("%^BOLD%^ ex: extra 4:");
  write("%^BOLD%^ add %^RESET%^ 2 to strength");
  write("This will make you strength 2 points higher.");
  write("Type %^BOLD%^done %^RESET%^ when finished");
  write("");
  write("");
  write("%^BOLD%^%^YELLOW%^NOW you are given an extra "+bonus+" to ");
  write("%^BOLD%^%^YELLOW%^add to your scores.%^RESET%^");
  write("");
  write("");
  write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  write("%^BOLD%^%^MAGENTA%^    Current scores   %^RESET%^");
  write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  write("%^BOLD%^%^BLUE%^ strength     --- "+TP->query_stats("strength"));
  write("%^BOLD%^%^BLUE%^ intelligence --- "+TP->query_stats("intelligence"));
  write("%^BOLD%^%^BLUE%^ dexterity    --- "+TP->query_stats("dexterity"));
  write("%^BOLD%^%^BLUE%^ constitution --- "+TP->query_stats("constitution"));
  write("%^BOLD%^%^BLUE%^ wisdom       --- "+TP->query_stats("wisdom"));
  write("%^BOLD%^%^BLUE%^ charisma     --- "+TP->query_stats("charisma"));

  add_action("add_stat","add");
}
