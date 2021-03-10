//Kalimex statue for new Seneca - made an actual
//object to be more noticeable.  ~Circe~ 12/10/07
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("kalimex statue");
    set_id(({"kalimex statue","statue","statue of kalimex","Kalimex Statue","warrior statue"}));
    set_weight(1000000);
    set_short("%^BOLD%^%^WHITE%^A marble statue of a kilted warrior%^MAGENTA%^");
    set_long("%^BOLD%^%^WHITE%^Captured mid-whirl, this kilted "+
       "warrior is a force to be reckoned with.  He holds twin "+
       "scimitars, his left hand curved over his head while "+
       "his right whips around in front of his waist.  Cleverly "+
       "designed to be in mid-leap, only the toes of one sandaled "+
       "foot touch the statue's base, while the other is kicked up "+
       "behind him, flaring the pleated kilt he wears to his knees.  "+
       "His mouth is open in a battle shout, visible beneath his "+
       "blazing eyes - the only facial features to be seen through "+
       "the T-shaped openings in his helmet.  A crest of horse "+
       "hair bristles from the top, the tail whipping around with "+
       "the warrior's motion.  The only other protection offered the man "+
       "is a round chestguard fastened with leather straps.  A "+
       "%^RESET%^%^ORANGE%^plaque %^BOLD%^%^WHITE%^has been set "+
       "at the base of the statue for visitors to read.%^RESET%^");
    set_value(0);
    set_property("no animate",1);
}

void init(){
   ::init();
   add_action("read_em","read");
}

int read_em(string str){
   if(!str) return 0;
   if(!id(str) && str != "plaque") return 0;
   tell_object(TP,"You read the plaque at the statue's base:");
   tell_object(TP,
"%^YELLOW%^------------------------------------------------\n"+
"%^YELLOW%^|           %^WHITE%^Kalimex of the Oriaum Clan         %^YELLOW%^|\n"+
"%^YELLOW%^|                                              %^YELLOW%^|\n"+
"%^YELLOW%^|    %^RESET%^%^ORANGE%^Hailing from %^YELLOW%^Graez%^RESET%^%^ORANGE%^, the %^CYAN%^Oriaum Clan %^ORANGE%^sent  %^YELLOW%^|\n"+
"%^YELLOW%^|       %^RESET%^%^ORANGE%^their best %^BLUE%^warriors %^ORANGE%^to help defend     %^YELLOW%^|\n"+
"%^YELLOW%^|     %^WHITE%^Seneca %^RESET%^%^ORANGE%^against the threat of %^BOLD%^%^BLACK%^Intruder%^RESET%^%^ORANGE%^.   %^YELLOW%^|\n"+
"%^YELLOW%^|        %^RESET%^%^ORANGE%^Their leader, %^BOLD%^%^BLUE%^Kalimex%^RESET%^%^ORANGE%^, drove his      %^YELLOW%^|\n"+
"%^YELLOW%^|     %^RESET%^%^ORANGE%^fierce band into the very %^RED%^heart %^ORANGE%^of the   %^YELLOW%^|\n"+
"%^YELLOW%^|            %^BOLD%^%^BLACK%^Tower of the Black Dawn%^RESET%^%^ORANGE%^,          %^YELLOW%^|\n"+
"%^YELLOW%^|          %^RESET%^%^ORANGE%^from which he never returned.       %^YELLOW%^|\n"+
"%^YELLOW%^|                                              %^YELLOW%^|\n"+
"%^YELLOW%^|          %^WHITE%^Daunting Enemy, Fierce Ally         %^YELLOW%^|\n"+
"%^YELLOW%^------------------------------------------------%^RESET%^"
   );
   if(!TP->query_invis()){
      tell_room(ETO,""+TPQCN+" reads the plaque.",TP);
   }
   return 1;
}