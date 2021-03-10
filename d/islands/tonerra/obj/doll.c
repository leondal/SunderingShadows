//doll

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit OBJECT;

void create(){
   ::create();
   set_name("little doll");
   set_id(({"little doll","doll"}));
   set_short("A sneering little doll");
   set_long(
@OLI
   This doll has an annoying sneer on its face. You almost wish
that you could wipe the sneer off its face. But it is only
a doll, why should you be effected by it like this.
OLI
   );
   set_value("2000");
   set_weight(4500);
}

void init(){
   ::init();
   add_action("wipe","wipe");
}

int wipe(string str){
   if(!str) return 0;

   tell_object(TP,"As you wipe the sneer off the dolls face, it starts to look really pissed.");
   tell_room(ETP,"As "+TPQCN+" starts to wipe the sneer off the dolls face it starts to look really pissed.",TP);
   new(MON+"dexterity")->move(ETP);
   tell_room(ETP,"%^BOLD%^%^YELLOW%^OOOPS IT IS PISSED!!!");
   call_out("remove",1);
   return 1;
}

