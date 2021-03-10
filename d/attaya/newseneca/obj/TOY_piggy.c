//TOY_purpledragon.c - designed by Lurue, 
//coded by Circe for new Seneca 11/28/07
#include <std.h>

inherit OBJECT;

int squeeze;

void create(){
   ::create();
   set_name("stuffed purple dragon");
   set_id(({"pig","pig toy","stuffed pig","stuffed piggy","piggy toy","stuffed animal","pink stuffed animal","piggy","piglet","stuffed animalz"})); //stuffed animalz is the id needed for loading into the store
   set_short("%^BOLD%^%^WHITE%^a stuffed %^MAGENTA%^piggy%^WHITE%^ toy%^RESET%^");
   set_long(
@AVATAR
%^BOLD%^%^WHITE%^Made from soft velvet material dyed a %^MAGENTA%^bright pink %^WHITE%^color, this little stuffed animal is in the shaped like a cute little %^MAGENTA%^piglet%^WHITE%^.  Standing on all fours, this porky little guy is filled to bursting with cotton padding that makes him look roly-poly.  A curly little corkscrew tail made of stiffened %^MAGENTA%^pink yarn %^WHITE%^juts from his rear end while two lopsided triangles of %^MAGENTA%^pink felt %^WHITE%^extend from the top of his head.  %^BLACK%^Black buttons %^WHITE%^have been used for eyes and nose, while %^RED%^red yarn %^WHITE%^has been used to fashion his mouth. Something about the cute little piggy makes you just want to %^BOLD%^%^MAGENTA%^<%^WHITE%^squeeze%^BOLD%^%^MAGENTA%^>%^WHITE%^ it.
AVATAR
   );
   set_weight(1);
   set_value(230);
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
      "belly of the piggy and it goes%^RESET%^ ' %^BOLD%^"+
      "%^MAGENTA%^oink oink%^RESET%^ '",ETO);
   tell_object(TP,"%^BOLD%^%^WHITE%^You squeeze the soft belly "+
      "of the piggy and it goes%^RESET%^ ' %^BOLD%^%^MAGENTA%^"+
      "oink oink%^RESET%^ '");
   return 1;
}
