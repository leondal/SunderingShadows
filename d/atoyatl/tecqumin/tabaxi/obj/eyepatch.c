//blindfold.c - coded by Lujke
#include <std.h>

inherit"/std/armour";

int position, charges;
void protect();

void create(){
::create();

   set_name("Tabaxi Third Eyepatch");
   set_id(({"headband","tabaxi eyepatch","eyepatch", "third eyepatch", "patch"}));
   set_obvious_short("%^BOLD%^%^BLACK%^A black eyepatch%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Tabaxi Third Eyepatch%^RESET%^");
   set_property("repairtype",({ "jewel" }));
   set_long( (: TO, "long_desc" :) );
   set_lore("The %^ORANGE%^tabaxi%^RESET%^ are known to believe that when this"
           +" eyepatch covers the wearer's 'third eye', it grants some concealment"
           +" from the prying eyes of those using magical or psychic scrying");
   set_property("lore difficulty",19);
    set_item_bonus("enchantment",7);
   set_type("ring"); 
   set_limbs(({"head"}));
   set_ac(0);
   set_weight(2);
   set_value(1750);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
   position = 0;
   charges = 50;
}

void init(){
  ::init();
  add_action("reposition", "reposition");  
}


int reposition(string str){
  int lev, num;
  string caster, targ, what,what2, spell, * quests;
  object ob;
  if (ETO->query_casting() && 
          objectp(ETO->query_property("spell_casting"))) {
    return notify_fail("You are already doing something!\n");
  }
  if (str != "eyepatch"){
    return notify_fail("try 'reposition eyepatch'");
  }
  if (query_worn() != ETO)
  {
    tell_object(ETO, "You would have to be wearing the eyepatch first");
    return 1;
  }
  if (ETO->query_property("raged")) {
    return notify_fail("You are too overcome with rage to adjust the"
                      +" eyepatch carefully\n");
  }
  if (objectp(ETO)){
    quests = ETO->query_mini_quests();
    if(member_array("Great Defender of the Tabaxi", quests)==-1 && !ETO->query_true_invis()){
      tell_object(ETO, "The Tabaxi have not granted you permission to use the magic of the eyepatch. Perhaps if you did something to help them out?");
      return 1; 
    }
  }

  if (position == 0){
    if (objectp(ETO)){
    lev = ETO->query_level();
    caster = ETO->query_name();
    if(TP->query_bound() || TP->query_paralyzed() ||TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
    }
//    spell = TO->query_power();
      tell_object(ETO, "You shift the eyepatch to the centre of your"
        +" forehead, covering the area where the tabaxi believe your"
        +" psychic third eye would be. You feel safer from prying"
        +" eyes.");
      position = 1;
      if (objectp(EETO)){
        tell_room (EETO, ETOQCN + "adjusts "+ ETO->QP +" eyepatch to"
         +" sit rather strangely over the centre of " + ETO->QP 
         +" forehead.", ETO);
      }
      if (charges < 1)
      {
        tell_object(TP, "Nothing happens, and you realise that the"
          +" eyepatch has run out of power");
        return 1;
      }
     
      ob = new("/cmds/spells/r/_remote_view_trap");
      if (ob->query_target_required() && !targ)
      {
        return notify_fail("You need to specify a target to use that"
             +" power!\n");
      }
      TP->setAdminBlock(2);
      ob->use_spell(TP, targ, lev);
      charges --;
      if (charges < 10)
      {
        tell_object(TP, "You get the feeling that the eyepatch may be running out of power.");
      }
      return 1;
    }
  } else {
    if (objectp(ETO)){
      tell_object(ETO, "You shift the eyepatch back over your eye");
      if (objectp(EETO)){
        tell_room (EETO, ETOQCN + "adjusts "+ ETO->QP +" eyepatch"
         +" back to cover " + ETO->QP +" eye.", ETO);
      }
      position = 0;
      return 1;
    }
  }
  return 0;
}

string long_desc(){
  string result;
  result = "This rakish eyepatch is made of %^BOLD%^%^BLACK%^black"
    +" cloth%^RESET%^, and is fastened by tying at the back. It can"
    +" sit over an eye, or be repositioned to cover the third eye.";
  if (!objectp(query_worn()))
  {
    return result;
  }
  switch (position)
  {
  case 0:
    if (TP == query_worn())
    {
      result += " At the moment, it is sitting over your eye";
    } else 
    {
      result += " At the moment, it is sitting over " + query_worn()->QCN + "%^RESET%^'s eye";
    }
    
    break;
  case 1:
    if (TP == query_worn())
    {
      result += " At the moment, it is sitting over your %^BOLD%^%^CYAN%^th%^WHITE%^i%^CYAN%^rd %^WHITE%^e%^BLUE%^y%^WHITE%^e";
    } else 
    {
      result += " At the moment, it is sitting over " + query_worn()->QCN + "'s %^BOLD%^%^CYAN%^th%^WHITE%^i%^CYAN%^rd %^WHITE%^e%^BLUE%^y%^WHITE%^e";
    }
    break;
  } 
  return result;
}

int wearme(){
  string * quests, msg;
  if(!living(ETO)) return 1;
  msg = "You slip the headband on, positioning the eyepatch over"
       +" your eye.";
  position = 0;
  quests = ETO->query_mini_quests();
  if(member_array("Great Defender of the Tabaxi", quests)!=-1){
    msg += " %^ORANGE%^You could %^BOLD%^%^RED%^<reposition> "
        +"%^RESET%^%^ORANGE%^the eyepatch to cover your third"
        +" eye, if you wish to conceal your presence from"
        +" scrying eyes.";
  }
  tell_object(ETO, msg);
  tell_room(EETO, ETOQCN+" slips the headband on, positioning the"
                +" eyepatch carefully over " + ETO->QP 
                + " eye.",ETO);
  return 1;
}

int unwearme(){
   tell_object(ETO,"You slip the eyepatch off your head");
   tell_room(EETO,ETOQCN + " slips the eyepatch off over "+ETO->QP
      +" head",ETO);
   return 1;
}

void slip(){
  
}
