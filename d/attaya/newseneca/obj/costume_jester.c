//costume_jester.c - jester costume for new Seneca
//~Circe~ 12/23/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
string CLR,CLR2,CLR3,myname;
   ::create();
   switch(random(3)){
      case 0:  CLR = "%^BOLD%^%^BLUE%^cobalt";
               CLR2 = "%^YELLOW%^yellow";
               CLR3 = "%^BOLD%^%^RED%^scarlet";
               myname = "%^BOLD%^%^BLUE%^t%^YELLOW%^r%^RED%^i"+
                  "%^BLUE%^-%^YELLOW%^c%^RED%^o%^BLUE%^l%^YELLOW%^o"+
                  "%^RED%^r";
               break;
      case 1:  CLR = "%^RESET%^%^MAGENTA%^purple";
               CLR2 = "%^BOLD%^%^MAGENTA%^pink";
               CLR3 = "%^BOLD%^%^GREEN%^green";
               myname = "%^RESET%^%^MAGENTA%^t%^BOLD%^r%^GREEN%^i"+
                  "%^RESET%^%^MAGENTA%^-%^BOLD%^c%^GREEN%^o%^RESET%^"+
                  "%^MAGENTA%^l%^BOLD%^o%^GREEN%^r";
               break;
      default:  CLR = "%^BOLD%^%^WHITE%^white";
               CLR2 = "%^BOLD%^%^BLACK%^black";
               CLR3 = "%^BOLD%^%^RED%^crimson";
               myname = "%^BOLD%^%^WHITE%^t%^BLACK%^r%^RED%^i"+
                  "%^WHITE%^-%^BLACK%^c%^RED%^o%^WHITE%^l%^BLACK%^o"+
                  "%^RED%^r";
               break;
   }
   set_name("jester costume");
   set_id(({"costume","jester costume","Jester Costume","colorful jester costume","tri-color jester costume"}));
   set_short(""+myname+" jester costume%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This brilliant jester costume is made "+
      "from lengths of "+CLR+"%^RESET%^%^CYAN%^, "+CLR2+"%^RESET%^"+
      "%^CYAN%^, and "+CLR3+" fabric %^RESET%^%^CYAN%^sewn together "+
      "in alternating panels.  The collar is made of pointed "+
      "strips of "+myname+" fabrics%^RESET%^%^CYAN%^, each "+
      "point fitted with a %^YELLOW%^tiny bell%^RESET%^%^CYAN%^.  "+
      "Striped "+myname+" stockings %^RESET%^%^CYAN%^and matching "+
      "shoes in "+CLR+" %^RESET%^%^CYAN%^and "+CLR3+" %^RESET%^"+
      "%^CYAN%^with curved toes ending in %^YELLOW%^bells %^RESET%^"+
      "%^CYAN%^are provided to help finish the costume.  The "+
      "crowning piece, though, is a fantastically crafted hat "+
      "made in three curving sections in "+myname+" fabric "+
      "%^RESET%^%^CYAN%^with %^YELLOW%^bells %^RESET%^%^CYAN%^"+
      "that jingle with every movement.%^RESET%^");
   set_costume_type(""+myname+" jester");
   set_costume("costume");
   set_value(500);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}