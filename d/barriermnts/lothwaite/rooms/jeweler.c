//jeweler.c - for Lothwaite  Circe 6/21/04
#include <std.h>
#include "../lothwaite.h"
#include <move.h>
inherit VAULT;

#define NUMBERS ({"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18"})

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Winds of Fortune Jewelry");
   set_short("Winds of Fortune Jewelry");
   set_long("%^ORANGE%^This huge shop features walls made of %^RESET%^"+
      "wattle%^ORANGE%^ packed with mud to provide protection from "+
      "the %^CYAN%^bitter winds%^ORANGE%^ that rip through the "+
      "%^GREEN%^valley%^ORANGE%^.  The bottom of the outside walls "+
      "are made of dry-fitted %^RESET%^stone%^ORANGE%^.  The "+
      "%^RED%^dirt floor %^ORANGE%^is covered with a layer of "+
      "%^GREEN%^rushes%^ORANGE%^, most likely pulled from the nearby "+
      "%^CYAN%^rivers %^ORANGE%^and %^CYAN%^lakes%^ORANGE%^.  "+
      "The wall of the shop facing the road has been fitted with "+
      "two large %^BOLD%^%^BLUE%^glass windows %^RESET%^%^ORANGE%^, "+
      "through which you can often see people passing by, looking "+
      "in at the %^YELLOW%^wooden counter %^RESET%^%^ORANGE%^"+
      "displaying the jewelry for sale here.  A large round "+
      "%^RED%^hearth %^ORANGE%^rises from the center of the floor, "+
      "and just behind it stands a massive %^YELLOW%^wooden "+
      "worktable %^RESET%^%^ORANGE%^covered with %^RESET%^tools "+
      "%^ORANGE%^used for jeweling.  A large %^RESET%^sign "+
      "%^ORANGE%^on the table displays the symbols that may "+
      "be used for signet rings.  Another wattle panel hides "+
      "the back of the shop from view and looks as though it "+
      "probably slides to lead to the shopkeeper's personal "+
      "quarters.%^RESET%^\n");
   set_items(([
      ({"walls","wall","wattle","wattle walls"}) : "%^ORANGE%^"+
         "The walls are made of wattle - woven panels of osier, or "+
         "willow, that have been packed with mud to seal the cracks "+
         "and keep out the wind.  The very bottom of the walls are "+
         "made of %^RESET%^stones %^ORANGE%^shaped to fit without "+
         "mortar.  The wall facing the road is set with two large "+
         "%^CYAN%^glass windows%^ORANGE%^.",
      ({"window","windows","glass","glass windows"}) : "%^CYAN%^"+
         "The front wall has two large glass windows that allow "+
         "passersby to glance in at the wares displayed below them.  "+
         "A large wooden counter takes up the front part of the shop, "+
         "showing off a collection of Edric's jewelry designs.  "+
         "The glass is rather thick and less than perfect, sporting "+
         "air bubbles and minor defects.",
      ({"floor","dirt floor","rushes"}) : "The dirt floor is covered "+
         "with a layer of rushes taken from the lake nearby.  The "+
         "rushes look to be changed ever so often to keep them "+
         "clean.  They add a slight grassy fragrance to the shop.",
      ({"counter","wooden counter","jewelry"}) : "The wooden counter "+
         "near the windows is long and tall, rising about eight feet "+
         "in the air.  Thankfully, a few narrow steps have been "+
         "built up to it so that those shorter than the firbolgs "+
         "in the village can climb up to view the wares.  The "+
         "jewelry is a mixture of wooden pendants and brooches "+
         "alongside more expensive bejewelled combs and signet rings.",
      ({"hearth","round hearth"}) : "The center of the shop is "+
         "dominated by a round, stone hearth, in which a %^BOLD%^"+
         "%^RED%^f%^YELLOW%^ir%^RED%^e %^RESET%^burns ceaselessly.  "+
         "An %^BOLD%^%^BLACK%^iron cauldron %^RESET%^is suspended "+
         "above it, with a stew bubbling lightly.",
      ({"table","worktable","wooden table","tools"}) : "On top of the "+
         "large wooden table are all manner of tools used in "+
         "jewelling, arranged carefully on racks.  Hammers, wire, "+
         "files, and the like are kept easily at hand for the "+
         "jeweler to create his works.  A large wooden crate has "+
         "many wooden molds carefully arranged, each with the name "+
         "of a single person etched into its side.",
      ({"sign","signet ring sign","large sign"}) : "The large sign "+
         "on the table has words painted on it in many different "+
         "languages.  They seem to list the %^BOLD%^symbols%^RESET%^, "+
         "%^RED%^weapons%^RESET%^, %^CYAN%^initials%^RESET%^, and "+
         "%^GREEN%^backgrounds %^RESET%^that may be chosen for signet "+
         "rings.  You may look at each to see them more closely.  "+
         "Near the bottom of the sign is painted the following in "+
         "large letters:\n\n"+
         "%^BOLD%^Here, you may <order> a signet ring or <reorder> "+
         "to replace a lost one.  Once you place your order, you "+
         "will never be able to order a different ring.  Please "+
         "make sure to look over the signs with %^BOLD%^symbols%^RESET%^, "+
         "%^RED%^weapons%^RESET%^, %^CYAN%^initials%^BOLD%^%^WHITE%^, and "+
         "%^GREEN%^backgrounds%^BOLD%^%^WHITE%^, and choose wisely.\n\n"+
         "\t%^BLUE%^First Ring%^WHITE%^: %^YELLOW%^2500 gold\n"+
         "\t%^BLUE%^Reorder Ring%^WHITE%^: %^YELLOW%^1500 gold%^RESET%^",
      ({"symbols","symbols sign"}) : (:TO,"symdesc":),
      ({"weapons","weapons sign"}) : (:TO,"weadesc":),
      ({"initials","initials sign"}) : (:TO,"inidesc":),
      ({"backgrounds","backgrounds sign"}) : (:TO,"bacdesc":)
   ]));
   set_smell("default","The light scent of grass mixes with the bubbling stew.");
   set_listen("default","The crackling of the fire seems soothing.");
   set_exits(([
      "north" : PATHEXIT"pathway24"
   ]));
   set_door("door",PATHEXIT"pathway24","north",0);
   set_door_description("door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
}

void reset(){
   ::reset();
   if(!present("edric")){
      new(MON"edric")->move(TO);
   }
}

void init(){
   ::init();
   add_action("order","order");
   add_action("reorder","reorder");
}

int order(string str){
object ob;
string file;
int i;
   if(!present("edric")){
      tell_object(TP,"The shopkeeper is not here to take your order!");
      return 1;
   }
   if(!str){
      tell_object(TP,"You may order signet rings here.  Please "+
         "try <order ring> or <order signet ring>.");
      return 1;
   }
   if(str != "ring" && str != "signet ring"){
      tell_object(TP,"You may only order signet rings here.  Please "+
         "try <order ring> or <order signet ring>.");
      return 1;
   }
   if(!TP->query_funds("gold",2500)){
      tell_room(TO,"%^MAGENTA%^Edric says with a thick rolling accent%^RESET%^: "+
         "I'm sorry, you seem to be a little short on money.  A ring "+
         "such as this will cost you 2500 gold.");
      return 1;
   }
   file = "/d/barriermnts/lothwaite/rings/"+TP->query_name()+".c";
   if(file_exists(file)){
      write("%^MAGENTA%^Edric says with a thick rolling accent"+
         "%^RESET%^: You have already "+
         "designed your signet ring.  You may "+
         "<reorder> it if you like.");
      return 1;
   }
   tell_object(TP,"What ring design would you like to order?  Enter "+
      "the design number 1-18.");
   write("%^GREEN%^------------------------- %^YELLOW%^Designs %^RESET%^%^GREEN%^-------------------------");
   write("\n"
"\t%^BOLD%^1 %^RESET%^- Symbol & Weapon on Background\n"
"\t%^BOLD%^2 %^RESET%^- Symbol & Initial on Background\n"
"\t%^BOLD%^3 %^RESET%^- Weapon & Initial on Background\n"
"\t%^BOLD%^4 %^RESET%^- Two Symbols on Background\n"
"\t%^BOLD%^5 %^RESET%^- Two Weapons on Background\n"
"\t%^BOLD%^6 %^RESET%^- Two Initials on Background\n"
"\t%^BOLD%^7 %^RESET%^- Symbol on Background\n"
"\t%^BOLD%^8 %^RESET%^- Weapon on Background\n"
"\t%^BOLD%^9 %^RESET%^- Initial on Background\n"
"\t%^BOLD%^10 %^RESET%^- Symbol & Weapon %^BOLD%^without %^RESET%^Background\n"
"\t%^BOLD%^11 %^RESET%^- Symbol & Initial %^BOLD%^without %^RESET%^Background\n"
"\t%^BOLD%^12 %^RESET%^- Weapon & Initial %^BOLD%^without %^RESET%^Background\n"
"\t%^BOLD%^13 %^RESET%^- Two Symbols %^BOLD%^without %^RESET%^Background\n"
"\t%^BOLD%^14 %^RESET%^- Two Weapons %^BOLD%^without %^RESET%^Background\n"
"\t%^BOLD%^15 %^RESET%^- Two Initials %^BOLD%^without %^RESET%^Background\n"
"\t%^BOLD%^16 %^RESET%^- Symbol %^BOLD%^without %^RESET%^Background\n"
"\t%^BOLD%^17 %^RESET%^- Weapon %^BOLD%^without %^RESET%^Background\n"
"\t%^BOLD%^18 %^RESET%^- Initial %^BOLD%^without %^RESET%^Background\n"
   );
   input_to("myring");
/*   ob = new("/d/barriermnts/lothwaite/rings/b_seal");
   tell_object(TP,"Edric takes your 2500 gold coins.");
   ob->set_file_name(file);
   ob->move(TP);
   TP->use_funds("gold",2500);
*/
   return 1;
}

void myring(string str){
object ob;
string file;
   if(!str){
      tell_object(TP,"You have failed to enter a design number.  "+
         "Try to order a ring again.");
      return 1;
   }
   if(member_array(str,NUMBERS) == -1){
      write("%^BOLD%^%^RED%^That is not a valid choice!\n");
      write("Please try to order your ring again.");
      return 1;
   }
   switch(str){
      case "1":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal1");
         break;
      case "2":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal2");
         break;
      case "3":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal3");
         break;
      case "4":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal4");
         break;
      case "5":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal5");
         break;
      case "6":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal6");
         break;
      case "7":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal7");
         break;
      case "8":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal8");
         break;
      case "9":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal9");
         break;
      case "10":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal10");
         break;
      case "11":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal11");
         break;
      case "12":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal12");
         break;
      case "13":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal13");
         break;
      case "14":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal14");
         break;
      case "15":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal15");
         break;
      case "16":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal16");
         break;
      case "17":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal17");
         break;
      case "18":  
         ob = new("/d/barriermnts/lothwaite/ring-inherits/b_seal18");
         break;
      default: 
         tell_object(TP,"That is not a valid choice.  Please try "+
            "to order your ring again.");
         break;
   }
   file = "/d/barriermnts/lothwaite/rings/"+TP->query_name()+".c";
   tell_object(TP,"Edric takes your 2500 gold coins.");
   ob->set_file_name(file);
   ob->move(TP);
   TP->use_funds("gold",2500);
}

int reorder(string str){
object ob;
string file;
string mname = ""+TP->query_name()+"";
   if(!present("edric")){
      tell_object(TP,"The shopkeeper is not here to take your order!");
      return 1;
   }
   if(!str){
      tell_object(TP,"You may <reorder ring> or <reorder signet ring>.");
      return 1;
   }
   if(str != "ring" && str != "signet ring"){
      tell_object(TP,"You may <reorder ring> or <reorder signet ring>.");
      return 1;
   }
   if(!TP->query_funds("gold",2500)){
      tell_room(TO,"%^MAGENTA%^Edric says with a thick rolling accent%^RESET%^: "+
         "I'm sorry, you seem to be a little short on money.  A ring "+
         "such as this will cost you 1500 gold.");
      return 1;
   }
   file = "/d/barriermnts/lothwaite/rings/"+TP->query_name()+".c";
   if(file_exists(file)){
      tell_object(TP,"Edric takes your 1500 gold coins.");
      ob = new("/d/barriermnts/lothwaite/rings/"+mname+".c");
      if(ob->move(TP) != MOVE_OK){
         ob->move(ETP);
      }
      write("Edric finishes your ring and gives it to you.");
      TP->use_funds("gold",1500);
      return 1;
   }else{
      tell_room(TO,"%^MAGENTA%^Edric says with a thick rolling accent%^RESET%^: "+
         "Sorry, you don't seem to have designed your ring yet.  You can "+
         "order a ring if you like.");
      return 1;
   }
}

void symdesc(){
   tell_object(TP,"%^GREEN%^------------------------- %^YELLOW%^Symbols %^RESET%^%^GREEN%^-------------------------%^RESET%^\n"
"\teagle - a soaring %^BOLD%^bald eagle %^RESET%^in flight\n"
"\tdoe - a %^RESET%^%^ORANGE%^gentle doe %^RESET%^standing peacefully\n"
"\trabbit - a small %^BOLD%^rabbit%^RESET%^\n"
"\tfox - a %^RESET%^%^RED%^sly fox%^RESET%^\n"
"\tlion - a proud %^YELLOW%^lion %^RESET%^with a "+
                       "%^ORANGE%^majestic mane%^RESET%^\n"
"\thawk - a wheeling %^RED%^hawk %^RESET%^gliding on "+
                       "the %^CYAN%^winds%^RESET%^\n"
"\tserpent - a cunning %^GREEN%^serpent %^RESET%^coiled to strike\n"
"\tunicorn - a proud %^BOLD%^unicorn %^RESET%^with her "+
                       "%^BOLD%^mane %^RESET%^rippling in the %^CYAN%^breeze%^RESET%^\n"
"\toak - an ancient %^GREEN%^oak tree %^RESET%^with spreading branches\n"
"\traven - a %^BOLD%^%^BLACK%^black-winged raven "+
                       "%^RESET%^floating on the winds\n"
"\tphoenix - a %^BOLD%^%^RED%^fi%^YELLOW%^e%^RED%^ry "+
                       "phoenix %^RESET%^rising from the %^BOLD%^%^BLACK%^"+
                       "ashes%^RESET%^\n"
"\tdragon - a shrewd %^BOLD%^dragon %^RESET%^atop its "+
                       "%^YELLOW%^horde%^RESET%^\n"
"\tspider - a furtive %^BOLD%^%^BLACK%^spider%^RESET%^\n"
"\tweb - a tangle of %^BOLD%^silver spider webs%^RESET%^\n"
"\tbees - a swarm of five %^YELLOW%^bees %^RESET%^"+
                       "flying a %^CYAN%^diamond-shaped pattern%^RESET%^\n"
"\tsnowflake - a beautiful %^BOLD%^snowflake%^RESET%^\n"
"\tgriffon - a proud %^ORANGE%^griffon %^RESET%^with wings outspread\n"
"\tscorpion - a glittering %^BOLD%^%^BLACK%^scorpion "+
                        "%^RESET%^with tail curled\n"
"\twolf - a howling %^BOLD%^%^BLACK%^wolf%^RESET%^\n"
"\tstag - a majestic %^ORANGE%^stag%^RESET%^\n"
"\tbear - a massive %^ORANGE%^bear %^RESET%^standing upright\n"
"\tcrown - a %^YELLOW%^golden crown %^RESET%^glittering "+
                         "with %^BOLD%^je%^CYAN%^we%^WHITE%^ls%^RESET%^\n"
"\tjewel - a single flawless %^BOLD%^%^CYAN%^jewel%^RESET%^\n"
"\tpanther - a sleek %^BOLD%^%^BLACK%^black panther "+
                         "%^RESET%^with glittering %^BOLD%^%^GREEN%^eyes%^RESET%^\n"
"\teye - an open %^BOLD%^%^BLUE%^eye%^RESET%^\n"
"\tdice - a pair of %^CYAN%^dice %^RESET%^with seven showing\n"
"\tknight - a %^BOLD%^noble knight %^RESET%^chess piece\n"
"\trook - a %^BOLD%^%^BLACK%^solid rook %^RESET%^chess piece\n"
   );
}

void weadesc(){
   tell_object(TP,"%^GREEN%^------------------------- %^YELLOW%^Weapons %^RESET%^%^GREEN%^-------------------------%^RESET%^\n"
"\tbattleaxe - a war-worn %^RED%^battleaxe%^RESET%^\n"
"\taxes - a pair of crossed %^GREEN%^wood axes%^RESET%^\n"
"\tlongsword - a slender %^BOLD%^longsword%^RESET%^\n"
"\tshort sword - a curving %^CYAN%^short sword%^RESET%^\n"
"\tdagger - an ornate %^BOLD%^%^BLACK%^dagger%^RESET%^\n"
"\twarhammer - a massive %^RED%^warhammer%^RESET%^\n"
"\tspears - a pair of crossed %^ORANGE%^spears%^RESET%^\n"
"\tmace - a %^BOLD%^spiked mace%^RESET%^\n"
"\tscepter - a regal %^YELLOW%^scepter%^RESET%^\n"
"\trapier - a slender, curving %^BOLD%^rapier%^RESET%^\n"
"\tflail - a vicious %^BOLD%^flail%^RESET%^\n"
"\tscimitar - an exotic %^CYAN%^scimitar%^RESET%^\n"
"\tquarterstaff - an aged %^ORANGE%^wooden quarterstaff%^RESET%^\n"
"\tbardiche - a vicious looking %^RED%^bardiche%^RESET%^\n"
"\tbastard sword - a massive %^BOLD%^bastard sword%^RESET%^\n"
"\tlance - a fine %^YELLOW%^lance %^RESET%^crossed "+
                      "over a %^ORANGE%^carved shield%^RESET%^\n"
"\twhip - a coiled %^BLUE%^scourge whip%^RESET%^\n"
"\ttrident - a heavily-carved %^CYAN%^trident%^RESET%^\n"
"\tgauntlet - a smooth %^BOLD%^steel gauntlet%^RESET%^\n"
"\tbook - an open %^ORANGE%^book%^RESET%^\n"
"\tscythe - a two-handed %^GREEN%^scythe %^RESET%^with blade raised\n"
"\tsickle - a wickedly curving %^ORANGE%^sickle%^RESET%^\n"
"\tmorning star - a solid %^YELLOW%^morning star%^RESET%^\n"
"\tbow - a curved %^ORANGE%^longbow %^RESET%^crossed "+
                    "with a quiver of %^BOLD%^arrows%^RESET%^\n"
"\tlute - a heavily-decorated %^ORANGE%^lute%^RESET%^\n"
   );
}

int inidesc(){
   tell_object(TP,"%^GREEN%^------------------------- %^YELLOW%^Initials %^RESET%^%^GREEN%^-------------------------%^RESET%^\n"
"\ta stylized %^CYAN%^A%^RESET%^\ta stylized %^CYAN%^J%^RESET%^\ta stylized %^CYAN%^S%^RESET%^\n"
"\ta stylized %^CYAN%^B%^RESET%^\ta stylized %^CYAN%^K%^RESET%^\ta stylized %^CYAN%^T%^RESET%^\n"
"\ta stylized %^CYAN%^C%^RESET%^\ta stylized %^CYAN%^L%^RESET%^\ta stylized %^CYAN%^U%^RESET%^\n"
"\ta stylized %^CYAN%^D%^RESET%^\ta stylized %^CYAN%^M%^RESET%^\ta stylized %^CYAN%^V%^RESET%^\n"
"\ta stylized %^CYAN%^E%^RESET%^\ta stylized %^CYAN%^N%^RESET%^\ta stylized %^CYAN%^W%^RESET%^\n"
"\ta stylized %^CYAN%^F%^RESET%^\ta stylized %^CYAN%^O%^RESET%^\ta stylized %^CYAN%^X%^RESET%^\n"
"\ta stylized %^CYAN%^G%^RESET%^\ta stylized %^CYAN%^P%^RESET%^\ta stylized %^CYAN%^Y%^RESET%^\n"
"\ta stylized %^CYAN%^H%^RESET%^\ta stylized %^CYAN%^Q%^RESET%^\ta stylized %^CYAN%^Z%^RESET%^\n"
"\ta stylized %^CYAN%^I%^RESET%^\ta stylized %^CYAN%^R%^RESET%^\n"
   );
}

int bacdesc(){
   tell_object(TP,"%^GREEN%^---------------------- %^YELLOW%^Backgrounds %^RESET%^%^GREEN%^-----------------------%^RESET%^\n"
"\twaterfall - a serene, cascading %^CYAN%^waterfall%^RESET%^\n"
"\tforest - a vast %^GREEN%^hardwood forest%^RESET%^\n"
"\tvalley - a wide, %^BOLD%^%^GREEN%^peaceful vale%^RESET%^\n"
"\tmountains - %^ORANGE%^rocky mountains %^RESET%^"+
                   "rising against the %^CYAN%^sky%^RESET%^\n"
"\tdesert - a wide, %^ORANGE%^sandy desert %^RESET%^"+
                   "braced by tall %^YELLOW%^dunes%^RESET%^\n"
"\tcity - a sprawling %^BOLD%^walled city %^RESET%^"+
                   "with a %^CYAN%^tower %^RESET%^rising high\n"
"\twheat field - a quiet %^GREEN%^wheat field %^RESET%^"+
                   "with a %^ORANGE%^farmhouse %^RESET%^nearby\n"
"\tcaves - a gaping %^BOLD%^%^BLACK%^cave %^RESET%^"+
                   "leading into the %^ORANGE%^mountainside%^RESET%^\n"
"\tdwarven city - the %^BOLD%^stone archways %^RESET%^of a dwarven city\n"
"\ttreetop village - the quiet peace of an elven "+
                   "%^GREEN%^treetop village%^RESET%^\n"
"\tevergreens - a dense %^GREEN%^evergreen forest%^RESET%^\n"
"\tocean - a %^ORANGE%^ship %^RESET%^dancing upon "+
                   "the %^CYAN%^ocean%^RESET%^\n"
"\tmonolith - a solitary %^BOLD%^monolith %^RESET%^"+
                   "in a flat %^GREEN%^field%^RESET%^\n"
"\tfull moon - a full risen %^BOLD%^moon %^RESET%^in a cloudless sky\n"
"\tcrescent moon - a pale %^BOLD%^%^BLACK%^crescent "+
                   "moon%^RESET%^ veiled by clouds\n"
"\tsteppe - a %^ORANGE%^sandy steppe %^RESET%^with "+
                   "a few patches of %^GREEN%^grass%^RESET%^\n"
"\tgrasslands - lush, flat %^BOLD%^%^GREEN%^grasslands "+
                   "%^RESET%^with a single %^GREEN%^tree %^RESET%^in the distance\n"
"\twinding path - a narrow %^ORANGE%^path %^RESET%^"+
                   "winding through rolling hills\n"
"\tjustice scales - the evenly balanced %^YELLOW%^"+
                   "scales of justice%^RESET%^\n"
"\tpyramid - an aged %^YELLOW%^pyramid %^RESET%^"+
                   "rising from the %^ORANGE%^desert%^RESET%^\n"
"\tivy - a simple border of tangled %^GREEN%^ivy%^RESET%^\n"
"\tflames - a writhing mass of %^BOLD%^%^RED%^fl"+
                   "%^YELLOW%^am%^RED%^es%^RESET%^\n"
"\ticeberg - a massive %^BOLD%^iceberg %^RESET%^"+
                   "rising out of the %^CYAN%^ocean%^RESET%^\n"
"\tsnowcapped peak - a lone %^ORANGE%^mountain "+
                   "%^RESET%^with a %^BOLD%^snowcapped peak%^RESET%^\n"
"\tmaze - an intricate %^BOLD%^maze %^RESET%^viewed from above\n"
"\tchess board - a finely crafted %^BOLD%^c%^BLACK%^h"+
                   "%^WHITE%^e%^BLACK%^s%^WHITE%^s board%^RESET%^\n"
"\tcastle - a sturdy %^BOLD%^castle %^RESET%^"+
                   "looming against the %^CYAN%^sky%^RESET%^\n"
   );
}