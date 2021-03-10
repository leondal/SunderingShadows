//librarian for Tabor.  Circe 6/2/04
#include <std.h>
inherit NPC;

void make_me();

void create(){
   ::create();
   make_me();
   set_body_type("human");
//   set_gender("female");
   set_class("mage");
   set_level(1);
//   set("aggressive",0);  setting this even to 0 also sets swarm per /std/Object.c so removing it *Styx*  3/16/03
   set_alignment(5);
   set_size(2);
   set_exp(1);
   set_nwp("studying",12);
}

void make_me(){
   switch(random(2)){
   case 0:
      set_race("half-elf");
      set_gender("male");
      set_name("Syvaelan");
      set_short("Syvaelan Leartan, Tabor City librarian");
      set_id(({"Syvaelan Leartan","Syvaelan","syvaelan","librarian"}));
      set_long("Syvaelan Laertan is a middle-aged half-elf who "+
         "has spent his life in isolation, reading and studying.  "+
         "It would seem that with his mixed heritage, this life "+
         "probably suited him best...or at least, he felt it did.  "+
         "His ears are more pointed than most half-elves, and his "+
         "eyes are almond-shaped and so dark as to appear black.  "+
         "He is rather thin and wears only a simple blue robe.  His "+
         "hair is striking, however, falling in lustrous waves "+
         "to his waist.  He appears not to notice, content only "+
         "to catalogue his scrolls and read his books.");
      break;
   case 1:
      set_race("human");
      set_gender("female");
      set_name("Haley");
      set_short("Haley Tourmalin, Tabor City librarian");
      set_id(({"Haley Tourmalin","Haley","haley","librarian"}));
      set_long("Haley Tourmalin is a young priestess of Oghma who "+
         "has been assigned to this library as part of her training.  "+
         "She is still rather young, seeming within her teens, but "+
         "she is intent upon her job.  She has thick black hair "+
         "she wears in a bun, and her eyes are an unusual violet "+
         "that brighten with curiosity at the mention of anything "+
         "unusual.  She is dressed in the manner of an Oghma "+
         "priestess, wearing ballooning pants above a white silk "+
         "shirt.  The pride of her outfit, however, is the heavily "+
         "embroidered vest she wears.");
      break;
   }
}