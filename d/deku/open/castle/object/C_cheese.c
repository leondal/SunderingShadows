//  A nice Marleen-Cheese 
// Pator@ShadowGate
// 07/06/95

inherit "/std/food";

create() {
      ::create();
      set_name("marleen-cheese");
      set_id(({"Marleen-cheese","marleen cheese","marleen castle cheese","castle cheese","cheese"}));
      set_short("A nice but very smelly Marleen castle cheese");
      set("long",
@PATOR
This is a very special cheese. It is made out of several very special ingredients. You can only tell that the color is yellow and the smell awful!!
PATOR
);
      set_weight(2);
      set_my_mess("You eat a Marleen castle cheese and you don't feel good !");
      set_your_mess("A Marleen-cheese is eaten !!!");
      set_strength(random(8));
      set_poison(random(2));
      set_value(5);
         }
