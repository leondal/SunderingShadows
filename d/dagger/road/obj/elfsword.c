//Updated by saide to re-adjust damage and give the weapon more value and uniqueness.
//Saide - 12/18/03
#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/longsword.c";

create() {
    ::create();
  set_id(({"sword","long sword","longsword","elven long sword","elven sword","elven longsword"}));
  set_name("ornate longsword");
  set_obvious_short("An ornate longsword");
  set_short("An %^GREEN%^elven%^RESET%^ longsword");
  set_long("The blade of this sword is forged from a piece of pure "+
  "%^BOLD%^%^WHITE%^mithril%^RESET%^ that has been etched with "+
  "%^RED%^ornate markings%^RESET%^ and enchanted to continually "+
  "give off an intense %^BOLD%^%^GREEN%^green glow%^RESET%^.  "+
  "The cross-piece that connects the blade to the hilt is in the "+
  "shape of a %^RED%^small hand%^RESET%^ clenched in a fist with "+
  "%^BOLD%^%^WHITE%^snow white%^RESET%^ crystals jutting upward, "+
  "downward, and then curving outward from it.  The %^BLUE%^hilt"+
  "%^RESET%^ of the weapon is made from a %^BLUE%^dark blue%^RESET%^ "+
  "substance that seems to soften and meld to the grip of the "+
  "wielder.  The weapon eventually ends in a %^GREEN%^dark "+
  "green crystal%^RESET%^ pommel that contains two %^RED%^red "+
  "specks%^RESET%^ in the shape of reptillian eyes.%^RESET%^");
  set_lore("These swords are said to be crafted by a secret enclave of elves "
  "that the local rangers protect in exchange for the supply of weapons.");
  set_property("enchantment",2);
  set_item_bonus("sight bonus",1);
  set_wield( (: TO, "extra_wield" :) );
  set_unwield((: TO,"unwield_me":));
  set_hit((:TO,"hit_em":));
  set_special_material_type("silver");
}

//added to give the sword a bit of flavor - Saide - 12/18/03
int hit_em(object targ) {
  int dam, len;
  if(!objectp(targ)) return 0;
  if(random(1000) < 200) {
    switch(random(20)) {
     case 0..11:
      tell_object(ETO,targ->QCN+"%^BOLD%^%^WHITE%^ screams in pain as the mithril blade flashes a %^RESET%^%^RED%^crimson%^BOLD%^%^WHITE%^ hue upon contact with "+targ->QP+"%^BOLD%^%^WHITE%^ flesh!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^WHITE%^The mithril blade of the sword wielded by "+ETO->QCN+"%^BOLD%^%^WHITE%^ flashes a %^RESET%^%^RED%^crimson%^BOLD%^%^WHITE%^ hue as it sears your flesh, causing you to scream out in pain!%^RESET%^");
      tell_room(EETO,targ->QCN+"%^BOLD%^%^WHITE%^ screams out in pain, as the mithril blade of "+ETO->QCN+"%^BOLD%^%^WHITE%^'s sword flashes a %^RESET%^%^RED%^crimson%^BOLD%^%^WHITE%^ hue upon contact with "+targ->QP+"%^BOLD%^%^WHITE%^ flesh!%^RESET%^",({targ,ETO}));
      ETO->set_property("magic",1);
      targ->do_damage(targ->return_target_limb(),roll_dice(1,6));
      ETO->set_property("magic",-1);
      break;
     case 12..18:
      tell_object(ETO,"%^BOLD%^%^GREEN%^A green light bursts forth from the pommel of the elven sword, leaving you feeling refreshed as it strikes "+targ->QCN+".");
      tell_object(targ,"%^BOLD%^%^GREEN%^A green light bursts forth from the pommel of the sword wielded by "+ETO->QCN+"%^BOLD%^%^GREEN%^ as it strikes you!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^GREEN%^A green light bursts forth from the pommel of the sword wielded by "+ETO->QCN+"%^BOLD%^%^GREEN%^ as it strikes "+targ->QCN+"%^BOLD%^%^GREEN%^!%^RESET%^",({ETO,targ}));
      dam = roll_dice(2,4);
      ETO->heal(dam);
      return targ->do_damage(targ->return_target_limb(),dam);
      break;
     case 19:
      len = 8 + random(7);
      tell_object(ETO,"%^RED%^The pommel of your sword flashes a dark red as you strike "+targ->QCN+"%^RED%^, causing "+targ->QP+" body to become rigid!%^RESET%^");
      tell_object(targ,"%^RED%^The pommel of "+ETO->QCN+"%^RED%^'s sword flashes a dark red as its blade strikes you and causes your body to become rigid!%^RESET%^");
      tell_room(EETO,"%^RED%^The pommel of the sword wielded by "+ETO->QCN+"%^RED%^ flashes a dark red as its blade strikes "+targ->QCN+"%^RED%^ causing "+targ->QP+"%^RED%^ body to become rigid!%^RESET%^",({ETO,targ}));
      return targ->set_paralyzed(len,"%^RED%^Your body is rigid!%^RESET%^");
    }
   }
}


int extra_wield(object ob) {
  int align;
  align = (int)ETO->query_alignment();
   if(ALIGN->is_evil(ETO)) {
      tell_object(ETO,"The sword %^RED%^BURNS%^RESET%^ your hand as you try to wield it!");
      tell_room(EETO,ETO->QCN+" screams in %^RED%^PAIN%^RESET%^ as "+ETO->QP+" hand is burned by the sword!%^RESET%^",ETO);
      ETO->do_damage("left hand",roll_dice(8,8));
      return 0;
  }
  if((string)ETO->query_race() != "elf") {
    write("%^RED%^You are not of elven blood and the sword refuses your hand!%^RESET%^");
    tell_room(EETO,ETO->QCN+" %^RESET%^seems to be trying to wield the sword but it doesn't seem to fit "+ETO->QP+" hand.",ETO);
    return 0;
  }
  if((int)ETO->query_level() < 15) {
    write("You are not yet worthy to wield such a fine weapon.");
    return 0;
  }
  if(ALIGN->is_neutral(ETO)) {
      tell_object(ETO,"You sense the magic in the sword reject you just as you rejected the goodness of your ancestors!");
      tell_room(EETO,ETO->QCN+" attempts to wield the sword but fails.",ETO);
      return 0;
  }
  //giving a sight_bonus() for the aura of light - sounds like a good idea to me - Saide
  tell_object(ETO,"%^CYAN%^A dim aura surrounds the sword as you wield it.%^RESET%^");
  tell_room(EETO,"%^CYAN%^An aura surrounds the sword as it is wielded by "+ETO->QCN+".%^RESET%^",ETO);
  return 1;
}

int unwield_me(object ob) {
  tell_object(ETO,"%^CYAN%^The aura surrounding the sword fades as you release the hilt.%^RESET%^");
  tell_room(EETO,"%^CYAN%^The aura surrounding the sword dims as "+ETO->QCN+" %^RESET%^%^CYAN%^releases the hilt.%^RESET%^",ETO);
  return 1;
}
