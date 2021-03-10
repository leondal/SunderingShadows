inherit "/std/food.c";

void create(){
   ::create();
   set_name("nuts");
   set_id(({"nuts","food"}));
   set_short("A handful of nuts");
   set_long("Fallen from a variety of trees, there are a few almonds, some walnuts and a couple pecans.");
   set_my_mess("You eat the handful of nuts.");
   set_your_mess("eats a handful of nuts.");
   set_destroy();
   set_poison(0);
   set_strength(10);
   set_weight(1);
   set_value(0);
}