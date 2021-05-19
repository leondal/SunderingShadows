// updated bonuses to meet current standards. N, 24/1/20.
#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/armour/leather_gauntlets";

int OWNED, mytype, charges, timer;
string *owners;
void set_mytype();

void create(){
   ::create();
   set_name("dragonhide gauntlets");
   set_id(({"gauntlets","dragonhide gauntlets","grips","chromatic grips","Chromatic Grips","dragon hide gauntlets"}));
   set_mytype();
   set_lore("%^BOLD%^%^WHITE%^'--And so, having inspired few people with his feats of combat and daring, Korvanus the "
"Dragonslayer turned his sights upon other projects.  Returning to the skills of his youth, he spent many years "
"perfecting the art of armor crafted from the skins of the dragons he hunted so intently.  So well crafted were they, "
"that rumor spoke of them retaining the properties of their original owners, still imbued within the scaled hides.  To "
"%^YELLOW%^grasp %^WHITE%^a foe would unleash such power as still resided within them, though even this faded with time "
"and use.  Korvanus garnered far more fame for his armors than his conquests of dragonkind; strange as it may seem, it "
"became immediately apparent upon viewing his creations just why this was the case.  With each piece of armor coated in "
"tiny teardrop shaped scales, it becomes apparent that Korvanus only ever subdued the youngest of dragons, hatchlings "
"barely flown from the nest.'\n\n%^BOLD%^%^WHITE%^----Famous Armorsmiths of the Tsarven Empire.");
   set_property("lore difficulty",35);
   set_property("id difficulty",30);
   set_value(4500);
   set_size(-1);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("spell damage resistance",25);
   set_item_bonus("endurance",4);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   charges = 20+ random(6);
   timer = 0;
   owners = ({});
}

void init() {
   ::init();
   add_action("grasp_fun","grasp");
}

int wear_fun() {
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
   if(ETO->query_level() < 35) {
     tell_object(ETO,"You are not experienced enough to use these gauntlets!");
     return 0;
   }
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" slides the snug-fitted gauntlets over "+ETO->QP+" hands.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^The gauntlets fit in snug comfort over your hands.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^WHITE%^The gauntlets slide smoothly back off.%^RESET%^");
   return 1;
}

void set_mytype() {
   mytype = random(5);
   switch(mytype) {
     case 0:
     TO->set_short("%^BOLD%^%^BLACK%^Chr%^RESET%^om%^BOLD%^%^BLACK%^atic Gr%^RESET%^i%^BOLD%^%^BLACK%^ps%^RESET%^");
     TO->set_obvious_short("%^BOLD%^%^BLACK%^dra%^RESET%^go%^BOLD%^%^BLACK%^nhide gauntl%^RESET%^e%^BOLD%^%^BLACK%^ts%^RESET%^");
     TO->set_long("%^RESET%^These rugged gauntlets are formed of a tanned hide base, over which lie the interlocking "
"scales of a %^RED%^dragon%^RESET%^.  Each of an elongated pentagonal shape, they look like layered %^CYAN%^te%^GREEN%^a"
"%^CYAN%^rdr%^BOLD%^o%^RESET%^%^CYAN%^ps%^RESET%^, each perfectly overlapped and fitted to leave no gaps between.  The "
"gauntlets themselves are so skillfully crafted, that they would likely offer similar freedom of movement to that of the "
"original creature from which they were made.  Each scale has a horny, translucent texture that affords it a permanent "
"glossy lustre.  The scales range in hue from a polished %^BOLD%^%^BLACK%^eb%^WHITE%^o%^BLACK%^n %^RESET%^sheen through "
"to more dull, %^BOLD%^%^BLACK%^m%^RESET%^at%^BOLD%^%^BLACK%^te black %^RESET%^texture.  Held close, a faint scent of "
"rotted vegetation can be noticed around the gauntlets, with a faint %^BOLD%^%^GREEN%^ac%^WHITE%^i%^GREEN%^dic %^RESET%^"
"undertone, perhaps a remnant of their original owner.\n");
     break;

     case 1:
     TO->set_short("%^RESET%^%^CYAN%^Chr%^BOLD%^om%^RESET%^%^CYAN%^atic Gr%^BOLD%^i%^RESET%^%^CYAN%^ps%^RESET%^");
     TO->set_obvious_short("%^RESET%^%^CYAN%^dra%^BOLD%^go%^RESET%^%^CYAN%^nhide gauntl%^BOLD%^e%^RESET%^%^CYAN%^ts%^RESET%^");
     TO->set_long("%^RESET%^These rugged gauntlets are formed of a tanned hide base, over which lie the interlocking "
"scales of a %^RED%^dragon%^RESET%^.  Each of an elongated pentagonal shape, they look like layered %^CYAN%^te%^GREEN%^a"
"%^CYAN%^rdr%^BOLD%^o%^RESET%^%^CYAN%^ps%^RESET%^, each perfectly overlapped and fitted to leave no gaps between.  The "
"gauntlets themselves are so skillfully crafted, that they would likely offer similar freedom of movement to that of the "
"original creature from which they were made.  Each scale has a horny, translucent texture that affords it a permanent "
"glossy lustre.  The scales range in hue from an iridescent %^BOLD%^%^CYAN%^az%^RESET%^%^CYAN%^ur%^BOLD%^e %^RESET%^sheen "
"through to %^MAGENTA%^deep i%^BLUE%^n%^MAGENTA%^digo%^RESET%^.  Held close, the soft hum and crackle of minor %^YELLOW%^"
"st%^WHITE%^a%^YELLOW%^t%^WHITE%^ic %^RESET%^can be heard around the gauntlets, perhaps a remnant of their original owner"
".\n");
     break;

     case 2:
     TO->set_short("%^RESET%^%^GREEN%^Chr%^BOLD%^om%^RESET%^%^GREEN%^atic Gr%^BOLD%^i%^RESET%^%^GREEN%^ps%^RESET%^");
     TO->set_obvious_short("%^RESET%^%^GREEN%^dra%^BOLD%^go%^RESET%^%^GREEN%^nhide gauntl%^BOLD%^e%^RESET%^%^GREEN%^ts%^RESET%^");
     TO->set_long("%^RESET%^These rugged gauntlets are formed of a tanned hide base, over which lie the interlocking "
"scales of a %^RED%^dragon%^RESET%^.  Each of an elongated pentagonal shape, they look like layered %^CYAN%^te%^GREEN%^a"
"%^CYAN%^rdr%^BOLD%^o%^RESET%^%^CYAN%^ps%^RESET%^, each perfectly overlapped and fitted to leave no gaps between.  The "
"gauntlets themselves are so skillfully crafted, that they would likely offer similar freedom of movement to that of the "
"original creature from which they were made.  Each scale has a horny, translucent texture that affords it a permanent "
"glossy lustre.  The scales range in hue through shades of %^GREEN%^fo%^CYAN%^re%^GREEN%^st%^RESET%^, %^BOLD%^%^GREEN%^em"
"%^YELLOW%^e%^WHITE%^r%^GREEN%^a%^RESET%^%^GREEN%^l%^BOLD%^d %^RESET%^and %^ORANGE%^ol%^GREEN%^iv%^ORANGE%^e %^RESET%^"
"green.  Held close, the bitter tang of %^CYAN%^chlorine gas %^RESET%^can be smelled around the gauntlets, perhaps a "
"remnant of their original owner.\n");
     break;

     case 3:
     TO->set_short("%^RESET%^%^RED%^Chr%^BOLD%^om%^RESET%^%^RED%^atic Gr%^BOLD%^i%^RESET%^%^RED%^ps%^RESET%^");
     TO->set_obvious_short("%^RESET%^%^RED%^dra%^BOLD%^go%^RESET%^%^RED%^nhide gauntl%^BOLD%^e%^RESET%^%^RED%^ts%^RESET%^");
     TO->set_long("%^RESET%^These rugged gauntlets are formed of a tanned hide base, over which lie the interlocking "
"scales of a %^RED%^dragon%^RESET%^.  Each of an elongated pentagonal shape, they look like layered %^CYAN%^te%^GREEN%^a"
"%^CYAN%^rdr%^BOLD%^o%^RESET%^%^CYAN%^ps%^RESET%^, each perfectly overlapped and fitted to leave no gaps between.  The "
"gauntlets themselves are so skillfully crafted, that they would likely offer similar freedom of movement to that of the "
"original creature from which they were made.  Each scale has a horny, translucent texture that affords it a permanent "
"glossy lustre.  The scales range in hue from a bright %^BOLD%^%^RED%^sc%^YELLOW%^a%^RED%^rlet %^RESET%^sheen through to "
"more dull shade of %^RED%^crim%^MAGENTA%^so%^RED%^n%^RESET%^.  Held close, a mild scent of %^RED%^sulfur %^RESET%^and "
"%^BOLD%^%^BLACK%^pum%^RED%^i%^BLACK%^ce %^RESET%^can be smelled around the gauntlets, perhaps a remnant of their "
"original owner.\n");
     break;

     case 4:
     TO->set_short("%^BOLD%^%^WHITE%^Chr%^CYAN%^om%^WHITE%^atic Gr%^CYAN%^i%^WHITE%^ps%^RESET%^");
     TO->set_obvious_short("%^BOLD%^%^WHITE%^dra%^CYAN%^go%^WHITE%^nhide gauntl%^CYAN%^e%^WHITE%^ts%^RESET%^");
     TO->set_long("%^RESET%^These rugged gauntlets are formed of a tanned hide base, over which lie the interlocking "
"scales of a %^RED%^dragon%^RESET%^.  Each of an elongated pentagonal shape, they look like layered %^CYAN%^te%^GREEN%^a"
"%^CYAN%^rdr%^BOLD%^o%^RESET%^%^CYAN%^ps%^RESET%^, each perfectly overlapped and fitted to leave no gaps between.  The "
"gauntlets themselves are so skillfully crafted, that they would likely offer similar freedom of movement to that of the "
"original creature from which they were made.  Each scale has a horny, translucent texture that affords it a permanent "
"glossy lustre.  The scales glisten in a %^BOLD%^%^WHITE%^pure white %^RESET%^layer, intermittently interrupted with a "
"few of pale %^CYAN%^bl%^RESET%^u%^CYAN%^e %^RESET%^and %^BOLD%^%^BLACK%^gray%^RESET%^.  Held close, a light %^BOLD%^"
"%^CYAN%^c%^WHITE%^h%^CYAN%^ill %^RESET%^can be felt in the air around the gauntlets, perhaps a remnant of their original "
"owner.\n");
     break;
   }
}

int grasp_fun(string str) {
   object mytarg;
   if(!TO->query_worn()) return notify_fail("You should wear the gauntlets first.\n");
   if(!str) return notify_fail("Grasp what?\n");
   if(!mytarg = present(str,ETP)) return notify_fail("That is not here to grasp.\n");
   if(!living(mytarg)) return notify_fail("You can't grasp that.\n");
   if(mytarg->query_true_invis()) return notify_fail("That is not here to grasp.\n");
   if(!charges) return notify_fail("The power in the gauntlets is already depleted.\n");
   if(timer > time()) return notify_fail("You've just used that!\n");
   switch(mytype) {
     case 0:
     tell_object(TP,"%^BOLD%^%^BLACK%^You lash out and grab hold of "+mytarg->QCN+" with a gauntleted fist.  Drops of "
"%^GREEN%^acid %^BLACK%^hiss from between the scales onto "+mytarg->QP+" skin, and the acrid smell of burning flesh "
"rises into the air.%^RESET%^");
     tell_object(mytarg,"%^BOLD%^%^BLACK%^"+ETO->QCN+" lashes out and grabs hold of you with a gauntleted fist.  Drops of "
"%^GREEN%^acid %^BLACK%^hiss from between the scales onto your skin, leaving horrible burns wherever they fall!%^RESET%^");
     tell_room(ETP,"%^BOLD%^%^BLACK%^"+ETO->QCN+" lashes out and grabs hold of "+mytarg->QCN+" with a gauntleted fist.  "
"Drops of %^GREEN%^acid %^BLACK%^hiss from between the scales onto "+mytarg->QP+" skin, and the acrid smell of burning "
"flesh rises into the air.%^RESET%^",({TP,mytarg}));
     break;

     case 1:
     tell_object(TP,"%^RESET%^%^BLUE%^You lash out and grab hold of "+mytarg->QCN+" with a gauntleted fist.  Crackles of "
"%^YELLOW%^lig%^WHITE%^h%^YELLOW%^tning %^RESET%^%^BLUE%^arc between the scales and onto "+mytarg->QP+" skin, and the "
"acrid smell of burning flesh rises into the air.%^RESET%^");
     tell_object(mytarg,"%^RESET%^%^BLUE%^"+ETO->QCN+" lashes out and grabs hold of you with a gauntleted fist.  Crackles "
"of %^YELLOW%^lig%^WHITE%^h%^YELLOW%^tning %^RESET%^%^BLUE%^arc between the scales and onto your skin, leaving horrible "
"burns in their wake!%^RESET%^");
     tell_room(ETP,"%^RESET%^%^BLUE%^"+ETO->QCN+" lashes out and grabs hold of "+mytarg->QCN+" with a gauntleted fist.  "
"Crackles of %^YELLOW%^lig%^WHITE%^h%^YELLOW%^tning %^RESET%^%^BLUE%^arc between the scales and onto "+mytarg->QP+" skin"
", and the acrid smell of burning flesh rises into the air.%^RESET%^",({TP,mytarg}));
     break;

     case 2:
     tell_object(TP,"%^RESET%^%^GREEN%^You lash out and grab hold of "+mytarg->QCN+" with a gauntleted fist.  A hiss of "
"%^BOLD%^sickly gas %^RESET%^%^GREEN%^is emitted from between the scales to coat "+mytarg->QP+" skin, and the acrid smell "
"of burning flesh rises into the air.%^RESET%^");
     tell_object(mytarg,"%^RESET%^%^GREEN%^"+ETO->QCN+" lashes out and grabs hold of you with a gauntleted fist.  A hiss "
"of %^BOLD%^sickly gas %^RESET%^%^GREEN%^is emitted from between the scales to coat "+mytarg->QP+" skin, eating away at "
"your skin wherever it touches!%^RESET%^");
     tell_room(ETP,"%^RESET%^%^GREEN%^"+ETO->QCN+" lashes out and grabs hold of "+mytarg->QCN+" with a gauntleted fist.  "
"A hiss of %^BOLD%^sickly gas %^RESET%^%^GREEN%^is emitted from between the scales to coat "+mytarg->QP+" skin, and the "
"acrid smell of burning flesh rises into the air.%^RESET%^",({TP,mytarg}));
     break;

     case 3:
     tell_object(TP,"%^RESET%^%^RED%^You lash out and grab hold of "+mytarg->QCN+" with a gauntleted fist.  Whisps of "
"%^RESET%^steam %^RED%^rise from between the scales where they contact "+mytarg->QP+" skin, and the acrid smell of "
"burning flesh rises into the air.%^RESET%^");
     tell_object(mytarg,"%^RESET%^%^RED%^"+ETO->QCN+" lashes out and grabs hold of you with a gauntleted fist.  Whisps of "
"%^RESET%^steam %^RED%^rise from between the scales where they contact your skin, leaving a scalding burn wherever they "
"touch!%^RESET%^");
     tell_room(ETP,"%^RESET%^%^RED%^"+ETO->QCN+" lashes out and grabs hold of "+mytarg->QCN+" with a gauntleted fist.  "
"Whisps of %^RESET%^steam %^RED%^rise from between the scales where they contact "+mytarg->QP+" skin, and the acrid smell "
"of burning flesh rises into the air.%^RESET%^",({TP,mytarg}));
     break;

     case 4:
     tell_object(TP,"%^BOLD%^%^WHITE%^You lash out and grab hold of "+mytarg->QCN+" with a gauntleted fist.  Tendrils of "
"%^CYAN%^hoarf%^WHITE%^r%^CYAN%^ost %^WHITE%^snake out from beneath the scales where they contact "+mytarg->QP+" skin, "
"and the acrid smell of burning flesh rises into the air.%^RESET%^");
     tell_object(mytarg,"%^BOLD%^%^WHITE%^"+ETO->QCN+" lashes out and grabs hold of you with a gauntleted fist.  Tendrils "
"of %^CYAN%^hoarf%^WHITE%^r%^CYAN%^ost %^WHITE%^snake out from beneath the scales where they contact your skin, leaving "
"chilling burns wherever they touch!%^RESET%^");
     tell_room(ETP,"%^BOLD%^%^WHITE%^"+ETO->QCN+" lashes out and grabs hold of "+mytarg->QCN+" with a gauntleted fist.  "
"Tendrils of %^CYAN%^hoarf%^WHITE%^r%^CYAN%^ost %^WHITE%^snake out from beneath the scales where they contact "
+mytarg->QP+" skin, and the acrid smell of burning flesh rises into the air.%^RESET%^",({TP,mytarg}));
     break;
   }
   mytarg->do_damage("torso",random(20)+21);
   timer = time() + 60;
   return 1;
}

void renew_charges() { charges = 20+ random(6); }
int is_tazrak_charged() { return 1; }

void bind_me(string *pplz) {
   owners += pplz;
   OWNED = 1;
}

string * bound_to() {
   if(sizeof(owners)) return owners;
   return 0;
}
