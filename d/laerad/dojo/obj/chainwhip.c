#include <std.h>
#include <magic.h>
inherit "/d/common/obj/weapon/katana"; //closest large exotic option

void create() {
    ::create();
    set_name("bladed chain whip");
    set_id(({"whip","chain","chain whip","bladed chain","bladed whip","bladed chain whip","Coiled Fury","T'ien-Long's Coiled Fury"}));
    set_short("%^BOLD%^%^BLACK%^T'i%^YELLOW%^e%^BLACK%^n-L%^WHITE%^o%^BLACK%^ng's Coiled Fu%^RED%^r%^BLACK%^y%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^vi%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^iou%^RESET%^s%^BOLD%^%^BLACK%^ly bladed c%^RESET%^h%^BOLD%^%^WHITE%^a%^BLACK%^in whip%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Entirely unique in appearance, this weapon might at best be compared to a whip, though it "
"would be far more dangerous both to the wielder and his opponent.  %^RESET%^%^CYAN%^Narrow metal se%^RESET%^g%^CYAN%^"
"ments %^BOLD%^%^WHITE%^are joined end-to-end by a set of three metal rings, forming a long and flexible chain.  While "
"more commonly these segments are simply rods of metal, in the case of this weapon they are slightly flattened along each "
"edge to meet as a %^BLACK%^ra%^RED%^z%^BLACK%^or-s%^YELLOW%^h%^WHITE%^a%^BLACK%^rp blade%^WHITE%^.  At one end lies a "
"moulded handle, the intentations for the wielder's hands forming the spaces between a coiled, serpentine %^YELLOW%^dr"
"%^RESET%^%^ORANGE%^ag%^YELLOW%^on %^WHITE%^that winds its way down the grip.  In its claws is gripped an i%^CYAN%^r"
"%^WHITE%^ides%^MAGENTA%^c%^WHITE%^ent pearl the size of a child's fist, forming a comfortable weight as the pommelstone"
".  At the distant end of the chain whip is a %^BLACK%^taper%^RESET%^e%^BOLD%^%^BLACK%^d metal dart%^WHITE%^, used as "
"much as a weight to direct the chain, as for further damage in slashing or piercing an opponent.  The entire piece is "
"surprisingly lightweight for one made entirely of darksteel.  Its dark form carries hints of %^RESET%^%^ORANGE%^go"
"%^YELLOW%^l%^RESET%^%^ORANGE%^d %^BOLD%^%^WHITE%^that trace their way in and out of the dragon's scaled hide, breathing "
"life into the inanimate creature and often causing its eyes to %^RESET%^%^RED%^gl%^BOLD%^ea%^RESET%^%^RED%^m %^BOLD%^"
"%^WHITE%^brightly.\n%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^This style of weapon dates back many centuries to the island civiliation of the Jin Chao, "
"and is named for the heavenly golden dragon who symbolised their line of Emperors.  The kingdom itself was famed across "
"the mainland of Shadowgate for both their exotic weaponry and their mastery of its use.  There were few travellers that "
"could best their skill at arms, and few powerful rulers that could afford their asking price as guardians or mercenaries"
".  The weapon itself was held as a sacred item, the use of which was only ever permitted to the most elite of the "
"Emperor's personal guards.  Its form was said to resemble the serpentine coils of the dragon, and its vicious bite was "
"that of his razor-sharp teeth and claws.%^RESET%^\n");
   set("no curse",1);
   set_property("lore difficulty",27);
   set_property("enchantment",4);
   set_value(8550);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun(){
    int toenchant;
    if(userp(ETO) && member_array("%^RESET%^%^MAGENTA%^%^Defeated the masters of the Vasati Aadhyaatmika.%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"%^BOLD%^You have not earned the right to make use of this item.%^RESET%^");
      return 0;
    }
    if(userp(ETO) && (int)ETO->query_level() < 25) {
      tell_object(ETO,"%^BOLD%^You must train further before you can attempt to use a weapon of this calibre.%^RESET%^");
      return 0;
    }
    tell_room(EETO,"%^RESET%^%^CYAN%^The bladed links ring together as the chain whip unfurls.%^RESET%^");
    return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^CYAN%^You hook the whip's length back over the handle, securing its dangerously bladed links in "
"the curled claw of the dragon.%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETOQCN+" coils the whip's length back up, careful not to cut "+ETO->QO+"self on the bladed "
"links.%^RESET%^",ETO);
   return 1;
}

int hit_fun(object targ) {
   object *mytargs;
   int rollchance, myhits, skinned, i;
   targ = ETO->query_current_attacker();
   mytargs = ETO->query_attackers();
   if(random(2500)<750){
     switch(random(400)){
       case 0..199:
       tell_object(ETO,"%^ORANGE%^You cast the chain whip in a wide arc towards "+targ->QCN+", snapping the end back at "
"the last moment to score a %^RED%^vi%^BOLD%^c%^WHITE%^i%^RED%^o%^RESET%^%^RED%^us %^ORANGE%^lash across "+targ->QP+
" skin!%^RESET%^");
       tell_object(targ,"%^ORANGE%^"+ETOQCN+" casts the chain whip in a wide arc towards you, and then snaps the end back "
"at the last moment to score a %^RED%^vi%^BOLD%^c%^WHITE%^i%^RED%^o%^RESET%^%^RED%^us %^ORANGE%^lash across your skin"
"!%^RESET%^");
       tell_room(EETO,"%^ORANGE%^"+ETOQCN+" casts the chain whip in a wide arc towards "+targ->QCN+", snapping the end "
"back at the last moment to score a %^RED%^vi%^BOLD%^c%^WHITE%^i%^RED%^o%^RESET%^%^RED%^us %^ORANGE%^lash across "
+targ->QP+" skin!%^RESET%^",({ETO,targ}));
       return 10;
       break;

       case 200..299:
       if(!sizeof(mytargs)) return 10;
       myhits = roll_dice(1,4)+4;
       tell_object(ETO,"%^WHITE%^%^BOLD%^You weave the chain whip back and forth, striking with %^BLACK%^d%^RED%^e"
"%^WHITE%^a%^RESET%^d%^BOLD%^%^BLACK%^ly %^WHITE%^precision at any foe that comes within reach!%^RESET%^");
       tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" weaves the chain whip back and forth in a %^BLACK%^d%^RED%^e%^WHITE%^a"
"%^RESET%^d%^BOLD%^%^BLACK%^ly %^WHITE%^pattern, lashing out at any foe that comes within reach!%^RESET%^",ETO);
       for(i = 0;i<myhits;i++) {
         targ = mytargs[random(sizeof(mytargs))];
         switch(random(3)) {
           case 0:
           tell_room(EETO,"%^BOLD%^%^RED%^The dart pierces "+targ->QCN+"!%^RESET%^",targ);
           tell_object(targ,"%^BOLD%^%^RED%^The dart pierces you!%^RESET%^");
           break;
           case 1:
           tell_room(EETO,"%^BOLD%^%^RED%^The bladed edge slashes across "+targ->QCN+"!%^RESET%^",targ);
           tell_object(targ,"%^BOLD%^%^RED%^The bladed edge slashes across your skin!%^RESET%^");
           break;
           case 2:
           tell_room(EETO,"%^BOLD%^%^RED%^The whip bites into "+targ->QCN+"!%^RESET%^",targ);
           tell_object(targ,"%^BOLD%^%^RED%^The whip bites into you!%^RESET%^");
           break;
         }
         targ->do_damage(targ->return_target_limb(),roll_dice(3,4));
       }
       break;

       case 300..399:
       tell_object(ETO,"%^BOLD%^%^BLACK%^Using the weighted dart to hook the whip around "+targ->QCN+", you pull it "
"tighter until it %^RED%^bit%^RESET%^%^RED%^e%^BOLD%^s %^BLACK%^into skin and "+targ->QP+" bones %^RESET%^cr%^BOLD%^ea"
"%^RESET%^k %^BOLD%^%^BLACK%^in protest!%^RESET%^");
       tell_object(targ,"%^BOLD%^%^BLACK%^Using the weighted dart to hook the whip around you, "+ETO->QCN+" pulls it "
"tighter until it %^RED%^bit%^RESET%^%^RED%^e%^BOLD%^s %^BLACK%^into your skin and your bones %^RESET%^cr%^BOLD%^ea"
"%^RESET%^k %^BOLD%^%^BLACK%^in protest!%^RESET%^");
       tell_room(EETO,"%^BOLD%^%^BLACK%^Using the weighted dart to hook the whip around "+targ->QCN+", "+ETO->QCN+" pulls "
"it tighter until it %^RED%^bit%^RESET%^%^RED%^e%^BOLD%^s %^BLACK%^into skin and "+targ->QP+" bones %^RESET%^cr%^BOLD%^ea"
"%^RESET%^k %^BOLD%^%^BLACK%^in protest!%^RESET%^",({ETO,targ}));
       if((skinned = (int)targ->query_stoneSkinned()) && random(2)) {
         tell_object(targ,"%^BOLD%^%^WHITE%^Thin layers of your protective skin c%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^"
"%^WHITE%^c%^BOLD%^k under the pressure!%^RESET%^");
         tell_room(EETO,"%^BOLD%^%^WHITE%^Thin layers of "+targ->QCN+"'s protective skin c%^RESET%^r%^BOLD%^%^BLACK%^a"
"%^RESET%^%^WHITE%^c%^BOLD%^k under the pressure!",targ);
         if (skinned > 25) targ->set_stoneSkinned(skinned - 25);
         else targ->set_stoneSkinned(0);
       }
       return 10;
       break;
     }
   }
   return 1;
}