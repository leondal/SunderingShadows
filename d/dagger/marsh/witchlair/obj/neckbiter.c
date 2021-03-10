#include <std.h>
inherit "/d/common/obj/weapon/shortsword";
void create() {
  ::create();
  set_name("Neckbiter");
  set_obvious_short("%^BOLD%^%^BLACK%^keen-edged "
"%^WHITE%^t%^RESET%^i%^BOLD%^ta%^RESET%^n%^BOLD%^i"
"%^RESET%^u%^BOLD%^m %^BOLD%^%^BLACK%^shortsword%^RESET%^");
  set_id(({ "sword","shortsword","short sword",
"neckbiter","titanium short sword","titanium shortsword"
  }));
  set_short("%^BOLD%^%^BLACK%^Ne%^RESET%^%^CYAN%^c"
"%^BOLD%^%^BLACK%^kbi%^RESET%^%^CYAN%^t%^BOLD%^%^BLACK%^er%^RESET%^");
  set_long("%^BOLD%^%^WHITE%^Bright, silvery titanium makes"
" up the blade of this %^RESET%^%^BLUE%^c%^GREEN%^r"
"%^BOLD%^%^GREEN%^e%^RESET%^%^BLUE%^e%^GREEN%^p"
"%^BOLD%^%^GREEN%^y%^RESET%^%^BLUE%^-l%^GREEN%^o"
"%^BOLD%^%^GREEN%^o%^RESET%^%^BLUE%^k%^GREEN%^i"
"%^BOLD%^%^GREEN%^n%^RESET%^%^BLUE%^g %^BOLD%^%^WHITE%^weapon."
" Measuring about twenty inches from tip to tip, it would "
"fit easily into the hand of even one of the smaller races. "
" The blade is slender and slightly curved, bearing "
"%^RESET%^%^RED%^w%^BOLD%^%^RED%^ic%^RESET%^%^RED%^k"
"%^BOLD%^%^RED%^e%^RESET%^%^RED%^d %^BOLD%^%^WHITE%^se"
"%^BLACK%^r%^RESET%^%^WHITE%^r%^BOLD%^at%^BLACK%^i"
"%^RESET%^%^WHITE%^o%^BOLD%^ns on its cutting edge. Triangular"
" designs mark the border of the sharpened edge and the"
" main body of the blade. It thins slightly at the base, "
"Curving sharply inwards where it meets the hilt. The hilt "
"itself is %^BLACK%^ma%^RESET%^%^BLUE%^tt"
"%^BOLD%^%^BLACK%^e-bl%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^ck "
"da%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^kst%^RESET%^%^WHITE%^e"
"%^BOLD%^%^BLACK%^el%^WHITE%^, formed into the shape of "
"outspread batlike wings. The detail of the wings is "
"unsettlingly lifelike, appearing as if they could come alive"
" at any moment and dig those minute claws into your flesh. "
"%^BOLD%^%^BLACK%^Da%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^ke"
"%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^ed %^WHITE%^leather "
"covers the handle for a comfortable grip, if such a thing "
"could be said of this evil-looking object.%^RESET%^");
  set_lore("%^BOLD%^%^BLACK%^This is one of the most prized "
"possessions of Ahkserin, a witch taking up residence deep in "
"the swamps of Dagger. The weapon's true origin is unknown, "
"and while being of no real aid in her quest for immortality, "
"she favored this blade for its wicked ability to %^RED%^drink "
"%^BLACK%^its victims' lifeblood, transferring their "
"vitality to its wielder.%^RESET%^\n");
  set_value(10000);
  set_size(1);
  set_property("lore difficulty",24);
  set_property("id difficulty",16);
  set_property("enchantment",3);
  set_item_bonus("attack bonus",2);
  set_wield((:TO,"wield_func":));
  set_unwield((:TO,"unwield_func":));
  set_hit((:TO,"hit_func":));
}

int wield_func(string str) {
  if((int)ETO->query_lowest_level() <15) {
    tell_object(ETO,"%^BOLD%^%^BLACK%^The wings on the weapon's"
" crossguard come alive as you try to wield it, beating "
"rapidly and forcing you to drop it!");
    tell_room(EETO,"%^BOLD%^%^BLACK%^The blade in "
""+ETO->QCN+"'s hand seems to come alive, leaving "+ETO->QS+" "
"to recoil in shock and drop it!");
  force_me("drop neckbiter");
  return;
  }
  if(!ETO->query_invis()) {
  tell_object(ETO,"%^BOLD%^%^WHITE%^A sinister "
"%^RESET%^%^BLUE%^chuckle %^BOLD%^%^WHITE%^echoes in your mind"
" as you grip the smooth hilt.");
  tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" "
"seems to briefly take on a more %^RESET%^%^RED%^im"
"%^MAGENTA%^p%^RED%^ish %^BOLD%^%^WHITE%^appearance.",ETO);
  return 1;
  }
  return 1;
}

int unwield_func(string str) {
  tell_object(ETO,"%^BOLD%^%^BLACK%^A strange thirst washes "
"over you as you release your hold of the sword.");
  tell_room(EETO,"%^BOLD%^%^BLACK%^A faraway "
"look enters "+ETOQCN+"'s eyes as they relinquish their "
"grip on the sword, licking their lips.",ETO);
  return 1;
}

int hit_func(object vict) {
  vict = ETO->query_current_attacker();
  if(!objectp(vict)) return 0;
   if(random(1000) < 200){
    switch(random(15)){
    case 0..4:
    tell_room(EETO,"%^RESET%^%^BLUE%^A high-pitched "
"%^BOLD%^%^RED%^screech %^RESET%^%^BLUE%^and the beating of "
"myriad tiny wings ring out as "+ETOQCN+"'s blade lands a "
"deep %^RED%^s%^BOLD%^%^RED%^las%^RESET%^%^RED%^h %^BLUE%^in "
""+vict->QCN+"'s flesh!",({vict,ETO}));
    tell_object(ETO,"%^RESET%^%^BLUE%^A high-pitched "
"%^BOLD%^%^RED%^screech %^RESET%^%^BLUE%^and the beating of "
"myriad tiny wings ring out as your blade lands a deep "
"%^RED%^s%^BOLD%^%^RED%^las%^RESET%^%^RED%^h %^BLUE%^in "
""+vict->QCN+"'s flesh!");
    tell_object(vict,"%^RESET%^%^BLUE%^A high-pitched "
"%^BOLD%^%^RED%^screech %^RESET%^%^BLUE%^and the beating of "
"myriad tiny wings ring out as "+ETOQCN+"'s blade lands a "
"deep %^RED%^s%^BOLD%^%^RED%^las%^RESET%^%^RED%^h %^BLUE%^in"
" your flesh!");
    vict->cause_typed_damage(vict,vict->return_target_limb(),random(6)+15,"slashing");
    break;
    case 5..8:
    tell_room(EETO,"%^RESET%^%^RED%^"+ETOQCN+"'s sword emits"
" a mocking %^CYAN%^hiss %^RED%^as it makes contact with "
""+vict->QCN+", seeming to %^BOLD%^%^RED%^absorb "
"%^RESET%^%^RED%^The blood from "+vict->QP+" fresh wound!",
({vict,ETO}));
    tell_object(ETO,"%^RESET%^%^RED%^The sword emits a gleeful"
" %^CYAN%^hiss %^RED%^as it makes contact, seeming to "
"%^BOLD%^%^absorb %^RESET%^%^RED%^the blood from "+vict->QCN+""
"'s fresh wound!");
    tell_object(vict,"%^RESET%^%^RED%^"+ETOQCN+"'s weapon "
"emits a mocking %^CYAN%^hiss %^RED%^as it makes contact, "
"seeming to %^BOLD%^%^RED%^absorb %^RESET%^%^RED%^the blood "
"from your fresh wound!");
    vict->cause_typed_damage(vict,vict->return_target_limb(),random(6)+15,"slashing");
    break;
    case 9..11:
    tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" "
"%^RED%^plunges %^BLACK%^the blade deep into "+vict->QCN+"!",({vict,ETO}));
    tell_object(ETO,"%^BOLD%^%^BLACK%^You flip the blade into"
" a backhanded grip and %^RED%^plunge %^BLACK%^it deep into"
" "+vict->QCN+", feeling it feed on "+vict->QP+" "
"%^CYAN%^l%^WHITE%^i%^CYAN%^fe ess%^WHITE%^en"
"%^CYAN%^ce%^BLACK%^! You feel a bit stronger as the "
"%^RED%^blood %^BLACK%^feeds your vigor!");
    tell_object(vict,"%^BOLD%^%^BLACK%^"+ETO->QCN+" "
"%^RED%^plunges %^BLACK%^the blade deep into you, and you"
" feel the weapon's dark power drinking the very %^CYAN%^l"
"%^WHITE%^i%^CYAN%^fe %^BLACK%^ from your veins!");
    ETO->cause_typed_damage(ETO,"torso",(random(10)-30),
    "positive energy");
    vict->cause_typed_damage(vict,vict->return_target_limb(),random(6)+15,"piercing");
    TO->remove_property("magic");
    return 1;
    break;
  default:
    break;
    }
  return 1;
  }
}
