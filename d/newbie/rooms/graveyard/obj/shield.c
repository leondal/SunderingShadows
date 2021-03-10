#include <std.h>
inherit "/d/common/obj/armour/mshield";

int polished;

void create() {
   ::create();
   set_name("shield");
   set_short("%^BOLD%^%^WHITE%^Rashan's Brace%^RESET%^");
   set_obvious_short("%^RESET%^%^WHITE%^a dusty shield%^RESET%^");
   set_id(({"shield","dusty shield","brace","rashans brace","rashan's brace","silver shield"}));
   set_long("This shield is obviously quite old, and is covered in %^BOLD%^%^BLACK%^grime %^RESET%^and "
"%^ORANGE%^dust%^RESET%^.  It must have been quite a %^YELLOW%^magnificent %^RESET%^shield in its early days "
"though, judging by its craftsmanship.  It is quite solid, yet deceptively %^BOLD%^%^WHITE%^light%^RESET%^, "
"and is etched upon the front with an %^CYAN%^elaborate %^RESET%^emblem, though it is difficult to make out "
"under all the grime.  Truth be told, it could do with a good %^BOLD%^%^BLUE%^polish%^RESET%^.\n");
   set_weight(8);
   set_value(8);
   set_lore("%^WHITE%^%^BOLD%^Common folk tales in Offestry recount the valor of their once-town hero, "
"Rashan.  He was said to be a skilled warrior, always clad in brilliant armor and defending the town from the "
"riff-raff beyond its borders.  Finally he was slain defending his hometown from a raid of orcs, after which "
"the townsfolk of Offestry built a tomb in the graveyard in his honor.%^RESET%^\n");
   set_property("lore difficulty",3);
   polished = 0;
   set_wear((:TO,"wearme":));
}

void init() {
   ::init();
   add_action("polish_fun","polish");
}

int wearme(){
   if(!polished && !random(3)) { tell_object(ETO,"A bit of %^ORANGE%^grime %^RESET%^rubs off on your arm as "
"you wear the shield.  It could really do with a good %^BOLD%^%^BLUE%^polish%^RESET%^."); }
   return 1;
}

int polish_fun(string str) {
   if(!objectp(TO)) return 0;
   if(!str) {
     notify_fail("What do you want to polish?\n");
     return 0;
   }
   if(str != "shield") {
     notify_fail("You can't polish that.\n");
     return 0;
   }
   if((int)TO->query_worn()) {
     notify_fail("That might be a bit difficult while you're wearing it.\n");
     return 0;
   }
   if(sizeof(TP->query_attackers()) > 0) {
     notify_fail("That might be a bit difficult while you're fighting.\n");
     return 0;
   }
   if(polished) {
     notify_fail("The shield has already been polished.\n");
     return 0;
   }
   tell_object(TP,"You take a moment to polish the shield to a %^BOLD%^%^WHITE%^brilliant %^RESET%^sheen.");
   tell_room(ETP,""+TP->QCN+" takes a moment to polish the shield to a %^BOLD%^%^WHITE%^brilliant%^RESET%^ "
"sheen.",TP);
   TO->set_obvious_short("%^BOLD%^%^WHITE%^a silver shield%^RESET%^");
   TO->set_long("This %^BOLD%^%^WHITE%^brilliant %^RESET%^silver shield appears quite old, but despite its "
"probable age it is in beautiful condition.  It must have been quite a %^YELLOW%^magnificent %^RESET%^shield "
"in its early days, judging by its craftsmanship.  It is quite solid, yet deceptively %^BOLD%^%^WHITE%^light"
"%^RESET%^, and is etched upon the front with an %^CYAN%^elaborate %^RESET%^emblem of a coiled dragon with "
"spread wings, its fanged maw frozen in a perpetual roar.\n");
   TO->set_value(20);
   polished = 1;
   return 1;
}
