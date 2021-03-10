//signet rings for Lothwaite - by Circe 6/21/04
#include <std.h>
#include <move.h>
#include <security.h>
#include "../lothwaite.h"
#include "signet_ring.h"

#define SYMBOLS ({"eagle","doe","rabbit","fox","lion","hawk","serpent","unicorn","oak","raven","phoenix","dragon","spider","web","bees","snowflake","griffon","scorpion","wolf","stag","bear","crown","jewel","panther","eye","dice","knight","rook"})

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
   write("%^GREEN%^Please choose the symbol you would like for your "+
      "ring from the list below.%^RESET%^\n");
   write("%^GREEN%^------------------------- %^YELLOW%^Symbols %^RESET%^%^GREEN%^-------------------------");
   write(
@CIRCE
   eagle       doe        rabbit      fox
   lion        hawk       serpent     unicorn
   oak         raven      phoenix     dragon
   spider      web        bees        snowflake
   griffon     scorpion   wolf        stag
   bear        crown      jewel       panther
   eye         dice       knight      rook   
CIRCE
   );
   input_to("mysymbol");
}

int mysymbol(string str){
   if(!str){
      write("%^BOLD%^You must choose a symbol for your ring from the "+
         "list below!  If you wish to cancel your order, use **.");
      write("%^GREEN%^------------------------- %^YELLOW%^Symbols %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   eagle       doe        rabbit      fox
   lion        hawk       serpent     unicorn
   oak         raven      phoenix     dragon
   spider      web        bees        snowflake
   griffon     scorpion   wolf        stag
   bear        crown      jewel       panther
   eye         dice       knight      rook   
CIRCE
      );
      input_to("mysymbol");
      return 1;
   }
   if(str == "**"){
      return exit();
   }
   if(member_array(str,SYMBOLS) == -1){
      write("%^BOLD%^%^RED%^That is not a valid symbol!\n");
      write("%^BOLD%^Please choose the symbol you would like on your ring.\n"+
      "You may choose any of the following.  Use ** to cancel "+
      "your order.%^RESET%^\n\n");
      write("%^GREEN%^------------------------- %^YELLOW%^Symbols %^RESET%^%^GREEN%^-------------------------");
      write(
@CIRCE
   eagle       doe        rabbit      fox
   lion        hawk       serpent     unicorn
   oak         raven      phoenix     dragon
   spider      web        bees        snowflake
   griffon     scorpion   wolf        stag
   bear        crown      jewel       panther
   eye         dice       knight      rook   
CIRCE
      );
      input_to("mysymbol");
      return 1;
   }
   switch(str){
      case "eagle":  str = "a soaring %^BOLD%^bald eagle %^RESET%^in flight";
                     break;
      case "doe":  str = "a %^RESET%^%^ORANGE%^gentle doe %^RESET%^standing peacefully";
                   break;
      case "rabbit":  str = "a small %^BOLD%^rabbit%^RESET%^";
                      break;
      case "fox":  str = "a %^RESET%^%^RED%^sly fox%^RESET%^";
                   break;
      case "lion":  str = "a proud %^YELLOW%^lion %^RESET%^with a "+
                       "%^ORANGE%^majestic mane%^RESET%^";
                   break;
      case "hawk":  str = "a wheeling %^RED%^hawk %^RESET%^gliding on "+
                       "the %^CYAN%^winds%^RESET%^";
                   break;
      case "serpent":  str = "a cunning %^GREEN%^serpent %^RESET%^coiled to strike";
                   break;
      case "unicorn":  str = "a proud %^BOLD%^unicorn %^RESET%^with her "+
                       "%^BOLD%^mane %^RESET%^rippling in the %^CYAN%^breeze%^RESET%^";
                   break;
      case "oak":  str = "an ancient %^GREEN%^oak tree %^RESET%^with spreading branches";
                   break;
      case "raven":  str = "a %^BOLD%^%^BLACK%^black-winged raven "+
                       "%^RESET%^floating on the winds";
                   break;
      case "phoenix":  str = "a %^BOLD%^%^RED%^fi%^YELLOW%^e%^RED%^ry "+
                       "phoenix %^RESET%^rising from the %^BOLD%^%^BLACK%^"+
                       "ashes%^RESET%^";
                   break;
      case "dragon":  str = "a shrewd %^BOLD%^dragon %^RESET%^atop its "+
                       "%^YELLOW%^horde%^RESET%^";
                   break;
      case "spider":  str = "a furtive %^BOLD%^%^BLACK%^spider%^RESET%^";
                   break;
      case "web":  str = "a tangle of %^BOLD%^silver spider webs%^RESET%^";
                   break;
      case "bees":  str = "a swarm of five %^YELLOW%^bees %^RESET%^"+
                       "flying a %^CYAN%^diamond-shaped pattern%^RESET%^";
                   break;
      case "snowflake":  str = "a beautiful %^BOLD%^snowflake%^RESET%^";
                   break;
      case "griffon":  str = "a proud %^ORANGE%^griffon %^RESET%^with wings outspread";
                   break;
      case "scorpion":  str = "a glittering %^BOLD%^%^BLACK%^scorpion "+
                        "%^RESET%^with tail curled";
                   break;
      case "wolf":  str = "a howling %^BOLD%^%^BLACK%^wolf%^RESET%^";
                   break;
      case "stag":  str = "a majestic %^ORANGE%^stag%^RESET%^";
                   break;
      case "bear":  str = "a massive %^ORANGE%^bear %^RESET%^standing upright";
                   break;
      case "crown":  str = "a %^YELLOW%^golden crown %^RESET%^glittering "+
                         "with %^BOLD%^je%^CYAN%^we%^WHITE%^ls%^RESET%^";
                   break;
      case "jewel":  str = "a single flawless %^BOLD%^%^CYAN%^jewel%^RESET%^";
                   break;
      case "panther":  str = "a sleek %^BOLD%^%^BLACK%^black panther "+
                         "%^RESET%^with glittering %^BOLD%^%^GREEN%^eyes%^RESET%^";
                   break;
      case "eye":  str = "an open %^BOLD%^%^BLUE%^eye%^RESET%^";
                   break;
      case "dice":  str = "a pair of %^CYAN%^dice %^RESET%^with seven showing";
                   break;
      case "knight":  str = "a %^BOLD%^noble knight %^RESET%^chess piece";
                   break;
      case "rook":  str = "a %^BOLD%^%^BLACK%^solid rook %^RESET%^chess piece";
                   break;
   }
   WF(MYSYMBOL1(str));
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
   return 1;
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
   WF(SYM);
   WF(MYSEAL7);
   WF(SEAL);
   ob = new(FILE);
   if(ob->move(TP) != MOVE_OK){
      ob->move(ETP);
   }
   write("Edric finishes your ring and gives it to you.");
   TO->remove();
   return;
}