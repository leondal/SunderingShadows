// updated bonuses to meet current standards. N, 24/1/20.
#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int OWNED, charges, limbset; // limbset 0 = feet, 1 = forehooves, 2 = hooves, 3 = forepaws
string *owners;
void set_my_lore();
void change_limbs(int limbid);

void create() {
   ::create();
   set_name("gray boots");
   set_id(({"boots","gray boots","mottled boots","mottled gray boots","boots of teleportation","greater boots of teleportation"}));
   set_short("%^BOLD%^%^BLACK%^Greater Boots of %^RESET%^%^CYAN%^Tel%^BOLD%^e%^RESET%^%^CYAN%^po%^BOLD%^r%^RESET%^%^CYAN%^ta%^BOLD%^t%^RESET%^%^CYAN%^ion%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y boots%^RESET%^");
   set_long("These boots are of fine make, crafted from %^ORANGE%^thick "
"leather%^RESET%^. They are rounded at the toe for greater %^CYAN%^comfort"
"%^RESET%^, and cut high to enclose partway up the wearer's calf. They are "
"%^RED%^stu%^MAGENTA%^r%^RED%^dy %^RESET%^and resilient to damage, with thick "
"soles to prevent any injury to the foot. Lacings travel up the insides, "
"allowing the wearer to adjust them, without the laces getting caught or "
"snagged as they travel. The dull, %^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^"
"%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y%^RESET%^ color of the boots "
"lends a similar appearance to dark stone, making you wonder what kind of "
"creature the leather was taken from.\n");
   set_property("lore difficulty",35);
   set_property("id difficulty",35);
   set_limbs(({"right foot","left foot"}));
   set_weight(2);
   set_value(1350);
   set_size(-1);
   set_ac(0);
   set_property("enchantment",5);
   while((int)TO->query_property("enchantment") != 5){
      remove_property("enchantment");
      set_property("enchantment",5);
   }
   set_item_bonus("dexterity",4);
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   charges = 15+ random(6);
   set_my_lore();
   owners = ({});
   set_property("no alter",1);
   limbset = 0;
}

void init() {
   ::init();
   add_action("teleportme","teleportme");
   if(userp(ETO)) {
     if((string)ETO->query_race() == "centaur") { if(limbset != 1) change_limbs(1); return; }
     if((string)ETO->query_race() == "minotaur") { if(limbset != 2) change_limbs(2); return; }
     if((string)ETO->query_race() == "wemic") { if(limbset != 3) change_limbs(3); return; }
     if(limbset != 0) change_limbs(0);
   }
}

void change_limbs(int limbid){
     string basetype;

     basetype = TO->query_name();
     tell_object(ETO,"%^BOLD%^%^CYAN%^The "+basetype+" shift and change to fit you!%^RESET%^");
     tell_room(EETO,"%^BLUE%^The "+basetype+" shift and change to fit "+ETO->QCN+"!",ETO);
     limbset = limbid;

     switch(limbid) {
       case 0: //feet
         TO->set_limbs(({"right foot","left foot"}));
         set_name("gray boots");
         set_id(({"boots","gray boots","mottled boots","mottled gray boots","boots of teleportation","greater boots of teleportation"}));
         set_short("%^BOLD%^%^BLACK%^Greater Boots of %^RESET%^%^CYAN%^Tel%^BOLD%^e%^RESET%^%^CYAN%^po%^BOLD%^r%^RESET%^%^CYAN%^ta%^BOLD%^t%^RESET%^%^CYAN%^ion%^RESET%^");
         set_obvious_short("%^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y boots%^RESET%^");
         set_long("These boots are of fine make, crafted from %^ORANGE%^thick "
"leather%^RESET%^. They are rounded at the toe for greater %^CYAN%^comfort"
"%^RESET%^, and cut high to enclose partway up the wearer's calf. They are "
"%^RED%^stu%^MAGENTA%^r%^RED%^dy %^RESET%^and resilient to damage, with thick "
"soles to prevent any injury to the foot. Lacings travel up the insides, "
"allowing the wearer to adjust them, without the laces getting caught or "
"snagged as they travel. The dull, %^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^"
"%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y%^RESET%^ color of the boots "
"lends a similar appearance to dark stone, making you wonder what kind of "
"creature the leather was taken from.\n");
       break;
       case 1: //forehooves
         TO->set_limbs(({"right forehoof","left forehoof"}));
         TO->set_name("gray guards");
         TO->set_id(({"guards","gray guards","mottled guards","mottled gray guards","guards of teleportation","greater guards of teleportation"}));
         TO->set_short("%^BOLD%^%^BLACK%^Greater Guards of %^RESET%^%^CYAN%^Tel%^BOLD%^e%^RESET%^%^CYAN%^po%^BOLD%^r%^RESET%^%^CYAN%^ta%^BOLD%^t%^RESET%^%^CYAN%^ion%^RESET%^");
         TO->set_obvious_short("%^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y guards%^RESET%^");
         TO->set_long("These leg guards are of fine make, crafted from %^ORANGE%^thick "
"leather%^RESET%^. They widen at the base for greater %^CYAN%^comfort%^RESET%^, "
"and are cut high to enclose partway up the wearer's foreleg. They are "
"%^RED%^stu%^MAGENTA%^r%^RED%^dy %^RESET%^and resilient to damage, with thick "
"reinforcements to prevent any injury to the hooves or ankles. Lacings travel up the insides, "
"allowing the wearer to adjust them, without the laces getting caught or "
"snagged as they travel. The dull, %^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^"
"%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y%^RESET%^ color of the guards "
"lends a similar appearance to dark stone, making you wonder what kind of "
"creature the leather was taken from.\n");
       break;
       case 2: //hooves
         TO->set_limbs(({"right hoof","left hoof"}));
         TO->set_name("gray guards");
         TO->set_id(({"guards","gray guards","mottled guards","mottled gray guards","guards of teleportation","greater guards of teleportation"}));
         TO->set_short("%^BOLD%^%^BLACK%^Greater Guards of %^RESET%^%^CYAN%^Tel%^BOLD%^e%^RESET%^%^CYAN%^po%^BOLD%^r%^RESET%^%^CYAN%^ta%^BOLD%^t%^RESET%^%^CYAN%^ion%^RESET%^");
         TO->set_obvious_short("%^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y guards%^RESET%^");
         TO->set_long("These leg guards are of fine make, crafted from %^ORANGE%^thick "
"leather%^RESET%^. They widen at the base for greater %^CYAN%^comfort%^RESET%^, "
"and are cut high to enclose partway up the wearer's foreleg. They are "
"%^RED%^stu%^MAGENTA%^r%^RED%^dy %^RESET%^and resilient to damage, with thick "
"reinforcements to prevent any injury to the hooves or ankles. Lacings travel up the insides, "
"allowing the wearer to adjust them, without the laces getting caught or "
"snagged as they travel. The dull, %^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^"
"%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y%^RESET%^ color of the guards "
"lends a similar appearance to dark stone, making you wonder what kind of "
"creature the leather was taken from.\n");
       break;
       case 3: //forepaws
         TO->set_limbs(({"right forepaw","left forepaw"}));
         TO->set_name("gray guards");
         TO->set_id(({"guards","gray guards","mottled guards","mottled gray guards","guards of teleportation","greater guards of teleportation"}));
         TO->set_short("%^BOLD%^%^BLACK%^Greater Guards of %^RESET%^%^CYAN%^Tel%^BOLD%^e%^RESET%^%^CYAN%^po%^BOLD%^r%^RESET%^%^CYAN%^ta%^BOLD%^t%^RESET%^%^CYAN%^ion%^RESET%^");
         TO->set_obvious_short("%^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y guards%^RESET%^");
         TO->set_long("These leg guards are of fine make, crafted from %^ORANGE%^thick "
"leather%^RESET%^. They widen at the base for greater %^CYAN%^comfort%^RESET%^, "
"and are cut high to enclose partway up the wearer's foreleg. They are "
"%^RED%^stu%^MAGENTA%^r%^RED%^dy %^RESET%^and resilient to damage, with thick "
"reinforcements to prevent any injury to the paws or ankles. Lacings travel up the insides, "
"allowing the wearer to adjust them, without the laces getting caught or "
"snagged as they travel. The dull, %^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^"
"%^BLACK%^tled gr%^RESET%^a%^BOLD%^%^BLACK%^y%^RESET%^ color of the guards "
"lends a similar appearance to dark stone, making you wonder what kind of "
"creature the leather was taken from.\n");
       break;
   }
}

int wear_fun() {
    if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
      return 0;
    }
    if(ETO->query_level() < 35) {
      if(!limbset) tell_object(ETO,"You are not experienced enough to use these boots.");
      else tell_object(ETO,"You are not experienced enough to use these guards.");
      return 0;
    }
    if(!limbset) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^The boots fit your feet in unmatched comfort.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" pulls on the comfortable-looking boots.%^RESET%^",ETO);
    }
    else {
      tell_object(ETO,"%^BOLD%^%^BLACK%^The guards fit you in unmatched comfort.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" pulls on the comfortable-looking guards.%^RESET%^",ETO);
    }
    return 1;
}

int teleportme(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     if(!limbset) tell_object(TP,"You need to be wearing the boots.");
     else tell_object(TP,"You need to be wearing the guards.");
     return 1;
   }
   if(!str) {
     tell_object(TP, "You need to specify somewhere to travel to.");
     return 1;
   }
   if(member_array(str,TP->query_rem_rooms_sort()) < 0 ) {
     tell_object(TP, "You don't have anywhere like that memorized.");
     return 1;
   }
   if(ETP->query_property("no teleport")) {
     tell_object(TP, "There is too much magical interference here.");
     return 1;
   }
   if(!charges) {
     if(!limbset) tell_object(TP,"The boots are depleted of magic.");
     else tell_object(TP,"The guards are depleted of magic.");
     return 1;
   }
   charges--;
   set_my_lore();
   new("/cmds/spells/t/_teleport")->use_spell(TP,str,25,100,"mage");
   return 1;
}

void set_my_lore() {
   set_lore("Sir Edward, a noble knight of House Guldwell, is said to first commissioned "
"these enchanted boots.  Sworn to his Lady Mystra to travel the lands and "
"seek out those places where magic's flow ebbed strangely, Sir Edward was "
"content riding the lands on horseback.  But many of those who he was forced "
"to employ in order to solve such problems were not so keen on this form of "
"travel.  In order to facilitate a means by which they could remain at home "
"until needed, Sir Edward sought the aid of the temple's magi to create "
"these boots.  Each was said to be enchanted with the ability to transport "
"one person to a distant location.  This seemed a perfect solution until it "
"became clear that the magic simply could not provide perfect reliability.  "
"After the third member of Sir Edward's team wound up in dangerous places, "
"these boots were abandoned, despite still retaining charges of spell.  In "
"fact, careful study of this set reveals they have "+charges+" charges left.  "
"You're pretty sure you could %^YELLOW%^teleportme location%^RESET%^ to use "
"them.  Such was the power of the magic used that the boots would change to "
"fit any wearer's feet");
}

void renew_charges() { charges = 15+ random(6); set_my_lore(); }
int is_tazrak_charged() { return 1; }

void bind_me(string *pplz) {
   owners += pplz;
   OWNED = 1;
}

string * bound_to() {
   if(sizeof(owners)) return owners;
   return 0;
}