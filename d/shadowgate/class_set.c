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
// shifted room to new racial queries. Nienne, 10/10
#include <daemons.h>
#include <std.h>
#include <rooms.h>
#define RACE (string)this_player()->query_race()
#define TRI_CLASS_OK 0

#define TESTCLASS ({  })
#define TESTERS ({ "testlackey", "testgreeble", "gaje", "testlock", "zeal", "iskehalya", "azrael", "shyntyrr" })


inherit ROOM;

void pick_diety();
void pick_school();
int bardness();
void school(string str);
void finish();
void pick_class();

string *names, myname, currentstr, *classes;
int receive, rolled, donechoose, doneassign, donedone, astr, adex, acon, acha, awis, aint, align;
mapping donestats;
mixed final;

void create() {
   room::create();
   set_property("light",2);
   set_property("indoors",1);
   set_property("no steal", 1);
   set_property("no attack", 1);
   set("short","Class hall");
   set_property("no teleport", 1);
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
   string myrace, mysubrace, myracefile, myclassfile, *tempclasses, *statkeys, *testers;
   int i, j, tracker, *alignholder;
   mapping statsholder;
   awis = this_player()->query_stats("wisdom");
   astr = this_player()->query_stats("strength");
   adex = this_player()->query_stats("dexterity");
   aint = this_player()->query_stats("intelligence");
   acon = this_player()->query_stats("constitution");
   acha = this_player()->query_stats("charisma");
   align = TP->query_alignment();
   myname = TP->query_name();
   myrace = (string)TP->query_race();
   mysubrace = (string)TP->query("subrace");
   ::init();

   classes = ({});
   tempclasses = ({ "bard", "cavalier", "paladin", "cleric", "fighter", "mage", "psion", "ranger", "sorcerer", "thief","druid","barbarian","psywarrior","warlock" });
   myracefile = "/std/races/"+myrace+".c";
   if(file_exists(myracefile)) {
     tempclasses -= (string *)myracefile->restricted_classes(mysubrace); // picks all classes for the current subrace
     //then roll through each valid class to ensure stat and align requirements are met
     if(sizeof(tempclasses)) {
       for(i=0;i<sizeof(tempclasses);i++) {
         tracker = 0;
         myclassfile = "/std/class/"+tempclasses[i]+".c";
         if(file_exists(myclassfile)) {
//Tester info added for ease of testing new classes ~Circe~ 9/3/15
           if(sizeof(TESTCLASS)){
              if(member_array(tempclasses[i],TESTCLASS) != -1){
                 if(member_array((string)TP->query_name(),TESTERS) == -1){ 
                    tracker = 1;
                 }
              }
           }            
           alignholder = (int *)myclassfile->restricted_alignments();
           if(member_array(align,alignholder) != -1) tracker = 1; // if their alignment is on the restricted list, fail
           statsholder = (mapping)myclassfile->stat_requirements(); // now check the stats mapping
           statkeys = keys(statsholder);
           if(sizeof(statkeys)) {
             for(j=0;j<sizeof(statkeys);j++) {
               if((int)TP->query_stats(statkeys[j]) < statsholder[statkeys[j]]) tracker = 1;
             }
           }
         }
         if(!tracker) classes += ({ tempclasses[i] });
       }
     }
   }
   pick_class();
}

void pick_class() {
   int i;
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

   write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-");
   if(!sizeof(classes)) write("  %^BOLD%^%^MAGENTA%^Error generating class list - please contact a wiz.");
   else {
     for(i=0;i<sizeof(classes);i++) {
       write("  %^BOLD%^%^MAGENTA%^"+capitalize(classes[i])+"");
     }
   }
   write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-");
   write("%^BOLD%^Now, we're almost done.  Just type %^BLACK%^<%^CYAN%^pick classname%^BLACK%^> %^WHITE%^to choose your class.");
   write("%^YELLOW%^Ex%^BLACK%^: %^WHITE%^pick fighter%^RESET%^ to join the fighters.");
   currentstr = "%^BOLD%^You must now %^BLACK%^<%^CYAN%^pick%^BLACK%^>%^WHITE%^ your class.";
   add_action("choose","pick");
   return 1;
}

int choose(string str) {
   int numcl, x,ex;
   string s1,s2,s3,s4;

   if(donechoose) {
      write("%^RED%^Thou has already chosen thine class.  Proceed to choose alignment.");
      return 1;
   }

   if(member_array(str,classes) == -1) {
      write("%^BOLD%^%^RED%^Thou can't become a %^MAGENTA%^"+str+"!");
      donechoose = 0;
      return 1;
   }

   this_player()->set_class(str);
   this_player()->set_mlevel(str,0);
   this_player()->new_body();
   this_player()->set_max_mp(0);
   this_player()->set_mp(0);
   this_player()->set_max_hp(20);
   this_player()->set_hp(20);
   this_player()->add_money("gold",200+random(300));
   this_player()->init_spellcaster();
   TP->add_exp(1);
   if(!donechoose) donechoose = 1;

   write("You are now a "+str+"!");
   new("/d/shadowgate/masters/"+str)->move(TO);
   return 1;
}
