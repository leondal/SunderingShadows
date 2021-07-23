#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("ring");
   set_id(({"ring of protection","band","ring","silver ring","delicate ring","delicate silver ring","ring of leaves","delicate ring of leaves","band of seasons","band of the shifting seasons","band of shifting seasons","band of spring's renewal","band of summer's vitality","band of autumn's decline","band of winter's dormance"}));
   set_short("%^RESET%^%^GREEN%^Band of the %^ORANGE%^Sh%^GREEN%^i%^BOLD%^f%^YELLOW%^ti%^RESET%^%^GREEN%^n%^BOLD%^g %^RESET%^%^GREEN%^S%^RESET%^%^WHITE%^e%^RED%^a%^GREEN%^so%^RESET%^%^ORANGE%^n%^GREEN%^s%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^a delicate %^WHITE%^s%^BOLD%^il%^RESET%^%^WHITE%^ve%^BOLD%^r %^RESET%^%^GREEN%^ring%^RESET%^");
   set_long("%^CYAN%^This small, delicate ring is stunningly worked, but seems quite %^MAGENTA%^fragile "
"%^CYAN%^to look at.  It consists of several slender %^WHITE%^s%^BOLD%^il%^RESET%^%^WHITE%^ve%^BOLD%^r "
"%^RESET%^%^CYAN%^threads, interwoven like the vines of some climbing plant.  From them extend small, rounded "
"%^GREEN%^leaves %^CYAN%^etched from the same metal, as though they had grown forth from the ring itself.  The "
"entire piece looks almost lifelike, except for its shining %^WHITE%^s%^BOLD%^il%^RESET%^%^WHITE%^ve%^BOLD%^r "
"%^RESET%^%^GREEN%^surface.\n%^RESET%^"); 
   set_lore("%^WHITE%^%^BOLD%^Rings such as these are almost unheard of nowadays.  They were originally known "
"to be crafted by wood elves, using a form of shamanistic magic unknown even to other elvenkind.  This form of "
"magic was said to be able to capture the very essence of nature itself into a mundane item, permanently "
"imbuing it with the life of the forest itself.%^RESET%^\n");
   set_property("lore difficulty",25);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_weight(2);
   set_size(-1);
   set_ac(0);
   while ((int)TO->query_property("enchantment") != 4) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",4);
   }
   set_item_bonus("fortitude",2);
   set_value(0);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_fun() {
   object *stuff;
   int i,j, flag;

   stuff = TP->all_armour();
   j = sizeof(stuff);
   for(i=0;i<j;i++) {
     if(!objectp(stuff[i])) continue;
     if((string)stuff[i]->query_type() == "ring") {
       if(member_array("ring of protection",stuff[i]->query_id()) != -1) {
         flag = 1;
         break;
       }
     }
   }
   if(flag) {
     write("The magic of the ring already worn prevents you from wearing this one!");
     return 0;
   }
   tell_room(EETO,"%^GREEN%^The silver metal %^WHITE%^sparkles%^GREEN%^ and seems to come to life!%^RESET%^");

   switch(season(time())) {
     case "spring":
       TO->set_short("%^RESET%^%^GREEN%^Band of %^BOLD%^Spr%^RESET%^%^GREEN%^i%^BOLD%^ng's R%^RESET%^%^GREEN%^e%^BOLD%^new%^RESET%^%^GREEN%^a%^BOLD%^l%^RESET%^");
       TO->set_obvious_short("%^RESET%^%^GREEN%^a delicate ring of %^BOLD%^lea%^RESET%^%^GREEN%^v%^BOLD%^es%^RESET%^");
       TO->set_long("%^CYAN%^This small, delicate ring consists of several slender, interwoven vines that seem "
"to be alive!  From them extend small, rounded leaves of a %^GREEN%^healthy green hue%^CYAN%^, as though part "
"of a freshly sprouted seedling.  A handful of tiny %^WHITE%^flower buds%^CYAN%^ are interspersed amongst the "
"leaves, not yet sprouted into bloom.  The entire piece is stunningly %^ORANGE%^lifelike%^CYAN%^, though how "
"such an item could retain its vitality is a mystery.\n%^RESET%^");
     break;
     case "summer":
       TO->set_short("%^RESET%^%^GREEN%^Band of %^BOLD%^Sum%^YELLOW%^m%^GREEN%^er's V%^YELLOW%^i%^GREEN%^tal%^YELLOW%^i%^GREEN%^ty%^RESET%^");
       TO->set_obvious_short("%^RESET%^%^GREEN%^a delicate ring of %^BOLD%^lea%^YELLOW%^v%^GREEN%^es%^RESET%^");
       TO->set_long("%^CYAN%^This small, delicate ring consists of several slender, interwoven vines that seem "
"to be alive!  From them extend glossy, rounded leaves of a %^GREEN%^healthy green hue%^CYAN%^, like those of "
"a flourishing plant at the height of growth.  A handful of little %^WHITE%^blossoms%^CYAN%^ are interspersed "
"amongst the leaves, their tiny petals spread wide.  The entire piece is stunningly %^ORANGE%^lifelike%^CYAN%^"
", though how such an item could retain its vitality is a mystery.\n%^RESET%^");
     break;
     case "autumn":
       TO->set_short("%^RESET%^%^GREEN%^Band of %^ORANGE%^Aut%^RED%^u%^ORANGE%^mn's D%^RED%^e%^ORANGE%^cli%^RED%^n%^ORANGE%^e%^RESET%^");
       TO->set_obvious_short("%^RESET%^%^GREEN%^a delicate ring of %^ORANGE%^lea%^RED%^v%^ORANGE%^es%^RESET%^");
       TO->set_long("%^CYAN%^This small, delicate ring consists of several slender, interwoven vines that seem "
"to be alive!  From them extend round, ruffled leaves of a myriad of colors, from %^GREEN%^deep green%^CYAN%^ "
"through %^RED%^dull red %^CYAN%^and %^ORANGE%^faded brown%^CYAN%^, like those of a plant about to drop its "
"leaves in fall.  A handful of little %^WHITE%^blossoms%^CYAN%^ are interspersed amongst the leaves, most "
"closed and faded as if their time to bloom was finished.  The entire piece is stunningly %^ORANGE%^lifelike"
"%^CYAN%^, though how such an item could retain its vitality is a mystery.\n%^RESET%^");
     break;
     case "winter":
       TO->set_short("%^RESET%^%^GREEN%^Band of %^WHITE%^Win%^GREEN%^t%^WHITE%^er's D%^GREEN%^o%^WHITE%^rma%^GREEN%^n%^WHITE%^ce%^RESET%^");
       TO->set_obvious_short("%^RESET%^%^GREEN%^a delicate ring of %^WHITE%^lea%^GREEN%^v%^WHITE%^es%^RESET%^");
       TO->set_long("%^CYAN%^This small, delicate ring consists of several slender, interwoven vines that seem "
"to be alive!  From them extend small, rounded leaves of a %^GREEN%^glossy green hue%^CYAN%^, like those of "
"a resiliant plant surviving through the harsher seasons.  A scattering of %^WHITE%^powdery dust%^CYAN%^ coats "
"the leaves, although it never seems to fall away from the leaves themselves.  The entire piece is stunningly "
"%^ORANGE%^lifelike%^CYAN%^, though how such an item could retain its vitality is a mystery.\n%^RESET%^");
     break;
     default: break;
   }
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^GREEN%^The ring %^WHITE%^shimmers%^GREEN%^ and again becomes lifeless silver.%^RESET%^");
   TO->set_short("%^RESET%^%^GREEN%^Band of the %^ORANGE%^Sh%^GREEN%^i%^BOLD%^f%^YELLOW%^ti%^RESET%^%^GREEN%^n%^BOLD%^g %^RESET%^%^GREEN%^S%^RESET%^%^WHITE%^e%^RED%^a%^GREEN%^so%^RESET%^%^ORANGE%^n%^GREEN%^s%^RESET%^");
   TO->set_obvious_short("%^RESET%^%^GREEN%^a delicate %^WHITE%^s%^BOLD%^il%^RESET%^%^WHITE%^ve%^BOLD%^r %^RESET%^%^GREEN%^ring%^RESET%^");
   TO->set_long("%^CYAN%^This small, delicate ring is stunningly worked, but seems quite %^MAGENTA%^fragile "
"%^CYAN%^to look at.  It consists of several slender %^WHITE%^s%^BOLD%^il%^RESET%^%^WHITE%^ve%^BOLD%^r "
"%^RESET%^%^CYAN%^threads, interwoven like the vines of some climbing plant.  From them extend small, rounded "
"%^GREEN%^leaves %^CYAN%^etched from the same metal, as though they had grown forth from the ring itself.  The "
"entire piece looks almost lifelike, except for its shining %^WHITE%^s%^BOLD%^il%^RESET%^%^WHITE%^ve%^BOLD%^r "
"%^RESET%^%^GREEN%^surface.\n%^RESET%^"); 
   return 1;
}