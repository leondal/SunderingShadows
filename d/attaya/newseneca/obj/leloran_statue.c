//Leloran statue for new Seneca - made an actual
//object to be more noticeable.  ~Circe~ 12/10/07
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("leloran statue");
    set_id(({"leloran statue","statue","statue of leloran","Leloran Statue","elf statue"}));
    set_weight(1000000);
    set_short("%^BOLD%^%^WHITE%^A marble statue of a studious elf%^MAGENTA%^");
    set_long("%^BOLD%^%^WHITE%^Books in precarious stacks pile "+
       "around the slender feet of this male elf.  He holds an "+
       "ancient tome open in his slender hands, the pages rolling "+
       "and crumbling.  A tall staff rests in the crook of his arm, "+
       "and he leans upon it absently as he studies.  Flowing hair "+
       "restrained by a delicate circlet cascades down his back "+
       "to his waist, where his simple robes are gathered by a "+
       "silken rope belt.  Intelligence radiates from his elven "+
       "features, visible in his eyes, while even his pointed ears "+
       "seem alert.  His mouth is partly open, as if captured in "+
       "mid-speech as he studies the tome in his hands.  A "+
       "%^RESET%^%^ORANGE%^plaque%^BOLD%^%^WHITE%^ has been set "+
       "into the base of the statue for visitors to read.%^RESET%^");
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
%^YELLOW%^---------------------------------------------
%^YELLOW%^|              %^WHITE%^Leloran Mearlan              %^YELLOW%^|
%^YELLOW%^|                                           %^YELLOW%^|
%^YELLOW%^|     %^RESET%^%^ORANGE%^During the first war of %^BOLD%^%^BLACK%^Intruder%^RESET%^%^ORANGE%^,     %^YELLOW%^|
%^YELLOW%^|   %^RESET%^%^ORANGE%^he discovered the %^GREEN%^Terisenbold Journal%^ORANGE%^,  %^YELLOW%^|
%^YELLOW%^|     %^RESET%^%^ORANGE%^leading to %^RED%^weapons%^ORANGE%^ of great worth.    %^YELLOW%^|
%^YELLOW%^|   %^RESET%^%^ORANGE%^He lost his life to a nest of %^BOLD%^%^GREEN%^gorgons   %^YELLOW%^|
%^YELLOW%^|   %^RESET%^%^ORANGE%^not long after he recovered the spell   %^YELLOW%^|
%^YELLOW%^|             %^MAGENTA%^Incendiary Cloud%^RESET%^%^ORANGE%^.             %^YELLOW%^|
%^YELLOW%^|                                           %^YELLOW%^|
%^YELLOW%^|       %^WHITE%^Clever Mind, Steadfast Heart        %^YELLOW%^|
%^YELLOW%^---------------------------------------------
CIRCE
   );
   if(!TP->query_invis()){
      tell_room(ETO,""+TPQCN+" reads the plaque.",TP);
   }
   return 1;
}