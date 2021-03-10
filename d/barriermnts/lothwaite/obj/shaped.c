#include <std.h>
#include "../lothwaite.h"

#define COLORS ({"%^BOLD%^%^WHITE%^white","%^RESET%^%^RED%^crimson","%^BOLD%^%^RED%^scarlet","%^RESET%^%^ORANGE%^taupe","%^YELLOW%^golden","%^RESET%^%^GREEN%^deep green","%^BOLD%^%^GREEN%^vibrant green","%^RESET%^%^CYAN%^sea green","%^BOLD%^%^CYAN%^sky blue","%^RESET%^%^BLUE%^midnight blue","%^BOLD%^%^BLUE%^royal blue","%^RESET%^%^MAGENTA%^violet","%^BOLD%^%^MAGENTA%^lilac","%^BOLD%^%^BLACK%^black"})

#define DESIGNS ({"antelope","eagle","osprey","unicorn","owl","otter","frog","squirrel","dog","rabbit","cat","hawk","falcon","raven","wolf","lion","panther","leopard","rose","cheetah","horse","spider","fish","turtle","snake","doe","stag","dolphin","whale","sphinx","tiger","lizard","pegasus","manticore","hydra","griffon","pony","dragonfly","bear","basilisk","cockatrice","robin","sparrow","fox","nightingale","raccoon","jaguar","hyena","salamander","scorpion","swan","vulture","condor","crow","smilodon","centaur","chimera","gargoyle","mermaid","hippogriff","imp","kirre","lamia","wemic","lammasu","butterfly","mouse","moose","minotaur","peryton","roc","satyr","selkie","sprite","worg","winter wolf","wyvern","leprechaun","alligator","peacock","grasshopper","tree","crescent moon"})

inherit OBJ"candle_inherit";

int j,l;
string str,COLOR,VAR;

void create()
{
   ::create();
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
	l = random(sizeof(DESIGNS));
	str = DESIGNS[l];
      VAR = "a";
      if(str == "antelope" || str == "eagle" || str == "osprey" || str ==
         "owl" || str == "oriole" || str == "otter") {
         VAR = "an";
      }
	set_value(100+random(75));
      set_cointype("gold");
	set_name("a "+COLOR+" "+str+" candle%^RESET%^");
	set_short("a "+COLOR+" "+str+" candle%^RESET%^");
	set_id(({"candle",""+COLOR+" candle",""+str+" candle","shaped","shaped candle"}));
      if(str == "rose" || str == "tree" || str == "crescent moon"){
         set_long("This unique candle is made of the highest quality "+
            "wax that has been dyed a "+COLOR+" shade%^RESET%^.  The "+
            "candle has been shaped into the image of a %^BOLD%^"+
            ""+str+"%^RESET%^, so finely detailed as to look "+
            "almost real.  Each line is smooth and molded perfectly.  "+
            "The top of the "+str+" reveals the wick, which has been "+
            "dyed "+COLOR+" %^RESET%^to match the candle, cleverly "+
            "hiding it.  Despite its decorative uses, you may also "+
            "light this candle or douse it when you are finished.");
      }else{
      set_long("This unique candle is made of the highest quality wax "+
         "that has been dyed a "+COLOR+" shade%^RESET%^.  The wax has "+
         "been shaped into the image of "+VAR+" %^BOLD%^"+str+""+
         "%^RESET%^, so finely detailed as to look very realistic.  "+
         "The %^BOLD%^"+str+" %^RESET%^even has eyes made of "+
         "%^BOLD%^g%^RESET%^l%^BOLD%^i%^RESET%^t%^BOLD%^t%^RESET%^"+
         "e%^BOLD%^r%^RESET%^i%^BOLD%^n%^RESET%^g semi-precious "+
         "%^CYAN%^gems%^RESET%^.  The top of the "+str+" "+ 
         "reveals the wick, which has been dyed "+COLOR+" %^RESET%^"+
         "to match the candle, cleverly hiding it.  Despite its "+
         "decorative uses, you may also light this candle or douse "+
         "it when you are finished.");
      }
      set_lore("Other than using it for decoration in homes or "+
         "temples, shaped candles are said to aid in certain "+
         "prayers.  A likeness of an animal or object pleasing "+
         "to a deity may burn during a prayer, which is believed "+
         "to draw the deity's attention and grant further attenion "+
         "to the one praying.");
      set_property("lore difficulty",8);
	set_weight(3);
}
