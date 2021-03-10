#include <std.h>
#define CHIPS "/d/shadow/obj/misc/chips.c"
inherit OBJECT;

int val;

void create(){
    ::create();
    val = 0;
    set_name("stack of chips");
    set_id(({"chips", "counters", "stack", "stack of chips", 
                                    "stack of betting counters"}));
    set_short("A stack of betting counters");
    set_long( (:TO, "long_desc":));
    set_value(0);
    set_weight(1);

}

void init(){
  ::init();
  add_action("combine_chips", "stack");
  add_action ("separate_stack", "take");
}

int separate_stack(string str){
  int amount;
  string what;
  object newstack;
  if (sscanf(str, "%d from %s", amount, what)<2){
     return 0;
  }
  if (!id(what)){
     return 0;
  }
  if (ETO!= TP){
    return 0;
  }
  if (amount>val){
    tell_object(TP, "You don't have that many chips in your stack");
    return 1;
  }
  if (amount == val){
    tell_object(TP, "That's the total value of your stack");
    return 1;
  }
  newstack = new(CHIPS);
  if (objectp(newstack)){
    newstack->set_val(amount);
    TO->set_val(val-amount);
    newstack->move(ETO);
    tell_object(TP, "You take " + amount + " chips from your stack to make"
              +" a separate stack");
    if (objectp(ETP)){
      tell_room(ETP, TPQCN + " hives some of " + TP->QP + " chips off into"
              +" a separate stack", TP);
    }
    return 1;
  }
  tell_object(TP, "There was an error making your new stack of chips."
             +" Please tell a wiz. Or spend some time crying quietly into"
             +" your beer");
  return 1;
}

int combine_chips(string str){
  object chips, chips2;
  if (str != "chips"){
    return 0;
  }
  if (ETO != TP){
    return 0;
  }
  if (!present("chips 2", TP)){
    tell_object(TP, "You are only carrying one stack of chips");
    return 1;
  }
  while(present("chips 2", TP)){
    chips = present("chips", TP);
    chips2 = present("chips 2", TP);
    if(objectp(chips)&&objectp(chips2)){
      chips->set_val (val + chips2->query_val());
      chips2->remove();
    }
  }
  tell_object(TP, "You combine your stacks of chips, ending up with a"
           +" total value of " + val + " gold");
  tell_room(ETO, TPQCN + "combines " + TP->QP + " stacks of betting chips",
                                                                      TP);
  return 1;
}

void set_val(int newval){
  val = newval;
}

int query_val(){
  return val;
}

string long_desc(){
  string result;
  result = "%^BOLD%^%^WHITE%^A stack of di%^BOLD%^%^RED%^ff"
        +"%^BOLD%^%^WHITE%^er%^BOLD%^%^BLUE%^en%^BOLD%^%^WHITE%^t"
        +" co%^BOLD%^%^BLUE%^lo%^BOLD%^%^WHITE%^ur%^BOLD%^%^RED%^ed"
        +"%^BOLD%^%^WHITE%^ betting counters.\n%^BOLD%^%^RED%^Total worth:"
        +" %^CYAN%^" + val + " gold\n%^RESET%^These can be cashed in with"
        +" a card dealer ('%^BOLD%^%^YELLOW%^cash in chips%^RESET%^')\n"
        +"You can also '%^BOLD%^%^YELLOW%^stack chips%^RESET%^' to combine"
        +" your stacks if you are carrying more than one lot, or '%^BOLD%^"
        +"%^YELLOW%^take <amount> from stack%^RESET%^' if you want to"
        +" separate some of your stack";
  return result;
}




