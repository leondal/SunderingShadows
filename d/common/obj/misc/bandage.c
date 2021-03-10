//created by Styx for all the poor souls who are being severely tortured  2/02.
//updated by ~Circe~ 12/15/15 to new code and to adjust the command since spells now use "prepare"
#include <std.h>
inherit ARMOUR;

string where;

void create() {
    ::create();
    set_name("bandage");
    set_id(({ "bandage" }) );
    set_short("%^RESET%^%^ORANGE%^A cloth bandage%^RESET%^");
    set_long("This is a strip of soft, absorbent cloth that can be used "
       "to bandage a limb, covering it for healing or to contain the bleeding.  "
       "Sometimes a cleric or healer will use them to apply healing "
       "ointments or poultices.  You should <prep> the bandage to wrap "
       "a particular body part before trying to wear it." );
    set_weight(1);
    set_value(4);
    set_type("ring");
    set_limbs( ({ "right arm" }) );
    set_ac(0);
    set_property("wrapped", "right arm");
}

void init() {
  ::init();
  if (ETO!=TP)     return;
  add_action("set_bandage","prep"); //was "prepare"
  add_action("set_bandage","bandage");
}

string query_short() {
    string str;
    str = ::query_short();
    if(TO->query_worn())  str = str+" wrapping the "+TO->query_property("wrapped");
    return str;
}

int set_bandage(string str) {
  string this;
  object ob;
  if ( (!stringp(str)) || (sscanf(str,"%s for %s", this, where) != 2))
    return notify_fail("Prep <which bandage> for <what body part>?\n");
  else {
  ob = present(this,TP);
    if(ob != TO) return 0;
    if (member_array(where,TP->query_limbs()) == -1)
      return notify_fail("You don't have a "+where+" body part so you can't wrap it!\n");
    if (TO->query_worn())
      return notify_fail("You would have to take it off first!\n");
    set_limbs(({where}));
    remove_property("wrapped");
    set_property("wrapped", where);
    write("You ready the bandage to wrap your "+where+".");
    tell_room(ETP,TPQCN+" seems to prepare a bandage to wrap something.",TP);
    set_value(0);
    return 1;
  }
}
