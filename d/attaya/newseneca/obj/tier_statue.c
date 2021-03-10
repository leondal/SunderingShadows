//Tiergaina statue for new Seneca - made an actual
//object to be more noticeable.  ~Circe~ 12/9/07
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("tiergaina statue");
    set_id(({"tiergaina statue","statue","statue of tiergaina","woman statue","lithe woman statue","Tiergaina statue"}));
    set_weight(1000000);
    set_short("%^BOLD%^%^WHITE%^A marble statue of a lithe woman%^MAGENTA%^");
    set_long("%^BOLD%^%^WHITE%^This beautiful statue looks to have been "+
       "carved by a master.  The woman depicted is slender, and the stone "+
       "used to create her appears supple and smooth.  One delicate arm "+
       "is raised with a single finger pointing northward, while the other "+
       "arm cradles a mighty tome.  The intelligence captured upon her face "+
       "combine with the book to suggest a mage, yet she is dressed in a "+
       "most unusual fashion.  Her legs are clad in skin-tight pants that "+
       "have been carved so that the sides are open in a deep 'v' that reaches "+
       "almost to her knees, closed only with what look to be metal loops "+
       "sewn into the fabric.  Draped across her chest is what appears "+
       "to be a flimsy piece of material held on by simple carved chains "+
       "that cross in the back and are partially covered by her long, flowing "+
       "hair.  A %^RESET%^%^ORANGE%^plaque%^BOLD%^%^WHITE%^ has been set into the "+
       "base of the statue, inviting you to read it.%^RESET%^");
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
%^YELLOW%^------------------------------------------
%^YELLOW%^|       %^WHITE%^Tiergaina the Enchantress        %^YELLOW%^|
%^YELLOW%^|                                        |
%^YELLOW%^|   %^RESET%^%^ORANGE%^During the first War of Intruder     %^YELLOW%^|
%^YELLOW%^|         %^RESET%^%^ORANGE%^Defeated the %^BOLD%^%^BLACK%^Lich %^RESET%^%^ORANGE%^and          %^YELLOW%^|
%^YELLOW%^|       %^RESET%^%^ORANGE%^Uncovered the Lost Spells        %^YELLOW%^|
%^YELLOW%^|   %^GREEN%^Acid Arrow %^RESET%^%^ORANGE%^and %^BOLD%^%^CYAN%^Ray of Enfeeblement   %^YELLOW%^|
%^YELLOW%^|       %^RESET%^%^ORANGE%^Sworn Nemesis of %^MAGENTA%^Callista%^ORANGE%^,       %^YELLOW%^|
%^YELLOW%^|        %^RESET%^%^ORANGE%^The Intruder's Assassin         %^YELLOW%^|
%^YELLOW%^|                                        |
%^YELLOW%^|        %^WHITE%^Ever Curious, Ever Bold         %^YELLOW%^|
%^YELLOW%^------------------------------------------%^RESET%^
CIRCE
   );
   if(!TP->query_invis()){
      tell_room(ETO,""+TPQCN+" reads the plaque.",TP);
   }
   return 1;
}