#include <std.h>
inherit OBJECT;
int squeeze;

void create(){
	::create();
	set_name("stuffed kitten toy");
	set_id(({ "stuffed toy", "kitten", "stuffed kitten", "toy", "kitten", "stuffed kitten toy", "stuffed animal", "stuffed animalz" }));
	set_short("%^BOLD%^%^WHITE%^a stuffed toy in the shape of a kitten%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a stuffed toy in the shape of a kitten%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This little white cotton toy is shaped like a kitten and has been stuffed with lots of soft cotton to make it squeezable. Small %^CYAN%^blue buttons %^WHITE%^have been used to make the eyes of this toy, while a %^MAGENTA%^pink button %^WHITE%^was used to make the nose. %^BLACK%^Black yarn %^WHITE%^has been sewn along the mouth line and curls up at either end in a smile. A bright %^MAGENTA%^pink bow %^WHITE%^has been tied around the toy's neck to add contrast to the white body. %^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(235);
}

void init(){
   ::init();
   add_action("squeeze_me","squeeze");
}

int squeeze_me(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   if (TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+TPQCN+" squeezes the soft belly of the kitten and it goes%^RESET%^ ' %^BOLD%^%^CYAN%^meow%^RESET%^ '",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You squeeze the soft belly of the kitten and it goes%^RESET%^ ' %^BOLD%^%^CYAN%^meow%^RESET%^ '");
    return 1;
}
