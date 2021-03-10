//%^BOLD%^psion testing.  Will be taken out later.%^RESET%^
//Second stage to the setter
//To allow for the picking of classes... to be adapted for
//kits/sub-classes to come soon.

//The players will arrive here after picking a race.
//They will be met and preached to... they then will a be allowed to
//decide on their class.
//A master of that class will appear and the orders will appear from
//that monster.
//but mainly the kits will appear from these monsters...
//They will then pick there alignment.
//and be allowed to start their adventure
//Created by TRISTAN@shadowgate
//some code adapted from begin.c (version 1) by Kayla

// moved this to a #define up here for easier location & maintenance *Styx* 6/11/06
// added psions for general access, and human multiclassing. Nienne, 02/07
// removed dex requirement for cavaliers. Nienne, 07/07
#include <daemons.h>
#include <std.h>
#define PSIONS_OK ({ })
#include <rooms.h>
//#include "diety.h"
#define RACE (string)this_player()->query_race()
#define TRI_CLASS_OK 0
inherit ROOM;

void pick_diety();
void pick_school();
int bardness();
void school(string str);
void finish();
void pick_class();

string *names, myname;
int receive, rolled;
int  donechoose, doneassign, donedone;
mapping donestats;
string currentstr;
mixed final;
int dok, eok, gok, heok, hok;
int fiok, paok, raok, maok, clok, drok, thok, baok, cavok, psiok, sorok;
int fithok, ficlok, fimaok, mathok, fimathok, clmaok, ficlmaok, psifiok, psithok, psiclok;
int astr, adex, acon, acha, awis, aint;
int align;


void create() {
   room::create();
   set_property("light",2);
   set_property("indoors",1);
   set_property("no steal", 1);
   set_property("no attack", 1);
   set("short","Class hall");
   set_long(
@OLI
This is a great barren hall. You can see neither walls nor ceiling.
All you can see is the grand statue near you. It beams with life,
a life it wishes to give you. Your purpose here is to be short. But
of the utmost importance.
OLI
   );
}

void init() {
   awis = this_player()->query_stats("wisdom");
   astr = this_player()->query_stats("strength");
   adex = this_player()->query_stats("dexterity");
   aint = this_player()->query_stats("intelligence");
   acon = this_player()->query_stats("constitution");
   acha = this_player()->query_stats("charisma");
   align = TP->query_alignment();
   myname = TP->query_name();
   ::init();
   pick_class();
}

void pick_class() {
   write("%^BOLD%^%^RED%^A grand voice booms from the walls and ceiling ");
   write("%^BOLD%^%^RED%^and floor. . . ");
   write("%^BOLD%^%^BLUE%^ Thou hast been born into the world of SHADOWGATE!!");
   write("%^BOLD%^%^YELLOW%^ Thou dost now complete thyself with worldly");
   write("%^BOLD%^%^YELLOW%^ things... ");
   write("");
   write("%^BOLD%^%^RED%^PICK THE COURSE OF THINE LIFE!!!");
   write("");
   write("%^BOLD%^Thou must choose thine class.");
   write("%^BOLD%^%^MAGENTA%^Classes available for thee to join are:");
//    paok = ((astr > 11) && (acon > 8) && (awis > 12) && (acha > 16) && (RACE == "human"));
//   cavok = ((astr > 11) && (acon > 8) && (adex > 14) && (awis > 9) && (aint > 9) && (RACE == "human") && (align == 1 || align == 2 || align == 3));
   cavok = ((astr > 11) && (acon > 8) && (awis > 9) && (aint > 9) && (RACE == "human") && (align == 1 || align == 2 || align == 3));
   raok = ((astr > 12) && (adex > 12) && (acon > 13) && (awis > 13) && ((RACE == "human") || (RACE == "elf") || (RACE == "half-elf") || (RACE == "beastman") || (RACE == "drow") || (RACE == "half-drow") || (RACE == "voadkyn") || (RACE == "wemic")));
   maok = ((aint > 8) && ((RACE == "human") || (RACE == "elf") || (RACE == "half-elf") || (RACE == "drow") || (RACE == "half-drow") || (RACE == "ogre-mage") || (RACE == "gnome")));
   psiok = ((aint > 8) && (RACE == "human"));
   thok = ((adex > 8) && (RACE !="firbolg") && (RACE != "ogre") && (RACE != "half-ogre") && (RACE !="wemic") && (align != 1));
   fiok = (astr > 8);
   drok = ((awis > 11) && (acha > 14) && ((RACE == "human") || (RACE == "half-elf")));
   clok = ((awis > 8) && (RACE !="beastman") && (RACE !="voadkyn") && (RACE != "ogre") && (RACE != "ogre-mage") && (RACE !="wemic"));
   baok = ((adex > 11) && (aint > 12) && (acha > 14) && ((RACE == "human") || (RACE == "half-elf") || (RACE == "wemic") || (RACE == "elf")) && (align == 2 || align == 4 || align == 5 || align == 6 || align == 8));
   sorok = ((acha > 10) && ((RACE == "human") || (RACE == "half-elf") || (RACE == "half-orc") || (RACE == "half-drow") || (RACE == "drow") || (RACE == "elf") || (RACE == "goblin") || (RACE == "kobold") || (RACE == "voadkyn") || (RACE == "halfling") || (RACE == "gnome")));
   write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-");
//    if(paok) write("  %^BOLD%^%^MAGENTA%^Paladin");
   if(cavok) write("  %^BOLD%^%^MAGENTA%^Cavalier");
   if(raok) write("  %^BOLD%^%^MAGENTA%^Ranger");
   if(maok) write("  %^BOLD%^%^MAGENTA%^Mage");
   if(psiok) write("  %^BOLD%^%^MAGENTA%^Psion");
   if(thok) write("  %^BOLD%^%^MAGENTA%^Thief");
   if(fiok) write("  %^BOLD%^%^MAGENTA%^Fighter");
//    if(drok) write("  %^BOLD%^%^MAGENTA%^Druid");
   if(clok) write("  %^BOLD%^%^MAGENTA%^Cleric");
   if(baok) write("  %^BOLD%^%^MAGENTA%^Bard");
   if(sorok) write("  %^BOLD%^%^MAGENTA%^Sorcerer");
   if(!TP->query("new_class_type"))
   {
        fithok = ((fiok) && (thok));
        ficlok = ((fiok) && (clok));
        fimaok = ((fiok) && (maok));
        mathok = ((maok) && (thok));
        fimathok = ((fiok) && (maok) && (thok) && TRI_CLASS_OK);
        clmaok = ((clok) && (maok));
        ficlmaok = ((fiok) && (clok) && (maok) && TRI_CLASS_OK);
        psifiok = ((fiok) && (psiok));
        psithok = ((thok) && (psiok));
        psiclok = ((clok) && (psiok));
        if(fithok) write("  %^BOLD%^%^MAGENTA%^Fighter-Thief");
        if(ficlok) write("  %^BOLD%^%^MAGENTA%^Fighter-Cleric");
        if(fimaok) write("  %^BOLD%^%^MAGENTA%^Fighter-Mage");
        if(mathok) write("  %^BOLD%^%^MAGENTA%^Mage-Thief");
        if(fimathok) write("  %^BOLD%^%^MAGENTA%^Fighter-Mage-Thief");
        if(clmaok) write("  %^BOLD%^%^MAGENTA%^Cleric-Mage");
        if(ficlmaok) write("  %^BOLD%^%^MAGENTA%^Fighter-Cleric-Mage");
        if(psifiok) write("  %^BOLD%^%^MAGENTA%^Psion-Fighter");
        if(psithok) write("  %^BOLD%^%^MAGENTA%^Psion-Thief");
        if(psiclok) write("  %^BOLD%^%^MAGENTA%^Psion-Cleric");
   }
   write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-");
   write("%^BOLD%^Now, we're almost done.  Just type %^BLACK%^<%^CYAN%^pick classname%^BLACK%^> %^WHITE%^to choose your class.");
   write("%^YELLOW%^Ex%^BLACK%^: %^WHITE%^pick fighter%^RESET%^ to join the fighters.");
   currentstr = "%^BOLD%^You must now %^BLACK%^<%^CYAN%^pick%^BLACK%^>%^WHITE%^ your class.";
   add_action("choose","pick");
   return 1;
}

int choose(string str) {
   int fail, numcl, x,ex;
   string s1,s2,s3,s4;

   if(donechoose) {
      write("%^RED%^Thou has already chosen thine class.  Proceed to choose alignment.");
      return 1;
   }

   fail = 0;
   if((str == "fighter") && (fiok)) fail = 1;
   if((str == "mage") && (maok)) fail = 1;
   if((str == "psion") && (psiok)) fail = 1;
   if((str == "cleric") && (clok)) fail = 1;
//    if((str == "druid") && (drok)) fail = 1;
   if((str == "ranger") && (raok)) fail = 1;
//    if((str == "paladin") && (paok)) fail = 1;
   if((str == "cavalier") && (cavok)) fail = 1;
   if((str == "thief") && (thok)) fail = 1;
   if((str == "bard") && (baok)) fail = 1;
   if((str == "sorcerer") && (sorok)) fail = 1;
   if(!TP->query("new_class_type"))
   {
       if((str == "fighter-thief") && (fithok)) fail = 1;
       if((str == "fighter-cleric") && (ficlok)) fail = 1;
       if((str == "fighter-mage") && (fimaok)) fail = 1;
       if((str == "mage-thief") && (mathok)) fail = 1;
       if((str == "fighter-mage-thief") && (fimathok)) fail = 1;
       if((str == "cleric-mage") && (clmaok)) fail = 1;
       if((str == "fighter-cleric-mage") && (ficlmaok)) fail = 1;
       if((str == "psion-fighter") && (psifiok)) fail = 1;
       if((str == "psion-thief") && (psithok)) fail = 1;
       if((str == "psion-cleric") && (psiclok)) fail = 1;
   }
   if(fail == 0) {
      write("%^BOLD%^%^RED%^Thou can't become a %^MAGENTA%^"+str+"!");
      donechoose = 0;
      return 1;
   }
   if(strsrch(str,"fighter")!=-1) {
      this_player()->set_class("fighter");
      this_player()->set_mlevel("fighter",0);
      if(TP->query("new_class_type")) catch("/cmds/mortal/_advance.c"->add_class_feats(TP,"fighter"));
   }
   if(strsrch(str,"cleric")!=-1) {
      this_player()->set_class("cleric");
      this_player()->set_mlevel("cleric",0);
      if(TP->query("new_class_type")) catch("/cmds/mortal/_advance.c"->add_class_feats(TP,"cleric"));
   }
   if(strsrch(str,"mage")!=-1) {
      this_player()->set_class("mage");
      this_player()->set_mlevel("mage",0);
      if(TP->query("new_class_type")) catch("/cmds/mortal/_advance.c"->add_class_feats(TP,"mage"));
   }
   if(strsrch(str,"psion")!=-1){
      this_player()->set_class("psion");
      this_player()->set_mlevel("psion",0);
      if(TP->query("new_class_type")) catch("/cmds/mortal/_advance.c"->add_class_feats(TP,"psion"));
   }
   if(strsrch(str,"thief")!=-1) {
      this_player()->set_class("thief");
      this_player()->set_mlevel("thief",0);
      if(TP->query("new_class_type")) catch("/cmds/mortal/_advance.c"->add_class_feats(TP,"thief"));
   }
/*
    if(strsrch(str,"paladin")!=-1){
      this_player()->set_class("paladin");
      this_player()->set_mlevel("paladin",0);
    }
*/
   if(strsrch(str,"cavalier")!=-1) {
      this_player()->set_class("cavalier");
      this_player()->set_mlevel("cavalier",0);
      if(TP->query("new_class_type")) catch("/cmds/mortal/_advance.c"->add_class_feats(TP,"cavalier"));
   }
   if(strsrch(str,"ranger")!=-1) {
      this_player()->set_class("ranger");
      this_player()->set_mlevel("ranger",0);
      if(TP->query("new_class_type")) catch("/cmds/mortal/_advance.c"->add_class_feats(TP,"ranger"));
   }
   if(strsrch(str,"bard")!=-1) {
      this_player()->set_class("bard");
      this_player()->set_mlevel("bard",0);
      if(TP->query("new_class_type")) catch("/cmds/mortal/_advance.c"->add_class_feats(TP,"bard"));
   }
   if(strsrch(str,"sorcerer")!=-1) {
      this_player()->set_class("sorcerer");
      this_player()->set_mlevel("sorcerer",0);
      if(TP->query("new_class_type")) catch("/cmds/mortal/_advance.c"->add_class_feats(TP,"sorcerer"));
   }
/*
    if(strsrch(str,"druid")!=-1){
      this_player()->set_class("druid");
      this_player()->set_mlevel("druid",0);
    }
*/
   this_player()->new_body();
   this_player()->set_max_mp(0);
   this_player()->set_mp(0);
   this_player()->set_max_hp(30);
   this_player()->set_hp(30);
   this_player()->add_money("gold",200+random(300));
   this_player()->init_spellcaster();
   TP->add_exp(1);
   if(!donechoose) {
      donechoose = 1;
   }
   write("You are now a "+str+"!");
//    if((strsrch(str,"fighter")!=-1) || (str == "paladin") || (str == "ranger")) {
   // removing exceptional strength so there's no need to roll it here -Ares
   /*
   if((strsrch(str,"fighter")!=-1) || (str == "cavalier") || (str == "ranger"))
   {
      if((int)TP->query_stats("strength") == 18)
      {
         x = random(99) +2;
         ex = TP->query_stats("exceptional_strength");
         switch(x)
         {
         case 1..50:
            switch(ex)
            {
            case 1..50:
               TP->set_stats("exceptional_strength",51+random(25));
               break;
            case 51..75:
               TP->set_stats("exceptional_strength",76+random(15));
               break;
            case -1:
               TP->set_stats("exceptional_strength",1+random(50));
               break;
            }
            break;
         case 51..75:
            switch(ex)
            {
            case 1..50:
               TP->set_stats("exceptional_strength",76+random(15));
               break;
            case 51..75:
               TP->set_stats("exceptional_strength",91+random(9));
               break;
            case -1:
               TP->set_stats("exceptional_strength",51+random(25));
               break;
            }
            break;
         case 76..90:
            switch(ex)
            {
            case 1..50:
               TP->set_stats("exceptional_strength",91+random(9));
               break;
            case 51..75:
               TP->set_stats("exceptional_strength",00);
               break;
            case -1:
               TP->set_stats("exceptional_strength",76+random(15));
               break;
            }
            break;
         case 91..99:
            switch(ex)
            {
            case 1..50:
               TP->set_stats("exceptional_strength",00);
               break;
            case 51..75:
               TP->set_stats("strength",19);
               TP->set_stats("exceptional_strength",-1);
               break;
            case -1:
               TP->set_stats("exceptional_strength",91+random(9));
               break;
            }
            break;
         default:
            TP->set_stats("exceptional_strength",x);
            break;
         }
         x = (int)TP->query_stats("exceptional_strength")%100;
         TP->set_stats("exceptional_strength",x);
         ex = TP->query_stats("exceptional_strength");
         if(ex != -1)
         {
            write("You rolled an exceptional strength of "+ex+"!");
            write("Your strength is now 18/"+ex+".");
         }
         else
         {
            write("Your strength is now "+TP->query_stats("strength")+"!");
         }
      }
   }*/
   new("/d/shadowgate/masters/"+str)->move(TO);
   return 1;
}
