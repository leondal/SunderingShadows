#include <std.h>

#define post ({"waybread","stew","tablescraps","roast leg","steak","rations","cheesecake","casserole"})
#define str ({"elven","dwarven","ogrish","gnollish","derro","human","goblin","orc","halfling"})

inherit OBJECT;

void create(){
   int i,j;
   string name, name1;
   ::create();
   j=random(8);
   i=random(9);
   name=post[j];
   name1= str[i];
   set_long("This "+name+" is something from the master cook in the firegiants underground home.   You're not terribly sure about how healthy it is, but it doesn't smell that bad actually.");
   set_short(""+name1+" "+name+"");
   set_id(({"food",name1,name,""+name1+" "+name+""}));
   set_weight(5);
   set_value(25);
}

void init(){
  ::init();
  add_action("eat","eat");
}

int eat(string fod){
   object shrt;
   (string)shrt=TO->query_short();
   if((fod=="food") || (fod==shrt)){
      if(!TP->add_stuffed(20)) return notify_fail("You're already stuffed!\n");
      tell_object(ETO,"You hesistantly bite into it and then realize it ain't that bad and finish it off.");
      tell_room(EETO,""+TPQCN+" takes a little nibble of something then looks surprised and eats the rest.",ETO);
      TP->add_hp(random(10)+10);
      remove();
      return 1;
   }
}
