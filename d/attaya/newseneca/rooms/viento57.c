//viento57 - Circe 11/17/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
   set_long(::query_long()+"North of here is a %^BOLD%^stone building "+
      "%^RESET%^with a %^GREEN%^tiled roof%^RESET%^, though there is no "+
      "door on this side.  To the south is a small %^BOLD%^%^RED%^shop "+
      "%^RESET%^with %^BOLD%^white trim%^RESET%^ that has a %^BOLD%^metal "+
      "sign %^RESET%^hanging near its door.\n");
   set_exits(([
      "west" : ROOMS"viento56",
      "east" : ROOMS"viento58",
      "south" : ROOMS"tattoo"
   ]));
   set_door("red door","/d/attaya/newseneca/rooms/tattoo","south",0,0);
   set_door_description("red door","Set within %^BOLD%^white trim %^RESET%^is "+
      "a blinding %^BOLD%^%^RED%^red door%^RESET%^ that leads into the building "+
      "to the south.");
   add_item("building","Solid stone walls topped with a %^GREEN%^tiled roof "+
      "%^RESET%^is all you can see of the building to the north.  Long, narrow, "+
      "glassless windows have been set near the top of the wall, just below the "+
      "roof.");
   add_item("shop","The building to the south is hard to miss, though it is "+
      "quite small.  Its walls are %^BOLD%^%^RED%^fiery red %^RESET%^set off "+
      "with %^BOLD%^glistening white trim%^RESET%^.  There is a %^BOLD%^metal "+
      "sign %^RESET%^hanging near the door you could read.");
   add_item("sign","The rectangular metal sign hanging near the door of the "+
      "shop to the south has a message punched into it."); 
   add_item("metal sign","The rectangular metal sign hanging near the door of the "+
      "shop to the south has a message punched into it."); 
}

void init(){
   ::init();
   add_action("read_em","read");
}

int read_em(string str){
   if(!str) return 0;
   if(str == "sign" || str == "metal sign"){
      tell_object(TP,"\n"+
"%^BOLD%^ +---------------------------+\n"+
" |                           |\n"+
" |   +-+-+-+-+-+-+-+-+-+-+   |\n"+
" |   |%^CYAN%^G%^WHITE%^|%^CYAN%^n%^WHITE%^|%^CYAN%^o%^WHITE%^|%^CYAN%^m%^WHITE%^|%^CYAN%^e%^WHITE%^|%^CYAN%^w%^WHITE%^|%^CYAN%^o%^WHITE%^|%^CYAN%^r%^WHITE%^|%^CYAN%^k%^WHITE%^|%^CYAN%^s%^WHITE%^|   |\n"+
" |   +-+-+-+-+-+-+-+-+-+-+   |\n"+
" |                           |\n"+
" |      +-+-+-+-+-+-+-+      |\n"+
" |      |%^CYAN%^T%^WHITE%^|%^CYAN%^a%^WHITE%^|%^CYAN%^t%^WHITE%^|%^CYAN%^t%^WHITE%^|%^CYAN%^o%^WHITE%^|%^CYAN%^o%^WHITE%^|%^CYAN%^s%^WHITE%^|      |\n"+
" |      +-+-+-+-+-+-+-+      |\n"+
" |                           |\n"+
" +---------------------------+\n"+
"%^RESET%^\n"
      );
      if(!TP->query_invis() && !TP->query_hidden()){
         tell_room(TO,""+TPQCN+" seems to be studying the sign.");
      }
      return 1;
   }
}