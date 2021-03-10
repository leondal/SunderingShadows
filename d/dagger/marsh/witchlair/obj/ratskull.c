#include <std.h>
#include "../witchlair.h"
#define WAIT_TIME 600
inherit ("/d/common/obj/armour/coif_leather");

int used_time;

void create() {
  ::create();
  set_name("ratskull");
  set_id(({ "skull", "rat skull", "rodent skull" }));
  set_short("%^BOLD%^%^WHITE%^R%^RESET%^a%^BOLD%^t "
"Sku%^RESET%^l%^BOLD%^l%^RESET%^");
  set_obvious_short("%^RESET%^%^WHITE%^a c%^BOLD%^ra"
"%^RESET%^c%^BOLD%^k%^RESET%^ed ro%^BOLD%^d%^RESET%^ent's "
"sk%^BOLD%^ul%^RESET%^l%^RESET%^");
  set_long("%^BOLD%^%^WHITE%^Not a scrap of meat remains on "
"this skull from a largish rodent, having been scraped or "
"scrubbed completely clean. Empty eye sockets stare out into "
"nothingness, spiderweb cracks leading down the canals. The base"
" has been removed, either cut or smashed away. This macabre "
"helmet would fit neatly over a small person's head, with the "
"top jaw coming to rest jutting out a few inches over the eyes. "
"A large %^BLACK%^crack %^WHITE%^trails from the base of the "
"left eye nearly to the nostrils.%^RESET%^");
  set_lore("%^BOLD%^%^WHITE%^Rumor tells of a peculiar goblin "
"roaming the lands near Shadow during early 730s SG. Known by "
"the name of Viik, he was in fact sent to this realm by his "
"hobgoblin masters from afar via portal, to pledge himself as "
"an assassin to the service of Cyric the Mad God. Accounts are"
" uncertain of his true fate, but it has lately been accepted "
"that he was enthralled by a witch residing in the Dagger "
"marshes. This repugnant, improvised piece of armor was "
"supposedly the only thing he carried with him from whatever "
"dark land he came from.");
  set_weight(5);
  set_value(1000);
  set_size(1);
  set_property("enchantment",3);
  set_property("no resize",1);
  set_property("damage resistance",2);
  set_wear((:TO,"wearit":));
  set_remove((:TO,"removeit":));
  add_action("headbutt_fun","headbutt");
}

int wearit(){
  tell_object(ETO,"%^BOLD%^%^WHITE%^You grin at the thought "
"of how damn fun it would be to %^RED%^headbutt "
"%^WHITE%^something right now!");
  tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s head "
"disappears under the empty stare of their new %^WHITE%^skull"
" %^BLACK%^helmet.",ETO);
  return 1;
}

int removeit(){
  tell_object(ETO,"%^BOLD%^%^WHITE%^You realize how uncomfor"
"tably exposed your head is without the skull protecting "
"it.");
  tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" looks around "
"uneasily after lifting the protective skull from over "
""+ETO->QP+" own head.",ETO);
  return 1;
}

void init(){
   ::init();
   if(living(ETO)){
     add_action("headbutt","headbutt");
   }
}
int headbutt(string str){
   string vict;
   object ob;
   if(!str){
     tell_object(ETO,"%^BOLD%^%^WHITE%^Whatcha wanna "
"headbutt?");
     return 1;
   }
   if(sscanf(str,"%s",vict) ==1){
     if(!(query_worn())){
       tell_object(ETO,"%^BOLD%^%^RED%^A raspy voice echoes"
" from the skull's empty depths: %^RESET%^%^WHITE%^Hey, put"
" it on before you do that!");
       return 1;
     }
         if(WAIT_TIME > (time() - used_time)){
       tell_object(ETO,"%^BOLD%^%^RED%^A raspy voice echoes"
" from the skull's empty depths: %^RESET%^%^WHITE%^Wait a"
" bit longer, smarty! You need to recover from last time!");
     return 1;
     }
         if(ob = present(vict,EETO)){
           if(living(ob)){
             switch(random(2)){
             case 0:
             tell_object(ETO,"%^BOLD%^%^BLACK%^You lower"
" your head and leap at "+ob->QCN+", but they manage to "
"avoid your lunge!\n"
"%^BOLD%^%^RED%^A raspy voice echoes from the skull's empty depths:"
" %^RESET%^%^WHITE%^You missed, you idiot!");
             tell_object(ob,"%^BOLD%^%^BLACK%^"+ETO->QCN+""
" lowers "+ETO->QP+" head and throws "+ETO->QP+"self at you,"
" but you manage to evade!");
             tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+""
" lowers "+ETO->QP+" head and leaps at "+ob->QCN+", but "
""+ob->QS+" manages to evade their attack!",({ETO,ob}));
             break;
             case 1:
             tell_object(ETO,"%^BOLD%^%^BLACK%^You lower"
"your head with a savage grin and scrape a foot across the"
"ground - it's time to bring the pain! You rush forward "
"and leap into the air toward "+ob->QCN+", %^RED%^slamming"
" %^BLACK%^into "+ob->QO+" like a living ballista bolt!");
             tell_object(ob,"%^BOLD%^%^BLACK%^"+ETO->QCN+""
" lowers "+ETO->QP+" head and throws "+ETO->QO+"self "
"through the air at you, %^RED%^slamming %^BLACK%^into you"
" with incredible force for such a small being!");
             tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+""
"lowers "+ETO->QP+" head and throws "+ETO->QO+"self "
"through the air at "+ob->QCN+", %^RED%^slamming %^BLACK%^"
"into "+ob->QO+"!",({ETO,ob}));
         ETO->use_stamina(roll_dice(1,6));
         ob->do_damage("torso",roll_dice(2,12));
         ob->set_paralyzed(roll_dice(1,6),
"%^RESET%^%^RED%^You're trying to recover from being "
"attacked by that little living battering ram!");
         used_time = time();
             break;
         }
       }
     return 1;
     }
   }
}
