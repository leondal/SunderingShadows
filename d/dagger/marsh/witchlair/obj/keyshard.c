#include <std.h>
#include <move.h>
#include "../witchlair.h"
inherit OBJECT;

void create(){
   ::create();
   set_name("key shard");
   set_value(0);
   set_weight(1);
   set_id(({"shard"}));
   set_short("key shard");
   set_long("key shard");
}

void shard_pick(int which){
   if(!objectp(TO)) return;
   if(!intp(which)) return;
   if(which < 1) which = 1;
   if(which > 3) which = 3;
   switch(which){
     case 1:
       set_id(({"shard","shard1","silver shard","silvery shard","platinum shard"}));
       set_short("%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^WHITE%^v%^RESET%^e%^BOLD%^%^BLACK%^r%^WHITE%^y %^RESET%^s"
"%^BOLD%^%^BLACK%^h%^WHITE%^a%^RESET%^r%^BOLD%^%^BLACK%^d%^RESET%^");
       set_long("%^BOLD%^%^WHITE%^Roughly conical in shape, this"
" appears to be a mere %^RESET%^%^BLUE%^piece %^BOLD%^%^WHITE%^"
" of something more. It fits nicely in the palm of the average "
"man, almost like the grip of a dagger, though shorn in half. "
"Flecks of a different %^RESET%^%^MAGENTA%^m%^CYAN%^a"
"%^BOLD%^%^CYAN%^t%^RESET%^%^MAGENTA%^e%^CYAN%^r"
"%^BOLD%^%^CYAN%^i%^RESET%^%^MAGENTA%^a%^CYAN%^l "
"%^BOLD%^%^WHITE%^cling to the edges of it, as though it were"
" suddenly torn away from something %^RESET%^%^MAGENTA%^e"
"%^CYAN%^l%^BOLD%^%^CYAN%^s%^RESET%^%^MAGENTA%^e"
"%^BOLD%^%^WHITE%^. You suspect that if the rest of the "
"strange object were found, it could be %^YELLOW%^assemble"
"%^WHITE%^d.%^RESET%^");
       break;
     case 2:
       set_id(({"shard","shard2","violet shard","jasper shard"}));
       set_short("%^RESET%^%^MAGENTA%^v"
"%^BOLD%^%^MAGENTA%^io%^RESET%^%^MAGENTA%^l"
"%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^t ge"
"%^BOLD%^%^MAGENTA%^m%^RESET%^%^MAGENTA%^st"
"%^BOLD%^%^MAGENTA%^on%^RESET%^%^MAGENTA%^e sha"
"%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^d%^RESET%^");
       set_long("%^BOLD%^%^WHITE%^Roughly conical in shape, "
"this appears to be a mere %^RESET%^%^BLUE%^piece "
"%^BOLD%^%^WHITE%^of something more. It fits nicely in the "
"palm of the average man, almost like the grip of a dagger, "
"though shorn in half. Flecks of a different m%^RESET%^a"
"%^BOLD%^%^BLACK%^t%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^i"
"%^WHITE%^a%^RESET%^l %^BOLD%^cling to the edges of it, as "
"though it were suddenly torn away from something "
"%^RESET%^%^MAGENTA%^e%^CYAN%^l%^BOLD%^%^CYAN%^s"
"%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^. You suspect that if "
"the rest of the strange object were found, it could be "
"%^YELLOW%^assemble%^WHITE%^d.%^RESET%^");
       break;
     case 3:
       set_id(({"shard","shard3","chunk","mineral chunk",
"mineral shard"}));
       set_short("%^RESET%^%^CYAN%^an odd %^BOLD%^%^CYAN%^m"
"%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^e"
"%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^l "
"%^RESET%^%^CYAN%^chunk%^RESET%^");
       set_long("%^BOLD%^%^CYAN%^This is a rough, shimmering"
" piece of some stone that, for the life of you, you can't "
"seem to identify. About the size of a gold coin, the stone "
"itself is a smooth, light-blue material, similar in texture"
" to a river stone, and covered sparsely in a metallic-purple"
" dust that s%^RESET%^%^MAGENTA%^h%^BOLD%^%^MAGENTA%^i"
"%^WHITE%^m%^MAGENTA%^m%^RESET%^%^MAGENTA%^e"
"%^BOLD%^%^CYAN%^rs in the light. You suspect that if the "
"rest of the strange object were found, it could be "
"%^YELLOW%^assemble%^CYAN%^d.%^RESET%^");
       break;
     }
}

void init(){
   ::init();
   add_action("assemble_act","assemble");
}

int assemble_act(string what){
   object ob1,ob2,ob3, ob;
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(!objectp(ob1 = present("shard1", ETO))){
     tell_object(ETO,"%^BOLD%^%^CYAN%^You realize that this"
" object is not yet complete...");
     return 1;
   }
   if(!objectp(ob2 = present("shard2", ETO))){
     tell_object(ETO,"%^BOLD%^%^CYAN%^You realize that this"
" object is not yet complete...");
     return 1;
   }
   if(!objectp(ob3 = present("shard3", ETO))){
     tell_object(ETO,"%^BOLD%^%^CYAN%^You realize that this"
" object is not yet complete...");
     return 1;
   }
   ob = new(OBJ"key");
   tell_object(ETO,"%^BOLD%^%^CYAN%^You carefully place the"
" misshapen piece within a matching depression in one of the"
"shards, then press the other neatly againast it. With a "
"pulse of %^GREEN%^light %^CYAN%^and a brief "
"%^RESET%^%^BLUE%^c%^BOLD%^%^BLUE%^h%^CYAN%^i%^GREEN%^m"
"%^YELLOW%^i%^RED%^n%^MAGENTA%^g %^CYAN%^sound, the broken"
" pieces have merged together into their proper form.");
   if(!ETO->query_invis()){
     tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETO->QCN+" places"
" all of the shards together and is left with their "
"proper, intact form!",ETO);
   }
   if(ob->move(ETO) !=MOVE_OK){
     tell_object(ETO,""+ob->query_short()+" slips from "
"your grasp to the ground...");
     ob->move(EETO);
   }
   if(objectp(ob1) && ob1 != TO) ob1->remove();
   if(objectp(ob2) && ob2 != TO) ob2->remove();
   if(objectp(ob3) && ob3 != TO) ob3->remove();
   TO->remove();
   return 1;
}
