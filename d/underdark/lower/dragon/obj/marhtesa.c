#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/quarter_staff";

int OWNED,charges,tracker;
string *owners;
void set_my_lore();

void create(){
    ::create();
    set_name("spiral longstaff");
    set_id( ({"staff","greatstaff","greatstaff of renewal","spiral longstaff","longstaff","marhtesa"}) );
    set_short("%^RESET%^%^MAGENTA%^M%^RED%^ar%^MAGENTA%^ht%^RED%^es%^MAGENTA%^"
"a %^BOLD%^%^WHITE%^- Lo%^CYAN%^n%^WHITE%^gst%^CYAN%^a%^WHITE%^ff of "
"%^YELLOW%^Re%^CYAN%^n%^WHITE%^e%^CYAN%^w%^YELLOW%^al%^RESET%^");
    set_obvious_short("%^WHITE%^%^BOLD%^a %^RESET%^%^MAGENTA%^s%^RED%^"
"p%^MAGENTA%^i%^RED%^r%^MAGENTA%^a"
"%^RED%^l %^BOLD%^%^CYAN%^longstaff %^WHITE%^inset with a "
"%^RESET%^tran%^BOLD%^%^BLACK%^s%^RESET%^lucent cry%^BOLD%^"
"%^BLACK%^s%^RESET%^tal%^RESET%^");
    set_long("This %^CYAN%^%^BOLD%^or%^WHITE%^na%^CYAN%^te %^RESET%^longstaff "
"has been carved from what appears to be two different pieces of wood, one "
"with the soft coloring of %^ORANGE%^oak%^RESET%^, and the other with the "
"deeper hue of %^RED%^ro%^MAGENTA%^s%^RED%^ewood%^RESET%^.  They have been "
"twisted %^BOLD%^%^BLACK%^ar%^RESET%^%^WHITE%^t%^BOLD%^%^BLACK%^isti%^RESET%^"
"%^WHITE%^c%^BOLD%^%^BLACK%^ally %^RESET%^around each other by some means of "
"skilled woodcarving, forming a single stave of %^ORANGE%^mu%^RED%^l"
"%^MAGENTA%^t%^RED%^i-%^MAGENTA%^h%^ORANGE%^u%^MAGENTA%^ed %^RESET%^wood.  At "
"the base and near the top, a thin band of %^BOLD%^%^WHITE%^cr%^CYAN%^y"
"%^WHITE%^stal %^RESET%^wraps the staff to secure it together, bordered above "
"and below with fine %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en%^RESET%^ "
"metal.  At the very top, the two spiraling lengths of wood branch to form a "
"winding net, trapped within which is a large shard of%^BOLD%^%^CYAN%^ "
"cr%^WHITE%^y%^CYAN%^st%^WHITE%^a%^CYAN%^l%^RESET%^.  The shard itself seems "
"to have been captured within in its raw state, with%^BOLD%^%^BLACK%^ "
"ja%^RED%^g%^BLACK%^g%^YELLOW%^ed %^RESET%^edges that refract%^BOLD%^ "
"%^WHITE%^light %^RESET%^through the many small openings in the web of wood "
"that encases it.  The staff certainly seems more ornate than serviceable for "
"combat purposes, but the %^BOLD%^%^CYAN%^cr%^WHITE%^y%^CYAN%^st%^WHITE%^"
"a%^CYAN%^l%^RESET%^ held within its grasp radiates a tangible aura of "
"%^CYAN%^po%^GREEN%^w%^CYAN%^er%^RESET%^.");
    set_value(25000);
    set_wc(1,2);
    set_large_wc(1,3);
    set_wield((:TO,"wield_fun":));
    set_unwield((:TO,"unwield_fun":));
    set_property("able to cast", 1);
    set_property("lore difficulty",35);
    set_property("id difficulty",35);
    set_ac(1); // revoked original AC since shields are now changed to none
    tracker = 0;
    charges = 30+random(5);
    set_my_lore();
    set_property("no alter",1);
    owners = ({});
    set_item_bonus("magic resistance",2);
    set_item_bonus("fortitude",3);
    set_item_bonus("reflex",3);
    set_item_bonus("will",3);
}

int wield_fun() {
    if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
      return 0;
    }
    if(!ETO->is_class("cleric")) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^The longstaff seems to have a will of "
"its own, and you just can't seem to get a good enough grip on it to wield "
"it.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" just can't seem to get a "
"good enough grip on the longstaff to wield it.%^RESET%^",ETO);
      return 0;
    }
    if(ETO->query_level() < 35) {
      tell_object(ETO,"You are not experienced enough to use this staff.");
      return 0;
    }
    if (!ETO->query_property("silent_wield")) {
        set_obvious_short("%^WHITE%^%^BOLD%^a %^RESET%^%^MAGENTA%^s%^RED%^"
            "p%^MAGENTA%^i%^RED%^r%^MAGENTA%^a"
            "%^RED%^l %^BOLD%^%^CYAN%^longstaff %^WHITE%^inset with a "
            "%^YELLOW%^gl%^CYAN%^o%^YELLOW%^wing cry%^CYAN%^s%^YELLOW%^tal%^RESET%^");
        tell_object(ETO, "%^BOLD%^%^WHITE%^The %^BOLD%^%^BLACK%^ja%^RED%^g%^BLACK%^"
            "g%^YELLOW%^ed %^WHITE%^crystal inset in the longstaff takes on a "
            "%^RESET%^%^CYAN%^so%^GREEN%^f%^CYAN%^t %^GREEN%^g%^CYAN%^l%^GREEN%^ow"
            "%^BOLD%^%^WHITE%^ as you take hold of it.%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^WHITE%^The %^BOLD%^%^BLACK%^ja%^RED%^g%^BLACK%^"
            "g%^YELLOW%^ed %^WHITE%^crystal inset in the longstaff takes on a %^RESET%^"
            "%^CYAN%^so%^GREEN%^f%^CYAN%^t %^GREEN%^g%^CYAN%^l%^GREEN%^ow%^BOLD%^%^WHITE%^"
            " as " + ETO->QCN + " takes hold of it.%^RESET%^", ETO);
        set_property("enchantment", 5);
        while (query_property("enchantment") != 5) {
            remove_property("enchantment");
            set_property("enchantment", 5);
        }
    }
    return 1;
}

int unwield_fun() {
    if (!ETO->query_property("silent_wield")) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The %^BOLD%^%^BLACK%^ja%^RED%^g%^BLACK%^"
            "g%^YELLOW%^ed %^WHITE%^crystal inset in the longstaff stops %^RESET%^%^GREEN%^g%^CYAN%^l"
            "%^GREEN%^owing%^BOLD%^%^WHITE%^ as you release it.%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^WHITE%^The %^BOLD%^%^BLACK%^ja%^RED%^g%^BLACK%^"
            "g%^YELLOW%^ed %^WHITE%^crystal inset in the longstaff stops %^RESET%^%^GREEN%^g%^CYAN%^"
            "l%^GREEN%^owing%^BOLD%^%^WHITE%^ as " + ETO->QCN + " releases it.%^RESET%^", ETO);
        set_obvious_short("%^WHITE%^%^BOLD%^a %^RESET%^%^MAGENTA%^s%^RED%^"
            "p%^MAGENTA%^i%^RED%^r%^MAGENTA%^a"
            "%^RED%^l %^BOLD%^%^CYAN%^longstaff %^WHITE%^inset with a "
            "%^RESET%^tran%^BOLD%^%^BLACK%^s%^RESET%^lucent cry%^BOLD%^"
            "%^BLACK%^s%^RESET%^tal%^RESET%^");
        remove_property("enchantment");
    }
    return 1;
}

void init(){
    ::init();
    if(userp(ETO)) {
      if((int)TO->query_size() != ((int)ETO->query_size())) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The crystal inset in the staff glints briefly with light as you take "
"hold of it, and the whole weapon changes to fit comfortably in your hand!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^WHITE%^The crystal inset in the staff glints briefly with light as "
+ETO->QCN+" takes hold of it, and the whole weapon changes to fit comfortably in your hand!%^RESET%^",ETO);
        TO->set_size((int)ETO->query_size());
      }
    }
    add_action("heal_me","cure");
    add_action("cleanse_me","cleanse");
    add_action("raise_me","raise");
}

int heal_me(string str) {
   object targ;
   if(!TO->query_wielded()) {
     notify_fail("You should be wielding the staff to activate the spell.\n");
     return 0;
   }
   if(!str) {
     notify_fail("You should specify who you want to heal.\n");
     return 0;
   }
   if(tracker > time()) {
     notify_fail("The staff is still glowing from its last use.\n");
     return 0;
   }
   if(!charges) {
     notify_fail("The staff seems to have run out of charges.\n");
     return 0;
   }
   if(!targ = present(str,ETP)) {
     notify_fail("You can't see that here.\n");
     return 0;
   }
   if (targ->query_property("berserked")) {
     notify_fail("The effects of the berserk rage upon "+targ->QCN+
" would only nullify the healing.\n");
     return 0;
   }
   tracker = time() + 6;
   if(targ == ETO) {
     tell_object(ETO,"%^CYAN%^You focus upon the staff, holding it before you "
"in both hands.%^RESET%^\n%^CYAN%^A brilliant %^ORANGE%^go%^YELLOW%^ld"
"%^RESET%^%^ORANGE%^en %^CYAN%^light shines towards you from the crystal "
"within the staff, and a feeling of %^GREEN%^fre%^BOLD%^s%^RESET%^%^GREEN%^"
"hness %^CYAN%^and %^YELLOW%^vi%^WHITE%^t%^YELLOW%^al%^WHITE%^i%^YELLOW%^ty "
"%^RESET%^%^CYAN%^courses through your body!%^RESET%^");
     tell_room(EETO,"%^CYAN%^"+ETO->QCN+" holds forth "+ETO->QP+" staff "
"before "+ETO->QO+", with a look of %^MAGENTA%^co%^RED%^nc%^MAGENTA%^en%^RED%^"
"tr%^MAGENTA%^at%^RED%^io%^MAGENTA%^n %^CYAN%^on "+ETO->QP+" face.%^RESET%^"
"\n%^CYAN%^A brilliant %^ORANGE%^go%^YELLOW%^ld%^RESET%^%^ORANGE%^en "
"%^CYAN%^light shines forth from the crystal within the staff, centred upon "
+ETO->QCN+"!%^RESET%^",ETO);
     ETO->add_hp((int)ETO->query_max_hp() - ((int)ETO->query_hp()));
   }
   else {
     tell_object(ETO,"%^CYAN%^You focus upon the staff, holding it forth in "
"both hands towards "+targ->QCN+".%^RESET%^\n%^CYAN%^A brilliant "
"%^ORANGE%^go%^YELLOW%^ld%^RESET%^%^ORANGE%^en %^CYAN%^light shines forth "
"from the crystal within the staff, centred upon "+targ->QCN+"!%^RESET%^");
     tell_room(EETO,"%^CYAN%^"+ETO->QCN+" holds forth "+ETO->QP+" staff "
"toward "+targ->QCN+", with a look of %^MAGENTA%^co%^RED%^nc%^MAGENTA%^"
"en%^RED%^tr%^MAGENTA%^at%^RED%^io%^MAGENTA%^n %^CYAN%^on "+ETO->QP+
" face.%^RESET%^\n%^CYAN%^A brilliant %^ORANGE%^go%^YELLOW%^ld%^RESET%^"
"%^ORANGE%^en %^CYAN%^light shines forth from the crystal within the staff, "
"centred upon "+targ->QCN+"!%^RESET%^",ETO);
     tell_object(targ,"%^CYAN%^"+ETO->QCN+" holds forth "+ETO->QP+" staff "
"toward you, with a look of %^MAGENTA%^co%^RED%^nc%^MAGENTA%^en%^RED%^"
"tr%^MAGENTA%^at%^RED%^io%^MAGENTA%^n %^CYAN%^on "+ETO->QP+" face.%^RESET%^"
"\n%^CYAN%^A brilliant %^ORANGE%^go%^YELLOW%^ld%^RESET%^%^ORANGE%^en "
"%^CYAN%^light shines toward you from the crystal within the staff, and a "
"feeling of %^GREEN%^fre%^BOLD%^s%^RESET%^%^GREEN%^hness %^CYAN%^and "
"%^YELLOW%^vi%^WHITE%^t%^YELLOW%^al%^WHITE%^i%^YELLOW%^ty %^RESET%^%^CYAN%^"
"courses through your body!%^RESET%^");
     targ->add_hp((int)targ->query_max_hp() - ((int)targ->query_hp()));
   }
   charges--;
   charges--;
   set_my_lore();
   return 1;
}

int cleanse_me(string str) {
   object targ;
   if(!TO->query_wielded()) {
     notify_fail("You should be wielding the staff to activate the spell.\n");
     return 0;
   }
   if(!str) {
     notify_fail("You should specify who you want to cleanse.\n");
     return 0;
   }
   if(tracker > time()) {
     notify_fail("The staff is still glowing from its last use.\n");
     return 0;
   }
   if(!charges) {
     notify_fail("The staff seems to have run out of charges.\n");
     return 0;
   }
   if(!targ = present(str,ETP)) {
     notify_fail("You can't see that here.\n");
     return 0;
   }
   tracker = time() + 6;
   if(targ == ETO) {
     tell_object(ETO,"%^CYAN%^You focus upon the staff, holding it before you "
"in both hands.%^RESET%^\n%^CYAN%^A vibrant %^GREEN%^e%^BOLD%^me%^RESET%^"
"%^GREEN%^r%^BOLD%^al%^RESET%^%^GREEN%^d %^CYAN%^light shines towards you "
"from the crystal within the staff, and a %^BOLD%^%^BLUE%^cl%^CYAN%^e%^BLUE%^"
"ans%^CYAN%^i%^BLUE%^ng %^RESET%^%^CYAN%^feeling suffuses your "
"body!%^RESET%^");
     tell_room(EETO,"%^CYAN%^"+ETO->QCN+" holds forth "+ETO->QP+" staff "
"before "+ETO->QO+", with a look of %^MAGENTA%^co%^RED%^nc%^MAGENTA%^en%^RED%^"
"tr%^MAGENTA%^at%^RED%^io%^MAGENTA%^n %^CYAN%^on "+ETO->QP+" face.%^RESET%^"
"\n%^CYAN%^A vibrant %^GREEN%^e%^BOLD%^me%^RESET%^%^GREEN%^r%^BOLD%^al"
"%^RESET%^%^GREEN%^d %^CYAN%^light shines forth from the crystal within the "
"staff, centred upon "+ETO->QCN+"!%^RESET%^",ETO);
     if(ETO->query_poisoning()) {
       ETO->set_poisoning((-1)*(int)ETO->query_poisoning());
     }
     ETO->set_blind(0);
     ETO->set_temporary_blind(0);
   }
   else {
     tell_object(ETO,"%^CYAN%^You focus upon the staff, holding it forth in "
"both hands towards "+targ->QCN+".%^RESET%^\n%^CYAN%^A vibrant %^GREEN%^e"
"%^BOLD%^me%^RESET%^%^GREEN%^r%^BOLD%^al%^RESET%^%^GREEN%^d %^CYAN%^light "
"shines forth from the crystal within the staff, centred upon "
+targ->QCN+"!%^RESET%^");
     tell_room(EETO,"%^CYAN%^"+ETO->QCN+" holds forth "+ETO->QP+" staff "
"toward "+targ->QCN+", with a look of %^MAGENTA%^co%^RED%^nc%^MAGENTA%^"
"en%^RED%^tr%^MAGENTA%^at%^RED%^io%^MAGENTA%^n %^CYAN%^on "+ETO->QP+
" face.%^RESET%^\n%^CYAN%^A vibrant %^GREEN%^e%^BOLD%^me%^RESET%^%^GREEN%^r"
"%^BOLD%^al%^RESET%^%^GREEN%^d %^CYAN%^light shines forth from the crystal "
"within the staff, centred upon "+targ->QCN+"!%^RESET%^",ETO);
     tell_object(targ,"%^CYAN%^"+ETO->QCN+" holds forth "+ETO->QP+" staff "
"toward you, with a look of %^MAGENTA%^co%^RED%^nc%^MAGENTA%^en%^RED%^"
"tr%^MAGENTA%^at%^RED%^io%^MAGENTA%^n %^CYAN%^on "+ETO->QP+" face.%^RESET%^"
"\n%^CYAN%^A vibrant %^GREEN%^e%^BOLD%^me%^RESET%^%^GREEN%^r%^BOLD%^al"
"%^RESET%^%^GREEN%^d %^CYAN%^light shines toward you from the crystal within "
"the staff, and a %^BOLD%^%^BLUE%^cl%^CYAN%^e%^BLUE%^ans%^CYAN%^i%^BLUE%^ng "
"%^RESET%^%^CYAN%^feeling suffuses your body!%^RESET%^");
     if(targ->query_poisoning()) {
       targ->set_poisoning((-1)*(int)targ->query_poisoning());
     }
     targ->set_blind(0);
     targ->set_temporary_blind(0);
   }
   charges--;
   set_my_lore();
   return 1;
}

int raise_me(string str) {
   object targ, corpse;
   string body;
   if(!TO->query_wielded()) {
     notify_fail("You should be wielding the staff to activate the spell.\n");
     return 0;
   }
   if(!str) {
     notify_fail("You should specify who you want to cleanse.\n");
     return 0;
   }
   if(tracker > time()) {
     notify_fail("The staff is still glowing from its last use.\n");
     return 0;
   }
   if(charges < 3) {
     notify_fail("The staff seems to have run out of charges.\n");
     return 0;
   }
   body = "corpse of "+ETO->realName(lower_case(str))+"";
   targ = find_player(ETO->realName(lower_case(str)));
   if(!targ) {
     notify_fail("You can't revive someone that doesn't exist.\n");
     return 0;
   }
   if(targ == ETO) {
     notify_fail("You can't revive yourself.\n");
     return 0;
   }
   if (!interactive(targ)) {
     notify_fail("You can only revive active players.");
     return 0;
   }
   if (!targ->query_ghost()) {
     notify_fail(""+capitalize(str)+" does not need to be revived.");
     return 0;
   }
   if (!corpse = present(body,EETO)) {
     notify_fail(""+capitalize(str)+"'s corpse is not here.");
     return 0;
   }
   tracker = time() + 6;
   tell_object(ETO,"%^CYAN%^You focus upon the staff, holding it forth in "
"both hands towards "+targ->QCN+"'s body.%^RESET%^\n%^CYAN%^A gentle "
"%^WHITE%^si%^BOLD%^lv%^RESET%^%^WHITE%^er %^CYAN%^light shines forth from "
"the crystal within the staff, centred upon the corpse, and it draws a "
"shuddering breath as %^GREEN%^li%^CYAN%^f%^GREEN%^e %^CYAN%^flows back into "
"it!%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETO->QCN+" holds forth "+ETO->QP+" staff "
"toward "+targ->QCN+"'s body, with a look of %^MAGENTA%^co%^RED%^nc%^MAGENTA%^"
"en%^RED%^tr%^MAGENTA%^at%^RED%^io%^MAGENTA%^n %^CYAN%^on "+ETO->QP+
" face.%^RESET%^\n%^CYAN%^A gentle %^WHITE%^si%^BOLD%^lv%^RESET%^%^WHITE%^er "
"%^CYAN%^light shines forth from the crystal within the staff, centred upon "
"the corpse, and it draws a shuddering breath as %^GREEN%^li%^CYAN%^f"
"%^GREEN%^e %^CYAN%^flows back into it!%^RESET%^",ETO);
   tell_object(targ,"%^CYAN%^A gentle %^WHITE%^si%^BOLD%^lv%^RESET%^%^WHITE%^"
"er %^CYAN%^light fills the air around you, and you suddenly feel %^GREEN%^"
"li%^CYAN%^f%^GREEN%^e %^CYAN%^flowing back into you!%^RESET%^");
   targ->revive(-10+random(2)+random(3)+1);
   targ->set_hp(targ->query_max_hp());
   targ->set_heart_beat(1);
   targ->cease_all_attacks();
   targ->move_player(EETO);
   corpse->remove();
   charges--;
   charges--;
   charges--;
   set_my_lore();
   return 1;
}

void set_my_lore() {
   set_lore("The lore on this staff is shrouded in mystery for it is said to only appear when the need is "
"great and the will is strong.  There are many who have carried it over the years.  Men and women whose "
"calling it was to serve others and bring healing into the world.  Their gift for compassion and their "
"fortitude for protecting is what gives this staff one of its many names: Marhtesa.  Named after the daughter "
"of an ancient barbarian king whose blood lust was so profound that it threatened to tear a part of the world "
"in two.  His daughter, born from one of his many conquests, was said to have been raised by foster parents "
"who instilled within Marhtesa the courage, will and fortitude to stand up against her barbarous father.  Not "
"alone as many might have tried, but by lifting the spirits of those she tended.  A quiet and caring woman, "
"her healing hand saved many a soul that slowly banded together and then rose up to fight and destroy the "
"tyrant that had ruled with iron fist and cruel hand.\n\nYou can tell by examining the staff that there are "
+charges+" charges remaining in the staff, which would allow you to cure, cleanse or raise a targetted person.");
}

void renew_charges() { charges = 30+random(5); set_my_lore(); }
int is_tazrak_charged() { return 1; }

void bind_me(string *pplz) {
   owners += pplz;
   OWNED = 1;
}

string * bound_to() {
   if(sizeof(owners)) return owners;
   return 0;
}
