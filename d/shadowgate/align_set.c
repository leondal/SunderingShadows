// New room just for alignments; doing this after races to save player confusion.
#include <daemons.h>
#include <std.h>
#include <rooms.h>
#define RACE (string)this_player()->query_race()
inherit ROOM;

void do_align();
void align_done();
string myrace, mysubrace;
int *validaligns;

void create() {
   room::create();
   set_property("light",2);
   set_property("indoors",1);
   set_property("no teleport", 1);
   set_property("no steal", 1);
   set_property("no attack", 1);
   set_short("Alignment hall");
   set_long("This is a great barren hall. You can see neither walls nor ceiling. All you can see is the grand statue near "
"you. It beams with life, a life it wishes to give you. Your purpose here is to be short. But of the utmost importance.");
   validaligns = ({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
}

void init() {
   string file;
   ::init();
   myrace = TP->query_race();
   mysubrace = TP->query("subrace");
   file = "/std/races/"+myrace+".c";
   if(file_exists(file)) validaligns -= (int *)file->restricted_alignments(mysubrace);

   add_action("select_align","pick");
   do_align();
}

void do_align() {
   int i;

   write(
@OLI
%^BOLD%^
Standing before you is a great figure. The figure glances at you casually.
SUDDENLY...

A booming voice announces:
%^GREEN%^"CHOOSE THE COURSE OF THINE LIFE.  How wilt thee act upon the world of Shadowgate?"

OLI
   );

   write("%^YELLOW%^You must now select an alignment. Your race allows the following options:");
   for(i=1;i<10;i++) {
     if(member_array(i,validaligns) != -1) {
       switch(i) {
         case 1: write("%^BOLD%^%^CYAN%^  1.) Lawful Good"); break;
         case 2: write("%^BOLD%^%^CYAN%^  2.) Lawful Neutral"); break;
         case 3: write("%^BOLD%^%^CYAN%^  3.) Lawful Evil"); break;
         case 4: write("%^BOLD%^%^CYAN%^  4.) Neutral Good"); break;
         case 5: write("%^BOLD%^%^CYAN%^  5.) True Neutral"); break;
         case 6: write("%^BOLD%^%^CYAN%^  6.) Neutral Evil"); break;
         case 7: write("%^BOLD%^%^CYAN%^  7.) Chaotic Good"); break;
         case 8: write("%^BOLD%^%^CYAN%^  8.) Chaotic Neutral"); break;
         case 9: write("%^BOLD%^%^CYAN%^  9.) Chaotic Evil"); break;
         default: write("%^BOLD%^%^RED%^There has been an error selecting your alignment! Please contact a wiz."); break;
       }
     }
   }
   write("");
   write("%^YELLOW%^Syntax example: pick 1");
   write("%^BOLD%^%^WHITE%^This will assign your alignment to Lawful Good.");
}

int select_align(string str) {
   int sel;
   if(!str) {
      write("%^YELLOW%^Thou must give a number from 1 to 9!");
      return 1;
   }
   if(!sscanf(str,"%d",sel) || (sel < 1) || (sel > 9)) {
      write("%^BOLD%^%^WHITE%^Syntax example: pick 1");
      write("%^BOLD%^%^WHITE%^This will assign your alignment to Lawful Good.");
      return 1;
   }
   if(member_array(sel,validaligns) == -1) {
      write("%^BOLD%^%^WHITE%^That is not a valid alignment for your race! Please try again.");
      return 1;
   }
   TP->set_alignment(sel);
   write("%^YELLOW%^Your alignment is set.");
   align_done();
   return 1;
}

void align_done() {
   write("%^BOLD%^ %^RED%^ SUDDENLY....");
   write("%^BOLD%^Thou are struck with a sudden blow....");
   write("but no physical damage was done...");
   write("Thy mind is flooded with memories....");
   switch((int)TP->query_alignment()) {
   case 1:
      write(
@OLI
%^BOLD%^
Sights of thee doing deeds of good. Rules have always been of a
great guidance to thee. Thou hast always been honest and hard
working.
OLI
      );
      break;
   case 2:
      write(
@OLI
%^BOLD%^
Rules are thy life. Morality is of no importance to thee.
Always thou seest that the law is supported. Thou hast looked to
organization since...
OLI
      );
      break;
   case 3:
      write(
@OLI
%^BOLD%^
Thou hast always seen the laws as there for thy own benefit.
What happens as thou used the rules hast never bothered thee.
OLI
      );
      break;
   case 4:
      write(
@OLI
%^BOLD%^
Thou hast always fought to do right... means have never meant
much to thee. Organizations of evil thou hast always seen as
enemies. Whilest organizations of good have been granted thy
support.
OLI
      );
      break;
   case 5:
      write(
@OLI
%^BOLD%^
To the underdog hast thou given thy support. Always hast
thee given thyself to overthrowing the powerful... wishing
to gain a balance someday.
OLI
      );
      break;
   case 6:
      write(
@OLI
%^BOLD%^
Thou hast always been concerned with thyself. Profit is of
utmost importance to thee. Bribes that thou hast excepted flow
through thy mind.
OLI
      );
      break;
   case 7:
      write(
@OLI
%^BOLD%^
Vigilance hast ruled thy life. Those who wish to push
good folk around have earned thy dislike. Society is of little
use to thee. Thou wishest to see thy own idea of good done.
OLI
      );
      break;
   case 8:
      write(
@OLI
%^BOLD%^
Thou sees problems always around thee. Society finds thee to
be troublesome.  Thou hast always forgotten obligations.
Thou hast been looked upon by others as insane.
OLI
      );
      break;
   case 9:
      write(
@OLI
%^BOLD%^
Thou hast always searched for thy own pleasure and profit.
Throughout life thou hast exploited and taken what was to be had.
Force has been thy only ally and yet a powerful enemy.
OLI
      );
      break;
   }
   TP->move(new("/d/shadowgate/class_set"));
}