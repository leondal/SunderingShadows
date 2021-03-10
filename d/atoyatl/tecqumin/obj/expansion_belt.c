#include <std.h>
#include <move.h>

inherit ARMOUR;

int stamina_track;

void create(){
        ::create();
        set_name("belt of vines");
        set_id(({ "belt", "vine belt", "belt of vines" }));
        set_short("belt of expansion");
        set_obvious_short("%^GREEN%^belt of %^BOLD%^j%^RESET%^%^GREEN%^u"
          +"%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e v%^RESET%^%^GREEN%^i"
          +"%^BOLD%^nes%^RESET%^");
        set_long(

@LUJKE
%^GREEN%^This belt is twisted from many strands of stretchy %^BOLD%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^RESET%^e %^BOLD%^v%^RESET%^%^GREEN%^i%^BOLD%^nes%^RESET%^%^GREEN%^. It has a %^ORANGE%^carved wooden buckle%^GREEN%^, and seems to stretch to fit a range of different sizes.

LUJKE
        );
        set_weight(3);
   set_value(150000);
        set_lore(
@LUJKE
Stories of the legendary %^CYAN%^Tecqumin%^RESET%^ hero %^ORANGE%^Tlatlcupra %^RESET%^tell of him towering over the armies of his enemies, and stretching past the tops of %^GREEN%^trees%^RESET%^ to find his way within the deep %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^. What is less commonly known is that the giant of %^CYAN%^Tecqumin%^RESET%^ national myths was actually the owner of a belt blessed by the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^ %^RESET%^%^GREEN%^spirit %^BOLD%^Q%^RESET%^%^GREEN%^ua%^BOLD%^l%^RESET%^%^GREEN%^i%^RESET%^ that, while not quite making him the giant of legend, did at least increase his size well above that of other men, as well as conferring other bonuses.  

LUJKE
        );
        set_property("lore difficulty",41);
        set_type("clothing");
        set_limbs(({ "waist" }));
        set_size(-1);
        TO->set_property("enchantment",6);
        set_wear((:TO,"wear_func":));
        set_remove((:TO, "remove_func":));
        set_overallStatus(320);
        set_item_bonus("damage", 4);
        set_item_bonus("dexterity", -2);
        set_item_bonus("constitution", 2);
       set_property("quest required", "%^GREEN%^Sealed the %^BLUE%^U%^MAGENTA%^nf"
    +"%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d"
    +" %^GREEN%^back into the %^BLUE%^v%^BOLD%^%^BLACK%^o%^RESET%^i%^BLUE%^d");
}

int isMagic(){ return 1; }

int wear_func(){
  int sz;
  if (!objectp(ETO)){
    return notify_fail("There's a problem with the belt's environment. Please make a bug report");
  }
  if (!interactive(ETO)){
    return notify_fail("You don't have that!");
  }
  if((int)ETO->query_level() < 41) {
    tell_object(ETO,"You aren't experienced enough to handle an item of this power.");
    return 0;
  }
  sz = ETO->query_size();
  sz++;
  ETO->set_size(sz);
  ETO->set_property("enlarged", 1);
  if (objectp(EETO)){
    tell_room(environment(ETO),ETO->QCN + " grows in size as " + ETO->QS + " fastens the belt around " + ETO->QP + " waist." , ETO);
  }
  tell_object(ETO,"As you fasten the belt around your waist, the world around you seems to shrink in size.");
  return 1;
}

int remove_func(){
  int sz;
  if (!objectp(ETO)){
    return;
  }
  if (!interactive(ETO)){
    return notify_fail("You don't have that!");
  }
  if (ETO->query_property("enlarged")>0){
    tell_object(ETO,"As you fasten the belt around your waist, the world around you seems to grow in size.");
    if (objectp(EETO)){
      tell_room(EETO,ETO->QCN + " shrinks before your eyes as " + ETO->QS + " unfastens the belt from " + ETO->QP + " waist." , ETO);
    }
    sz = ETO->query_size();
    sz--;
    ETO->set_size(sz);
    ETO->remove_property("enlarged");
  }
  return 1;
}
