//Monk statue for new Seneca - made an actual
//object to be more noticeable.  ~Circe~ 12/10/07
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("monk statue");
    set_id(({"monk statue","statue","statue of monk","stoic monk statue","Monk Statue"}));
    set_weight(1000000);
    set_short("%^BOLD%^%^WHITE%^A marble statue of a stoic monk%^MAGENTA%^");
    set_long("%^BOLD%^%^WHITE%^Depicted kneeling, this statue has "+
       "a quiet beauty.  It is carved from flawless white marble "+
       "that seems to glow no matter what light hits it.  The "+
       "statue is in the shape of a man in a simple, flowing "+
       "robe belted at the waist.  He is kneeling and sitting back "+
       "on his heels, the robe pushed up to reveal his bare feet "+
       "beneath.  His hands are crossed gently on his knees, and "+
       "his eyes are closed with a serene expression on his face.  "+
       "His hair is pulled back smoothly and tied back with a simple "+
       "cord before running in a single braid all the way down his "+
       "back, curling atop his feet like a rope.  A %^RESET%^%^ORANGE%^"+
       "plaque %^BOLD%^%^WHITE%^has been placed at the statue's base "+
       "for visitors to read.%^RESET%^");
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
@CIRCE
%^YELLOW%^-------------------------------------------------
%^YELLOW%^|         %^WHITE%^The Order of Altherian Monks          %^YELLOW%^|
%^YELLOW%^|                                               %^YELLOW%^|
%^YELLOW%^|        %^RESET%^%^ORANGE%^This brave order of stoic %^CYAN%^monks        %^YELLOW%^|
%^YELLOW%^|   %^RESET%^%^ORANGE%^were all but eliminated by the %^BOLD%^%^BLACK%^Kinnesaruda  %^YELLOW%^|
%^YELLOW%^|     %^RESET%^%^ORANGE%^in their rise to %^MAGENTA%^power%^ORANGE%^.  Here, they are   %^YELLOW%^|
%^YELLOW%^|    %^RESET%^%^ORANGE%^honored for their %^GREEN%^dedication %^ORANGE%^and %^CYAN%^service   %^YELLOW%^|
%^YELLOW%^|            %^RESET%^%^ORANGE%^to the people of %^BOLD%^%^WHITE%^Seneca%^RESET%^%^ORANGE%^.           %^YELLOW%^|
%^YELLOW%^|                                               %^YELLOW%^|
%^YELLOW%^|          %^WHITE%^Never Gone, Never Forgotten          %^YELLOW%^|
%^YELLOW%^-------------------------------------------------%^RESET%^
CIRCE
   );
   if(!TP->query_invis()){
      tell_room(ETO,""+TPQCN+" reads the plaque.",TP);
   }
   return 1;
}