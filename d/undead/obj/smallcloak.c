#include <std.h>
inherit ARMOUR;

int setting;
void mynew_longdesc();
void reset_longdesc();

void create(){
   ::create();
   set_name("pearl and oyster shell pendant");
   set_id(({"clasp","clasp of the shifting sands","pendant","shell pendant","oyster shell pendant","pearl pendant","pearl and oyster shell pendant",}));
   set_short("%^RESET%^%^CYAN%^Clasp of the %^RED%^Shi%^ORANGE%^fti%^BOLD%^%^BLUE%^ng Sa%^CYAN%^nds%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^a %^BOLD%^%^BLACK%^pearl %^RESET%^%^CYAN%^and %^ORANGE%^oyster shell %^CYAN%^pendant%^RESET%^");
   set_long("%^RESET%^%^CYAN%^A half moon shard of polished %^ORANGE%^oyster "
"shell %^CYAN%^hangs from a thin %^BOLD%^%^WHITE%^mithril chain%^RESET%^%^CYAN%^"
".  The pendant's shape is such that the curves of the half moon nearly touch "
"their points together.  Only the tiniest of space between the curves of oyster "
"shell remains open.  Hanging within the center of that opening, a perfect "
"%^BOLD%^%^BLACK%^black pearl %^RESET%^%^CYAN%^can be seen.  Tiny mithril links "
"bind it to the center of the oyster shell, allowing it to swing freely and "
"shed a fine, %^RED%^mu%^ORANGE%^lti%^BOLD%^%^BLUE%^hu%^CYAN%^ed %^RESET%^"
"%^CYAN%^sand.  The dust sifts down to the point where the shell nearly closes "
"and then vanishes, causing you to wonder just what is going on with this "
"pendant.%^RESET%^\n");
   set_weight(2);
   set_size(1);
   set_type("clothing");
   set_limbs(({"neck",}));
    set_property("enchantment",5);
    while (query_property("enchantment") != 5) {
      remove_property("enchantment");
      set_property("enchantment",5);
    }
   set_value(10000);
   set_lore("%^RESET%^When Captain Escuoso sailed from his war torn home to "
"seek aid from foreign ports, his beautiful wife gifted him with a protective "
"necklace much like this one.  Though there are only rumors as to what it does "
"exactly, it is said that Escuoso's wife offered a prayer to each of the "
"elemental deities, asking that they grant her husband their gifts.  In answer "
"to such earnest prayers the gods sent four things to her, a shell for water, a "
"lustrous pearl for fire, a fine mithril chain for earth and finally an ever "
"shifting wind.  Each of these she collected up and formed into a necklace to "
"give her husband telling him he had but to set his %^RED%^will %^RESET%^to one "
"element or another and they would aid him.");
   set_property("lore difficulty",14);
   set_wear((:TO,"wear_it":));
   set_remove((:TO,"remove_it":));
   set_struck((:TO,"struck":));
   setting = 0;
}

void init() {
   ::init();
   add_action("changeme","will");
}

int wear_it(){
    if(!setting) {
      tell_room(EETO,"%^BOLD%^%^WHITE%^As "+ETOQCN+" sets the pendant about "
+ETO->QP+" neck, a few grains of sand drift free from the shell.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^%^WHITE%^As the pendant settles around your "
"neck, a few grains of sand drift free from the shell.%^RESET%^");
      return 1;
    }
    tell_room(EETO,"%^BOLD%^%^WHITE%^As "+ETOQCN+" sets the pendant about "
+ETO->QP+" neck, a flowing cloak of shifting sands flows out from the mithril "
"links.",ETO);
    tell_object(ETO,"%^BOLD%^%^WHITE%^As the pendant settles around your neck, "
"the %^RESET%^%^RED%^fi%^ORANGE%^ne %^BOLD%^%^BLUE%^du%^CYAN%^st %^WHITE%^pours "
"out of its small hole and swirls up around you, following the line of mithril "
"and shimmering down about your shoulders into an ever-shifting "
"cloak!%^RESET%^");
    mynew_longdesc();
    return 1;
}

int remove_it(){
    if(!setting) {
      tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" undoes the clasp of "+ETO->QP+
" pendant, and a few grains of sand escape the shell to drift away on the "
"wind.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^%^WHITE%^You undo the clasp of the pendant, and "
"a few grains of sand escape the shell to drift away on the wind.%^RESET%^");
      return 1;
    }
    tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" undoes the clasp of "+ETO->QP+
" pendant, causing the cloak of sand to scatter apart and drift "
"away.%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^WHITE%^You undo the clasp and the fine sands of "
"the cloak fall apart and drift away in the air.%^RESET%^");
    reset_longdesc();
    return 1;
}

int struck(int damage, object what, object who){
   if(setting && !random(2)){
     switch(setting) {
       case 1:
       tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s cloak ripples and shifts, "
"throwing "+who->QCN+"'s blow off balance!%^RESET%^",({who,ETO}));
       tell_object(who,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s cloak ripples and shifts, "
"throwing your blow off balance!%^RESET%^");
       tell_object(ETO,"%^BOLD%^%^BLUE%^Your cloak ripples and shifts, throwing "
+who->QCN+"'s blow off balance!%^RESET%^");
       break;
       case 2:
       tell_room(EETO,"%^ORANGE%^"+who->QCN+"'s strike bounces off "+ETO->QCN+
"'s cloak as though it were solid stone!%^RESET%^",({who,ETO}));
       tell_object(who,"%^ORANGE%^Your strike bounces off "+ETO->QCN+
"'s cloak as though it were solid stone!%^RESET%^");
       tell_object(ETO,"%^ORANGE%^"+who->QCN+"'s strike bounces off your "
"cloak as though it were solid stone!%^RESET%^");
       break;
       case 3:
       tell_room(EETO,"%^BOLD%^%^RED%^"+ETO->QCN+"'s cloak flares up in brilliant "
"flames, throwing "+who->QCN+"'s blow off balance!%^RESET%^",({who,ETO}));
       tell_object(who,"%^BOLD%^%^RED%^"+ETO->QCN+"'s cloak flares up in brilliant "
"flames, throwing your blow off balance!%^RESET%^");
       tell_object(ETO,"%^BOLD%^%^RED%^Your cloak flares up in brilliant flames, "
"throwing "+who->QCN+"'s blow off balance!%^RESET%^");
       break;
       case 4:
       tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETO->QCN+"'s cloak swirls as the winds "
"pick up, throwing "+who->QCN+"'s blow off balance!%^RESET%^",({who,ETO}));
       tell_object(who,"%^BOLD%^%^CYAN%^"+ETO->QCN+"'s cloak swirls as the winds "
"pick up, throwing your blow off balance!%^RESET%^");
       tell_object(ETO,"%^BOLD%^%^CYAN%^Your cloak swirls as the winds pick up, "
"throwing "+who->QCN+"'s blow off balance!%^RESET%^");
       break;
     }
     return(-1)*(damage);
   }
}

int changeme(string str) {
   if(!str) {
     notify_fail("What are you focussing your will upon?\n");
     return 0;
   }
   if(!TO->query_worn()) {
     notify_fail("You can't feel anything from the pendant, without it touching your skin.\n");
     return 0;
   }
   if(setting) {
     notify_fail("The amulet is already attuned to an element.\n");
     return 0;
   }
   switch(str) {
     case "water":
       tell_object(TP,"%^BOLD%^%^WHITE%^You set your mind to %^BLUE%^water"
"%^WHITE%^ and a wave of fine sands tumbles forth from the amulet, shimmering "
"into the appearance of %^BLUE%^rolling waters %^BOLD%^%^WHITE%^flowing all "
"around you!%^RESET%^");
       if(!TP->query_invis()) tell_room(ETP,"%^BOLD%^%^BLUE%^Water seems to "
"encompass "+TP->QCN+" as fine sands tumble forth from "+TP->QP+" amulet and "
"shift in color!%^RESET%^",TP);
       setting = 1;
       mynew_longdesc();
     break;
     case "earth":
       tell_object(TP,"%^BOLD%^%^WHITE%^You set your mind to %^RESET%^%^ORANGE%^"
"earth%^WHITE%^ and a wave of fine sands tumbles forth from the amulet, "
"shimmering into the appearance of %^RESET%^%^ORANGE%^stony earth %^BOLD%^"
"%^WHITE%^flowing all around you!%^RESET%^");
       if(!TP->query_invis()) tell_room(ETP,"%^RESET%^%^ORANGE%^Stony earth "
"seems to encompass "+TP->QCN+" as fine sands tumble forth from "+TP->QP+
" amulet and shift in color!%^RESET%^",TP);
       setting = 2;
       mynew_longdesc();
     break;
     case "fire":
       tell_object(TP,"%^BOLD%^%^WHITE%^You set your mind to %^RED%^fire"
"%^WHITE%^ and a wave of fine sands tumbles forth from the amulet, shimmering "
"into the appearance of %^RED%^roaring flames %^BOLD%^%^WHITE%^flowing all "
"around you!%^RESET%^");
       if(!TP->query_invis()) tell_room(ETP,"%^BOLD%^%^RED%^Fire seems to "
"encompass "+TP->QCN+" as fine sands tumble forth from "+TP->QP+" amulet and "
"shift in color!%^RESET%^",TP);
       setting = 3;
       mynew_longdesc();
     break;
     case "air":
       tell_object(TP,"%^BOLD%^%^WHITE%^You set your mind to %^CYAN%^air"
"%^WHITE%^ and a wave of fine sands tumbles forth from the amulet, shimmering "
"into the appearance of %^CYAN%^translucent clouds %^BOLD%^%^WHITE%^flowing all "
"around you!%^RESET%^");
       if(!TP->query_invis()) tell_room(ETP,"%^BOLD%^%^CYAN%^Clouds seems to "
"encompass "+TP->QCN+" as fine sands tumble forth from "+TP->QP+" amulet and "
"shift in color!%^RESET%^",TP);
       setting = 4;
       mynew_longdesc();
     break;
     default:
       tell_object(TP,"%^BOLD%^%^WHITE%^A few grains of sand escape the mouth "
"of the pendant's oyster shell, reflecting a myriad of colors in the light that "
"remind you of elements.  They flash past your eyes in a whirl of %^RED%^fire"
"%^WHITE%^, %^CYAN%^air%^WHITE%^, %^BLUE%^water%^WHITE%^ and %^RESET%^%^ORANGE%^"
"earth%^BOLD%^%^WHITE%^.%^RESET%^"); 
     break;
   }
   return 1;
}

void mynew_longdesc() {
   string colourz;
   switch(setting) {
     case 1:
       TO->set_short("%^BOLD%^%^WHITE%^Clasp of the %^BLUE%^Shi%^RESET%^%^BLUE%^fti%^BOLD%^ng Sa%^RESET%^%^BLUE%^nds%^RESET%^");
       TO->set_obvious_short("%^BOLD%^%^WHITE%^a cloak made of %^BLUE%^shi%^RESET%^%^BLUE%^fti%^BOLD%^ng sa%^RESET%^%^BLUE%^nds%^RESET%^");
       colourz = "%^BOLD%^%^BLUE%^sw%^RESET%^%^BLUE%^irl%^BOLD%^ing%^RESET%^%^BLUE%^ wat%^BOLD%^er";
     break;
     case 2:
       TO->set_short("%^BOLD%^%^WHITE%^Clasp of the %^RESET%^%^ORANGE%^Shi%^GREEN%^fti%^ORANGE%^ng Sa%^GREEN%^nds%^RESET%^");
       TO->set_obvious_short("%^BOLD%^%^WHITE%^a cloak made of %^RESET%^%^ORANGE%^shi%^GREEN%^fti%^ORANGE%^ng sa%^GREEN%^nds%^RESET%^");
       colourz = "%^RESET%^%^ORANGE%^st%^BOLD%^%^BLACK%^on%^RESET%^%^ORANGE%^y e%^BOLD%^%^BLACK%^ar%^RESET%^%^ORANGE%^th";
     break;
     case 3:
       TO->set_short("%^BOLD%^%^WHITE%^Clasp of the %^RED%^Shi%^RESET%^%^RED%^fti%^BOLD%^ng Sa%^RESET%^%^RED%^nds%^RESET%^");
       TO->set_obvious_short("%^BOLD%^%^WHITE%^a cloak made of %^RED%^shi%^RESET%^%^RED%^fti%^BOLD%^ng sa%^RESET%^%^RED%^nds%^RESET%^");
       colourz = "%^BOLD%^%^RED%^ra%^RESET%^%^RED%^gin%^BOLD%^g f%^RESET%^%^RED%^lam%^BOLD%^es";
     break;
     case 4:
       TO->set_short("%^BOLD%^%^WHITE%^Clasp of the %^CYAN%^Shi%^RESET%^%^CYAN%^fti%^BOLD%^ng Sa%^RESET%^%^CYAN%^nds%^RESET%^");
       TO->set_obvious_short("%^BOLD%^%^WHITE%^a cloak made of %^CYAN%^shi%^RESET%^%^CYAN%^fti%^BOLD%^ng sa%^RESET%^%^CYAN%^nds%^RESET%^");
       colourz = "%^BOLD%^%^CYAN%^wh%^WHITE%^ir%^CYAN%^lin%^WHITE%^g a%^CYAN%^ir";
     break;
     default:
       if(objectp(ETO)) tell_object(ETO,"Something is wrong with your pendant, call an imm.");
       colourz = "nothing";
     break;
   }
   set_id(({"clasp","clasp of the shifting sands","cloak","cloak made of shifting sands","shifting sands","shifting sands cloak","cloak of sands",}));
   set_long("%^RESET%^%^CYAN%^A half moon shard of polished %^ORANGE%^oyster "
"shell %^CYAN%^hangs from a thin %^BOLD%^%^WHITE%^mithril chain%^RESET%^%^CYAN%^"
".  The pendant's shape is such that the curves of the half moon nearly touch "
"their points together.  Only the tiniest of space between the curves of oyster "
"shell remains open.  Hanging within the center of that opening, a perfect "
"%^BOLD%^%^BLACK%^black pearl %^RESET%^%^CYAN%^can be seen.  Tiny mithril links "
"bind it to the center of the oyster shell, allowing it to swing freely and "
"shed a fine, %^RED%^mu%^ORANGE%^lti%^BOLD%^%^BLUE%^hu%^CYAN%^ed %^RESET%^"
"%^CYAN%^sand.  The dust sifts down in a flowing wave, around the circuit of "
"the mithril links and down into a cloak of rippling colors.  The colors "
"reflect a pattern of "+colourz+" %^RESET%^%^CYAN%^in constant movement across "
"the surface of the magical garment.%^RESET%^\n");
}

void reset_longdesc() {
   set_id(({"clasp","clasp of the shifting sands","pendant","shell pendant","oyster shell pendant","pearl pendant","pearl and oyster shell pendant",}));
   set_short("%^RESET%^%^CYAN%^Clasp of the %^RED%^Shi%^ORANGE%^fti%^BOLD%^%^BLUE%^ng Sa%^CYAN%^nds%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^a %^BOLD%^%^BLACK%^pearl %^RESET%^%^CYAN%^and %^ORANGE%^oyster shell %^CYAN%^pendant%^RESET%^");
   set_long("%^RESET%^%^CYAN%^A half moon shard of polished %^ORANGE%^oyster "
"shell %^CYAN%^hangs from a thin %^BOLD%^%^WHITE%^mithril chain%^RESET%^%^CYAN%^"
".  The pendant's shape is such that the curves of the half moon nearly touch "
"their points together.  Only the tiniest of space between the curves of oyster "
"shell remains open.  Hanging within the center of that opening, a perfect "
"%^BOLD%^%^BLACK%^black pearl %^RESET%^%^CYAN%^can be seen.  Tiny mithril links "
"bind it to the center of the oyster shell, allowing it to swing freely and "
"shed a fine, %^RED%^mu%^ORANGE%^lti%^BOLD%^%^BLUE%^hu%^CYAN%^ed %^RESET%^"
"%^CYAN%^sand.  The dust sifts down to the point where the shell nearly closes "
"and then vanishes, causing you to wonder just what is going on with this "
"pendant.%^RESET%^\n");
}
