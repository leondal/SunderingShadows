#include <std.h>
inherit "/d/common/obj/weapon/battle_axe.c";

int counter;

void create(){
   ::create();
   set_id(({"axe","dragon slayer","battle axe","medium axe","dragonbane"}));
   set_name("dragonbane");
   set_obvious_short("A razor sharp battle axe");
   set_short("%^BOLD%^%^RED%^Drag%^RESET%^o%^BOLD%^%^RED%^nbane%^RESET%^");
   set_long(
      "%^BOLD%^%^RED%^This axe was forged with the highest quality of mithril"+
      " you have ever laid eyes on. The handle is made of finely carved redwood"+
      " and the handle is laced in red leather rings to match the color"+
      " of the handle. The mithril axe head is set into the top of the"+
      " handle and is fashioned with a crescent blade on each side."+
      " The axe holds no evidence of previous battle use. Not even the"+
      " wooden handle contains a single scratch and the blade gleams in the light"+
   " as if it had just been polished."
   );
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_property("lore difficulty",15);
   set_value(17550);
   set_wield((:TO,"wieldit":));
   set_hit((:TO,"hitit":));
   set_unwield((:TO,"unwieldit":));
   set_item_bonus("damage bonus",2);
   set_lore(
      "This axe has an intresting history. Hundreds of years ago, Kraken Battleshield, a dwarf from the old dwarven empire Barindor, made this axe with the help of a half-elven mage in hopes stopping Klauth from terrorizing an elven settlement on the surface. Unknown to the creators of the axe, Klauth was scrying them the whole time and obliterated the party the day they came to the surface. Not much remained from the encounter, except the axe in perfect condition."
   );
}

int wieldit() {
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"You can't get a proper grip on the weapon.");
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^RED%^As you grip the handle of the axe, you get the urge to hunt down a dragon!%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" grips the handle of the axe and looks prepared for battle!%^RESET%^",ETO);
   counter = 0;
   return 1;
}

int unwieldit() {
   tell_object(ETO,"%^BOLD%^%^RED%^You feel as if a certain rage for battle has left your body.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" unwields the axe and exhales heavily.%^RESET%^",ETO);
   return 1;
}

int hitit(object ob)
{
    object shape;
   string race = (string)ob->query_race();
   if(objectp(shape = ob->query_property("shapeshifted")))
   {
       race = shape->query_shape_race();
   }
        if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(ob)) return 1;
        if(random(1000) < 400){
      switch(random(5)){
      case 0:
         if(race == "dragon") {
            tell_object(ETO,"%^RESET%^%^GREEN%^You strike the soft spot in the belly of the beast with suprising accuracy%^RESET%^");
            tell_object(ob,"%^RESET%^%^GREEN%^"+ETO->query_cap_name()+" strikes you with suprising accuracy in the soft spot of your belly!%^RESET%^");
            tell_room(environment(query_wielded()),"%^RESET%^%^GREEN%^"+ETO->query_cap_name()+" strikes the dragon in the soft spot of the belly with astounding accuracy!%^RESET%^",({ETO,ob}));
            ob->do_damage("torso",random(30)+50);
            counter ++;
            break;
         } else {
tell_object(ETO,"%^BOLD%^%^WHITE%^You cut deeply with the razor sharp edge of the axe!%^RESET%^");
            tell_object(ob,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" cuts you deeply with the razor sharp edge of the axe!%^RESET%^");
            tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" cuts deeply with the razor sharp edge of the axe!%^RESET%^",({ETO,ob}));
            ob->do_damage("torso",random(20)+10);
            break;
         }
         case 1:
         if(race == "dragon") {
            tell_object(ETO,"%^BOLD%^%^WHITE%^With a tremendous roar you strike powerfully with the axe!%^RESET%^");
            tell_object(ob,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" roars loudly and strikes you powerfully with the axe!%^RESET%^");
            tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" roars with rage and strikes the dragon %^BOLD%^%^RED%^powerfully%^BOLD%^%^WHITE%^ with the axe!%^RESET%^",({ETO,ob}));
            ob->do_damage("torso",random(30)+50);
            counter ++;
            break;
         } else {
tell_object(ETO,"%^BOLD%^%^WHITE%^You cut deeply with the razor sharp edge of the axe!%^RESET%^");
            tell_object(ob,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" cuts you deeply with the razor sharp edge of the axe!%^RESET%^");
            tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" cuts deeply with the razor sharp edge of the axe!%^RESET%^",({ETO,ob}));
            ob->do_damage("torso",random(20)+10);
             break;
         }
         case 2:
         if(race == "dragon") {
            if(counter > 5) {
            tell_object(ETO,"%^BOLD%^%^RED%^You enter a frenzy and swing your axe wildly!%^RESET%^");
            tell_object(ob,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" enters a frenzy, swinging the axe wildly!%^RESET%^");
            tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" enters a frenzy, swinging the axe wildly!%^RESET%^",({ETO,ob}));
            counter = 0;
            ETO->execute_attack();
            ETO->execute_attack();
            ETO->execute_attack();
            ETO->execute_attack();
            } else {
            tell_object(ETO,"%^BOLD%^%^BLUE%^The edge of the axe flashes briefly with a blue light as you strike the dragon!%^RESET%^");
            tell_object(ob,"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"'s axe flashes briefly with a blue light as it strikes you!%^RESET%^");
            tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"'s axe flashes briefly with a blue light as it makes contact with the dragon!%^RESET%^",({ETO,ob}));
            ob->do_damage("torso",random(30)+50);
            counter ++;
            }
            break;
            } else {
tell_object(ETO,"%^BOLD%^%^WHITE%^You cut deeply with the razor sharp edge of the axe!%^RESET%^");
            tell_object(ob,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" cuts you deeply with the razor sharp edge of the axe!%^RESET%^");
            tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" cuts deeply with the razor sharp edge of the axe!%^RESET%^",({ETO,ob}));
            ob->do_damage("torso",random(30)+10);
            break;
         }
            case 3..4:
         if(race == "dragon") {
            tell_object(ETO,"%^BOLD%^%^BLUE%^The edge of the axe flashes briefly with a blue light as you strike the dragon!%^RESET%^");
            tell_object(ob,"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"'s axe flashes briefly with a blue light as it strikes you!%^RESET%^");
            tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+"'s axe flashes briefly with a blue light as it makes contact with the dragon!%^RESET%^",({ETO,ob}));
            ob->do_damage("torso",random(30)+50);
            counter ++;
            break;
            } else {
tell_object(ETO,"%^BOLD%^%^WHITE%^You cut deeply with the razor sharp edge of the axe!%^RESET%^");
            tell_object(ob,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" cuts you deeply with the razor sharp edge of the axe!%^RESET%^");
            tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" cuts deeply with the razor sharp edge of the axe!%^RESET%^",({ETO,ob}));
            ob->do_damage("torso",random(30)+10);
            break;
}
return 1;
}
}
}
