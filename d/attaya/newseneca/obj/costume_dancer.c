//costume_belly dancer.c - belly dancer costume for new Seneca
//~Circe~ 12/22/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

#define COLORS ({"violet","sapphire","saffron","crimson","ivory","ebony"})

void create(){
string color,COLOR;
   ::create();
   color = COLORS[random(sizeof(COLORS))];
   switch(color){
      case "violet": COLOR = "%^RESET%^%^MAGENTA%^"; break;
      case "sapphire": COLOR = "%^BOLD%^%^BLUE%^"; break;
      case "saffron": COLOR = "%^YELLOW%^"; break;
      case "crimson": COLOR = "%^BOLD%^%^RED%^"; break;
      case "ivory": COLOR = "%^BOLD%^%^WHITE%^"; break;
      case "ebony": COLOR = "%^BOLD%^%^BLACK%^"; break;
      default: COLOR = "broken!"; break;
   }
   set_name("belly dancer costume");
   set_id(({"costume","belly dancer costume","Belly Dancer Costume","exotic belly dancer costume","dancer costume","exotic costume",""+color+" belly dancer costume"}));
   set_short(""+COLOR+"exotic "+color+" belly dancer costume%^RESET%^");
   set_long("%^RESET%^%^CYAN%^Very little fabric has gone into the "+
      "creation of this exotic costume.  A flowing divided skirt "+
      "made of sheer "+COLOR+""+color+" fabric %^RESET%^%^CYAN%^"+
      "is gathered at the ankles, the curves of the wearer's legs "+
      "clearly visible.  A belt of %^ORANGE%^golden coins %^CYAN%^"+
      "is sewn around the hip, jingling lightly with movement.  "+
      "A tiny top is provided as well, made of slightly thicker "+
      ""+COLOR+""+color+" material %^RESET%^%^CYAN%^and sewn with "+
      "matching %^ORANGE%^coins%^CYAN%^.  Completing the costume is "+
      "the sheer "+COLOR+"veil%^RESET%^%^CYAN%^ designed to be worn "+
      "over the lower half of the wearer's face, revealing only the "+
      "eyes.%^RESET%^");
   set_costume_type(""+COLOR+"exotic belly dancer");
   set_costume("costume");
   set_value(450);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}