#include <std.h>
#include "../lothwaite.h"

inherit MONSTER;

void make_me();
#define EYES ({"%^BOLD%^%^BLUE%^blue","%^BOLD%^%^CYAN%^azure","%^RESET%^%^GREEN%^green","%^RESET%^%^ORANGE%^brown","%^BOLD%^%^BLACK%^gray","%^BOLD%^%^GREEN%^eme%^WHITE%^r%^GREEN%^ald","%^BOLD%^%^BLUE%^sa%^CYAN%^p%^BLUE%^ph%^CYAN%^i%^BLUE%^re","%^RESET%^%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^th%^BOLD%^y%^RESET%^%^MAGENTA%^st"})

#define HAIR ({"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r","%^YELLOW%^blonde","%^RED%^red","%^RESET%^%^ORANGE%^chestnut","%^YELLOW%^golden","%^RESET%^white","%^BOLD%^%^BLACK%^mahogany"})

#define TOPS ({"tunic","shirt","coat","vest","bliaut","chiton","jerkin","smock"})

#define BOTTOMS ({"breeches","buckskins","hose","leggings","pants","trousers"})

#define COLORS ({"%^RED%^red","%^ORANGE%^brown","%^GREEN%^green","%^BOLD%^%^BLACK%^black","%^BOLD%^%^WHITE%^white","%^BOLD%^%^BLUE%^blue","%^YELLOW%^yellow","%^MAGENTA%^purple"})

int a,b,c,d,e,f;
string MYEYES,MYHAIR,MYTOP,MYBOTTOM,MYCOLOR,MYCOLOR2;

void create(){
   ::create();
   a = random(sizeof(EYES));
   MYEYES = EYES[a];
   b = random(sizeof(HAIR));
   MYHAIR = HAIR[b];
   c = random(sizeof(TOPS));
   MYTOP = TOPS[c];
   d = random(sizeof(BOTTOMS));
   MYBOTTOM = BOTTOMS[d];
   e = random(sizeof(COLORS));
   MYCOLOR = COLORS[e];
   f = random(sizeof(COLORS));
   MYCOLOR2 = COLORS[f];
   set_name("firbolg citizen");
   set_id(({"citizen","firbolg citizen"}));
   set_race("firbolg");
   set_size(3);
   switch(random(10)){
      case 0..1:  set_alignment(1);
               break;
      case 2..6:  set_alignment(4);
               break;
      case 7:  set_alignment(5);
               break;
      case 8..9:  set_alignment(7);
               break;
   }
   set_moving(1);
   set_nogo(({"/d/barriermnts/lothwaite/rooms/pathway10","/d/barriermnts/lothwaite/rooms/training1"}));
   set_speed(35+random(16));
   set_property("swarm",1);
   switch(random(7)){
      case 0..2:  set_gender("male");
                  set_hd(30,15);
                  set_max_level(25);
                  set_overall_ac(-3);
                  set_max_hp(random(20)+200);
                  set_hp(query_max_hp());
                  set_exp(1000);
                  set_level(30);
                  set_class("fighter");
                  set_mlevel("fighter",30);
                  set_stats("strength",20);
                  set_stats("wisdom",13);
                  set_stats("intelligence",15);
                  set_stats("constitution",16);
                  set_stats("dexterity",12);
                  set_stats("charisma",14);
                  set_mob_magic_resistance("average");
                  set_property("full attacks",1);
                  add_money("gold",random(100));
                  set_short("A male firbolg citizen");
                  set_long("This man seems to be middle-aged.  He looks "+
                     "much like an oversized human with a few handsome "+
                     "features.  He has a thick "+MYHAIR+" beard "+
                     "%^RESET%^%^CYAN%^that matches the long hair "+
                     "pulled back away from his face.  His eyes are "+
                     "a deep "+MYEYES+" %^RESET%^%^CYAN%^that possess "+
                     "a cool, calculating look.  He eyes strangers "+
                     "warily and seems to protect the women and "+
                     "children of the village, though he flashes a "+
                     "ready smile to those the trusts.  He is wearing "+
                     "a "+MYCOLOR+" "+MYTOP+" %^RESET%^%^CYAN%^over "+
                     ""+MYCOLOR2+" "+MYBOTTOM+"%^RESET%^%^CYAN%^, and his "+
                     "feet are clad in the simple %^ORANGE%^leather "+
                     "shoes %^CYAN%^the firbolgs of Lothwaite seem "+
                     "to favor.");
                  if(random(3)){
                     new(OBJ"abrigon")->move(TO);
                     command("wear abrigon");
                  }
                  break;
      case 3..4:  set_gender("female");
                  set_hd(20,15);
                  set_max_level(18);
                  set_overall_ac(0);
                  set_max_hp(random(20)+150);
                  set_hp(query_max_hp());
                  set_exp(750);
                  set_level(20);
                  set_class("fighter");
                  set_mlevel("fighter",30);
                  set_class("mage");
                  set_mlevel("mage",15);
                  set_guild_level("mage",15);
                  set_stats("strength",15);
                  set_stats("wisdom",15);
                  set_stats("intelligence",18);
                  set_stats("constitution",16);
                  set_stats("dexterity",12);
                  set_stats("charisma",14);
                  set_mob_magic_resistance("average");
                  add_money("gold",random(100));
                  set_short("A female firbolg citizen");
                  set_spells(({"lightning bolt","magic missile","burning hands","hold person"}));
                  set_spell_chance(35);
                  set_long("This firbolg woman has clear "+MYEYES+" eyes "+
                     "%^RESET%^%^CYAN%^that watch over the children of "+
                     "the village with care.  Her long "+MYHAIR+" hair "+
                     "%^RESET%^%^CYAN%^is pulled into a long braid "+
                     "that trails down her back.  She is dressed in "+
                     "a well-fitting "+MYCOLOR+" "+MYTOP+" %^RESET%^"+
                     "%^CYAN%^worn over "+MYCOLOR2+" "+MYBOTTOM+""+
                     "%^RESET%^%^CYAN%^, and her feet are clad in simple "+
                     "%^ORANGE%^sandals%^CYAN%^.  Embroidery adorns "+
                     "her clothing in various places, adding a bit of "+
                     "the unique to her attire.");
                  if(random(3)){
                     new(OBJ"abrigon")->move(TO);
                     command("wear abrigon");
                  }
                  break;
      case 5:  set_gender("male");
                  set_hd(10,15);
                  set_max_level(12);
                  set_overall_ac(2);
                  set_max_hp(random(20)+80);
                  set_hp(query_max_hp());
                  set_exp(250);
                  set_level(10);
                  set_class("fighter");
                  set_mlevel("fighter",10);
                  set_stats("strength",16);
                  set_stats("wisdom",13);
                  set_stats("intelligence",15);
                  set_stats("constitution",16);
                  set_stats("dexterity",15);
                  set_stats("charisma",14);
                  set_mob_magic_resistance("average");
                  set_property("full attacks",1);
                  add_money("gold",random(25));
                  set_short("A young male firbolg");
                  set_long("Though he towers well over ten feet tall, "+
                     "the round face of this firbolg clearly shows he "+
                     "is still just a boy.  His "+MYHAIR+" hair "+
                     "%^RESET%^%^CYAN%^is cut short "+
                     "around his head in the manner of the firbolg "+
                     "boys, though he will grow it longer when he "+
                     "reaches manhood.  His "+MYEYES+" eyes %^RESET%^"+
                     "%^CYAN%^seem to dart around, lighting on one "+
                     "article of interest before moving on to another.  "+
                     "He is dressed simply, wearing a "+MYCOLOR+" "+
                     ""+MYTOP+" %^RESET%^%^CYAN%^over "+MYCOLOR2+" "+
                     ""+MYBOTTOM+"%^RESET%^%^CYAN%^.");
                  if(!random(2)){
                     new("/d/common/obj/misc/fishing_rod")->move(TO);
                     new("/d/common/obj/misc/bait")->move(TO);
                  }
                  break;
      case 6:  set_gender("female");
                  set_hd(10,15);
                  set_max_level(12);
                  set_overall_ac(2);
                  set_max_hp(random(20)+80);
                  set_hp(query_max_hp());
                  set_exp(250);
                  set_level(10);
                  set_class("fighter");
                  set_mlevel("fighter",10);
                  set_stats("strength",16);
                  set_stats("wisdom",13);
                  set_stats("intelligence",15);
                  set_stats("constitution",16);
                  set_stats("dexterity",15);
                  set_stats("charisma",14);
                  set_mob_magic_resistance("average");
                  add_money("gold",random(25));
                  set_short("A young female firbolg");
                  set_long("This tall young lady stands around ten "+
                     "feet tall, though her youthful heart-shaped "+
                     "face reveals her to be only a girl.  Her "+
                     "eyes are a sparkling "+MYEYES+" %^RESET%^"+
                     "%^CYAN%^that seem to hold the warmth of the "+
                     "sun in them, though she - like the older "+
                     "citizens of Lothwaite - seems distrustful of "+
                     "strangers.  Her "+MYHAIR+" hair %^RESET%^"+
                     "%^CYAN%^is worn loose about her shoulders "+
                     "until she reaches adulthood, when it will be "+
                     "braided.  She is dressed in a "+MYCOLOR+" "+
                     ""+MYTOP+" %^RESET%^%^CYAN%^above "+MYCOLOR2+" "+
                     ""+MYBOTTOM+"%^RESET%^%^CYAN%^, and her feet "+
                     "are bare.");
                  if(!random(2)){
                     switch(random(4)){
                        case 0:  new("/d/tharis/conforest/obj/daffodil")->move(TO);
                                 break;
                        case 1:  new("/d/tharis/conforest/obj/daisy")->move(TO);
                                 break;
                        case 2:  new("/d/tharis/conforest/obj/thistle")->move(TO);
                                 break;
                        case 3:  new("/d/tharis/conforest/obj/tulip")->move(TO);
                                 break;
                     }
                  }
                  break;
   default:  break;
   }
}