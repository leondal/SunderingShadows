//signet rings for Lothwaite - by Circe 6/21/04
#include <std.h>
#include <move.h>
#include <security.h>
#include "../lothwaite.h"
#include "signet_ring.h"

#define WEAPONS ({"battleaxe","axes","longsword","short sword","dagger","warhammer","spears","mace","scepter","rapier","flail","scimitar","quarterstaff","bardiche","bastard sword","lance","whip","trident","gauntlet","book","scythe","sickle","morning star","bow","lute"})

#define LETTERS ({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"})

#define BACKGROUNDS ({"waterfall","forest","valley","mountains","desert","city",\
"wheat field","caves","dwarven city","treetop village","evergreens","ocean",\
"monolith","full moon","crescent moon","steppe","grasslands","winding path",\
"justice scales","pyramid","ivy","flames","iceberg","snowcapped peak","maze",\
"chess board","castle"})
inherit OBJECT;

string FILE;

void finish();

int save_me(string file){ return 1;}

void exit(){
   TP->add_money("gold",2500);
   tell_object(TP,"Edric returns your 2500 gold coins.");
   rm(FILE);
   remove();
}

void set_file_name(string f) {
    FILE = f;
}

void init(){
   ::init();
   seteuid(UID_RESTORE);
   WF(HEADER);
   WF(NAME);
   WF(ID);
   WF(SHORT);
   write("%^BOLD%^%^RED%^NOTE: %^WHITE%^Once you complete the order "+
      "for a ring, you will be unable to change the design - %^RED%^EVER"+
      "%^WHITE%^.  Be sure you choose something that fits your character.  "+
      "Use ** to cancel your order.%^RESET%^\n\n");
   write("%^BOLD%^Please choose the weapon you would like for your "+
      "ring from the list below.\n");
   write("%^GREEN%^------------------------- %^YELLOW%^Weapons %^RESET%^%^GREEN%^-------------------------");
   write(
@CIRCE
   battleaxe   axes       longsword   short sword
   dagger      warhammer  spears      mace
   scepter     rapier     flail       scimitar
   bardiche    lance      whip        quarterstaff
   trident     gauntlet   book        bastard sword
   scythe      sickle     bow         morning star
   lute
CIRCE
   );
   input_to("myweapon");
   return 1;
}

void myweapon(string str){
   if(!str){
   write("%^BOLD%^You must choose a weapon for your ring.  If you want "+
      "to cancel your order, use **.%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Weapons %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   battleaxe   axes       longsword   short sword
   dagger      warhammer  spears      mace
   scepter     rapier     flail       scimitar
   bardiche    lance      whip        quarterstaff
   trident     gauntlet   book        bastard sword
   scythe      sickle     bow         morning star
   lute
CIRCE
      );
      input_to("myweapon");
      return;
   }
   if(str == "**"){
      return exit();
   }
   if(member_array(str,WEAPONS) == -1){
      write("%^BOLD%^%^RED%^That is not a valid weapon!\n");
      write("%^BOLD%^Please choose the weapon you would like to have featured on your "+
      "ring from the following list.  Use ** to cancel your order.%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Weapons %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   battleaxe   axes       longsword   short sword
   dagger      warhammer  spears      mace
   scepter     rapier     flail       scimitar
   bardiche    lance      whip        quarterstaff
   trident     gauntlet   book        bastard sword
   scythe      sickle     bow         morning star
   lute
CIRCE
      );
      input_to("myweapon");
      return;
   }
   switch(str){
      case "battleaxe":  str = "a war-worn %^RED%^battleaxe%^RESET%^";
                         break;
      case "axes":  str = "a pair of crossed %^GREEN%^wood axes%^RESET%^";
                   break;
      case "longsword":  str = "a slender %^BOLD%^longsword%^RESET%^";
                   break;
      case "short sword":  str = "a curving %^CYAN%^short sword%^RESET%^";
                   break;
      case "dagger":  str = "an ornate %^BOLD%^%^BLACK%^dagger%^RESET%^";
                   break;
      case "warhammer":  str = "a massive %^RED%^warhammer%^RESET%^";
                   break;
      case "spears":  str = "a pair of crossed %^ORANGE%^spears%^RESET%^";
                   break;
      case "mace":  str = "a %^BOLD%^spiked mace%^RESET%^";
                   break;
      case "scepter":  str = "a regal %^YELLOW%^scepter%^RESET%^";
                   break;
      case "rapier":  str = "a slender, curving %^BOLD%^rapier%^RESET%^";
                   break;
      case "flail":  str = "a vicious %^BOLD%^flail%^RESET%^";
                   break;
      case "scimitar":  str = "an exotic %^CYAN%^scimitar%^RESET%^";
                   break;
      case "quarterstaff":  str = "an aged %^ORANGE%^wooden quarterstaff%^RESET%^";
                   break;
      case "bardiche":  str = "a vicious looking %^RED%^bardiche%^RESET%^";
                   break;
      case "bastard sword":  str = "a massive %^BOLD%^bastard sword%^RESET%^";
                   break;
      case "lance":  str = "a fine %^YELLOW%^lance %^RESET%^crossed "+
                      "over a %^ORANGE%^carved shield%^RESET%^";
                   break;
      case "whip":  str = "a coiled %^BLUE%^scourge whip%^RESET%^";
                   break;
      case "trident":  str = "a heavily-carved %^CYAN%^trident%^RESET%^";
                   break;
      case "gauntlet":  str = "a smooth %^BOLD%^steel gauntlet%^RESET%^";
                   break;
      case "book":  str = "an open %^ORANGE%^book%^RESET%^";
                   break;
      case "scythe":  str = "a two-handed %^GREEN%^scythe %^RESET%^with blade raised";
                   break;
      case "sickle":  str = "a wickedly curving %^ORANGE%^sickle%^RESET%^";
                   break;
      case "morning star":  str = "a solid %^YELLOW%^morning star%^RESET%^";
                   break;
      case "bow":  str = "a curved %^ORANGE%^longbow %^RESET%^crossed "+
                    "with a quiver of %^BOLD%^arrows%^RESET%^";
                   break;
      case "lute":  str = "a heavily-decorated %^ORANGE%^lute%^RESET%^";
                   break;
   }
   WF(MYWEAPON1(str));
   write("%^BOLD%^Please choose the initial you would like for your "+
      "ring from the list below.  Please make sure the letter you type "+
      "is in lowercase (it will be capitalized on the ring).  Use "+
      "** to cancel your order.\n");
   write("%^GREEN%^------------------------- %^YELLOW%^Initials %^RESET%^%^GREEN%^-------------------------");
   write(
@CIRCE
   a   b   c   d   e   f   g   h   i   j   k   l   m
   n   o   p   q   r   s   t   u   v   w   x   y   z
CIRCE
   );
   input_to("myinitial");
   return 1;
}

void myinitial(string str){
   if(!str){
      write("%^BOLD%^You must choose an initial for your ring.  If you want "+
         "to cancel your order, use **.%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Initials %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   a   b   c   d   e   f   g   h   i   j   k   l   m
   n   o   p   q   r   s   t   u   v   w   x   y   z
CIRCE
      );
      input_to("myinitial");
      return;
   }
   if(str == "**"){
      return exit();
   }
   if(member_array(str,LETTERS) == -1){
      write("%^BOLD%^%^RED%^That is not a valid letter!\n");
      write("%^BOLD%^Please choose the initial you would like to have featured on your "+
      "ring from the following list.  NOTE: make sure it is lowercase."+
      "  Use ** to cancel your order.%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Initials %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   a   b   c   d   e   f   g   h   i   j   k   l   m
   n   o   p   q   r   s   t   u   v   w   x   y   z
CIRCE
      );
      input_to("myinitial");
      return;
   }
   str = "a stylized %^CYAN%^"+capitalize(str)+"%^RESET%^";
   WF(MYINITIAL1(str));
   write("%^BOLD%^Please choose the background you would like for "+
      "your ring from the list below.  Use ** to cancel your order.\n");
   write("%^GREEN%^---------------------- %^YELLOW%^Backgrounds %^RESET%^%^GREEN%^-----------------------");
   write(
@CIRCE
   waterfall      forest         valley         mountains
   desert         city           caves          wheat field
   evergreens     ocean          monolith       dwarven city
   full moon      crescent moon  steppe         treetop village
   grasslands     winding path   pyramid        justice scales
   ivy            flames         iceberg        snowcapped peak
   maze           chess board    castle
CIRCE
   );
   input_to("bgchoice");
   return;
}

void bgchoice(string str){
   if(str == "**"){
      return exit();
   }
   if(member_array(str,BACKGROUNDS) == -1){
      write("%^BOLD%^%^RED%^That is not a valid background choice!\n");
      write("%^BOLD%^Please choose a background from the following list.\n\n");
      write("%^GREEN%^---------------------- %^YELLOW%^Backgrounds %^RESET%^%^GREEN%^-----------------------");
      write(
@CIRCE
   waterfall      forest         valley         mountains
   desert         city           caves          wheat field
   evergreens     ocean          monolith       dwarven city
   full moon      crescent moon  steppe         treetop village
   grasslands     winding path   pyramid        justice scales
   ivy            flames         iceberg        snowcapped peak
   maze           chess board    castle
CIRCE
      );
      input_to("bgchoice");
      return;
   }
   switch(str){
      case "waterfall":  str = "a serene, cascading %^CYAN%^waterfall%^RESET%^";
                   break;
      case "forest":  str = "a vast %^GREEN%^hardwood forest%^RESET%^";
                   break;
      case "valley":  str = "a wide, %^BOLD%^%^GREEN%^peaceful vale%^RESET%^";
                   break;
      case "mountains":  str = "%^ORANGE%^rocky mountains %^RESET%^"+
                   "rising against the %^CYAN%^sky%^RESET%^";
                   break;
      case "desert":  str = "a wide, %^ORANGE%^sandy desert %^RESET%^"+
                   "braced by tall %^YELLOW%^dunes%^RESET%^";
                   break;
      case "city":  str = "a sprawling %^BOLD%^walled city %^RESET%^"+
                   "with a %^CYAN%^tower %^RESET%^rising high";
                   break;
      case "wheat field":  str = "a quiet %^GREEN%^wheat field %^RESET%^"+
                   "with a %^ORANGE%^farmhouse %^RESET%^nearby";
                   break;
      case "caves":  str = "a gaping %^BOLD%^%^BLACK%^cave %^RESET%^"+
                   "leading into the %^ORANGE%^mountainside%^RESET%^";
                   break;
      case "dwarven city":  str = "the %^BOLD%^stone archways %^RESET%^of a dwarven city";
                   break;
      case "treetop village":  str = "the quiet peace of an elven "+
                   "%^GREEN%^treetop village%^RESET%^";
                   break;
      case "evergreens":  str = "a dense %^GREEN%^evergreen forest%^RESET%^";
                   break;
      case "ocean":  str = "a %^ORANGE%^ship %^RESET%^dancing upon "+
                   "the %^CYAN%^ocean%^RESET%^";
                   break;
      case "monolith":  str = "a solitary %^BOLD%^monolith %^RESET%^"+
                   "in a flat %^GREEN%^field%^RESET%^";
                   break;
      case "full moon":  str = "a full risen %^BOLD%^moon %^RESET%^in a cloudless sky";
                   break;
      case "crescent moon":  str = "a pale %^BOLD%^%^BLACK%^crescent "+
                   "moon%^RESET%^ veiled by clouds";
                   break;
      case "steppe":  str = "a %^ORANGE%^sandy steppe %^RESET%^with "+
                   "a few patches of %^GREEN%^grass%^RESET%^";
                   break;
      case "grasslands":  str = "lush, flat %^BOLD%^%^GREEN%^grasslands "+
                   "%^RESET%^with a single %^GREEN%^tree %^RESET%^in the distance";
                   break;
      case "winding path":  str = "a narrow %^ORANGE%^path %^RESET%^"+
                   "winding through rolling hills";
                   break;
      case "justice scales":  str = "the evenly balanced %^YELLOW%^"+
                   "scales of justice%^RESET%^";
                   break;
      case "pyramid":  str = "an aged %^YELLOW%^pyramid %^RESET%^"+
                   "rising from the %^ORANGE%^desert%^RESET%^";
                   break;
      case "ivy":  str = "a simple border of tangled %^GREEN%^ivy%^RESET%^";
                   break;
      case "flames":  str = "a writhing mass of %^BOLD%^%^RED%^fl"+
                   "%^YELLOW%^am%^RED%^es%^RESET%^";
                   break;
      case "iceberg":  str = "a massive %^BOLD%^iceberg %^RESET%^"+
                   "rising out of the %^CYAN%^ocean%^RESET%^";
                   break;
      case "snowcapped peak":  str = "a lone %^ORANGE%^mountain "+
                   "%^RESET%^with a %^BOLD%^snowcapped peak%^RESET%^";
                   break;
      case "maze":  str = "an intricate %^BOLD%^maze %^RESET%^viewed from above";
                   break;
      case "chess board":  str = "a finely crafted %^BOLD%^c%^BLACK%^h"+
                   "%^WHITE%^e%^BLACK%^s%^WHITE%^s board%^RESET%^";
                   break;
      case "castle":  str = "a sturdy %^BOLD%^castle %^RESET%^"+
                   "looming against the %^CYAN%^sky%^RESET%^";
                   break;
   }
   WF(MYBACK(str));
   finish();
}

void finish(){
object ob;
   WF(LONG);
   WF(WEIGHT);
   WF(VALUE);
   WF(AC);
   WF(LIMBS);
   WF(TYPE);
   WF(LORE);
   WF(LOREDIFF);
   WF(CLOSE);
   WF(WEA);
   WF(INI);
   WF(MYSEAL3);
   WF(SEAL);
   ob = new(FILE);
   if(ob->move(TP) != MOVE_OK){
      ob->move(ETP);
   }
   write("Edric finishes your ring and gives it to you.");
   TO->remove();
   return;
}
