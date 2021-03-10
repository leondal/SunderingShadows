#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

int glowing, owned, variety;
string obvshort, short, owner;

void create() {
   ::create();
   set_name("mithril longsword");
   set_id(({"longsword","long sword","sword","mithril longsword","blade","engraved longsword","syolkiir","Syolkiir","wild star","moonbladex"}));
   set_short("%^YELLOW%^Sy%^WHITE%^o%^YELLOW%^lk%^WHITE%^i%^YELLOW%^ir %^WHITE%^- %^BOLD%^%^BLUE%^the W%^WHITE%^i%^CYAN%^l%^BLUE%^d S%^CYAN%^t%^BLUE%^ar%^RESET%^");
   set_obvious_short("%^RESET%^a %^MAGENTA%^de%^RED%^li%^MAGENTA%^cat%^BOLD%^e%^RESET%^%^MAGENTA%^ly %^RESET%^engraved %^BOLD%^%^WHITE%^mith%^CYAN%^r%^WHITE%^il %^RESET%^longsword");
   set_long("This weapon is simple and efficient in design, a longsword with a straight blade of nearly three "
"feet length.  The mirror-like blade is made of %^BOLD%^%^WHITE%^gle%^CYAN%^a%^WHITE%^ming mith%^CYAN%^r"
"%^WHITE%^il%^RESET%^, with a tapered point that allows for effective thrusting attacks against heavily "
"armored foes.  From the tip, it broadens slightly and then leads down parallel on either side almost to the "
"hilt, each %^BOLD%^%^BLACK%^ra%^WHITE%^z%^YELLOW%^o%^BLACK%^r-sha%^YELLOW%^r%^BLACK%^p edge%^RESET%^ allowing "
"for vicious cutting attacks.  In from each edge, the blade broadens in a lenticular shape, but is prevented "
"from reaching thickness at the centre by the inlay of a wide fuller.  A series of %^GREEN%^e%^BOLD%^l%^RESET%^"
"%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^n %^BOLD%^r%^RESET%^%^GREEN%^u%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s "
"%^RESET%^thread their way down the middle of this indentation, until the entire blade broadens at the last to "
"flare out in a narrow crosspiece, barely curled at each end.  A raised diamond ridge at the centre of the "
"crosspiece leads down into a rounded hilt, undecorated but %^ORANGE%^comfortable %^RESET%^enough to be "
"gripped in a single hand.  Below this lies the pommel, unusually heavy in weight to balance the swing of the "
"blade, where tines of mithril claw their way around an iridescent stone.  Within the stone, depths of "
"%^YELLOW%^li%^WHITE%^gh%^YELLOW%^t %^RESET%^and %^BLUE%^sh%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^dow %^RESET%^"
"glitter and reflect like the lively sparkling of a %^BOLD%^%^BLUE%^st%^CYAN%^a%^BLUE%^r%^RESET%^.  The entire "
"effect is given of a masterworked weapon of unmatched craftsmanship, light and elegant but definitely %^RED%^"
"da%^MAGENTA%^ng%^RED%^e%^MAGENTA%^ro%^RED%^us %^RESET%^in the hands of an experienced user.\n");
   set_lore("  Lo, for it was conceived among the elders of the Realm of Promises Fulfilled, that blades would "
"be blessed and woven within the High Art, that they might discern among elvenkind the most worthy and wise to "
"be rulers of the People.  The High Mages of the court gathered, each conducting ritual over those blades "
"created, and above them all stood the Grand Mage Ethlando.  By his hand all these rituals were bound as one, "
"and together a great weaving was made across the realms to bind all of the High Mages in solemn ceremony.\n"
"  And when it was done, it came to each clan's heir to take up the blade and be judged for their worthiness "
"to rule.  Within the blades was imbued the ability to grant power and protection to those of rightful morals, "
"and death to any other who attempted to harness their power.  Of the few hundred who stood forward at the "
"First Claiming Ceremony, near half their number perished, and dozens of Gold Elf houses stood humbled as "
"their heirs were judged unworthy to rule elvenkind.  And so they were named the Moonblades, for at the last, "
"greatest among those judged worthy were Moon Elf clans.\n"
"  Left was the promise of the Grand Mage Ethlando, as he spake prophecy to the rightful heirs that remained.  "
"'When the blades number a score and four, they shall ring out the time for the Ascension Ceremony.  The one "
"clan and one clan heir chosen worthiest by the moonblades shall unify the elves in their truest homeland, "
"where the heir shall rule over all.  Never again shall a tyrant ruin all that is great among the People, for "
"both the Seldarine and the Weave shall choose through the swords' magic.'\n  - from 'The crafting of the "
"Moonblades', recorded by Lor'dressil the Learned.");
   set_property("lore difficulty",35);
   set_property("id difficulty",35);
   set_value(23200);
   set_property("enchantment",5);
   while(query_property("enchantment") != 5) {
     remove_property("enchantment");
     set_property("enchantment",5);
   }
   set_item_bonus("attack bonus",3);
   set_item_bonus("damage bonus",3);
   set_item_bonus("sight bonus",3);
   set_weapon_prof("exotic");
   glowing = 0;
   owned = 0;
   short = "%^YELLOW%^Sy%^WHITE%^o%^YELLOW%^lk%^WHITE%^i%^YELLOW%^ir %^WHITE%^- %^BOLD%^%^BLUE%^the W%^WHITE%^i%^CYAN%^l%^BLUE%^d S%^CYAN%^t%^BLUE%^ar%^RESET%^";
   obvshort = "%^RESET%^a %^MAGENTA%^de%^RED%^li%^MAGENTA%^cat%^BOLD%^e%^RESET%^%^MAGENTA%^ly %^RESET%^engraved %^BOLD%^%^WHITE%^mith%^CYAN%^r%^WHITE%^il %^RESET%^longsword";
   set_heart_beat(1);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
   int myflag, i;
   object *mywielded;
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) { //yes, they need to get the ragnarok trade themselves to use it.
     tell_object(ETO,"%^BOLD%^%^WHITE%^You sense the blade's refusal, for your failure to truly earn such a fine weapon!");
     return 0;
   }
   if((int)ETO->query_alignment() % 3 != 1 || ((string)ETO->query_race() != "elf" && (string)ETO->query_race() != "half-elf") || (owned && (string)ETO->query_name() != owner)) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You attempt to take up the sword, and the runes upon the blade flare "
"an angry shade of %^GREEN%^vi%^RESET%^%^GREEN%^r%^BOLD%^id%^RESET%^%^GREEN%^i%^BOLD%^an%^WHITE%^!  A shock of "
"%^RED%^ag%^MAGENTA%^on%^RED%^y %^WHITE%^runs through your body, and you can't help but to drop the weapon."
"%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+"%^BOLD%^%^WHITE%^ attempts to take up the sword, and the "
"runes upon the blade flare an angry shade of %^GREEN%^vi%^RESET%^%^GREEN%^r%^BOLD%^id%^RESET%^%^GREEN%^i"
"%^BOLD%^an%^WHITE%^!  "+capitalize(ETO->QS)+" lets out a gasp and drops the weapon.%^RESET%^",ETO);
     TO->set_property("magic",1);
     ETO->do_damage("torso",roll_dice(20,10));
     TO->set_property("magic",-1);
     ETO->force_me("drop moonbladex");
     return 0;
   }
   if(ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
     tell_object(ETO,"%^BOLD%^%^WHITE%^You reach out to grasp the blade, and the weapon already in your hand "
"seems to radiate with denial.  You find yourself unwilling even to lift the second weapon!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" reaches out to grasps the blade, but then hesitates, and "
"stops.",ETO);
     return 0;
   }
   if(!owned) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^As you grasp the blade, a feeling runs through you of a presence "
"watching... judging... and then a calm %^RESET%^%^GREEN%^acceptance %^BOLD%^%^WHITE%^washes over you.  You "
"realise it must have been the weapon in your hand, testing you somehow.  And fortunately, it seems you passed!"
"%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^WHITE%^An intense look comes briefly over "+ETO->QCN+"%^BOLD%^%^WHITE%^'s face, "
"before "+ETO->QS+" relaxes again.%^RESET%^",ETO);
     owned = 1;
     owner = ETO->query_name();
   }
   else {
     tell_object(ETO,"%^BOLD%^%^WHITE%^The heavy counterweight of the pommel allows you a %^BLUE%^well-b"
"%^CYAN%^a%^BLUE%^lanced %^WHITE%^hold upon the weapon's hilt.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^WHITE%^The longsword rests in a light and balanced hold in "+ETO->QCN+"'s hand."
"%^RESET%^",ETO);
   }
   ETO->set_property("good item",1);
   ETO->set_property("master weapon",1);
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^BOLD%^%^WHITE%^You release your hold on the %^BLACK%^com%^RESET%^%^ORANGE%^fo%^BOLD%^"
"%^BLACK%^rtab%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^e %^WHITE%^grip of the longsword.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+"%^BOLD%^%^WHITE%^ releases hold on the grip of the longsword."
"%^RESET%^",ETO);
   ETO->set_property("good item",-1);
   ETO->set_property("master weapon",-1);
   return 1;
}

int get_evils(object ob) {
   if(ob == ETO) return 0;
   if(ob->query_true_invis()) return 0;
   if((int)ob->query_property("hidden alignment") % 3) return 0;
   if((int)ob->query_property("hidden alignment") && !((int)ob->query_property("hidden alignment") % 3))
     return 1;
   if((int)ob->query_alignment() % 3) return 0;
   return 1;
}

void heart_beat() {
   object holder, location, *people, *ids;
   int tracker, i;
   if(!objectp(ETO)) return;
   if(!objectp(EETO)) return;
   tracker = 0;
   ids = TO->query_id();
   holder = ETO;
   location = environment(holder);
   people = all_living(location);
   for(i = 0; i < sizeof(people); i++) {
     if(get_evils(people[i])) tracker = 1;
   }
   if(tracker && !glowing) {
     if(!TO->query_wielded()) return;
     if (!holder->query_invis()) tell_room(location,"%^BOLD%^%^WHITE%^The "+ids[0]+
" in "+holder->QCN+"'s hands takes on a %^CYAN%^pale ra%^GREEN%^d%^CYAN%^iance"
"%^BOLD%^%^WHITE%^.%^RESET%^",holder);
     tell_object(holder,"%^BOLD%^%^WHITE%^The "+ids[0]+" in your hand takes on "
"a %^CYAN%^pale ra%^GREEN%^d%^CYAN%^iance%^BOLD%^%^WHITE%^, warning of danger "
"nearby.%^RESET%^");
     TO->set_short(short+" %^BOLD%^%^CYAN%^(glowing softly)%^RESET%^");
     TO->set_obvious_short(obvshort+" %^BOLD%^%^CYAN%^(glowing softly)%^RESET%^");
     glowing = 1;
   }
   else {
     if(glowing && (!TO->query_wielded() || !tracker)) {
       if (!holder->query_invis()) tell_room(location,"%^BOLD%^%^WHITE%^The "+ids[0]+
" in "+holder->QCN+"'s hands stops glowing again.%^RESET%^",holder);
       if(!TO->query_wielded())
         tell_object(holder,"%^BOLD%^%^WHITE%^The "+ids[0]+" stops glowing "
"again as you release contact with it.%^RESET%^");
       else
         tell_object(holder,"%^BOLD%^%^WHITE%^The "+ids[0]+" in your hand stops "
"glowing again, the danger past.%^RESET%^");
       TO->set_short(short);
       TO->set_obvious_short(obvshort);
       glowing = 0;
     }
   }
   return;
}

int hit_func(object targ){
    int rand;
    object ob;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    targ = ETO->query_current_attacker();
    if(!objectp(targ)) return 0;
    if(random(100) > 36) return 1;
    rand = roll_dice(1,10);

    if((rand > 0 && rand < 5) || (rand == 10 && present("elfshadow",EETO))) {
      tell_object(ETO,"%^BOLD%^%^CYAN%^The first rune upon the longsword's blade flares %^GREEN%^br%^RESET%^"
"%^GREEN%^i%^BOLD%^llia%^YELLOW%^n%^GREEN%^tly %^CYAN%^as it draws a line of blood across "+targ->QCN+"'s "
"flesh!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^CYAN%^The first rune upon the blade of "+ETO->QCN+"'s longsword flares "
"%^GREEN%^br%^RESET%^%^GREEN%^i%^BOLD%^llia%^YELLOW%^n%^GREEN%^tly %^CYAN%^as it draws a line of blood across "
"your flesh!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^CYAN%^The first rune upon the blade of "+ETO->QCN+"'s longsword flares "
"%^GREEN%^br%^RESET%^%^GREEN%^i%^BOLD%^llia%^YELLOW%^n%^GREEN%^tly %^CYAN%^as it draws a line of blood across "
+targ->QCN+"'s flesh!%^RESET%^",({ETO,targ}));
      TO->set_property("magic",1);
      targ->do_damage(targ->return_target_limb(),roll_dice(2,10)+2);
      TO->remove_property("magic");
    }

    if(rand > 3 && rand < 7) {
      tell_object(ETO,"%^BOLD%^%^GREEN%^The longsword's second rune emits a sudden flash of %^RESET%^%^GREEN%^"
"virid%^YELLOW%^i%^RESET%^%^GREEN%^an %^BOLD%^light.  "+targ->QCN+" struggles to blink away the blinding "
"afterimage.%^RESET%^");
      tell_object(targ,"%^BOLD%^%^GREEN%^"+ETO->QCN+"'s longsword emits a sudden flash of %^RESET%^%^GREEN%^"
"virid%^YELLOW%^i%^RESET%^%^GREEN%^an %^BOLD%^light, and the world disappears in a blinding white afterimage!"
"%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+"'s longsword emits a sudden flash of %^RESET%^%^GREEN%^"
"virid%^YELLOW%^i%^RESET%^%^GREEN%^an %^BOLD%^light from the fourth rune upon its blade, and you barely turn "
"away in time to avoid being blinded by it!%^RESET%^",({ETO,targ}));
      targ->set_temporary_blinded(2);
    }

    if(rand > 5 && rand < 8) {
      tell_object(ETO,"%^BOLD%^%^BLUE%^The third rune upon the longsword %^GREEN%^c%^YELLOW%^r%^GREEN%^ack"
"%^WHITE%^l%^GREEN%^es %^BLUE%^with light, and a sudden burst of energy races down the blade to throw "
+targ->QCN+" to the ground!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^BLUE%^The third rune upon "+ETO->QCN+"'s longsword %^GREEN%^c%^YELLOW%^r"
"%^GREEN%^ack%^WHITE%^l%^GREEN%^es %^BLUE%^with light, and a sudden burst of energy races down the blade to "
"throw you to the ground!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLUE%^The third rune upon "+ETO->QCN+"'s longsword %^GREEN%^c%^YELLOW%^r"
"%^GREEN%^ack%^WHITE%^l%^GREEN%^es %^BLUE%^with light, and a sudden burst of energy races down the blade to "
"throw "+targ->QO+" to the ground!%^RESET%^",({ETO,targ}));
      targ->set_paralyzed(roll_dice(1,16) + 8, "You are shaking from the blast!");
    }

    if(rand > 7 && rand < 10) {
      targ->do_damage("torso",roll_dice(2,10)+2);
      tell_object(ETO,"%^YELLOW%^The longsword's fourth rune %^RESET%^%^GREEN%^pul%^BOLD%^s%^RESET%^%^GREEN%^"
"es %^YELLOW%^brightly, and a burst of speed runs through your body to lead you into another strike!%^RESET%^");
      tell_room(EETO,"%^YELLOW%^The fourth rune upon "+ETO->QCN+"'s blade %^RESET%^%^GREEN%^pul%^BOLD%^s"
"%^RESET%^%^GREEN%^es %^YELLOW%^brightly, and "+ETO->QS+" strikes again in a sudden burst of speed!"
"%^RESET%^",ETO);
      ETO->execute_attack();
    }

    if(rand == 10 && !present("elfshadow",EETO)) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^The fifth rune upon the longsword's blade lights up with a %^RESET%^"
"%^GREEN%^soft j%^CYAN%^ad%^GREEN%^e glow%^BOLD%^%^WHITE%^, and as you blink, you realise the %^RESET%^%^BLUE%^"
"shadowy silhouette %^BOLD%^%^WHITE%^of an elven figure stands at your side in a protective stance!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^WHITE%^The fifth rune upon "+ETO->QCN+"'s blade lights up with a %^RESET%^"
"%^GREEN%^soft j%^CYAN%^ad%^GREEN%^e glow%^BOLD%^%^WHITE%^, and as you blink, you realise the %^RESET%^%^BLUE%^"
"shadowy silhouette %^BOLD%^%^WHITE%^of an elven figure stands at "+ETO->QP+" side in a protective "
"stance!",ETO);
      ob = new("/d/retired/obj/elfshadow.c");
      ob->move(EETO);
      ob->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob);
    }
    return 1;
}

int setbound(string thename) {
     owned = 1;
     owner = thename;
     return 1;
}
