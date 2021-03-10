#include <std.h>
#include "../inherit/ruins.h"
inherit "/d/common/obj/weapon/scimitar.c";

void create() {
   ::create();
   set_id(({ "scimitar","Scimitar","bladestaff scimitar","sword" }));
   set_name("scimitar");
   set_short("%^BLACK%^%^BOLD%^Me%^RESET%^%^WHITE%^g%^ORANGE%^i%^WHITE%^l'%^BLACK%^%^BOLD%^eh%^RESET%^%^WHITE%^a%^ORANGE%^l%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^er sc%^RESET%^%^WHITE%^i%^ORANGE%^mi%^WHITE%^t%^BLACK%^%^BOLD%^ar%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^ada%^RESET%^%^WHITE%^m%^WHITE%^%^BOLD%^an%^RESET%^%^WHITE%^t%^BOLD%^ium sc%^RESET%^%^WHITE%^i%^WHITE%^%^BOLD%^mi%^RESET%^%^WHITE%^t%^WHITE%^%^BOLD%^ar%^RESET%^");
   set_long("%^BLACK%^%^BOLD%^This scimitar has a strange handle, made of %^RESET%^%^ORANGE%^solid "
"wood%^BLACK%^%^BOLD%^, and more like the end of a thick staff than any common sword hilt.  A "
"crosspiece of the same wood is set just below where the blade is attached.  The blade itself is "
"adamantium, long and curved, and honed to a "
"%^WHITE%^ra%^RESET%^%^WHITE%^zo%^BLACK%^%^BOLD%^r-s%^RESET%^%^WHITE%^ha%^BOLD%^rp%^BLACK%^ "
"edge.%^RESET%^\n");
   set_value(750);
   set_lore("%^WHITE%^%^BOLD%^This sword is one of two that together form a unique style of two-ended "
"sword; an ancient elven artifact, it was only created within a small region of villages north of the "
"Dagger Mountains.  It was a weapon granted only to the most skilled of their kin, used by village "
"scouts with high expertise in the complex weapon's useage.  It was known as a bladestaff, "
"'megil'ehalaer' in the elven tongue.  Once separated, the wielder could socket the pair of scimitars "
"back together, which would return the two blades to their original double-edged form.%^RESET%^\n");
   set_property("lore difficulty",19);
   set_read("%^BOLD%^%^WHITE%^Part the twin blades with a simple %^CYAN%^twist%^WHITE%^,\n"
"And %^CYAN%^socket%^WHITE%^ them together with a flick of the wrist.\n");
   set_language("elven");
   set_weight(4);
   set_property("enchantment",3);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

void init() {
    ::init();
    if(living(ETO)) {
      add_action("socket_fun","socket");
    }
}

int wield_fun() {
   if((int)ETO->query_lowest_level() < 15) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You need more training to use this item!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" can't seem to figure out how to use the weapon.",ETO);
     return 0;
   }
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->query_cap_name()+" grasps the hilt of the scimitar with "
"practiced ease.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^You grasp the hilt of the scimitar with practiced ease.%^RESET%^");
   return 1;
}

int unwield_fun() {
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" spins the scimitar overhand and releases the "
"hilt.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^You spin the scimitar overhand and release the hilt.%^RESET%^");
   return 1;
}

int socket_fun(string str) {
   object ob1,ob2,*names;
   int i;
   if (ETO->query_bound() || EETO->query_unconscious() || EETO->query_paralyzed()) {
     ETO->send_paralyzed_message("info",ETO);
     return 0;
   }
   if (!str) {
     notify_fail("Socket what?\n");
     return 0;
   }
   if (member_array(str,TO->query_id()) == -1 && str != "scimitars") {
     notify_fail("You can't socket that.\n");
     return 0;
   }
   if ((int)ETO->query_lowest_level() < 15) {
     notify_fail("You can't figure out how to do that.\n");
     return 0;
   }
   if((ob2 = present("bladestaff scimitar",ETO)) && living(ETO) && ob2 != TO){
     ob1 = new(OBJ+"bladestaff.c");
     while((int)ob1->query_property("enchantment") != 3) {
       ob1->remove_property("enchantment");
       ob1->set_property("enchantment",3);
     }
     if (TO->query_identified()) {
       names = TO->query_identified();
       for (i=0;i<sizeof(names);i++) {
         ob1->add_identified(names[i]);
       }
     }
     else {
       if (ob2->query_identified()) {
         names = ob2->query_identified();
         for (i=0;i<sizeof(names);i++) {
           ob1->add_identified(names[i]);
         }
       }
     }
     if(ob2->query_property("soulbound") || TO->query_property("soulbound")) ob1->set_property("soulbound",1);
     tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" carefully fits the two scimitars together, forming a single two-edged sword!%^RESET%^\n",ETO);
     tell_object(ETO,"%^ORANGE%^You carefully socket the two scimitars together, forming a single two-edged sword!%^RESET%^");
     TO->move("/d/shadowgate/void");
     ob2->move("/d/shadowgate/void");
     ob1->move(TP);
     TP->force_me("wield bladestaff");
     ob2->remove();
     TO->remove();
     return 1;
   }
   notify_fail("There is only one blade here.\n");
   return 0;
}

int hit_fun(object target) 
{
    object ob;
    if(!objectp(target) || !objectp(ETO) || !objectp(EETO)) { return roll_dice(1,4); }
    if(!random(10)) 
    {
        if((ob = present("bladestaff scimitar",ETO)) && living(ETO) && ob != TO && ob->query_wielded()) 
        {
            ETO->execute_attack();
            tell_room(EETO,"%^CYAN%^%^BOLD%^"+ETOQCN+" twirls the twin scimitars at lightning "
                "speed, slashing back at "+target->QCN+" again!%^RESET%^",({ETO,target}));
            tell_object(ETO,"%^WHITE%^%^BOLD%^You twirl the scimitars, bringing up the second "
                "quickly after the first, to slash at "+target->QCN+" again!%^RESET%^");
            tell_object(target,"%^WHITE%^%^BOLD%^"+ETOQCN+" twirls the twin scimitars at lightning "
                "speed, slashing back at you again!%^RESET%^");
            return 1;
        }
    }
}
