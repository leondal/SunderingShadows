#include <std.h>
#include "../inherit/ruins.h"
inherit "/d/common/obj/armour/leather_gauntlets";

int birdtype;
object birdobject;

void create(){
        ::create();
        birdtype = random(4);
        set_name("dark leather gloves");
        set_id(({"gloves","Gloves","leather gloves","thick leather gloves","dark leather gloves","Windrider's call","windrider's call"}));
        set_short("%^BLACK%^%^BOLD%^Windrider's Call%^RESET%^");
        set_obvious_short("%^BOLD%^%^BLACK%^dark leather gloves%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^These dark gloves are made of thick, multi-layered leather, %^RESET%^%^ORANGE%^tanned %^BOLD%^%^BLACK%^and "
"treated on the outside, and smooth-lined inside.  They are thickened sufficiently to offer a small amount of protection to the hands from blows, "
"but are %^RESET%^%^CYAN%^comfortable %^BOLD%^%^BLACK%^enough to allow for unrestricted movement.  A complex series of buckles would let them be "
"tightened for a smaller hand, or loosened for one larger.  Upon the smooth inner lining of the left glove have been burnt several %^RESET%^"
"%^GREEN%^r%^BOLD%^u%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^%^GREEN%^s%^BOLD%^%^BLACK%^.%^RESET%^\n");
        set_value(5000);
        set_size(-1);
        set("read","%^WHITE%^%^BOLD%^For those with the true calling to the wild.\n"
"%^WHITE%^%^BOLD%^You can %^YELLOW%^<summon bird>%^WHITE%^ to call for a companion,\n"
"%^WHITE%^%^BOLD%^Or %^YELLOW%^<dismiss bird>%^WHITE%^ to return it to the skies.\n"
"%^WHITE%^%^BOLD%^It will only allow you to %^YELLOW%^<stroke>%^WHITE%^ its feathers.\n"
"%^WHITE%^%^BOLD%^Once tamed, you can %^YELLOW%^<sendto someone>%^WHITE%^ an item,\n"
"%^WHITE%^%^BOLD%^If it is small enough to be carried by your new friend.\n");
        set_language("elven");
        set_lore("%^WHITE%^%^BOLD%^These gloves are one of several relics of a long-since destroyed elven "
"village north of the Dagger Mountains.  The many ranger scouts each carried such a pair, which "
"together with their innate animal empathy allowed them to befriend a bird companion.  These birds were "
"often used to send as messengers between the ranger scouts.%^RESET%^");
        set_property("lore difficulty",21);
        set_wear((:TO,"wear_fun":));
        set_remove((:TO,"remove_fun":));
        if (query_property("summoned")) { remove_property("summoned"); }
        set_property("summoned",0);
}

void init(){
   ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
    add_action("summon_fun","summon");
}

void reset(){
   ::reset();
   if(living(ETO)) { if(!objectp(EETO)) return; }
   if(TO->query_worn() && !EETO->query_property("indoors") && !TO->query_property("summoned") && (string)ETO->query_name() == (string)TO->query_property("owner")) {
     if(random(4)) {
       switch(random(5)) {
         case 0:
         tell_room(EETO,"%^CYAN%^%^BOLD%^A bird circles far above you in the sky.%^RESET%^");
         break;
         case 1:
         tell_room(EETO,"%^ORANGE%^In the distance, a bird swoops down at something on the ground and "
"disappears from view.%^RESET%^");
         break;
         case 2:
         tell_room(EETO,"%^BLACK%^%^BOLD%^A dark shadow passes over you as a bird flies past "
"overhead.%^RESET%^");
         break;
         case 3:
         tell_room(EETO,"%^WHITE%^%^BOLD%^The dark shape of a bird glides low in the air, before "
"flapping higher again and vanishing behind a cloud.%^RESET%^");
         break;
         case 4:
         tell_room(EETO,"%^RED%^You hear a bird's cry somewhere nearby.%^RESET%^");
         break;
       }
     }
   }
}

int wear_fun(){
   if((int)ETO->query_level() < 15) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You need more training to use these gloves!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" can't seem to figure out how to use the gloves.",ETO);
     return 0;
   }
    if(!TO->query_property("owner")) {
        TO->set_property("owner",ETOQN);
    }
    if(TO->query_property("summoned")) {
      TO->remove_property("summoned");
      TO->set_property("summoned",0);
    }
    tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETO->QCN+" slides the thick gloves over "+ETO->QP+
" hands.%^RESET%^",ETO);
    tell_object(ETO,"%^WHITE%^%^BOLD%^You slide the thick gloves over your hands.%^RESET%^");
    return 1;
}

int remove_fun(){
    if(!objectp(TO)) { return 1; }
    if(!objectp(ETO)) { return 1; }
    if(!objectp(EETO)) { return 1; }
    if (objectp(birdobject)) {
      tell_room(EETO,"%^WHITE%^%^BOLD%^The bird spreads its wings and flies up into the sky.%^RESET%^");
      TO->remove_property("summoned");
      TO->set_property("summoned",0);
      birdobject->remove();
    }
    tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" slips the thick leather gloves from "+ETO->QP+
" hands.%^RESET%^",ETO);
    tell_object(ETO,"%^BLACK%^%^BOLD%^You slip the thick leather gloves from your hands.%^RESET%^");
    return 1;
}

int summon_fun(string str) {
    object ob;
    if(!TO->query_worn()) return notify_fail("You should try wearing the gloves first.\n");
    if(!str) return notify_fail("Summon what?\n");
    if(str != "bird") return notify_fail("Nothing happens.\n");
    if(!TO->query_property("owner") || (string)TP->query_name() != (string)TO->query_property("owner"))
      return notify_fail("Nothing happens.\n");
    if(EETO->query_property("indoors")) return notify_fail("You can't call for a bird while you're indoors!\n");
    if(present("glovebird")) return notify_fail("You have already called your bird here!\n");
    if(TO->query_property("summoned")) return notify_fail("You have already called your bird!\n");

    tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" holds out "+ETO->QP+" gloved hand and gives a series of "
"screeches and trills.  A few seconds later, a great bird swoops down from the sky to land on "+ETO->QP+
" hand!%^RESET%^",ETO);
    tell_object(ETO,"%^WHITE%^%^BOLD%^You hold out your gloved hand and give a series of screeches and "
"trills.  A few seconds later, a great bird swoops down from the sky to land on your hand!%^RESET%^");
    ob=new(MON+"glovebird.c");
    ob->move(EETO);
    switch(birdtype){
      case 0:
      ob->set_name("falcon");
      ob->set_id(({"bird","glovebird","falcon","black falcon"}));
      ob->set_short("%^BLACK%^%^BOLD%^Black falcon%^RESET%^");
      ob->set_long("%^BLACK%^%^BOLD%^This magnificent bird has jet-black feathers running from its "
"crown down its back, and along its broad wings and tailfeathers.  Sparkling yellow eyes are set above "
"its triangular, hooked beak.  Its feathers pale to a slight gray shade upon its underbelly, running "
"down to its two wickedly-clawed feet.%^RESET%^");
      ob->set_race("falcon");
      ob->set_gender("male");
      break;
      case 1:
      ob->set_name("kestrel");
      ob->set_id(({"bird","glovebird","kestrel","tawny kestrel"}));
      ob->set_short("%^RESET%^%^ORANGE%^Taw%^BLACK%^%^BOLD%^n%^RESET%^%^ORANGE%^y kes%^BLACK%^%^BOLD%^t%^RESET%^%^ORANGE%^rel%^RESET%^");
      ob->set_long("%^ORANGE%^This small, hawk-like bird has bright amber eyes that watch your every "
"move.  Both its hooked beak and its taloned feet look wickedly-sharp.  It has deep chestnut "
"underfeathers speckled with gray, and darker wings folded across its back.  Its head and tail are a "
"grayish hue, with bars across the tailfeathers.%^RESET%^");
      ob->set_race("kestrel");
      ob->set_gender("female");
      break;
      case 2:
      ob->set_name("owl");
      ob->set_id(({"bird","glovebird","owl","snowy owl"}));
      ob->set_short("%^WHITE%^%^BOLD%^Snowy owl%^RESET%^");
      ob->set_long("%^WHITE%^%^BOLD%^This majestic bird has a flat face, with a sharply curved beak.  It "
"peers at you with large, intelligent orange eyes that are overshadowed by thick-feathered brows.  Downy "
"feathers of a silvery sheen coat its underbelly, and a pair of thick white wings are folded over its "
"back.  A short fan of tailfeathers rest down behind its wickedly-taloned claws.%^RESET%^");
      ob->set_race("owl");
      ob->set_gender("male");
      break;
      case 3:
      ob->set_name("hawk");
      ob->set_id(({"bird","glovebird","hawk","golden hawk"}));
      ob->set_short("%^RESET%^%^ORANGE%^G%^YELLOW%^o%^RESET%^%^ORANGE%^ld%^YELLOW%^e%^RESET%^%^ORANGE%^n ha%^YELLOW%^w%^RESET%^%^ORANGE%^k%^RESET%^");
      ob->set_long("%^ORANGE%^This bird looks quite intelligent, peering at you with sharp eyes set "
"above a long, hooked beak.  Golden brown feathers coat its head and down its back, with lighter "
"feathers upon its underbelly and legs.  Its wings are folded at its sides, which when unfurled reveal "
"an impressive wingspan.  Its clawed feet look dangerously sharp, and a fan of long golden feathers form "
"its tail.%^RESET%^");
      ob->set_race("hawk");
      ob->set_gender("male");
      break;
    }
    TO->set_property("summoned",1);
    ob->set_property("glove",TO);
    ob->set_property("owner",TPQN);
    birdobject = ob;
    ETO->add_follower(ob);
    ETO->force_me("pose has a bird perched upon "+ETO->QP+" gloved hand");
    return 1;
}

void set_bird(int bird) {
   birdtype = bird;
}
