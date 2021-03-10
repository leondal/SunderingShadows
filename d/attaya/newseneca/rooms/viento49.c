//viento49 - Circe 11/10/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
/*
   set_long(::query_long()+"To the north is the grand marble "+
      "entryway to the %^BOLD%^Bard Academy%^RESET%^ while to "+
      "the south is a %^GREEN%^s%^RESET%^t%^GREEN%^r%^RESET%^i"+
      "%^GREEN%^p%^RESET%^e%^GREEN%^d %^GREEN%^a%^RESET%^w%^GREEN%^n"+
      "%^RESET%^i%^GREEN%^n%^RESET%^g above the entrance to "+
      "a fashionable %^CYAN%^restaurant%^RESET%^.  Hanging above "+
      "the door is a %^GREEN%^sign%^RESET%^ you might read.\n");
Return to this description when the Bard Academy opens
*/
   set_long(::query_long()+"To the north is the grand marble "+
      "entryway to the %^BOLD%^Bard Academy%^RESET%^, though "+
      "it seems to still be undergoing construction, while to "+
      "the south is a %^GREEN%^s%^RESET%^t%^GREEN%^r%^RESET%^i"+
      "%^GREEN%^p%^RESET%^e%^GREEN%^d %^GREEN%^a%^RESET%^w%^GREEN%^n"+
      "%^RESET%^i%^GREEN%^n%^RESET%^g above the entrance to "+
      "a fashionable %^CYAN%^restaurant%^RESET%^.  Hanging above "+
      "the door is a %^GREEN%^sign%^RESET%^ you might read.\n");
   set_exits(([
      "west" : ROOMS"wstreet37",
      "east" : ROOMS"viento50",
//      "north" : ROOMS"bard_entry",
      "south" : ROOMS"restaurant1"
   ]));
   set_door("restaurant door","/d/attaya/newseneca/rooms/restaurant1","south",0,0);
   set_door_description("restaurant door","%^RED%^The door to the south "+
      "is painted red and curved at the top.  Set near the top of the door "+
      "is a half-moon window allowing a tiny glimpse of the restaurant beyond.%^RESET%^");
   set_door("double doors","/d/attaya/newseneca/rooms/bard_entry","north",0);
   set_door_description("double doors","%^BOLD%^%^BLACK%^The building to the "+
      "north features double mahogany doors, each with a %^CYAN%^frosted "+
      "glass window %^BLACK%^filling half its length.  The glass is protected "+
      "by an elegant iron grill with a scrolling design.%^RESET%^");
   add_item("academy","%^BOLD%^The northern building features a beautiful "+
      "marble facade jutting out from the main building, forming a grand "+
      "entryway.  Stairs lead up to a pair of %^BLACK%^double mahogany "+
      "doors %^WHITE%^that open and close at all hours as aspiring musicians, "+
      "actors, poets, and artists enter and leave.%^RESET%^");
   add_item("bard academy","%^BOLD%^The northern building features a beautiful "+
      "marble facade jutting out from the main building, forming a grand "+
      "entryway.  Stairs lead up to a pair of %^BLACK%^double mahogany "+
      "doors %^WHITE%^that open and close at all hours as aspiring musicians, "+
      "actors, poets, and artists enter and leave.%^RESET%^");
   add_item("Bard Academy","%^BOLD%^The northern building features a beautiful "+
      "marble facade jutting out from the main building, forming a grand "+
      "entryway.  Stairs lead up to a pair of %^BLACK%^double mahogany "+
      "doors %^WHITE%^that open and close at all hours as aspiring musicians, "+
      "actors, poets, and artists enter and leave.%^RESET%^");
   add_item("restaurant","The building to the south is a small restaurant with "+
      "%^BOLD%^cream stucco walls %^RESET%^and a %^GREEN%^s%^RESET%^t%^GREEN%^r%^RESET%^i"+
      "%^GREEN%^p%^RESET%^e%^GREEN%^d %^GREEN%^a%^RESET%^w%^GREEN%^n"+
      "%^RESET%^i%^GREEN%^n%^RESET%^g above a %^RED%^red door%^RESET%^.  "+
      "It appears to be quite popular, as there are always well-dressed "+
      "customers coming and going.");
   add_item("sign","%^GREEN%^The sign to the south is painted a slightly "+
      "lighter shade of green than the stripes of the awning.  It features "+
      "a message in %^MAGENTA%^purple %^GREEN%^you might read.%^RESET%^");
}

void init(){
   ::init();
   add_action("read_em","read");
}

int read_em(string str){
   if(!str) return 0;
   if(str == "sign"){
      tell_object(TP,"\n"+
"%^RESET%^%^MAGENTA%^        __\n"+
" |  _. (_  _.._  _ ._%^GREEN%^o%^MAGENTA%^ _.\n"+
" |_(_| __)(_|| |(_|| |(_|\n"+
"                 _|\n"+
"\n"+
" %^BOLD%^%^RED%^@%^RESET%^%^GREEN%^}-%^ORANGE%^`%^GREEN%^--%^ORANGE%^,%^GREEN%^--%^ORANGE%^`%^GREEN%^--%^ORANGE%^,%^GREEN%^--%^ORANGE%^`%^GREEN%^--%^ORANGE%^,%^GREEN%^--%^ORANGE%^`%^GREEN%^--%^RESET%^\n"+
"\n"
      );
      if(!TP->query_invis() && !TP->query_hidden()){
         tell_room(TO,""+TPQCN+" seems to be studying the sign.");
      }
      return 1;
   }
}