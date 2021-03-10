// ultra-huge Setter Room
// made by Kayla of ShadowGate
// 9/24/94

#include <std.h>
#include <daemons.h>
#include <rooms.h>

inherit ROOM;

void okdone();
void roll();

int receive, rolled;
int doneroll, donechoose, donepick, doneassign, donedone;
mapping donestats;
string currentstr;
mixed final;
int dok, eok, gok, heok, hok;
int fiok, paok, raok, maok, clok, drok, thok, baok, ilok;
int fithok, ficlok, fimaok, mathok, fimathok, fiilok, ilthok, fithok;
int astr, adex, acon, acha, awis, aint;


void create() {
    ::create();
    rolled = 0;
    set_property("light",2);
    set_property("indoors",1);
    set_short("The Setting Room");
    set_long(
@KAYLA
You are standing in a small room with white walls and a tiled
ceramic floor.  On the wall there is a list of instructions
that read:
  Step 1.)  Then thou shalt <assign> your rolls to statistics.
  Step 2.)  Thou shalt type <done> when you have assigned all your stats
            and not before.
  Step 3.)  Thou willst then <pick> thy race.
  Shouldst thou need to read these intructions again, thou shalt
  type <look> and thou willt be informed.
  
  Please note that you willst be given further instructions and details
  upon to execution of said commands.
KAYLA
);
}

void init() {
  ::init();
    donestats = allocate_mapping(10);
    donestats["strength"] = 0;
    donestats["dexterity"] = 0;
    donestats["constitution"] = 0;
    donestats["charisma"] = 0;
    donestats["wisdom"] = 0;
    donestats["intelligence"] = 0;
    roll();
}

int race_ok(string str, int astr, int adex, int aint, int acon, int acha, int awis) {
  int ret;
  ret = 1;
  if (str == "dwarf") {
    if (astr < 8) ret = 0; if (adex > 17) ret = 0; 
    if (acon < 11) ret = 0; if (acha > 17) ret = 0;
  }
  if (str == "elf") {
    if (adex < 6) ret = 0;  if (acon < 7) ret = 0;
    if (aint < 8) ret = 0;  if (acha < 8) ret = 0; 
  }
  if (str == "gnome") {
    if (astr < 6) ret = 0;  if (acon < 8) ret = 0;
    if (aint < 6) ret = 0;
  }
  if (str == "half-elf") {
    if (adex < 6) ret = 0; if (acon < 6) ret = 0;
    if (aint < 4) ret = 0;
  }
  if (str == "halfling") {
    if (astr < 7) ret = 0; if (adex < 7) ret = 0;
    if (acon < 10) ret = 0; if (aint < 6) ret = 0;
    if (awis > 17) ret = 0;
  }
  return ret;
}

int okdone() {
  int fail;
 
  if(donedone) {
    write("Thou hast already typed done!  Proceed to pick thine race!");
    return 1;
  }
  if(!rolled) {
    write("Thou has not <roll>d thine stats.");
    return 1;
  }
  if(!donedone) {
    donedone = 1;
  }
    
  awis = this_player()->query_stats("wisdom");
  astr = this_player()->query_stats("strength");
  adex = this_player()->query_stats("dexterity");
  aint = this_player()->query_stats("intelligence");
  acon = this_player()->query_stats("constitution");
  acha = this_player()->query_stats("charisma");
  fail = ((!awis) || (!astr) || (!adex) || (!aint) || (!acon) || (!acha));
  if(fail) {
    write("Thou has not completed assigning your stats!");
    write("Pay attention to the intructions.");
    write("A lightning bolt hits the floor two feet from you.");
    donedone = 0;
    this_player()->force_me("look");
    return 1;
  }
  write("Good.  Thou hast finished choosing your stats.");
  write("Now thou must pick a race for you to become.");
  write("This is the list thou canst choose from.");
  dok = race_ok("dwarf",astr,adex,aint,acon,acha,awis);
  if(dok) write("  Dwarf");
  eok = race_ok("elf",astr,adex,aint,acon,acha,awis);
  if(eok) write("  Elf");
  gok = race_ok("gnome",astr,adex,aint,acon,acha,awis);
  if(gok) write("  Gnome");
  heok = race_ok("half-elf",astr,adex,aint,acon,acha,awis);
  if(heok) write("  Half-Elf");
  hok = race_ok("halfling",astr,adex,aint,acon,acha,awis);
  if(hok) write("  Halfling");
  write("  Human");
  write("Type <pick racename> to pick your race for good.");
  write("Ex: pick dwarf    will make you a dwarf.");
  currentstr = "You must <pick> your race now.";
  add_action("pick","pick");
  return 1;
}

void already() {
  write("You have already finished the use of that command.");
  write(currentstr);
  return 1;
}

int pick(string str) {
    string *which;
    mapping borg;
    int tmp, i, fail;
    string class;

    if(donepick) {
      write("Thou hast already picked thine race!  Proceed to choose thine class!");
      return 1;
    }
    if(!donedone) {
      write("Thou hast not typed <done> yet!  Finish assigning your stats!");
      return 1;
    }
    fail = 0;
    if(!str) {
        write("To pick a race, type \"pick whatever\", where whatever is the race from");
        write("the following list:");
        if(dok) write("  Dwarf");
        if(eok) write("  Elf");
        if(gok) write("  Gnome");
        if(heok) write("  Half-Elf");
        if(hok) write("  Halfling");
        write("  Human");
        donepick = 0;
        return 1;
    }
    str = lower_case(str);
    if(member_array(str, (string *)RACE_D->query_races()) == -1) {
	write("That is not a valid race.\n");
	write("Valid races are: dwarf, elf, human, gnome, half-elf, halfling.");
	return 1;
    }
    if(!donepick) {
      donepick =1;
    }
    if ((str == "dwarf") && !dok) fail = 1;
    if ((str == "elf") && !eok) fail = 1;
    if ((str == "gnome") && !gok) fail = 1;
    if ((str == "half-elf") && !heok) fail = 1;
    if ((str == "halfling") && !hok) fail = 1;
    if(fail) {
      write("I'm sorry, you're not allowed to be a "+str+".");
      donepick = 0;
      return 1;
    }
    this_player()->set_race(str);
    write("You are now a "+str+"!");
    write("Finally, you have to choose your class.");
    write("Classes available for you to join are:");
    paok = ((astr > 11) && (acon > 8) && (awis > 12) && (acha > 16));
    raok = ((astr > 12) && (adex > 12) && (acon > 13) && (awis > 13));
    maok = (aint > 8);
    thok = (adex > 8);
    fiok = (astr > 8);
    ilok = ((aint > 8) && (adex > 15));
    drok = ((awis > 11) && (acha > 14));
    clok = (awis > 8);
    baok = ((adex > 11) && (aint > 12) && (acha > 15));
    if(paok) write("  Paladin");
    if(raok) write("  Ranger");
    if(maok) write("  Mage");
    if(thok) write("  Thief");
    if(fiok) write("  Fighter");
//    if(ilok) write("  Illusionist");
    if(drok) write("  Druid");
    if(clok) write("  Cleric");
    if(baok) write("  Bard");
/*
    fithok = ((fiok) && (thok) && (str == "dwarf"));
    ficlok = ((fiok) && (clok) && (str == "dwarf"));
    fimaok = ((fiok) && (maok) && (str == "elf"));
    fithok = ((fiok) && (thok) && (str == "elf"));
    mathok = ((maok) && (thok) && (str == "elf"));
    fimathok = ((fiok) && (maok) && (thok) && (str == "elf"));    
    fiilok = ((fiok) && (ilok) && (str == "gnome"));
    ilthok = ((ilok) && (thok) && (str == "gnome"));
    fithok = ((fiok) && (thok) && (str == "gnome"));
    fithok = ((fiok) && (thok) && (str == "halfling"));
    if(fithok) write("  Fighter-Thief");
    if(ficlok) write("  Fighter-Cleric");
    if(fimaok) write("  Fighter-Mage");
    if(mathok) write("  Mage-Thief");
    if(fimathok) write("  Fighter-Mage-Thief");
    if(fiilok) write("  Fighter-Illusionist");
    if(ilthok) write("  Illusionist-Thief");
*/  
  
    write("Now, we're almost done.  Just type <pick classname> to choose your class.");
    write("Ex: pick fighter      to join the fighters.");
//    write("or  pick fighter-mage-thief");
    currentstr = "You must now <pick> your class.";
    add_action("choose","pick");
    return 1;
  }
  
  int choose(string str) {
    int fail, numcl, x;
    string s1,s2,s3,s4;
    
    if(donechoose) {
      write("Thou has already chosen thine class.  Proceed to choose aligment.");
      return 1;
    }
    if(!donepick) {
      write("Thou art not ready to choose thine class.  You must pick thine race first.");
      return 1;
    }
    fail = 0;
    if((str == "fighter") && (fiok)) fail = 1;
    if((str == "mage") && (maok)) fail = 1;
    if((str == "cleric") && (clok)) fail = 1;
    if((str == "druid") && (drok)) fail = 1;
  //  if((str == "illusionist") && (ilok)) fail = 1;
    if((str == "ranger") && (raok)) fail = 1;
    if((str == "paladin") && (paok)) fail = 1;
    if((str == "thief") && (thok)) fail = 1;
    if((str == "bard") && (baok)) fail = 1;
  /*
    if((str == "fighter-thief") && (fithok)) fail = 1;
    if((str == "fighter-cleric") && (ficlok)) fail = 1;
    if((str == "fighter-mage") && (fimaok)) fail = 1;
    if((str == "mage-thief") && (mathok)) fail = 1;
    if((str == "fighter-mage-thief") && (fimathok)) fail = 1;
    if((str == "fighter-illusionist") && (fiilok)) fail = 1;
    if((str == "illusionist-thief") && (ilthok)) fail = 1;
  */
    if(fail == 0) {
      write("You can't become a "+str+"!");
      donechoose = 0;
      return 1;
    }
    if(sscanf(str,"%s-%s",s1,s2)) {
      numcl = 0;
      this_player()->init_mclass();
      if(s1) { numcl+=1; this_player()->set_mclass(numcl,s1); }
      if(sscanf(s2,"%s-%s",s3,s4)) {
        if(s3) { numcl+=1; this_player()->set_mclass(numcl, s3); }
        if(s4) { numcl+=1; this_player()->set_mclass(numcl, s4); }
      }
      else
        if(s2) { numcl+=1; this_player()->set_mclass(numcl, s2); }
      this_player()->set_multi(numcl);
    }
    for(x=0; x<numcl;x++) {
      this_player()->set_class_level(x,0);
      this_player()->set_level(1);
    }
    this_player()->new_body();
    this_player()->set_max_mp(0);
    this_player()->set_mp(0);
    if(!this_player()->query_multi())
      this_player()->set_level(0);
    this_player()->set_class(str);
    this_player()->set_max_hp(1);
    this_player()->set_hp(1);
    this_player()->add_money("gold",200+random(300));
    if(!donechoose) {
      donechoose = 1;
    }
    write("You are now a "+str+"!");
    if((str == "fighter") || (str == "paladin") || (str == "ranger")) {
      if((int)this_player()->query_stats("strength") == 18) {
        x = random(99);
        this_player()->set_stats("exceptional_strength",x);
        write("You rolled an exceptional strength of "+x+"!");
        write("Your strength is now 18/"+x+".");
      }
    }
    this_player()->add_exp(10);
    write("Now, only one step to go.  You must now select an alignment.");
    write("These are the alignments you can select from:");
    write("  1.) Lawful Good");
    if (str != "paladin") {
      write("  2.) Lawful Neutral");
      write("  3.) Lawful Evil");
      write("  4.) Neutral Good");
      write("  5.) True Neutral");
      write("  6.) Neutral Evil");
      write("  7.) Chaotic Good");
      write("  8.) Chaotic Neutral");
      write("  9.) Chaotic Evil");
    }
    write("So now type <pick> number");
    write("Ex: pick 1    to select Lawful Good.");
    currentstr = "You must now <pick> your alignment.";
    add_action("select","pick");
    return 1;
  }
  
 int select(string str) {
    int sel;
    if(!str) {
      write("Thou must give a number from 1 to 9z!");
      return 1;
    }
    if(!donechoose) {
      write("Thou hast not chosen thine class!");
      return 1;
    }
    if(!sscanf(str,"%d",sel)) {
      write("I'm sorry, that's not a valid entry.");
      return 1;
    }
    if((sel < 1) || (sel > 9)) {
      write("I'm sorry, that's not a valid entry.");
      return 1;
    }
    if (( (string)this_player()->query_class() == "paladin") &&
        (sel != 1)) {
        write("I'm sorry, but Paladins can only be Lawful Good.");
        return 1;
     }
     this_player()->set_alignment(sel);
     write("Your alignment is set.");
     if( (string)this_player()->query_gender() == "male")
       this_player()->setenv("TITLE", "$N the boy");
      else this_player()->setenv("TITLE", "$N the girl");
    this_player()->init_skills((string)this_player()->query_class());
    write("Matter folds around you and forms your living self.");    
    write("You are suddenly transported to a new world.");
    this_player()->move_player(ROOM_START);
    this_object()->remove();
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

    this_player()->new_body();
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
    write("+------- Your rolls were ----------");
    for (i=1; i < 7; i++)
      write("Roll number: "+i+"   =    "+final[i]);
    write("Now you can <assign> a roll number to a stat.");
    write("For instance 'assign 2 strength' will assign roll #2 to strength.");
    write("You can type <show> at any point to list your rolls.");
    write("You can also type <stats> to show your current stats.");
    write("Note that you can just type <quick> to quickly associate them.");
    write("Type <done> when you are finished with your stats.");
    currentstr = "You must <assign> your rolls.  Type <assign> for help.";
    add_action("quick","quick");
    add_action("show","show");
    add_action("assign","assign");
    add_action("okdone","done");
    return 1;
}

int quick(string str) {
  if(!donedone) {
    write("Your stats are complete.");
    this_player()->set_stats("strength",final[1]);
    this_player()->set_stats("dexterity",final[2]);
    this_player()->set_stats("constitution",final[3]);
    this_player()->set_stats("intelligence",final[4]);
    this_player()->set_stats("wisdom",final[5]);
    this_player()->set_stats("charisma",final[6]);
    final[1] = 0; final[2] = 0; final[3] = 0;
    final[4] = 0; final[5] = 0; final[6] = 0;
    okdone();
    return 1;
  }
  else
  {
    write("You are finished with your stats.");
    write(currentstr);
    return 1;
  }
  
}

int show(string str) {
  int i;
  write("--- Your Rolls ---");
  for (i=1; i<7;i++)
   write("Roll "+i+".)   "+final[i]);
  return 1;
}

int assign(string str) {
  int i,j,tmp;
  string stt,stat;
  if (!doneroll) {
    write("Thou must first <roll> your stats!");
    return 1;
  }
  if(donedone) {
    write("Thou art done with your stats!");
    write(currentstr);
    return 1;
  }
  if(!str) {
    write("Now you can <assign> a roll number to a stat.");
    write("For instance 'assign 2 strength' will assign roll #2 to strength.");
    write("You can type <show> at any point to list your rolls.");
    write("You can also type <stats> to show your current stats.");
    write("Type <done> when you are finished with your stats.");
    return 1;
  }
  if(!sscanf(str,"%d %s",i,stt)) {
    write("Format: assign roll# stat");
    write("Ex: assign 2 strength   to assign roll 2 to strength.");
    return 1;
  } 
  if( (i < 1) || (i > 6) ) {
    write("Invalid roll number.  Enter a number between 1 and 6.");
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
    write("You've already assigned that stat!");
    return 1;
  }
  if((stat != "strength") && (stat != "dexterity") && (stat != "constitution") &&
    (stat != "intelligence") && (stat != "wisdom") && (stat != "charisma"))  {
    write("Invalid stat.");
    return 1;
  }
  if(!final[i]) {
    write("That stat is already used.");
    return 1;
  }
  this_player()->set_stats(stat,final[i]);
  write(capitalize(stat)+" set to "+final[i]+".");
  donestats[stat]=1;
  final[i]=0;
  return 1;
}

int list(string str) {
    string *res;
    int i, j, tmp;
    if(!str) {
	notify_fail("What do you want to read? A list?\n");
	return 0;
    }
    if(str != "list") {
	notify_fail("That is not here to be read.\n");
	return 0;
    }
    write("These are the following races available in our reality:");
    write("-----------------------------------------------------------");
    message("Ninfo", format_page((string *)RACE_D->query_races(), 4),
      this_player());
    write("----------------------------------------------------------");
    write("pick <race> will forever make you one of these races");
    write("Type <help races> for more information.");
    return 1;
}
