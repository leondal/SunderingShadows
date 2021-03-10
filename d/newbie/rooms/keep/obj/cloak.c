#include <std.h>
inherit ARMOUR;

#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})
#define COLORS2 ({"pure white","dark crimson","bright scarlet","forest green","midnight black","deep cobalt","daffodil yellow","pale tan","sky blue","aquamarine","dusky violet","baby pink"})

void create() {
   ::create();
   set_name("cloak");
   set_short("%^BOLD%^%^WHITE%^Chromatic Cloak%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A long pure white cloak%^RESET%^");
   set_id(({"cloak", "long cloak", "newbiecloakobject"}));
   set_long("This beautiful %^BOLD%^%^WHITE%^pure white %^RESET%^cloak is sewn from soft cotton, lightweight "
"and comfortable as it rests upon the shoulders.  A small %^BOLD%^%^WHITE%^silver%^RESET%^ clasp holds it at "
"the throat, from where it falls over the shoulders and down the wearer's back, reaching partway down their "
"legs.  It is mostly simple in design, except for the fine tracing of matching %^BOLD%^%^WHITE%^silver "
"%^RESET%^embroidery along its hem, marking it with a touch of elegance.  Along the inner lining are some "
"embroidered words that you could probably %^BOLD%^%^BLUE%^read%^RESET%^.\n");
   set_weight(2);
   set_value(25);
   set_limbs(({"neck"}));
   set_type("clothing");
   set_size(2);
   set_lore("%^WHITE%^%^BOLD%^A cloak such as this is a common trinket of many wizards, imbued with the magic "
"of their craft.  This kind in particular were enspelled with the ability to change color upon the will of the "
"wearer; they would simply need to %^YELLOW%^concentrate on%^WHITE%^ the color they wished for.%^RESET%^\n");
   set_property("lore difficulty",3);
   set_read("\n%^BOLD%^%^WHITE%^Simply %^YELLOW%^concentrate on %^WHITE%^the color you wish for.%^RESET%^");
   set_wear("%^BOLD%^%^WHITE%^You drape the beautiful cloak around your shoulders.%^RESET%^");
   set_remove("%^BOLD%^%^WHITE%^You unclasp the cloak and remove it.%^RESET%^");
}

void init() {
   ::init();
   add_action("concentrate_fun","concentrate");
}

int concentrate_fun(string str) {
   int tracker;
   if(!objectp(TO)) return 0;
   if(!objectp(TP)) return 0;
   if(!str) {
     notify_fail("What are you concentrating on?\n");
     return 0;
   }
   if(str != "on white" && str != "on crimson" && str != "on scarlet" && str != "on green" && str != "on black" && str != "on cobalt" && str != "on yellow" && str != "on tan" && str != "on blue" && str != "on aquamarine" && str != "on violet" && str != "on pink") {
     tell_object(TP,"%^RESET%^An array of colors flash through your mind: you could concentrate on %^BOLD%^"
"%^WHITE%^white%^RESET%^, %^RED%^crimson%^RESET%^, %^BOLD%^%^RED%^scarlet%^RESET%^, %^GREEN%^green%^RESET%^, "
"%^BOLD%^%^BLACK%^black%^RESET%^, %^BLUE%^cobalt%^RESET%^, %^YELLOW%^yellow%^RESET%^, %^ORANGE%^tan%^RESET%^, "
"%^BOLD%^%^CYAN%^blue%^RESET%^, %^CYAN%^aquamarine%^RESET%^, %^MAGENTA%^violet%^RESET%^ or %^BOLD%^%^MAGENTA%^"
"pink%^RESET%^.\n");
     return 1;
   }
   if(!TO->query_worn()) {
     notify_fail("You get the feeling you should wear the cloak first.\n");
     return 0;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^A sparkle of light flashes across the cloak as it shifts colors.%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^WHITE%^A sparkle of light flashes across "+TP->QCN+"'s cloak as it shifts colors.%^RESET%^",TP);
   switch(str) {
     case "on white": tracker = 0; break;
     case "on crimson": tracker = 1; break;
     case "on scarlet": tracker = 2; break;
     case "on green": tracker = 3; break;
     case "on black": tracker = 4; break;
     case "on cobalt": tracker = 5; break;
     case "on yellow": tracker = 6; break;
     case "on tan": tracker = 7; break;
     case "on blue": tracker = 8; break;
     case "on aquamarine": tracker = 9; break;
     case "on violet": tracker = 10; break;
     case "on pink": tracker = 11; break;
     break;
   }
   TO->set_short(""+COLORS1[tracker]+"Chrom%^WHITE%^a"+COLORS1[tracker]+"tic Cloak%^RESET%^");
   TO->set_obvious_short(""+COLORS1[tracker]+"A long "+COLORS2[tracker]+" cloak%^RESET%^");
   TO->set_long("This beautiful "+COLORS1[tracker]+COLORS2[tracker]+" %^RESET%^cloak is sewn from soft cotton, "
"lightweight and comfortable as it rests upon the shoulders.  A small %^BOLD%^%^WHITE%^silver%^RESET%^ clasp "
"holds it at the throat, from where it falls over the shoulders and down the wearer's back, reaching partway "
"down their legs.  It is mostly simple in design, except for the fine tracing of matching %^BOLD%^%^WHITE%^"
"silver %^RESET%^embroidery along its hem, marking it with a touch of elegance.  Along the inner lining are "
"some embroidered words that you could probably %^BOLD%^%^BLUE%^read%^RESET%^.\n");
   return 1;
}
