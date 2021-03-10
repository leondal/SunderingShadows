//TOY_purpledragon.c - designed by Lurue, 
//coded by Circe for new Seneca 11/28/07
#include <std.h>

inherit OBJECT;

int squeeze;

void create(){
   ::create();
   set_name("stuffed purple dragon");
   set_id(({"dragon","dragon toy","stuffed dragon","stuffed purple dragon","purple dragon","stuffed animal","pink stuffed animal","stuffed animalz"})); //stuffed animalz is the id needed for loading into the store
   set_short("%^BOLD%^%^WHITE%^a stuffed toy in the shape of a "+
      "%^BOLD%^%^MAGENTA%^dr%^RESET%^%^MAGENTA%^a%^WHITE%^g"+
      "%^MAGENTA%^o%^BOLD%^n%^RESET%^ ");
   set_long(
@AVATAR
%^RESET%^Made out of textured doeskin, this small stuffed animal looks like a fierce %^BOLD%^%^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^WHITE%^r%^MAGENTA%^p%^BOLD%^le dr%^RESET%^%^MAGENTA%^a%^WHITE%^g%^MAGENTA%^o%^BOLD%^n %^RESET%^complete with %^BOLD%^%^MAGENTA%^pink wings %^RESET%^and%^MAGENTA%^%^BOLD%^ ridges %^RESET%^running along its back. Posed sitting up, its large %^MAGENTA%^%^BOLD%^pink wings %^RESET%^extend outward from the body while its head is lifted up in a mighty %^BOLD%^%^WHITE%^roar%^RESET%^. %^BLUE%^BOLD%^%^Blue buttons%^RESET%^ have been used for eyes and a %^BOLD%^%^BLACK%^black piece of yarn %^RESET%^has been sewn along the mouth turning up at the edges into a smile. Something about the cute little dragon makes you just want to %^BOLD%^%^MAGENTA%^<%^RESET%^squeeze%^BOLD%^%^MAGENTA%^>%^RESET%^ it.
AVATAR
   );
   set_weight(1);
   set_value(215);
}

void init(){
   ::init();
   add_action("squeeze_me","squeeze");
}

int squeeze_me(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   if (TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+TPQCN+" squeezes the soft "+
      "belly of the dragon and it goes%^RESET%^ ' %^BOLD%^"+
      "%^MAGENTA%^rar rar rar%^RESET%^ '",ETO);
   tell_object(TP,"%^BOLD%^%^WHITE%^You squeeze the soft belly "+
      "of the dragon and it goes%^RESET%^ ' %^BOLD%^%^MAGENTA%^"+
      "rar rar rar%^RESET%^ '");
   return 1;
}
